#ifndef KONGKONG_ARGUMENTNULLEXCEPTION_H
#define KONGKONG_ARGUMENTNULLEXCEPTION_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.ArgumentException.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 引数がnull
    struct ArgumentNullException : public ArgumentException {

        /// @brief ふぁ！？っく
        static void CheckNull(std::nullptr_t, const char16_t*) = delete;
        /// @brief ふぁ！？っく
        static void CheckNull(const void*, std::nullptr_t) = delete;
        /// @brief ふぁ！？っく
        static void CheckNull(Object const&, std::nullptr_t) = delete;
        /// @brief ふぁ！？っく
        static void CheckNull(std::nullptr_t, std::nullptr_t) = delete;

#ifdef KONGKONG_OBJECTIVE_C_ENABLED
        /// @brief ふぁ！？っく
        static void CheckNull(AppleDevice::NSObject const&, std::nullptr_t) = delete;
#endif

        /// @brief ポインターがnullptrでないかを確認する
        /// @param p 対象のポインター
        /// @param pName 変数名
        /// @throws ArgumentNullException: pがnullptrのとき
        static void CheckNull(const void* p, const char16_t* pName);

        /// @brief オブジェクトがnullptrでないかを確認する
        /// @param p 対象のオブジェクト
        /// @param pName 変数名
        /// @throws ArgumentNullException: objectがnullptrのとき
        static void CheckNull(Object const& object, const char16_t* pName);

#ifdef KONGKONG_OBJECTIVE_C_ENABLED
        /// @brief オブジェクトがnullptrでないかを確認する
        /// @param p 対象のオブジェクト
        /// @param pName 変数名
        /// @throws ArgumentNullException: objectがnullptrのとき
        static void CheckNull(AppleDevice::NSObject const& object, const char16_t* pName);
#endif

        /// @brief ふぁ！？っく
        static void ThrowWithName(std::nullptr_t) = delete;

        /// @brief 変数名を使用して例外をスロー
        /// @attention nameをnullptrにしないでね！
        /// @param name 変数名
        /// @throws ArgumentNullException: 必ずスローする
        [[noreturn]]
        static void ThrowWithName(const char16_t* name);

        using ArgumentException::ArgumentException;
    };
    
}

#endif //!KONGKONG_ARGUMENTNULLEXCEPTION_H
