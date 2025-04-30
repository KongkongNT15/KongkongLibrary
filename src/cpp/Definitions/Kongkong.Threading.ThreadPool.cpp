//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{
#if defined(KONGKONG_ENV_WINDOWS) || defined(KONGKONG_OBJECTIVE_C_ENABLED) || defined(__POSIX__)

#ifdef KONGKONG_OBJECTIVE_C_ENABLED
    constinit AppleDevice::Foundation::Threading::NSOperationQueue ThreadPool::_queue = nullptr;
#elif defined(__POSIX__)
    constinit LazyObject<Posix::Threading::ThreadPool> ThreadPool::s_pool;
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
#elif defined(__POSIX__)
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
#elif defined(__POSIX__)
            ThreadPool::_tmpS0 m_s;
#endif
        };
#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback };
#elif defined(__POSIX__)

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
#elif defined(__POSIX__)
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
#elif defined(__POSIX__)
            ThreadPool::_tmpS1 m_s;
#endif
        };

#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback };
#elif defined(__POSIX__)

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
#elif defined(__POSIX__)
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
#elif defined(__POSIX__)
            ThreadPool::_tmpS1 m_s;
#endif
        };

#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ ::std::move(callback) };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ ::std::move(callback) };
#elif defined(__POSIX__)

        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ ::std::move(callback) };
#endif
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(char), char arg)
    {
        return _runAsync0<char, char>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(char)> const& callback, char arg)
    {
        return _runAsync1<char, char>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(char)>&& callback, char arg)
    {
        return _runAsync2<char, char>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(signed char), signed char arg)
    {
        return _runAsync0<signed char, signed char>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(signed char)> const& callback, signed char arg)
    {
        return _runAsync1<signed char, signed char>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(signed char)>&& callback, signed char arg)
    {
        return _runAsync2<signed char, signed char>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(unsigned char), unsigned char arg)
    {
        return _runAsync0<unsigned char, unsigned char>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned char)> const& callback, unsigned char arg)
    {
        return _runAsync1<unsigned char, unsigned char>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned char)>&& callback, unsigned char arg)
    {
        return _runAsync2<unsigned char, unsigned char>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(short), short arg)
    {
        return _runAsync0<short, short>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(short)> const& callback, short arg)
    {
        return _runAsync1<short, short>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(short)>&& callback, short arg)
    {
        return _runAsync2<short, short>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(unsigned short), unsigned short arg)
    {
        return _runAsync0<unsigned short, unsigned short>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned short)> const& callback, unsigned short arg)
    {
        return _runAsync1<unsigned short, unsigned short>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned short)>&& callback, unsigned short arg)
    {
        return _runAsync2<unsigned short, unsigned short>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(int), int arg)
    {
        return _runAsync0<int, int>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(int)> const& callback, int arg)
    {
        return _runAsync1<int, int>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(int)>&& callback, int arg)
    {
        return _runAsync2<int, int>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(unsigned int), unsigned int arg)
    {
        return _runAsync0<unsigned int, unsigned int>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned int)> const& callback, unsigned int arg)
    {
        return _runAsync1<unsigned int, unsigned int>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned int)>&& callback, unsigned int arg)
    {
        return _runAsync2<unsigned int, unsigned int>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(long), long arg)
    {
        return _runAsync0<long, long>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(long)> const& callback, long arg)
    {
        return _runAsync1<long, long>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(long)>&& callback, long arg)
    {
        return _runAsync2<long, long>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(unsigned long), unsigned long arg)
    {
        return _runAsync0<unsigned long, unsigned long>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned long)> const& callback, unsigned long arg)
    {
        return _runAsync1<unsigned long, unsigned long>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned long)>&& callback, unsigned long arg)
    {
        return _runAsync2<unsigned long, unsigned long>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(long long), long long arg)
    {
        return _runAsync0<long long, long long>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(long long)> const& callback, long long arg)
    {
        return _runAsync1<long long, long long>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(long long)>&& callback, long long arg)
    {
        return _runAsync2<long long, long long>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(unsigned long long), unsigned long long arg)
    {
        return _runAsync0<unsigned long long, unsigned long long>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned long long)> const& callback, unsigned long long arg)
    {
        return _runAsync1<unsigned long long, unsigned long long>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(unsigned long long)>&& callback, unsigned long long arg)
    {
        return _runAsync2<unsigned long long, unsigned long long>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(float), float arg)
    {
        return _runAsync0<float, float>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(float)> const& callback, float arg)
    {
        return _runAsync1<float, float>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(float)>&& callback, float arg)
    {
        return _runAsync2<float, float>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(double), double arg)
    {
        return _runAsync0<double, double>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(double)> const& callback, double arg)
    {
        return _runAsync1<double, double>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(double)>&& callback, double arg)
    {
        return _runAsync2<double, double>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(long double), long double arg)
    {
        return _runAsync0<long double, long double>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(long double)> const& callback, long double arg)
    {
        return _runAsync1<long double, long double>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(long double)>&& callback, long double arg)
    {
        return _runAsync2<long double, long double>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(void*), void* arg)
    {
        return _runAsync0<void*, void*>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(void*), ::std::nullptr_t)
    {
        return _runAsync0<void*, void*>(callback, nullptr);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(void*)> const& callback, void* arg)
    {
        return _runAsync1<void*, void*>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(void*)> const& callback, ::std::nullptr_t)
    {
        return _runAsync1<void*, void*>(callback, nullptr);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(void*)>&& callback, void* arg)
    {
        return _runAsync2<void*, void*>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(void*)>&& callback, ::std::nullptr_t)
    {
        return _runAsync2<void*, void*>(::std::move(callback), nullptr);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(const void*), const void* arg)
    {
        return _runAsync0<const void*, const void*>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(const void*), void* arg)
    {
        return _runAsync0<const void*, const void*>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(const void*), ::std::nullptr_t)
    {
        return _runAsync0<const void*, const void*>(callback, nullptr);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(const void*)> const& callback, const void* arg)
    {
        return _runAsync1<const void*, const void*>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(const void*)> const& callback, void* arg)
    {
        return _runAsync1<const void*, const void*>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(const void*)> const& callback, ::std::nullptr_t)
    {
        return _runAsync1<const void*, const void*>(callback, nullptr);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(const void*)>&& callback, const void* arg)
    {
        return _runAsync2<const void*, const void*>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(const void*)>&& callback, void* arg)
    {
        return _runAsync2<const void*, const void*>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(const void*)>&& callback, ::std::nullptr_t)
    {
        return _runAsync2<const void*, const void*>(::std::move(callback), nullptr);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(Object const&), Object const& arg)
    {
        return _runAsync0<Object const&, Object>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(Object const&), Object&& arg)
    {
        return _runAsync0<Object const&, Object>(callback, ::std::move(arg));
    }

    AsyncAction ThreadPool::RunAsync(void(*callback)(Object const&), ::std::nullptr_t)
    {
        return _runAsync0<Object const&, Object>(callback, nullptr);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(Object const&)> const& callback, Object const& arg)
    {
        return _runAsync1<Object const&, Object>(callback, arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(Object const&)> const& callback, Object&& arg)
    {
        return _runAsync1<Object const&, Object>(callback, ::std::move(arg));
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(Object const&)> const& callback, ::std::nullptr_t)
    {
        return _runAsync1<Object const&, Object>(callback, nullptr);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(Object const&)>&& callback, Object const& arg)
    {
        return _runAsync2<Object const&, Object>(::std::move(callback), arg);
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(Object const&)>&& callback, Object&& arg)
    {
        return _runAsync2<Object const&, Object>(::std::move(callback), ::std::move(arg));
    }

    AsyncAction ThreadPool::RunAsync(::std::function<void(Object const&)>&& callback, ::std::nullptr_t)
    {
        return _runAsync2<Object const&, Object>(::std::move(callback), nullptr);
    }

    template <class TFArg, class TValue>
    AsyncAction ThreadPool::_runAsync0(void(*callback)(TFArg), TValue value)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#ifdef KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(ThreadPool::_callback2<TFArg, TValue>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
                //この時点で_queueはnullptrでない

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { _callback(_value); h.resume(); });
#elif defined(__POSIX__)
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback2<TFArg, TValue>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#ifdef KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS2<TFArg, TValue> _s;
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
            void(*_callback)(TFArg);
            TValue _value;
