//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::IO::Storage
{
    void File::Delete(const char16_t* path)
    {
        if (!File::Exists(path)) [[unlikely]] throw FileNotFoundException(u"指定されたファイルが見つかりませんでした");
#if KONGKONG_ENV_WINDOWS
        Win32::IO::File::Delete(path);
#endif
    }

    void File::Delete(String const& path)
    {
#if KONGKONG_ENV_WINDOWS
        Delete(path.c_str());
#endif
    }

    void File::Delete(const char* path)
    {
#if KONGKONG_ENV_WINDOWS
        Delete(String(path));
#else
        if (!File::Exists(path)) [[unlikely]] throw FileNotFoundException(u"The specified file does not exist.");
        
        try {
            std::filesystem::remove(path);
        }
        catch (std::filesystem::filesystem_error) {
            throw IOException(EXCEPTION_MESSAGE);
        }
#endif
    }

    bool File::Exists(const char16_t* path)
    {
#if KONGKONG_ENV_WINDOWS
        return Win32::IO::File::Exists(path);

#elif KONGKONG_OBJECTIVE_C_ENABLED

        try {
            AppleDevice::Foundation::NSString str = path;

            return Exists(str);
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"path");
        }
#else
        try {
            return std::filesystem::is_regular_file(path);
        }
        catch (std::filesystem::filesystem_error) {
            throw NotSupportedException(u"The format of path is incorrect.");
        }
#endif
    }

    bool File::Exists(String const& path)
    {
#if KONGKONG_ENV_WINDOWS
        return Win32::IO::File::Exists(path);

#elif KONGKONG_OBJECTIVE_C_ENABLED
        AppleDevice::Foundation::NSString str = path;

        return Exists(path);
#else
        try {
            return std::filesystem::is_regular_file(path.c_str());
        }
        catch (std::filesystem::filesystem_error) {
            throw NotSupportedException(u"The format of path is incorrect.");
        }

#endif
    }

    bool File::Exists(const char* path)
    {
#if KONGKONG_ENV_WINDOWS
        return Win32::IO::File::Exists(String(path));

#elif KONGKONG_OBJECTIVE_C_ENABLED

        try {
            AppleDevice::Foundation::NSString str = path;

            return Exists(str);
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"path");
        }
#else
        try {
            return std::filesystem::is_regular_file(path);
        }
        catch (std::filesystem::filesystem_error) {
            throw NotSupportedException(u"The format of path is incorrect.");
        }
#endif
    }

#if KONGKONG_OBJECTIVE_C_ENABLED

    bool File::Exists(AppleDevice::Foundation::NSString const& path)
    {
        return AppleDevice::Foundation::FileSystem::NSFileManager::DefaultManager().FileExistsAtPath(path);
    }
    
#endif
}
