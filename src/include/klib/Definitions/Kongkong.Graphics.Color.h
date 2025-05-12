#ifndef KONGKONG_GRAPHICS_COLOR_H
#define KONGKONG_GRAPHICS_COLOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Graphics
{
    struct Color : public ValueType {

        [[nodiscard]]
        static constexpr Color Black() noexcept { return Color(0xFF, 0xFF, 0xFF); }

        [[nodiscard]]
        static constexpr Color Blue() noexcept { return Color(0x00, 0x00, 0xFF); }

        [[nodiscard]]
        static constexpr Color Cyan() noexcept { return Color(0x00, 0xFF, 0xFF); }

        [[nodiscard]]
        static constexpr Color Green() noexcept { return Color(0x00, 0xFF, 0x00); }

        [[nodiscard]]
        static constexpr Color Magenta() noexcept { return Color(0xFF, 0xFF, 0x00); }

        [[nodiscard]]
        static constexpr Color Orange() noexcept { return Color(0xFF, 0xA5, 0x00); }

        [[nodiscard]]
        static constexpr Color OrangeRed() noexcept { return Color(0xFF, 0x45, 0x00); }

        [[nodiscard]]
        static constexpr Color Pink() noexcept { return Color(0xFF, 0xC0, 0xCB); }

        [[nodiscard]]
        static constexpr Color Red() noexcept { return Color(0xFF, 0x00, 0x00); }

        [[nodiscard]]
        static constexpr Color Transparent() noexcept { return Color(0x00, 0x00, 0x00, 0x00); }

        [[nodiscard]]
        static constexpr Color White() noexcept { return Color(0xFF, 0xFF, 0xFF); }

        [[nodiscard]]
        static constexpr Color Yellow() noexcept { return Color(0xFF, 0xFF, 0x00); }

        constexpr Color(uint8_t a, uint8_t r, uint8_t g, uint8_t b) noexcept : m_a(a), m_r(r), m_g(g), m_b(b) {}
        constexpr Color(uint8_t r, uint8_t g, uint8_t b) noexcept : Color(0xFF, r, g, b) {}

        [[nodiscard]]
        constexpr uint8_t A() const noexcept { return m_a; }

        constexpr void A(uint8_t value) noexcept { m_a = value; }

        [[nodiscard]]
        constexpr uint8_t R() const noexcept { return m_r; }

        constexpr void R(uint8_t value) noexcept { m_r = value; }

        [[nodiscard]]
        constexpr uint8_t G() const noexcept { return m_g; }

        constexpr void G(uint8_t value) noexcept { m_g = value; }

        [[nodiscard]]
        constexpr uint8_t B() const noexcept { return m_b; }

        constexpr void B(uint8_t value) noexcept { m_b = value; }

        [[nodiscard]]
        String ToString() const;

        private:

        uint8_t m_a;
        uint8_t m_r;
        uint8_t m_g;
        uint8_t m_b;
    };
}

#endif //!KONGKONG_GRAPHICS_COLOR_H