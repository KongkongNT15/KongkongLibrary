#ifndef KONGKONG_STD_STLTHREADPOOL_H
#define KONGKONG_STD_STLTHREADPOOL_H

#include "Base.h"
#include <mutex>
#include <condition_variable>
#include <thread>
#include "Kongkong.Collections.Turbo.FastArrayList.h"
#include "Kongkong.Collections.Turbo.FastLinkedQueue.h"

namespace KONGKONG_NAMESPACE::Std
{
    /// @brief STLの機能を使ったスレッドプール
    struct StlThreadPool final : public ValueType {
        using TaskEntryPoint = void(*)(void*);

        explicit StlThreadPool();
        explicit StlThreadPool(ssize_t threadCount);

        StlThreadPool(StlThreadPool const&) = delete;
        StlThreadPool(StlThreadPool&&) = delete;

        ~StlThreadPool();

        StlThreadPool& operator=(StlThreadPool const&) = delete;
        StlThreadPool& operator=(StlThreadPool&&) = delete;

        /// @brief ふぁ！？っく
        void AppendTask(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void AppendTask(::std::nullptr_t, ::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void AppendTask(::std::nullptr_t, void*) = delete;

        /// @brief タスクを追加
        /// @attention この関数はentryPointがnullptrであるかどうかを判定しないよ！
        /// @param entryPoint エントリーポイント
        void AppendTask(TaskEntryPoint entryPoint);

        /// @brief タスクを追加
        /// @attention この関数はentryPointがnullptrであるかどうかを判定しないよ！
        /// @param entryPoint エントリーポイント
        void AppendTask(TaskEntryPoint entryPoint, ::std::nullptr_t);

        /// @brief タスクを追加
        /// @attention この関数はentryPointがnullptrであるかどうかを判定しないよ！
        /// @param entryPoint エントリーポイント
        /// @param args パラメータ
        void AppendTask(TaskEntryPoint entryPoint, void* args);

        /// @brief ワーカースレッド数
        [[nodiscard]]
        constexpr ssize_t ThreadCount() const noexcept { return m_workers.Length(); }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;
        
        private:
        struct s_task {
            TaskEntryPoint m_func;
            void* args;
        };

        Collections::Turbo::FastArrayList<::std::thread> m_workers;
        Collections::Turbo::FastLinkedQueue<s_task> m_tasks;
        ::std::mutex m_mutex;
        ::std::condition_variable m_condition;
        bool m_isRunning;

        StlThreadPool(ssize_t threadCount, int);

        s_task m_getTask();

        void m_initialize(ssize_t threadCount);

        static void s_workerEntryPoint(StlThreadPool* pThreadPool);
    };
}

#endif //!KONGKONG_STD_STLTHREADPOOL_H