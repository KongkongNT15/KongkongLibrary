#ifndef KONGKONG_GRAPHICS_FONTWEIGHT_H
#define KONGKONG_GRAPHICS_FONTWEIGHT_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Graphics
{
    struct FontWeight final : public ValueType {

        [[nodiscard]]
        static constexpr FontWeight Thin() noexcept { return 100; }

        [[nodiscard]]
        static constexpr FontWeight ExtraLight() noexcept { return 200; }

        [[nodiscard]]
        static constexpr FontWeight UltraLight() noexcept { return 200; }

        [[nodiscard]]
        static constexpr FontWeight Light() noexcept { return 300; }

        [[nodiscard]]
        static constexpr FontWeight SemiLight() noexcept { return 350; }

        [[nodiscard]]
        static constexpr FontWeight Normal() noexcept { return 400; }

        [[nodiscard]]
        static constexpr FontWeight Regular() noexcept { return 400; }

        [[nodiscard]]
        static constexpr FontWeight Medium() noexcept { return 500; }

        [[nodiscard]]
        static constexpr FontWeight DemiBold() noexcept { return 600; }

        [[nodiscard]]
        static constexpr FontWeight SemiBold() noexcept { return 600; }

        [[nodiscard]]
        static constexpr FontWeight Bold() noexcept { return 700; }

        [[nodiscard]]
        static constexpr FontWeight ExtraBold() noexcept { return 800; }

        [[nodiscard]]
        static constexpr FontWeight UltraBold() noexcept { return 800; }

        [[nodiscard]]
        static constexpr FontWeight Black() noexcept { return 900; }

        [[nodiscard]]
        static constexpr FontWeight Heavy() noexcept { return 900; }

        [[nodiscard]]
        static constexpr FontWeight ExtraBlack() noexcept { return 950; }

        [[nodiscard]]
        static constexpr FontWeight UltraBlack() noexcept { return 950; }

        [[nodiscard]]
        String ToString() const;

        [[nodiscard]]
        constexpr uint32_t Weight() const noexcept { return m_weight; }

        private:

        constexpr FontWeight(int weight) noexcept : m_weight((uint8_t)weight) {}

        uint16_t m_weight;

        friend constexpr bool operator==(FontWeight const&, FontWeight const&) noexcept;
        friend constexpr bool operator!=(FontWeight const&, FontWeight const&) noexcept;
        friend constexpr bool operator<(FontWeight const&, FontWeight const&) noexcept;
        friend constexpr bool operator<=(FontWeight const&, FontWeight const&) noexcept;
        friend constexpr bool operator>(FontWeight const&, FontWeight const&) noexcept;
        friend constexpr bool operator>=(FontWeight const&, FontWeight const&) noexcept;
        friend constexpr ::std::strong_ordering operator<=>(FontWeight const&, FontWeight const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(FontWeight const& left, FontWeight const& right) noexcept { return left.m_weight == right.m_weight; }
    [[nodiscard]] constexpr bool operator!=(FontWeight const& left, FontWeight const& right) noexcept { return left.m_weight != right.m_weight; }
    [[nodiscard]] constexpr bool operator<(FontWeight const& left, FontWeight const& right) noexcept { return left.m_weight < right.m_weight; }
    [[nodiscard]] constexpr bool operator<=(FontWeight const& left, FontWeight const& right) noexcept { return left.m_weight <= right.m_weight; }
    [[nodiscard]] constexpr bool operator>(FontWeight const& left, FontWeight const& right) noexcept { return left.m_weight > right.m_weight; }
    [[nodiscard]] constexpr bool operator>=(FontWeight const& left, FontWeight const& right) noexcept { return left.m_weight >= right.m_weight; }
    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(FontWeight const& left, FontWeight const& right) noexcept { return left.m_weight <=> right.m_weight; }
}

#endif //!KONGKONG_GRAPHICS_FONTWEIGHT_H