//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    SystemTime SystemTime::Now()
    {
        return Primitives::SysInfoAPI::SystemTime();
    }

    SystemTime::SystemTime(::FILETIME const& fileTime) : SystemTimeBase(Primitives::TimeZoneAPI::FileTimeToSystemTime(fileTime))
    {
    }

    LocalTime SystemTime::ToLocalTime() const
    {
        return LocalTime(Primitives::TimeZoneAPI::SystemTimeToLocalTime(_systemTime));
    }
}
