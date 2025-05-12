//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    int IOHelper::OpenFileReader(const char* fileName)
    {
        int result = ::open(fileName, (int)FileOpen::ReadOnly);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileReader(const char* fileName, FileOpen openMode)
    {
        constexpr int rInvalidOpenMode = ~(int)(FileOpen::WriteOnly | FileOpen::ReadWrite);

        int result = ::open(fileName, (int)openMode & (rInvalidOpenMode & (int)FileOpen::ReadOnly));

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileReader(const char* fileName, FileOpen openMode, FileMode mode)
    {
        constexpr int rInvalidOpenMode = ~(int)(FileOpen::WriteOnly | FileOpen::ReadWrite);

        int result = ::open(fileName, (int)openMode & (rInvalidOpenMode & (int)FileOpen::ReadOnly), (::mode_t)mode);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileReader(const char* fileName, FileMode mode)
    {
        int result = ::open(fileName, (int)FileOpen::ReadOnly, (::mode_t)mode);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileReader(CharString const& fileName)
    {
        return OpenFileReader(fileName.c_str());
    }

    int IOHelper::OpenFileReader(CharString const& fileName, FileOpen openMode)
    {
        return OpenFileReader(fileName.c_str(), openMode);
    }

    int IOHelper::OpenFileReader(CharString const& fileName, FileOpen openMode, FileMode mode)
    {
        return OpenFileReader(fileName.c_str(), openMode, mode);
    }

    int IOHelper::OpenFileReader(CharString const& fileName, FileMode mode)
    {
        return OpenFileReader(fileName.c_str(), mode);
    }

    int IOHelper::OpenFileRW(const char* fileName)
    {
        int result = ::open(fileName, (int)FileOpen::ReadWrite);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileRW(const char* fileName, FileOpen openMode)
    {
        constexpr int rInvalidOpenMode = ~(int)(FileOpen::WriteOnly | FileOpen::ReadOnly);

        int result = ::open(fileName, (int)openMode & (rInvalidOpenMode & (int)FileOpen::ReadWrite));

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileRW(const char* fileName, FileOpen openMode, FileMode mode)
    {
        constexpr int rInvalidOpenMode = ~(int)(FileOpen::WriteOnly | FileOpen::ReadOnly);

        int result = ::open(fileName, (int)openMode & (rInvalidOpenMode & (int)FileOpen::ReadWrite), (::mode_t)mode);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileRW(const char* fileName, FileMode mode)
    {
        int result = ::open(fileName, (int)FileOpen::ReadWrite, (::mode_t)mode);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileRW(CharString const& fileName)
    {
        return OpenFileRW(fileName.c_str());
    }

    int IOHelper::OpenFileRW(CharString const& fileName, FileOpen openMode)
    {
        return OpenFileRW(fileName.c_str(), openMode);
    }

    int IOHelper::OpenFileRW(CharString const& fileName, FileOpen openMode, FileMode mode)
    {
        return OpenFileRW(fileName.c_str(), openMode, mode);
    }

    int IOHelper::OpenFileRW(CharString const& fileName, FileMode mode)
    {
        return OpenFileRW(fileName.c_str(), mode);
    }

    int IOHelper::OpenFileWriter(const char* fileName)
    {
        int result = ::open(fileName, (int)FileOpen::WriteOnly);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileWriter(const char* fileName, FileOpen openMode)
    {
        constexpr int rInvalidOpenMode = ~(int)(FileOpen::ReadOnly | FileOpen::ReadWrite);

        int result = ::open(fileName, ((int)openMode & rInvalidOpenMode) & (int)FileOpen::WriteOnly);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileWriter(const char* fileName, FileOpen openMode, FileMode mode)
    {
        constexpr int rInvalidOpenMode = ~(int)(FileOpen::ReadOnly | FileOpen::ReadWrite);

        int result = ::open(fileName, ((int)openMode & rInvalidOpenMode) & (int)FileOpen::WriteOnly, (::mode_t)mode);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileWriter(const char* fileName, FileMode mode)
    {
        int result = ::open(fileName, (int)FileOpen::WriteOnly, (::mode_t)mode);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    int IOHelper::OpenFileWriter(CharString const& fileName)
    {
        return OpenFileWriter(fileName.c_str());
    }

    int IOHelper::OpenFileWriter(CharString const& fileName, FileOpen openMode)
    {
        return OpenFileWriter(fileName.c_str(), openMode);
    }

    int IOHelper::OpenFileWriter(CharString const& fileName, FileOpen openMode, FileMode mode)
    {
        return OpenFileWriter(fileName.c_str(), openMode, mode);
    }

    int IOHelper::OpenFileWriter(CharString const& fileName, FileMode mode)
    {
        return OpenFileWriter(fileName.c_str(), mode);
    }

    bool IOHelper::Read(int ioDevice, uint8_t& target)
    {
        ssize_t result = ::read(ioDevice, &target, 1);

        if (result == EOF) [[unlikely]] throw PosixException();

        return (bool)result;
    }

    ssize_t IOHelper::Read(int ioDevice, ssize_t bufferCount, void* buffer)
    {
        Collections::CollectionHelper::CheckLength(bufferCount);
        ArgumentNullException::CheckNull(buffer, u"buffer");

        ssize_t result = ::read(ioDevice, buffer, bufferCount);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    bool IOHelper::ReadUnsafe(int ioDevice, uint8_t& target) noexcept
    {
        ssize_t result = ::read(ioDevice, &target, 1);

        switch (result) {
            case EOF:
            case 0:
                return false;

            default: return true;
        }
    }

    ssize_t IOHelper::ReadUnsafe(int ioDevice, ssize_t bufferCount, void* buffer) noexcept
    {
        return ::read(ioDevice, buffer, bufferCount);
    }

    bool IOHelper::Write(int ioDevice, uint8_t data)
    {
        ssize_t result = ::write(ioDevice, &data, 1);

        if (result == EOF) [[unlikely]] throw PosixException();

        return (bool)result;
    }
    
    ssize_t IOHelper::Write(int ioDevice, ssize_t bufferCount, const void* buffer)
    {
        Collections::CollectionHelper::CheckLength(bufferCount);
        ArgumentNullException::CheckNull(buffer, u"buffer");

        ssize_t result = ::write(ioDevice, buffer, bufferCount);

        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    bool IOHelper::WriteUnsafe(int ioDevice, uint8_t data) noexcept
    {
        switch (::write(ioDevice, &data, 1)) {
            case EOF: [[unlikely]]
            case 0: [[unlikely]]
                return false;
            default: [[likely]] return true;
        }
    }

    ssize_t IOHelper::WriteUnsafe(int ioDevice, ssize_t bufferCount, const void* buffer) noexcept
    {
        return ::write(ioDevice, buffer, bufferCount);
    }
}
