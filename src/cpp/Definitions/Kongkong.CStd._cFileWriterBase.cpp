//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    void _cFileWriterBase::Flush()
    {
        _checkIsOpen();
        if (::fflush(_fp) == EOF) [[unlikely]] throw CStdException();
    }

    int _cFileWriterBase::FlushUnsafe() noexcept
    {
        return ::fflush(_fp);
    }
}
