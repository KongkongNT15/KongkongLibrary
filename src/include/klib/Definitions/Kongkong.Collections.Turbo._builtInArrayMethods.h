#ifndef KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _builtInArrayMethods {

        [[nodiscard]]
        constexpr bool IsEmpty() const noexcept { return false; }

        [[nodiscard]]
        String ToString() const;

        private:
        _builtInArrayMethods() = default;
        _builtInArrayMethods(_builtInArrayMethods const&) = default;
        _builtInArrayMethods(_builtInArrayMethods&&) = default;

        _builtInArrayMethods& operator=(_builtInArrayMethods const&) = default;
        _builtInArrayMethods& operator=(_builtInArrayMethods&&) = default;

        template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
        friend struct BuiltInArray;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYMETHODS_H
