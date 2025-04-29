#ifndef KONGKONG_WIN32_UI_THICKNESS_H
#define KONGKONG_WIN32_UI_THICKNESS_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct Thickness final : public ValueType {

        constexpr Thickness() noexcept : Thickness(0, 0, 0, 0) {}
        constexpr Thickness(double x, double y) noexcept : Thickness(x, y, x, y) {}
        constexpr Thickness(double left, double top, double right, double bottom) noexcept : _left(left), _top(top), _right(right), _bottom(bottom) {}

        [[nodiscard]]
        constexpr double Left() const noexcept { return _left; }

        constexpr void Left(double value) noexcept { _left = value; }

        [[nodiscard]]
        constexpr double Top() const noexcept { return _top; }

        constexpr void Top(double value) noexcept { _top = value; }

        [[nodiscard]]
        constexpr double Right() const noexcept { return _right; }

        constexpr void Right(double value) noexcept { _right = value; }

        [[nodiscard]]
        constexpr double Bottom() const noexcept { return _bottom; }

        constexpr void Bottom(double value) noexcept { _bottom = value; }

        [[nodiscard]]
        String ToString() const;

        private:
        double _left;
        double _top;
        double _right;
        double _bottom;
    };
}

#endif //!KONGKONG_WIN32_UI_THICKNESS_H
