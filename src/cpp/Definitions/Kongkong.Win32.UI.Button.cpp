//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    Button::Button()
    {
        _handle = ::CreateWindowW(L"BUTTON", L"", WS_CHILD | WS_VISIBLE, 0, 0, 64, 24, nullptr, CommandNumber(), GetModuleHandleW(nullptr), nullptr);

        if (_handle == nullptr) [[unlikely]] throw HResultException();
    }

    String Button::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::UI::Button");
    }
}

namespace KONGKONG_NAMESPACE::Win32::UI
{
    
}
