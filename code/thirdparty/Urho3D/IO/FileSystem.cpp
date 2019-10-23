//
// Copyright (c) 2008-2019 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include "../Precompiled.h"

#include "../Container/ArrayPtr.h"
#include "../Core/Context.h"
#include "../Core/CoreEvents.h"
#include "../Core/Thread.h"
#include "../Engine/EngineEvents.h"
#include "../IO/File.h"
#include "../IO/FileSystem.h"
#include "../IO/IOEvents.h"
#include "../IO/Log.h"

#ifdef __ANDROID__
#include <SDL_rwops.h>
#endif

#include <SDL_filesystem.h>

#include <sys/stat.h>
#include <cstdio>

#include <dirent.h>
#include <cerrno>
#include <unistd.h>
#include <utime.h>
#include <sys/wait.h>
#define MAX_PATH 256

#if defined(__APPLE__)
#include <mach-o/dyld.h>
#endif

extern "C"
{
#ifdef __ANDROID__
const char* SDL_Android_GetFilesDir();
char** SDL_Android_GetFileList(const char* path, int* count);
void SDL_Android_FreeFileList(char*** array, int* count);
#elif defined(IOS) || defined(TVOS)
const char* SDL_IOS_GetResourceDir();
const char* SDL_IOS_GetDocumentsDir();
#endif
}


namespace Urho3D
{

int DoSystemCommand(const String& commandLine, bool redirectToLog, Context* context)
{
#if defined(TVOS) || defined(IOS)
    return -1;
#else
    if (!redirectToLog)
        return system(commandLine.CString());

    // Get a platform-agnostic temporary file name for stderr redirection
    String stderrFilename;
    String adjustedCommandLine(commandLine);
    char* prefPath = SDL_GetPrefPath("urho3d", "temp");
    if (prefPath)
    {
        stderrFilename = String(prefPath) + "command-stderr";
        adjustedCommandLine += " 2>" + stderrFilename;
        SDL_free(prefPath);
    }

    // Use popen/pclose to capture the stdout and stderr of the command
    FILE* file = popen(adjustedCommandLine.CString(), "r");
    if (!file)
        return -1;

    // Capture the standard output stream
    char buffer[128];
    while (!feof(file))
    {
        if (fgets(buffer, sizeof(buffer), file))
            URHO3D_LOGRAW(String(buffer));
    }
    int exitCode = pclose(file);

    // Capture the standard error stream
    if (!stderrFilename.Empty())
    {
        SharedPtr<File> errFile(new File(context, stderrFilename, FILE_READ));
        while (!errFile->IsEof())
        {
            unsigned numRead = errFile->Read(buffer, sizeof(buffer));
            if (numRead)
                Log::WriteRaw(String(buffer, numRead), true);
        }
    }

    return exitCode;
#endif
}

int DoSystemRun(const String& fileName, const Vector<String>& arguments)
{
#ifdef TVOS
    return -1;
#else
    String fixedFileName = GetNativePath(fileName);

    pid_t pid = fork();
    if (!pid)
    {
        PODVector<const char*> argPtrs;
        argPtrs.Push(fixedFileName.CString());
        for (unsigned i = 0; i < arguments.Size(); ++i)
            argPtrs.Push(arguments[i].CString());
        argPtrs.Push(nullptr);

        execvp(argPtrs[0], (char**)&argPtrs[0]);
        return -1; // Return -1 if we could not spawn the process
    }
    else if (pid > 0)
    {
        int exitCode;
        wait(&exitCode);
        return exitCode;
    }
    else
        return -1;
#endif
}

/// Base class for async execution requests.
class AsyncExecRequest : public Thread
{
public:
    /// Construct.
    explicit AsyncExecRequest(unsigned& requestID) :
        requestID_(requestID)
    {
        // Increment ID for next request
        ++requestID;
        if (requestID == M_MAX_UNSIGNED)
            requestID = 1;
    }

    /// Return request ID.
    unsigned GetRequestID() const { return requestID_; }

    /// Return exit code. Valid when IsCompleted() is true.
    int GetExitCode() const { return exitCode_; }

