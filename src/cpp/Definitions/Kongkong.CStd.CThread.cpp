//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CThread CThread::Current() noexcept
    {
        return ::thrd_current();
    }

    void CThread::Exit(int returnCode) noexcept
    {
        ::thrd_exit(returnCode);
    }

    CThreadSleepResult CThread::Sleep(::timespec const& timePoint) noexcept
    {
        return _sleep(timePoint, nullptr);
    }

    CThreadSleepResult CThread::Sleep(::timespec const& timePoint, ::timespec& remaining) noexcept
    {
        return _sleep(timePoint, &remaining);
    }

    CThreadSleepResult CThread::SleepForMicroSeconds(::time_t microSeconds) noexcept
    {
        constexpr ::time_t nMicro = 1000000;

        timespec t;
        t.tv_sec = microSeconds / nMicro;
        t.tv_nsec = (long)((microSeconds % nMicro) * 1000);

        return Sleep(t);
    }

    CThreadSleepResult CThread::SleepForMilliSeconds(::time_t milliSeconds) noexcept
    {
        constexpr ::time_t nMilli = 1000;

        timespec t;
        t.tv_sec = milliSeconds / nMilli;
        t.tv_nsec = (long)((milliSeconds % nMilli) * 1000000);

        return Sleep(t);
    }

    CThreadSleepResult CThread::SleepForNanoSeconds(::time_t nanoSeconds) noexcept
    {
        constexpr ::time_t nNano = 1000000000;

        timespec t;
        t.tv_sec = nanoSeconds / nNano;
        t.tv_nsec = (long)(nanoSeconds % nNano);

        return Sleep(t);
    }

    CThreadSleepResult CThread::SleepForSeconds(::time_t seconds) noexcept
    {
        timespec t;
        t.tv_sec = seconds;
        t.tv_nsec = 0;

        return Sleep(t);
    }

    CThread::CThread(::thrd_start_t func) : CThread(func, nullptr)
    {
    }

    CThread::CThread(::thrd_start_t func, void* args) : _thread()
    {
        CThreadStatus status = (CThreadStatus)::thrd_create(&_thread, func, args);

        if (status != CThreadStatus::Success) [[unlikely]] throw CThreadException(status, u"スレッドの作成に失敗しました");
    }

    void CThread::Detach()
    {
        CThreadStatus status = (CThreadStatus)::thrd_detach(_thread);

        if (status != CThreadStatus::Success) [[unlikely]] throw CThreadException(status, u"スレッドのデタッチに失敗しました");
    }

    bool CThread::DetachUnsafe() noexcept
    {
        return ::thrd_detach(_thread) == ::thrd_success;
    }

    CThreadResult CThread::Join() noexcept
    {
        CThreadResult result;

        result._status = (CThreadStatus)::thrd_join(_thread, &result._returnCode);

        return result;
    }

    String CThread::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Standard::CThread");
    }

    CThreadSleepResult CThread::_sleep(::timespec const& timePoint, ::timespec* p) noexcept
    {
        switch (::thrd_sleep(&timePoint, p)) {
            case 0: return CThreadSleepResult::Success;
            case -1: return CThreadSleepResult::Interrupted;

            default: [[unlikely]] return CThreadSleepResult::Fail;
        }
    }

    bool operator==(CThread const& left, CThread const& right) noexcept
    {
        return (bool)::thrd_equal(left._thread, right._thread);
    }

    bool operator!=(CThread const& left, CThread const& right) noexcept
    {
        return !(left == right);
    }
}
