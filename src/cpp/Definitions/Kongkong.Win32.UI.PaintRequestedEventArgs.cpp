//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::UI
{
    Gdi::DeviceContext PaintRequestedEventArgs::DeviceContext() const noexcept
    {
        return Gdi::DeviceContext(_paintStruct.hdc, false);
    }

    String PaintRequestedEventArgs::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::UI::PaintRequestedEventArgs");
    }
}
