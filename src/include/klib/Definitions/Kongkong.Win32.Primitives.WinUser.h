#ifndef KONGKONG_WIN32_PRIMITIVES_WINUSER_H
#define KONGKONG_WIN32_PRIMITIVES_WINUSER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<WinUser.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/winuser/
    class WinUser final {
        public:

        STATIC_CLASS(WinUser)

        //CharLower()
        //CharUpper()
        //は
        //Win32::CharHelper
        //Win32::StringHelper
        //として分離

        //フォルダ作成
        static void CreateDirectory(const char16_t* path);
        static void CreateDirectory(String const& path);
        static void CreateDirectory(const char16_t* path, ::SECURITY_ATTRIBUTES& securityAttributes);
        static void CreateDirectory(String const& path, ::SECURITY_ATTRIBUTES& securityAttributes);

        //IsCharAlpha()
        //IsCharLower()
        //IsCharUpper()
        //は
        //Win32::CharHelper
        //として分離

        //MessageBox()は
        //Win32::MessageBox class
        //として分離

        static void DestroyWindow(::HWND hWindow);

        static String GetClassName(::HWND hWindow);

        static uint32_t GetDpiForWindow(::HWND hWindow);

        static ::HWND GetParentWindow(::HWND hWindow);

        static void MinimizeWindow(::HWND hWindow);

        static ::HWND SetParentWindow(::HWND hChild, ::HWND hParent);

        static void ShowWindow(::HWND hWindow, int nCmdShow);

        static void UpdateWindow(::HWND hWindow);

    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_WINUSER_H
