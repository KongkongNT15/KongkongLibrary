#ifndef KONGKONG_WIN32_UI_SIZECHANGEDEVENTARGS_H
#define KONGKONG_WIN32_UI_SIZECHANGEDEVENTARGS_H

#include "Base.h"
#include "Kongkong.Events.EventArgs.h"
#include "Kongkong.Win32.UI.Size.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct SizeChangedEventArgs final : public ::KONGKONG_NAMESPACE::Events::EventArgs {

        constexpr SizeChangedEventArgs(Size const& newSize) noexcept : _newSize(newSize) {}
        constexpr SizeChangedEventArgs(double newWidth, double newHeight) noexcept : _newSize(newWidth, newHeight) {}

        [[nodiscard]]
        constexpr double NewHeight() const noexcept { return _newSize.Height(); }
        
        [[nodiscard]]
        constexpr Size const& NewSize() const noexcept { return _newSize; }

        [[nodiscard]]
        constexpr double NewWidth() const noexcept { return _newSize.Width(); }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        Size _newSize;
    };
}

#endif //!KONGKONG_WIN32_UI_SIZECHANGEDEVENTARGS_H
