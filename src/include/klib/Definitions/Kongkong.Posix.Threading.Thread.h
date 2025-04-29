#ifndef KONGKONG_POSIX_THREAD_H
#define KONGKONG_POSIX_THREAD_H

#include "Base.h"
#include "Kongkong.HandleType.h"

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    class Thread final : public HandleType {
        public:
        using EntryPoint = void*(*)(void*);

        [[nodiscard]]
        static Thread Current() noexcept;

        /// @brief このスレッドを終了
        /// @param returnValue スレッドの戻り値
        void Exit(void* returnValue) noexcept { ::pthread_exit(returnValue); }

        static int Sleep(unsigned int seconds) noexcept { return ::sleep(seconds); }
        static int SleepForMicroseconds(unsigned int microseconds) noexcept { return ::usleep(microseconds); }

        /// @brief ふぁ！？っく
        Thread(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        Thread(std::nullptr_t, void*) = delete;

        /// @brief ふぁ！？っく
        Thread(std::nullptr_t, ThreadAttribute const&) = delete;

        /// @brief ふぁ！？っく
        Thread(std::nullptr_t, std::nullptr_t, ThreadAttribute const&) = delete;

        /// @brief ふぁ！？っく
        Thread(std::nullptr_t, void*, ThreadAttribute const&) = delete;

        Thread(EntryPoint entryPoint);
        Thread(EntryPoint entryPoint, std::nullptr_t);
        Thread(EntryPoint entryPoint, void* args);
        Thread(EntryPoint entryPoint, ThreadAttribute const& attribute);
        Thread(EntryPoint entryPoint, std::nullptr_t, ThreadAttribute const& attribute);
        Thread(EntryPoint entryPoint, void* args, ThreadAttribute const& attribute);
        Thread(Thread const&) = delete;
        constexpr Thread(Thread&& right) noexcept : _t(right._t) { right._t = nullptr; }

        /// @brief nullptrとして作成
        constexpr Thread(std::nullptr_t) noexcept : _t(nullptr) {}

        ~Thread();

        Thread& operator=(Thread const&) = delete;

        Thread& operator=(Thread&& right) noexcept;

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _t != nullptr; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return _t == nullptr; }

        /// @brief スレッドを強制終了
        void Cancel() const;

        /// @brief スレッドを強制終了
        int CancelUnsafe() const noexcept;

        /// @brief スレッドにシグナルを送信
        /// @param signal シグナル
        void Kill(int signal);

        /// @brief スレッドにシグナルを送信
        /// @param signal シグナル
        /// @return エラーコード
        int KillUnsafe(int signal) noexcept;

        /// @brief スレッドの終了を待機
        /// @return スレッドの戻り値
        /// @throws PosixException: 操作に失敗した時
        void* Join() const;

        /// @brief スレッドの終了を待機
        /// @return スレッドの戻り値
        void* JoinUnsafe() const noexcept;

        private:
        ::pthread_t _t;

        Thread(EntryPoint entryPoint, void* args, const ::pthread_attr_t* attribute);
        constexpr Thread(::pthread_t pThread) noexcept : _t(pThread) {}

        friend bool operator==(Thread const&, Thread const&) noexcept;
        friend constexpr bool operator==(Thread const&, std::nullptr_t) noexcept;
        friend constexpr bool operator==(std::nullptr_t, Thread const&) noexcept;
        friend bool operator!=(Thread const&, Thread const&) noexcept;
        friend constexpr bool operator!=(Thread const&, std::nullptr_t) noexcept;
        friend constexpr bool operator!=(std::nullptr_t, Thread const&) noexcept;
    };

    [[nodiscard]] bool operator==(Thread const&, Thread const&) noexcept;
    [[nodiscard]] constexpr bool operator==(Thread const& left, std::nullptr_t) noexcept { return left._t == nullptr; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, Thread const& right) noexcept { return nullptr == right._t; }
    [[nodiscard]] bool operator!=(Thread const&, Thread const&) noexcept;
    [[nodiscard]] constexpr bool operator!=(Thread const& left, std::nullptr_t) noexcept { return left._t != nullptr; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, Thread const& right) noexcept { return nullptr != right._t; }
}

#endif //!KONGKONG_POSIX_THREAD_H
