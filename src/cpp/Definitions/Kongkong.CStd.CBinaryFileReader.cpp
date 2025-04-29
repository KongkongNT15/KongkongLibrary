//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CBinaryFileReader::CBinaryFileReader(CBinaryFileReader&& right) noexcept :
        _cFileReaderBase(right._fp)
    {
        right._fp = nullptr;
    }

    CBinaryFileReader::CBinaryFileReader(const char* fileName)
    {
        Open(fileName);
    }

    CBinaryFileReader::CBinaryFileReader(CharString const& fileName)
    {
        Open(fileName);
    }

    CBinaryFileReader::~CBinaryFileReader()
    {
        CloseUnsafe();
    }

    CBinaryFileReader& CBinaryFileReader::operator=(CBinaryFileReader&& right) noexcept
    {
        CloseUnsafe();

        _fp = right._fp;
        right._fp = nullptr;

        return *this;
    }

    size_t CBinaryFileReader::Get(void* buffer, size_t bufferLength)
    {
        _checkIsOpen();
        ArgumentNullException::CheckNull(buffer, u"buffer");

        return GetUnsafe(buffer, bufferLength);
    }

    size_t CBinaryFileReader::GetUnsafe(void* buffer, size_t bufferLength) noexcept
    {
        int b;
        uint8_t* p = (uint8_t*)buffer;
        uint8_t* end = p + bufferLength;

        while (p != end) {
            b = ::fgetc(_fp);
            if (b == EOF) break;
            *p = (uint8_t)b;
            ++p;
        }

        return p - (uint8_t*)buffer;
    }

    void CBinaryFileReader::Open(const char* fileName)
    {
        ArgumentNullException::CheckNull(fileName, u"fileName");

        _fp = ::fopen(fileName, "rb");

        OpenUnsafe(fileName);
    }

    void CBinaryFileReader::Open(CharString const& fileName)
    {
        OpenUnsafe(fileName.c_str());
    }

    void CBinaryFileReader::OpenUnsafe(const char* fileName)
    {
        _fp = ::fopen(fileName, "rb");

        if (_fp == nullptr) throw CStdException();
    }

    void CBinaryFileReader::Reopen(const char* fileName)
    {
        Close();
        Open(fileName);
    }

    void CBinaryFileReader::Reopen(CharString const& fileName)
    {
        Close();
        Open(fileName);
    }

    void CBinaryFileReader::ReopenUnsafe(const char* fileName)
    {
        CloseUnsafe();
        OpenUnsafe(fileName);
    }

    String CBinaryFileReader::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Standard::CBinaryFileReader");
    }
}
