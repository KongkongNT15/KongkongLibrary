#ifndef KONGKONG_POSIX_IO_DIRECTORYINFO_H
#define KONGKONG_POSIX_IO_DIRECTORYINFO_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Posix.IO.FileMode.h"

#include <string>

namespace KONGKONG_NAMESPACE::Posix::IO
{
    struct DirectoryInfo final : public ValueType {

        /// @brief ふぁ！？っく
        DirectoryInfo(std::nullptr_t) = delete;

        explicit DirectoryInfo(const char* path);
        explicit DirectoryInfo(std::string const& path);
        explicit DirectoryInfo(std::string&& path);
        explicit DirectoryInfo(String const& path);

        [[nodiscard]] DirectoryIterator begin() const;
        [[nodiscard]] DirectoryIterator end() const;

        [[nodiscard]] Collections::IArray<FileInfo> GetChildren() const;
        [[nodiscard]] Collections::IArray<FileInfo> GetDirectories() const;
        [[nodiscard]] Collections::IArray<FileInfo> GetFiles() const;

        [[nodiscard]] constexpr ::blkcnt_t BlockCount() const noexcept { return _stat.st_blocks; }

        [[nodiscard]] constexpr ::blksize_t BlockSize() const noexcept { return _stat.st_blksize; }

        [[nodiscard]] constexpr ::time_t CreatedTime() const noexcept { return _stat.st_birthtimespec.tv_sec; }

        [[nodiscard]] constexpr long CreatedTimeNano() const noexcept { return _stat.st_birthtimespec.tv_nsec; }

        [[nodiscard]] constexpr ::dev_t DeviceID() const noexcept { return _stat.st_dev; }

        [[nodiscard]] constexpr ::off_t FileSize() const noexcept { return _stat.st_size; }

        [[nodiscard]] constexpr ::gid_t GID() const noexcept { return _stat.st_gid; }

        [[nodiscard]] constexpr ::nlink_t HardLinkCount() const noexcept { return _stat.st_nlink; }

        [[nodiscard]] constexpr ::ino_t INode() const noexcept { return _stat.st_ino; }

        [[nodiscard]] constexpr ::time_t LastAccessTime() const noexcept { return _stat.st_atimespec.tv_sec; }

        [[nodiscard]] constexpr long LastAccessTimeNano() const noexcept { return _stat.st_atimespec.tv_nsec; }
        
        [[nodiscard]] constexpr ::time_t LastStatusChangedTime() const noexcept { return _stat.st_ctimespec.tv_sec; }

        [[nodiscard]] constexpr long LastStatusChangedTimeNano() const noexcept { return _stat.st_ctimespec.tv_nsec; }

        [[nodiscard]] constexpr ::time_t LastWrittenTime() const noexcept { return _stat.st_mtimespec.tv_sec; }

        [[nodiscard]] constexpr long LastWrittenTimeNano() const noexcept { return _stat.st_mtimespec.tv_nsec; }

        [[nodiscard]] constexpr FileMode Mode() const noexcept { return (FileMode)_stat.st_mode; }

        [[nodiscard]] String ToString() const;

        [[nodiscard]] constexpr ::uid_t UID() const noexcept { return _stat.st_uid; }

        
        private:
        std::string _path;
        struct ::stat _stat;

        static void _checkPath(const char* path, struct ::stat& stat);
    };
}

#endif //!KONGKONG_POSIX_IO_DIRECTORYINFO_H
