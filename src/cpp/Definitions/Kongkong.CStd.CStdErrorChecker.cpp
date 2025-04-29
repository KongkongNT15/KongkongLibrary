//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    void CStdErrorChecker::CheckInt(int value)
    {
        if (value == EOF) [[unlikely]] throw CStdException();
    }

    void CStdErrorChecker::CheckSize(size_t value)
    {
        if (value == (size_t)EOF) [[unlikely]] throw CStdException();
    }

    void CStdErrorChecker::CheckError(int value)
    {
        CheckInt(value);
    }

    void CStdErrorChecker::CheckError(size_t value)
    {
        CheckSize(value);
    }

    int CStdErrorChecker::LastError() noexcept
    {
        return errno;
    }

    void CStdErrorChecker::LastError(int value) noexcept
    {
        errno = value;
    }
}
