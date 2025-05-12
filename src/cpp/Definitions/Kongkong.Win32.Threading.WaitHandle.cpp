//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    WaitStatus WaitHandle::Wait() const
    {
        return Primitives::SyncHAPI::WaitForSingleObject(_h.__rawHandle());
    }

    WaitStatus WaitHandle::Wait(uint32_t milliSeconds) const
    {
        return Primitives::SyncHAPI::WaitForSingleObject(_h.__rawHandle(), milliSeconds);
    }

    WaitStatus WaitHandle::WaitUnsafe() const noexcept
    {
        return Primitives::SyncHAPI::WaitForSingleObjectUnsafe(_h.__rawHandle());
    }

    WaitStatus WaitHandle::WaitUnsafe(uint32_t milliSeconds) const noexcept
    {
        return Primitives::SyncHAPI::WaitForSingleObjectUnsafe(_h.__rawHandle(), milliSeconds);
    }
}

CREATE_CLASS_TYPE(Threading::WaitHandle, WaitHandle)
