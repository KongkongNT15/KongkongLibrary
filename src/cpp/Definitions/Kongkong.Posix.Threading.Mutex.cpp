//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    Mutex::Mutex(MutexKind kind)
    {
        ::pthread_mutexattr_t attribute;

        if (::pthread_mutexattr_settype(&attribute, (int)kind) == EOF) [[unlikely]] throw PosixException();

        if (::pthread_mutex_init(this, &attribute) == EOF) [[unlikely]] throw PosixException();
    }

    Mutex::~Mutex()
    {
        ::pthread_mutex_destroy(this);
    }

    void Mutex::Lock()
    {
        if (::pthread_mutex_lock(this) == EOF) [[unlikely]] throw PosixException();
    }

    String Mutex::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::Threading::Mutex");
    }

    bool Mutex::TryLock() noexcept
    {
        return ::pthread_mutex_trylock(this) != EBUSY;
    }
}
