#ifndef KONGKONG_CSTD_CTHREAD_H
#define KONGKONG_CSTD_CTHREAD_H

#include "Base.h"
#include "Kongkong.HandleType.h"

#include <threads.h>

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief C標準のスレッド
    class CThread final : public HandleType {
        public:

        /// @brief このスレッド
        [[nodiscard]]
        static CThread Current() noexcept;

        /// @brief このスレッドを終了する
        /// @param returnCode 終了コード
        [[noreturn]]
        static void Exit(int returnCode) noexcept;

        /// @brief スレッドを中断
        /// @attention 失敗しても例外は投げないよ！
        /// @param timePoint 中断する時間
        /// @return 実行結果
        static CThreadSleepResult Sleep(::timespec const& timePoint) noexcept;
        
        /// @brief スレッドを中断
        /// @attention 失敗しても例外は投げないよ！
        /// @param timePoint 中断する時間
        /// @param remaining 途中で復帰した場合の残り時間の書き込み先
        /// @return 実行結果
        static CThreadSleepResult Sleep(::timespec const& timePoint, ::timespec& remaining) noexcept;

        /// @brief スレッドを中断
        /// @attention 失敗しても例外は投げないよ！
        /// @param microSeconds 中断する時間
        /// @return 実行結果
        static CThreadSleepResult SleepForMicroSeconds(::time_t microSeconds) noexcept;

        /// @brief スレッドを中断
        /// @attention 失敗しても例外は投げないよ！
        /// @param milliSeconds 中断する時間
        /// @return 実行結果
        static CThreadSleepResult SleepForMilliSeconds(::time_t milliSeconds) noexcept;

        /// @brief スレッドを中断
        /// @attention 失敗しても例外は投げないよ！
        /// @param nanoSeconds 中断する時間
        /// @return 実行結果
        static CThreadSleepResult SleepForNanoSeconds(::time_t nanoSeconds) noexcept;

        /// @brief スレッドを中断
        /// @attention 失敗しても例外は投げないよ！
        /// @param timePoint 中断する時間
        /// @return 実行結果
        static CThreadSleepResult SleepForSeconds(::time_t seconds) noexcept;

        /// @brief スレッドの作成
        /// @param func 実行する関数
        /// @throws CThreadException: 操作に失敗したとき
        explicit CThread(::thrd_start_t func);

        /// @brief スレッドの作成
        /// @param func 実行する関数
        /// @param args funcに与える引数
        /// @throws CThreadException: 操作に失敗したとき
        explicit CThread(::thrd_start_t func, void* args);

        /// @brief スレッドハンドルをデタッチ
        /// @throws CThreadException: 操作に失敗したとき
        void Detach();

        /// @return 操作に成功すればtrue
        /// @return 失敗すればfalse
        bool DetachUnsafe() noexcept;

        /// @brief スレッドの終了を待機
        /// @attention エラーが発生しても例外は投げないよ！
        /// @return 実行結果
        CThreadResult Join() noexcept;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        ::thrd_t _thread;

        static CThreadSleepResult _sleep(::timespec const& timePoint, ::timespec* p) noexcept;

        constexpr CThread(::thrd_t const& thread) noexcept : _thread(thread) {}

        friend bool operator==(CThread const& left, CThread const& right) noexcept;
    };

    [[nodiscard]]
    bool operator==(CThread const& left, CThread const& right) noexcept;

    [[nodiscard]]
    bool operator!=(CThread const& left, CThread const& right) noexcept;
}

#endif //!KONGKONG_CSTD_CTHREAD_H
