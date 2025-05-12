//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Std
{
    StlThreadPool::StlThreadPool() : StlThreadPool(::std::thread::hardware_concurrency(), 0)
    {
    }

    StlThreadPool::StlThreadPool(ssize_t threadCount) :
        m_workers(Collections::Turbo::FastArrayList<::std::thread>::CreateWithCapacity(threadCount)),
        m_isRunning(true)
    {
        m_initialize(threadCount);
    }

    StlThreadPool::~StlThreadPool()
    {
        m_isRunning = false;

        m_condition.notify_all();

        for (::std::thread& t : m_workers) {
            t.join();
        }
    }

    void StlThreadPool::AppendTask(TaskEntryPoint entryPoint)
    {
        ::std::unique_lock<::std::mutex> lock(m_mutex);
        m_tasks.Push(s_task{ entryPoint, nullptr });

        m_condition.notify_one();
    }

    void StlThreadPool::AppendTask(TaskEntryPoint entryPoint, ::std::nullptr_t)
    {
        ::std::unique_lock<::std::mutex> lock(m_mutex);
        m_tasks.Push(s_task{ entryPoint, nullptr });

        m_condition.notify_one();
    }

    void StlThreadPool::AppendTask(TaskEntryPoint entryPoint, void* args)
    {
        ::std::unique_lock<::std::mutex> lock(m_mutex);
        m_tasks.Push(s_task{ entryPoint, args });

        m_condition.notify_one();
    }

    String StlThreadPool::ToString() const
    {
        return String::FromLiteral(u"Kongkong::Std::StlThreadPool");
    }

    StlThreadPool::StlThreadPool(ssize_t threadCount, int) :
        m_workers(Collections::Turbo::FastArrayList<::std::thread>::CreateWithCapacityUnsafe(threadCount)),
        m_isRunning(true)
    {
        m_initialize(threadCount);
    }

    StlThreadPool::s_task StlThreadPool::m_getTask()
    {
        ::std::unique_lock<::std::mutex> lock(m_mutex);

        while (m_tasks.Length() == 0 && m_isRunning) {
            m_condition.wait(lock);
        }

        if (!m_isRunning || m_tasks.Length() == 0) return s_task{};

        return m_tasks.PopUnsafe();
    }

    void StlThreadPool::m_initialize(ssize_t threadCount)
    {
#if KONGKONG_HAS_CPP23
        [[assume(threadCount >= 1)]];
#endif
        try {
            for (ssize_t count = 0; count != threadCount; count++) {
                m_workers.Emplace(s_workerEntryPoint, this);
            }
        }
        catch (...) {
            StlThreadPool::~StlThreadPool();
            ::std::rethrow_exception(::std::current_exception());
        }
        
    }

    void StlThreadPool::s_workerEntryPoint(StlThreadPool* pThreadPool)
    {
#if KONGKONG_HAS_CPP23
        [[assume(pThreadPool != nullptr)]];
#endif
        StlThreadPool& threadPool = *pThreadPool;

        while (threadPool.m_isRunning) {
            s_task task = threadPool.m_getTask();

            if (task.m_func != nullptr) {
                task.m_func(task.args);
            }
        }
    }
}