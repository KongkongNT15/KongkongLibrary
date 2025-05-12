#ifndef KONGKONG_WIN32_PRIMITIVES_VERSIONHELPER_H
#define KONGKONG_WIN32_PRIMITIVES_VERSIONHELPER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<VersionHelper.h>
    class VersionHelper final {
        public:

        STATIC_CLASS(VersionHelper)

        [[nodiscard]] static bool IsWindowsXPOrGreater() noexcept;
        [[nodiscard]] static bool IsWindowsXPSP1OrGreater() noexcept;
        [[nodiscard]] static bool IsWindowsXPSP2OrGreater() noexcept;
        [[nodiscard]] static bool IsWindowsXPSP3OrGreater() noexcept;
        [[nodiscard]] static bool IsWindowsVistaOrGreater() noexcept;
        [[nodiscard]] static bool IsWindowsVistaSP1OrGreater() noexcept;
        [[nodiscard]] static bool IsWindowsVistaSP2OrGreater() noexcept;
        [[nodiscard]] static bool IsWindows7OrGreater() noexcept;
        [[nodiscard]] static bool IsWindows7SP1OrGreater() noexcept;
        [[nodiscard]] static bool IsWindows8OrGreater() noexcept;
        [[nodiscard]] static bool IsWindows8Point1OrGreater() noexcept;
        [[nodiscard]] static bool IsWindows10OrGreater() noexcept;
        
        [[nodiscard]] static bool IsWindowsXP() noexcept;
        [[nodiscard]] static bool IsWindowsXPSP1() noexcept;
        [[nodiscard]] static bool IsWindowsXPSP2() noexcept;
        [[nodiscard]] static bool IsWindowsXPSP3() noexcept;
        [[nodiscard]] static bool IsWindowsVista() noexcept;
        [[nodiscard]] static bool IsWindowsVistaSP1() noexcept;
        [[nodiscard]] static bool IsWindowsVistaSP2() noexcept;
        [[nodiscard]] static bool IsWindows7() noexcept;
        [[nodiscard]] static bool IsWindows7SP1() noexcept;
        [[nodiscard]] static bool IsWindows8() noexcept;
        [[nodiscard]] static bool IsWindows8Or8Point1() noexcept;
        [[nodiscard]] static bool IsWindows8Point1() noexcept;
        
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_VERSIONHELPER_H
