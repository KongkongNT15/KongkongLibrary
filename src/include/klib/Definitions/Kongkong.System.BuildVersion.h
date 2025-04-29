#ifndef KONGKONG_SYSTEM_BUILDVERSION_H
#define KONGKONG_SYSTEM_BUILDVERSION_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::System
{
    struct BuildVersion : public ValueType {

        constexpr BuildVersion(uint16_t major, uint16_t minor, uint32_t patch, uint32_t buildNumber) noexcept : m_major(major), m_minor(minor), m_patch(patch), m_buildNumber(buildNumber) {}

        [[nodiscard]]
        constexpr uint16_t Major() const noexcept { return m_major; }

        constexpr void Major(uint16_t value) noexcept { m_major = value; }

        [[nodiscard]]
        String ToString() const;

        private:
        uint16_t m_major;
        uint16_t m_minor;
        uint32_t m_patch;
        uint32_t m_buildNumber;

        friend constexpr bool operator==(BuildVersion const&, BuildVersion const&) noexcept;
        friend constexpr bool operator!=(BuildVersion const&, BuildVersion const&) noexcept;
        friend constexpr bool operator<(BuildVersion const&, BuildVersion const&) noexcept;
        friend constexpr bool operator<=(BuildVersion const&, BuildVersion const&) noexcept;
        friend constexpr bool operator>(BuildVersion const&, BuildVersion const&) noexcept;
        friend constexpr bool operator>=(BuildVersion const&, BuildVersion const&) noexcept;
        friend constexpr ::std::strong_ordering operator<=>(BuildVersion const&, BuildVersion const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(BuildVersion const& left, BuildVersion const& right) noexcept
    {
        return left.m_major == right.m_major
            && left.m_minor == right.m_minor
            && left.m_patch == right.m_patch
            && left.m_buildNumber == right.m_buildNumber;
    }

    [[nodiscard]] constexpr bool operator!=(BuildVersion const& left, BuildVersion const& right) noexcept
    {
        return left.m_major != right.m_major
            && left.m_minor != right.m_minor
            && left.m_patch != right.m_patch
            && left.m_buildNumber != right.m_buildNumber;
    }

    [[nodiscard]] constexpr bool operator<(BuildVersion const& left, BuildVersion const& right) noexcept
    {
        if (left.m_major < right.m_major) return true;
        if (left.m_major > right.m_major) return false;

        if (left.m_minor < right.m_minor) return true;
        if (left.m_minor > right.m_minor) return false;

        if (left.m_patch < right.m_patch) return true;
        if (left.m_patch > right.m_patch) return false;

        return left.m_buildNumber < right.m_buildNumber;
    }

    [[nodiscard]] constexpr bool operator<=(BuildVersion const& left, BuildVersion const& right) noexcept
    {
        if (left.m_major < right.m_major) return true;
        if (left.m_major > right.m_major) return false;

        if (left.m_minor < right.m_minor) return true;
        if (left.m_minor > right.m_minor) return false;

        if (left.m_patch < right.m_patch) return true;
        if (left.m_patch > right.m_patch) return false;
        
        return left.m_buildNumber <= right.m_buildNumber;
    }

    [[nodiscard]] constexpr bool operator>(BuildVersion const& left, BuildVersion const& right) noexcept
    {
        if (left.m_major > right.m_major) return true;
        if (left.m_major < right.m_major) return false;

        if (left.m_minor > right.m_minor) return true;
        if (left.m_minor < right.m_minor) return false;

        if (left.m_patch > right.m_patch) return true;
        if (left.m_patch < right.m_patch) return false;

        return left.m_buildNumber < right.m_buildNumber;
    }

    [[nodiscard]] constexpr bool operator>=(BuildVersion const& left, BuildVersion const& right) noexcept
    {
        if (left.m_major > right.m_major) return true;
        if (left.m_major < right.m_major) return false;

        if (left.m_minor > right.m_minor) return true;
        if (left.m_minor < right.m_minor) return false;

        if (left.m_patch > right.m_patch) return true;
        if (left.m_patch < right.m_patch) return false;
        
        return left.m_buildNumber >= right.m_buildNumber;
    }

    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(BuildVersion const& left, BuildVersion const& right) noexcept
    {
        if (left.m_major < right.m_major) return ::std::strong_ordering::less;
        if (left.m_major > right.m_major) return ::std::strong_ordering::greater;

        if (left.m_minor < right.m_minor) return ::std::strong_ordering::less;
        if (left.m_minor > right.m_minor) return ::std::strong_ordering::greater;

        if (left.m_patch < right.m_patch) return ::std::strong_ordering::less;
        if (left.m_patch > right.m_patch) return ::std::strong_ordering::greater;

        return left.m_buildNumber <=> right.m_buildNumber;
    }
}

#endif //!KONGKONG_SYSTEM_BUILDVERSION_H
