#ifndef KONGKONG_FORMATEXCEPTION_H
#define KONGKONG_FORMATEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 書式エラー
    struct FormatException : public Exception {
        /// @param errorMessage 例外メッセージ
        /// @attention errorMessageを空の文字列にすると例外メッセージが「ふぁ！？っく」になる
        explicit FormatException(String const& errorMessage, bool useFormatErrorMessage = true);
    };
    
}

#endif //!KONGKONG_FORMATEXCEPTION_H
