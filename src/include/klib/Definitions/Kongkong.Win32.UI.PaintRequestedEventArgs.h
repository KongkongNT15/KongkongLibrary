#ifndef KONGKONG_WIN32_UI_PAINTREQUESTEDEVENTARGS_H
#define KONGKONG_WIN32_UI_PAINTREQUESTEDEVENTARGS_H

#include "Base.h"
#include "Kongkong.Events.EventArgs.h"
#include "Kongkong.Win32.UI.Rect.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct PaintRequestedEventArgs final : public Events::EventArgs {

        constexpr PaintRequestedEventArgs(::PAINTSTRUCT paintStruct) noexcept : _paintStruct(paintStruct) {}

        [[nodiscard]]
        constexpr Rect Area() const noexcept { return _paintStruct.rcPaint; }

        [[nodiscard]]
        Gdi::DeviceContext DeviceContext() const noexcept;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]] 
        String ToString() const;

        private:

        PaintRequestedEventArgs() = default;

        ::PAINTSTRUCT _paintStruct;

        friend IMPLEMENTATION::Window;
    };
}

#endif //!KONGKONG_WIN32_UI_PAINTREQUESTEDEVENTARGS_H
