//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    uint16_t UIElement::_commandNumber = 0;
    
    UIElement::UIElement() :
        _children(),
        _handle(),
        _requestedTheme(),
        _height(),
        _width(),
        _dpiChanged(),
        _sizeChanged()
    {
        DpiChanged() += _applyDpiChanged;
    }

    double UIElement::ActualHeight() const noexcept
    {
        return PhysicalHeight() * Scale();
    }
    
    double UIElement::ActualWidth() const noexcept
    {
        return PhysicalWidth() * Scale();
    }

    Collections::IReadOnlyArray<UIElement::ProjType> UIElement::Children() const noexcept
    {
        return _children;
    }

    String UIElement::ClassName() const
    {
        return Primitives::WinUser::GetClassName(_handle);
    }

    uint32_t UIElement::Dpi() const noexcept
    {
        return ::GetDpiForWindow(_handle);
    }

    int32_t UIElement::PhysicalHeight() const noexcept
    {
        Rect rect = Position();

        return rect.Bottom() - rect.Top();
    }

    int32_t UIElement::PhysicalWidth() const noexcept
    {
        Rect rect = Position();

        return rect.Right() - rect.Bottom();
    }

    Rect UIElement::Position() const noexcept
    {
        Rect rect;
        ::GetWindowRect(_handle, &rect._rect);

        return rect;
    }

    bool UIElement::RemoveChild(ProjType const& element)
    {
        auto& e = Object::ProjType::GetInstance(element, u"element");

        if (Object::ProjType::GetInstanceUnsafe(_children).Remove(element)) [[likely]] {
            ::SetParent(e._handle, nullptr);
        }
    }

    double UIElement::Scale() const noexcept
    {
        return Dpi() / 96.0;
    }

    int64_t UIElement::SendMessage(uint32_t message, uint64_t wParam, int64_t lParam) const noexcept
    {
        return ::SendMessageW(_handle, message, wParam, lParam);
    }

    String UIElement::Text() const
    {
        //null文字を含まない長さ
        int32_t length = ::GetWindowTextLengthW(_handle);
        int32_t capacity = length + 1;

        if (length == 0) return String(true);
        
        char16_t* p = String::AllocMemoryUnsafe(capacity);

        ::GetWindowTextW(_handle, (wchar_t*)p, capacity);

        return String::WrapUnsafe(capacity, length, p);
    }

    void UIElement::Text(const char16_t* p)
    {
        if (::SetWindowTextW(_handle, (const wchar_t*)p) == 0) [[unlikely]] throw HResultException();
    }

    void UIElement::Text(String const& str)
    {
        Text(str.c_str());
    }

    String UIElement::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::UI::UIElement");
    }

    void UIElement::_applyDpiChanged(ProjType const& sender, DpiChangedEventArgs const& args)
    {
        for (ProjType const& child : sender->Children()) {
            ::KONGKONG_NAMESPACE::Object::GetInstanceUnsafe(child)._dpiChanged.Call(child, args);
        }
    }
}

namespace KONGKONG_NAMESPACE::Win32::UI
{
    double UIElement::ActualHeight() const
    {
        return _getPtr<ImplType>()->ActualHeight();
    }

    double UIElement::ActualWidth() const
    {
        return _getPtr<ImplType>()->ActualWidth();
    }

    Collections::IReadOnlyArray<UIElement> UIElement::Children() const
    {
        return _getPtr<ImplType>()->Children();
    }

    int64_t UIElement::SendMessage(uint32_t message, uint64_t wParam, int64_t lParam) const
    {
        return _getPtr<ImplType>()->SendMessage(message, wParam, lParam);
    }

    auto& UIElement::DpiChanged() const
    {
        return _getPtr<ImplType>()->DpiChanged();
    }

    auto& UIElement::SizeChanged() const
    {
        return _getPtr<ImplType>()->SizeChanged();
    }
}
