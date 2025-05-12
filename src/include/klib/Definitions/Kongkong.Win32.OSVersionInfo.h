#ifndef KONGKONG_WIN32_OSVERSIONINFO_H
#define KONGKONG_WIN32_OSVERSIONINFO_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Win32.VersionNT.h"
#include "Kongkong.Win32.VersionSuite.h"

namespace KONGKONG_NAMESPACE::Win32
{
    /// @brief システムバージョン情報
    struct OSVersionInfo final : public ValueType {

        constexpr operator ::OSVERSIONINFOEXW() const noexcept { return _info; }

        constexpr OSVersionInfo& operator=(::OSVERSIONINFOEXW const& info) noexcept { _info = info; return *this; }

        [[nodiscard]]
        constexpr uint32_t BuildNumber() const noexcept { return _info.dwBuildNumber; }

        [[nodiscard]]
        String CSDVersion() const;

        [[nodiscard]]
        constexpr uint32_t MajorVersion() const noexcept { return _info.dwMajorVersion; }

        [[nodiscard]]
        constexpr uint32_t MinorVersion() const noexcept { return _info.dwMinorVersion; }

        [[nodiscard]]
        constexpr uint32_t PlatformId() const noexcept { return _info.dwPlatformId; }

        [[nodiscard]]
        constexpr VersionNT ProductType() const noexcept { return (VersionNT)_info.wProductType; }

        [[nodiscard]]
        constexpr uint16_t ServicePackMajor() const noexcept { return _info.wServicePackMajor; }

        [[nodiscard]]
        constexpr uint16_t ServicePackMinor() const noexcept { return _info.wServicePackMinor; }

        [[nodiscard]]
        constexpr VersionSuite SuiteMask() const noexcept { return (VersionSuite)_info.wSuiteMask; }

        /// @brief 型名を取得
        [[nodiscard]]
        String ToString() const;

        private:

        constexpr OSVersionInfo(::OSVERSIONINFOEXW const& info) noexcept : _info(info) {}
        OSVersionInfo() = default;

        ::OSVERSIONINFOEXW _info;
        
        friend Environment;
    };
}

#endif //!KONGKONG_WIN32_OSVERSIONINFO_H
