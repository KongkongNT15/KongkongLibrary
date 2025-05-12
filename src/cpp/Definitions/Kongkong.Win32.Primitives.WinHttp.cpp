//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    uint32_t WinHttp::ReadData(::HINTERNET hInternet, void* buffer, uint32_t bufferLength)
    {
        ArgumentNullException::CheckNull(buffer, u"buffer");
        
        return ReadDataUncheckBufferUnsafe(hInternet, buffer, bufferLength);
    }

    uint32_t WinHttp::ReadDataUncheckBufferUnsafe(::HINTERNET hInternet, void* buffer, uint32_t bufferLength)
    {
        DWORD writtenLength;
        if (::WinHttpReadData(hInternet, buffer, bufferLength, &writtenLength) == 0) [[unlikely]] throw HResultException();

        return writtenLength;
    }

    uint32_t WinHttp::ReadDataUnsafe(::HINTERNET hInternet, void* buffer, uint32_t bufferLength) noexcept
    {
        DWORD writtenLength;
        ::WinHttpReadData(hInternet, buffer, bufferLength, &writtenLength);

        return writtenLength;
    }
}
