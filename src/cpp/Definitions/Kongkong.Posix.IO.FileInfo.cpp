//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    FileInfo::FileInfo(DirectoryEntry const& entry) : 
        _name(CharString::FromPointerUnsafe(entry.NameLength(), entry.Name())),
        _fileType(entry.FileType()),
        _stat(entry._stat)
    {
    }

    String FileInfo::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::FileInfo");
    }

    bool operator==(FileInfo const& left, FileInfo const& right) noexcept
    {
        return left._name == right._name && left._fileType == right._fileType && Algorithms::Range::IsEqualUnsafe(sizeof(struct ::stat), &left._stat, &right._stat);
    }

    bool operator!=(FileInfo const& left, FileInfo const& right) noexcept
    {
        return !(left == right);
    }
}
