//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    RegistryKeyView RegistryKey::ClassesRoot() noexcept
    {
        return RegistryKeyView(HKEY_CLASSES_ROOT);
    }

    RegistryKeyView RegistryKey::CurrentConfig() noexcept
    {
        return RegistryKeyView(HKEY_CURRENT_CONFIG);
    }

    RegistryKeyView RegistryKey::CurrentUser() noexcept
    {
        return RegistryKeyView(HKEY_CURRENT_USER);
    }

    RegistryKeyView RegistryKey::LocalMachine() noexcept
    {
        return RegistryKeyView(HKEY_LOCAL_MACHINE);
    }

    RegistryKeyView RegistryKey::Users() noexcept
    {
        return RegistryKeyView(HKEY_USERS);
    }

    RegistryKey::~RegistryKey()
    {
        if (IsOpen()) ::RegCloseKey(_key);
    }

    RegistryKey& RegistryKey::operator=(RegistryKey&& right) noexcept
    {
        RegistryKey::~RegistryKey();

        _key = right._key;

        right._key = nullptr;

        return *this;
    }
}
