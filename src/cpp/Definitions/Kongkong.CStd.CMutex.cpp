//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    CMutex::CMutex() : CMutex(CMutexKind::Plain)
    {
    }

    CMutex::CMutex(CMutexKind kind) : _mutex()
    {
        CThreadStatus result = (CThreadStatus)::mtx_init(&_mutex, (int)kind);

        if (result != CThreadStatus::Success) [[unlikely]] throw CThreadException(result, u"ミューテックスオブジェクトの作成に失敗しました");
    }

    CMutex::~CMutex()
    {
        ::mtx_destroy(&_mutex);
    }

    void CMutex::Lock()
    {
        CThreadStatus result = (CThreadStatus)::mtx_lock(&_mutex);

        if (result != CThreadStatus::Success) [[unlikely]] throw CThreadException(result, u"ミューテックスのロックに失敗しました");
    }

    bool CMutex::LockUnsafe() noexcept
    {
        return ::mtx_lock(&_mutex) == ::thrd_success;
    }

    CThreadStatus CMutex::TryLock() noexcept
    {
        return (CThreadStatus)::mtx_trylock(&_mutex);
    }

    String CMutex::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Standard::CMutex");
    }

    void CMutex::Unlock()
    {
        CThreadStatus result = (CThreadStatus)::mtx_unlock(&_mutex);

        if (result != CThreadStatus::Success) [[unlikely]] throw CThreadException(result, u"ミューテックスのアンロックに失敗しました");
    }

    bool CMutex::UnlockUnsafe() noexcept
    {
        return ::mtx_unlock(&_mutex) == ::thrd_success;
    }
}
