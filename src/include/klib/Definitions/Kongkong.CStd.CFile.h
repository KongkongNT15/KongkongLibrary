#ifndef KONGKONG_CSTD_CFILE_H
#define KONGKONG_CSTD_CFILE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::CStd
{
    class CFile final {
        public:
        STATIC_CLASS(CFile)

        /// @brief Tempファイルの名前を生成
        /// @throws CStdException: 操作に失敗したとき
        [[nodiscard]]
        static CharString CreateTempFileName();

        /// @brief ふぁ！？っく
        static void Remove(std::nullptr_t) = delete;

        /// @brief ファイルを削除
        /// @param filePath 削除するファイルのパス
        /// @throws ArgumentNullException: filePathがnullptrのとき
        /// @throws CStdException: 操作に失敗したとき
        static void Remove(const char* filePath);

        /// @brief ファイルを削除
        /// @param filePath 削除するファイルのパス
        /// @throws CStdException: 操作に失敗したとき
        static void Remove(CharString const& filePath);

        /// @brief ふぁ！？っく
        static void Rename(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void Rename(const char*, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void Rename(std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        static void Rename(CharString const&, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void Rename(std::nullptr_t, CharString const&) = delete;

        /// @brief ファイルの名前を変更
        /// @param oldPath 元のファイル名
        /// @param newPath 変更後のファイル名
        /// @throws ArgumentNullException: oldPathまたはnewPathがnullptrのとき
        /// @throws CStdException: 操作に失敗したとき
        static void Rename(const char* oldPath, const char* newPath);

        /// @brief ファイルの名前を変更
        /// @param oldPath 元のファイル名
        /// @param newPath 変更後のファイル名
        /// @throws ArgumentNullException: newPathがnullptrのとき
        /// @throws CStdException: 操作に失敗したとき
        static void Rename(CharString const& oldPath, const char* newPath);

        /// @brief ファイルの名前を変更
        /// @param oldPath 元のファイル名
        /// @param newPath 変更後のファイル名
        /// @throws ArgumentNullException: oldPathがnullptrのとき
        /// @throws CStdException: 操作に失敗したとき
        static void Rename(const char* oldPath, CharString const& newPath);

        /// @brief ファイルの名前を変更
        /// @param oldPath 元のファイル名
        /// @param newPath 変更後のファイル名
        /// @throws CStdException: 操作に失敗したとき
        static void Rename(CharString const& oldPath, CharString const& newPath);

        private:
        /// @brief ファイルの名前を変更
        /// @param oldPath 元のファイル名
        /// @param newPath 変更後のファイル名
        /// @throws CStdException: 操作に失敗したとき
        static void _rename(const char* oldPath, const char* newPath);
    };
}

#endif //!KONGKONG_CSTD_CFILE_H
