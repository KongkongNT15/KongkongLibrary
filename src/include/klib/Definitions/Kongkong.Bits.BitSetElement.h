#ifndef KONGKONG_BITS_BITSETELEMENT_H
#define KONGKONG_BITS_BITSETELEMENT_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Bits
{
    struct BitSetElement final : public ValueType {

        constexpr BitSetElement(uint8_t& target, uint8_t index) : _value(target), _index(index) {}
        BitSetElement(BitSetElement const&) = delete;

        BitSetElement& operator=(BitSetElement const&) = delete;

        [[nodiscard]]
        constexpr operator bool() const noexcept { return (bool)(_value & (1 << _index)); }

        BitSetElement& operator=(bool value) noexcept;
        BitSetElement& operator~() noexcept;

        /// @brief 値の文字列表現
        [[nodiscard]]
        String ToString() const;

        private:
        uint8_t& _value;
        uint8_t _index;
    };

}

#endif //!KONGKONG_BITS_BITSETELEMENT_H
