#ifndef KONGKONG_COLLECTIONS_TURBO_CONSTFASTPOINTERARRAYITERATOR_H
#define KONGKONG_COLLECTIONS_TURBO_CONSTFASTPOINTERARRAYITERATOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo._constFastPointerArrayIteratorMethods.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct ConstFastPointerArrayIterator final : public ValueType, public _constFastPointerArrayIteratorMethods {
        using ElementType = const T*;
        using PointerType = ElementType*;

        friend constexpr bool operator==(ConstFastPointerArrayIterator const& left, ConstFastPointerArrayIterator const& right) noexcept { return left._p == right._p; }
        friend constexpr bool operator!=(ConstFastPointerArrayIterator const& left, ConstFastPointerArrayIterator const& right) noexcept { return left._p != right._p; }

        [[nodiscard]] constexpr T const& operator*() const noexcept { return *(*_p); }

        constexpr ConstFastPointerArrayIterator& operator++() noexcept
        {
            ++_p;
            return *this;
        }

        constexpr ConstFastPointerArrayIterator& operator++(int) noexcept
        {
            ConstFastPointerArrayIterator iter = *this;
            ++_p;
            return iter;
        }

        private:
        PointerType _p;

        constexpr ConstFastPointerArrayIterator(PointerType p) noexcept : _p(p) {}

        friend FastPointerList<T>;
    };
    
}

#endif //!KONGKONG_COLLECTIONS_TURBO_CONSTFASTPOINTERARRAYITERATOR_H
