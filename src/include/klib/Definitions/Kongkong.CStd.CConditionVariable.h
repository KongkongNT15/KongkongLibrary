#ifndef KONGKONG_CSTD_CONDITIONVARIABLE_H
#define KONGKONG_CSTD_CONDITIONVARIABLE_H

#include "Base.h"
#include "Kongkong.HandleType.h"

#include <threads.h>

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief C標準の条件変数
    class CConditionVariable final : public HandleType {
        public:

        /// @brief 条件変数を作成
        /// @throws CThreadException: 操作に失敗したとき
        CConditionVariable();
        CConditionVariable(CConditionVariable const&) = delete;

        ~CConditionVariable();

        CConditionVariable& operator=(CConditionVariable const&) = delete;

        /// @brief すべてのスレッドのブロックを解除
        /// @throws CThreadException: 操作に失敗したとき
        void BroadCast();

        CThreadStatus BroadCastUnsafe() noexcept;

        /// @brief 待機中のスレッドを1つだけブロック解除
        /// @throws CThreadException: 操作に失敗したとき
        void Signal();

        CThreadStatus SignalUnsafe() noexcept;

        void TimedWait(CMutex& mutex, ::timespec const& time);

        CThreadStatus TimedWaitUnsafe(CMutex& mutex, ::timespec const& time) noexcept;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        /// @brief ふぁ！？っく
        void Wait(CMutex&, std::nullptr_t) = delete;

        void Wait(CMutex& mutex);

        void Wait(CMutex& mutex, bool(*func)());

        /// @brief ふぁ！？っく
        CThreadStatus WaitUnsafe(CMutex&, std::nullptr_t) = delete;

        CThreadStatus WaitUnsafe(CMutex& mutex) noexcept;

        CThreadStatus WaitUnsafe(CMutex& mutex, bool(*func)()) noexcept;

        private:
        ::cnd_t _condition;
    };
}

#endif //!KONGKONG_CSTD_CONDITIONVARIABLE_H
