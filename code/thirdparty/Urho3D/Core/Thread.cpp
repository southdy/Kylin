//
// Copyright (c) 2008-2020 the Urho3D project.
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

#include "../Core/Thread.h"

#include <pthread.h>


namespace Urho3D
{

static void* ThreadFunctionStatic(void* data)
{
    auto* thread = static_cast<Thread*>(data);
    thread->ThreadFunction();
    pthread_exit((void*)nullptr);
    return nullptr;
}

ThreadID Thread::mainThreadID;

Thread::Thread() :
    handle_(nullptr),
    shouldRun_(false)
{
}

Thread::~Thread()
{
    Stop();
}

bool Thread::Run()
{
    // Check if already running
    if (handle_)
        return false;

    shouldRun_ = true;
    handle_ = new pthread_t;
    pthread_attr_t type;
    pthread_attr_init(&type);
    pthread_attr_setdetachstate(&type, PTHREAD_CREATE_JOINABLE);
    pthread_create((pthread_t*)handle_, &type, ThreadFunctionStatic, this);
    return handle_ != nullptr;
}

void Thread::Stop()
{
    // Check if already stopped
    if (!handle_)
        return;

    shouldRun_ = false;
    auto* thread = (pthread_t*)handle_;
    if (thread)
        pthread_join(*thread, nullptr);
    delete thread;
    handle_ = nullptr;
}

void Thread::SetPriority(int priority)
{
}

void Thread::SetMainThread()
{
    mainThreadID = GetCurrentThreadID();
}

ThreadID Thread::GetCurrentThreadID()
{
    return pthread_self();
}

bool Thread::IsMainThread()
{
    return GetCurrentThreadID() == mainThreadID;
}

}
