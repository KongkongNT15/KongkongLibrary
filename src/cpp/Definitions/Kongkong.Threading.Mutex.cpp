//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{
#ifdef KONGKONG_ENV_WINDOWS
    Mutex::Mutex() noexcept : _hMutex(::CreateMutexW(nullptr, FALSE, nullptr))
    {
        //if (_hMutex == nullptr) [[unlikely]] throw Exception
    }

    Mutex::Mutex(Mutex const& mutex) noexcept : _hMutex(nullptr)
    {
        ::DuplicateHandle(::GetCurrentProcess(), mutex._hMutex, ::GetCurrentProcess(), &_hMutex, 0, FALSE, DUPLICATE_SAME_ACCESS);
    }

    Mutex::Mutex(Mutex&& mutex) noexcept : _hMutex(mutex._hMutex)
    {
        mutex._hMutex = nullptr;
    }

    Mutex::~Mutex() noexcept
    {
        if (_hMutex != nullptr) ::CloseHandle(_hMutex);
    }

    Mutex& Mutex::operator=(Mutex const& mutex) noexcept
    {
        if (_hMutex != nullptr) ::CloseHandle(_hMutex);
        ::DuplicateHandle(::GetCurrentProcess(), mutex._hMutex, ::GetCurrentProcess(), &_hMutex, 0, FALSE, DUPLICATE_SAME_ACCESS);
    
        return *this;
    }

    Mutex& Mutex::operator=(Mutex&& mutex) noexcept
    {
        if (_hMutex != nullptr) ::CloseHandle(_hMutex);

        _hMutex = mutex._hMutex;

        mutex._hMutex = nullptr;

        return *this;
    }

    void Mutex::Lock()
    {
        ::WaitForSingleObject(_hMutex, INFINITE);
    }

    void Mutex::Unlock()
    {
        if (::ReleaseMutex(_hMutex) == FALSE) [[unlikely]] throw InvalidOperationException(u"Mutexのアンロック操作に失敗しました");
    }

#elif defined(__POSIX__)
    Mutex::Mutex() noexcept : _isActive(true)
    {
        ::pthread_mutex_init(&_mutex, nullptr);
    }

    Mutex::Mutex(Mutex&& mutex) noexcept : _mutex(mutex._mutex)
    {
        mutex._isActive = false;
    }

    Mutex::~Mutex() noexcept
    {
        if (_isActive) ::pthread_mutex_destroy(&_mutex);
    }

    Mutex& Mutex::operator=(Mutex&& mutex) noexcept
    {
        Mutex::~Mutex();

        _mutex = mutex._mutex;

        mutex._isActive = false;

        return *this;
    }

    void Mutex::Lock()
    {
        ::pthread_mutex_lock(&_mutex);
    }

    void Mutex::Unlock()
    {
        ::pthread_mutex_unlock(&_mutex);
    }
#endif

    String Mutex::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Threading::Mutex");
    }

    
}
