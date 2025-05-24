#ifndef KONGKONG_THREADING_THREADPOOL_H
#define KONGKONG_THREADING_THREADPOOL_H

#include "Base.h"
#include "Kongkong.Threading.AsyncAction.h"

#include <functional>
#include <coroutine>

#if KONGKONG_ENV_WINDOWS
// なにもしない
#elif KONGKONG_OBJECTIVE_C_ENABLED
    #include "Kongkong.AppleDevice.Foundation.Threading.NSOperationQueue.h"
#elif KONGKONG_ENV_UNIX
    #include "Kongkong.Posix.Threading.ThreadPool.h"
    #include "Kongkong.LazyObject.h"
#else
    #include "Kongkong.LazyObject.h"
    #include "Kongkong.Std.StlThreadPool.h"
#endif

namespace KONGKONG_NAMESPACE::Threading
{
    template <class T>
    concept HasCallOperator = requires(T t) {
        { &T::operator() };
    };

    class ThreadPool final {
        private:

        template <class T>
        static constexpr bool IsFunctionPointerV = (::std::is_pointer_v<T> && ::std::is_function_v<std::remove_pointer_t<T>>) || ::std::is_function_v<T>;

        public:

        STATIC_CLASS(ThreadPool)

        /// @brief ふぁ！？っく
        static void ParallelFor(ssize_t, ssize_t, ::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void ParallelFor(uint32_t, ssize_t, ssize_t, ::std::nullptr_t) = delete;

        static void ParallelFor(ssize_t begin, ssize_t end, void(*f)(ssize_t));
        static void ParallelFor(ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f);
        static void ParallelFor(uint32_t threadCount, ssize_t begin, ssize_t end, void(*f)(ssize_t));
        static void ParallelFor(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f);

        /// @brief 別スレッドで関数を実行
        /// @attention callbackにnullptrを入れないでね！！！
        /// @param callback 実行する関数
        /// @return 非同期オブジェクト
        template <class TFunc>
        static AsyncAction RunAsync(TFunc const& func)
        {
            if constexpr (IsFunctionPointerV<TFunc>) {
                if constexpr (::std::is_function_v<TFunc>) {
                    TFunc* p = func;
                    return s_runAsyncfp(p);
                }
                else {
                    return s_runAsyncfp(func);
                }
            }
            else if constexpr (HasCallOperator<TFunc>) {
                return s_runAsyncfol(func);
            }
            else {
                static_assert(false, "指定された型は呼び出しができません");
            }
        }

        template <class TFunc>
        static AsyncAction RunAsync(TFunc&& func)
        {
            if constexpr (IsFunctionPointerV<TFunc>) {
                if constexpr (::std::is_function_v<TFunc>) {
                    TFunc* p = func;
                    return s_runAsyncfp(p);
                }
                else {
                    return s_runAsyncfp(func);
                }
            }
            else if constexpr (HasCallOperator<TFunc>) {
                return s_runAsyncfor(::std::move(func));
            }
            else {
                static_assert(false, "指定された型は呼び出しができません");
            }
        }

        template <class TFunc, class TValue>
        static AsyncAction RunAsync(TFunc const& func, TValue value)
        {
            if constexpr (IsFunctionPointerV<TFunc>) {
                if constexpr (::std::is_function_v<TFunc>) {
                    TFunc* p = func;
                    return s_runAsync0(p, ::std::move(value));
                }
                else {
                    return s_runAsync0(func, ::std::move(value));
                }
            }
            else if constexpr (HasCallOperator<TFunc>) {
                return s_runAsync1(func, ::std::move(value));
            }
            else {
                static_assert(false, "指定された型は呼び出しができません");
            }
        }

        template <class TFunc, class TValue>
        static AsyncAction RunAsync(TFunc&& func, TValue value)
        {
            if constexpr (IsFunctionPointerV<TFunc>) {
                if constexpr (::std::is_function_v<TFunc>) {
                    TFunc* p = func;
                    return s_runAsync0(p, ::std::move(value));
                }
                else {
                    return s_runAsync0(func, ::std::move(value));
                }
            }
            else if constexpr (HasCallOperator<TFunc>) {
                return s_runAsync2(::std::move(func), ::std::move(value));
            }
            else {
                static_assert(false, "指定された型は呼び出しができません");
            }
        }
    
        private:

        template <class TFunc>
        static void s_parallelFor(uint32_t threadCount, ssize_t begin, ssize_t end, TFunc f);

        template <class TResult>
        static AsyncAction s_runAsyncfp(TResult(*callback)(void));

        template <class TFunc>
        static AsyncAction s_runAsyncfol(TFunc const& callback);

        template <class TFunc>
        static AsyncAction s_runAsyncfor(TFunc&& callback);

        template <class TResult, class TFArg, class TValue>
        static AsyncAction s_runAsync0(TResult(*callback)(TFArg), TValue value);

        template <class TFunc, class TValue>
        static AsyncAction s_runAsync1(TFunc const& callback, TValue value);

        template <class TFunc, class TValue>
        static AsyncAction s_runAsync2(TFunc&& callback, TValue value);

#if KONGKONG_ENV_WINDOWS
        template <class TResult>
        static void _callback0(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work);

        template <class TFunc>
        static void _callback1(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work);

        template <class TResult, class TFArg, class TValue>
        static void _callback2(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work);

        template <class TFunc, class TValue>
        static void _callback3(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work);

        template <class TResult>
        struct _tmpS0 {
            TResult(*cb)(void);
            ::std::coroutine_handle<> h;
        };

        template <class TFunc>
        struct _tmpS1 {
            TFunc cb;
            ::std::coroutine_handle<> h;
        };

        template <class TResult, class TFArg, class TValue>
        struct _tmpS2 {
            TResult(*cb)(TFArg);
            TValue v;
            ::std::coroutine_handle<> h;
        };

        template <class TFunc, class TValue>
        struct _tmpS3 {
            TFunc cb;
            TValue v;
            ::std::coroutine_handle<> h;
        };

#elif KONGKONG_OBJECTIVE_C_ENABLED

        static AppleDevice::Foundation::Threading::NSOperationQueue _queue;

#else

    #if KONGKONG_ENV_UNIX
        static LazyObject<Posix::Threading::ThreadPool> s_pool;
    #else
        static LazyObject<Std::StlThreadPool> s_pool;
    #endif
        template <class TResult>
        static void _callback0(void* args);

        template <class TFunc>
        static void _callback1(void* args);

        template <class TFArg, class TValue>
        static void _callback2(void* args);

        template <class TFArg, class TValue>
        static void _callback3(void* args);

        template <class TResult>
        struct _tmpS0 {
            TResult(*cb)(void);
            ::std::coroutine_handle<> h;
        };

        template <class TFunc>
        struct _tmpS1 {
            TFunc cb;
            ::std::coroutine_handle<> h;
        };

        template <class TResult, class TFArg, class TValue>
        struct _tmpS2 {
            TResult(*cb)(TFArg);
            TValue v;
            ::std::coroutine_handle<> h;
        };

        template <class TFArg, class TValue>
        struct _tmpS3 {
            ::std::function<void(TFArg)> cb;
            TValue v;
            ::std::coroutine_handle<> h;
        };

#endif
    };
}

namespace KONGKONG_NAMESPACE::Threading
{
#if KONGKONG_ENV_WINDOWS
    template <class TResult>
    void ThreadPool::_callback0(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work)
    {
        _tmpS0<TResult>* p = (_tmpS0<TResult>*)context;

        p->cb();
        p->h.resume();
    }

