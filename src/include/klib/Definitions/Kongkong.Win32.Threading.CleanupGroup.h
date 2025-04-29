#ifndef KONGKONG_WIN32_CREANUPGROUP_H
#define KONGKONG_WIN32_CREANUPGROUP_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.Win32.Threading._cleanupGroupBase.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class KONGKONG_INCOMPLETED_CLASS CleanupGroup final : public HandleType, public _cleanupGroupBase {
        public:
        CleanupGroup();
        CleanupGroup(CleanupGroup const&) = delete;
        constexpr CleanupGroup(CleanupGroup&& right) noexcept : _cleanupGroupBase(right._cleanupGroup) { right._cleanupGroup = nullptr; }
        /// @brief nullptrとして作成
        constexpr CleanupGroup(::std::nullptr_t) noexcept : _cleanupGroupBase(nullptr) {}

        ~CleanupGroup();

        CleanupGroup& operator=(CleanupGroup const&) = delete;
        CleanupGroup& operator=(CleanupGroup&& right) noexcept;
        CleanupGroup& operator=(::std::nullptr_t) noexcept;

        [[nodiscard]]
        String ToString() const;
    };
}

#endif //!KONGKONG_WIN32_CREANUPGROUP_H
