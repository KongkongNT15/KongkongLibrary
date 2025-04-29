//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    void SyncHAPI::ResetEvent(::HANDLE hEvent)
    {
        if (::ResetEvent(hEvent) == 0) [[unlikely]] throw HResultException();
    }

    bool SyncHAPI::ResetEventUnsafe(::HANDLE hEvent) noexcept
    {
        return (bool)::ResetEvent(hEvent);
    }

    void SyncHAPI::SetEvent(::HANDLE hEvent)
    {
        if (::SetEvent(hEvent) == 0) [[unlikely]] throw HResultException();
    }

    bool SyncHAPI::SetEventUnsafe(::HANDLE hEvent) noexcept
    {
        return (bool)::SetEvent(hEvent);
    }

    WaitStatus SyncHAPI::WaitForSingleObject(HANDLE hObject)
    {
        return WaitForSingleObject(hObject, INFINITE);
    }

    WaitStatus SyncHAPI::WaitForSingleObject(HANDLE hObject, uint32_t milliseconds)
    {
        WaitStatus status = (WaitStatus)::WaitForSingleObject(hObject, milliseconds);

        if (status == WaitStatus::Failed) [[unlikely]] throw HResultException();

        return status;
    }

    WaitStatus SyncHAPI::WaitForSingleObjectUnsafe(HANDLE hObject) noexcept
    {
        return (WaitStatus)::WaitForSingleObject(hObject, INFINITE);
    }

    WaitStatus SyncHAPI::WaitForSingleObjectUnsafe(HANDLE hObject, uint32_t milliseconds) noexcept
    {
        return (WaitStatus)::WaitForSingleObject(hObject, milliseconds);
    }

    WaitObjectInfo SyncHAPI::WaitForSingleThread(HANDLE hObject)
    {
        return WaitForSingleThread(hObject, INFINITE);
    }

    WaitObjectInfo SyncHAPI::WaitForSingleThread(HANDLE hObject, uint32_t milliseconds)
    {
        uint32_t waitStatus = ::WaitForSingleObject(hObject, milliseconds);

        if (waitStatus == WAIT_FAILED) throw HResultException();

        if (waitStatus != WAIT_TIMEOUT) return WaitObjectInfo(ProcessThreadAPI::GetExitCodeThread(hObject), (WaitStatus)waitStatus);
        
        return WaitObjectInfo(STILL_ACTIVE, WaitStatus::Timeout);
    }
}
