//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    ThreadPool::ThreadPool() : ThreadPool(::std::thread::hardware_concurrency(), 0)
    {
    }

    ThreadPool::ThreadPool(ssize_t threadCount) : m_workers(Collections::Turbo::FastArrayList<::pthread_t>::CreateWithCapacity(threadCount)), m_isRunning(true)
    {
        m_initialize(threadCount);
    }

    ThreadPool::~ThreadPool()
    {
        m_isRunning = false;

        ::pthread_cond_broadcast(&m_cond);

        for (pthread_t workers : m_workers) {
            ::pthread_join(workers, nullptr);
        }

        ::pthread_mutex_destroy(&m_mutex);
        ::pthread_cond_destroy(&m_cond);
    }

    void ThreadPool::AppendTask(TaskEntryPoint entryPoint)
    {
        AppendTask(entryPoint, (void*)nullptr);
    }

    void ThreadPool::AppendTask(TaskEntryPoint entryPoint, ::std::nullptr_t)
    {
        AppendTask(entryPoint, (void*)nullptr);
    }

    void ThreadPool::AppendTask(TaskEntryPoint entryPoint, void* args)
    {
        s_scopedLock lock(&m_mutex);

        m_taskQueue.Push(s_task{ entryPoint, args });

        ::pthread_cond_signal(&m_cond);
    }

    String ThreadPool::ToString() const
    {
        return String::FromLiteral(u"Kongkong::Posix::Threading::ThreadPool");
    }

    ThreadPool::ThreadPool(ssize_t threadCount, int) : m_workers(Collections::Turbo::FastArrayList<::pthread_t>::CreateWithCapacityUnsafe(threadCount)), m_isRunning(true)
    {
        m_initialize(threadCount);
    }

    ThreadPool::s_task ThreadPool::m_getTask()
    {
        s_scopedLock lock(&m_mutex);

        while (m_taskQueue.Length() == 0 && m_isRunning) {
            ::pthread_cond_wait(&m_cond, &m_mutex);
        }

        if (!m_isRunning || m_taskQueue.Length() == 0) return s_task{};

        return m_taskQueue.PopUnsafe();
    }

    void ThreadPool::m_initialize(ssize_t threadCount)
    {
        constexpr char16_t errorMessage[] = u"スレッドプールの初期化に失敗しました";

#if KONGKONG_HAS_CPP23
        [[assume(threadCount >= 1)]];
#endif
        
        if (::pthread_mutex_init(&m_mutex, nullptr) != 0) [[unlikely]] throw Kongkong::Threading::ThreadStateException(errorMessage);

        if (::pthread_cond_init(&m_cond, nullptr) != 0) [[unlikely]] {
            ::pthread_mutex_destroy(&m_mutex);

            throw Kongkong::Threading::ThreadStateException(errorMessage);
        }

        ::pthread_t thread;

        for (ssize_t count = 0; count != threadCount; count++) {
            if (::pthread_create(&thread, nullptr, s_threadEntryPoint, this) != 0) [[unlikely]] {
                ThreadPool::~ThreadPool();
                throw Kongkong::Threading::ThreadStateException(errorMessage);
            }
            m_workers.Append(thread);
        }
        
    }

    void* ThreadPool::s_threadEntryPoint(void* pThreadPool)
    {
#if KONGKONG_HAS_CPP23
        [[assume(pThreadPool != nullptr)]];
#endif
        ThreadPool& threadPool = *static_cast<ThreadPool*>(pThreadPool);

        while (threadPool.m_isRunning) {
            s_task task = threadPool.m_getTask();

            if (task.entryPoint != nullptr) {
                task.entryPoint(task.args);
            }
        }

        return nullptr;
    }
}