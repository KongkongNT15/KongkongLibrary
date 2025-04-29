#ifndef KONGKONG_WIN32_UI_RECT_H
#define KONGKONG_WIN32_UI_RECT_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct Rect final : public ValueType {

        constexpr Rect() noexcept : _rect() {}

        constexpr Rect(int32_t left, int32_t top, int32_t right, int32_t bottom) noexcept : _rect({ left, top, right, bottom }) {}

        constexpr Rect(::RECT const& rect) noexcept : _rect(rect) {}

        constexpr operator ::RECT() const noexcept { return _rect; }

        constexpr Rect& operator=(::RECT const& rect) noexcept { _rect = rect; return *this; }

        [[nodiscard]]
        constexpr int32_t Left() const noexcept { return _rect.left; }

        constexpr void Left(int32_t value) noexcept { _rect.left = value; }

        [[nodiscard]]
        constexpr int32_t Top() const noexcept { return _rect.top; }

        constexpr void Top(int32_t value) noexcept { _rect.top = value; }

        [[nodiscard]]
        constexpr int32_t Right() const noexcept { return _rect.right; }

        constexpr void Right(int32_t value) noexcept { _rect.right = value; }

        [[nodiscard]]
        constexpr int32_t Bottom() const noexcept { return _rect.bottom; }

        constexpr void Bottom(int32_t value) noexcept { _rect.bottom = value; }

        [[nodiscard]]
        String ToString() const;

        private:
        ::RECT _rect;

        friend IMPLEMENTATION::UIElement;
    };
}

#endif //!KONGKONG_WIN32_UI_RECT_H
