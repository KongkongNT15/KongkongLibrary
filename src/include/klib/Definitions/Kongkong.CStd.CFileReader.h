#ifndef KONGKONG_CSTD_CFILEREADER_H
#define KONGKONG_CSTD_CFILEREADER_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.CStd._cFileReaderBase.h"

namespace KONGKONG_NAMESPACE::CStd
{
    struct CFileReader final : public HandleType, public _cFileReaderBase {

        /// @brief ふぁ！？っく
        constexpr CFileReader(std::nullptr_t) noexcept : _cFileReaderBase(nullptr) {}

        CFileReader(CFileReader const&) = delete;
        CFileReader(CFileReader&& right) noexcept;
        explicit CFileReader(const char* fileName);
        explicit CFileReader(CharString const& fileName);

        ~CFileReader();

        CFileReader& operator=(CFileReader const&) = delete;
        CFileReader& operator=(CFileReader&& right) noexcept;

        void DiscardLine();
        void DiscardLineUnsafe() noexcept;

        //戻り値に改行文字は含まれない
        [[nodiscard]] CharString GetLine();
        [[nodiscard]] CharString GetLineUnsafe() noexcept;

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

#endif //!KONGKONG_CSTD_CFILEREADER_H
