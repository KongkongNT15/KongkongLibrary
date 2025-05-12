#ifndef KONGKONG_POSIX_IO_DIRECTORYENTRY_H
#define KONGKONG_POSIX_IO_DIRECTORYENTRY_H

#include "Base.h"
#include "Kongkong.ValueType.h"

#include "Kongkong.Posix.IO.FileType.h"
#include "Kongkong.Posix.IO.FileMode.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    struct DirectoryEntry final : public ValueType {

        DirectoryEntry(DirectoryEntry const&) = delete;
        DirectoryEntry& operator=(DirectoryEntry const&) = delete;

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
        constexpr ::KONGKONG_NAMESPACE::Posix::IO::FileType FileType() const noexcept { return (::KONGKONG_NAMESPACE::Posix::IO::FileType)_dirent->d_type; }

        [[nodiscard]]
        constexpr ::gid_t GID() const noexcept { return _stat.st_gid; }

        [[nodiscard]]
        constexpr ::dirent* Handle() const noexcept { return _dirent; }

        [[nodiscard]]
        constexpr ::nlink_t HardLinkCount() const noexcept { return _stat.st_nlink; }

        [[nodiscard]]
        constexpr bool HasValidData() const noexcept { return _dirent != nullptr; }

        [[nodiscard]]
        constexpr ::ino_t INode() const noexcept { return _stat.st_ino; }

        [[nodiscard]]
        constexpr time_t LastAccessTime() const noexcept { return _stat.st_atimespec.tv_sec; }

        [[nodiscard]]
        constexpr long LastAccessTimeNano() const noexcept { return _stat.st_atimespec.tv_nsec; }
        
        [[nodiscard]]
        constexpr time_t LastStatusChangedTime() const noexcept { return _stat.st_ctimespec.tv_sec; }

        [[nodiscard]]
        constexpr long LastStatusChangedTimeNano() const noexcept { return _stat.st_ctimespec.tv_nsec; }

        [[nodiscard]]
        constexpr time_t LastWrittenTime() const noexcept { return _stat.st_mtimespec.tv_sec; }

        [[nodiscard]]
        constexpr long LastWrittenTimeNano() const noexcept { return _stat.st_mtimespec.tv_nsec; }

        [[nodiscard]]
        constexpr FileMode Mode() const noexcept { return (FileMode)_stat.st_mode; }

        [[nodiscard]]
        const char* Name() const { return _dirent->d_name; }

        [[nodiscard]]
        uint16_t NameLength() const noexcept { return _dirent->d_namlen; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき 
        [[nodiscard]]
        String ToString() const;

        [[nodiscard]]
        constexpr ::uid_t UID() const noexcept { return _stat.st_uid; }

        private:
        DirectoryEntry(::dirent* p, const char* directoryName);

        void Handle(::dirent* p);

        ::dirent* _dirent;
        struct ::stat _stat;
        CharString _directoryName;

        friend IMPLEMENTATION::DirectoryIterator;
        friend FileInfo;

    };
}

#endif //!KONGKONG_POSIX_IO_DIRECTORYENTRY_H
