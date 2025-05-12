#ifndef KONGKONG_WIN32_CREANUPGROUPBASE_H
#define KONGKONG_WIN32_CREANUPGROUPBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class _cleanupGroupBase {
        public:

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _cleanupGroup != nullptr; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return _cleanupGroup == nullptr; }

        void CloseMembers(bool cancelPendingCallbacks) const;
        void CloseMembers(bool cancelPendingCallbacks, ::std::nullptr_t) const;
        void CloseMembers(bool cancelPendingCallbacks, void* pCleanupContext) const;

        void CloseMembersUnsafe(bool cancelPendingCallbacks) const noexcept;
        void CloseMembersUnsafe(bool cancelPendingCallbacks, ::std::nullptr_t) const noexcept;
        void CloseMembersUnsafe(bool cancelPendingCallbacks, void* pCleanupContext) const noexcept;

        private:
        ::PTP_CLEANUP_GROUP _cleanupGroup;

        _cleanupGroupBase() = default;
        _cleanupGroupBase(_cleanupGroupBase const&) = default;
        _cleanupGroupBase(_cleanupGroupBase&&) = default;

        constexpr _cleanupGroupBase(::PTP_CLEANUP_GROUP cleanupGroup) noexcept : _cleanupGroup(cleanupGroup) {}
        constexpr _cleanupGroupBase(::std::nullptr_t) noexcept : _cleanupGroup(nullptr) {}

        _cleanupGroupBase& operator=(_cleanupGroupBase const&) = default;
        _cleanupGroupBase& operator=(_cleanupGroupBase&&) = default;

        friend CleanupGroup;
        friend CleanupGroupView;
        friend constexpr bool operator==(_cleanupGroupBase const&, _cleanupGroupBase const&) noexcept;
        friend constexpr bool operator==(_cleanupGroupBase const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator==(::std::nullptr_t, _cleanupGroupBase const&) noexcept;
        friend constexpr bool operator!=(_cleanupGroupBase const&, _cleanupGroupBase const&) noexcept;
        friend constexpr bool operator!=(_cleanupGroupBase const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator!=(::std::nullptr_t, _cleanupGroupBase const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(_cleanupGroupBase const& left, _cleanupGroupBase const& right) noexcept { return left._cleanupGroup == right._cleanupGroup; }
    [[nodiscard]] constexpr bool operator==(_cleanupGroupBase const& left, ::std::nullptr_t) noexcept { return left._cleanupGroup == nullptr; }
    [[nodiscard]] constexpr bool operator==(::std::nullptr_t, _cleanupGroupBase const& right) noexcept { return nullptr == right._cleanupGroup; }
    [[nodiscard]] constexpr bool operator!=(_cleanupGroupBase const& left, _cleanupGroupBase const& right) noexcept { return left._cleanupGroup != right._cleanupGroup; }
    [[nodiscard]] constexpr bool operator!=(_cleanupGroupBase const& left, ::std::nullptr_t) noexcept { return left._cleanupGroup != nullptr; }
    [[nodiscard]] constexpr bool operator!=(::std::nullptr_t, _cleanupGroupBase const& right) noexcept { return nullptr != right._cleanupGroup; }
}

#endif //!KONGKONG_WIN32_CREANUPGROUPBASE_H
