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

#include "../Core/Profiler.h"
#include "../IO/NamedPipe.h"
#include "../IO/Log.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <csignal>
#include <unistd.h>


namespace Urho3D
{

static const unsigned PIPE_BUFFER_SIZE = 65536;

NamedPipe::NamedPipe(Context* context) :
    Object(context),
    isServer_(false),
    readHandle_(-1),
    writeHandle_(-1)
{
}

NamedPipe::NamedPipe(Context* context, const String& pipeName, bool isServer) :
    Object(context),
    isServer_(false),
    readHandle_(-1),
    writeHandle_(-1)
{
    Open(pipeName, isServer);
}

NamedPipe::~NamedPipe()
{
    Close();
}

unsigned NamedPipe::Seek(unsigned position)
{
    return 0;
}

static const char* pipePath = "/tmp/";

#define SAFE_CLOSE(handle) if ((handle) != -1) { close(handle); (handle) = -1; }

bool NamedPipe::Open(const String& pipeName, bool isServer)
{
    URHO3D_PROFILE(OpenNamedPipe);

    Close();

    isServer_ = false;

    String serverReadName = pipePath + pipeName + "SR";
    String clientReadName = pipePath + pipeName + "CR";

    // Make sure SIGPIPE is ignored and will not lead to process termination
    signal(SIGPIPE, SIG_IGN);

    if (isServer)
    {
        mkfifo(serverReadName.CString(), 0660);
        mkfifo(clientReadName.CString(), 0660);

        readHandle_ = open(serverReadName.CString(), O_RDONLY | O_NDELAY);
        writeHandle_ = open(clientReadName.CString(), O_WRONLY | O_NDELAY);

        if (readHandle_ == -1 && writeHandle_ == -1)
        {
            URHO3D_LOGERROR("Failed to create named pipe " + pipeName);
            SAFE_CLOSE(readHandle_);
            SAFE_CLOSE(writeHandle_);
            unlink(serverReadName.CString());
            unlink(clientReadName.CString());
            return false;
        }
        else
        {
            URHO3D_LOGDEBUG("Created named pipe " + pipeName);
            pipeName_ = pipeName;
            isServer_ = true;
            return true;
        }
    }
    else
    {
        readHandle_ = open(clientReadName.CString(), O_RDONLY | O_NDELAY);
        writeHandle_ = open(serverReadName.CString(), O_WRONLY | O_NDELAY);
        if (readHandle_ == -1 && writeHandle_ == -1)
        {
            URHO3D_LOGERROR("Failed to connect to named pipe " + pipeName);
            SAFE_CLOSE(readHandle_);
            SAFE_CLOSE(writeHandle_);
            return false;
        }
        else
        {
            URHO3D_LOGDEBUG("Connected to named pipe " + pipeName);
            pipeName_ = pipeName;
            return true;
        }
    }
}

unsigned NamedPipe::Read(void* dest, unsigned size)
{
    // Attempt to open late if only the write handle is open yet
    if (readHandle_ == -1 && writeHandle_ != -1)
    {
        if (isServer_)
            readHandle_ = open((pipePath + pipeName_ + "SR").CString(), O_RDONLY | O_NDELAY);
        else
            readHandle_ = open((pipePath + pipeName_ + "CR").CString(), O_RDONLY | O_NDELAY);
    }

    if (readHandle_ != -1)
    {
        ssize_t readNow = read(readHandle_, dest, size);
        return readNow < 0 ? 0 : (unsigned)readNow;
    }
    else
        return 0;
}

unsigned NamedPipe::Write(const void* data, unsigned size)
{
    // Attempt to open late if only the read handle is open yet
    if (writeHandle_ == -1 && readHandle_ != -1)
    {
        if (isServer_)
            writeHandle_ = open((pipePath + pipeName_ + "CR").CString(), O_WRONLY | O_NDELAY);
        else
            writeHandle_ = open((pipePath + pipeName_ + "SR").CString(), O_WRONLY | O_NDELAY);
    }

    // Loop until all bytes written in case of partial write
    if (writeHandle_ != -1)
    {
        ssize_t written = 0;
        while (written < (ssize_t)size)
        {
            ssize_t writtenNow = write(writeHandle_, ((const unsigned char*)data) + written, size - written);
            if (writtenNow < 0)
                return 0; // Error while writing
            written += writtenNow;
        }

        return (unsigned)written;
    }
    else
        return 0;
}

void NamedPipe::Close()
{
    if (readHandle_ != -1 || writeHandle_ != -1)
    {
        URHO3D_PROFILE(CloseNamedPipe);
        SAFE_CLOSE(readHandle_);
        SAFE_CLOSE(writeHandle_);

        if (isServer_)
        {
            String serverReadName = pipePath + pipeName_ + "SR";
            String clientReadName = pipePath + pipeName_ + "CR";
            unlink(serverReadName.CString());
            unlink(clientReadName.CString());
            isServer_ = false;
        }

        pipeName_.Clear();
    }
}

bool NamedPipe::IsOpen() const
{
    return readHandle_ != -1 || writeHandle_ != -1;
}

bool NamedPipe::IsEof() const
{
    // Attempt to open late if only the write handle is open yet
    if (readHandle_ == -1 && writeHandle_ != -1)
    {
        if (isServer_)
            readHandle_ = open((pipePath + pipeName_ + "SR").CString(), O_RDONLY | O_NDELAY);
        else
            readHandle_ = open((pipePath + pipeName_ + "CR").CString(), O_RDONLY | O_NDELAY);
    }

    if (readHandle_ != -1)
    {
        fd_set set;
        FD_ZERO(&set);      // NOLINT(modernize-use-bool-literals)
        FD_SET(readHandle_, &set);

        struct timeval timeout{0, 1000};    // 1ms timeout for select

        return select(readHandle_ + 1, &set, nullptr, nullptr, &timeout) <= 0;
    }
    else
        return true;
}

}
