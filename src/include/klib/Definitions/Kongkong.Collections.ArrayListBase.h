#ifndef KONGKONG_COLLECTIONS_ARRAYLISTBASE_H
#define KONGKONG_COLLECTIONS_ARRAYLISTBASE_H

#include "Base.h"
#include "Kongkong.Collections.IArray.h"
#include "Kongkong.Collections.List.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    struct ArrayListBase : public List<T>, public IArray<T> {

        constexpr ssize_t Length() const noexcept override { return -1; }

        /// @brief 容量
        [[nodiscard]]
        virtual ssize_t Capacity() const noexcept = 0;

        /// @brief 指定した位置に要素を挿入
        /// @param index 挿入する位置
        /// @param value 挿入する値
        /// @throws ArgumentOutOfRangeException: 位置が範囲外のとき
        virtual void Insert(ssize_t index, T const& value) = 0;

        /// @brief 指定した位置に要素を挿入
        /// @param index 挿入する位置
        /// @param value 挿入する値
        /// @throws ArgumentOutOfRangeException: 位置が範囲外のとき
        virtual void Insert(ssize_t index, T&& value) = 0;

        /// @brief 指定した場所の要素を削除
        /// @param index 削除する位置
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        virtual void RemoveAt(ssize_t index) = 0;

        /// @brief 指定した場所の要素を削除
        /// @param index 削除する位置
        virtual void RemoveAtUnsafe(ssize_t index) noexcept = 0;

        /// @brief Capacity()をLength()に合わせる
        virtual void ShrinkToFit() = 0;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    class ArrayListBase : public List<T> {
        public:
        using ImplType = IMPLEMENTATION::ArrayListBase<T>;

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

        /// @brief nullptrとして作成
        constexpr ArrayListBase(std::nullptr_t) noexcept : List<T>(nullptr) {}

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        T& operator[](ssize_t index) const { return Object::_getRef<ImplType>().operator[](index); }

        /// @brief 指定した位置から指定した数だけ要素を削除
        /// @param index 削除する初めの位置
        /// @param count 削除する要素数
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws ArgumentOutOfRangeException: 範囲外の要素を指定したとき
        //void RemoveRange(ssize_t index, ssize_t count) const { Object::_getRef<ImplType>().RemoveRange(index, count); }
    };
}

#endif //!KONGKONG_COLLECTIONS_ARRAYLISTBASE_H
