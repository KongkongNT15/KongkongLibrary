//このcppファイルをコンパイルに含めないでください

#if 0
namespace KONGKONG_NAMESPACE::System
{
    String Environment::CurrentDirectory()
    {
#if KONGKONG_ENV_WINDOWS
        return Win32::Environment::CurrentDirectory();
//#elif KONGKONG_OBJECTIVE_C_ENABLED
        //auto& manager = Object::GetInstanceUnsafe(AppleDevice::Foundation::FileSystem::NSFileManager::DefaultManager());

        //return manager.CurrentDirectory().ToString();
#elif KONGKONG_ENV_UNIX
        return Posix::Environment::CurrentDirectory();
#else
        return std::filesystem::current_path().u16string();
#endif
    }

    void Environment::CurrentDirectory(const char16_t* path)
    {
#if KONGKONG_ENV_WINDOWS
        try {
            Win32::Environment::CurrentDirectory(path);
        }
        catch (Win32::HResultException& e) {
            switch (e.ErrorCode()) {
                case ERROR_PATH_NOT_FOUND: throw IO::Storage::DirectoryNotFoundException(e.Message());
                case ERROR_INVALID_LEVEL: throw FormatException(e.Message());
                case ERROR_INVALID_PARAMETER:
                    if (path == nullptr) ArgumentNullException::ThrowWithName(u"path");
                    else throw ArgumentException(e.Message());
                    
                default: throw IOException(e.Message());
            }
        }
        
#else
        try {
            std::filesystem::current_path(path);
        }
        catch (std::filesystem::filesystem_error& e) {
            throw IOException(e.what());
        }
#endif
    }

    void Environment::CurrentDirectory(String const& path)
    {
#if KONGKONG_ENV_WINDOWS
        return CurrentDirectory(path.c_str());
        
#else
        try {
            std::filesystem::current_path(path.c_str());
        }
        catch (std::filesystem::filesystem_error& e) {
            throw IOException(e.what());
        }
#endif
    }

#if KONGKONG_OBJECTIVE_C_ENABLED
    void Environment::CurrentDirectory(AppleDevice::Foundation::NSString const& path)
    {
        if (AppleDevice::Foundation::FileSystem::NSFileManager::DefaultManager().CurrentDirectory(path) == false) [[unlikely]] throw IOException(u"指定されたパスが無効です");
    }
#endif

    void Environment::Exit(int32_t exitCode) noexcept
    {
#if KONGKONG_ENV_WINDOWS
        ::ExitProcess((::UINT)exitCode);
#else
        ::exit(exitCode);
#endif
    }

    String const& Environment::NewLine()
    {
#if KONGKONG_ENV_WINDOWS
        return Win32::Environment::NewLine();
#elif KONGKONG_ENV_UNIX
        return Posix::Environment::NewLine();
#endif
    }

}

#endif //0
