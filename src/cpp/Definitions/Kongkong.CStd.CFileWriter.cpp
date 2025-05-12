//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CFileWriter::CFileWriter(const char* fileName)
    {
        Open(fileName);
    }

    CFileWriter::CFileWriter(CharString const& fileName)
    {
        Open(fileName);
    }

    CFileWriter::CFileWriter(CFileWriter&& right) noexcept :
        _cFileWriterBase(right._fp)
    {
        right._fp = nullptr;
    }

    CFileWriter::~CFileWriter()
    {
        CloseUnsafe();
    }

    CFileWriter& CFileWriter::operator=(CFileWriter&& right) noexcept
    {
        CloseUnsafe();

        _fp = right._fp;
        right._fp = nullptr;

        return *this;
    }

    void CFileWriter::Open(const char* fileName)
    {
        ArgumentNullException::CheckNull(fileName, u"fileName");

        OpenUnsafe(fileName);
    }

    void CFileWriter::Open(CharString const& fileName)
    {
        OpenUnsafe(fileName.c_str());
    }

    void CFileWriter::OpenUnsafe(const char* fileName)
    {
        _fp = ::fopen(fileName, "w");

        if (_fp == nullptr) throw CStdException();
    }

    void CFileWriter::PutCharacter(char c)
    {
        _checkIsOpen();
        PutCharacterUnsafe(c);
    }

    int CFileWriter::PutCharacterUnsafe(char c) noexcept
    {
        return ::fputc(c, _fp);
    }

    void CFileWriter::PutString(const char* str)
    {
        _checkIsOpen();
        ArgumentNullException::CheckNull(str, u"str");

        ::fputs(str, _fp);
    }

    int CFileWriter::PutStringUnsafe(const char* str) noexcept
    {
        return ::fputs(str, _fp);
    }

    void CFileWriter::PutString(size_t length, const char* str)
    {
        _checkIsOpen();
        ArgumentNullException::CheckNull(str, u"str");
        if (length == 0) [[unlikely]] throw InvalidArgumentException(u"書き込む文字数にゼロが指定されました");

        PutStringUnsafe(length, str);
    }

    void CFileWriter::PutStringUnsafe(size_t length, const char* str) noexcept
    {
        const char* p = str;
        const char* end = p + length;

        while (p != end) {
            ::fputc(*p, _fp);
            ++p;
        }
    }

    void CFileWriter::PutLine(const char* str)
    {
        PutString(str);
        ::fputc('\n', _fp);
    }

    void CFileWriter::PutLineUnsafe(const char* str) noexcept
    {
        PutStringUnsafe(str);
        ::fputc('\n', _fp);
    }

    void CFileWriter::PutLine()
    {
        _checkIsOpen();
        ::fputc('\n', _fp);
    }

    int CFileWriter::PutLineUnsafe() noexcept
    {
        return ::fputc('\n', _fp) == EOF ? EOF : 0;
    }

    void CFileWriter::Reopen(const char* fileName)
    {
        Close();
        Open(fileName);
    }

    void CFileWriter::Reopen(CharString const& fileName)
    {
        Close();
        Open(fileName);
    }

    void CFileWriter::ReopenUnsafe(const char* fileName)
    {
        CloseUnsafe();
        OpenUnsafe(fileName);
    }

    String CFileWriter::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Standard::CFileWriter");
    }
}
