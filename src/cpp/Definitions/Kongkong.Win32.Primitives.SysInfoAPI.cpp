//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    MemoryStatus SysInfoAPI::GlobalMemoryStatus()
    {
        ::MEMORYSTATUSEX status;
        status.dwLength = sizeof(::MEMORYSTATUSEX);

        if (::GlobalMemoryStatusEx(&status) == 0) [[unlikely]] throw HResultException();

        return status;
    }

    ::SYSTEMTIME SysInfoAPI::LocalTime() noexcept
    {
        ::SYSTEMTIME time;

        ::GetLocalTime(&time);

        return time;
    }

    ::KONGKONG_NAMESPACE::Win32::SystemInfo SysInfoAPI::SystemInfo() noexcept
    {
        ::KONGKONG_NAMESPACE::Win32::SystemInfo info;
        ::GetSystemInfo(info.BasePointer());

        return info;
    }

    ::SYSTEMTIME SysInfoAPI::SystemTime() noexcept
    {
        ::SYSTEMTIME time;

        ::GetSystemTime(&time);

        return time;
    }

    uint32_t SysInfoAPI::TickCount() noexcept
    {
        return ::GetTickCount();
    }

    uint64_t SysInfoAPI::TickCount64() noexcept
    {
        return ::GetTickCount64();
    }

    String SysInfoAPI::WindowsDirectory()
    {
        ssize_t length = FileAPI::MaxPathLength();
        char16_t* wcs = String::AllocMemory(length);

        UINT reqLength = ::GetWindowsDirectoryW((wchar_t*)wcs, (UINT)length);
        

        if (reqLength == 0) [[unlikely]] {
            String::FreeMemoryUnsafe(wcs);

            throw HResultException();
        }

        if ((ssize_t)reqLength >= length) {
            String::FreeMemoryUnsafe(wcs);

            wcs = String::AllocMemory(reqLength);
            length = reqLength;

            if (::GetWindowsDirectoryW((wchar_t*)wcs, (UINT)length) == 0) {
                String::FreeMemoryUnsafe(wcs);

                throw HResultException();
            }

        }

        return String::WrapUnsafe(length, wcs);
    }
    
}
