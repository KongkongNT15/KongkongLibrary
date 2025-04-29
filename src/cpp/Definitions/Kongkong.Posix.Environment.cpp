//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix
{
    String Environment::_newLine = String::FromLiteral(u"\n");
    
    String Environment::CurrentDirectory()
    {
        String str = CurrentDirectoryCharString().c_str();

        return str;
    }

    CharString Environment::CurrentDirectoryCharString()
    {
        constexpr size_t defaultLength = 256;
        size_t length = defaultLength;

        char* str;

        while (true) {
            errno = 0;
            str = CharString::AllocMemoryUnsafe(length);
            
            if (::getcwd(str, length) == nullptr) {
                CharString::FreeMemoryUnsafe(str);

                throw PosixException();
            }

            if (errno != ERANGE) {
                errno = 0;
                break;
            }

            CharString::FreeMemoryUnsafe(str);

            length += defaultLength;
        }

        return CharString::WrapUnsafe(length, str);
    }

    void Environment::CurrentDirectory(String const& value)
    {
        CurrentDirectory(std::to_string(value).c_str());
    }

    void Environment::CurrentDirectory(const char16_t* value)
    {
        CurrentDirectory(std::to_string(value).c_str());
    }

    void Environment::CurrentDirectory(std::string const& value)
    {
        CurrentDirectory(value.c_str());
    }

    void Environment::CurrentDirectory(const char* value)
    {
        if (::chdir(value) != 0) throw PosixException();
    }

    uint32_t Environment::PhysicalProcessorCount() noexcept
    {
        return (uint32_t)::sysconf(_SC_NPROCESSORS_ONLN);
    }

    uint32_t Environment::ProcessorCount() noexcept
    {
        return (uint32_t)::sysconf(_SC_NPROCESSORS_CONF);
    }
}
