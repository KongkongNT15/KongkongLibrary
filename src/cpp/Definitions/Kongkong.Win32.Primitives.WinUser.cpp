//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Primitives
{

    void WinUser::CreateDirectory(const char16_t* path)
    {
        if (::CreateDirectoryW((const wchar_t*)path, nullptr) == 0) throw HResultException();
    }

    void WinUser::CreateDirectory(String const& path)
    {
        CreateDirectory(path.c_str());
    }

    void WinUser::CreateDirectory(const char16_t* path, ::SECURITY_ATTRIBUTES& securityAttributes)
    {
        if (::CreateDirectoryW((const wchar_t*)path, &securityAttributes) == 0) throw HResultException();
    }

    void WinUser::CreateDirectory(String const& path, ::SECURITY_ATTRIBUTES& securityAttributes)
    {
        CreateDirectory(path.c_str(), securityAttributes);
    }

    void WinUser::DestroyWindow(::HWND hWindow)
    {
        if (::DestroyWindow(hWindow) == 0) [[unlikely]] throw HResultException();
    }

    String WinUser::GetClassName(::HWND hWindow)
    {
        constexpr int32_t defaultSize = 16;
        int32_t length = defaultSize;
        int tmp;

        char16_t* p = String::AllocMemoryUnsafe(length);

        while (true) {
            tmp = ::GetClassNameW(hWindow, (wchar_t*)p, length);

            if (tmp == 0) [[unlikely]] throw HResultException();
            
            if (tmp != length - 1) break;
            
            length += defaultSize;
            
            String::FreeMemoryUnsafe(p);

            p = String::AllocMemoryUnsafe(length);
        }

        return String::WrapUnsafe(length, p);
    }

    uint32_t WinUser::GetDpiForWindow(::HWND hWindow)
    {
        uint32_t value = ::GetDpiForWindow(hWindow);

        if (value == 0) [[unlikely]] throw HResultException();

        return value;
    }

    ::HWND WinUser::GetParentWindow(::HWND hWindow)
    {
        ::HWND hParent = ::GetParent(hWindow);

        if (hParent == nullptr) [[unlikely]] throw HResultException();

        return hParent;
    }

    void WinUser::MinimizeWindow(::HWND hWindow)
    {
        if (::CloseWindow(hWindow) == 0) [[unlikely]] throw HResultException();
    }

    ::HWND WinUser::SetParentWindow(::HWND hChild, ::HWND hParent)
    {
        ::HWND hPreviusParent = ::SetParent(hChild, hParent);

        if (hPreviusParent == nullptr) [[unlikely]] throw HResultException();

        return hPreviusParent;
    }

    void WinUser::ShowWindow(::HWND hWindow, int nCmdShow)
    {
        if (::ShowWindow(hWindow, nCmdShow) == 0) [[unlikely]] throw HResultException();
    }

    void WinUser::UpdateWindow(::HWND hWindow)
    {
        if (::UpdateWindow(hWindow) == 0) [[unlikely]] throw HResultException();
    }
    
}
