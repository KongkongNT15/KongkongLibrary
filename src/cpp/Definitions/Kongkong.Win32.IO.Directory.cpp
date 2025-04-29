//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::IO
{
    void Directory::Create(const char16_t* path)
    {
        Primitives::WinUser::CreateDirectory(path);
    }

    void Directory::Create(String const& path)
    {
        Primitives::WinUser::CreateDirectory(path);
    }

    void Directory::Create(const char16_t* path, ::SECURITY_ATTRIBUTES& securityAttributes)
    {
        Primitives::WinUser::CreateDirectory(path, securityAttributes);
    }

    void Directory::Create(String const& path, ::SECURITY_ATTRIBUTES& securityAttributes)
    {
        Primitives::WinUser::CreateDirectory(path, securityAttributes);
    }

    bool Directory::Exists(const char16_t* path) noexcept
    {
        WIN32_FIND_DATA tmp;
        HANDLE hFind = ::FindFirstFileW((const wchar_t*)path, &tmp);

        ::SetLastError(NO_ERROR);

        if (hFind == Primitives::HandleAPI::InvalidValue()) return false;

        ::FindClose(hFind);

        FileAttribute attribute = (FileAttribute)tmp.dwFileAttributes;

        return (bool)(attribute & FileAttribute::Directory);
    }

    bool Directory::Exists(String const& path) noexcept
    {
        return Exists(path.c_str());
    }

    Collections::IArray<FileSystemInfo> Directory::GetChildren(const char16_t* directoryPath)
    {
        String str = directoryPath;
        
        _checkWildCard(str);

        WIN32_FIND_DATA data;
        HANDLE hFind = ::FindFirstFileW((const wchar_t*)str.c_str(), &data);

        if (hFind == Primitives::HandleAPI::InvalidValue()) [[unlikely]] throw HResultException();

        Collections::ArrayList<FileSystemInfo> list;

        {
            std::u16string_view view = (char16_t*)data.cFileName;
            if (!view.ends_with(u"..") && !view.ends_with(u'.')) list->Append(data);
            
        }

        while (::FindNextFileW(hFind, &data) != 0) {
            std::u16string_view view = (char16_t*)data.cFileName;
            if (view.ends_with(u"..") || view.ends_with(u'.')) continue;
            
            list->Append(data);
        }

        ::FindClose(hFind);

        return list;
    }

    Collections::IArray<FileSystemInfo> Directory::GetChildren(String const& directoryPath)
    {
        return GetChildren(directoryPath.c_str());
    }

    Collections::IArray<FileSystemInfo> Directory::GetDirectories(const char16_t* directoryPath)
    {
        String str = directoryPath;
        
        _checkWildCard(str);

        WIN32_FIND_DATA data;
        HANDLE hFind = ::FindFirstFileW((const wchar_t*)str.c_str(), &data);

        if (hFind == Primitives::HandleAPI::InvalidValue()) [[unlikely]] throw HResultException();

        Collections::ArrayList<FileSystemInfo> list;

        {
            std::u16string_view view = (char16_t*)data.cFileName;
            if (!view.ends_with(u"..") && !view.ends_with(u'.') && (bool)((FileAttribute)data.dwFileAttributes & FileAttribute::Directory)) list->Append(data);
            
        }

        while (::FindNextFileW(hFind, &data) != 0) {
            std::u16string_view view = (char16_t*)data.cFileName;
            if (view.ends_with(u"..") || view.ends_with(u'.')) continue;

            if ((bool)((FileAttribute)data.dwFileAttributes & FileAttribute::Directory)) list->Append(data);
        }

        ::FindClose(hFind);

        return list;
    }
    
    Collections::IArray<FileSystemInfo> Directory::GetDirectories(String const& directoryPath)
    {
        return GetDirectories(directoryPath.c_str());
    }

    Collections::IArray<FileSystemInfo> Directory::GetFiles(const char16_t* directoryPath)
    {
        String str = directoryPath;
        
        _checkWildCard(str);

        WIN32_FIND_DATA data;
        HANDLE hFind = ::FindFirstFileW((const wchar_t*)str.c_str(), &data);

        if (hFind == Primitives::HandleAPI::InvalidValue()) [[unlikely]] throw HResultException();

        Collections::ArrayList<FileSystemInfo> list;

        {
            std::u16string_view view = (char16_t*)data.cFileName;
            if (!view.ends_with(u"..") && !view.ends_with(u'.') && !(bool)((FileAttribute)data.dwFileAttributes & FileAttribute::Directory)) list->Append(data);
            
        }

        while (::FindNextFileW(hFind, &data) != 0) {
            std::u16string_view view = (char16_t*)data.cFileName;
            if (view.ends_with(u"..") || view.ends_with(u'.')) continue;

            if (!(bool)((FileAttribute)data.dwFileAttributes & FileAttribute::Directory)) list->Append(data);
        }

        ::FindClose(hFind);

        return list;
    }

    Collections::IArray<FileSystemInfo> Directory::GetFiles(String const& directoryPath) 
    {
        return GetFiles(directoryPath.c_str());
    }

    void Directory::Remove(const char16_t* path)
    {
        Primitives::ErrorChecker::CheckBool(::RemoveDirectoryW((const wchar_t*)path));
    }

    void Directory::Remove(String const& path)
    {
        Remove(path.c_str());
    }

    void Directory::_checkWildCard(String& str)
    {
        if (str.Contains(u'*')) [[unlikely]] throw FormatException(u"ワイルドカードは使用しないでください");
        if (str.EndsWith(u'\\') || str.EndsWith(u'/')) str.Append(u'*');
        else str.AppendUnsafe(u"\\*");
    }
}
