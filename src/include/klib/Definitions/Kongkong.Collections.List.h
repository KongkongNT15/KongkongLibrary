#ifndef KONGKONG_COLLECTIONS_LIST_H
#define KONGKONG_COLLECTIONS_LIST_H

#include "Base.h"
#include "Kongkong.Collections.ICollection.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    struct List : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object, virtual public ICollection<T> {

        List& operator+=(T const& value)
        {
            Append(value);
            return *this;
        }

        List& operator+=(T&& value)
        {
            Append(std::move(value));
            return *this;
        }

        List& operator-=(T const& value)
        {
            Remove(value);
            return *this;
        }

        // 要素を追加
        virtual void Append(T const& value) = 0;
        virtual void Append(T&& value) = 0;

        // 要素をすべて削除
        virtual void Clear() noexcept = 0;

        /// @brief 指定した要素を削除
        /// @return 要素を削除すればtrue
        /// @return 指定した要素が見つからなければfalse
        [[nodiscard]]
        virtual bool Remove(T const& value) = 0;

        /// @brief 最後の要素を削除
        /// @throws InvalidOperationException: コンテナが空のとき
        void RemoveBack()
        {
            CollectionHelper::CheckBackFront(this->Length());

            RemoveBackUnsafe();
        }

        /// @brief 最後の要素を削除
        virtual void RemoveBackUnsafe() noexcept = 0;

        /// @brief 最初の要素を削除
        /// @throws InvalidOperationException: コンテナが空のとき
        void RemoveFront()
        {
            CollectionHelper::CheckBackFront(this->Length());

            RemoveFrontUnsafe();
        }

        /// @brief 最初の要素を削除
        virtual void RemoveFrontUnsafe() noexcept = 0;

        /// @brief リストが空かを判定
        [[nodiscard]]
        bool IsEmpty() const noexcept { return this->Length() == 0; }

        [[nodiscard]]
        String ToString() const override { return u"Kongkong::Collections::List<T>"; }
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    class List : public Object {
        public:
        using ImplType = IMPLEMENTATION::List<T>;

        [[nodiscard]]
        operator ICollection<T>() const { return Object::As<ICollection<T>>(); }

        [[nodiscard]]
        operator IIterable<T>() const { return Object::As<IIterable<T>>(); }

        [[nodiscard]]
        operator IReadOnlyCollection<T>() const { return Object::As<IReadOnlyCollection<T>>(); }

        [[nodiscard]]
        operator IReadOnlyIterable<T>() const { return Object::As<IReadOnlyIterable<T>>(); }

        /// @brief nullptrとして作成
        constexpr List(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] Iterators::Iterator<T> begin() const { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] Iterators::Iterator<T> end() const { return _getPtr<ImplType>()->end(); }

        /// @brief 要素を追加
        /// @param value 追加する要素
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws MemoryAllocationException: 要素を追加できなかったとき
        List const& operator+=(T const& value) const
        {
            Object::_getPtr<ImplType>()->operator+=(value);
            return *this;
        }

        /// @brief 要素を追加
        /// @param value 追加する要素
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws MemoryAllocationException: 要素を追加できなかったとき
        List const& operator+=(T&& value) const
        {
            Object::_getPtr<ImplType>()->operator+=(std::move(value));
            return *this;
        }

        /// @brief 指定した要素を削除
        /// @attention 指定した要素が見つからない場合は何もしないよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        List const& operator-=(T const& value) const
        {
            Object::_getPtr<ImplType>()->operator-=(value);
            return *this;
        }
        
    };
}

#endif //!KONGKONG_COLLECTIONS_LIST_H
