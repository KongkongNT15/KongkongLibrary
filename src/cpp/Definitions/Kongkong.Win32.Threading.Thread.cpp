//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    Thread Thread::Current() noexcept
    {
        Thread thread = nullptr;
        thread._h.__setRawHandle(::GetCurrentThread(), ClassType::Thread);

        return thread;
    }

    uint32_t Thread::CurrentProcessorNumber() noexcept
    {
        return ::GetCurrentProcessorNumber();
    }

    ProcessorNumber Thread::CurrentProcessorGroupAndNumber() noexcept
    {
        ProcessorNumber result;
        ::GetCurrentProcessorNumberEx(&result);

        return result;
    }

    WaitObjectInfo Thread::Run(::LPTHREAD_START_ROUTINE func)
    {
        return Run(func, nullptr, INFINITE);
    }

    WaitObjectInfo Thread::Run(::LPTHREAD_START_ROUTINE func, uint32_t milliseconds)
    {
        return Run(func, nullptr, milliseconds);
    }

    WaitObjectInfo Thread::Run(::LPTHREAD_START_ROUTINE func, void* parameter)
    {
        return Run(func, parameter, INFINITE);
    }

    WaitObjectInfo Thread::Run(::LPTHREAD_START_ROUTINE func, void* parameter, uint32_t milliseconds)
    {
        Thread thread(func, parameter);

        return Primitives::SyncHAPI::WaitForSingleThread(thread._h.__rawHandle(), milliseconds);
    }

    void Thread::Sleep(uint32_t milliseconds) noexcept
    {
        ::Sleep(milliseconds);
    }

    WaitStatus Thread::Sleep(uint32_t milliseconds, bool isAlertable) noexcept
    {
        return (WaitStatus)::SleepEx(milliseconds, isAlertable);
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func) : Thread(func, nullptr, 0, ThreadStart::RightAway)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, ThreadStart flag) : Thread(func, nullptr, 0, flag)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, void* parameter) : Thread(func, parameter, 0, ThreadStart::RightAway)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, void* parameter, ThreadStart flag) : Thread(func, parameter, 0, flag)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, size_t stackSize, ThreadStart flag) : Thread(func, nullptr, stackSize, flag)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, void* parameter, size_t stackSize, ThreadStart flag) : WaitHandle(nullptr)
    {
        ::HANDLE handle = ::CreateThread(nullptr, stackSize, func, parameter, (DWORD)flag, nullptr);

        if (handle == nullptr) [[unlikely]] throw HResultException();

        _h.__rawHandle(handle, ClassType::Thread);
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, ::SECURITY_ATTRIBUTES& securityAttributes) : Thread(func, nullptr, 0, ThreadStart::RightAway, securityAttributes)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, ThreadStart flag, ::SECURITY_ATTRIBUTES& securityAttributes) : Thread(func, nullptr, 0, flag, securityAttributes)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, void* parameter, ::SECURITY_ATTRIBUTES& securityAttributes) : Thread(func, parameter, 0, ThreadStart::RightAway, securityAttributes)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, size_t stackSize, ThreadStart flag, ::SECURITY_ATTRIBUTES& securityAttributes) : Thread(func, nullptr, stackSize, flag, securityAttributes)
    {
    }

    Thread::Thread(::LPTHREAD_START_ROUTINE func, void* parameter, size_t stackSize, ThreadStart flag, ::SECURITY_ATTRIBUTES& securityAttributes) : WaitHandle(nullptr)
    {
        ::HANDLE handle = ::CreateThread(&securityAttributes, stackSize, func, parameter, (DWORD)flag, nullptr);

        if (handle == nullptr) [[unlikely]] throw HResultException();

        _h.__rawHandle(handle, ClassType::Thread);
    }

    uint32_t Thread::ExitCode() const
    {
        return Primitives::ProcessThreadAPI::GetExitCodeThread(_h.__rawHandle());
    }

    uint32_t Thread::GetExitCodeUnsafe() const noexcept
    {
        return Primitives::ProcessThreadAPI::GetExitCodeThreadUnsafe(_h.__rawHandle());
    }

    uint32_t Thread::Resume() const
    {
        return Primitives::ProcessThreadAPI::ResumeThread(_h.__rawHandle());
    }

    uint32_t Thread::ResumeUnsafe() const noexcept
    {
        return ::ResumeThread(_h.__rawHandle());
    }

    uint32_t Thread::Suspend() const
    {
        return Primitives::ProcessThreadAPI::SuspendThread(_h.__rawHandle());
    }

    uint32_t Thread::SuspendUnsafe() const noexcept
    {
        return ::SuspendThread(_h.__rawHandle());
    }

    void Thread::Terminate(uint32_t exitCode) const
    {
        return Primitives::ProcessThreadAPI::TerminateThread(_h.__rawHandle(), exitCode);
    }

    bool Thread::TerminateUnsafe(uint32_t exitCode) const noexcept
    {
        return (bool)::TerminateThread(_h.__rawHandle(), exitCode);
    }

    uint32_t Thread::ThreadId() const
    {
        return Primitives::ProcessThreadAPI::GetThreadId(_h.__rawHandle());
    }

    uint32_t Thread::ThreadIdUnsafe() const noexcept
    {
        return ::GetThreadId(_h.__rawHandle());
    }

    String Thread::_toString(Handle const&)
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::Thread");
    }

}

CREATE_CLASS_TYPE(Threading::Thread, Thread)
