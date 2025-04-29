//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::IO
{
    int64_t InputDevice::GetLengthUnsafe() const noexcept
    {
        return Primitives::FileAPI::GetFileSizeUnsafe(_h.__rawHandle());
    }

    int64_t InputDevice::Length() const
    {
        return Primitives::FileAPI::GetFileSize(_h.__rawHandle());
    }

    uint8_t InputDevice::ReadData() const
    {
        return Primitives::FileAPI::Read(_h.__rawHandle());
    }

    Collections::IArray<uint8_t> InputDevice::ReadData(uint32_t length) const
    {
        return Primitives::FileAPI::Read(_h.__rawHandle(), length);
    }

    uint8_t InputDevice::ReadDataUnsafe() const noexcept
    {
        return Primitives::FileAPI::ReadUnsafe(_h.__rawHandle());
    }
}

CREATE_CLASS_TYPE(IO::InputDevice, InputDevice)
