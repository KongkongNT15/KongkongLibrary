//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    String Environment::_newLine = String::FromLiteral(u"\r\n");

    String Environment::CurrentDirectory()
    {
        constexpr auto maxLength = Primitives::FileAPI::MaxPathLength() + 1;
        DWORD length = maxLength;

        char16_t* p;
        DWORD ret;
        p = String::AllocMemoryUnsafe(length);

        ret = ::GetCurrentDirectoryW(length, (wchar_t*)p);

        if (ret == 0u) [[unlikely]] {
            String::FreeMemoryUnsafe(p);

            throw HResultException();
        }

        if (ret >= length) {
            length = ret;
            String::FreeMemoryUnsafe(p);
            p = String::AllocMemoryUnsafe(length);

            if (::GetCurrentDirectoryW(length, (wchar_t*)p) == 0u) [[unlikely]] {
                String::FreeMemoryUnsafe(p);

                throw HResultException();
            }
        }

        return String::WrapUnsafe(length, p);
    }

    void Environment::CurrentDirectory(const char16_t* path)
    {
        if (::SetCurrentDirectoryW((const wchar_t*)path) == 0) throw HResultException();
    }

    void Environment::CurrentDirectory(String const& path)
    {
        CurrentDirectory(path.c_str());
    }

    Collections::IArray<String> Environment::GetStrings()
    {
        LPWCH envstr = ::GetEnvironmentStringsW();

        if (envstr == nullptr) [[unlikely]] throw HResultException();

        char16_t* tmp = (char16_t*)envstr;
        size_t tmpLength;
        Collections::Turbo::FastArrayList<String> list;

        while (*tmp != u'\0') {
            tmpLength = Text::StringHelper::GetLengthUnsafe(tmp);
            list.Append(String::FromPointerUnsafe(tmpLength, tmp, true));

            tmp += tmpLength + 1;
        }

        //使用後は領域を開放する
        ::FreeEnvironmentStringsW(envstr);

        return Collections::ArrayList<String>(std::move(list));
    }

    Collections::IArray<String> Environment::GetVariable(const char16_t* name)
    {
        constexpr DWORD length = 100u;
        DWORD fret;

        char16_t* wcs = String::AllocMemoryUnsafe(length);

        fret = ::GetEnvironmentVariableW((const wchar_t*)name, (wchar_t*)wcs, length);

        if (fret == 0u) [[unlikely]] {
            String::FreeMemoryUnsafe(wcs);

            throw HResultException();
        }

        if (fret >= length) {
            String::FreeMemoryUnsafe(wcs);

            wcs = String::AllocMemoryUnsafe(fret);

            if (::GetEnvironmentVariableW((const wchar_t*)name, (wchar_t*)wcs, fret) == 0u) [[unlikely]] {
                String::FreeMemoryUnsafe(wcs);

                throw HResultException();
            }

        }
        else {
            fret = length;
        }

        String str = String::WrapUnsafe(fret, wcs);

        return str.Split(u';');
    }

    Collections::IArray<String> Environment::GetVariable(String const& name)
    {
        return GetVariable(name.c_str());
    }

    uint32_t Environment::PhysicalProcessorCount()
    {
        DWORD length = 0;
        SYSTEM_LOGICAL_PROCESSOR_INFORMATION* buffer;

        ::GetLogicalProcessorInformation(nullptr, &length);

        buffer = (SYSTEM_LOGICAL_PROCESSOR_INFORMATION*)::malloc(length);

        MemoryAllocationException::CheckNull(buffer);

        if (::GetLogicalProcessorInformation(buffer, &length) == 0) [[unlikely]] {
            ::free(buffer);
            throw HResultException();
        }

        SYSTEM_LOGICAL_PROCESSOR_INFORMATION* p = buffer;
        SYSTEM_LOGICAL_PROCESSOR_INFORMATION* end = reinterpret_cast<SYSTEM_LOGICAL_PROCESSOR_INFORMATION*>(reinterpret_cast<uint8_t*>(buffer) + length);
        uint32_t result = 0;

        while (p != end) {
            if (p->Relationship == LOGICAL_PROCESSOR_RELATIONSHIP::RelationProcessorCore) result++;
            p++;
        }

        ::free(buffer);

        return result;
    }

    uint32_t Environment::ProcessorCount() noexcept
    {
        ::SYSTEM_INFO info;
        ::GetSystemInfo(&info);

        return info.dwNumberOfProcessors;
    }

    void Environment::SetVariable(const char16_t* name, const char16_t* value)
    {
        if (::SetEnvironmentVariableW((const wchar_t*)name, (const wchar_t*)value) == 0) throw HResultException();
    }

    void Environment::SetVariable(String const& name, const char16_t* value)
    {
        SetVariable(name.c_str(), value);
    }

    void Environment::SetVariable(const char16_t* name, String const& value)
    {
        SetVariable(name, value.c_str());
    }

    void Environment::SetVariable(String const& name, String const& value) 
    {
        SetVariable(name.c_str(), value.c_str());
    }

    String Environment::SystemDirectory()
    {
        UINT length = ::GetSystemDirectoryW(nullptr, 0);

        char16_t* c16s = String::AllocMemoryUnsafe(length);

        if (::GetSystemDirectoryW((wchar_t*)c16s, length) == 0) [[unlikely]] {
            String::FreeMemoryUnsafe(c16s);

            throw HResultException();
        }

        return String::WrapUnsafe(length, c16s);
    }

    OSVersionInfo Environment::SystemVersion()
    {
        OSVersionInfo info;

        info._info.dwOSVersionInfoSize = sizeof(::OSVERSIONINFOEXW);
        if (::GetVersionExW((LPOSVERSIONINFOW)&info._info) == 0) throw HResultException();

        return info;
    }

    String Environment::WindowsDirectory()
    {
        return Primitives::SysInfoAPI::WindowsDirectory();
    }

}
