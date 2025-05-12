//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    void RegistryKeyBase::DeleteSubKey(const char16_t* subKeyName) const
    {
        Primitives::WinRegistry::DeleteSubKey(_key, subKeyName);
    }

    void RegistryKeyBase::DeleteSubKey(String const& subKeyName) const
    {
        Primitives::WinRegistry::DeleteSubKey(_key, subKeyName);
    }

    void RegistryKeyBase::DeleteSubKey(const char16_t* subKeyName, RegistryKeyAccessRight accessRight) const
    {
        Primitives::WinRegistry::DeleteSubKey(_key, subKeyName, accessRight);
    }

    void RegistryKeyBase::DeleteSubKey(String const& subKeyName, RegistryKeyAccessRight accessRight) const
    {
        Primitives::WinRegistry::DeleteSubKey(_key, subKeyName, accessRight);
    }

    int32_t RegistryKeyBase::DeleteSubKeyUnsafe(const char16_t* subKeyName) const noexcept
    {
        return Primitives::WinRegistry::DeleteSubKeyUnsafe(_key, subKeyName);
    }

    int32_t RegistryKeyBase::DeleteSubKeyUnsafe(String const& subKeyName) const noexcept
    {
        return Primitives::WinRegistry::DeleteSubKeyUnsafe(_key, subKeyName);
    }

    int32_t RegistryKeyBase::DeleteSubKeyUnsafe(const char16_t* subKeyName, RegistryKeyAccessRight accessRight) const noexcept
    {
        return Primitives::WinRegistry::DeleteSubKeyUnsafe(_key, subKeyName, accessRight);
    }

    int32_t RegistryKeyBase::DeleteSubKeyUnsafe(String const& subKeyName, RegistryKeyAccessRight accessRight) const noexcept
    {
        return Primitives::WinRegistry::DeleteSubKeyUnsafe(_key, subKeyName, accessRight);
    }

    void RegistryKeyBase::DeleteTree(const char16_t* subKeyName) const
    {
        Primitives::WinRegistry::DeleteTree(_key, subKeyName);
    }

    void RegistryKeyBase::DeleteTree(String const& subKeyName) const
    {
        Primitives::WinRegistry::DeleteTree(_key, subKeyName);
    }

    int32_t RegistryKeyBase::DeleteTreeUnsafe(const char16_t* subKeyName) const noexcept
    {
        return Primitives::WinRegistry::DeleteTreeUnsafe(_key, subKeyName);
    }

    int32_t RegistryKeyBase::DeleteTreeUnsafe(String const& subKeyName) const noexcept
    {
        return Primitives::WinRegistry::DeleteTreeUnsafe(_key, subKeyName);
    }

    void RegistryKeyBase::DeleteValue(const char16_t* valueName) const
    {
        Primitives::WinRegistry::DeleteValue(_key, valueName);
    }

    void RegistryKeyBase::DeleteValue(String const& valueName) const
    {
        Primitives::WinRegistry::DeleteValue(_key, valueName);
    }

    int32_t RegistryKeyBase::DeleteValueUnsafe(const char16_t* valueName) const noexcept
    {
        return Primitives::WinRegistry::DeleteValueUnsafe(_key, valueName);
    }

    int32_t RegistryKeyBase::DeleteValueUnsafe(String const& valueName) const noexcept
    {
        return Primitives::WinRegistry::DeleteValueUnsafe(_key, valueName);
    }

    void RegistryKeyBase::Flush() const
    {
        Primitives::WinRegistry::FlushKey(_key);
    }

    int32_t RegistryKeyBase::FlushUnsafe() const noexcept
    {
        return ::RegFlushKey(_key);
    }

    RegistryKey RegistryKeyBase::GetSubKey(const char16_t* subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) const
    {
        return RegistryKey(Primitives::WinRegistry::OpenKey(_key, subKeyName, option, accessRight));
    }

    RegistryKey RegistryKeyBase::GetSubKey(String const& subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) const
    {
        return GetSubKey(subKeyName.c_str(), option, accessRight);
    }

    RegistryKey RegistryKeyBase::GetSubKeyUnsafe(const char16_t* subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) const noexcept
    {
        return RegistryKey(Primitives::WinRegistry::OpenKey(_key, subKeyName, option, accessRight));
    }

    RegistryKey RegistryKeyBase::GetSubKeyUnsafe(String const& subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) const noexcept
    {
        return GetSubKey(subKeyName.c_str(), option, accessRight);
    }

    RegistryValue RegistryKeyBase::GetValue(const char16_t* name) const
    {
        RegistryValueType type;
        DWORD size;
        auto result = ::RegGetValueW(_key, nullptr, (const wchar_t*)name, RRF_RT_ANY | RRF_NOEXPAND, (DWORD*)&type, nullptr, &size);
    
        if (result == ERROR_FILE_NOT_FOUND) [[unlikely]] throw HResultException();

        Object obj = nullptr;
        
        switch (type) {
            case RegistryValueType::None:
            {
                break;
            }
            case RegistryValueType::String:
            {
                if (size == 0) [[unlikely]] {
                    obj = Object::BoxValue(String(true));
                    break;
                }

                ssize_t capacity = size / 2;

                char16_t* p = String::AllocMemoryUnsafe(capacity);

                ::RegGetValueW(_key, nullptr, (const wchar_t*)name, RRF_RT_ANY, nullptr, p, &size);

                obj = Object::BoxValue(String::WrapUnsafe(capacity, capacity - 1, p));
                break;
            }
            case RegistryValueType::ExpandString:
            {
                if (size == 0) [[unlikely]] {
                    obj = Object::BoxValue(String(true));
                    break;
                }
            
                ssize_t capacity = size / 2;

                char16_t* p = String::AllocMemoryUnsafe(capacity);

                ::RegGetValueW(_key, nullptr, (const wchar_t*)name, RRF_RT_ANY | RRF_NOEXPAND, nullptr, p, &size);

                obj = Object::BoxValue(String::WrapUnsafe(capacity, capacity - 1, p));
                break;
            }
            case RegistryValueType::Binary:
            {
                Collections::Array<uint8_t> arr(size);

                ::RegGetValueW(_key, nullptr, (const wchar_t*)name, RRF_RT_ANY, nullptr, arr->Data(), &size);

                obj = std::move(arr);

                break;
            }
            case RegistryValueType::DoubleWord:
            {
                uint32_t value;
                size = sizeof(value);
                ::RegGetValueW(_key, nullptr, (const wchar_t*)name, RRF_RT_ANY, nullptr, &value, &size);

                obj = Object::BoxValue(value);

                break;
            }
            case RegistryValueType::MultiString:
            {
                Collections::PointerList<String> list;
                
                if (size == 0) [[unlikely]] {
                    obj = std::move(list);
                    break;
                }

                auto& rList = Object::GetInstanceUnsafe(list);

                char16_t* p = (char16_t*)::malloc(size);

                MemoryAllocationException::CheckNull(p);

                ::RegGetValueW(_key, nullptr, (const wchar_t*)name, RRF_RT_ANY, nullptr, p, &size);

                char16_t* tmp = p;

                while (*tmp) {
                    String str = String::FromPointerUnsafe(tmp, true);

                    tmp += str.Length() + 1;

                    rList.Append(std::move(str));
                }

                ::free(p);
                obj = std::move(list);

                break;
            }
            case RegistryValueType::QuadWord:
            {
                uint64_t value;
                size = sizeof(value);
                ::RegGetValueW(_key, nullptr, (const wchar_t*)name, RRF_RT_ANY, nullptr, &value, &size);

                obj = Object::BoxValue(value);

                break;
            }
            default: [[unlikely]] break;
        }

        return RegistryValue(std::move(obj), type);
    }

    RegistryValue RegistryKeyBase::GetValue(String const& name) const
    {
        return GetValue(name.c_str());
    }
}
