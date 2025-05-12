#ifndef KONGKONG_WIN32_UI_WINDOW_H
#define KONGKONG_WIN32_UI_WINDOW_H

#include "Base.h"
#include "Kongkong.Events.EventHandler.h"
#include "Kongkong.Win32.UI.TitleBar.h"
#include "Kongkong.Win32.UI.UIElement.h"

#include <map>

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    struct KONGKONG_INCOMPLETED_CLASS Window : public UIElement {
        using ProjType = ::KONGKONG_NAMESPACE::Win32::UI::Window;

        static void MessageLoop();
        static void SetCmdShow(int nCmdShow) noexcept;

        static Initializer _init;
        static int _nCmdShow;
        static bool _isSetedCmdShow;
        static std::map<::HWND, Window*> _map;
        static ::LRESULT CALLBACK _procedure(::HWND hwnd, ::UINT uMsg, ::WPARAM wParam, ::LPARAM lParam);
        static void _initialize();

        /// @brief 投影型で作成するかnewでインスタンスを作ること
        Window();

        ~Window();

        void Activate();

        //Windowを破棄
        void Destroy() const noexcept { ::DestroyWindow(_handle); }

        bool IsZoomed() const noexcept { (bool)::IsZoomed(_handle); }

        //Windowを最小化
        void Minimize() const noexcept { ::CloseWindow(_handle); }

        String ToString() const override;

        constexpr auto& Activated() noexcept { return _activated.List(); }
        constexpr auto& Closing() noexcept { return _closing.List(); }
        constexpr auto& Creating() noexcept{ return _creating.List(); }
        constexpr auto& Destroyed() noexcept { return _destroyed.List(); }
        constexpr auto& PaintRequested() noexcept { return _paintRequested.List(); }

        constexpr TitleBar::ProjType const& TitleBar() const noexcept { return _titleBar; }

        private:

        PaintRequestedEventHandler _paintRequested;
        WindowActivatedEventHandler _activated;
        WindowClosingEventHandler _closing;
        WindowCratingEventHandler _creating;
        WindowEventHandler _destroyed;

        TitleBar::ProjType _titleBar;
    };
}

namespace KONGKONG_NAMESPACE::Win32::UI
{
    class KONGKONG_INCOMPLETED_CLASS Window : public UIElement {
        public:
        using ImplType = IMPLEMENTATION::Window;

        static void SetCmdShow(int nCmdShow) noexcept { ImplType::SetCmdShow(nCmdShow); }

        Window() : UIElement(nullptr) { _setInstance(NEW ImplType()); }
        /// @brief nullptrとして作成
        constexpr Window(std::nullptr_t) noexcept : UIElement(nullptr) {}

        //Windowを破棄
        void Destroy() const { _getPtr<ImplType>()->Destroy(); }

        auto& Activated() const { return _getPtr<ImplType>()->Activated(); }
        auto& Closing() const { return _getPtr<ImplType>()->Closing(); }
        auto& Creating() const { return _getPtr<ImplType>()->Creating(); }
        auto& Destroyed() const { return _getPtr<ImplType>()->Destroyed(); }
    };
}

#endif //!KONGKONG_WIN32_UI_WINDOW_H
