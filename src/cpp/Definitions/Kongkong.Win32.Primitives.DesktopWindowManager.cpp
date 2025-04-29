//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    UI::SystemBackDrop DesktopWindowManager::GetTitleBarBackDrop(::HWND hWnd)
    {
        ::DWM_SYSTEMBACKDROP_TYPE type;
        HRESULT result;

        result = ::DwmGetWindowAttribute(hWnd, DWMWINDOWATTRIBUTE::DWMWA_SYSTEMBACKDROP_TYPE, &type, sizeof(::DWM_SYSTEMBACKDROP_TYPE));

        if (result != S_OK) [[unlikely]] throw HResultException(result);

        return (UI::SystemBackDrop)type;
    }

    void DesktopWindowManager::SetTitleBarBackDrop(HWND hWnd, UI::SystemBackDrop backDrop)
    {
        HRESULT result = ::DwmSetWindowAttribute(hWnd, DWMWINDOWATTRIBUTE::DWMWA_SYSTEMBACKDROP_TYPE, &backDrop, sizeof(UI::SystemBackDrop));

        if (result != S_OK) [[unlikely]] throw HResultException(result);
        
    }

    void DesktopWindowManager::SetTitleBarColor(HWND hWnd, UI::Color const& color)
    {
        SetTitleBarColor(hWnd, _convertToRGB(color));
    }

    void DesktopWindowManager::SetTitleBarColor(HWND hWnd, ::COLORREF const& rgb)
    {
        _setColor(hWnd, ::DWMWINDOWATTRIBUTE::DWMWA_CAPTION_COLOR, rgb);
    }

    void DesktopWindowManager::SetTitleBarTextColor(HWND hWnd, UI::Color const& color)
    {
        SetTitleBarTextColor(hWnd, _convertToRGB(color));
    }

    void DesktopWindowManager::SetTitleBarTextColor(HWND hWnd, ::COLORREF const& rgb)
    {
        _setColor(hWnd, ::DWMWINDOWATTRIBUTE::DWMWA_TEXT_COLOR, rgb);
    }

    void DesktopWindowManager::SetTitleBarTheme(HWND hWnd, DwmTitleBarTheme theme)
    {
        HRESULT result = ::DwmSetWindowAttribute(hWnd, DWMWINDOWATTRIBUTE::DWMWA_USE_IMMERSIVE_DARK_MODE, &theme, sizeof(theme));

        if (result != S_OK) [[unlikely]] throw HResultException(result);
        
    }

    void DesktopWindowManager::SetWindowBorderColor(HWND hWnd, UI::Color const& color)
    {
        SetWindowBorderColor(hWnd, _convertToRGB(color));
    }

    void DesktopWindowManager::SetWindowBorderColor(HWND hWnd, ::COLORREF const& rgb)
    {
        _setColor(hWnd, ::DWMWINDOWATTRIBUTE::DWMWA_BORDER_COLOR, rgb);
    }

    void DesktopWindowManager::SetWindowCornerPreference(HWND hWnd, UI::WindowCornerPreference preference)
    {
        HRESULT result = ::DwmSetWindowAttribute(hWnd, DWMWINDOWATTRIBUTE::DWMWA_WINDOW_CORNER_PREFERENCE, &preference, sizeof(UI::WindowCornerPreference));

        if (result != S_OK) [[unlikely]] throw HResultException(result);
        
    }

    ::COLORREF DesktopWindowManager::_convertToRGB(UI::Color const& color)
    {
        //rgb[0] = A: 常にゼロ
        //rgb[1] = B: 青
        //rgb[2] = G: 緑
        //rgb[3] = R: 赤
        uint8_t rgb[4];
        COLORREF* p = (COLORREF*)rgb;

        rgb[0] = 0x00;
        rgb[1] = color.B();
        rgb[2] = color.G();
        rgb[3] = color.R();

        return *p;
    }
    
    void DesktopWindowManager::_setColor(HWND hWnd, ::DWMWINDOWATTRIBUTE attribute , COLORREF const& rgb)
    {
        HRESULT result = ::DwmSetWindowAttribute(hWnd, attribute, &rgb, sizeof(COLORREF));

        if (result != S_OK) [[unlikely]] throw HResultException(result);
        
    }
}
