#ifndef KONGKONG_COLLECTIONS_IARRAY_H
#define KONGKONG_COLLECTIONS_IARRAY_H

#include "Base.h"
#include "Kongkong.Collections.ICollection.h"
#include "Kongkong.Collections.IReadOnlyArray.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    INTERFACE IArray : public IReadOnlyArray<T>, virtual public ICollection<T> {

        constexpr ssize_t Length() const noexcept override { return -1; }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        virtual T& operator[](ssize_t index) noexcept = 0;

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        virtual T& At(ssize_t index) = 0;

    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    /// @brief 配列の機能を持つインターフェース
    /// @tparam T 要素の型
    template <class T>
    INTERFACE IArray final : public Interface {
        public:
        using ImplType = IMPLEMENTATION::IArray<T>;

        [[nodiscard]]
        operator ICollection<T>() const { return Object::As<ICollection<T>>(); }

        [[nodiscard]]
        operator IIterable<T>() const { return Object::As<IIterable<T>>(); }

        [[nodiscard]]
        operator IReadOnlyArray<T>() const { return Object::As<IReadOnlyArray<T>>(); }

        [[nodiscard]]
        operator IReadOnlyCollection<T>() const { return Object::As<IReadOnlyCollection<T>>(); }

        [[nodiscard]]
        operator IReadOnlyIterable<T>() const { return Object::As<IReadOnlyIterable<T>>(); }
        
        /// @brief nullptrとして作成
        constexpr IArray(std::nullptr_t) noexcept : Interface(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] Iterators::Iterator<T> begin() const { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] Iterators::Iterator<T> end() const { return _getPtr<ImplType>()->end(); }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        T& operator[](ssize_t index) const { return Object::_getRef<ImplType>().operator[](index); }
    };
}

#endif //!KONGKONG_COLLECTIONS_IARRAY_H
