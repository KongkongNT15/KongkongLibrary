#ifndef KONGKONG_THREADING_MUTEX_H
#define KONGKONG_THREADING_MUTEX_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Threading
{
    struct Mutex final : public ValueType {

        Mutex() noexcept;

#ifdef KONGKONG_ENV_WINDOWS
        Mutex(Mutex const& mutex) noexcept;
#elif defined(__POSIX__)
        Mutex(Mutex const& mutex) = delete;
#endif
        Mutex(Mutex&& mutex) noexcept;

        ~Mutex() noexcept;

#ifdef KONGKONG_ENV_WINDOWS
        Mutex& operator=(Mutex const& mutex) noexcept;
#elif defined(__POSIX__)
        Mutex& operator=(Mutex const& mutex) = delete;
#endif
        Mutex& operator=(Mutex&& mutex) noexcept;

        /// @brief ほかのスレッドをブロック
        void Lock();

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        //bool TryLock();

        /// @brief 所有権を解放
        void Unlock();

        private:
#ifdef KONGKONG_ENV_WINDOWS
        ::HANDLE _hMutex;
#elif defined(__POSIX__)
        ::pthread_mutex_t _mutex;
        bool _isActive;
#endif
    };
}

#endif
