//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    bool RWDevice::Read(uint8_t& target) const
    {
        return IOHelper::Read(_h.__fd, target);
    }

    ssize_t RWDevice::Read(size_t bufferCount, void* buffer) const
    {
        return IOHelper::Read(_h.__fd, bufferCount, buffer);
    }

    bool RWDevice::ReadUnsafe(uint8_t& target) const noexcept
    {
        return IOHelper::ReadUnsafe(_h.__fd, target);
    }

    ssize_t RWDevice::ReadUnsafe(size_t bufferCount, void* buffer) const noexcept
    {
        return IOHelper::ReadUnsafe(_h.__fd, bufferCount, buffer);
    }

    bool RWDevice::Write(uint8_t data) const
    {
        return IOHelper::Write(_h.__fd, data);
    }

    ssize_t RWDevice::Write(ssize_t bufferCount, const void* buffer) const
    {
        return IOHelper::Write(_h.__fd, bufferCount, buffer);
    }

    bool RWDevice::WriteUnsafe(uint8_t data) const noexcept
    {
        return IOHelper::Write(_h.__fd, data);
    }

    ssize_t RWDevice::WriteUnsafe(ssize_t bufferCount, const void* buffer) const noexcept
    {
        return IOHelper::Write(_h.__fd, bufferCount, buffer);
    }
}