    template <class TFunc>
    void ThreadPool::_callback1(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work)
    {
        _tmpS1<TFunc>* p = (_tmpS1<TFunc>*)context;

        p->cb();
        p->h.resume();
    }

    template <class TResult, class TFArg, class TValue>
    void ThreadPool::_callback2(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work)
    {
        _tmpS2<TResult, TFArg, TValue>* p = (_tmpS2<TResult, TFArg, TValue>*)context;

        p->cb(p->v);
        p->h.resume();
    }

    template <class TFunc, class TValue>
    void ThreadPool::_callback3(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work)
    {
        _tmpS3<TFunc, TValue>* p = (_tmpS3<TFunc, TValue>*)context;

        p->cb(p->v);
        p->h.resume();
    }
#elif !KONGKONG_OBJECTIVE_C_ENABLED
    template <class TResult>
    void ThreadPool::_callback0(void* args)
    {
        _tmpS0<TResult>& s = *static_cast<_tmpS0<TResult>*>(args);

        s.cb();

        s.h.resume();
    }

    template <class TFunc>
    void ThreadPool::_callback1(void* args)
    {
        _tmpS1<TFunc>& s = *static_cast<_tmpS1<TFunc>*>(args);

        s.cb();

        s.h.resume();
    }

    template <class TResult, class TFArg, class TValue>
    void ThreadPool::_callback2(void* args)
    {
        auto& s = *static_cast<_tmpS2<TResult, TFArg, TValue>*>(args);
        s.cb(s.v);

        s.h.resume();
    }

    template <class TFunc, class TValue>
    void ThreadPool::_callback3(void* args)
    {
        auto& s = *static_cast<_tmpS3<TFunc, TValue>*>(args);
        s.cb(s.v);

        s.h.resume();
    }
#endif
    template <class TResult>
    AsyncAction ThreadPool::s_runAsyncfp(TResult(*callback)(void))
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#if KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(_callback0<TResult>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif KONGKONG_OBJECTIVE_C_ENABLED
                //この時点で_queueはnullptrでない

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { _callback(); h.resume(); });
#else
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback0<TResult>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#if KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS0<TResult> _s;
#elif KONGKONG_OBJECTIVE_C_ENABLED
            TResult(*_callback)(void);
#else
            ThreadPool::_tmpS0<TResult> m_s;
#endif
        };
#if KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback };
#elif KONGKONG_OBJECTIVE_C_ENABLED
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback };
#else

        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback };
