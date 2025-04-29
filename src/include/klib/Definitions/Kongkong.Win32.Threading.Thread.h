#ifndef KONGKONG_WIN32_THREAD_H
#define KONGKONG_WIN32_THREAD_H

#include "Base.h"
#include "Kongkong.Win32.Threading.WaitHandle.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class Thread final : public WaitHandle {
        public:
        using VoidFunc = void (*)();

        /// @brief このスレッド
        [[nodiscard]]
        static Thread Current() noexcept;

        /// @brief このスレッドを動かしているプロセッサ番号
        [[nodiscard]]
        static uint32_t CurrentProcessorNumber() noexcept;

        /// @brief このスレッドを動かしているプロセッサのグループとプロセッサ番号
        [[nodiscard]]
        static ProcessorNumber CurrentProcessorGroupAndNumber() noexcept;

        //static WaitObjectInfo Run(VoidFunc func) { return Run(func, INFINITE); }
        //static WaitObjectInfo Run(VoidFunc func, uint32_t milliseconds);
        [[nodiscard]] static WaitObjectInfo Run(::LPTHREAD_START_ROUTINE func);
        [[nodiscard]] static WaitObjectInfo Run(::LPTHREAD_START_ROUTINE func, uint32_t milliseconds);
        [[nodiscard]] static WaitObjectInfo Run(::LPTHREAD_START_ROUTINE func, void* parameter);
        [[nodiscard]] static WaitObjectInfo Run(::LPTHREAD_START_ROUTINE func, void* parameter, uint32_t milliseconds);

        static void Sleep(uint32_t milliseconds) noexcept;
        static WaitStatus Sleep(uint32_t milliseconds, bool isAlertable) noexcept;

        //スレッドが終了する前にExitCode()を呼ぶと出てくる値
        [[nodiscard]]
        static constexpr uint32_t StillActive() noexcept { return STILL_ACTIVE; }


        //Thread(VoidFunc func) : Thread(func, 0, ThreadStart::RightAway) {}
        //Thread(VoidFunc func, ThreadStart flag) : Thread(func, 0, flag) {}
        //Thread(VoidFunc func, size_t stackSize, ThreadStart flag);
        explicit Thread(::LPTHREAD_START_ROUTINE func);
        explicit Thread(::LPTHREAD_START_ROUTINE func, ThreadStart flag);
        explicit Thread(::LPTHREAD_START_ROUTINE func, void* parameter);
        explicit Thread(::LPTHREAD_START_ROUTINE func, void* parameter, ThreadStart flag);
        explicit Thread(::LPTHREAD_START_ROUTINE func, size_t stackSize, ThreadStart flag);
        explicit Thread(::LPTHREAD_START_ROUTINE func, void* parameter, size_t stackSize, ThreadStart flag);
        explicit Thread(::LPTHREAD_START_ROUTINE func, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Thread(::LPTHREAD_START_ROUTINE func, ThreadStart flag, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Thread(::LPTHREAD_START_ROUTINE func, void* parameter, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Thread(::LPTHREAD_START_ROUTINE func, size_t stackSize, ThreadStart flag, ::SECURITY_ATTRIBUTES& securityAttributes);
        explicit Thread(::LPTHREAD_START_ROUTINE func, void* parameter, size_t stackSize, ThreadStart flag, ::SECURITY_ATTRIBUTES& securityAttributes);

        /// @brief nullptrとして作成
        constexpr Thread(std::nullptr_t) noexcept : WaitHandle(nullptr) {}

        /// @brief このスレッドの中断数をデクリメント
        /// @return 以前の中断カウント
        /// @throws HResultException: 操作に失敗したとき
        uint32_t Resume() const;

        /// @brief このスレッドの中断数をデクリメント
        /// @return 以前の中断カウント
        /// @return 操作に失敗した場合は(uint32_t)-1
        uint32_t ResumeUnsafe() const noexcept;

        /// @brief 
        /// @return 
        [[nodiscard]]
        uint32_t ExitCode() const;

        [[nodiscard]]
        uint32_t GetExitCodeUnsafe() const noexcept;

        /// @brief このスレッドの中断数をインクリメント
        /// @return 以前の中断カウント
        /// @throws HResultException: 操作に失敗したとき
        uint32_t Suspend() const;

        /// @brief このスレッドの中断数をインクリメント
        /// @return 以前の中断カウント
        /// @return 操作に失敗した場合は(uint32_t)-1
        uint32_t SuspendUnsafe() const noexcept;

        /// @brief スレッドを強制終了
        /// @param exitCode 終了コード
        /// @throws HResultException: 操作に失敗したとき
        void Terminate(uint32_t exitCode) const;

        /// @brief スレッドを強制終了
        /// @param exitCode 終了コード
        /// @return 操作に成功すればtrue
        /// @return 失敗すればfalse
        bool TerminateUnsafe(uint32_t exitCode) const noexcept;

        /// @brief このスレッドのID
        /// @throws HResultException: 操作に失敗したとき
        [[nodiscard]]
        uint32_t ThreadId() const;

        /// @brief このスレッドのID
        /// @throws HResultException: 操作に失敗したとき
        [[nodiscard]]
        uint32_t ThreadIdUnsafe() const noexcept;

        private:

        friend String Handle::ToString() const;

        static String _toString(Handle const& handle);
        
    };
}

#endif //!KONGKONG_WIN32_THREAD_H
