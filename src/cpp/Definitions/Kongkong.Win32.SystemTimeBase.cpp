//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    String SystemTimeBase::ToString() const
    {
        constexpr ssize_t size = 20;
        char wcs[size];

        std::snprintf(wcs, size, "%04hu/%02hu/%02hu %02hu:%02hu:%02hu", _systemTime.wYear, _systemTime.wMonth, _systemTime.wDay, _systemTime.wHour, _systemTime.wMinute, _systemTime.wSecond);

        return String::FromAsciiUnsafe(size - 1, wcs);
    }
}