#endif
    }

    template <class TFunc>
    AsyncAction ThreadPool::s_runAsyncfol(TFunc const& callback)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#if KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(_callback1<TFunc>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif KONGKONG_OBJECTIVE_C_ENABLED
                //この時点で_queueはnullptrでない

                auto* fp = &_callback;

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { fp->operator()(); h.resume(); });
#else
                //この時点で_poolはnullptrでない
                m_s.h = h;

                s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback1<TFunc>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#if KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS1<TFunc> _s;
#elif KONGKONG_OBJECTIVE_C_ENABLED
            TFunc _callback;
#else
            ThreadPool::_tmpS1<TFunc> m_s;
#endif
        };
#if KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback };
#elif KONGKONG_OBJECTIVE_C_ENABLED
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback };
#else

        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback };
#endif
    }
    template <class TFunc>
    AsyncAction ThreadPool::s_runAsyncfor(TFunc&& callback)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#if KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(_callback1<TFunc>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif KONGKONG_OBJECTIVE_C_ENABLED
                //この時点で_queueはnullptrでない

                auto* fp = &_callback;

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { fp->operator()(); h.resume(); });
#else
                //この時点で_poolはnullptrでない
                m_s.h = h;

                s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback1<TFunc>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#if KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS1<TFunc> _s;
#elif KONGKONG_OBJECTIVE_C_ENABLED
            TFunc _callback;
#else
            ThreadPool::_tmpS1<TFunc> m_s;
#endif
        };

#if KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ ::std::move(callback) };
#elif KONGKONG_OBJECTIVE_C_ENABLED
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ ::std::move(callback) };
#else

        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ ::std::move(callback) };
#endif
    }

    template <class TResult, class TFArg, class TValue>
    AsyncAction ThreadPool::s_runAsync0(TResult(*callback)(TFArg), TValue value)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#if KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(ThreadPool::_callback2<TResult, TFArg, TValue>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif KONGKONG_OBJECTIVE_C_ENABLED
                //この時点で_queueはnullptrでない

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { _callback(_value); h.resume(); });
#else
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback2<TResult, TFArg, TValue>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#if KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS2<TResult, TFArg, TValue> _s;
#elif KONGKONG_OBJECTIVE_C_ENABLED
            void(*_callback)(TFArg);
            TValue _value;
#else
            ThreadPool::_tmpS2<TResult, TFArg, TValue> m_s;
#endif
        };
#if KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback, ::std::move(value) };
#elif KONGKONG_OBJECTIVE_C_ENABLED
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#else
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#endif
    }

    template <class TFunc, class TValue>
    AsyncAction ThreadPool::s_runAsync1(TFunc const& callback, TValue value)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#if KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(ThreadPool::_callback3<TFunc, TValue>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif KONGKONG_OBJECTIVE_C_ENABLED
                //この時点で_queueはnullptrでない

                auto* fp = &_callback;

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { fp->operator()(_value); h.resume(); });
#else
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback3<TFunc, TValue>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#if KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS3<TFunc, TValue> _s;
#elif KONGKONG_OBJECTIVE_C_ENABLED
            TFunc _callback;
            TValue _value;
#else
            ThreadPool::_tmpS3<TFunc, TValue> m_s;
#endif
        };

#if KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback, ::std::move(value) };
#elif KONGKONG_OBJECTIVE_C_ENABLED
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#else
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#endif
    }

    template <class TFunc, class TValue>
    AsyncAction ThreadPool::s_runAsync2(TFunc&& callback, TValue value)
    {
        struct tmpAwaiter {
            constexpr bool await_ready() noexcept { return false; } // すぐには完了しない
            void await_suspend(::std::coroutine_handle<> h) {
#if KONGKONG_ENV_WINDOWS
                _s.h = h;
                ::PTP_WORK work = ::CreateThreadpoolWork(ThreadPool::_callback3<TFunc, TValue>, &_s, nullptr);

                ::SubmitThreadpoolWork(work);

                ::CloseThreadpoolWork(work);
#elif KONGKONG_OBJECTIVE_C_ENABLED
                //この時点で_queueはnullptrでない

                auto* fp = &_callback;

                ThreadPool::_queue.AddOperationWithBlockUnsafe(^() { fp->operator()(_value); h.resume(); });
#else
                //この時点で_poolはnullptrでない

                m_s.h = h;

                ThreadPool::s_pool.GetValueUnsafe().AppendTask(ThreadPool::_callback3<TFunc, TValue>, &m_s);
#endif
            }
            constexpr void await_resume() noexcept {}
#if KONGKONG_ENV_WINDOWS
            ThreadPool::_tmpS3<TFunc, TValue> _s;
#elif KONGKONG_OBJECTIVE_C_ENABLED
            TFunc _callback;
            TValue _value;
#else
            ThreadPool::_tmpS3<TFunc, TValue> m_s;
#endif
        };

#if KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
#elif KONGKONG_OBJECTIVE_C_ENABLED
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
#else
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
#endif
    }
}

#endif //!KONGKONG_THREADING_THREADPOOL_H
