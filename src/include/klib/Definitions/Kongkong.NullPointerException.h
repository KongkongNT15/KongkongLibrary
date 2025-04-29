#ifndef KONGKONG_NULLPOINTEREXCEPTION_H
#define KONGKONG_NULLPOINTEREXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief NULL登場時の例外
    struct NullPointerException : public Exception {
        
        /// @brief ふぁ！？っく
        static void CheckNull(std::nullptr_t, const char16_t*) = delete;
        /// @brief ふぁ！？っく
        static void CheckNull(const void*, std::nullptr_t) = delete;
        /// @brief ふぁ！？っく
        static void CheckNull(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ポインターがnullptrでないかを確認する
        /// @param p 対象のポインター
        /// @param pName 変数名
        /// @throws NullPointerException: pがnullptrのとき
        static void CheckNull(const void* p, const char16_t* pName);

        using Exception::Exception;
    };

}

#endif //!KONGKONG_NULLPOINTEREXCEPTION_H
