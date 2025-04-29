#ifndef KONGKONG_WIN32_CREANUPGROUPVIEW_H
#define KONGKONG_WIN32_CREANUPGROUPVIEW_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.Win32.Threading._cleanupGroupBase.h"
#include "Kongkong.Win32.Threading.CleanupGroup.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class KONGKONG_INCOMPLETED_CLASS CleanupGroupView final : public HandleType, public _cleanupGroupBase {
        public:

        constexpr CleanupGroupView(::PTP_CLEANUP_GROUP cleanupGroup) noexcept : _cleanupGroupBase(cleanupGroup) {}
        constexpr CleanupGroupView(CleanupGroup const& cleanupGroup) noexcept : _cleanupGroupBase(cleanupGroup._cleanupGroup) {}
        CleanupGroupView(CleanupGroup&&) = delete;

        /// @brief nullptrとして作成
        constexpr CleanupGroupView(::std::nullptr_t) noexcept : _cleanupGroupBase(nullptr) {}

        constexpr CleanupGroupView& operator=(::PTP_CLEANUP_GROUP cleanupGroup) noexcept { _cleanupGroup = cleanupGroup; return *this; }
        constexpr CleanupGroupView& operator=(CleanupGroup const& cleanupGroup) noexcept { _cleanupGroup = cleanupGroup._cleanupGroup; return *this; }
        constexpr CleanupGroupView& operator=(::std::nullptr_t) noexcept { _cleanupGroup = nullptr; return *this; }
        CleanupGroupView& operator=(CleanupGroup&&) = delete;

        [[nodiscard]]
        String ToString() const;
    };
}

#endif //!KONGKONG_WIN32_CREANUPGROUPVIEW_H
