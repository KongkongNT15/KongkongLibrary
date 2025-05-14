#ifndef KONGKONG_THREADING_THREAD_H
#define KONGKONG_THREADING_THREAD_H

#include "Base.h"
#include "Kongkong.HandleType.h"

#if KONGKONG_ENV_WINDOWS
    #include "Kongkong.Win32.Threading.Thread.h"
#elif KONGKONG_OBJECTIVE_C_ENABLED
    #include "Kongkong.AppleDevice.Foundation.Threading.NSThread.h"
#elif KONGKONG_ENV_UNIX
    #include "Kongkong.Posix.Threading.Thread.h"
#else
    #include <thread>
#endif

#include <functional>

namespace KONGKONG_NAMESPACE::Threading
{
    class Thread final : public HandleType {
        public:

        using EntryPoint = void(*)(void*);

        /// @brief このスレッド
        [[nodiscard]]
        static Thread Current() noexcept;

        static void Sleep(uint32_t milliseconds) noexcept;

        /// @brief ふぁ！？っく
        Thread(::std::nullptr_t, ::std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        Thread(::std::nullptr_t, void*) = delete;

        explicit Thread(EntryPoint entryPoint, void* args);
        explicit Thread(EntryPoint entryPoint, void* args, size_t stackSize);
        explicit Thread(::std::function<void(void*)> const& entryPoint, void* args);
        explicit Thread(::std::function<void(void*)> const& entryPoint, void* args, size_t stackSize);
        explicit Thread(::std::function<void(void*)>&& entryPoint, void* args);
        explicit Thread(::std::function<void(void*)>&& entryPoint, void* args, size_t stackSize);
        Thread(Thread const&) = delete;
        Thread(Thread&&) = default;

        Thread& operator=(Thread const&) = delete;
        Thread& operator=(Thread&&) = default;

        void Join();

        void Start();

        [[nodiscard]]
        String ToString() const;

        private:
        bool _isStarted;
#if KONGKONG_ENV_WINDOWS
        Win32::Threading::Thread _thread;

        constexpr Thread(Win32::Threading::Thread&& thread) noexcept : _thread(::std::move(thread)), _isStarted(true) {}
#elif KONGKONG_OBJECTIVE_C_ENABLED

        AppleDevice::Foundation::Threading::NSThread _thread;
        constexpr Thread(AppleDevice::Foundation::Threading::NSThread&& thread) noexcept : _thread(::std::move(thread)), _isStarted(true) {}
#elif KONGKONG_ENV_UNIX
        Posix::Threading::Thread _thread;
        Posix::Threading::Thread::EntryPoint _func;
        void* _fArgs;
        size_t _stackSize;

        static constexpr size_t _invalidStackSize = (size_t)-1;
        constexpr Thread(Posix::Threading::Thread&& thread) noexcept : _thread(::std::move(thread)), _isStarted(true), _func(nullptr), _fArgs(nullptr), _stackSize(_invalidStackSize) {}
#else
        ::std::thread _thread;
#endif

        template <class TFunc>
        struct _args {    
            TFunc func;
            void* args;
        };

#if KONGKONG_ENV_WINDOWS
        template <class TFunc>
        static DWORD WINAPI _entryPoint(void* args);
#elif KONGKONG_OBJECTIVE_C_ENABLED
        template <class TFunc>
        static void _entryPoint(void* args);
#elif KONGKONG_ENV_UNIX
        template <class TFunc>
        static void* _entryPoint(void* args);
#else
        template <class TFunc>
        static void _entryPoint(void* args);
#endif
        template <class TFunc>
        Thread(_args<TFunc>* args);

        template <class TFunc>
        Thread(_args<TFunc>* args, size_t stackSize);
    };
}

#endif //!KONGKONG_THREADING_THREAD_H
