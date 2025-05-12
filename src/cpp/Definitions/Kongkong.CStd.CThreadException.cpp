//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CThreadException::CThreadException(CThreadStatus status, const char16_t* message)
        : Exception(message), _status(status)
    {
    }

    CThreadException::CThreadException(CThreadStatus status, String const& message)
        : Exception(message), _status(status)
    {
    }

    CThreadException::CThreadException(CThreadStatus status, String&& message)
        : Exception(std::move(message)), _status(status)
    {
    }
}
