#ifndef KONGKONG_BITS_CONSTBITSETELEMENTITERATOR_H
#define KONGKONG_BITS_CONSTBITSETELEMENTITERATOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Bits.BitSetElement.h"
#include "Kongkong.Bits._bitSetIteratorBase.h"

namespace KONGKONG_NAMESPACE::Bits
{
    struct ConstBitSetIterator final : public ValueType, public _bitSetIteratorBase {

        
        ConstBitSetIterator(ConstBitSetIterator const&) = default;
        ConstBitSetIterator(ConstBitSetIterator&&) = default;

        ConstBitSetIterator& operator=(ConstBitSetIterator const&) = default;
        ConstBitSetIterator& operator=(ConstBitSetIterator&&) = default;

        [[nodiscard]]
        bool operator*() const noexcept { return (bool)BitSetElement(*(_p + (_index / 8)), _index % 8); }

        constexpr ConstBitSetIterator& operator++() noexcept { ++_index; return *this; }

        constexpr ConstBitSetIterator operator++(int) noexcept
        {
            ConstBitSetIterator ret = *this;
            ++_index;

            return ret;
        }

        [[nodiscard]]
        String ToString() const;

        private:

        constexpr ConstBitSetIterator(uint8_t* p, ssize_t index) noexcept : _bitSetIteratorBase(p, index) {}

        template <ssize_t N> requires (N >= 1)
        friend struct BitSet;
    };
}

#endif //!KONGKONG_BITS_CONSTBITSETELEMENTITERATOR_H
