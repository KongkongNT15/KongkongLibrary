#ifndef KONGKONG_COLLECTIONS_LINKEDLIST_H
#define KONGKONG_COLLECTIONS_LINKEDLIST_H

#include "Base.h"
#include "Kongkong.InvalidOperationException.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.LinkElement.h"
#include "Kongkong.Collections.List.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    struct LinkedList final : public List<T> {

        [[nodiscard]] Iterators::Iterator<T> begin() override { return Iterators::LinkedListIterator<T>(_list.begin()); }
        [[nodiscard]] Iterators::ConstIterator<T> begin() const override { return Iterators::ConstLinkedListIterator<T>(_list.begin()); }
        [[nodiscard]] Iterators::Iterator<T> end() override { return Iterators::LinkedListIterator<T>(_list.end()); }
        [[nodiscard]] Iterators::ConstIterator<T> end() const override { return Iterators::ConstLinkedListIterator<T>(_list.end()); }

        constexpr LinkedList() noexcept : _list() {}

        void Append(T const& value) override { _list.Append(value); }
        void Append(T&& value) override { _list.Append(std::move(value)); }

        /// @brief 手前に要素を追加
        /// @param value 追加する値
        /// @throws MemoryAllocationException: 要素を追加できなかったとき
        void AppendFront(T const& value) { _list.AppendFront(value); }

        /// @brief 手前に要素を追加
        /// @param value 追加する値
        /// @throws MemoryAllocationException: 要素を追加できなかったとき
        void AppendFront(T&& value) { _list.AppendFront(std::move(value)); }
        T& BackUnsafe() noexcept override { return _list.BackUnsafe(); }
        T const& cBackUnsafe() const noexcept override { return _list.BackUnsafe(); }
        void Clear() noexcept override { _list.Clear(); }
        bool Contains(T const& value) const noexcept override { return _list.Contains(value); }
        constexpr ssize_t Length() const noexcept override { return _list.Length(); }
        T& FrontUnsafe() noexcept override { return _list.FrontUnsafe(); }
        T const& cFrontUnsafe() const override { return _list.FrontUnsafe(); }

        /// @throws 指定した位置に要素を挿入
        /// @param iter 挿入する位置
        /// @param value 挿入する値
        /// @throws InvalidCastException: iterがLinkedListIterator<T>でなかったとき
        /// @throws MemoryAllocationException: 要素を追加できなかったとき
        void Insert(Iterators::Iterator<T> const& iter, T const& value)
        {
            Iterators::LinkedListIterator<T> lIter = iter.template Cast<Iterators::LinkedListIterator<T>>();

            auto& instance = Object::template GetInstanceUnsafe(lIter);

            _list.Insert(instance._iter, value);
        }

        /// @throws 指定した位置に要素を挿入
        /// @param iter 挿入する位置
        /// @param value 挿入する値
        /// @throws InvalidCastException: iterがLinkedListIterator<T>でなかったとき
        /// @throws MemoryAllocationException: 要素を追加できなかったとき
        void Insert(Iterators::Iterator<T> const& iter, T&& value)
        {
            Iterators::LinkedListIterator<T> lIter = iter.template Cast<Iterators::LinkedListIterator<T>>();

            auto& instance = Object::template GetInstanceUnsafe(lIter);

            _list.Insert(instance._iter, std::move(value));
        }

        /// @brief 指定した要素を削除
        /// @return 要素を削除すればtrue
        /// @return 指定した要素が見つからなければfalse
        [[nodiscard]]
        bool Remove(T const& value) noexcept override { return _list.Remove(value); }

        /// @brief 最後の要素を削除
        void RemoveBackUnsafe() noexcept override { _list.RemoveBackUnsafe(); }

        /// @brief 最初の要素を削除
        void RemoveFrontUnsafe() noexcept override { _list.RemoveFrontUnsafe(); }

        /// @brief 要素を逆順に入れ替え
        void Reverse() noexcept override { _list.Reverse(); }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const override { return u"Kongkong::Collections::LinkedList<T>"; }

    private:
        Turbo::FastLinkedList<T> _list;
    };

}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    class LinkedList final : public List<T> {
    public:
        using ImplType = IMPLEMENTATION::LinkedList<T>;

        /// @brief 空のリストを作成
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        LinkedList() : List<T>(nullptr) { Object::_setInstance(NEW ImplType()); }
        
        /// @brief nullptrとして作成
        constexpr LinkedList(std::nullptr_t) : List<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]]
        operator ICollection<T>() const { return Object::As<ICollection<T>>(); }

        [[nodiscard]]
        operator IIterable<T>() const { return Object::As<IIterable<T>>(); }

        [[nodiscard]]
        operator IReadOnlyCollection<T>() const { return Object::As<IReadOnlyCollection<T>>(); }

        [[nodiscard]]
        operator IReadOnlyIterable<T>() const { return Object::As<IReadOnlyIterable<T>>(); }
    };
}

#endif //!KONGKONG_COLLECTIONS_LINKEDLIST_H
