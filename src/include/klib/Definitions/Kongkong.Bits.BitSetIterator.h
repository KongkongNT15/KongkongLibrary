#ifndef KONGKONG_BITS_BITSETELEMENTITERATOR_H
#define KONGKONG_BITS_BITSETELEMENTITERATOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Bits.BitSetElement.h"
#include "Kongkong.Bits._bitSetIteratorBase.h"

namespace KONGKONG_NAMESPACE::Bits
{
    struct BitSetIterator final : public ValueType, public _bitSetIteratorBase {

        BitSetIterator(BitSetIterator const&) = default;
        BitSetIterator(BitSetIterator&&) = default;

        BitSetIterator& operator=(BitSetIterator const&) = default;
        BitSetIterator& operator=(BitSetIterator&&) = default;

        [[nodiscard]]
        BitSetElement operator*() const noexcept { return BitSetElement(*(_p + (_index / 8)), _index % 8); }

        constexpr BitSetIterator& operator++() noexcept { ++_index; return *this; }

        constexpr BitSetIterator operator++(int) noexcept
        {
            BitSetIterator ret = *this;
            ++_index;

            return ret;
        }

        [[nodiscard]]
        String ToString() const;

        private:

        constexpr BitSetIterator(uint8_t* p, ssize_t index) noexcept : _bitSetIteratorBase(p, index) {}

        template <ssize_t N> requires (N >= 1)
        friend struct BitSet;
    };
}

#endif //!KONGKONG_BITS_BITSETELEMENTITERATOR_H
