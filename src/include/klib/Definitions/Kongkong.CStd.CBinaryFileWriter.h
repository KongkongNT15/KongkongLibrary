#ifndef KONGKONG_CSTD_CBINARYFILEWRITER_H
#define KONGKONG_CSTD_CBINARYFILEWRITER_H

#include "Base.h"
#include "Kongkong.CStd._cFileWriterBase.h"
#include "Kongkong.HandleType.h"

namespace KONGKONG_NAMESPACE::CStd
{
    struct CBinaryFileWriter final : public HandleType, public _cFileWriterBase {
        /// @brief nullptrとして作成
        constexpr CBinaryFileWriter(std::nullptr_t) noexcept : _cFileWriterBase(nullptr) {}

        explicit CBinaryFileWriter(const char* fileName);
        explicit CBinaryFileWriter(CharString const& fileName);
        CBinaryFileWriter(CBinaryFileWriter const&) = delete;
        CBinaryFileWriter(CBinaryFileWriter&& right) noexcept;

        ~CBinaryFileWriter();

        CBinaryFileWriter& operator=(CBinaryFileWriter const&) = delete;
        CBinaryFileWriter& operator=(CBinaryFileWriter&& right) noexcept;

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

        /// @brief ふぁ！？っく
        void Write(size_t, std::nullptr_t) = delete;

        void Write(uint8_t data);

        void Write(size_t size, const void* buffer);

        /// @brief ふぁ！？っく
        void WriteUnsafe(size_t, std::nullptr_t) = delete;

        int WriteUnsafe(uint8_t data) noexcept;
        
        size_t WriteUnsafe(size_t size, const void* buffer) noexcept;

    };
}

#endif //!KONGKONG_CSTD_CBINARYFILEWRITER_H
