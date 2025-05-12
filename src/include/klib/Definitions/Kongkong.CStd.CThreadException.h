#ifndef KONGKONG_CSTD_CTHREADEXCEPTION_H
#define KONGKONG_CSTD_CTHREADEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

#include "Kongkong.CStd.CThreadStatus.h"

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief スレッド操作の失敗
    struct CThreadException : public Exception {

        /// @brief ふぁ！？っく
        CThreadException(CThreadStatus, std::nullptr_t) = delete;

        /// @brief 作成
        /// @param status 状態
        /// @param message 例外メッセージ
        explicit CThreadException(CThreadStatus status, const char16_t* message);
        
        /// @brief 作成
        /// @param status 状態
        /// @param message 例外メッセージ
        explicit CThreadException(CThreadStatus status, String const& message);
        
        /// @brief 作成
        /// @param status 状態
        /// @param message 例外メッセージ
        explicit CThreadException(CThreadStatus status, String&& message);

        /// @brief 状態
        [[nodiscard]]
        constexpr CThreadStatus Status() const noexcept { return _status; }

        private:
        CThreadStatus _status;
    };
}

#endif //!KONGKONG_CSTD_CTHREADEXCEPTION_H
