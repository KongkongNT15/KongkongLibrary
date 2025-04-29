#ifndef KONGKONG_CSTD_CFILEWRITER_H
#define KONGKONG_CSTD_CFILEWRITER_H

#include "Base.h"
#include "Kongkong.ArgumentException.h"
#include "Kongkong.CStd._cFileWriterBase.h"
#include "Kongkong.CStd.CStdException.h"
#include "Kongkong.HandleType.h"

namespace KONGKONG_NAMESPACE::CStd
{
    struct CFileWriter final : public HandleType, public _cFileWriterBase {
        /// @brief nullptrとして作成
        constexpr CFileWriter(std::nullptr_t) noexcept : _cFileWriterBase(nullptr) {}
        
        explicit CFileWriter(const char* fileName);
        explicit CFileWriter(CharString const& fileName);
        CFileWriter(CFileWriter const&) = delete;
        CFileWriter(CFileWriter&& right) noexcept;

        ~CFileWriter();

        CFileWriter& operator=(CFileWriter const&) = delete;
        CFileWriter& operator=(CFileWriter&& right) noexcept;
        
        /// @brief writeモードでファイルを開く
        /// @param fileName ファイルパス
        /// @throws ArgumentNullException: fileNameがnullptrのとき
        /// @throws CStdException: ファイルを開けなかったとき
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

        /// @brief 1文字書き込む
        /// @param c 書き込む文字
        /// @throws IOException: ファイルが開かれていないとき
        void PutCharacter(char c);

        /// @brief 1文字書き込む
        /// @param c 書き込む文字
        /// @return 書き込んだ文字、失敗した場合はEOF
        int PutCharacterUnsafe(char c) noexcept;
        
        /// @brief ふぁ！？っく
        void PutString(std::nullptr_t) = delete;

        /// @brief 文字列を書き込む
        /// @param str 書き込む文字列
        /// @throws IOException: ファイルが開かれていないとき
        /// @throws ArgumentNullException: strがnullptrのとき
        void PutString(const char* str);

        /// @brief ふぁ！？っく
        void PutStringUnsafe(std::nullptr_t) = delete;

        /// @brief 文字列を書き込む
        /// @param str 書き込む文字列
        /// @return 操作に成功した場合は0、失敗した場合はEOF
        int PutStringUnsafe(const char* str) noexcept;

        /// @brief 文字列を書き込む
        /// @param length 書き込む文字数
        /// @param str 書き込む文字列
        /// @throws IOException: ファイルが開かれていないとき
        /// @throws ArgumentNullException: strがnullptrのとき
        /// @throws InvalidArgumentException: lengthがゼロのとき
        void PutString(size_t length, const char* str);

        /// @brief 文字列を書き込む
        /// @param length 書き込む文字数
        /// @param str 書き込む文字列
        void PutStringUnsafe(size_t length, const char* str) noexcept;

        /// @brief ふぁ！？っく
        void PutLine(std::nullptr_t) = delete;

        /// @brief 改行文字を書き込む
        /// @throws IOException: ファイルが開かれていないとき
        void PutLine();
        
        /// @brief 改行文字付きで文字列を書き込む
        /// @param str 文字列
        /// @throws IOException: ファイルが開かれていないとき 
        /// @throws ArgumentNullException: strがnullptrのとき
        void PutLine(const char* str);

        /// @brief ふぁ！？っく
        void PutLineUnsafe(std::nullptr_t) = delete;

        /// @brief 改行文字を書き込む
        /// @return 操作に成功した場合は0、失敗した場合はEOF
        int PutLineUnsafe() noexcept;

        /// @brief 改行文字付きで文字列を書き込む
        /// @param str 文字列
        void PutLineUnsafe(const char* str) noexcept;

        /// @brief ふぁ！？っく
        template <class... Args>
        void WriteFormat(std::nullptr_t, Args...) = delete;

        /// @brief fprintfと同じ
        /// @attention 安全ではない可能性
        /// @param format 書式
        /// @param ...args 可変長引数
        /// @throws IOException: ファイルが開かれていないとき
        /// @throws ArgumentNullException: formatがnullptrのとき
        /// @throws CStdException: 致命的なエラーが発生したとき
        template <class... Args>
        void WriteFormat(const char* format, Args... args)
        {
            _checkIsOpen();
            ArgumentNullException::CheckNull(format, u"format");
            
            if (::fprintf(_fp, format, args...) == EOF) [[unlikely]] throw CStdException();
        }

        /// @brief ふぁ！？っく
        template <class... Args>
        void WriteFormatUnsafe(std::nullptr_t, Args...) = delete;

        /// @brief fprintfと同じ
        /// @param format 書式
        /// @param ...args 可変長引数
        /// @return 出力された文字数、致命的なエラーが発生した場合はEOF
        template <class... Args>
        int WriteFormatUnsafe(const char* format, Args... args) noexcept
        {
            return ::fprintf(_fp, format, args...);
        }

        /// @brief ふぁ！？っく
        template <class... Args>
        void WriteLineFormat(std::nullptr_t, Args...) = delete;

        template <class... Args>
        void WriteLineFormat(const char* format, Args... args)
        {
            WriteFormat(format, args...);
            ::fputc('\n', _fp);
        }

        /// @brief ふぁ！？っく
        template <class... Args>
        void WriteLineFormatUnsafe(std::nullptr_t, Args...) = delete;

        template <class... Args>
        void WriteLineFormatUnsafe(const char* format, Args... args) noexcept
        {
            ::fprintf(_fp, format, args...);
            ::fputc('\n', _fp);
        }

        /// @brief クラス名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;
    };
}

#endif //!KONGKONG_CSTD_CFILEWRITER_H
