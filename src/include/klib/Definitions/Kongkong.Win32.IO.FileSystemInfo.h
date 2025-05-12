#ifndef KONGKONG_WIN32_IO_FILESYSTEMINFO_H
#define KONGKONG_WIN32_IO_FILESYSTEMINFO_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Win32.IO.FileAttribute.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    struct FileSystemInfo final : public ValueType {

        //ファイル属性
        [[nodiscard]] constexpr FileAttribute Attributes() const noexcept { return (FileAttribute)_data.dwFileAttributes; }

        //作成日時
        [[nodiscard]] LocalTime CreationTime() const;
        [[nodiscard]] SystemTime CreationTimeUtc() const;

        //ファイル名
        [[nodiscard]] String FileName() const;

        //ファイルサイズ
        [[nodiscard]] uint64_t FileSize() const noexcept;

        //最後のアクセス日時
        [[nodiscard]] LocalTime LastAccessTime() const;
        [[nodiscard]] SystemTime LastAccessTimeUtc() const;

        //更新日時
        [[nodiscard]] LocalTime LastWriteTime() const;
        [[nodiscard]] SystemTime LastWriteTimeUtc() const;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;
        
        private:
        ::WIN32_FIND_DATA _data;

        constexpr FileSystemInfo(::WIN32_FIND_DATA const& right) noexcept : _data(right) {}
        constexpr FileSystemInfo() noexcept : _data() {}

        friend Directory;
        friend File;
        friend Path;

    };

    [[nodiscard]]
    bool operator==(FileSystemInfo const& left, FileSystemInfo const& right) noexcept;
}

#endif //!KONGKONG_WIN32_IO_FILESYSTEMINFO_H
