#ifndef KONGKONG_WIN32_SYSTEMTIME_H
#define KONGKONG_WIN32_SYSTEMTIME_H

#include "Base.h"
#include "Kongkong.Win32.SystemTimeBase.h"

namespace KONGKONG_NAMESPACE::Win32
{
    struct SystemTime final : public SystemTimeBase {
        [[nodiscard]] static SystemTime Now();

        constexpr SystemTime(::SYSTEMTIME const& right) noexcept : SystemTimeBase(right) {}
        SystemTime(::FILETIME const& fileTime);
        

        [[nodiscard]] LocalTime ToLocalTime() const;

    };
}

#endif //!KONGKONG_WIN32_SYSTEMTIME_H
