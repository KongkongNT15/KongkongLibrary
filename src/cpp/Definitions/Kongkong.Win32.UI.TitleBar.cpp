//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    void TitleBar::BackDrop(SystemBackDrop backDrop)
    {
        Primitives::DesktopWindowManager::SetTitleBarBackDrop(_hWindow, backDrop);
    }

    SystemBackDrop TitleBar::BackDrop() const
    {
        return Primitives::DesktopWindowManager::GetTitleBarBackDrop(_hWindow);
    }

    String TitleBar::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::UI::TitleBar");
    }
}

namespace KONGKONG_NAMESPACE::Win32::UI
{
    TitleBar::TitleBar(::HWND hWindow) : Object(nullptr)
    {
        _setInstance(NEW ImplType(hWindow));
    }

    void TitleBar::BackDrop(SystemBackDrop backDrop) const
    {
        _getPtr<ImplType>()->BackDrop(backDrop);
    }

    SystemBackDrop TitleBar::BackDrop() const
    {
        return _getPtr<ImplType>()->BackDrop();
    }

}
