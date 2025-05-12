//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    String CStdException::ErrorNumberToString(int errorNumber)
    {
        return ::strerror(errorNumber);
    }

    CStdException::CStdException() :
        CStdException(errno, ::strerror(errno))
    {
    }

    CStdException::CStdException(String const& errorMessage) :
        CStdException(errno, errorMessage)
    {
    }

    CStdException::CStdException(String&& errorMessage) :
        CStdException(errno, std::move(errorMessage))
    {
    }

    CStdException::CStdException(const char16_t* errorMessage) :
        CStdException(errno, errorMessage)
    {
    }

    CStdException::CStdException(int errorCode, String const& errorMessage) :
        Exception(errorMessage), _errorCode(errorCode)
    {
    }

    CStdException::CStdException(int errorCode, String&& errorMessage) :
        Exception(std::move(errorMessage)), _errorCode(errorCode)
    {
    }

    CStdException::CStdException(int errorCode, const char16_t* errorMessage) :
        Exception(errorMessage), _errorCode(errorCode)
    {
    }
}
