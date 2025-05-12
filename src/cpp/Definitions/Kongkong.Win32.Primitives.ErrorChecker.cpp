//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    void ErrorChecker::CheckBool(::BOOL value)
    {
        if (value == FALSE) [[unlikely]] throw HResultException();
    }

    void ErrorChecker::CheckHResult(::HRESULT value)
    {
        if (value != S_OK) [[unlikely]] throw HResultException(value);
    }

    void ErrorChecker::CheckSystemError(::DWORD value)
    {
        if (value == NO_ERROR) [[unlikely]] throw HResultException();
    }

    void ErrorChecker::CheckError(::BOOL value)
    {
        CheckBool(value);
    }

    void ErrorChecker::CheckError(::HRESULT value)
    {
        CheckHResult(value);
    }

    void ErrorChecker::CheckError(::DWORD value)
    {
        CheckSystemError(value);
    }

    uint32_t ErrorChecker::LastError() noexcept
    {
        return ::GetLastError();
    }

    void ErrorChecker::LastError(uint32_t errorCode) noexcept
    {
        ::SetLastError(errorCode);
    }

}
