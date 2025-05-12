#ifndef KONGKONG_COLLECTIONS_ARRAY_H
#define KONGKONG_COLLECTIONS_ARRAY_H

#include "Base.h"

#include "Kongkong.Collections.IArray.h"
#include "Kongkong.Collections.Iterators.ArrayIterator.h"
#include "Kongkong.Collections.Iterators.ConstArrayIterator.h"
#include "Kongkong.Collections.Turbo.FastArray.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    // 配列のラッパー
    template <class T>
    struct Array final : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object, public IArray<T> {
        using ProjType = ::KONGKONG_NAMESPACE::Collections::Array<T>;

        [[nodiscard]] Iterators::Iterator<T> begin() override { return Iterators::ArrayIterator<T>(_arr.begin()); }
        [[nodiscard]] Iterators::ConstIterator<T> begin() const override { return Iterators::ConstArrayIterator<T>(_arr.begin()); }
        [[nodiscard]] Iterators::Iterator<T> end() override { return Iterators::ArrayIterator<T>(_arr.end()); }
        [[nodiscard]] Iterators::ConstIterator<T> end() const override { return Iterators::ConstArrayIterator<T>(_arr.end()); }

        // 要素数を指定
        explicit Array(ssize_t length) requires std::default_initializable<T>
            : _arr(length)
        {
        }

        // 要素数と初期値を指定
        explicit Array(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T>
            : _arr(length, defaultValue)
        {
        }

        // 初期化リストから作成
        Array(std::initializer_list<T> const& inil) requires ::std::copy_constructible<T>
            : _arr(inil)
        {
        }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]] T& operator[](ssize_t index) noexcept override { return _arr[index]; }
        [[nodiscard]] T const& operator[](ssize_t index) const noexcept override { return _arr[index]; }

        // 等値判定
        [[nodiscard]] friend bool operator==(Array<T> const& left, Array<T> const& right) noexcept { return left._arr == right._arr; }
        [[nodiscard]] friend bool operator!=(Array<T> const& left, Array<T> const& right) noexcept { return left._arr != right._arr; }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]] T& At(ssize_t index) override { return _arr.At(index); }
        [[nodiscard]] T const& At(ssize_t index) const override { return _arr.At(index); }

        /// @brief 最後の要素を取得
        [[nodiscard]] T& BackUnsafe() noexcept override { return _arr.GetBackUnsafe(); }
        [[nodiscard]] T const& BackUnsafe() const noexcept override { return _arr.GetBackUnsafe(); }

        /// @brief 指定した値が含まれるかを判定
        /// @param value 値
        [[nodiscard]]
        bool Contains(T const& value) const noexcept override
        {
            return _arr.Contains(value);
        }

        /// @brief 配列へのポインター
        [[nodiscard]] constexpr T* Data() noexcept { return _arr.Data(); }
        [[nodiscard]] constexpr const T* Data() const noexcept { return _arr.Data(); }

        /// @brief 最初の要素を取得
        [[nodiscard]] T& FrontUnsafe() noexcept override { return _arr.GetFrontUnsafe(); }
        [[nodiscard]] T const& FrontUnsafe() const noexcept override { return _arr.GetFrontUnsafe(); }

        /// @brief 指定した要素の番号を取得
        /// @param value 値
        /// @return 要素番号、要素が見つからなかった場合はCollectionHelper::NotFound()
        [[nodiscard]]
        ssize_t IndexOf(T const& value) const noexcept override
        {
            return _arr.IndexOf(value);
        }

        /// @brief 要素数
        [[nodiscard]]
        ssize_t Length() const noexcept override { return _arr.Length(); }

        /// @brief 配列へのポインター
        [[nodiscard]]
        constexpr const T* Pointer() const noexcept { return _arr.Pointer(); }

        /// @brief 要素数を変更
        /// @attention MemoryAllocationExceptionが発生した場合はオブジェクトは変更されないよ！
        /// @param length 変更後の要素数
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Resize(ssize_t length) requires ::std::default_initializable<T>
        {
            _arr.Resize(length);
        }

        /// @brief 要素数を変更
        /// @attention MemoryAllocationExceptionが発生した場合はオブジェクトは変更されないよ！
        /// @param length 変更後の要素数
        /// @param defaultValue 新たに追加される要素の初期値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Resize(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T>
        {
            _arr.Resize(length, defaultValue);
        }

        /// @brief 要素を逆順に入れ替え
        void Reverse() noexcept override
        {
            _arr.Reverse();
        }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const override { return String::FromPointerUnsafe(u"Kongkong::Collections::Array<T>", true); }

        private:
        Turbo::FastArray<T> _arr;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    /// @brief 配列クラス
    template <class T>
    class Array final : public Object {
        public:
        using ImplType = IMPLEMENTATION::Array<T>;

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

        /// @brief 要素数を指定して作成
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit Array(ssize_t length) requires std::default_initializable<T>
            : Object(nullptr)
        {
            this->_setInstance(NEW ImplType(length));
        }

        /// @brief 要素数と初期値を指定して作成
        /// @param length 長さ
        /// @param defaultValue 初期値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit Array(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T>
            : Object(nullptr)
        {
            this->_setInstance(NEW ImplType(length, defaultValue));
        }

        /// @brief 初期化リストから作成
        /// @param inil 初期化リスト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        Array(std::initializer_list<T> const& inil) requires ::std::copy_constructible<T>
            : Object(nullptr)
        {
            this->_setInstance(NEW ImplType(inil));
        }

        /// @brief nullptrとして作成
        constexpr Array(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] Iterators::Iterator<T> begin() const { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] Iterators::Iterator<T> end() const { return _getPtr<ImplType>()->end(); }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]]
        T& operator[](ssize_t index) const { return Object::_getRef<ImplType>().operator[](index); }

        friend bool operator==(Array<T> const& left, Array<T> const& right) { return left.template _getRef<ImplType>() == right.template _getRef<ImplType>(); }
        friend bool operator!=(Array<T> const& left, Array<T> const& right) { return !(left == right); }
    };
}

#endif //!KONGKONG_COLLECTIONS_ARRAY_H
