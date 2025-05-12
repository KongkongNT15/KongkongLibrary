#ifndef KONGKONG_POSIX_THREADING_MUTEX_H
#define KONGKONG_POSIX_THREADING_MUTEX_H

#include "Base.h"
#include "Kongkong.HandleType.h"

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    struct Mutex final : public HandleType, private ::pthread_mutex_t {

        Mutex();
        Mutex(MutexKind kind);
        Mutex(Mutex const&) = delete;

        ~Mutex();

        Mutex& operator=(Mutex const&) = delete;

        /// @brief このオブジェクトをロックします
        /// @throws PosixException: ロックに失敗したとき
        void Lock();

        /// @brief ロックを試みます
        /// @details オブジェクトがロックされていなければ、ロックする
        /// @details すでにロックされていれば何もしない
        /// @return ロックできればtrue
        /// @return 他のスレッドがロックしていればfalse
        bool TryLock() noexcept;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]] 
        String ToString() const;
    };
}

#endif //!KONGKONG_POSIX_THREADING_MUTEX_H
