#ifndef KONGKONG_CSTD_CCONSOLE_H
#define KONGKONG_CSTD_CCONSOLE_H

#include "Base.h"
#include "Kongkong.CStd.CStdException.h"

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief 
    class CConsole final {
        public:

        STATIC_CLASS(CConsole)

        /// @brief 標準入力から1文字取得
        /// @return 取得した文字の文字コード EOFの可能性がある
        [[nodiscard]]
        static int Read() noexcept;

        /// @brief 標準入力から1行分取得
        /// @return 1行分の文字列
        [[nodiscard]]
        static std::string ReadLine();

        /// @brief 標準出力に1文字出力
        /// @param c 出力する文字
        /// @return 出力した文字の文字コード EOFの可能性がある
        static int Write(char c) noexcept;
        
        /// @brief 文字列を標準出力に出力
        /// @attention NULLの場合は Null と出力されるよ！
        /// @param str 出力する文字列
        static void Write(const char* str) noexcept;

        static void ReopenOutput(const char* fileName);
        static void ReopenInput(const char* fileName);
        static void ReopenError(const char* fileName);

        /// @brief 文字列を改行付きで出力
        /// @param str 出力する文字列 NULLの場合は Null と出力される
        /// @return 操作に成功すれば 0 失敗すれば EOF
        static int WriteLine(const char* str) noexcept;

        /// @brief printf()と同じ
        /// @tparam ...Args 可変長引数テンプレート
        /// @param format Cスタイル文字列フォーマット
        /// @param ...args 出力する値
        template <class... Args>
        static void WriteFormat(const char* format, Args... args)
        { 
            if (::printf(format, args...) == EOF) [[unlikely]] throw CStdException();
        }
        
    };
}

#endif //!KONGKONG_CSTD_CCONSOLE_H
