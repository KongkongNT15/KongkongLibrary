#ifndef KONGKONG_WIN32_UI_WINDOWACTIVATEEVENTARGS_H
#define KONGKONG_WIN32_UI_WINDOWACTIVATEEVENTARGS_H

#include "Base.h"
#include "Kongkong.Events.EventArgs.h"
#include "Kongkong.Win32.UI.WindowActivate.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct WindowActivatedEventArgs final : public ::KONGKONG_NAMESPACE::Events::EventArgs {
        
        constexpr WindowActivatedEventArgs(int windowActivate, bool isMinimized) noexcept : _windowActivate((::KONGKONG_NAMESPACE::Win32::UI::WindowActivate)windowActivate), _isMinimized(isMinimized) {}
        constexpr WindowActivatedEventArgs(::KONGKONG_NAMESPACE::Win32::UI::WindowActivate windowActivate, bool isMinimized) noexcept : _windowActivate(windowActivate), _isMinimized(isMinimized)  {}

        [[nodiscard]]
        constexpr ::KONGKONG_NAMESPACE::Win32::UI::WindowActivate WindowActivate() const noexcept { return _windowActivate; }
        
        [[nodiscard]]
        constexpr bool IsMinimized() const noexcept { return _isMinimized; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        ::KONGKONG_NAMESPACE::Win32::UI::WindowActivate _windowActivate;
        bool _isMinimized;
    };
}

#endif //!KONGKONG_WIN32_UI_WINDOWACTIVATEEVENTARGS_H
