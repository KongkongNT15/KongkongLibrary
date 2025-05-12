#ifndef KONGKONG_COLLECTIONS_OBSERVABLEARRAYLIST_H
#define KONGKONG_COLLECTIONS_OBSERVABLEARRAYLIST_H

#include "Base.h"
#include "Kongkong.Collections.ArrayList.h"
#include "Kongkong.Events.EventHandler.h"
#include "Kongkong.Collections.CollectionChange.h"
#include "Kongkong.Collections.ArrayChangingEventArgs.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{ 
    template <class T>
    struct ObservableArrayList final : public ArrayList<T> {
        using Base = ArrayList<T>;
        using ProjType = ::KONGKONG_NAMESPACE::Collections::ObservableArrayList<T>;

        ObservableArrayList() = default;

        // 初期化リストから作成
        ObservableArrayList(std::initializer_list<T> const& inil) : ArrayList<T>(inil) {}

        ObservableArrayList(ObservableArrayList const&) = delete;
        ObservableArrayList(ObservableArrayList&&) = delete;

        ObservableArrayList& operator=(ObservableArrayList const&) = delete;
        ObservableArrayList& operator=(ObservableArrayList&&) = delete;

        /// @brief 要素を追加
        /// @param value 追加する値
        /// @throws MemoryAllocationException: 要素を追加できなかったとき
        void Append(T const& value) override;

        /// @brief 要素を追加
        /// @param value 追加する値
        /// @throws MemoryAllocationException: 要素を追加できなかったとき
        void Append(T&& value) override;

        [[nodiscard]]
        constexpr auto& ArrayChanging() noexcept { return _arrayChanging.List(); }

        // 要素をすべて削除
        void Clear() noexcept override;

        /// @brief 指定した位置に要素を挿入
        /// @param index 挿入する位置
        /// @param value 挿入する値
        /// @throws ArgumentOutOfRangeException: 位置が範囲外のとき
        void Insert(ssize_t index, T const& value) override;

        /// @brief 指定した位置に要素を挿入
        /// @param index 挿入する位置
        /// @param value 挿入する値
        /// @throws ArgumentOutOfRangeException: 位置が範囲外のとき
        void Insert(ssize_t index, T&& value) override;

        /// @brief 指定した要素を削除
        /// @return 要素を削除すればtrue
        /// @return 指定した要素が見つからなければfalse
        bool Remove(T const& value) noexcept override;

        /// @brief 指定した場所の要素を削除
        /// @param index 削除する位置
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        void RemoveAt(ssize_t index) override;

        /// @brief 指定した場所の要素を削除
        /// @param index 削除する位置
        void RemoveAtUnsafe(ssize_t index) noexcept override;

        /// @brief 最後の要素を削除
        void RemoveBackUnsafe() noexcept override;

        /// @brief 最初の要素を削除
        void RemoveFrontUnsafe() noexcept override;

        /// @brief 要素を逆順に入れ替え
        void Reverse() noexcept override;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const override { return u"Kongkong::Collections::ObservableArrayList<T>"; }

        private:

        ArrayChangingEventHandler<ProjType> _arrayChanging;

        ProjType _make();

        void _callEvent(ssize_t index, CollectionChange change);
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    class ObservableArrayList : public ArrayList<T> {
        public:
        using ImplType = IMPLEMENTATION::ObservableArrayList<T>;

        /// @brief 空のリストを作成
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        ObservableArrayList() : ArrayList<T>(nullptr) { this->_setInstance(NEW ImplType()); }

        /// @brief 初期化リストから作成
        /// @param inil 初期化リスト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        ObservableArrayList(std::initializer_list<T> const& inil) : ArrayList<T>(nullptr) { this->_setInstance(NEW ImplType(inil)); }

        /// @brief nullptrとして作成
        constexpr ObservableArrayList(std::nullptr_t) noexcept : ArrayList<T>(nullptr) {}

        [[nodiscard]]
        operator IArray<T>() const { return Object::As<IArray<T>>(); }

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

        [[nodiscard]]
        auto& ArrayChanging() const { return _getPtr<ImplType>()->ArrayChanging(); }
    };
}

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    void ObservableArrayList<T>::Append(T const& value)
    {
        Base::Append(value);

        _callEvent(this->Length() - 1, CollectionChange::ItemInserted);
    }

    template <class T>
    void ObservableArrayList<T>::Append(T&& value)
    {
        Base::Append(std::move(value));

        _callEvent(this->Length() - 1, CollectionChange::ItemInserted);
    }

    template <class T>
    void ObservableArrayList<T>::Clear() noexcept
    {
        Base::Clear();

        _callEvent(-1, CollectionChange::Reset);
    }

    template <class T>
    void ObservableArrayList<T>::Insert(ssize_t index, T const& value)
    {
        Base::Insert(index, value);

        _callEvent(index, CollectionChange::ItemInserted);
    }

    template <class T>
    void ObservableArrayList<T>::Insert(ssize_t index, T&& value)
    {
        Base::Insert(index, std::move(value));

        _callEvent(index, CollectionChange::ItemInserted);
    }

    template <class T>
    bool ObservableArrayList<T>::Remove(T const& value) noexcept
    {
        ssize_t index = this->IndexOf(value);

        if (index != CollectionHelper::NotFound()) {
            RemoveAtUnsafe(index);
            return true;
        }

        return false;
    }

    template <class T>
    void ObservableArrayList<T>::RemoveAt(ssize_t index)
    {
        Base::RemoveAt(index);

        _callEvent(index, CollectionChange::ItemRemoved);
    }

    template <class T>
    void ObservableArrayList<T>::RemoveAtUnsafe(ssize_t index) noexcept
    {
        Base::RemoveAtUnsafe(index);

        _callEvent(index, CollectionChange::ItemRemoved);
    }

    template <class T>
    void ObservableArrayList<T>::RemoveBackUnsafe() noexcept
    {
        Base::RemoveBackUnsafe();

        _callEvent(this->Length(), CollectionChange::ItemRemoved);
    }

    template <class T>
    void ObservableArrayList<T>::RemoveFrontUnsafe() noexcept
    {
        Base::RemoveFrontUnsafe();

        _callEvent(0, CollectionChange::ItemRemoved);
    }

    template <class T>
    void ObservableArrayList<T>::Reverse() noexcept
    {
        Base::Reverse();

        _callEvent(-1, CollectionChange::Reverse);
    }

    template <class T>
    ObservableArrayList<T>::ProjType ObservableArrayList<T>::_make()
    {
        return Object::Make<ProjType, ObservableArrayList<T>>(this);
    }

    template <class T>
    void ObservableArrayList<T>::_callEvent(ssize_t index, CollectionChange change)
    {
        _arrayChanging.Call(_make(), ArrayChangingEventArgs(index, change));
    }
}

#endif //!KONGKONG_COLLECTIONS_OBSERVABLEARRAYLIST_H