#elif defined(__POSIX__)
            ThreadPool::_tmpS2<TFArg, TValue> m_s;
#endif
        };
#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback, ::std::move(value) };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#elif defined(__POSIX__)
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#endif
    }

    template <class TFArg, class TValue>
    AsyncAction ThreadPool::_runAsync1(::std::function<void(TFArg)> const& callback, TValue value)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#ifdef KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(ThreadPool::_callback3<TFArg, TValue>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
                //この時点で_queueはnullptrでない

                auto* fp = &_callback;

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { fp->operator()(_value); h.resume(); });
#elif defined(__POSIX__)
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback3<TFArg, TValue>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#ifdef KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS3<TFArg, TValue> _s;
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
            const ::std::function<void(TFArg)> _callback;
            TValue _value;
#elif defined(__POSIX__)
            ThreadPool::_tmpS3<TFArg, TValue> m_s;
#endif
        };

#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback, ::std::move(value) };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#elif defined(__POSIX__)
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#endif
    }

    template <class TFArg, class TValue>
    AsyncAction ThreadPool::_runAsync2(::std::function<void(TFArg)>&& callback, TValue value)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#ifdef KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(ThreadPool::_callback3<TFArg, TValue>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
                //この時点で_queueはnullptrでない

                auto* fp = &_callback;

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { fp->operator()(_value); h.resume(); });
#elif defined(__POSIX__)
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback3<TFArg, TValue>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#ifdef KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS3<TFArg, TValue> _s;
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
            const ::std::function<void(TFArg)> _callback;
            TValue _value;
#elif defined(__POSIX__)
            ThreadPool::_tmpS3<TFArg, TValue> m_s;
#endif
        };

#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
#elif defined(__POSIX__)
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
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

    template <class TFArg, class TValue>
    void ThreadPool::_callback2(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work)
    {
        _tmpS2<TFArg, TValue>* p = (_tmpS2<TFArg, TValue>*)context;

        p->cb(p->v);
        p->h.resume();
    }

    template <class TFArg, class TValue>
    void ThreadPool::_callback3(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work)
    {
        _tmpS3<TFArg, TValue>* p = (_tmpS3<TFArg, TValue>*)context;

        p->cb(p->v);
        p->h.resume();
    }

#elif defined(__POSIX__)

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

    template <class TFArg, class TValue>
    void ThreadPool::_callback2(void* args)
    {
        auto& s = *static_cast<_tmpS2<TFArg, TValue>*>(args);
        s.cb(s.v);

        s.h.resume();
    }

    template <class TFArg, class TValue>
    void ThreadPool::_callback3(void* args)
    {
        auto& s = *static_cast<_tmpS3<TFArg, TValue>*>(args);
        s.cb(s.v);

        s.h.resume();
    }

#endif
#endif //defined(KONGKONG_ENV_WINDOWS) || defined(KONGKONG_OBJECTIVE_C_ENABLED)

}
