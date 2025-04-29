#ifndef KONGKONG_WIN32_PRIMITIVES_SYSINFOAPI_H
#define KONGKONG_WIN32_PRIMITIVES_SYSINFOAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<sysinfoapi.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/sysinfoapi/
    class SysInfoAPI final {
        public:

        STATIC_CLASS(SysInfoAPI)

        //GetComputerNameEx()
        //は
        //Kongkong::Win32::ComputerName
        //に移動

        //GetSystemDirectoryW()
        //GetVersionExW()
        //は
        //Kongkong::Win32::Environment
        //に移動

        //メモリの状態を取得
        [[nodiscard]] static MemoryStatus GlobalMemoryStatus();
        
        //現在時刻を設定された地域で取得
        [[nodiscard]] static ::SYSTEMTIME LocalTime() noexcept;

        [[nodiscard]] static ::KONGKONG_NAMESPACE::Win32::SystemInfo SystemInfo() noexcept;

        //現在時刻を世界標準時で取得する
        [[nodiscard]] static ::SYSTEMTIME SystemTime() noexcept;

        //Windows起動後の経過時間
        [[nodiscard]] static uint32_t TickCount() noexcept;
        [[nodiscard]] static uint64_t TickCount64() noexcept;
        
        //Windowsディレクトリを取得
        [[nodiscard]] static String WindowsDirectory();

    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_SYSINFOAPI_H
