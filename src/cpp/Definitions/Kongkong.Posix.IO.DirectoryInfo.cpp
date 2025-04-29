//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    DirectoryInfo::DirectoryInfo(const char* path)
    {
        ArgumentNullException::CheckNull(path, u"path");

        _path = path;

        _checkPath(path, _stat);
    }

    DirectoryInfo::DirectoryInfo(std::string const& path) : _path(path)
    {
        _checkPath(path.c_str(), _stat);
    }

    DirectoryInfo::DirectoryInfo(std::string&& path) : _path(std::move(path))
    {
        _checkPath(_path.c_str(), _stat);
    }

    DirectoryInfo::DirectoryInfo(String const& path) : _path(::std::to_string(path))
    {
        _checkPath(_path.c_str(), _stat);
    }

    DirectoryIterator DirectoryInfo::begin() const
    {
        ::DIR* dir = ::opendir(_path.c_str());
        ::dirent* dp = ::readdir(dir);

        return DirectoryIterator(dp, dir, _path.c_str());
    }

    DirectoryIterator DirectoryInfo::end() const
    {
        return DirectoryIterator();
    }

    Collections::IArray<FileInfo> DirectoryInfo::GetChildren() const
    {
        Collections::ArrayList<FileInfo> list;

        for (DirectoryEntry const& entry : *this) {
            list += FileInfo(entry);
        }

        return list;
    }

    Collections::IArray<FileInfo> DirectoryInfo::GetDirectories() const
    {
        Collections::ArrayList<FileInfo> list;

        for (DirectoryEntry const& entry : *this) {
            if (entry.FileType() == FileType::Directory) {
                list += FileInfo(entry);
            }
        }

        return list;
    }

    Collections::IArray<FileInfo> DirectoryInfo::GetFiles() const
    {
        Collections::ArrayList<FileInfo> list;

        for (DirectoryEntry const& entry : *this) {
            
            switch (entry.FileType()) {
                case FileType::RegularFile:
                case FileType::BlockFile:
                case FileType::CharacterFile:
                    
                    list += FileInfo(entry);

                    break;

                default: break;
            }
        }

        return list;
    }

    String DirectoryInfo::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Posix::IO::DirectoryInfo");
    }

    void DirectoryInfo::_checkPath(const char* path, struct ::stat& stat)
    {
        if (::stat(path, &stat) == EOF) [[unlikely]] throw PosixException();
    }
}
