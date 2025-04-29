#ifndef KONGKONG_COLLECTIONS_TURBO_FASTPOINTERARRAYITERATOR_H
#define KONGKONG_COLLECTIONS_TURBO_FASTPOINTERARRAYITERATOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo._fastPointerArrayIteratorMethods.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastPointerArrayIterator final : public ValueType, public _fastPointerArrayIteratorMethods {
        using PointerType = T**;

        [[nodiscard]] friend constexpr bool operator==(FastPointerArrayIterator const& left, FastPointerArrayIterator const& right) noexcept { return left._p == right._p; }
        [[nodiscard]] friend constexpr bool operator!=(FastPointerArrayIterator const& left, FastPointerArrayIterator const& right) noexcept { return left._p != right._p; }

        [[nodiscard]] constexpr T& operator*() noexcept { return *(*_p); }
        [[nodiscard]] constexpr T const& operator*() const noexcept { return *(*_p); }

        constexpr FastPointerArrayIterator& operator++() noexcept
        {
            ++_p;
            return *this;
        }

        constexpr FastPointerArrayIterator& operator++(int) noexcept
        {
            FastPointerArrayIterator iter = *this;
            ++_p;
            return iter;
        }

        private:
        PointerType _p;

        constexpr FastPointerArrayIterator(PointerType p) noexcept : _p(p) {}

        friend FastPointerList<T>;
    };
    
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTPOINTERARRAYITERATOR_H
