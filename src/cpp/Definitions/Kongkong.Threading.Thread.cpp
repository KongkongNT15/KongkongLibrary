//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{
    Thread Thread::Current() noexcept
    {
#ifdef KONGKONG_ENV_WINDOWS
        return Win32::Threading::Thread::Current();
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        return AppleDevice::Foundation::Threading::NSThread::CurrentThread();
#elif defined(KONGKONG_ENV_UNIX)
        return Posix::Threading::Thread::Current();
#else
        static_assert(false, "つくろうね？？？");
#endif
    }

    void Thread::Sleep(uint32_t milliseconds) noexcept
    {
#ifdef KONGKONG_ENV_WINDOWS
        Win32::Threading::Thread::Sleep(milliseconds);
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        AppleDevice::Foundation::Threading::NSThread::SleepForTimeInterval(milliseconds / 1000.0);
#elif defined(KONGKONG_ENV_UNIX)
        uint64_t microSeconds = milliseconds * 1000L;
        
        if (microSeconds > ::std::numeric_limits<unsigned>::max()) [[unlikely]] {
            uint64_t max = microSeconds / ::std::numeric_limits<unsigned>::max();
            unsigned nokori = (unsigned)(microSeconds % ::std::numeric_limits<unsigned>::max());

            for (uint64_t n = 0; n != max; n++) Posix::Threading::Thread::SleepForMicroseconds(::std::numeric_limits<unsigned>::max());
            Posix::Threading::Thread::SleepForMicroseconds(nokori);
        }
        else {
            Posix::Threading::Thread::SleepForMicroseconds((unsigned)microSeconds);
        }
#else
        ::std::this_thread::sleep_for(::std::chrono::milliseconds(milliseconds));
#endif
    }

    Thread::Thread(EntryPoint entryPoint, void* args) : Thread(new _args<EntryPoint>{ entryPoint, args })
    {
    }

    Thread::Thread(EntryPoint entryPoint, void* args, size_t stackSize) : Thread(new _args<EntryPoint>{ entryPoint, args }, stackSize)
    {
    }

    Thread::Thread(::std::function<void(void*)> const& entryPoint, void* args) : Thread(new _args<::std::function<void(void*)>>{ entryPoint, args })
    {
    }

    Thread::Thread(::std::function<void(void*)> const& entryPoint, void* args, size_t stackSize) : Thread(new _args<::std::function<void(void*)>>{ entryPoint, args }, stackSize)
    {
    }

    Thread::Thread(::std::function<void(void*)>&& entryPoint, void* args) : Thread(new _args<::std::function<void(void*)>>{ ::std::move(entryPoint), args })
    {
    }

    Thread::Thread(::std::function<void(void*)>&& entryPoint, void* args, size_t stackSize) : Thread(new _args<::std::function<void(void*)>>{ ::std::move(entryPoint), args }, stackSize)
    {
    }

    void Thread::Join()
    {
        if (!_isStarted) [[unlikely]] throw ThreadStateException(u"開始していないスレッドを待機しようとしました");
#ifdef KONGKONG_ENV_WINDOWS
        
        _thread.WaitUnsafe();

#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        while (!_thread.GetIsCancelledUnsafe() && !_thread.GetIsFinishedUnsafe()) {
            ::usleep(1000);
        }
#elif defined(KONGKONG_ENV_UNIX)
        _thread.JoinUnsafe();
#else
        _thread.join();
#endif
    }

    void Thread::Start()
    {
        if (_isStarted) [[unlikely]] throw ThreadStateException(u"スレッドは既に開始されています");
#ifdef KONGKONG_ENV_WINDOWS
        
        _thread.ResumeUnsafe();
        
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        _thread.StartUnsafe();
#elif defined(KONGKONG_ENV_UNIX)
        if (_stackSize == _invalidStackSize) {
            _thread = Posix::Threading::Thread(_func, _fArgs);
        }
        else {
            Posix::Threading::ThreadAttribute attribute;
            attribute.SetStackSizeUnsafe(_stackSize);
            _thread = Posix::Threading::Thread(_func, _fArgs, attribute);
        }
        
#else
        static_assert(false, "つくろうね？");
#endif
        _isStarted = true;
    }

    String Thread::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Threading::Thread");
    }

#ifdef KONGKONG_ENV_WINDOWS
    template <class TFunc>
    DWORD Thread::_entryPoint(void* args)
    {
        auto p = (_args<TFunc>*)args;
        
        p->func(p->args);

        delete p;

        return 0;
    }
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
    template <class TFunc>
    void Thread::_entryPoint(void* args)
    {
        auto p = (_args<TFunc>*)args;
            
        p->func(p->args);

        delete p;
    }
#elif defined(KONGKONG_ENV_UNIX)
    template <class TFunc>
    void* Thread::_entryPoint(void* args)
    {
        auto p = (_args<TFunc>*)args;
            
        p->func(p->args);

        delete p;

        return nullptr;
    }
#else
    template <class TFunc>
    void Thread::_entryPoint(void* args)
    {
        auto p = (_args<TFunc>*)args;
            
        p->func(p->args);

        delete p;
    }
#endif

    template <class TFunc>
    Thread::Thread(_args<TFunc>* args) :
        _isStarted(false),
#ifdef KONGKONG_ENV_WINDOWS
        _thread(_entryPoint<TFunc>, args, Win32::Threading::ThreadStart::Suspended)
        
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        _thread(_entryPoint<TFunc>, args)
#elif defined(KONGKONG_ENV_UNIX)
        _thread(nullptr),
        _func(_entryPoint<TFunc>),
        _fArgs(args),
        _stackSize(_invalidStackSize)
#else
        static_assert(false, "つくろうね？？？");
#endif
    {
    }

    template <class TFunc>
    Thread::Thread(_args<TFunc>* args, size_t stackSize) :
        _isStarted(false),
#ifdef KONGKONG_ENV_WINDOWS
        _thread(_entryPoint<TFunc>, args, stackSize, Win32::Threading::ThreadStart::Suspended)
#elif defined(KONGKONG_OBJECTIVE_C_ENABLED)
        _thread(_entryPoint<TFunc>, args)
#elif defined(KONGKONG_ENV_UNIX)
        _thread(nullptr),
        _func(_entryPoint<TFunc>),
        _fArgs(args),
        _stackSize(stackSize)
#else
        static_assert(false, "つくろうね？？？");
#endif
    {
#ifdef KONGKONG_OBJECTIVE_C_ENABLED
        _thread.SetStackSizeUnsafe(stackSize);
#endif
    }
}
