#ifndef KONGKONG_WIN32_PRIMITIVES_DESKTOPWINDOWMANAGER_H
#define KONGKONG_WIN32_PRIMITIVES_DESKTOPWINDOWMANAGER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<dwmapi.h>
    class DesktopWindowManager final {
        public:

        STATIC_CLASS(DesktopWindowManager)

        [[nodiscard]] static constexpr ::COLORREF DefaultColor() noexcept { return DWMWA_COLOR_DEFAULT; }
        [[nodiscard]] static constexpr ::COLORREF NoneColor() noexcept { return DWMWA_COLOR_NONE; }

        [[nodiscard]] static UI::SystemBackDrop GetTitleBarBackDrop(::HWND hWnd);


        static void SetTitleBarBackDrop(HWND hWnd, UI::SystemBackDrop backDrop);
        static void SetTitleBarColor(HWND hWnd, UI::Color const& color);
        static void SetTitleBarColor(HWND hWnd, ::COLORREF const& rgb);
        static void SetTitleBarTextColor(HWND hWnd, UI::Color const& color);
        static void SetTitleBarTextColor(HWND hWnd, ::COLORREF const& rgb);
        static void SetTitleBarTheme(HWND hWnd, DwmTitleBarTheme theme);
        static void SetWindowBorderColor(HWND hWnd, UI::Color const& color);
        static void SetWindowBorderColor(HWND hWnd, ::COLORREF const& rgb);
        static void SetWindowCornerPreference(HWND hWnd, UI::WindowCornerPreference preference);

        private:
        static ::COLORREF _convertToRGB(UI::Color const& color);
        static void _setColor(HWND hWnd, ::DWMWINDOWATTRIBUTE attribute , COLORREF const& rgb);

    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_DESKTOPWINDOWMANAGER_H
