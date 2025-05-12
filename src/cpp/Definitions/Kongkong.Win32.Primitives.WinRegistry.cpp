//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    void WinRegistry::CloseKey(::HKEY key)
    {
        ::LSTATUS status = ::RegCloseKey(key);
        if (status != ERROR_SUCCESS) [[unlikely]] throw HResultException(status);
    }

    void WinRegistry::DeleteSubKey(::HKEY key, const char16_t* subKeyName)
    {
        ::LSTATUS status = ::RegDeleteKeyW(key, (const wchar_t*)subKeyName);
        if (status != ERROR_SUCCESS) [[unlikely]] throw HResultException(status);
    }

    void WinRegistry::DeleteSubKey(::HKEY hKey, String const& subKeyName)
    {
        DeleteSubKey(hKey, subKeyName.c_str());
    }

    void WinRegistry::DeleteSubKey(::HKEY hKey, const char16_t* subKeyName, RegistryKeyAccessRight accessRight)
    {
        ::LSTATUS status = ::RegDeleteKeyExW(hKey, (const wchar_t*)subKeyName, (::REGSAM)accessRight, 0);
        if (status != ERROR_SUCCESS) [[unlikely]] throw HResultException(status);
    }

    void WinRegistry::DeleteSubKey(::HKEY hKey, String const& subKeyName, RegistryKeyAccessRight accessRight)
    {
        DeleteSubKey(hKey, subKeyName.c_str(), accessRight);
    }

    int32_t WinRegistry::DeleteSubKeyUnsafe(::HKEY key, const char16_t* subKeyName) noexcept
    {
        return ::RegDeleteKeyW(key, (const wchar_t*)subKeyName);
    }

    int32_t WinRegistry::DeleteSubKeyUnsafe(::HKEY hKey, String const& subKeyName) noexcept
    {
        return DeleteSubKeyUnsafe(hKey, subKeyName.c_str());
    }

    int32_t WinRegistry::DeleteSubKeyUnsafe(::HKEY hKey, const char16_t* subKeyName, RegistryKeyAccessRight accessRight) noexcept
    {
        return ::RegDeleteKeyExW(hKey, (const wchar_t*)subKeyName, (::REGSAM)accessRight, 0);
    }

    int32_t WinRegistry::DeleteSubKeyUnsafe(::HKEY hKey, String const& subKeyName, RegistryKeyAccessRight accessRight) noexcept
    {
        return DeleteSubKeyUnsafe(hKey, subKeyName.c_str(), accessRight);
    }

    void WinRegistry::DeleteTree(::HKEY key, const char16_t* valueName)
    {
        ::LSTATUS status = ::RegDeleteTreeW(key, (const wchar_t*)valueName);
        if (status != ERROR_SUCCESS) [[unlikely]] throw HResultException(status);
    }

    void WinRegistry::DeleteTree(::HKEY hKey, String const& subKeyName)
    {
        DeleteTree(hKey, subKeyName.c_str());
    }

    int32_t WinRegistry::DeleteTreeUnsafe(::HKEY key, const char16_t* valueName) noexcept
    {
        return ::RegDeleteTreeW(key, (const wchar_t*)valueName);
    }

    int32_t WinRegistry::DeleteTreeUnsafe(::HKEY hKey, String const& subKeyName) noexcept
    {
        return DeleteTreeUnsafe(hKey, subKeyName.c_str());
    }

    void WinRegistry::DeleteValue(::HKEY key, const char16_t* valueName)
    {
        ::LSTATUS status = ::RegDeleteValueW(key, (const wchar_t*)valueName);
        if (status != ERROR_SUCCESS) [[unlikely]] throw HResultException(status);
    }

    void WinRegistry::DeleteValue(::HKEY hKey, String const& valueName)
    {
        DeleteValue(hKey, valueName.c_str());
    }

    int32_t WinRegistry::DeleteValueUnsafe(::HKEY key, const char16_t* valueName) noexcept
    {
        return ::RegDeleteValueW(key, (const wchar_t*)valueName);
    }

    int32_t WinRegistry::DeleteValueUnsafe(::HKEY hKey, String const& valueName) noexcept
    {
        return DeleteValueUnsafe(hKey, valueName.c_str());
    }

    void WinRegistry::FlushKey(::HKEY key)
    {
        ::LSTATUS status = ::RegFlushKey(key);
        if (status != ERROR_SUCCESS) [[unlikely]] throw HResultException(status);
    }

    ::HKEY WinRegistry::OpenKey(::HKEY hKey, const char16_t* subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight)
    {
        ArgumentNullException::CheckNull(subKeyName, u"subKeyName");
        Text::StringHelper::CheckEmptyUnsafe(subKeyName);
        
        ::HKEY key;
        ::LSTATUS status = ::RegOpenKeyExW(hKey, (const wchar_t*)subKeyName, (DWORD)option, (::REGSAM)accessRight, &key);
        if (status != ERROR_SUCCESS) [[unlikely]] throw HResultException(status);

        return key;
    }

    ::HKEY WinRegistry::OpenKey(::HKEY hKey, String const& subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight)
    {
        Text::StringHelper::CheckEmpty(subKeyName);
        
        ::HKEY key;
        ::LSTATUS status = ::RegOpenKeyExW(hKey, (const wchar_t*)subKeyName.c_str(), (DWORD)option, (::REGSAM)accessRight, &key);
        if (status != ERROR_SUCCESS) [[unlikely]] throw HResultException(status);

        return key;
    }

    ::HKEY WinRegistry::OpenKeyUnsafe(::HKEY hKey, const char16_t* subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) noexcept
    {
        ::HKEY key;
        RegOpenKeyExW(hKey, (const wchar_t*)subKeyName, (::DWORD)option, (::REGSAM)accessRight, &key);

        return key;
    }

    ::HKEY WinRegistry::OpenKeyUnsafe(::HKEY hKey, String const& subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) noexcept
    {
        return OpenKeyUnsafe(hKey, subKeyName.c_str(), option, accessRight);
    }
}
