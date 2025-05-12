//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    ::SYSTEMTIME TimeZoneAPI::FileTimeToLocalTime(::FILETIME const& value)
    {
        return SystemTimeToLocalTime(FileTimeToSystemTime(value));
    }

    ::SYSTEMTIME TimeZoneAPI::FileTimeToSystemTime(::FILETIME const& value)
    {
        ::SYSTEMTIME time;
        if (::FileTimeToSystemTime(&value, &time) == 0) throw HResultException();

        return time;
    }

    ::SYSTEMTIME TimeZoneAPI::LocalTimeToSystemTime(::SYSTEMTIME const& value)
    {
        ::SYSTEMTIME time;
        if (::TzSpecificLocalTimeToSystemTime(nullptr, &value, &time) == 0) throw HResultException();

        return time;
    }

    ::FILETIME TimeZoneAPI::SystemTimeToFileTime(::SYSTEMTIME const& value)
    {
        ::FILETIME time;

        if (::SystemTimeToFileTime(&value, &time) == 0) throw HResultException();

        return time;
    }

    ::SYSTEMTIME TimeZoneAPI::SystemTimeToLocalTime(::SYSTEMTIME const& value)
    {
        ::SYSTEMTIME time;
        if (::SystemTimeToTzSpecificLocalTime(nullptr, &value, &time) == 0) throw HResultException();

        return time;
    }
}
