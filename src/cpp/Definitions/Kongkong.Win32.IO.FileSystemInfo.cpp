//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::IO
{
    LocalTime FileSystemInfo::CreationTime() const
    {
        return _data.ftCreationTime;
    }

    SystemTime FileSystemInfo::CreationTimeUtc() const
    {
        return _data.ftCreationTime;
    }

    String FileSystemInfo::FileName() const
    {
        return String::FromPointerUnsafe((char16_t*)_data.cFileName, true);
    }

    uint64_t FileSystemInfo::FileSize() const noexcept
    {
        return MinWinHelper::ToUInt64(_data.nFileSizeHigh, _data.nFileSizeLow);
    }

    LocalTime FileSystemInfo::LastAccessTime() const
    {
        return _data.ftLastAccessTime;
    }

    SystemTime FileSystemInfo::LastAccessTimeUtc() const
    {
        return _data.ftLastAccessTime;
    }

    LocalTime FileSystemInfo::LastWriteTime() const
    {
        return _data.ftLastWriteTime;
    }

    SystemTime FileSystemInfo::LastWriteTimeUtc() const
    {
        return _data.ftLastWriteTime;
    }

    String FileSystemInfo::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::IO::FileSystemInfo");
    }

    bool operator==(FileSystemInfo const& left, FileSystemInfo const& right) noexcept
    {
        constexpr size_t size = sizeof(FileSystemInfo);
        const uint8_t* lp = reinterpret_cast<const uint8_t*>(&left);
        const uint8_t* rp = reinterpret_cast<const uint8_t*>(&right);

        for (size_t i = 0; i < size; i++) {
            if (lp[i] != rp[i]) return false;
        }

        return true;
    }

}
