//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSThread*)_instance())
#define INSTANCE_UNSAFE ((::NSThread*)_instanceUnsafe())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    NSThread NSThread::CreateUnsafe(EntryPointType entryPoint)
    {
        return CreateUnsafe(entryPoint, (void*)nullptr);
    }

    NSThread NSThread::CreateUnsafe(EntryPointType entryPoint, void* args)
    {
        ::NSThread* t = [[::NSThread alloc] initWithBlock:^{ entryPoint(args); }];

        MemoryAllocationException::CheckNull(t);

        NSThread thread = nullptr;
        NSObjectHelper::SetPointer(thread, t);

        return thread;
    }

    NSThread NSThread::CreateUnsafe(EntryPointType entryPoint, std::nullptr_t)
    {
        return CreateUnsafe(entryPoint, (void*)nullptr);
    }

    NSThread NSThread::CurrentThread() noexcept
    {
        ::NSThread* t = [::NSThread currentThread];
        [t retain];

        NSThread current = nullptr;
        NSObjectHelper::SetPointer(current, t);

        return current;
    }

    double NSThread::CurrentThreadPriority() noexcept
    {
        return [::NSThread threadPriority];
    }

    void NSThread::CurrentThreadPriority(double priority) noexcept
    {
        [::NSThread setThreadPriority:priority];
    }

    void NSThread::Exit() noexcept
    {
        [::NSThread exit];
    }

    bool NSThread::IsCurrentThreadMain() noexcept
    {
        return (bool)[::NSThread isMainThread];
    }

    bool NSThread::IsMultiThreaded() noexcept
    {
        return (bool)[::NSThread isMultiThreaded];
    }

    NSThread NSThread::MainThread() noexcept
    {
        NSThread thread = nullptr;
        NSObjectHelper::SetPointer(thread, [::NSThread mainThread]);
        
        return thread;
    }

    void NSThread::SleepForTimeInterval(double seconds) noexcept
    {
        [::NSThread sleepForTimeInterval:seconds];
    }

    NSThread::NSThread(EntryPointType entryPoint) : NSThread(entryPoint, (void*)nullptr)
    {
    }

    NSThread::NSThread(EntryPointType entryPoint, void* args) : NSObject(nullptr)
    {
        if (entryPoint == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"entryPoint");

        _setInstance([[::NSThread alloc] initWithBlock:^{ entryPoint(args); }]);
    }

    NSThread::NSThread(EntryPointType entryPoint, std::nullptr_t) : NSThread(entryPoint, (void*)nullptr)
    {
    }

    bool NSThread::GetIsCancelledUnsafe() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isCancelled];
    }

    bool NSThread::GetIsExecutingUnsafe() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isExecuting];
    }

    bool NSThread::GetIsFinishedUnsafe() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isFinished];
    }

    bool NSThread::GetIsMainThreadUnsafe() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isMainThread];
    }

    size_t NSThread::GetStackSizeUnsafe() const noexcept
    {
        return INSTANCE_UNSAFE.stackSize;
    }

    double NSThread::GetThreadPriorityUnsafe() const noexcept
    {
        return [INSTANCE_UNSAFE threadPriority];
    }

    bool NSThread::IsCancelled() const
    {
        return (bool)[INSTANCE isCancelled];
    }

    bool NSThread::IsExecuting() const
    {
        return (bool)[INSTANCE isExecuting];
    }

    bool NSThread::IsFinished() const
    {
        return (bool)[INSTANCE isFinished];
    }

    bool NSThread::IsMainThread() const
    {
        return (bool)[INSTANCE isMainThread];
    }

    size_t NSThread::StackSize() const
    {
        return INSTANCE.stackSize;
    }

    void NSThread::StackSize(size_t stackSize) const
    {
        INSTANCE.stackSize = stackSize;
    }

    void NSThread::Start() const
    {
        [INSTANCE start];
    }

    void NSThread::StartUnsafe() const noexcept
    {
        [INSTANCE_UNSAFE start];
    }

    void NSThread::SetStackSizeUnsafe(size_t stackSize) const noexcept
    {
        INSTANCE_UNSAFE.stackSize = stackSize;
    }

    void NSThread::SetThreadPriorityUnsafe(double priority) const noexcept
    {
        INSTANCE_UNSAFE.threadPriority = priority;
    }

    double NSThread::ThreadPriority() const
    {
        return [INSTANCE threadPriority];
    }

    void NSThread::ThreadPriority(double priority) const
    {
        INSTANCE.threadPriority = priority;
    }
}

#undef INSTANCE
#undef INSTANCE_UNSAFE

