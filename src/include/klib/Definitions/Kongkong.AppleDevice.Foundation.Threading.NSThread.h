#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSTHREAD_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSTHREAD_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    class NSThread : public NSObject {
        public:
        using EntryPointType = void(*)(void*);

        /// @brief ふぁ！？っく
        static NSThread CreateUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static NSThread CreateUnsafe(std::nullptr_t, std::nullptr_t) = delete;
        
        /// @brief ふぁ！？っく
        static NSThread CreateUnsafe(std::nullptr_t, void*) = delete;

        /// @brief スレッドを作成
        /// @param entryPoint エントリーポイント
        /// @return 作成されたスレッドオブジェクト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSThread CreateUnsafe(EntryPointType entryPoint);

        /// @brief スレッドを作成
        /// @param entryPoint エントリーポイント
        /// @param args 引数
        /// @return 作成されたスレッドオブジェクト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSThread CreateUnsafe(EntryPointType entryPoint, void* args);

        /// @brief スレッドを作成
        /// @param entryPoint エントリーポイント
        /// @return 作成されたスレッドオブジェクト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        static NSThread CreateUnsafe(EntryPointType entryPoint, std::nullptr_t);

        /// @brief このスレッド
        [[nodiscard]]
        static NSThread CurrentThread() noexcept;

        /// @brief このスレッドの優先度を0.0~1.0の範囲で取得
        [[nodiscard]]
        static double CurrentThreadPriority() noexcept;

        /// @brief このスレッドの優先度を0.0~1.0の範囲で設定
        /// @attention 範囲外の値を指定すると範囲内の値に丸められるよ！
        /// @param priority 優先度
        static void CurrentThreadPriority(double priority) noexcept;

        /// @brief このスレッドを終了
        static void Exit() noexcept;

        /// @brief このスレッドがメインスレッドであるかどうか
        [[nodiscard]]
        static bool IsCurrentThreadMain() noexcept;

        [[nodiscard]]
        static bool IsMultiThreaded() noexcept;

        /// @brief メインスレッド
        [[nodiscard]]
        static NSThread MainThread() noexcept;

        static void SleepForTimeInterval(double seconds) noexcept;

        /// @brief ふぁ！？っく
        NSThread(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        NSThread(std::nullptr_t, void*) = delete;

        /// @brief スレッドを作成
        /// @param entryPoint エントリーポイント
        /// @return 作成されたスレッドオブジェクト
        /// @throws ArgumentNullException: entryPointがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSThread(EntryPointType entryPoint);

        /// @brief スレッドを作成
        /// @param entryPoint エントリーポイント
        /// @param args 引数
        /// @return 作成されたスレッドオブジェクト
        /// @throws ArgumentNullException: entryPointがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSThread(EntryPointType entryPoint, void* args);

        /// @brief スレッドを作成
        /// @param entryPoint エントリーポイント
        /// @return 作成されたスレッドオブジェクト
        /// @throws ArgumentNullException: entryPointがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSThread(EntryPointType entryPoint, std::nullptr_t);

        /// @brief nullptrとして作成
        constexpr NSThread(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief スレッドがキャンセルされたかどうかを取得
        [[nodiscard]]
        bool GetIsCancelledUnsafe() const noexcept;

        /// @brief スレッドが実行中かどうかを取得
        [[nodiscard]]
        bool GetIsExecutingUnsafe() const noexcept;

        /// @brief スレッドが終了したかどうかを取得
        [[nodiscard]]
        bool GetIsFinishedUnsafe() const noexcept;

        [[nodiscard]]
        bool GetIsMainThreadUnsafe() const noexcept;

        [[nodiscard]]
        size_t GetStackSizeUnsafe() const noexcept;

        /// @brief スレッドの優先順位を0.0~1.0の範囲で取得
        [[nodiscard]]
        double GetThreadPriorityUnsafe() const noexcept;

        /// @brief スレッドがキャンセルされたかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsCancelled() const;

        /// @brief スレッドが実行中かどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsExecuting() const;

        /// @brief スレッドが終了したかどうか
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        bool IsFinished() const;

        [[nodiscard]]
        bool IsMainThread() const;

        [[nodiscard]]
        size_t StackSize() const;

        void StackSize(size_t stackSize) const;

        /// @brief スレッドを開始
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Start() const;

        /// @brief スレッドを開始
        void StartUnsafe() const noexcept;

        void SetStackSizeUnsafe(size_t stackSize) const noexcept;

        /// @brief スレッドの優先度を0.0~1.0の範囲で設定
        /// @attention 範囲外の値を指定すると範囲内の値に丸められるよ！
        /// @param priority 優先度
        void SetThreadPriorityUnsafe(double priority) const noexcept;

        /// @brief スレッドの優先度を0.0~1.0の範囲で取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        double ThreadPriority() const;

        /// @brief スレッドの優先度を0.0~1.0の範囲で設定
        /// @attention 範囲外の値を指定すると範囲内の値に丸められるよ！
        /// @param priority 優先度
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void ThreadPriority(double priority) const;

    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSTHREAD_H
