//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    void _cFileStream::ClearError()
    {
        _checkIsOpen();
        ClearErrorUnsafe();
    }

    void _cFileStream::ClearErrorUnsafe() noexcept
    {
        ::clearerr(_fp);
    }

    void _cFileStream::Close()
    {
        if (IsOpen()) [[likely]] {
            if (::fclose(_fp) == EOF) [[unlikely]] throw CStdException();
            _fp = nullptr;
        }
    }

    int _cFileStream::CloseUnsafe() noexcept
    {
        if (IsOpen()) [[likely]] {
            int result = ::fclose(_fp);
            _fp = nullptr;

            return result;
        }

        return 0;
    }

    int _cFileStream::ErrorCode() const
    {
        _checkIsOpen();
        return ::ferror(_fp);
    }

    int _cFileStream::ErrorCodeUnsafe() const noexcept
    {
        return ::ferror(_fp);
    }

    void _cFileStream::_checkIsOpen() const
    {
        if (!IsOpen()) [[unlikely]] throw IOException(u"ファイルが開かれていません");
    }
}
