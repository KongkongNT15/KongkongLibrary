//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::IO
{
    IO::FileType IODevice::FileType() const
    {
        return Primitives::FileAPI::GetFileType(_h.__rawHandle());
    }

    IO::FileType IODevice::GetFileTypeUnsafe() const noexcept
    {
        return Primitives::FileAPI::GetFileTypeUnsafe(_h.__rawHandle());
    }
}

CREATE_CLASS_TYPE(IO::IODevice, IODevice)
