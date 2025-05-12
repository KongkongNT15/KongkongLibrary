#ifndef KONGKONG_THREADING_SCOPELOCK_H
#define KONGKONG_THREADING_SCOPELOCK_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Threading.Mutex.h"

namespace KONGKONG_NAMESPACE::Threading
{
    struct ScopeLock final : public ValueType {

        /// @brief _mutex.Lock()を実行
        /// @param mutex ロックするオブジェクト
        ScopeLock(Mutex& mutex);
        ScopeLock(ScopeLock const&) = delete;

        /// @brief _mutex.Unlock()を実行
        ~ScopeLock();

        ScopeLock& operator=(ScopeLock const&) = delete;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        Mutex& _mutex;

    };
}

#endif //!KONGKONG_THREADING_SCOPELOCK_H
