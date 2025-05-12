#ifndef KONGKONG_CSTD_CMUTEX_H
#define KONGKONG_CSTD_CMUTEX_H

#include "Base.h"
#include "Kongkong.HandleType.h"

#include <threads.h>

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief C標準のミューテックス
    class CMutex final : public HandleType {
        public:

        /// @brief CMutexKind::Plainとして作成
        /// @throws CThreadException: 作成に失敗したとき
        CMutex();

        /// @brief 種類を指定して作成
        /// @param kind 種類
        /// @throws CThreadException: 作成に失敗したとき
        explicit CMutex(CMutexKind kind);

        CMutex(CMutex const&) = delete;

        /// @brief オブジェクトを破棄
        ~CMutex();

        CMutex& operator=(CMutex const&) = delete;

        /// @brief ほかのスレッドをブロック
        /// @throws CThreadException: 操作に失敗したとき
        void Lock();

        /// @brief ほかのスレッドをブロック
        /// @return 操作に成功すればtrue
        /// @return 失敗すればfalse
        bool LockUnsafe() noexcept;

        /// @brief ロックを試みる
        /// @return ロックに成功すればCThreadStatus::Success
        /// @return すでにロックされていればCThreadStatus::Busy
        /// @return 操作に失敗すればCThreadStatus::Error
        CThreadStatus TryLock() noexcept;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        /// @brief 所有権を解放
        /// @throws CThreadException: 操作に失敗したとき
        void Unlock();

        /// @brief 所有権を解放
        /// @return 操作に成功すればtrue
        /// @return 失敗すればfalse
        bool UnlockUnsafe() noexcept;

        private:

        ::mtx_t _mutex;

        friend CConditionVariable;
    };
}

#endif //!KONGKONG_CSTD_CMUTEX_H
