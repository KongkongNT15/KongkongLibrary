//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CConditionVariable::CConditionVariable()
    {
        auto result = (CThreadStatus)::cnd_init(&_condition);
        if (result != CThreadStatus::Success) [[unlikely]] throw CThreadException(result, u"条件変数の作成に失敗しました");
    }

    CConditionVariable::~CConditionVariable()
    {
        ::cnd_destroy(&_condition);
    }

    void CConditionVariable::BroadCast()
    {
        auto status = BroadCastUnsafe();
        if (status != CThreadStatus::Success) [[unlikely]] throw CThreadException(status, u"スレッドのブロック解除に失敗しました");
    }

    CThreadStatus CConditionVariable::BroadCastUnsafe() noexcept
    {
        return (CThreadStatus)::cnd_broadcast(&_condition);
    }

    void CConditionVariable::Signal()
    {
        auto status = SignalUnsafe();
        if (status != CThreadStatus::Success) [[unlikely]] throw CThreadException(status, u"スレッドのブロック解除に失敗しました");
    }

    CThreadStatus CConditionVariable::SignalUnsafe() noexcept
    {
        return (CThreadStatus)::cnd_signal(&_condition);
    }

    void CConditionVariable::TimedWait(CMutex& mutex, ::timespec const& time)
    {
        auto status = TimedWaitUnsafe(mutex, time);
        if (status != CThreadStatus::Success) throw CThreadException(status, u"待機に失敗しました");
    }

    CThreadStatus CConditionVariable::TimedWaitUnsafe(CMutex& mutex, ::timespec const& time) noexcept
    {
        return (CThreadStatus)::cnd_timedwait(&_condition, &mutex._mutex, &time);
    }

    String CConditionVariable::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::CStd::CConditionVariable");
    }

    void CConditionVariable::Wait(CMutex& mutex)
    {
        auto status = WaitUnsafe(mutex);
        if (status != CThreadStatus::Success) throw CThreadException(status, u"待機に失敗しました");
    }

    void CConditionVariable::Wait(CMutex& mutex, bool(*func)())
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");

        while (!func()) {
            Wait(mutex);
        }
    }

    CThreadStatus CConditionVariable::WaitUnsafe(CMutex& mutex) noexcept
    {
        return (CThreadStatus)::cnd_wait(&_condition, &mutex._mutex);
    }

    CThreadStatus CConditionVariable::WaitUnsafe(CMutex& mutex, bool(*func)()) noexcept
    {
        while (!func()) {
            ::cnd_wait(&_condition, &mutex._mutex);
        }
    }
}
