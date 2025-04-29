//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Gdi
{
    DeviceContext::DeviceContext(::HDC dc, bool autoRelease) : _dc(dc), _hwnd(nullptr), _autoRelease(autoRelease)
    {
        ArgumentNullException::CheckNull(dc, u"dc");
    }

    DeviceContext::DeviceContext(DeviceContext&& right) noexcept : _dc(right._dc), _hwnd(right._hwnd), _autoRelease(right._autoRelease)
    {
        right._dc = nullptr;
    }

    DeviceContext::~DeviceContext()
    {
        if (_dc != nullptr && _autoRelease) {
            if (_hwnd == nullptr) ::DeleteDC(_dc);
            else ::ReleaseDC(_hwnd, _dc);
        }
    }

    DeviceContext& DeviceContext::operator=(DeviceContext&& right) noexcept
    {
        DeviceContext::~DeviceContext();

        _dc = right._dc;
        _hwnd = right._hwnd;
        _autoRelease = right._autoRelease;

        right._dc = nullptr;

        return *this;
    }

    void DeviceContext::Close()
    {
        _checkHandle();

        BOOL result;
        if (_hwnd == nullptr) result = ::DeleteDC(_dc);
        else result = ::ReleaseDC(_hwnd, _dc);

        if (result == FALSE) [[unlikely]] throw HResultException();

        _dc = nullptr;
    }

    void DeviceContext::PaintRectangle(int left, int top, int right, int bottom)
    {
        if (::Rectangle(_dc, left, top, right, bottom) == 0) [[unlikely]] {
            _checkHandle();
            throw HResultException();
        }
    }

    void DeviceContext::PaintRectangle(::RECT const& rect)
    {
        PaintRectangle(rect.left, rect.top, rect.right, rect.bottom);
    }

    void DeviceContext::PaintRectangle(UI::Rect const& rect)
    {
        PaintRectangle(rect.Left(), rect.Top(), rect.Right(), rect.Bottom());
    }

    String DeviceContext::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::Gdi::DeviceContext");
    }

    void DeviceContext::_checkHandle() const
    {
        if (_dc == nullptr) [[unlikely]] throw InvalidOperationException(u"ハンドルはすでに解放されています");
    }
}
