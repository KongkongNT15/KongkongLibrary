//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    Mutex Mutex::Open(const char16_t* name)
    {
        return Open(name, false);
    }

    Mutex Mutex::Open(String const& name)
    {
        return Open(name.c_str());
    }

    Mutex Mutex::Open(const char16_t* name, bool isInheritHandle)
    {
        Mutex mutex = nullptr;

        ::HANDLE result = ::OpenMutexW(SYNCHRONIZE, isInheritHandle, (const wchar_t*)name);

        if (result == nullptr) [[unlikely]] throw HResultException();

        mutex._h.__setRawHandle(result, ClassType::Mutex);

        return mutex;
    }

    Mutex Mutex::Open(String const& name, bool isInheritHandle)
    {
        return Open(name.c_str(), isInheritHandle);
    }

    Mutex::Mutex() : Mutex(nullptr, false, nullptr)
    {
    }

    Mutex::Mutex(bool isInitialOwner) : Mutex(nullptr, isInitialOwner, nullptr)
    {
    }

    Mutex::Mutex(::SECURITY_ATTRIBUTES& securityAttributes) : Mutex(nullptr, false, &securityAttributes)
    {
    }

    Mutex::Mutex(bool isInitialOwner, ::SECURITY_ATTRIBUTES& securityAttributes) : Mutex(nullptr, false, nullptr)
    {
    }

    Mutex::Mutex(const char16_t* name) : Mutex(name, false, nullptr)
    {
    }

    Mutex::Mutex(const char16_t* name, bool isInitialOwner) : Mutex(name, isInitialOwner, nullptr)
    {
    }

    Mutex::Mutex(const char16_t* name, bool isInitialOwner, ::SECURITY_ATTRIBUTES& securityAttributes) : Mutex(name, isInitialOwner, &securityAttributes)
    {
    }

    Mutex::Mutex(const char16_t* name, ::SECURITY_ATTRIBUTES& securityAttributes) : Mutex(name, false, &securityAttributes)
    {
    }

    Mutex::Mutex(String const& name) : Mutex(name.c_str(), false, nullptr)
    {
    }

    Mutex::Mutex(String const& name, bool isInitialOwner) : Mutex(name.c_str(), isInitialOwner, nullptr)
    {
    }

    Mutex::Mutex(String const& name, bool isInitialOwner, ::SECURITY_ATTRIBUTES& securityAttributes) : Mutex(name.c_str(), isInitialOwner, &securityAttributes)
    {
    }

    Mutex::Mutex(String const& name, ::SECURITY_ATTRIBUTES& securityAttributes) : Mutex(name.c_str(), false, &securityAttributes)
    {
    }

    Mutex::Mutex(std::nullptr_t, bool isInitialOwner) : Mutex(nullptr, isInitialOwner, nullptr)
    {
    }

    Mutex::Mutex(std::nullptr_t, ::SECURITY_ATTRIBUTES& securityAttributes) : Mutex(nullptr, false, &securityAttributes)
    {
    }

    Mutex::Mutex(std::nullptr_t, bool isInitialOwner, ::SECURITY_ATTRIBUTES& securityAttributes) : Mutex(nullptr, false, nullptr)
    {
    }

    WaitStatus Mutex::Wait() const
    {
        return Wait(INFINITE);
    }

    WaitStatus Mutex::Wait(uint32_t milliSeconds) const
    {
        WaitStatus result = (WaitStatus)::WaitForSingleObject(_h.__rawHandle(), milliSeconds);
        if (result == WaitStatus::Failed) [[unlikely]] throw HResultException();

        return result;
    }

    WaitStatus Mutex::LockUnsafe() const noexcept
    {
        return LockUnsafe(INFINITE);
    }

    WaitStatus Mutex::LockUnsafe(uint32_t milliSeconds) const noexcept
    {
        return (WaitStatus)::WaitForSingleObject(_h.__rawHandle(), milliSeconds);
    }

    void Mutex::Release() const
    {
        if (ReleaseUnsafe() == false) [[unlikely]] throw HResultException();
    }

    bool Mutex::ReleaseUnsafe() const noexcept
    {
        return (bool)::ReleaseMutex(_h.__rawHandle());
    }

    Mutex::Mutex(const char16_t* name, bool isInitialOwner, ::LPSECURITY_ATTRIBUTES lpSecurityAttributes) : WaitHandle(nullptr)
    {
        ::HANDLE hMutex = ::CreateMutexW(lpSecurityAttributes, isInitialOwner, (const wchar_t*)name);

        if (hMutex == nullptr) [[unlikely]] throw HResultException();

        _h.__rawHandle(hMutex, ClassType::Mutex);
    }

    String Mutex::_toString(Handle const&)
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::Threading::Mutex");
    }
}
