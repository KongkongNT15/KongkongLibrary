//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{

#ifdef KONGKONG_ENV_WINDOWS
// なにもしない
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
    constinit AppleDevice::Foundation::Threading::NSOperationQueue ThreadPool::_queue = nullptr;
#elif defined(KONGKONG_ENV_UNIX)
    constinit LazyObject<Posix::Threading::ThreadPool> ThreadPool::s_pool;
#else
    constinit LazyObject<Std::StlThreadPool> ThreadPool::s_pool;
#endif

    AsyncAction ThreadPool::RunAsync(void(*callback)(void))
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#ifdef KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(_callback0, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
                //この時点で_queueはnullptrでない

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { _callback(); h.resume(); });
#else
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback0, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#ifdef KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS0 _s;
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
            void(*_callback)(void);
#else
            ThreadPool::_tmpS0 m_s;
#endif
        };
#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback };
#else

        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback };
#endif
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(void)> const& callback)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#ifdef KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(_callback1, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
                //この時点で_queueはnullptrでない

                auto* fp = &_callback;

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { fp->operator()(); h.resume(); });
#else
                //この時点で_poolはnullptrでない
                m_s.h = h;

                s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback1, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#ifdef KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS1 _s;
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
            const ::std::function<void(void)> _callback;
#else
            ThreadPool::_tmpS1 m_s;
#endif
        };

#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback };
#else

        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback };
#endif
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(void)>&& callback)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(std::coroutine_handle<> h) {
#ifdef KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(_callback1, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
                //この時点で_queueはnullptrでない

                auto* fp = &_callback;

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { fp->operator()(); h.resume(); });
#else
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback0, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#ifdef KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS1 _s;
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
            const ::std::function<void(void)> _callback;
#else
            ThreadPool::_tmpS1 m_s;
#endif
        };

#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ ::std::move(callback) };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ ::std::move(callback) };
#else

        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ ::std::move(callback) };
#endif
    }

#ifdef KONGKONG_ENV_WINDOWS
void ThreadPool::_callback0(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work)
    {
        _tmpS0* p = (_tmpS0*)context;

        p->cb();
        p->h.resume();
    }

    void ThreadPool::_callback1(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work)
    {
        _tmpS1* p = (_tmpS1*)context;

        p->cb();
        p->h.resume();
    }
#elif !defined(KONGKONG_OBJECTIVE_C_ENABLED)

    void ThreadPool::_callback0(void* args)
    {
        _tmpS0& s = *static_cast<_tmpS0*>(args);

        s.cb();

        s.h.resume();
    }

    void ThreadPool::_callback1(void* args)
    {
        _tmpS1& s = *static_cast<_tmpS1*>(args);

        s.cb();

        s.h.resume();
    }
#endif
}
