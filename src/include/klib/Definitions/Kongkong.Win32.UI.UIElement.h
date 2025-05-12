#ifndef KONGKONG_WIN32_UI_UIELEMENT_H
#define KONGKONG_WIN32_UI_UIELEMENT_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.Collections.ArrayList.h"
#include "Kongkong.Events.EventHandler.h"
#include "Kongkong.Win32.UI.ElementTheme.h"
#include "Kongkong.Win32.UI.Rect.h"

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    struct KONGKONG_INCOMPLETED_CLASS UIElement : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Win32::UI::UIElement;

        UIElement();
        UIElement(UIElement const&) = delete;

        UIElement& operator=(UIElement const&) = delete;

        double ActualHeight() const noexcept;
        double ActualWidth() const noexcept;

        bool AppendChild(ProjType const& element);

        Collections::IReadOnlyArray<ProjType> Children() const noexcept;

        String ClassName() const;

        uint32_t Dpi() const noexcept;

        constexpr double Height() const noexcept { return _height; }
        void Height(double value);

        int64_t SendMessage(uint32_t message, uint64_t wParam, int64_t lParam) const noexcept;

        int32_t PhysicalHeight() const noexcept;
        int32_t PhysicalWidth() const noexcept;

        Rect Position() const noexcept;

        bool RemoveChild(ProjType const& element);

        double Scale() const noexcept;

        String Text() const;
        void Text(const char16_t* p);
        void Text(String const& str);

        String ToString() const;

        constexpr double Width() const noexcept { return _width; }
        void Width(double value);

        constexpr auto& DpiChanged() noexcept { return _dpiChanged.List(); }
        constexpr auto& SizeChanged() noexcept { return _sizeChanged.List(); }

        protected:
        HWND _handle;

        [[nodiscard]]
        static constexpr ::HMENU CommandNumber() noexcept { return (::HMENU)(++_commandNumber); }

        private:
        Collections::ArrayList<ProjType> _children;

        ElementTheme _requestedTheme;

        DpiChangedEventHandler _dpiChanged;
        SizeChangedEventHandler _sizeChanged;

        double _height;
        double _width;

        static uint16_t _commandNumber;

        //
        static void _applyDpiChanged(ProjType const& sender, DpiChangedEventArgs const& args);
    
        friend Window;
    };
}

namespace KONGKONG_NAMESPACE::Win32::UI
{
    class KONGKONG_INCOMPLETED_CLASS UIElement : public Object {
        public:
        using ImplType = IMPLEMENTATION::UIElement;

        /// @brief nullptrとして作成
        constexpr UIElement(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] double ActualHeight() const;
        [[nodiscard]] double ActualWidth() const;

        Collections::IReadOnlyArray<UIElement> Children() const;

        [[deprecated]] int64_t SendMessage(uint32_t message, uint64_t wParam, int64_t lParam) const;

        [[nodiscard]] auto& DpiChanged() const;
        [[nodiscard]] auto& SizeChanged() const;

    };
}

#endif //!KONGKONG_WIN32_UI_UIELEMENT_H
