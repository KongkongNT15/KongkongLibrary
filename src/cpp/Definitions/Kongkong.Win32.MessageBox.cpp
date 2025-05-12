//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption)
    {
        return Show(hWnd, messageText, caption, MessageBoxButton::OK, MessageBoxImage::None, MessageBoxDefaultButton::Button1, MessageBoxModality::ApplicationModal, MessageBoxOtherOptions::None);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption, MessageBoxButton button)
    {
        return Show(hWnd, messageText, caption, button, MessageBoxImage::None, MessageBoxDefaultButton::Button1, MessageBoxModality::ApplicationModal, MessageBoxOtherOptions::None);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption, MessageBoxImage icon)
    {
        return Show(hWnd, messageText, caption, MessageBoxButton::OK, icon, MessageBoxDefaultButton::Button1, MessageBoxModality::ApplicationModal, MessageBoxOtherOptions::None);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption, MessageBoxButton button, MessageBoxImage icon)
    {
        return Show(hWnd, messageText, caption, button, icon, MessageBoxDefaultButton::Button1, MessageBoxModality::ApplicationModal, MessageBoxOtherOptions::None);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, const char16_t* caption, MessageBoxButton button, MessageBoxImage icon, MessageBoxDefaultButton defaultButton, MessageBoxModality modality, MessageBoxOtherOptions options)
    {
        int ret = ::MessageBoxW(hWnd, (const wchar_t*)messageText, (const wchar_t*)caption, (UINT)button | (UINT)icon | (UINT)defaultButton | (UINT)modality | (UINT)options);

        if (ret == 0) [[unlikely]] throw HResultException();
        
        return (MessageBoxResult)ret;
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, String const& caption)
    {
        return Show(hWnd, messageText, caption.c_str());
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, String const& caption, MessageBoxButton button)
    {
        return Show(hWnd, messageText, caption.c_str(), button);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, String const& caption, MessageBoxImage icon)
    {
        return Show(hWnd, messageText, caption.c_str(), icon);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, String const& caption, MessageBoxButton button, MessageBoxImage icon)
    {
        return Show(hWnd, messageText, caption.c_str(), button, icon);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, const char16_t* messageText, String const& caption, MessageBoxButton button, MessageBoxImage icon, MessageBoxDefaultButton defaultButton, MessageBoxModality modality, MessageBoxOtherOptions options)
    {
        return Show(hWnd, messageText, caption.c_str(), button, icon, defaultButton, modality, options);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, const char16_t* caption)
    {
        return Show(hWnd, messageText.c_str(), caption);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, const char16_t* caption, MessageBoxButton button)
    {
        return Show(hWnd, messageText.c_str(), caption, button);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, const char16_t* caption, MessageBoxImage icon)
    {
        return Show(hWnd, messageText.c_str(), caption, icon);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, const char16_t* caption, MessageBoxButton button, MessageBoxImage icon)
    {
        return Show(hWnd, messageText.c_str(), caption, button, icon);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, const char16_t* caption, MessageBoxButton button, MessageBoxImage icon, MessageBoxDefaultButton defaultButton, MessageBoxModality modality, MessageBoxOtherOptions options)
    {
        return Show(hWnd, messageText.c_str(), caption, button, icon, defaultButton, modality, options);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, String const& caption)
    {
        return Show(hWnd, messageText.c_str(), caption.c_str());
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, String const& caption, MessageBoxButton button)
    {
        return Show(hWnd, messageText.c_str(), caption.c_str(), button);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, String const& caption, MessageBoxImage icon)
    {
        return Show(hWnd, messageText.c_str(), caption.c_str(), icon);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, String const& caption, MessageBoxButton button, MessageBoxImage icon)
    {
        return Show(hWnd, messageText.c_str(), caption.c_str(), button, icon);
    }

    MessageBoxResult MessageBox::Show(::HWND hWnd, String const& messageText, String const& caption, MessageBoxButton button, MessageBoxImage icon, MessageBoxDefaultButton defaultButton, MessageBoxModality modality, MessageBoxOtherOptions options)
    {
        return Show(hWnd, messageText.c_str(), caption.c_str(), button, icon, defaultButton, modality, options);
    }

}
