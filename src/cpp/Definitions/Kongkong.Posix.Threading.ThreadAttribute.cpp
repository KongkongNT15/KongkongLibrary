//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    ThreadAttribute::ThreadAttribute()
    {
        if (::pthread_attr_init(this) != 0) [[unlikely]] throw PosixException();
    }

    ThreadAttribute::~ThreadAttribute()
    {
        ::pthread_attr_destroy(this);
    }

    ThreadCreate ThreadAttribute::DetachState() const noexcept
    {
        int result;

        ::pthread_attr_getdetachstate(this, &result);

        return (ThreadCreate)result;
    }

    void ThreadAttribute::DetachState(ThreadCreate value)
    {
        if (SetDetachStateUnsafe(value) != 0) [[unlikely]] throw PosixException();
    }

    size_t ThreadAttribute::GuardSize() const noexcept
    {
        size_t result;

        ::pthread_attr_getguardsize(this, &result);

        return result;
    }

    void ThreadAttribute::GuardSize(size_t guardSize)
    {
        if (SetGuardSizeUnsafe(guardSize) != 0) [[unlikely]] throw PosixException();
    }

    ThreadScope ThreadAttribute::Scope() const noexcept
    {
        int result;
        ::pthread_attr_getscope(this, &result);

        return (ThreadScope)result;
    }

    void ThreadAttribute::Scope(ThreadScope scope)
    {
        if (SetScopeUnsafe(scope) != 0) [[unlikely]] throw PosixException();
    }

    int ThreadAttribute::SetDetachStateUnsafe(ThreadCreate value) noexcept
    {
        return ::pthread_attr_setdetachstate(this, (int)value);
    }

    int ThreadAttribute::SetGuardSizeUnsafe(size_t guardSize) noexcept
    {
        return ::pthread_attr_setguardsize(this, guardSize);
    }

    int ThreadAttribute::SetScopeUnsafe(ThreadScope scope) noexcept
    {
        return ::pthread_attr_setscope(this, (int)scope);
    }

    int ThreadAttribute::SetStackSizeUnsafe(size_t size) noexcept
    {
        return ::pthread_attr_setstacksize(this, size);
    }

    int ThreadAttribute::SetStackUnsafe(ThreadStackInfo const& info) noexcept
    {
        return ::pthread_attr_setstack(this, info.StackAddress(), info.StackSize());
    }

    int ThreadAttribute::SetStackUnsafe(void* stackAddress, size_t stackSize) noexcept
    {
        return ::pthread_attr_setstack(this, stackAddress, stackSize);
    }

    ThreadStackInfo ThreadAttribute::Stack() const noexcept
    {
        void* p;
        size_t stackSize;

        ::pthread_attr_getstack(this, &p, &stackSize);

        return ThreadStackInfo(p, stackSize);
    }

    void ThreadAttribute::Stack(ThreadStackInfo const& info)
    {
        if (SetStackUnsafe(info) != 0) [[unlikely]] throw PosixException();
    }

    void ThreadAttribute::Stack(void* stackAddress, size_t stackSize)
    {
        if (SetStackUnsafe(stackAddress, stackSize) != 0) [[unlikely]] throw PosixException();
    }

    void* ThreadAttribute::StackAddress() const noexcept
    {
        void* p;

        ::pthread_attr_getstackaddr(this, &p);

        return p;
    }

    size_t ThreadAttribute::StackSize() const noexcept
    {
        size_t result;
        ::pthread_attr_getstacksize(this, &result);

        return result;
    }

    void ThreadAttribute::StackSize(size_t size)
    {
        if (SetStackSizeUnsafe(size) != 0) [[unlikely]] throw PosixException();
    }

    String ThreadAttribute::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::Threading::ThreadAttribute");
    }
}
