//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    //https://learn.microsoft.com/ja-jp/windows/win32/cossdk/interpreting-error-codes
    String HResultException::HResultToString(::HRESULT errorCode)
    {
        if (FACILITY_WINDOWS == HRESULT_FACILITY(errorCode)) errorCode = HRESULT_CODE(errorCode);

        char16_t* szErrMsg;

        if (::FormatMessageW( 
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 
        nullptr, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
        (wchar_t*)&szErrMsg, 0, nullptr) == 0) 
        {
            constexpr size_t arrLength = 21 + 8;
            char arr[arrLength];

            ::snprintf(arr, arrLength, "Unknown error '0x%08X'.", errorCode);
            return String::FromAsciiUnsafe(arrLength - 1, arr);
        }

        String ret = szErrMsg;
        //末尾のCRLFを削除
        ret.RemoveBackUnsafe();
        ret.RemoveBackUnsafe();
        
        ::LocalFree(szErrMsg);

        return ret;
    }

    HResultException::HResultException(HRESULT hResult, DWORD errorCode) :
        Exception(HResultToString(hResult)), _hResult(hResult), _errorCode(errorCode)
    {
    }

    HResultException::HResultException(HRESULT hResult) :
        HResultException(hResult, ERROR_SUCCESS)
    {
    }

    HResultException::HResultException(DWORD errorCode) :
        HResultException(::HRESULT_FROM_WIN32(errorCode), errorCode)
    {
    }

    HResultException::HResultException() :
        HResultException(::GetLastError())
    {
    }
}
