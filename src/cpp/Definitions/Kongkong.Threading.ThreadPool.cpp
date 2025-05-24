//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{

#if KONGKONG_ENV_WINDOWS
// なにもしない
#elif KONGKONG_OBJECTIVE_C_ENABLED
    constinit AppleDevice::Foundation::Threading::NSOperationQueue ThreadPool::_queue = nullptr;
#elif KONGKONG_ENV_UNIX
    constinit LazyObject<Posix::Threading::ThreadPool> ThreadPool::s_pool = nullptr;
#else
    constinit LazyObject<Std::StlThreadPool> ThreadPool::s_pool = nullptr;
#endif

    void ThreadPool::ParallelFor(ssize_t begin, ssize_t end, void(*f)(ssize_t))
    {
        s_parallelFor(::std::thread::hardware_concurrency(), begin, end, f);
    }

    void ThreadPool::ParallelFor(ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f)
    {
        s_parallelFor(::std::thread::hardware_concurrency(), begin, end, f);
    }

    void ThreadPool::ParallelFor(uint32_t threadCount, ssize_t begin, ssize_t end, void(*f)(ssize_t))
    {
        s_parallelFor(threadCount, begin, end, f);
    }

    void ThreadPool::ParallelFor(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f)
    {
        s_parallelFor(threadCount, begin, end, f);
    }

    template <class TFunc>
    void ThreadPool::s_parallelFor(uint32_t threadCount, ssize_t begin, ssize_t end, TFunc f)
    {
#if !KONGKONG_OBJECTIVE_C_ENABLED
        struct fArgs {
            ssize_t b;
            ssize_t e;
            TFunc f;
    #if KONGKONG_ENV_WINDOWS
            ::PTP_WORK work;
    #else
            ::std::atomic<uint32_t>* pFinishedCount;
    #endif
        };
#endif

#if KONGKONG_ENV_WINDOWS
        void (*func)(::PTP_CALLBACK_INSTANCE, ::PVOID, ::PTP_WORK) = [](::PTP_CALLBACK_INSTANCE, ::PVOID args, ::PTP_WORK) {
            auto& fargs = *static_cast<fArgs*>(args);
            while (fargs.b != fargs.e) {
                fargs.f(fargs.b);
                ++fargs.b;
            }
        };
#elif KONGKONG_OBJECTIVE_C_ENABLED
        // なにもしない
#else
        void(*func)(void*) = [](void* args) {
            auto& fargs = *static_cast<fArgs*>(args);
            while (fargs.b != fargs.e) {
                fargs.f(fargs.b);
                ++fargs.b;
            }
            auto& ato = *fargs.pFinishedCount;
            ++ato;
        };
#endif
        ssize_t count = end - begin;

        if (count <= 0) [[unlikely]] return;

        ssize_t listCapacity;

        if ((ssize_t)threadCount > count) listCapacity = count;
        else listCapacity = threadCount;

#if !KONGKONG_OBJECTIVE_C_ENABLED
        auto list = 
    #if KONGKONG_ENV_WINDOWS
            Collections::Turbo::FastArrayList<fArgs>::CreateWithCapacityUnsafe(listCapacity);
    #else
            Collections::Turbo::FastArrayList<fArgs>::CreateWithCapacityUnsafe(listCapacity);
    #endif
#endif
        ssize_t c = count % listCapacity;
        ssize_t d = count / listCapacity;

#if KONGKONG_ENV_WINDOWS
        // 何もしない
#elif KONGKONG_OBJECTIVE_C_ENABLED
        ::std::atomic<uint32_t> finishedCount = 0;
        auto pFinishedCount = &finishedCount;
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();
#else
        ::std::atomic<uint32_t> finishedCount = 0;
        auto pFinishedCount = &finishedCount;
        if (!s_pool.IsInitialized()) s_pool.InitializeUnsafe();
#endif

        if (c == 0) {
            for (ssize_t i = begin; i != end;) {

                ssize_t next = i + d;
#if KONGKONG_ENV_WINDOWS   
                list.Emplace(
                    i,
                    next,
                    f,
                    ::CreateThreadpoolWork(func, list.end(), nullptr)
                );
#elif KONGKONG_OBJECTIVE_C_ENABLED
                _queue.AddOperationWithBlockUnsafe(
                    ^{
                        for (ssize_t n = i; n != next; ++n) {
                            f(n);
                        }
                        auto& ato = *pFinishedCount;
                        ++ato;
                    }
                );
#else
                list.Emplace(i, next, f, pFinishedCount);
                s_pool.GetValueUnsafe().AppendTask(func, &list.GetBackUnsafe());
#endif

#if KONGKONG_ENV_WINDOWS
                ::SubmitThreadpoolWork(list.GetBackUnsafe().work);
#endif

                i = next;
            }
        }
        else {
            ssize_t n = d * (listCapacity * (d + 1) - count);
            ssize_t i = 0;

            while (i != n) {
                ssize_t next = i + d;
#if KONGKONG_ENV_WINDOWS   
                list.Emplace(
                    i,
                    next,
                    f,
                    ::CreateThreadpoolWork(func, list.end(), nullptr)
                );
#elif KONGKONG_OBJECTIVE_C_ENABLED
                _queue.AddOperationWithBlockUnsafe(
                    ^{
                        for (ssize_t n = i; n != next; ++n) {
                            f(n);
                        }
                        auto& ato = *pFinishedCount;
                        ++ato;
                    }
                );
#else
                list.Emplace(i, next, f, pFinishedCount);
                s_pool.GetValueUnsafe().AppendTask(func, &list.GetBackUnsafe());
#endif

#if KONGKONG_ENV_WINDOWS
                ::SubmitThreadpoolWork(list.GetBackUnsafe().work);
#endif
                i =  next;
            }

            d++;

            while (i != count) {
                ssize_t next = i + d;

#if KONGKONG_ENV_WINDOWS   
                list.Emplace(
                    i,
                    next,
                    f,
                    ::CreateThreadpoolWork(func, list.end(), nullptr)
                );
#elif KONGKONG_OBJECTIVE_C_ENABLED
                _queue.AddOperationWithBlockUnsafe(
                    ^{
                        for (ssize_t n = i; n != next; ++n) {
                            f(n);
                        }
                        auto& ato = *pFinishedCount;
                        ++ato;
                    }
                );
#else
                list.Emplace(i, next, f, pFinishedCount);
                s_pool.GetValueUnsafe().AppendTask(func, &list.GetBackUnsafe());
#endif
#if KONGKONG_ENV_WINDOWS
                ::SubmitThreadpoolWork(list.GetBackUnsafe().work);
#endif
                i = next;
            }
        }

#if KONGKONG_ENV_WINDOWS
        for (auto& fargs : list) {
            ::WaitForThreadpoolWorkCallbacks(fargs.work, FALSE);
            ::CloseThreadpoolWork(fargs.work);
        }
#elif KONGKONG_OBJECTIVE_C_ENABLED
        while (finishedCount != listCapacity) {
            using namespace ::std::chrono;
            ::std::this_thread::sleep_for(1ms);
        }
#else
        while (finishedCount != listCapacity) {
            using namespace ::std::chrono;
            ::std::this_thread::sleep_for(1ms);
        }
#endif
    }
}
