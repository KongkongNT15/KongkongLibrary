#ifndef KONGKONG_WIN32_LOCALTIME_H
#define KONGKONG_WIN32_LOCALTIME_H

#include "Base.h"
#include "Kongkong.Win32.SystemTimeBase.h"

namespace KONGKONG_NAMESPACE::Win32
{
    struct LocalTime final : public SystemTimeBase {
        [[nodiscard]] static LocalTime Now();

        constexpr LocalTime(::SYSTEMTIME const& right) noexcept : SystemTimeBase(right) {}
        LocalTime(::FILETIME const& fileTime);
        
        [[nodiscard]] SystemTime ToSystemTime() const;
    };
}

#endif //!KONGKONG_WIN32_LOCALTIME_H
