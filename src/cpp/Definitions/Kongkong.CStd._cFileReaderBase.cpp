//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{

    bool _cFileReaderBase::EndOfStream() const
    {
        return Peek() == EOF;
    }

    bool _cFileReaderBase::EndOfStreamUnsafe() const noexcept
    {
        return PeekUnsafe() == EOF;
    }

    int _cFileReaderBase::Get()
    {
        _checkIsOpen();

        return GetUnsafe();
    }

    int _cFileReaderBase::GetUnsafe() noexcept
    {
        return ::fgetc(_fp);
    }

    int _cFileReaderBase::Peek() const
    {
        _checkIsOpen();

        return PeekUnsafe();
    }

    int _cFileReaderBase::PeekUnsafe() const noexcept
    {
        int c = ::fgetc(_fp);

        if (c != EOF) ::ungetc(c, _fp);

        return c;
    }
}
