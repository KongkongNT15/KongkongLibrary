#ifndef KONGKONG_WIN32_SYSTEMTIMEBASE_H
#define KONGKONG_WIN32_SYSTEMTIMEBASE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Time.DayOfWeek.h"

namespace KONGKONG_NAMESPACE::Win32
{
    //時刻
    struct SystemTimeBase : public ValueType {

        constexpr operator ::SYSTEMTIME() const noexcept { return _systemTime; }

        [[nodiscard]] constexpr uint16_t Year() const noexcept { return _systemTime.wYear; }
        [[nodiscard]] constexpr uint16_t Month() const noexcept { return _systemTime.wMonth; }
        [[nodiscard]] constexpr uint16_t Day() const noexcept { return _systemTime.wDay; }
        [[nodiscard]] constexpr uint16_t Hour() const noexcept { return _systemTime.wHour; }
        [[nodiscard]] constexpr uint16_t Minute() const noexcept { return _systemTime.wMinute; }
        [[nodiscard]] constexpr uint16_t Second() const noexcept { return _systemTime.wSecond; }
        [[nodiscard]] constexpr uint16_t Milliseconds() const noexcept { return _systemTime.wMilliseconds; }

        [[nodiscard]] constexpr Time::DayOfWeek DayOfWeek() const noexcept { return (Time::DayOfWeek)_systemTime.wDayOfWeek; }

        [[nodiscard]] String ToString() const;

        protected:

        constexpr SystemTimeBase(::SYSTEMTIME const& right) noexcept : _systemTime(right) {}

        ::SYSTEMTIME _systemTime;

    };
}

#endif //!KONGKONG_WIN32_SYSTEMTIMEBASE_H
