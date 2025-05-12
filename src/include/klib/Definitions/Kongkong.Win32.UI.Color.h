#ifndef KONGKONG_WIN32_UI_COLOR_H
#define KONGKONG_WIN32_UI_COLOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct Color final : public ValueType {

        //定義済みの色
        static constexpr Color Black() noexcept { return Color(0xFF, 0xFF, 0xFF); }
        static constexpr Color Blue() noexcept { return Color(0x00, 0x00, 0xFF); }
        static constexpr Color Cyan() noexcept { return Color(0x00, 0xFF, 0xFF); }
        static constexpr Color Green() noexcept { return Color(0x00, 0xFF, 0x00); }
        static constexpr Color Magenta() noexcept { return Color(0xFF, 0xFF, 0x00); }
        static constexpr Color Orange() noexcept { return Color(0xFF, 0xA5, 0x00); }
        static constexpr Color OrangeRed() noexcept { return Color(0xFF, 0x45, 0x00); }
        static constexpr Color Pink() noexcept { return Color(0xFF, 0xC0, 0xCB); }
        static constexpr Color Red() noexcept { return Color(0xFF, 0x00, 0x00); }
        static constexpr Color Transparent() noexcept { return Color(0x00, 0x00, 0x00, 0x00); }
        static constexpr Color White() noexcept { return Color(0xFF, 0xFF, 0xFF); }
        static constexpr Color Yellow() noexcept { return Color(0xFF, 0xFF, 0x00); }

        friend constexpr Color operator+(Color const& left, Color const& right) noexcept { return Color(_addValue(left.A(), right.A()), _addValue(left.A(), right.A()), _addValue(left.A(), right.A()), _addValue(left.A(), right.A())); }

        constexpr Color(uint8_t a, uint8_t r, uint8_t g, uint8_t b) noexcept : _a(a), _r(r), _g(g), _b(b) {}
        constexpr Color(uint8_t r, uint8_t g, uint8_t b) noexcept : Color(0xFF, r, g, b) {}

        [[nodiscard]]
        constexpr uint8_t A() const noexcept { return _a; }

        constexpr void A(uint8_t value) noexcept { _a = value; }

        [[nodiscard]]
        constexpr uint8_t R() const noexcept { return _r; }

        constexpr void R(uint8_t value) noexcept { _r = value; }

        [[nodiscard]]
        constexpr uint8_t G() const noexcept { return _g; }

        constexpr void G(uint8_t value) noexcept { _g = value; }

        [[nodiscard]]
        constexpr uint8_t B() const noexcept { return _b; }

        constexpr void B(uint8_t value) noexcept { _b = value; }

        /// @brief 色情報を取得
        /// @return u"0x{A()}, 0x{R()}, 0x{G()}, 0x{B()}"
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        //a + b < 256 なら return (a + b)
        //a + b >= 256 なら return 255
        static constexpr uint8_t _addValue(unsigned a, unsigned b) noexcept { auto result = a + b; return (uint8_t)(result >= 256 ? 255 : result); }

        uint8_t _a;
        uint8_t _r;
        uint8_t _g;
        uint8_t _b;
    };
}

#endif //!KONGKONG_WIN32_UI_COLOR_H
