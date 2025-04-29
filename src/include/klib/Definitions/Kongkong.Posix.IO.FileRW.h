#ifndef KONGKONG_POSIX_IO_FILERW_H
#define KONGKONG_POSIX_IO_FILERW_H

#include "Base.h"
#include "Kongkong.Posix.IO.RWDevice.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    /// @brief ファイル読み書き
    class FileRW final : public RWDevice {
        public:

        using RWDevice::RWDevice;

        /// @brief ふぁ！？っく
        explicit FileRW(std::nullptr_t, FileOpen) = delete;

        /// @brief ふぁ！？っく
        explicit FileRW(std::nullptr_t, FileOpen, FileMode) = delete;

        /// @brief ふぁ！？っく
        explicit FileRW(std::nullptr_t, FileMode) = delete;

        /// @brief ファイルを開く
        /// @param fileName ファイル名
        /// @throws PosixException: 操作に失敗した時
        explicit FileRW(const char* fileName);
        explicit FileRW(const char* fileName, FileOpen openMode);
        explicit FileRW(const char* fileName, FileOpen openMode, FileMode mode);
        explicit FileRW(const char* fileName, FileMode mode);

        /// @brief ファイルを開く
        /// @param fileName ファイル名
        /// @throws PosixException: 操作に失敗した時
        explicit FileRW(CharString const& fileName);
        explicit FileRW(CharString const& fileName, FileOpen openMode);
        explicit FileRW(CharString const& fileName, FileOpen openMode, FileMode mode);
        explicit FileRW(CharString const& fileName, FileMode mode);
    };
}

#endif //!KONGKONG_POSIX_IO_FILERW_H
