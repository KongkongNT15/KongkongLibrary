//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CBinaryFileWriter::CBinaryFileWriter(const char* fileName)
    {
        Open(fileName);
    }

    CBinaryFileWriter::CBinaryFileWriter(CharString const& fileName)
    {
        Open(fileName);
    }

    CBinaryFileWriter::CBinaryFileWriter(CBinaryFileWriter&& right) noexcept :
        _cFileWriterBase(right._fp)
    {
        right._fp = nullptr;
    }

    CBinaryFileWriter::~CBinaryFileWriter()
    {
        CloseUnsafe();
    }

    CBinaryFileWriter& CBinaryFileWriter::operator=(CBinaryFileWriter&& right) noexcept
    {
        CloseUnsafe();

        _fp = right._fp;
        right._fp = nullptr;

        return *this;
    }

    void CBinaryFileWriter::Open(const char* fileName)
    {
        ArgumentNullException::CheckNull(fileName, u"fileName");
        
        OpenUnsafe(fileName);
    }

    void CBinaryFileWriter::Open(CharString const& fileName)
    {
        OpenUnsafe(fileName.c_str());
    }

    void CBinaryFileWriter::OpenUnsafe(const char* fileName)
    {
        _fp = ::fopen(fileName, "w");

        if (_fp == nullptr) throw CStdException();
    }

    void CBinaryFileWriter::Reopen(const char* fileName)
    {
        Close();
        Open(fileName);
    }

    void CBinaryFileWriter::Reopen(CharString const& fileName)
    {
        Close();
        Open(fileName);
    }

    void CBinaryFileWriter::ReopenUnsafe(const char* fileName)
    {
        CloseUnsafe();
        OpenUnsafe(fileName);
    }

    String CBinaryFileWriter::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Standard::CBinaryFileWriter");
    }

    void CBinaryFileWriter::Write(uint8_t data)
    {
        _checkIsOpen();
        if(::fputc(data, _fp) == EOF) [[unlikely]] throw CStdException();
    }

    int CBinaryFileWriter::WriteUnsafe(uint8_t data) noexcept
    {
        return ::fputc(data, _fp);
    }

    void CBinaryFileWriter::Write(size_t size, const void* buffer)
    {
        _checkIsOpen();
        ArgumentNullException::CheckNull(buffer, u"buffer");

        ::fwrite(buffer, 1, size, _fp);
    }

    size_t CBinaryFileWriter::WriteUnsafe(size_t size, const void* buffer) noexcept
    {
        return ::fwrite(buffer, 1, size, _fp);
    }

}
