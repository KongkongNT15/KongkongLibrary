//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::IO::Storage
{
    bool Path::Exists(const char16_t* path)
    {
#ifdef KONGKONG_ENV_WINDOWS
        ArgumentNullException::CheckNull(path, u"path");

        return Win32::IO::Path::Exists(path);

#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        
        try {
            AppleDevice::Foundation::NSString str = path;

            return Exists(str);
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"path");
        }
#else
        ArgumentNullException::CheckNull(path, u"path");
        try {
            return std::filesystem::exists(path);
        }
        catch (std::filesystem::filesystem_error) {
            throw NotSupportedException(u"The format of path is incorrect.");
        }
#endif
    }

    bool Path::Exists(String const& path)
    {
#ifdef KONGKONG_ENV_WINDOWS

        return Win32::IO::Path::Exists(path.c_str());

#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        AppleDevice::Foundation::NSString str = path;

        return Exists(str);

#else
        try {
            return std::filesystem::exists(path.c_str());
        }
        catch (std::filesystem::filesystem_error) {
            throw NotSupportedException(u"The format of path is incorrect.");
        }
#endif
    }

    bool Path::Exists(const char* path)
    {
#ifdef KONGKONG_ENV_WINDOWS
        ArgumentNullException::CheckNull(path, u"path");

        String str = path;

        return Win32::IO::Path::Exists(str.c_str());

#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)

        try {
            AppleDevice::Foundation::NSString str = path;

            return Exists(str);
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"path");
        }
#else
        try {
            return std::filesystem::exists(path);
        }
        catch (std::filesystem::filesystem_error) {
            throw NotSupportedException(u"The format of path is incorrect.");
        }
#endif
    }

#ifdef KONGKONG_OBJECTIVE_C_ENABLED
    bool Path::Exists(AppleDevice::Foundation::NSString const& path)
    {
        return AppleDevice::Foundation::FileSystem::NSFileManager::DefaultManager().PathExists(path);
    }
#endif
}
