//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    bool InputDevice::Read(uint8_t& target) const
    {
        return IOHelper::Read(_h.__fd, target);
    }

    ssize_t InputDevice::Read(size_t bufferCount, void* buffer) const
    {
        return IOHelper::Read(_h.__fd, bufferCount, buffer);
    }

    bool InputDevice::ReadUnsafe(uint8_t& target) const noexcept
    {
        return IOHelper::ReadUnsafe(_h.__fd, target);
    }

    ssize_t InputDevice::ReadUnsafe(size_t bufferCount, void* buffer) const noexcept
    {
        return IOHelper::ReadUnsafe(_h.__fd, bufferCount, buffer);
    }
}
