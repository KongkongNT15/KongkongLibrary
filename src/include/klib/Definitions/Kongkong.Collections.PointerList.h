#ifndef KONGKONG_COLLECTIONS_POINTERLIST_H
#define KONGKONG_COLLECTIONS_POINTERLIST_H

#include "Base.h"
#include "Kongkong.NullPointerException.h"
#include "Kongkong.Collections.IArray.h"
#include "Kongkong.Collections.ArrayListBase.h"
#include "Kongkong.Collections.Turbo.FastPointerList.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    struct PointerList final : public ArrayListBase<T> {

        [[nodiscard]] Iterators::Iterator<T> begin() override { return Iterators::PointerListIterator<T>(_list.Data()); }
        [[nodiscard]] Iterators::ConstIterator<T> begin() const override { return Iterators::ConstPointerListIterator<T>(_list.Data()); }
        [[nodiscard]] Iterators::Iterator<T> end() override { return Iterators::PointerListIterator<T>(_list.Data() + _list.Length()); }
        [[nodiscard]] Iterators::ConstIterator<T> end() const override { return Iterators::ConstPointerListIterator<T>(_list.Data() + _list.Length()); }

        PointerList() : _list()
        {
        }

        PointerList(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T> : _list(length, defaultValue)
        {
        }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]] T& operator[](ssize_t index) noexcept override { return _list[index]; }
        [[nodiscard]] T const& operator[](ssize_t index) const noexcept override { return _list[index]; }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        [[nodiscard]] T& At(ssize_t index) override { return _list.At(index); }
        [[nodiscard]] T const& At(ssize_t index) const override { return _list.At(index); }

        void Append(T const& value) override { _list.Append(value); }

        void Append(T&& value) override { _list.Append(std::move(value)); }

        [[nodiscard]] T& BackUnsafe() noexcept override { return _list.GetBackUnsafe(); }
        [[nodiscard]] T const& BackUnsafe() const noexcept override { return _list.GetBackUnsafe(); }

        /// @brief 容量
        [[nodiscard]]
        ssize_t Capacity() const noexcept override { return _list.Capacity(); }

        /// @brief 要素をすべて削除
        void Clear() noexcept override { _list.Clear(); }

        /// @brief 指定した値が含まれるかを判定
        [[nodiscard]]
        bool Contains(T const& value) const noexcept override { return _list.Contains(value); }

        /// @brief 要素数
        [[nodiscard]]
        ssize_t Length() const noexcept override { return _list.Length(); }

        /// @brief 最初の要素を取得
        [[nodiscard]] T& FrontUnsafe() noexcept override { return _list.GetFrontUnsafe(); }
        [[nodiscard]] T const& FrontUnsafe() const noexcept override { return _list.GetFrontUnsafe(); }

        /// @brief 指定した要素の番号を取得
        /// @param value 値
        /// @return 要素番号、要素が見つからなかった場合はCollectionHelper::NotFound()
        [[nodiscard]]
        ssize_t IndexOf(T const& value) const noexcept override { return _list.IndexOf(value); }

        /// @brief 指定した位置に要素を挿入
        /// @param index 挿入する位置
        /// @param value 挿入する値
        /// @throws ArgumentOutOfRangeException: 位置が範囲外のとき
        void Insert(ssize_t index, T const& value) override { _list.Insert(index, value); }

        /// @brief 指定した位置に要素を挿入
        /// @param index 挿入する位置
        /// @param value 挿入する値
        /// @throws ArgumentOutOfRangeException: 位置が範囲外のとき
        void Insert(ssize_t index, T&& value) override { _list.Insert(index, std::move(value)); }

        /// @brief 指定した要素を削除
        /// @return 要素を削除すればtrue
        /// @return 指定した要素が見つからなければfalse
        bool Remove(T const& value) override { return _list.Remove(value); }

        /// @brief 指定した場所の要素を削除
        /// @param index 削除する位置
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        void RemoveAt(ssize_t index) override { _list.RemoveAt(index); }

        /// @brief 指定した場所の要素を削除
        /// @param index 削除する位置
        void RemoveAtUnsafe(ssize_t index) noexcept override { _list.RemoveAtUnsafe(index); }

        /// @brief 最後の要素を削除
        void RemoveBackUnsafe() noexcept override { _list.RemoveBackUnsafe(); }

        /// @brief 最初の要素を削除
        void RemoveFrontUnsafe() noexcept override { _list.RemoveFrontUnsafe(); }

        /// @brief 要素を逆順に入れ替え
        void Reverse() noexcept override { _list.Reverse(); }

        /// @brief Capacity()をLength()に合わせる
        void ShrinkToFit() override { _list.ShrinkToFit(); }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const override { return u"Kongkong::Collections::PointerList<T>"; }

        private:
        Turbo::FastPointerList<T> _list;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    class PointerList final : public ArrayListBase<T> {
        public:
        using ImplType = IMPLEMENTATION::PointerList<T>;

        [[nodiscard]]
        operator IArray<T>() const { return Object::As<IArray<T>>(); }

        [[nodiscard]]
        operator ICollection<T>() const { return Object::As<ICollection<T>>(); }

        [[nodiscard]]
        operator IIterable<T>() const { return Object::As<PointerList, IIterable<T>>(); }

        [[nodiscard]]
        operator IReadOnlyArray<T>() const { return Object::As<IReadOnlyArray<T>>(); }

        [[nodiscard]]
        operator IReadOnlyCollection<T>() const { return Object::As<IReadOnlyCollection<T>>(); }

        [[nodiscard]]
        operator IReadOnlyIterable<T>() const { return Object::As<IReadOnlyIterable<T>>(); }

        /// @brief 空のリストを作成
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        PointerList() : ArrayListBase<T>(nullptr) { Object::_setInstance(NEW ImplType()); }
        
        /// @brief 要素数と初期値を指定して作成
        /// @param length 長さ
        /// @param defaultValue 初期値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        PointerList(ssize_t length, T const& defaultValue) : ArrayListBase<T>(nullptr) { Object::_setInstance(NEW ImplType(length, defaultValue)); }
        
        /// @brief nullptrとして作成
        constexpr PointerList(std::nullptr_t) noexcept : ArrayListBase<T>(nullptr) {}

        /// @brief ふぁ！？っく
        //void SetAt(ssize_t, std::nullptr_t) const = delete;

        /// @brief 指定した位置の要素を置き換えます
        /// @param index 置き換える要素の位置
        /// @param pValue 置き換え後の値
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        /// @throws ArgumentNullException: pValueがnullptrのとき
        //void SetAt(ssize_t index, T* pValue) const { Object::_getRef<ImplType>().SetAt(index, pValue); }
    };

    
}

#endif //!KONGKONG_COLLECTIONS_POINTERLIST_H
