#ifndef KONGKONG_POSIX_THREADING_THREADPOOL_H
#define KONGKONG_POSIX_THREADING_THREADPOOL_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo.FastArrayList.h"
#include "Kongkong.Collections.Turbo.FastLinkedQueue.h"

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    /// @brief POSIX APIを使ったスレッドプール
    struct ThreadPool : public ValueType {
        using TaskEntryPoint = void(*)(void*);

        explicit ThreadPool();
        explicit ThreadPool(ssize_t threadCount);

        ThreadPool(ThreadPool const&) = delete;
        ThreadPool(ThreadPool&&) = delete;

        ~ThreadPool();

        ThreadPool& operator=(ThreadPool const&) = delete;
        ThreadPool& operator=(ThreadPool&&) = delete;

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

        /// @brief スレッド数
        [[nodiscard]]
        constexpr ssize_t ThreadCount() const noexcept { return m_workers.Length(); }

        String ToString() const;

        private:

        struct s_scopedLock {
            s_scopedLock(::pthread_mutex_t* pMutex) noexcept : m_pMutex(pMutex) { ::pthread_mutex_lock(pMutex); }

            ~s_scopedLock() { ::pthread_mutex_unlock(m_pMutex); }

            private:
            ::pthread_mutex_t* m_pMutex;
        };

        struct s_task {
            TaskEntryPoint entryPoint;
            void* args;
        };

        Collections::Turbo::FastArrayList<::pthread_t> m_workers;
        Collections::Turbo::FastLinkedQueue<s_task> m_taskQueue;
        ::pthread_mutex_t m_mutex;
        ::pthread_cond_t m_cond;
        bool m_isRunning;

        explicit ThreadPool(ssize_t threadCount, int);

        s_task m_getTask();

        void m_initialize(ssize_t threadCount);

        

        static void* s_threadEntryPoint(void* pThreadPool);
    };
}

#endif //!KONGKONG_POSIX_THREADING_THREADPOOL_H