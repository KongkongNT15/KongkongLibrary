//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    void IODevice::Close()
    {
        if (::close(_h.__fd) == EOF) [[unlikely]] throw PosixException();
        _h.__fd = _ioDeviceHandle::__closedFd;
    }

    ::off_t IODevice::CurrentPosition() const
    {
        ::off_t result = ::lseek(_h.__fd, 0, (int)Standard::CFilePosition::Current);
        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    template <>
    bool IODevice::Is<FileReader>() const noexcept
    {
        struct ::stat s;

        if (::fstat(_h.__fd, &s) == EOF) return false;

        return _isInputDevice((FileMode)s.st_mode) && _isFileDevice((FileMode)s.st_mode);
    }

    template <>
    bool IODevice::Is<FileRW>() const noexcept
    {
        struct ::stat s;

        if (::fstat(_h.__fd, &s) == EOF) return false;

        return _isRWDevice((FileMode)s.st_mode) && _isFileDevice((FileMode)s.st_mode);
    }

    template <>
    bool IODevice::Is<FileWriter>() const noexcept
    {
        struct ::stat s;

        if (::fstat(_h.__fd, &s) == EOF) return false;

        return _isOutputDevice((FileMode)s.st_mode) && _isFileDevice((FileMode)s.st_mode);
    }

    template <>
    bool IODevice::Is<InputDevice>() const noexcept
    {
        struct ::stat s;

        if (::fstat(_h.__fd, &s) == EOF) return false;

        return _isInputDevice((FileMode)s.st_mode);
    }

    template <>
    bool IODevice::Is<OutputDevice>() const noexcept
    {
        struct ::stat s;
        
        if (::fstat(_h.__fd, &s) == EOF) return false;

        return _isOutputDevice((FileMode)s.st_mode);
    }

    template <>
    bool IODevice::Is<RWDevice>() const noexcept
    {
        struct ::stat s;

        if (::fstat(_h.__fd, &s) == EOF) return false;

        return _isRWDevice((FileMode)s.st_mode);
    }

    FileMode IODevice::Mode() const
    {
        int result = ::fcntl(_h.__fd, F_GETFL);

        if (result == EOF) [[unlikely]] throw PosixException();

        return (FileMode)result;
    }

    ::off_t IODevice::Seek(::off_t offset, Standard::CFilePosition position) const
    {
        ::off_t result = ::lseek(_h.__fd, offset, (int)position);
        if (result == EOF) [[unlikely]] throw PosixException();

        return result;
    }

    String IODevice::ToString() const
    {
        struct ::stat s;
        if (::fstat(_h.__fd, &s) == EOF) return String::FromLiteral(u"Null");

        //RWDevice
        if (_isRWDevice((FileMode)s.st_mode)) {
            if (_isFileDevice((FileMode)s.st_mode)) return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::FileRW");
            return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::RWDevice");
        }

        //InputDevice
        if (_isInputDevice((FileMode)s.st_mode)) {
            
            if (_isFileDevice((FileMode)s.st_mode)) return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::FileReader");
            return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::InputDevice");
        }

        //OutputDevice
        if (_isOutputDevice((FileMode)s.st_mode)) {
            if (_isFileDevice((FileMode)s.st_mode)) return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::FileWriter");
            return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::OutputDevice");
        }

        return String::FromLiteral(u"Null");
    }

    IODevice::_ioDeviceHandle::_ioDeviceHandle(_ioDeviceHandle const& right)
    {
        if (right.__fd == __closedFd) {
            __fd = __closedFd;
            return;
        }
        
        __fd = ::dup(right.__fd);

        if (__fd == EOF) [[unlikely]] throw PosixException();
    }

    IODevice::_ioDeviceHandle::~_ioDeviceHandle()
    {
        if (__fd != __closedFd) ::close(__fd);
    }

    IODevice::_ioDeviceHandle& IODevice::_ioDeviceHandle::operator=(_ioDeviceHandle const& right)
    {
        _ioDeviceHandle::~_ioDeviceHandle();

        if (right.__fd == __closedFd) {
            __fd = __closedFd;
            return *this;
        }

        __fd = ::dup(right.__fd);

        if (__fd == EOF) [[unlikely]] throw PosixException();

        return *this;
    }

    IODevice::_ioDeviceHandle& IODevice::_ioDeviceHandle::operator=(_ioDeviceHandle&& right) noexcept
    {
        _ioDeviceHandle::~_ioDeviceHandle();

        __fd = right.__fd;
        right.__fd = __closedFd;

        return *this;
    }

    FileOpen IODevice::_mode() const noexcept
    {
        return (FileOpen)::fcntl(_h.__fd, F_GETFL);
    }

    bool IODevice::_isInputDevice(FileMode mode) noexcept
    {
        return (bool)(mode & FileMode::ReadForAll);
    }

    bool IODevice::_isOutputDevice(FileMode mode) noexcept
    {
        return (bool)(mode & FileMode::WriteForAll);
    }

    bool IODevice::_isRWDevice(FileMode mode) noexcept
    {
        return (bool)(mode & FileMode::RWXForAll);
    }

    bool IODevice::_isFileDevice(FileMode mode) noexcept
    {
        return (bool)(mode & FileMode::RegularFile);
    }
}
