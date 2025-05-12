//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CharString CFile::CreateTempFileName()
    {
        constexpr size_t length = FILENAME_MAX;
        char* p = CharString::AllocMemoryUnsafe(length);

        if (::tmpnam(p) == nullptr) [[unlikely]] throw CStdException();

        return CharString::WrapUnsafe(length, p);
    }

    void CFile::Remove(const char* filePath)
    {
        ArgumentNullException::CheckNull(filePath, u"filePath");
        if (::remove(filePath) == EOF) [[unlikely]] throw CStdException();
    }

    void CFile::Remove(CharString const& filePath)
    {
        if (::remove(filePath.c_str()) == EOF) [[unlikely]] throw CStdException();
    }

    void CFile::Rename(const char* oldPath, const char* newPath)
    {
        ArgumentNullException::CheckNull(oldPath, u"oldPath");
        ArgumentNullException::CheckNull(newPath, u"newPath");

        return _rename(oldPath, newPath);
    }

    void CFile::Rename(CharString const& oldPath, const char* newPath)
    {
        ArgumentNullException::CheckNull(newPath, u"newPath");

        return _rename(oldPath.c_str(), newPath);
    }

    void CFile::Rename(const char* oldPath, CharString const& newPath)
    {
        ArgumentNullException::CheckNull(oldPath, u"oldPath");

        return _rename(oldPath, newPath.c_str());
    }

    void CFile::Rename(CharString const& oldPath, CharString const& newPath)
    {
        return _rename(oldPath.c_str(), newPath.c_str());
    }

    void CFile::_rename(const char* oldPath, const char* newPath)
    {
        if (::rename(oldPath, newPath) == EOF) [[unlikely]] throw CStdException();
    }
}
