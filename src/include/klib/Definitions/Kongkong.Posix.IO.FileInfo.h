#ifndef KONGKONG_POSIX_IO_FILEINFO_H
#define KONGKONG_POSIX_IO_FILEINFO_H

#include "Base.h"
#include "Kongkong.ValueType.h"

#include "Kongkong.Posix.IO.FileMode.h"
#include "Kongkong.Posix.IO.FileType.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    struct FileInfo final : public ValueType {

        friend bool operator==(FileInfo const& left, FileInfo const& right) noexcept;

        /// @brief ふぁ！？っく
        FileInfo(std::nullptr_t, ::KONGKONG_NAMESPACE::Posix::IO::FileType) = delete;

        explicit FileInfo(DirectoryEntry const& entry);
        //explicit FileInfo(const char* fileName, ::KONGKONG_NAMESPACE::Posix::IO::FileType fileType) : _name(fileName), _fileType(fileType) {}
        //explicit FileInfo(std::string const& fileName, ::KONGKONG_NAMESPACE::Posix::IO::FileType fileType) : _name(fileName), _fileType(fileType) {}
        //explicit FileInfo(std::string&& fileName, ::KONGKONG_NAMESPACE::Posix::IO::FileType fileType) : _name(std::move(fileName)), _fileType(fileType) {}
        //explicit FileInfo(String const& fileName, ::KONGKONG_NAMESPACE::Posix::IO::FileType fileType) : _name(std::to_string(fileName)), _fileType(fileType) {}

        [[nodiscard]]
        constexpr ::blkcnt_t BlockCount() const noexcept { return _stat.st_blocks; }

        [[nodiscard]]
        constexpr ::blksize_t BlockSize() const noexcept { return _stat.st_blksize; }

        [[nodiscard]]
        constexpr ::time_t CreatedTime() const noexcept { return _stat.st_birthtimespec.tv_sec; }

        [[nodiscard]]
        constexpr long CreatedTimeNano() const noexcept { return _stat.st_birthtimespec.tv_nsec; }

        [[nodiscard]]
        constexpr ::dev_t DeviceID() const noexcept { return _stat.st_dev; }

        [[nodiscard]]
        constexpr ::off_t FileSize() const noexcept { return _stat.st_size; }

        [[nodiscard]]
        ::KONGKONG_NAMESPACE::Posix::IO::FileType FileType() const noexcept { return (::KONGKONG_NAMESPACE::Posix::IO::FileType)_fileType; }

        [[nodiscard]]
        constexpr ::gid_t GID() const noexcept { return _stat.st_gid; }

        [[nodiscard]]
        constexpr ::nlink_t HardLinkCount() const noexcept { return _stat.st_nlink; }

        [[nodiscard]]
        constexpr ::ino_t INode() const noexcept { return _stat.st_ino; }

        [[nodiscard]]
        constexpr ::time_t LastAccessTime() const noexcept { return _stat.st_atimespec.tv_sec; }

        [[nodiscard]]
        constexpr long LastAccessTimeNano() const noexcept { return _stat.st_atimespec.tv_nsec; }
        
        [[nodiscard]]
        constexpr ::time_t LastStatusChangedTime() const noexcept { return _stat.st_ctimespec.tv_sec; }

        [[nodiscard]]
        constexpr long LastStatusChangedTimeNano() const noexcept { return _stat.st_ctimespec.tv_nsec; }

        [[nodiscard]]
        constexpr ::time_t LastWrittenTime() const noexcept { return _stat.st_mtimespec.tv_sec; }

        [[nodiscard]]
        constexpr long LastWrittenTimeNano() const noexcept { return _stat.st_mtimespec.tv_nsec; }

        [[nodiscard]]
        constexpr FileMode Mode() const noexcept { return (FileMode)_stat.st_mode; }

        [[nodiscard]]
        constexpr const char* Name() const noexcept { return _name.c_str(); }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        [[nodiscard]]
        constexpr ::uid_t UID() const noexcept { return _stat.st_uid; }

        private:
        CharString _name;
        ::KONGKONG_NAMESPACE::Posix::IO::FileType _fileType;
        struct ::stat _stat;

    };

    [[nodiscard]] bool operator==(FileInfo const& left, FileInfo const& right) noexcept;
    [[nodiscard]] bool operator!=(FileInfo const& left, FileInfo const& right) noexcept;
}

#endif //!KONGKONG_POSIX_IO_FILEINFO_H
