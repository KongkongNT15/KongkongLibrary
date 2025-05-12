#ifndef KONGKONG_COLLECTIONS_IREADONLYARRAY_H
#define KONGKONG_COLLECTIONS_IREADONLYARRAY_H

#include "Base.h"
#include "Kongkong.ArgumentOutOfRangeException.h"
#include "Kongkong.InvalidArgumentException.h"
#include "Kongkong.Collections.IReadOnlyCollection.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    KONGKONG_INTERFACE IReadOnlyArray : public IReadOnlyCollection<T> {

        /// @brief 指定した要素の番号を取得
        /// @param value 値
        /// @return 要素番号、要素が見つからなかった場合はCollectionHelper::NotFound()
        [[nodiscard]]
        virtual ssize_t IndexOf(T const& value) const noexcept = 0;

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]]
        virtual T const& operator[](ssize_t index) const noexcept = 0;

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        [[nodiscard]]
        virtual T const& At(ssize_t index) const = 0;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    KONGKONG_INTERFACE IReadOnlyArray final : public Interface {
        public:
        using ImplType = IMPLEMENTATION::IReadOnlyArray<T>;

        [[nodiscard]]
        operator IReadOnlyCollection<T>() const { return Object::As<IReadOnlyCollection<T>>(); }

        [[nodiscard]]
        operator IReadOnlyIterable<T>() const { return Object::As<IReadOnlyIterable<T>>(); }

        /// @brief nullptrとして作成
        constexpr IReadOnlyArray(std::nullptr_t) noexcept : Interface(nullptr) {}
        
        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] Iterators::ConstIterator<T> begin() const { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] Iterators::ConstIterator<T> end() const { return _getPtr<ImplType>()->end(); }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        T& operator[](ssize_t index) const { return Object::_getRef<ImplType>().operator[](index); }
    };
}

#endif //!KONGKONG_COLLECTIONS_IREADONLYARRAY_H
