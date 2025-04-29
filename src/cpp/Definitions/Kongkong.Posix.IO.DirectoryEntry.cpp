//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    DirectoryEntry::DirectoryEntry(::dirent* p, const char* directoryName) : _dirent(p), _stat(), _directoryName(CharString::FromPointerUnsafe(directoryName))
    {
        if (p != nullptr) {
            if (::stat(Path::Combine(_directoryName, CharStringView::FromPointerUnsafe(p->d_name)).c_str(), &_stat) == EOF) [[unlikely]] throw PosixException();
        }
    }

    void DirectoryEntry::Handle(::dirent* p)
    {
        _dirent = p;
        if (p != nullptr) {
            if (::stat(Path::Combine(_directoryName, CharStringView::FromPointerUnsafe(p->d_name)).c_str(), &_stat) == EOF) [[unlikely]] throw PosixException();
        }
    }

    String DirectoryEntry::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::DirectoryEntry");
    }
}
