#ifndef KONGKONG_GRAPHICS_COLOR_H
#define KONGKONG_GRAPHICS_COLOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"

#ifdef KONGKONG_ENV_WINDOWS
    #include <d2d1.h>
#endif

namespace KONGKONG_NAMESPACE::Graphics
{
    template <NumberType TNum>
    struct t_Color : public ValueType {

        constexpr t_Color(TNum a, TNum r, TNum g, TNum b) noexcept : m_a(a), m_r(r), m_g(g), m_b(b) {}
        //constexpr t_Color(uint8_t r, uint8_t g, uint8_t b) noexcept : Color(0xFF, r, g, b) {}

        [[nodiscard]]
        constexpr TNum A() const noexcept { return m_a; }

        constexpr void A(TNum value) noexcept { m_a = value; }

        [[nodiscard]]
        constexpr TNum R() const noexcept { return m_r; }

        constexpr void R(TNum value) noexcept { m_r = value; }

        [[nodiscard]]
        constexpr TNum G() const noexcept { return m_g; }

        constexpr void G(TNum value) noexcept { m_g = value; }

        [[nodiscard]]
        constexpr TNum B() const noexcept { return m_b; }

        constexpr void B(TNum value) noexcept { m_b = value; }

        template <NumberType UNum>
        constexpr t_Color<UNum> As() const noexcept { return t_Color<UNum>((UNum)m_a, (UNum)m_r, (UNum)m_g, (UNum)m_b); }

#ifdef KONGKONG_ENV_WINDOWS
        [[nodiscard]]
        ::D2D1::ColorF ToDirectXColorF() const noexcept { return ::D2D1::ColorF((float)m_r, (float)m_g, (float)m_b, (float)m_a); }
#endif

        private:

        TNum m_a;
        TNum m_r;
        TNum m_g;
        TNum m_b;
    };
}

#endif //!KONGKONG_GRAPHICS_COLOR_H