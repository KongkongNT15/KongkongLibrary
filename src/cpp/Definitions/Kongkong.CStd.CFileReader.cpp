//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CFileReader::CFileReader(CFileReader&& right) noexcept
        : _cFileReaderBase(right._fp)
    {
        right._fp = nullptr;
    }

    CFileReader::CFileReader(const char* fileName)
    {
        Open(fileName);
    }

    CFileReader::CFileReader(CharString const& fileName)
    {
        Open(fileName);
    }

    CFileReader::~CFileReader()
    {
        CloseUnsafe();
    }

    CFileReader& CFileReader::operator=(CFileReader&& right) noexcept
    {
        CloseUnsafe();

        _fp = right._fp;
        right._fp = nullptr;

        return *this;
    }

    void CFileReader::Open(const char* fileName)
    {
        ArgumentNullException::CheckNull(fileName, u"fileName");
        
        OpenUnsafe(fileName);
    }

    void CFileReader::Open(CharString const& fileName)
    {
        OpenUnsafe(fileName.c_str());
    }

    void CFileReader::OpenUnsafe(const char* fileName)
    {
        _fp = ::fopen(fileName, "r");

        if (_fp == nullptr) throw CStdException();
    }

    void CFileReader::DiscardLine()
    {
        _checkIsOpen();
        DiscardLineUnsafe();
    }

    void CFileReader::DiscardLineUnsafe() noexcept
    {
        int c;

        while (true) {
            c = ::fgetc(_fp);
            if (c == '\n' || c == EOF) break;
        }
    }

    CharString CFileReader::GetLine()
    {
        _checkIsOpen();

        return GetLineUnsafe();
    }

    CharString CFileReader::GetLineUnsafe() noexcept
    {
        CharString str;
        int c;

        while ((c = ::fgetc(_fp)) != '\n' && c != EOF) {
            str.Append(c);
        }

        return str;
    }

    void CFileReader::Reopen(const char* fileName)
    {
        Close();
        Open(fileName);
    }

    void CFileReader::Reopen(CharString const& fileName)
    {
        Close();
        Open(fileName);
    }

    void CFileReader::ReopenUnsafe(const char* fileName)
    {
        CloseUnsafe();
        OpenUnsafe(fileName);
    }

    String CFileReader::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Standard::CFileReader");
    }
}
