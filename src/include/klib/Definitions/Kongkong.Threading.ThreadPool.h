#ifndef KONGKONG_THREADING_THREADPOOL_H
#define KONGKONG_THREADING_THREADPOOL_H

#include "Base.h"

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

        static AsyncAction RunAsync(void(*callback)(char), char arg);
        static AsyncAction RunAsync(::std::function<void(char)> const& callback, char arg);
        static AsyncAction RunAsync(::std::function<void(char)>&& callback, char arg);

        static AsyncAction RunAsync(void(*callback)(signed char), signed char arg);
        static AsyncAction RunAsync(::std::function<void(signed char)> const& callback, signed char arg);
        static AsyncAction RunAsync(::std::function<void(signed char)>&& callback, signed char arg);

        static AsyncAction RunAsync(void(*callback)(unsigned char), unsigned char arg);
        static AsyncAction RunAsync(::std::function<void(unsigned char)> const& callback, unsigned char arg);
        static AsyncAction RunAsync(::std::function<void(unsigned char)>&& callback, unsigned char arg);

        static AsyncAction RunAsync(void(*callback)(short), short arg);
        static AsyncAction RunAsync(::std::function<void(short)> const& callback, short arg);
        static AsyncAction RunAsync(::std::function<void(short)>&& callback, short arg);

        static AsyncAction RunAsync(void(*callback)(unsigned short), unsigned short arg);
        static AsyncAction RunAsync(::std::function<void(unsigned short)> const& callback, unsigned short arg);
        static AsyncAction RunAsync(::std::function<void(unsigned short)>&& callback, unsigned short arg);

        static AsyncAction RunAsync(void(*callback)(int), int arg);
        static AsyncAction RunAsync(::std::function<void(int)> const& callback, int arg);
        static AsyncAction RunAsync(::std::function<void(int)>&& callback, int arg);

        static AsyncAction RunAsync(void(*callback)(unsigned int), unsigned int arg);
        static AsyncAction RunAsync(::std::function<void(unsigned int)> const& callback, unsigned int arg);
        static AsyncAction RunAsync(::std::function<void(unsigned int)>&& callback, unsigned int arg);

        static AsyncAction RunAsync(void(*callback)(long), long arg);
        static AsyncAction RunAsync(::std::function<void(long)> const& callback, long arg);
        static AsyncAction RunAsync(::std::function<void(long)>&& callback, long arg);

        static AsyncAction RunAsync(void(*callback)(unsigned long), unsigned long arg);
        static AsyncAction RunAsync(::std::function<void(unsigned long)> const& callback, unsigned long arg);
        static AsyncAction RunAsync(::std::function<void(unsigned long)>&& callback, unsigned long arg);

        static AsyncAction RunAsync(void(*callback)(long long), long long arg);
        static AsyncAction RunAsync(::std::function<void(long long)> const& callback, long long arg);
        static AsyncAction RunAsync(::std::function<void(long long)>&& callback, long long arg);

        static AsyncAction RunAsync(void(*callback)(unsigned long long), unsigned long long arg);
        static AsyncAction RunAsync(::std::function<void(unsigned long long)> const& callback, unsigned long long arg);
        static AsyncAction RunAsync(::std::function<void(unsigned long long)>&& callback, unsigned long long arg);

        static AsyncAction RunAsync(void(*callback)(float), float arg);
        static AsyncAction RunAsync(::std::function<void(float)> const& callback, float arg);
        static AsyncAction RunAsync(::std::function<void(float)>&& callback, float arg);

        static AsyncAction RunAsync(void(*callback)(double), double arg);
        static AsyncAction RunAsync(::std::function<void(double)> const& callback, double arg);
        static AsyncAction RunAsync(::std::function<void(double)>&& callback, double arg);

        static AsyncAction RunAsync(void(*callback)(long double), long double arg);
        static AsyncAction RunAsync(::std::function<void(long double)> const& callback, long double arg);
        static AsyncAction RunAsync(::std::function<void(long double)>&& callback, long double arg);

        static AsyncAction RunAsync(void(*callback)(void*), void* arg);
        static AsyncAction RunAsync(void(*callback)(void*), ::std::nullptr_t);
        static AsyncAction RunAsync(::std::function<void(void*)> const& callback, void* arg);
        static AsyncAction RunAsync(::std::function<void(void*)> const& callback, ::std::nullptr_t);
        static AsyncAction RunAsync(::std::function<void(void*)>&& callback, void* arg);
        static AsyncAction RunAsync(::std::function<void(void*)>&& callback, ::std::nullptr_t);

        static AsyncAction RunAsync(void(*callback)(const void*), const void* arg);
        static AsyncAction RunAsync(void(*callback)(const void*), void* arg);
        static AsyncAction RunAsync(void(*callback)(const void*), ::std::nullptr_t);
        static AsyncAction RunAsync(::std::function<void(const void*)> const& callback, const void* arg);
        static AsyncAction RunAsync(::std::function<void(const void*)> const& callback, void* arg);
        static AsyncAction RunAsync(::std::function<void(const void*)> const& callback, ::std::nullptr_t);
        static AsyncAction RunAsync(::std::function<void(const void*)>&& callback, const void* arg);
        static AsyncAction RunAsync(::std::function<void(const void*)>&& callback, void* arg);
        static AsyncAction RunAsync(::std::function<void(const void*)>&& callback, ::std::nullptr_t);

        static AsyncAction RunAsync(void(*callback)(Object const&), Object const& arg);
        static AsyncAction RunAsync(void(*callback)(Object const&), Object&& arg);
        static AsyncAction RunAsync(void(*callback)(Object const&), ::std::nullptr_t);
        static AsyncAction RunAsync(::std::function<void(Object const&)> const& callback, Object const& arg);
        static AsyncAction RunAsync(::std::function<void(Object const&)> const& callback, Object&& arg);
        static AsyncAction RunAsync(::std::function<void(Object const&)> const& callback, ::std::nullptr_t);
        static AsyncAction RunAsync(::std::function<void(Object const&)>&& callback, Object const& arg);
        static AsyncAction RunAsync(::std::function<void(Object const&)>&& callback, Object&& arg);
        static AsyncAction RunAsync(::std::function<void(Object const&)>&& callback, ::std::nullptr_t);
    
        private:

        template <class TFArg, class TValue>
        static AsyncAction _runAsync0(void(*callback)(TFArg), TValue value);

        template <class TFArg, class TValue>
        static AsyncAction _runAsync1(::std::function<void(TFArg)> const& callback, TValue value);

        template <class TFArg, class TValue>
        static AsyncAction _runAsync2(::std::function<void(TFArg)>&& callback, TValue value);

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

#endif //!KONGKONG_THREADING_THREADPOOL_H
