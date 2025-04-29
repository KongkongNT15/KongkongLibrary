//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    bool VersionHelper::IsWindowsXPOrGreater() noexcept
    {
        return ::IsWindowsXPOrGreater();
    }

    bool VersionHelper::IsWindowsXPSP1OrGreater() noexcept
    {
        return ::IsWindowsXPSP1OrGreater();
    }

    bool VersionHelper::IsWindowsXPSP2OrGreater() noexcept
    {
        return ::IsWindowsXPSP2OrGreater();
    }

    bool VersionHelper::IsWindowsXPSP3OrGreater() noexcept
    {
        return ::IsWindowsXPSP3OrGreater();
    }
    
    bool VersionHelper::IsWindowsVistaOrGreater() noexcept
    {
        return ::IsWindowsVistaOrGreater();
    }

    bool VersionHelper::IsWindowsVistaSP1OrGreater() noexcept
    {
        return ::IsWindowsVistaSP1OrGreater();
    }

    bool VersionHelper::IsWindowsVistaSP2OrGreater() noexcept
    {
        return ::IsWindowsVistaSP2OrGreater();
    }

    bool VersionHelper::IsWindows7OrGreater() noexcept
    {
        return ::IsWindows7OrGreater();
    }

    bool VersionHelper::IsWindows7SP1OrGreater() noexcept
    {
        return ::IsWindows7SP1OrGreater();
    }

    bool VersionHelper::IsWindows8OrGreater() noexcept
    {
        return ::IsWindows8OrGreater();
    }

    bool VersionHelper::IsWindows8Point1OrGreater() noexcept
    {
        return ::IsWindows8Point1OrGreater();
    }

    bool VersionHelper::IsWindows10OrGreater() noexcept
    {
        return ::IsWindows10OrGreater();
    }
    
    bool VersionHelper::IsWindowsXP() noexcept
    {
        return !::IsWindowsVistaOrGreater();
    }

    bool VersionHelper::IsWindowsXPSP1() noexcept
    {
        return ::IsWindowsXPSP1OrGreater() && !::IsWindowsXPSP2OrGreater();
    }

    bool VersionHelper::IsWindowsXPSP2() noexcept
    {
        return ::IsWindowsXPSP2OrGreater() && !::IsWindowsXPSP3OrGreater();
    }

    bool VersionHelper::IsWindowsXPSP3() noexcept
    {
        return ::IsWindowsXPSP3OrGreater() && !::IsWindowsVistaOrGreater();
    }

    bool VersionHelper::IsWindowsVista() noexcept
    {
        return ::IsWindowsVistaOrGreater() && !::IsWindows7OrGreater();
    }

    bool VersionHelper::IsWindowsVistaSP1() noexcept
    {
        return ::IsWindowsVistaSP1OrGreater() && !::IsWindowsVistaSP2OrGreater();
    }

    bool VersionHelper::IsWindowsVistaSP2() noexcept
    {
        return ::IsWindowsVistaSP2OrGreater() && !::IsWindows7OrGreater();
    }

    bool VersionHelper::IsWindows7() noexcept
    {
        return ::IsWindows7OrGreater() && !::IsWindows8OrGreater();
    }

    bool VersionHelper::IsWindows7SP1() noexcept
    {
        return ::IsWindows7SP1OrGreater() && !::IsWindows8OrGreater();
    }

    bool VersionHelper::IsWindows8() noexcept
    {
        return ::IsWindows8OrGreater() &&!::IsWindows8Point1OrGreater();
    }

    bool VersionHelper::IsWindows8Or8Point1() noexcept
    {
        return ::IsWindows8OrGreater() && !::IsWindows10OrGreater();
    }

    bool VersionHelper::IsWindows8Point1() noexcept
    {
        return ::IsWindows8Point1OrGreater() && !::IsWindows10OrGreater();
    }

}
