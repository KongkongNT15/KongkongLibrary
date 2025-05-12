#ifndef KONGKONG_BITS_BITSETELEMENTITERATORBASE_H
#define KONGKONG_BITS_BITSETELEMENTITERATORBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Bits
{
    struct _bitSetIteratorBase {

        private:
        uint8_t* _p;
        ssize_t _index;

        constexpr _bitSetIteratorBase(uint8_t* p, ssize_t index) noexcept : _p(p), _index(index) {}

        _bitSetIteratorBase(_bitSetIteratorBase const&) = default;
        _bitSetIteratorBase(_bitSetIteratorBase&&) = default;
        _bitSetIteratorBase& operator=(_bitSetIteratorBase const&) = default;
        _bitSetIteratorBase& operator=(_bitSetIteratorBase&&) = default;

        friend BitSetIterator;
        friend ConstBitSetIterator;

        friend constexpr bool operator==(_bitSetIteratorBase const&, _bitSetIteratorBase const&) noexcept;
        friend constexpr bool operator!=(_bitSetIteratorBase const&, _bitSetIteratorBase const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(_bitSetIteratorBase const& left, _bitSetIteratorBase const& right) noexcept { return left._index == right._index && left._p == right._p; }
    [[nodiscard]] constexpr bool operator!=(_bitSetIteratorBase const& left, _bitSetIteratorBase const& right) noexcept { return left._index != right._index || left._p != right._p; }
}

#endif //!KONGKONG_BITS_BITSETELEMENTITERATORBASE_H
