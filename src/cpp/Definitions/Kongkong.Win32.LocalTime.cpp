//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    LocalTime LocalTime::Now()
    {
        return Primitives::SysInfoAPI::LocalTime();
    }

    LocalTime::LocalTime(::FILETIME const& fileTime) : SystemTimeBase(Primitives::TimeZoneAPI::FileTimeToLocalTime(fileTime))
    {
    }

    SystemTime LocalTime::ToSystemTime() const
    {
        return SystemTime(Primitives::TimeZoneAPI::LocalTimeToSystemTime(_systemTime));
    }
}