    /// Return completion status.
    bool IsCompleted() const { return completed_; }

protected:
    /// Request ID.
    unsigned requestID_{};
    /// Exit code.
    int exitCode_{};
    /// Completed flag.
    volatile bool completed_{};
};

/// Async system command operation.
class AsyncSystemCommand : public AsyncExecRequest
{
public:
    /// Construct and run.
    AsyncSystemCommand(unsigned requestID, const String& commandLine) :
        AsyncExecRequest(requestID),
        commandLine_(commandLine)
    {
        Run();
    }

    /// The function to run in the thread.
    void ThreadFunction() override
    {
        exitCode_ = DoSystemCommand(commandLine_, false, nullptr);
        completed_ = true;
    }

private:
    /// Command line.
    String commandLine_;
};

/// Async system run operation.
class AsyncSystemRun : public AsyncExecRequest
{
public:
    /// Construct and run.
    AsyncSystemRun(unsigned requestID, const String& fileName, const Vector<String>& arguments) :
        AsyncExecRequest(requestID),
        fileName_(fileName),
        arguments_(arguments)
    {
        Run();
    }

    /// The function to run in the thread.
    void ThreadFunction() override
    {
        exitCode_ = DoSystemRun(fileName_, arguments_);
        completed_ = true;
    }

private:
    /// File to run.
    String fileName_;
    /// Command line split in arguments.
    const Vector<String>& arguments_;
};

FileSystem::FileSystem(Context* context) :
    Object(context)
{
    SubscribeToEvent(E_BEGINFRAME, URHO3D_HANDLER(FileSystem, HandleBeginFrame));

    // Subscribe to console commands
    SetExecuteConsoleCommands(true);
}

FileSystem::~FileSystem()
{
    // If any async exec items pending, delete them
    if (asyncExecQueue_.Size())
    {
        for (List<AsyncExecRequest*>::Iterator i = asyncExecQueue_.Begin(); i != asyncExecQueue_.End(); ++i)
            delete(*i);

        asyncExecQueue_.Clear();
    }
}

bool FileSystem::SetCurrentDir(const String& pathName)
{
    if (!CheckAccess(pathName))
    {
        URHO3D_LOGERROR("Access denied to " + pathName);
        return false;
    }
    if (chdir(GetNativePath(pathName).CString()) != 0)
    {
        URHO3D_LOGERROR("Failed to change directory to " + pathName);
        return false;
    }

    return true;
}

bool FileSystem::CreateDir(const String& pathName)
{
    if (!CheckAccess(pathName))
    {
        URHO3D_LOGERROR("Access denied to " + pathName);
        return false;
    }

    // Create each of the parents if necessary
    String parentPath = GetParentPath(pathName);
    if (parentPath.Length() > 1 && !DirExists(parentPath))
    {
        if (!CreateDir(parentPath))
            return false;
    }

    bool success = mkdir(GetNativePath(RemoveTrailingSlash(pathName)).CString(), S_IRWXU) == 0 || errno == EEXIST;

    if (success)
        URHO3D_LOGDEBUG("Created directory " + pathName);
    else
        URHO3D_LOGERROR("Failed to create directory " + pathName);

    return success;
}

void FileSystem::SetExecuteConsoleCommands(bool enable)
{
    if (enable == executeConsoleCommands_)
        return;

    executeConsoleCommands_ = enable;
    if (enable)
        SubscribeToEvent(E_CONSOLECOMMAND, URHO3D_HANDLER(FileSystem, HandleConsoleCommand));
    else
        UnsubscribeFromEvent(E_CONSOLECOMMAND);
}

int FileSystem::SystemCommand(const String& commandLine, bool redirectStdOutToLog)
{
    if (allowedPaths_.Empty())
        return DoSystemCommand(commandLine, redirectStdOutToLog, context_);
    else
    {
        URHO3D_LOGERROR("Executing an external command is not allowed");
        return -1;
    }
}

int FileSystem::SystemRun(const String& fileName, const Vector<String>& arguments)
{
    if (allowedPaths_.Empty())
        return DoSystemRun(fileName, arguments);
    else
    {
        URHO3D_LOGERROR("Executing an external command is not allowed");
        return -1;
    }
}

unsigned FileSystem::SystemCommandAsync(const String& commandLine)
{
    if (allowedPaths_.Empty())
    {
        unsigned requestID = nextAsyncExecID_;
        auto* cmd = new AsyncSystemCommand(nextAsyncExecID_, commandLine);
        asyncExecQueue_.Push(cmd);
        return requestID;
    }
    else
    {
        URHO3D_LOGERROR("Executing an external command is not allowed");
        return M_MAX_UNSIGNED;
    }
}

unsigned FileSystem::SystemRunAsync(const String& fileName, const Vector<String>& arguments)
{
    if (allowedPaths_.Empty())
    {
        unsigned requestID = nextAsyncExecID_;
        auto* cmd = new AsyncSystemRun(nextAsyncExecID_, fileName, arguments);
        asyncExecQueue_.Push(cmd);
        return requestID;
    }
    else
    {
        URHO3D_LOGERROR("Executing an external command is not allowed");
        return M_MAX_UNSIGNED;
    }
}

bool FileSystem::SystemOpen(const String& fileName, const String& mode)
{
    if (allowedPaths_.Empty())
    {
        if (!FileExists(fileName) && !DirExists(fileName))
        {
            URHO3D_LOGERROR("File or directory " + fileName + " not found");
            return false;
        }

        Vector<String> arguments;
        arguments.Push(fileName);
        bool success = SystemRun(
#if defined(__APPLE__)
            "/usr/bin/open",
#else
            "/usr/bin/xdg-open",
#endif
            arguments) == 0;
        if (!success)
            URHO3D_LOGERROR("Failed to open " + fileName + " externally");
        return success;
    }
    else
    {
        URHO3D_LOGERROR("Opening a file externally is not allowed");
        return false;
    }
}

bool FileSystem::Copy(const String& srcFileName, const String& destFileName)
{
    if (!CheckAccess(GetPath(srcFileName)))
    {
        URHO3D_LOGERROR("Access denied to " + srcFileName);
        return false;
    }
    if (!CheckAccess(GetPath(destFileName)))
    {
        URHO3D_LOGERROR("Access denied to " + destFileName);
        return false;
    }

    SharedPtr<File> srcFile(new File(context_, srcFileName, FILE_READ));
    if (!srcFile->IsOpen())
        return false;
    SharedPtr<File> destFile(new File(context_, destFileName, FILE_WRITE));
    if (!destFile->IsOpen())
        return false;

    unsigned fileSize = srcFile->GetSize();
    SharedArrayPtr<unsigned char> buffer(new unsigned char[fileSize]);

    unsigned bytesRead = srcFile->Read(buffer.Get(), fileSize);
    unsigned bytesWritten = destFile->Write(buffer.Get(), fileSize);
    return bytesRead == fileSize && bytesWritten == fileSize;
}

bool FileSystem::Rename(const String& srcFileName, const String& destFileName)
{
    if (!CheckAccess(GetPath(srcFileName)))
    {
        URHO3D_LOGERROR("Access denied to " + srcFileName);
        return false;
    }
    if (!CheckAccess(GetPath(destFileName)))
    {
        URHO3D_LOGERROR("Access denied to " + destFileName);
        return false;
    }

    return rename(GetNativePath(srcFileName).CString(), GetNativePath(destFileName).CString()) == 0;
}

bool FileSystem::Delete(const String& fileName)
{
    if (!CheckAccess(GetPath(fileName)))
    {
        URHO3D_LOGERROR("Access denied to " + fileName);
        return false;
    }

    return remove(GetNativePath(fileName).CString()) == 0;
}

String FileSystem::GetCurrentDir() const
{
    char path[MAX_PATH];
    path[0] = 0;
    getcwd(path, MAX_PATH);
    return AddTrailingSlash(String(path));
}

bool FileSystem::CheckAccess(const String& pathName) const
{
    String fixedPath = AddTrailingSlash(pathName);

    // If no allowed directories defined, succeed always
    if (allowedPaths_.Empty())
        return true;

    // If there is any attempt to go to a parent directory, disallow
    if (fixedPath.Contains(".."))
        return false;

    // Check if the path is a partial match of any of the allowed directories
    for (HashSet<String>::ConstIterator i = allowedPaths_.Begin(); i != allowedPaths_.End(); ++i)
    {
        if (fixedPath.Find(*i) == 0)
            return true;
    }

    // Not found, so disallow
    return false;
}

unsigned FileSystem::GetLastModifiedTime(const String& fileName) const
{
    if (fileName.Empty() || !CheckAccess(fileName))
        return 0;

    struct stat st{};
    if (!stat(fileName.CString(), &st))
        return (unsigned)st.st_mtime;
    else
        return 0;
}

bool FileSystem::FileExists(const String& fileName) const
{
    if (!CheckAccess(GetPath(fileName)))
        return false;

#ifdef __ANDROID__
    if (URHO3D_IS_ASSET(fileName))
    {
        SDL_RWops* rwOps = SDL_RWFromFile(URHO3D_ASSET(fileName), "rb");
        if (rwOps)
        {
            SDL_RWclose(rwOps);
            return true;
        }
        else
            return false;
    }
#endif

    String fixedName = GetNativePath(RemoveTrailingSlash(fileName));

    struct stat st{};
    if (stat(fixedName.CString(), &st) || st.st_mode & S_IFDIR)
        return false;

    return true;
}

bool FileSystem::DirExists(const String& pathName) const
{
    if (!CheckAccess(pathName))
        return false;

    // Always return true for the root directory
    if (pathName == "/")
        return true;

    String fixedName = GetNativePath(RemoveTrailingSlash(pathName));

#ifdef __ANDROID__
    if (URHO3D_IS_ASSET(fixedName))
    {
        // Split the pathname into two components: the longest parent directory path and the last name component
        String assetPath(URHO3D_ASSET((fixedName + "/")));
        String parentPath;
        unsigned pos = assetPath.FindLast('/', assetPath.Length() - 2);
        if (pos != String::NPOS)
        {
            parentPath = assetPath.Substring(0, pos);
            assetPath = assetPath.Substring(pos + 1);
        }
        assetPath.Resize(assetPath.Length() - 1);

        bool exist = false;
        int count;
        char** list = SDL_Android_GetFileList(parentPath.CString(), &count);
        for (int i = 0; i < count; ++i)
        {
            exist = assetPath == list[i];
            if (exist)
                break;
        }
        SDL_Android_FreeFileList(&list, &count);
        return exist;
    }
#endif

    struct stat st{};
    if (stat(fixedName.CString(), &st) || !(st.st_mode & S_IFDIR))
        return false;

    return true;
}

void FileSystem::ScanDir(Vector<String>& result, const String& pathName, const String& filter, unsigned flags, bool recursive) const
{
    result.Clear();

    if (CheckAccess(pathName))
    {
        String initialPath = AddTrailingSlash(pathName);
        ScanDirInternal(result, initialPath, initialPath, filter, flags, recursive);
    }
}

String FileSystem::GetProgramDir() const
{
#if defined(__ANDROID__)
    // This is an internal directory specifier pointing to the assets in the .apk
    // Files from this directory will be opened using special handling
    return APK;
#elif defined(IOS) || defined(TVOS)
    return AddTrailingSlash(SDL_IOS_GetResourceDir());
#elif defined(__APPLE__)
    char exeName[MAX_PATH];
    memset(exeName, 0, MAX_PATH);
    unsigned size = MAX_PATH;
    _NSGetExecutablePath(exeName, &size);
    return GetPath(String(exeName));
#elif defined(__linux__)
    char exeName[MAX_PATH];
    memset(exeName, 0, MAX_PATH);
    pid_t pid = getpid();
    String link = "/proc/" + String(pid) + "/exe";
    readlink(link.CString(), exeName, MAX_PATH);
    return GetPath(String(exeName));
#else
    return GetCurrentDir();
#endif
}

String FileSystem::GetUserDocumentsDir() const
{
#if defined(__ANDROID__)
    return AddTrailingSlash(SDL_Android_GetFilesDir());
#elif defined(IOS) || defined(TVOS)
    return AddTrailingSlash(SDL_IOS_GetDocumentsDir());
#else
    char pathName[MAX_PATH];
    pathName[0] = 0;
    strcpy(pathName, getenv("HOME"));
    return AddTrailingSlash(String(pathName));
#endif
}

String FileSystem::GetAppPreferencesDir(const String& org, const String& app) const
{
    String dir;
    char* prefPath = SDL_GetPrefPath(org.CString(), app.CString());
    if (prefPath)
    {
        dir = GetInternalPath(String(prefPath));
        SDL_free(prefPath);
    }
    else
        URHO3D_LOGWARNING("Could not get application preferences directory");

    return dir;
}

void FileSystem::RegisterPath(const String& pathName)
{
    if (pathName.Empty())
        return;

    allowedPaths_.Insert(AddTrailingSlash(pathName));
}

bool FileSystem::SetLastModifiedTime(const String& fileName, unsigned newTime)
{
    if (fileName.Empty() || !CheckAccess(fileName))
        return false;

    struct stat oldTime{};
    struct utimbuf newTimes{};
    if (stat(fileName.CString(), &oldTime) != 0)
        return false;
    newTimes.actime = oldTime.st_atime;
    newTimes.modtime = newTime;
    return utime(fileName.CString(), &newTimes) == 0;
}

void FileSystem::ScanDirInternal(Vector<String>& result, String path, const String& startPath,
    const String& filter, unsigned flags, bool recursive) const
{
    path = AddTrailingSlash(path);
    String deltaPath;
    if (path.Length() > startPath.Length())
        deltaPath = path.Substring(startPath.Length());

    String filterExtension = filter.Substring(filter.FindLast('.'));
    if (filterExtension.Contains('*'))
        filterExtension.Clear();

#ifdef __ANDROID__
    if (URHO3D_IS_ASSET(path))
    {
        String assetPath(URHO3D_ASSET(path));
        assetPath.Resize(assetPath.Length() - 1);       // AssetManager.list() does not like trailing slash
        int count;
        char** list = SDL_Android_GetFileList(assetPath.CString(), &count);
        for (int i = 0; i < count; ++i)
        {
            String fileName(list[i]);
            if (!(flags & SCAN_HIDDEN) && fileName.StartsWith("."))
                continue;

#ifdef ASSET_DIR_INDICATOR
            // Patch the directory name back after retrieving the directory flag
            bool isDirectory = fileName.EndsWith(ASSET_DIR_INDICATOR);
            if (isDirectory)
            {
                fileName.Resize(fileName.Length() - sizeof(ASSET_DIR_INDICATOR) / sizeof(char) + 1);
                if (flags & SCAN_DIRS)
                    result.Push(deltaPath + fileName);
                if (recursive)
                    ScanDirInternal(result, path + fileName, startPath, filter, flags, recursive);
            }
            else if (flags & SCAN_FILES)
#endif
            {
                if (filterExtension.Empty() || fileName.EndsWith(filterExtension))
                    result.Push(deltaPath + fileName);
            }
        }
        SDL_Android_FreeFileList(&list, &count);
        return;
    }
#endif
    DIR* dir;
    struct dirent* de;
    struct stat st{};
    dir = opendir(GetNativePath(path).CString());
    if (dir)
    {
        while ((de = readdir(dir)))
        {
            /// \todo Filename may be unnormalized Unicode on Mac OS X. Re-normalize as necessary
            String fileName(de->d_name);
            bool normalEntry = fileName != "." && fileName != "..";
            if (normalEntry && !(flags & SCAN_HIDDEN) && fileName.StartsWith("."))
                continue;
            String pathAndName = path + fileName;
            if (!stat(pathAndName.CString(), &st))
            {
                if (st.st_mode & S_IFDIR)
                {
                    if (flags & SCAN_DIRS)
                        result.Push(deltaPath + fileName);
                    if (recursive && normalEntry)
                        ScanDirInternal(result, path + fileName, startPath, filter, flags, recursive);
                }
                else if (flags & SCAN_FILES)
                {
                    if (filterExtension.Empty() || fileName.EndsWith(filterExtension))
                        result.Push(deltaPath + fileName);
                }
            }
        }
        closedir(dir);
    }
}

void FileSystem::HandleBeginFrame(StringHash eventType, VariantMap& eventData)
{
    /// Go through the execution queue and post + remove completed requests
    for (List<AsyncExecRequest*>::Iterator i = asyncExecQueue_.Begin(); i != asyncExecQueue_.End();)
    {
        AsyncExecRequest* request = *i;
        if (request->IsCompleted())
        {
            using namespace AsyncExecFinished;

            VariantMap& newEventData = GetEventDataMap();
            newEventData[P_REQUESTID] = request->GetRequestID();
            newEventData[P_EXITCODE] = request->GetExitCode();
            SendEvent(E_ASYNCEXECFINISHED, newEventData);

            delete request;
            i = asyncExecQueue_.Erase(i);
        }
        else
            ++i;
    }
}

void FileSystem::HandleConsoleCommand(StringHash eventType, VariantMap& eventData)
{
    using namespace ConsoleCommand;
    if (eventData[P_ID].GetString() == GetTypeName())
        SystemCommand(eventData[P_COMMAND].GetString(), true);
}

void SplitPath(const String& fullPath, String& pathName, String& fileName, String& extension, bool lowercaseExtension)
{
    String fullPathCopy = GetInternalPath(fullPath);

    unsigned extPos = fullPathCopy.FindLast('.');
    unsigned pathPos = fullPathCopy.FindLast('/');

    if (extPos != String::NPOS && (pathPos == String::NPOS || extPos > pathPos))
    {
        extension = fullPathCopy.Substring(extPos);
        if (lowercaseExtension)
            extension = extension.ToLower();
        fullPathCopy = fullPathCopy.Substring(0, extPos);
    }
    else
        extension.Clear();

    pathPos = fullPathCopy.FindLast('/');
    if (pathPos != String::NPOS)
    {
        fileName = fullPathCopy.Substring(pathPos + 1);
        pathName = fullPathCopy.Substring(0, pathPos + 1);
    }
    else
    {
        fileName = fullPathCopy;
        pathName.Clear();
    }
}

String GetPath(const String& fullPath)
{
    String path, file, extension;
    SplitPath(fullPath, path, file, extension);
    return path;
}

String GetFileName(const String& fullPath)
{
    String path, file, extension;
    SplitPath(fullPath, path, file, extension);
    return file;
}

String GetExtension(const String& fullPath, bool lowercaseExtension)
{
    String path, file, extension;
    SplitPath(fullPath, path, file, extension, lowercaseExtension);
    return extension;
}

String GetFileNameAndExtension(const String& fileName, bool lowercaseExtension)
{
    String path, file, extension;
    SplitPath(fileName, path, file, extension, lowercaseExtension);
    return file + extension;
}

String ReplaceExtension(const String& fullPath, const String& newExtension)
{
    String path, file, extension;
    SplitPath(fullPath, path, file, extension);
    return path + file + newExtension;
}

String AddTrailingSlash(const String& pathName)
{
    String ret = pathName.Trimmed();
    ret.Replace('\\', '/');
    if (!ret.Empty() && ret.Back() != '/')
        ret += '/';
    return ret;
}

String RemoveTrailingSlash(const String& pathName)
{
    String ret = pathName.Trimmed();
    ret.Replace('\\', '/');
    if (!ret.Empty() && ret.Back() == '/')
        ret.Resize(ret.Length() - 1);
    return ret;
}

String GetParentPath(const String& path)
{
    unsigned pos = RemoveTrailingSlash(path).FindLast('/');
    if (pos != String::NPOS)
        return path.Substring(0, pos + 1);
    else
        return String();
}

String GetInternalPath(const String& pathName)
{
    return pathName.Replaced('\\', '/');
}

String GetNativePath(const String& pathName)
{
    return pathName;
}

WString GetWideNativePath(const String& pathName)
{
    return WString(pathName);
}

bool IsAbsolutePath(const String& pathName)
{
    if (pathName.Empty())
        return false;

    String path = GetInternalPath(pathName);

    if (path[0] == '/')
        return true;

    return false;
}

String FileSystem::GetTemporaryDir() const
{
    if (char* pathName = getenv("TMPDIR"))
        return AddTrailingSlash(pathName);
#ifdef P_tmpdir
    return AddTrailingSlash(P_tmpdir);
#else
    return "/tmp/";
#endif
}

}
