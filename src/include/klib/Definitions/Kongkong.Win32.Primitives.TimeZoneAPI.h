#ifndef KONGKONG_WIN32_PRIMITIVES_TIMEZONEAPI_H
#define KONGKONG_WIN32_PRIMITIVES_TIMEZONEAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<Timezoneapi.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/timezoneapi/
    class TimeZoneAPI final {
        public:

        STATIC_CLASS(TimeZoneAPI)

        [[nodiscard]] static ::SYSTEMTIME FileTimeToLocalTime(::FILETIME const& value);
        [[nodiscard]] static ::SYSTEMTIME FileTimeToSystemTime(::FILETIME const& value);
        [[nodiscard]] static ::SYSTEMTIME LocalTimeToSystemTime(::SYSTEMTIME const& value);
        [[nodiscard]] static ::FILETIME SystemTimeToFileTime(::SYSTEMTIME const& value);
        [[nodiscard]] static ::SYSTEMTIME SystemTimeToLocalTime(::SYSTEMTIME const& value);
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_TIMEZONEAPI_H
