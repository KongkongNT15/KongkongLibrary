#ifndef KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYBASE_H
#define KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYBASE_H

#include "Base.h"
#include "Kongkong.Algorithms.Range.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
    struct _builtInArrayBase {

        [[nodiscard]] constexpr T& operator[](ssize_t index) noexcept { return Data()[index]; }
        [[nodiscard]] constexpr T const& operator[](ssize_t index) const noexcept { return Data()[index]; }

        [[nodiscard]] constexpr T* begin() noexcept { return Data(); }
        [[nodiscard]] constexpr const T* begin() const noexcept { return Data(); }

        /// @brief 容量
        [[nodiscard]]
        constexpr ssize_t Capacity() const noexcept { return N; }

        [[nodiscard]] constexpr T* Data() noexcept { return (T*)((void*)_arr); }
        [[nodiscard]] constexpr const T* Data() const noexcept { return (const T*)((const void*)_arr); }

        private:
        uint8_t _arr[sizeof(T) * N];

        _builtInArrayBase() = default;
        _builtInArrayBase(_builtInArrayBase const&) = default;
        _builtInArrayBase(_builtInArrayBase&&) = default;

        _builtInArrayBase& operator=(_builtInArrayBase const&) = default;
        _builtInArrayBase& operator=(_builtInArrayBase&&) = default;

        friend BuiltInArray<T, N>;

        friend BuiltInArrayList<T, N>;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYBASE_H
