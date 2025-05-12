//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    bool OutputDevice::Write(uint8_t data) const
    {
        return IOHelper::Write(_h.__fd, data);
    }

    ssize_t OutputDevice::Write(ssize_t bufferCount, const void* buffer) const
    {
        return IOHelper::Write(_h.__fd, bufferCount, buffer);
    }

    bool OutputDevice::WriteUnsafe(uint8_t data) const noexcept
    {
        return IOHelper::Write(_h.__fd, data);
    }

    ssize_t OutputDevice::WriteUnsafe(ssize_t bufferCount, const void* buffer) const noexcept
    {
        return IOHelper::Write(_h.__fd, bufferCount, buffer);
    }
}
