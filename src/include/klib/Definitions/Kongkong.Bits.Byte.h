#ifndef KONGKONG_BITS_BYTE_H
#define KONGKONG_BITS_BYTE_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Bits
{
    struct Byte final : public ValueType {

        [[nodiscard]]
        static constexpr Byte MaxValue() noexcept { return Byte(255u); }

        [[nodiscard]]
        static constexpr Byte MinValue() noexcept { return Byte(0); }

        friend constexpr bool operator==(Byte const& left, Byte const& right) noexcept { return left._value == right._value; }
        friend constexpr bool operator!=(Byte const& left, Byte const& right) noexcept { return left._value != right._value; }
        friend constexpr bool operator<(Byte const& left, Byte const& right) noexcept { return left._value < right._value; }
        friend constexpr bool operator<=(Byte const& left, Byte const& right) noexcept { return left._value <= right._value; }
        friend constexpr bool operator>(Byte const& left, Byte const& right) noexcept { return left._value > right._value; }
        friend constexpr bool operator>=(Byte const& left, Byte const& right) noexcept { return left._value >= right._value; }
        friend constexpr std::strong_ordering operator<=>(Byte const& left, Byte const& right) { return left._value <=> right._value; }

        constexpr Byte() noexcept : _value() {}
        constexpr Byte(uint8_t value) noexcept : _value(value) {}

        constexpr operator uint8_t() const noexcept { return _value; }
        constexpr Byte& operator=(uint8_t value) noexcept
        {
            _value = value;
            return *this;
        }

        String ToString() const;

        constexpr void Value(uint8_t value) noexcept { _value = value; }

        [[nodiscard]]
        constexpr uint8_t Value() const noexcept { return _value; }

        private:
        uint8_t _value;

    };
}

#endif //!KONGKONG_BITS_BYTE_H
