#ifndef KONGKONG_WIN32_HRESULTEXCEPTION_H
#define KONGKONG_WIN32_HRESULTEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE::Win32
{
    /// @brief Win32APIのエラー
    struct HResultException final : public Exception {

        /// @brief HRESULT値からエラーメッセージを取得
        /// @param hResult HRESULT値
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static String HResultToString(::HRESULT hResult);
        
        /// @brief 2種類のエラー番号から作成
        /// @param hResult HRESULT値
        /// @param errorCode システムエラーコード
        HResultException(::HRESULT hResult, DWORD errorCode);

        /// @brief HRESULT値から作成
        /// @attention ErrorCode()はERROR_SUCCESSになるよ
        /// @param hResult HRESULT値
        HResultException(::HRESULT hResult);

        /// @brief システムエラーコードから作成
        /// @attention HRESULT値も設定されるよ
        /// @param errorCode エラーコード
        HResultException(::DWORD errorCode);

        /// @brief GetLastError()で作成
        /// @attention HRESULT値も設定されるよ
        HResultException();

        /// @brief HRESULT値
        [[nodiscard]]
        constexpr ::HRESULT HResult() const noexcept { return _hResult; }

        /// @brief システムエラーコード
        [[nodiscard]]
        constexpr ::DWORD ErrorCode() const noexcept { return _errorCode; }

        private:
        ::HRESULT _hResult;
        ::DWORD _errorCode;
    };
}

#endif //!KONGKONG_WIN32_HRESULTEXCEPTION_H
