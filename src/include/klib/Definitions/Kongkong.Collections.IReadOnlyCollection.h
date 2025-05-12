#ifndef KONGKONG_COLLECTIONS_IREADONLYCOLLECTION_H
#define KONGKONG_COLLECTIONS_IREADONLYCOLLECTION_H

#include "Base.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.Collections.IReadOnlyIterable.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    KONGKONG_INTERFACE IReadOnlyCollection : virtual public IReadOnlyIterable<T> {
        /// @brief 要素数
        [[nodiscard]]
        virtual ssize_t Length() const noexcept { return -1; }

        /// @brief 指定した値が含まれるかを判定
        [[nodiscard]]
        virtual bool Contains(T const& value) const noexcept = 0;

        /// @brief 最後の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T const& Back() const
        {
            CollectionHelper::CheckBackFront(Length());
            return BackUnsafe();
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        virtual T const& BackUnsafe() const noexcept = 0;

        /// @brief 最初の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T const& Front() const
        {
            CollectionHelper::CheckBackFront(Length());
            return FrontUnsafe();
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        virtual T const& FrontUnsafe() const noexcept = 0;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    KONGKONG_INTERFACE IReadOnlyCollection final : public Interface {
        public:
        using ImplType = IMPLEMENTATION::IReadOnlyCollection<T>;

        [[nodiscard]]
        operator IReadOnlyIterable<T>() const { return Object::As<IReadOnlyIterable<T>>(); }

        /// @brief nullptrとして作成
        constexpr IReadOnlyCollection(std::nullptr_t) noexcept : Interface(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] Iterators::ConstIterator<T> begin() const { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] Iterators::ConstIterator<T> end() const { return _getPtr<ImplType>()->end(); }
    };
}

#endif //!KONGKONG_COLLECTIONS_IREADONLYCOLLECTION_H
