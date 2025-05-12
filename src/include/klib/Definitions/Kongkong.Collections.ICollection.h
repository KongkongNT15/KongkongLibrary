#ifndef KONGKONG_COLLECTIONS_ICOLLECTION_H
#define KONGKONG_COLLECTIONS_ICOLLECTION_H

#include "Base.h"
#include "Kongkong.Collections.IReadOnlyCollection.h"
#include "Kongkong.Collections.IIterable.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    KONGKONG_INTERFACE ICollection : public IReadOnlyCollection<T>, public IIterable<T> {
        
        /// @brief 最後の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T& Back()
        {
            CollectionHelper::CheckBackFront(IReadOnlyCollection<T>::Length());
            return BackUnsafe();
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        virtual T& BackUnsafe() noexcept = 0;

        /// @brief 最初の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T& Front()
        {
            CollectionHelper::CheckBackFront(IReadOnlyCollection<T>::Length());
            return FrontUnsafe();
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        virtual T& FrontUnsafe() noexcept = 0;

        /// @brief 要素を逆順に入れ替え
        virtual void Reverse() noexcept = 0;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    KONGKONG_INTERFACE ICollection final : public Interface {
        public:
        using ImplType = IMPLEMENTATION::ICollection<T>;

        [[nodiscard]]
        operator IIterable<T>() const { return Object::As<IIterable<T>>(); }

        [[nodiscard]]
        operator IReadOnlyCollection<T>() const { return Object::As<IReadOnlyCollection<T>>(); }

        [[nodiscard]]
        operator IReadOnlyIterable<T>() const { return Object::As<IReadOnlyIterable<T>>(); }

        /// @brief nullptrとして作成
        constexpr ICollection(std::nullptr_t) noexcept : Interface(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] Iterators::Iterator<T> begin() const { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] Iterators::Iterator<T> end() const { return _getPtr<ImplType>()->end(); }
    };
}

#endif //!KONGKONG_COLLECTIONS_ICOLLECTION_H
