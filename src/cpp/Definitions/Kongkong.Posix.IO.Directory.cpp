//このcppファイルをコンパイルに含めないでください

//Unixのみ
#ifdef KONGKONG_ENV_UNIX

namespace KONGKONG_NAMESPACE::Posix::IO
{
    void Directory::Create(const char* directoryName)
    {
        Create(directoryName, FileMode::RWXForAll);
    }

    void Directory::Create(std::string const& directoryName)
    {
        Create(directoryName, FileMode::RWXForAll);
    }

    void Directory::Create(String const& directoryName)
    {
        Create(directoryName, FileMode::RWXForAll);
    }

    void Directory::Create(const char* directoryName, FileMode mode)
    {
        if (::mkdir(directoryName, (mode_t)mode) == EOF) [[unlikely]] throw PosixException();
    }

    void Directory::Create(std::string const& directoryName, FileMode mode)
    {
        Create(directoryName.c_str(), mode);
    }
    
    void Directory::Create(String const& directoryName, FileMode mode)
    {
        Create(std::to_string(directoryName), mode);
    }

    bool Directory::Exists(const char* path) noexcept
    {
        struct ::stat st;
        int result;

        int erno = errno;

        result = ::stat(path, &st);

        errno = erno;

        if (result == EOF) return false;

        return bool((FileMode)st.st_mode & FileMode::Directory);
    }

    bool Directory::Exists(std::string const& path) noexcept
    {
        return Exists(path.c_str());
    }

    bool Directory::Exists(String const& path)
    {
        return Exists(std::to_string(path));
    }

    Collections::IArray<FileInfo> Directory::GetChildren(const char* directoryName)
    {
        DirectoryInfo directory(directoryName);
        
        return directory.GetChildren();
    }

    Collections::IArray<FileInfo> Directory::GetChildren(std::string const& directoryName)
    {
        return GetChildren(directoryName.c_str());
    }

    Collections::IArray<FileInfo> Directory::GetChildren(String const& directoryName)
    {
        return GetChildren(std::to_string(directoryName));
    }

    Collections::IArray<FileInfo> Directory::GetDirectories(const char* directoryName)
    {
        DirectoryInfo directory(directoryName);
        
        return directory.GetDirectories();
    }

    Collections::IArray<FileInfo> Directory::GetDirectories(std::string const& directoryName)
    {
        return GetDirectories(directoryName.c_str());
    }

    Collections::IArray<FileInfo> Directory::GetDirectories(String const& directoryName)
    {
        return GetDirectories(std::to_string(directoryName));
    }

    Collections::IArray<FileInfo> Directory::GetFiles(const char* directoryName)
    {
        DirectoryInfo directory(directoryName);
        
        return directory.GetFiles();
    }

    Collections::IArray<FileInfo> Directory::GetFiles(std::string const& directoryName)
    {
        return GetFiles(directoryName.c_str());
    }

    Collections::IArray<FileInfo> Directory::GetFiles(String const& directoryName)
    {
        return GetFiles(std::to_string(directoryName));
    }

    void Directory::Remove(const char* directoryName)
    {
        if (::rmdir(directoryName) == EOF) [[unlikely]] throw PosixException();
    }

    void Directory::Remove(const char16_t* directoryName)
    {
        Remove(std::to_string(directoryName).c_str());
    }

    void Directory::Remove(String const& directoryName)
    {
        Remove(directoryName.c_str());
    }

}

#endif //KONGKONG_ENV_UNIX
