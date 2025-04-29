#ifndef KONGKONG_CSTD_CSTDEXCEPTION_H
#define KONGKONG_CSTD_CSTDEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief C言語標準APIのエラー
    struct CStdException : public Exception {

        /// @brief errnoからエラー文を取得
        /// @param errorNumber エラー番号
        [[nodiscard]]
        static String ErrorNumberToString(int errorNumber);

        /// @brief ふぁ！？っく
        CStdException(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        CStdException(int, std::nullptr_t) = delete;

        /// @brief errnoを使用して作成
        explicit CStdException();

        /// @param errorMessage 例外メッセージ
        /// @warning errorMessageをからの文字列またはnullptrにすると例外メッセージが「ふぁ！？っく」になる
        explicit CStdException(String const& errorMessage);

        /// @param errorMessage 例外メッセージ
        /// @warning errorMessageをからの文字列またはnullptrにすると例外メッセージが「ふぁ！？っく」になる
        explicit CStdException(String&& errorMessage);

        /// @param errorMessage 例外メッセージ
        /// @warning errorMessageをからの文字列またはnullptrにすると例外メッセージが「ふぁ！？っく」になる
        explicit CStdException(const char16_t* errorMessage);

        /// @param errorCode エラーコード
        /// @param errorMessage 例外メッセージ
        /// @warning errorMessageをからの文字列またはnullptrにすると例外メッセージが「ふぁ！？っく」になる
        explicit CStdException(int errorCode, String const& errorMessage);

        /// @param errorCode エラーコード
        /// @param errorMessage 例外メッセージ
        /// @warning errorMessageをからの文字列またはnullptrにすると例外メッセージが「ふぁ！？っく」になる
        explicit CStdException(int errorCode, String&& errorMessage);

        /// @param errorCode エラーコード
        /// @param errorMessage 例外メッセージ
        /// @warning errorMessageをからの文字列またはnullptrにすると例外メッセージが「ふぁ！？っく」になる
        explicit CStdException(int errorCode, const char16_t* errorMessage);

        /// @brief エラーコードを取得
        [[nodiscard]]
        constexpr int ErrorCode() const noexcept { return _errorCode; }

        private:
        int _errorCode;
    };
}

#endif //!KONGKONG_CSTD_CSTDEXCEPTION_H
