#ifndef KONGKONG_GRAPHICS_COLORF_H
#define KONGKONG_GRAPHICS_COLORF_H

#include "Base.h"
#include "Kongkong.ValueType.h"

#if KONGKONG_ENV_WINDOWS
    #include <d2d1.h>
#endif

namespace KONGKONG_NAMESPACE::Graphics
{
    struct ColorF : public ValueType {

        [[nodiscard]]
        static constexpr ColorF Black() noexcept { return ColorF(0.0F, 0.0F, 0.0F); }

        [[nodiscard]]
        static constexpr ColorF Blue() noexcept { return ColorF(0.0F, 0.0F, 1.0F); }

        [[nodiscard]]
        static constexpr ColorF Cyan() noexcept { return ColorF(0.0F, 1.0F, 1.0F); }

        [[nodiscard]]
        static constexpr ColorF Green() noexcept { return ColorF(0.0F, 1.0F, 0.0F); }

        [[nodiscard]]
        static constexpr ColorF Magenta() noexcept { return ColorF(1.0F, 1.0F, 0.0F); }

        [[nodiscard]]
        static constexpr ColorF Orange() noexcept { return ColorF(1.0F, 165.0F / 255.0F, 0.0F); }

        [[nodiscard]]
        static constexpr ColorF OrangeRed() noexcept { return ColorF(1.0F, 69.0F / 255.0F, 0.0F); }

        [[nodiscard]]
        static constexpr ColorF Pink() noexcept { return ColorF(1.0F, 192.0F / 255.0F, 203.0F / 255.0F); }

        [[nodiscard]]
        static constexpr ColorF Red() noexcept { return ColorF(1.0F, 0.0F, 0.0F); }

        [[nodiscard]]
        static constexpr ColorF Transparent() noexcept { return ColorF(0.0F, 0.0F, 0.0F, 0.0F); }

        [[nodiscard]]
        static constexpr ColorF White() noexcept { return ColorF(1.0F, 1.0F, 1.0F); }

        [[nodiscard]]
        static constexpr ColorF Yellow() noexcept { return ColorF(1.0F, 1.0F, 0.0F); }

        constexpr ColorF(float a, float r, float g, float b) noexcept : m_a(a), m_r(r), m_g(g), m_b(b) {}
        constexpr ColorF(float r, float g, float b) noexcept : ColorF(1.0F, r, g, b) {}

        [[nodiscard]]
        constexpr float A() const noexcept { return m_a; }

        constexpr void A(float value) noexcept { m_a = value; }

        [[nodiscard]]
        constexpr float R() const noexcept { return m_r; }

        constexpr void R(float value) noexcept { m_r = value; }

        [[nodiscard]]
        constexpr float G() const noexcept { return m_g; }

        constexpr void G(float value) noexcept { m_g = value; }

        [[nodiscard]]
        constexpr float B() const noexcept { return m_b; }

        constexpr void B(float value) noexcept { m_b = value; }

        constexpr void Clamp() noexcept
        {
            s_clamp(m_a);
            s_clamp(m_r);
            s_clamp(m_g);
            s_clamp(m_b);
        }

#if KONGKONG_ENV_WINDOWS
        [[nodiscard]]
        ::D2D1::ColorF ToDirectXColorF() const noexcept { return ::D2D1::ColorF(m_r, m_g, m_b, m_a); }
#endif

        [[nodiscard]]
        String ToString() const;

        private:

        float m_a;
        float m_r;
        float m_g;
        float m_b;

        static constexpr void s_clamp(float& v) noexcept
        {
            if (v < 0.0F) {
                v = 0.0F;
                return;
            }
            if (v > 1.0F) {
                v = 1.0F;
                return;
            }
        }
    };
}

#endif //!KONGKONG_GRAPHICS_COLORF_H