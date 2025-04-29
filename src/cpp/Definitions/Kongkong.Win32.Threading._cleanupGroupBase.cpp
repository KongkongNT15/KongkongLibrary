//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    void _cleanupGroupBase::CloseMembers(bool cancelPendingCallbacks) const
    {
        NullPointerException::CheckNull(_cleanupGroup, u"CleanupGroup");
        ::CloseThreadpoolCleanupGroupMembers(_cleanupGroup, cancelPendingCallbacks, nullptr);
    }

    void _cleanupGroupBase::CloseMembers(bool cancelPendingCallbacks, ::std::nullptr_t) const
    {
        NullPointerException::CheckNull(_cleanupGroup, u"CleanupGroup");
        ::CloseThreadpoolCleanupGroupMembers(_cleanupGroup, cancelPendingCallbacks, nullptr);
    }

    void _cleanupGroupBase::CloseMembers(bool cancelPendingCallbacks, void* pCleanupContext) const
    {
        NullPointerException::CheckNull(_cleanupGroup, u"CleanupGroup");
        ::CloseThreadpoolCleanupGroupMembers(_cleanupGroup, cancelPendingCallbacks, pCleanupContext);
    }

    void _cleanupGroupBase::CloseMembersUnsafe(bool cancelPendingCallbacks) const noexcept
    {
        ::CloseThreadpoolCleanupGroupMembers(_cleanupGroup, cancelPendingCallbacks, nullptr);
    }

    void _cleanupGroupBase::CloseMembersUnsafe(bool cancelPendingCallbacks, ::std::nullptr_t) const noexcept
    {
        ::CloseThreadpoolCleanupGroupMembers(_cleanupGroup, cancelPendingCallbacks, nullptr);
    }

    void _cleanupGroupBase::CloseMembersUnsafe(bool cancelPendingCallbacks, void* pCleanupContext) const noexcept
    {
        ::CloseThreadpoolCleanupGroupMembers(_cleanupGroup, cancelPendingCallbacks, pCleanupContext);
    }
}
