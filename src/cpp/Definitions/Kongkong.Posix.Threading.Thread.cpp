//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    Thread Thread::Current() noexcept
    {
        return ::pthread_self();
    }

    Thread::Thread(EntryPoint entryPoint) : Thread(entryPoint, nullptr, nullptr)
    {
    }
    
    Thread::Thread(EntryPoint entryPoint, std::nullptr_t) : Thread(entryPoint, nullptr, nullptr)
    {
    }

    Thread::Thread(EntryPoint entryPoint, void* args) : Thread(entryPoint, args, nullptr)
    {
    }

    Thread::Thread(EntryPoint entryPoint, ThreadAttribute const& attribute) : Thread(entryPoint, nullptr, &attribute.pthread_attr_t())
    {
    }

    Thread::Thread(EntryPoint entryPoint, std::nullptr_t, ThreadAttribute const& attribute) : Thread(entryPoint, nullptr, &attribute.pthread_attr_t())
    {
    }

    Thread::Thread(EntryPoint entryPoint, void* args, ThreadAttribute const& attribute) : Thread(entryPoint, args, &attribute.pthread_attr_t())
    {
    }

    Thread::~Thread()
    {
        if (_t != nullptr && _t != ::pthread_self()) ::pthread_detach(_t);
    }

    Thread::Thread(EntryPoint entryPoint, void* args, const ::pthread_attr_t* attribute)
    {
        if (::pthread_create(&_t, attribute, entryPoint, args) != 0) [[unlikely]] throw PosixException();
    }

    Thread& Thread::operator=(Thread&& right) noexcept
    {
        Thread::~Thread();

        _t = right._t;

        right._t = nullptr;

        return *this;
    }

    void Thread::Cancel() const
    {
        if (::pthread_cancel(_t) != 0) [[unlikely]] throw PosixException();
    }

    int Thread::CancelUnsafe() const noexcept
    {
        return ::pthread_cancel(_t);
    }

    void* Thread::Join() const
    {
        void* result;
        if (::pthread_join(_t, &result) != 0) [[unlikely]] throw PosixException();

        return result;
    }

    void* Thread::JoinUnsafe() const noexcept
    {
        void* result;
        ::pthread_join(_t, &result);

        return result;
    }

    void Thread::Kill(int signal)
    {
        if (::pthread_kill(_t, signal) != 0) [[unlikely]] throw PosixException();
    }

    int Thread::KillUnsafe(int signal) noexcept
    {
        return ::pthread_kill(_t, signal);
    }

    bool operator==(Thread const& left, Thread const& right) noexcept
    {
        if (left._t == nullptr) return right._t == nullptr;

        return ::pthread_equal(left._t, right._t) > 0;
    }

    bool operator!=(Thread const& left, Thread const& right) noexcept
    {
        return !(left == right);
    }
}
