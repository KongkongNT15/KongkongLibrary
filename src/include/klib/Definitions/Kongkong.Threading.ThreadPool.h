#ifndef KONGKONG_THREADING_THREADPOOL_H
#define KONGKONG_THREADING_THREADPOOL_H

#include "Base.h"
#include "Kongkong.Threading.AsyncAction.h"

#include <functional>
#include <coroutine>

#ifdef KONGKONG_ENV_WINDOWS
// なにもしない
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
    #include "Kongkong.AppleDevice.Foundation.Threading.NSOperationQueue.h"
#elif defined(KONGKONG_ENV_UNIX)
    #include "Kongkong.Posix.Threading.ThreadPool.h"
    #include "Kongkong.LazyObject.h"
#else
    #include "Kongkong.LazyObject.h"
    #include "Kongkong.Std.StlThreadPool.h"
#endif

namespace KONGKONG_NAMESPACE::Threading
{
    class ThreadPool final {
        public:

        STATIC_CLASS(ThreadPool)

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, ::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, char) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, signed char) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, unsigned char) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, short) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, unsigned short) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, int) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, unsigned int) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, long) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, unsigned long) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, long long) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, unsigned long long) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, float) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, double) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, long double) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, void*) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, const void*) = delete;

        /// @brief ふぁ！？っく
        static AsyncAction RunAsync(::std::nullptr_t, Object const&) = delete;

        /// @brief 別スレッドで関数を実行
        /// @attention callbackにnullptrを入れないでね！！！
        /// @param callback 実行する関数
        /// @return 非同期オブジェクト
        static AsyncAction RunAsync(void(*callback)(void));
        
        /// @brief 別スレッドで関数を実行
        /// @param callback 実行する関数
        /// @return 非同期オブジェクト
        static AsyncAction RunAsync(::std::function<void(void)> const& callback);

        /// @brief 別スレッドで関数を実行
        /// @param callback 実行する関数
        /// @return 非同期オブジェクト
        static AsyncAction RunAsync(::std::function<void(void)>&& callback);

        template <class TFArg, class TValue>
        static AsyncAction RunAsync(void(*callback)(TFArg), TValue value);

        template <class TFArg, class TValue>
        static AsyncAction RunAsync(::std::function<void(TFArg)> const& callback, TValue value);

        template <class TFArg, class TValue>
        static AsyncAction RunAsync(::std::function<void(TFArg)>&& callback, TValue value);
    
        private:

        

#ifdef KONGKONG_ENV_WINDOWS
        static void _callback0(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work);
        static void _callback1(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work);

        template <class TFArg, class TValue>
        static void _callback2(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work);

        template <class TFArg, class TValue>
        static void _callback3(::PTP_CALLBACK_INSTANCE instance, ::PVOID context, ::PTP_WORK work);

        struct _tmpS0 {
            void(*cb)(void);
            ::std::coroutine_handle<> h;
        };

        struct _tmpS1 {
            ::std::function<void(void)> cb;
            ::std::coroutine_handle<> h;
        };

        template <class TFArg, class TValue>
        struct _tmpS2 {
            void(*cb)(TFArg);
            TValue v;
            ::std::coroutine_handle<> h;
        };

        template <class TFArg, class TValue>
        struct _tmpS3 {
            ::std::function<void(TFArg)> cb;
            TValue v;
            ::std::coroutine_handle<> h;
        };

#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)

        static AppleDevice::Foundation::Threading::NSOperationQueue _queue;

#else

#ifdef KONGKONG_ENV_UNIX
        static LazyObject<Posix::Threading::ThreadPool> s_pool;
#else
        static LazyObject<Std::StlThreadPool> s_pool;
#endif
        static void _callback0(void* args);
        static void _callback1(void* args);

        template <class TFArg, class TValue>
        static void _callback2(void* args);

        template <class TFArg, class TValue>
        static void _callback3(void* args);

        struct _tmpS0 {
            void(*cb)(void);
            ::std::coroutine_handle<> h;
        };

        struct _tmpS1 {
            ::std::function<void(void)> cb;
            ::std::coroutine_handle<> h;
        };

        template <class TFArg, class TValue>
        struct _tmpS2 {
            void(*cb)(TFArg);
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
template <class TFArg, class TValue>
    AsyncAction ThreadPool::RunAsync(void(*callback)(TFArg), TValue value)
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
#else
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
#else
            ThreadPool::_tmpS2<TFArg, TValue> m_s;
#endif
        };
#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback, ::std::move(value) };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#else
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#endif
    }

    template <class TFArg, class TValue>
    AsyncAction ThreadPool::RunAsync(::std::function<void(TFArg)> const& callback, TValue value)
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
#else
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
#else
            ThreadPool::_tmpS3<TFArg, TValue> m_s;
#endif
        };

#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ callback, ::std::move(value) };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#else
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ callback, ::std::move(value) };
#endif
    }

    template <class TFArg, class TValue>
    AsyncAction ThreadPool::RunAsync(::std::function<void(TFArg)>&& callback, TValue value)
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
#else
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
#else
            ThreadPool::_tmpS3<TFArg, TValue> m_s;
#endif
        };

#ifdef KONGKONG_ENV_WINDOWS
        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        if (_queue == nullptr) _queue = AppleDevice::Foundation::Threading::NSOperationQueue();

        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
#else
        if (!s_pool) s_pool.InitializeUnsafe();

        co_await tmpAwaiter{ ::std::move(callback), ::std::move(value) };
#endif
    }

#ifdef KONGKONG_ENV_WINDOWS

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
}

#endif //!KONGKONG_THREADING_THREADPOOL_H
