#ifndef KONGKONG_CSTD_CBINARYFILEREADER_H
#define KONGKONG_CSTD_CBINARYFILEREADER_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.CStd._cFileReaderBase.h"

namespace KONGKONG_NAMESPACE::CStd
{
    struct CBinaryFileReader final : public HandleType, public _cFileReaderBase {
        /// @brief nullptrとして作成
        constexpr CBinaryFileReader(std::nullptr_t) noexcept : _cFileReaderBase(nullptr) {}

        CBinaryFileReader(CBinaryFileReader const&) = delete;
        CBinaryFileReader(CBinaryFileReader&& right) noexcept;
        explicit CBinaryFileReader(const char* fileName);
        explicit CBinaryFileReader(CharString const& fileName);

        ~CBinaryFileReader();

        CBinaryFileReader& operator=(CBinaryFileReader const&) = delete;
        CBinaryFileReader& operator=(CBinaryFileReader&& right) noexcept;

        /// @brief ふぁ！？っく
        size_t Get(std::nullptr_t, size_t) = delete;

        size_t Get(void* buffer, size_t bufferLength);

        /// @brief ふぁ！？っく
        size_t GetUnsafe(std::nullptr_t, size_t) = delete;
        
        size_t GetUnsafe(void* buffer, size_t bufferLength) noexcept;

        /// @brief ファイルを開く
        /// @param fileName ファイルパス
        /// @throws ArgumentNullException: fileNameがnullptrのとき
        /// @throws CStdException: 操作に失敗したとき
        void Open(const char* fileName);

        /// @brief ファイルを開く
        /// @param fileName ファイルパス
        /// @throws CStdException: 操作に失敗したとき
        void Open(CharString const& fileName);

        /// @brief ファイルを開く
        /// @param fileName ファイルパス
        /// @throws CStdException: 操作に失敗したとき
        void OpenUnsafe(const char* fileName);

        /// @brief ファイルを閉じて別のファイルを開く
        /// @param fileName ファイルパス
        /// @throws ArgumentNullException: fileNameがnullptrのとき
        /// @throws CStdException: 操作に失敗したとき
        void Reopen(const char* fileName);

        /// @brief ファイルを閉じて別のファイルを開く
        /// @param fileName ファイルパス
        /// @throws CStdException: 操作に失敗したとき
        void Reopen(CharString const& fileName);

        /// @brief ファイルを閉じて別のファイルを開く
        /// @param fileName ファイルパス
        /// @throws CStdException: 操作に失敗したとき
        void ReopenUnsafe(const char* fileName);

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;
        
    };
}

#endif //!KONGKONG_CSTD_CBINARYFILEREADER_H
