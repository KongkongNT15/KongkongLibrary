#ifndef KONGKONG_TIME_H
#define KONGKONG_TIME_H

#include "Kongkong.h"
#include "Definitions/Kongkong.Time.DayOfWeek.h"

namespace KONGKONG_NAMESPACE::Time
{
    enum struct DateTimeKind {
        Unspecified,
        Utc,
        Local,
    };

    struct DateTime final : public ValueType {

        static DateTime Now() { return DateTime(std::time(nullptr), DateTimeKind::Local); }

        constexpr DateTime() noexcept {}
        

        int Day() const noexcept { return _tm.tm_mday; }
        DayOfWeek DayOfWeek() const noexcept { return (::KONGKONG_NAMESPACE::Time::DayOfWeek)_tm.tm_wday; }
        int DayOfYear() const noexcept { return _tm.tm_yday; }
        DateTimeKind Kind() const noexcept { return _kind; }
        int Month() const noexcept { return _tm.tm_mon; }
        int Second() const noexcept { return _tm.tm_sec; }
        int Year() const noexcept { return _tm.tm_year + 1900; }

        String ToString() const;

        DateTime AddDays(double day) const { return AddSeconds((int64_t)(86400.0 * day)); }
        DateTime AddHours(double hour) const { return AddSeconds((int64_t)(3600.0 * hour)); }
        DateTime AddMonths(int month);
        DateTime AddMinutes(double minutes) const { return AddSeconds((int64_t)(60.0 * minutes)); }
        DateTime AddSeconds(int64_t seconds) const;
        DateTime AddYears(int year);


        private:
        //LocalとUtcの時間差を取得
        //Local - Utc
        static time_t _lgDifference();

        DateTime(std::time_t time, DateTimeKind kind);
        constexpr DateTime(std::tm const& time, DateTimeKind kind) : _tm(time), _kind(kind) {}

        std::tm _tm;
        DateTimeKind _kind;

    };
}

#endif //!KONGKONG_TIME_H
