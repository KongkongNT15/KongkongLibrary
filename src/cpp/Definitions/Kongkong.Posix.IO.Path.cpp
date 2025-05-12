//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::IO
{
    CharString Path::Combine(CharStringView const& left, CharStringView const& right)
    {
        _checkPath(left);
        _checkPath(right);

        CharString result = left;

        if (left.EndsWith('/')) {
            if (right.StartsWith('/')) result.AppendUnsafe(right.Length() - 1, right.c_str() + 1);
            else result.Append(right);
        }
        else {
            if (right.StartsWith('/')) result.Append(right);
            else {
                result.Append('/');
                result.Append(right);
            }
        }

        return result;
    }

    bool Path::Exists(const char* path) noexcept
    {
        struct ::stat tmp;

        int result = ::stat(path, &tmp);

        errno = 0;

        return result == 0;
    }

    bool Path::Exists(std::string const& path) noexcept
    {
        return Exists(path.c_str());
    }

    bool Path::Exists(String const& path) noexcept
    {
        return Exists(std::to_string(path));
    }

    FileMode Path::GetFileType(const char* path)
    {
        struct ::stat st;

        if (::stat(path, &st) == EOF) [[unlikely]] throw PosixException();

        return (FileMode)st.st_mode;
    }

    FileMode Path::GetFileType(std::string const& path)
    {
        return GetFileType(path.c_str());
    }

    FileMode Path::GetFileType(String const& path)
    {
        return GetFileType(std::to_string(path));
    }

    void Path::_checkPath(CharStringView const& path)
    {
        bool isSlash = false;
        for (char c : path) {
            if (c == '/') {
                if (isSlash) [[unlikely]] throw FormatException(u"パスの形式が正しくありません");
                isSlash = true;
            }
            else isSlash = false;
        }
    }
}
