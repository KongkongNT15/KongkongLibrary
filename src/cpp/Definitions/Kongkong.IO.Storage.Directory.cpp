//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::IO::Storage
{
    void Directory::Create(const char16_t* path)
    {
#ifdef KONGKONG_ENV_WINDOWS
        try {
            Win32::IO::Directory::Create(path);
        }
        catch (Win32::HResultException& e) {

            if (path == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"path");

            switch (e.ErrorCode()) {
                case ERROR_PATH_NOT_FOUND: throw DirectoryNotFoundException(std::move(e.Message()));
                case ERROR_INVALID_LEVEL: throw FormatException(std::move(e.Message()));
                case ERROR_ALREADY_EXISTS:
                default: throw IOException(std::move(e.Message()));
            }
        }
        
#elif defined(__POSIX__)

#endif
    }

    void Directory::Create(String const& path)
    {
#ifdef KONGKONG_ENV_WINDOWS
        Create(path.c_str());
#elif defined(__UNIX__)

#endif
    }

    void Directory::Create(const char* path)
    {
#ifdef KONGKONG_ENV_WINDOWS
        ArgumentNullException::CheckNull(path, u"path");
        String str = path;
        Create(str.c_str());

#elif defined(__POSIX__)

#endif
    }

    bool Directory::Exists(const char16_t* path)
    {
#ifdef KONGKONG_ENV_WINDOWS
        return Win32::IO::Directory::Exists(path);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        try {
            AppleDevice::Foundation::NSString str = path;

            return Exists(str);
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"path");
        }

#elif defined(__POSIX__)

#else

#endif
    }

    bool Directory::Exists(String const& path)
    {
#ifdef KONGKONG_ENV_WINDOWS
        return Win32::IO::Directory::Exists(path);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        AppleDevice::Foundation::NSString str = path;

        return Exists(str);


#elif defined(__POSIX__)

#endif
    }

    bool Directory::Exists(const char* path)
    {
#ifdef KONGKONG_ENV_WINDOWS
        ArgumentNullException::CheckNull(path, u"path");
        return Win32::IO::Directory::Exists(path);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)

        try {
            AppleDevice::Foundation::NSString str = path;

            return Exists(str);
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"path");
        }

#elif defined(__POSIX__)

#endif
    }

#ifdef KONGKONG_OBJECTIVE_C_ENABLED
    bool Directory::Exists(AppleDevice::Foundation::NSString const& path)
    {
        return AppleDevice::Foundation::FileSystem::NSFileManager::DefaultManager().DirectoryExistsAtPath(path);
    }
#endif

    Collections::IArray<String> Directory::GetDirectories(String const& path)
    {
        if (File::Exists(path)) [[unlikely]] throw IOException(u"The specified path is a file.");
        if (!Exists(path)) [[unlikely]] throw DirectoryNotFoundException(u"The specified path does not exist.");

        std::filesystem::directory_iterator itr{path.c_str()};
        Collections::ArrayList<String> list;

        for (std::filesystem::directory_entry const& de : itr) {
            list->Append(de.path().u16string());
        }

        return list;
    }
}
