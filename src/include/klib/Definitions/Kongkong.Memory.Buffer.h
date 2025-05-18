#ifndef KONGKONG_MEMORY_BUFFER_H
#define KONGKONG_MEMORY_BUFFER_H

#include "Base.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.NullPointerException.h"
#include "Kongkong.Memory.BufferBase.h"

namespace KONGKONG_NAMESPACE::Memory
{
    /// @brief バッファー
    /// @tparam T 要素型
    template <class T>
    struct Buffer final : public BufferBase {
        /// @brief 要素型
        using ElementType = T;

        /// @brief 要素の大きさ
        [[nodiscard]] 
        constexpr ssize_t ElementSize() noexcept { return sizeof(T); }

        /// @brief メモリを割り当てずに作成
        constexpr Buffer() noexcept : _p(nullptr), _length(0) {}

        /// @brief メモリを割り当てて作成
        /// @attention 要素の初期化はしないよ！
        /// @param length 要素数
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの割り当てに失敗したとき
        Buffer(ssize_t length);

        Buffer(Buffer const&) = delete;
        Buffer(Buffer&& right) noexcept;

        ~Buffer();

        Buffer& operator=(Buffer const&) = delete;
        Buffer& operator=(Buffer&& right) noexcept;

        [[nodiscard]] constexpr T* begin() noexcept { return _p; }
        [[nodiscard]] constexpr const T* begin() const noexcept { return _p; }
        [[nodiscard]] constexpr T* end() noexcept { return _p + _length; }
        [[nodiscard]] constexpr const T* end() const noexcept { return _p + _length; }

        /// @brief 指定した位置の要素を取得
        /// @param index 要素番号
        [[nodiscard]] constexpr T& operator[] (ssize_t index) noexcept { return _p[index]; }
        [[nodiscard]] constexpr T const& operator[] (ssize_t index) const noexcept { return _p[index]; }

        /// @brief メモリを割り当て
        /// @attention 要素の初期化はしないよ！
        /// @param length 要素数
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの割り当てに失敗したとき
        void Alloc(ssize_t length);

        /// @brief メモリを割り当て
        /// @param length 要素数
        /// @throws MemoryAllocationException: メモリの割り当てに失敗したとき
        void AllocUnsafe(ssize_t length);

        /// @brief 指定した位置の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexがゼロ以下のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]] T& At(ssize_t index);
        [[nodiscard]] T const& At(ssize_t index) const;

        /// @brief 最後の要素を取得
        /// @throws NullPointerException: メモリが割り当てられていないとき
        [[nodiscard]] T& Back();
        [[nodiscard]] T const& Back() const;

        /// @brief 最後の要素を取得
        [[nodiscard]] constexpr T& BackUnsafe() noexcept { return _p[_length - 1]; }
        [[nodiscard]] constexpr T const& BackUnsafe() const noexcept { return _p[_length - 1]; }

        /// @brief 割り当てられているメモリブロック
        [[nodiscard]] constexpr T* Data() noexcept { return _p; }
        [[nodiscard]] constexpr const T* Data() const noexcept { return _p; }

        /// @brief すべての要素のデストラクタを呼びます
        /// @throws NullPointerException: メモリが割り当てられていないとき
        void DestoryAll() requires ::std::destructible<T>;

        /// @brief 全ての要素のデストラクタを呼ぶふりをします
        /// @throws NullPointerException: メモリが割り当てられていないとき
        void DestoryAll();

        /// @brief すべての要素のデストラクタを呼びます
        void DestoryAllUnsafe() noexcept requires ::std::destructible<T>;

        /// @brief 全ての要素のデストラクタを呼ぶふりをします
        constexpr void DestoryAllUnsafe() noexcept {}

        /// @brief 指定した位置の要素のデストラクタを呼びます
        /// @param index 要素番号
        /// @throws NullPointerException: メモリが割り当てられていないとき
        /// @throws InvalidArgumentException: indexがゼロ以下のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        void DestoryAt(ssize_t index) requires ::std::default_initializable<T>;

        /// @brief 指定した位置の要素のデストラクタを呼ぶふりをします
        /// @param index 要素番号
        /// @throws NullPointerException: メモリが割り当てられていないとき
        /// @throws InvalidArgumentException: indexがゼロ以下のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        void DestoryAt([[maybe_unused]] ssize_t index);

        /// @brief 指定した位置の要素のデストラクタを呼びます
        /// @param index 要素番号
        void DestoryAtUnsafe(ssize_t index) noexcept requires ::std::default_initializable<T>;

        /// @brief 指定した位置の要素のデストラクタを呼ぶふりをします
        /// @param index 要素番号
        /// @throws NullPointerException: メモリが割り当てられていないとき
        /// @throws InvalidArgumentException: indexがゼロ以下のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        constexpr void DestoryAtUnsafe([[maybe_unused]] ssize_t index) {}

        /// @brief 指定した位置に直接構築
        /// @param index 位置
        /// @param ...args コンストラクタ引数
        /// @return 作成されたオブジェクトへの参照
        /// @throws NullPointerException: メモリが割り当てられていないとき
        /// @throws InvalidArgumentException: indexがゼロ以下のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        template <class... Args>
        T& EmplaceAt(ssize_t index, Args&&... args);

        /// @brief 指定した位置に直接構築
        /// @param index 位置
        /// @param ...args コンストラクタ引数
        /// @return 作成されたオブジェクトへの参照
        template <class... Args>
        T& EmplaceAtUnsafe(ssize_t index, Args&&... args);

        /// @brief 割り当てられているメモリを解放
        /// @throws NullPointerException: メモリが割り当てられていないとき
        void FreeMemory();

        /// @brief 割り当てられているメモリを解放
        void FreeMemoryUnsafe() noexcept;

        /// @brief 最初の要素を取得
        /// @throws NullPointerException: メモリが割り当てられていないとき
        [[nodiscard]] T& Front();
        [[nodiscard]] T const& Front() const;

        /// @brief 最初の要素を取得
        [[nodiscard]] constexpr T& FrontUnsafe() noexcept { return _p[0]; }
        [[nodiscard]] constexpr T const& FrontUnsafe() const noexcept { return _p[0]; }

        /// @brief メモリが割り当てられているかを確認
        [[nodiscard]]
        constexpr bool HasData() const noexcept { return _p != nullptr; }

        /// @brief 要素をすべて初期化します
        /// @throws NullPointerException: メモリが割り当てられていないとき
        void InitializeAll() requires ::std::default_initializable<T>;

        /// @brief 要素をすべて初期化します
        /// @param defaultValue 初期値
        /// @throws NullPointerException: メモリが割り当てられていないとき
        void InitializeAll(T const& defaultValue) requires ::std::copy_constructible<T>;

        /// @brief 要素をすべて初期化します
        void InitializeAllUnsafe() requires ::std::default_initializable<T>;

        /// @brief 要素をすべて初期化します
        /// @param defaultValue 初期値
        void InitializeAllUnsafe(T const& defaultValue) requires ::std::copy_constructible<T>;

        /// @brief 指定した要素を初期化
        /// @attention すでに値が入っている場合はまずDestroy()を使ってね！
        /// @param index 要素番号
        /// @return 作成されたオブジェクトへの参照
        /// @throws NullPointerException: メモリが割り当てられていないとき
        /// @throws InvalidArgumentException: indexがゼロ以下のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        T& InitializeAt(ssize_t index) requires ::std::default_initializable<T>;

        /// @brief 指定した要素を初期化
        /// @attention すでに値が入っている場合はまずDestroy()を使ってね！
        /// @param index 要素番号
        /// @param value コピー元
        /// @return 作成されたオブジェクトへの参照
        /// @throws NullPointerException: メモリが割り当てられていないとき
        /// @throws InvalidArgumentException: indexがゼロ以下のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        T& InitializeAt(ssize_t index, T const& value) requires ::std::copy_constructible<T>;

        /// @brief 指定した要素を初期化
        /// @attention すでに値が入っている場合はまずDestroy()を使ってね！
        /// @param index 要素番号
        /// @param value ムーブ元
        /// @return 作成されたオブジェクトへの参照
        /// @throws NullPointerException: メモリが割り当てられていないとき
        /// @throws InvalidArgumentException: indexがゼロ以下のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        T& InitializeAt(ssize_t index, T&& value) requires ::std::move_constructible<T>;

        /// @brief 指定した要素を初期化
        /// @attention すでに値が入っている場合はまずDestroy()を使ってね！
        /// @param index 要素番号
        /// @return 作成されたオブジェクトへの参照
        T& InitializeAtUnsafe(ssize_t index) requires ::std::default_initializable<T>;

        /// @brief 指定した要素を初期化
        /// @attention すでに値が入っている場合はまずDestroy()を使ってね！
        /// @param index 要素番号
        /// @param value コピー元
        /// @return 作成されたオブジェクトへの参照
        T& InitializeAtUnsafe(ssize_t index, T const& value) requires ::std::copy_constructible<T>;

        /// @brief 指定した要素を初期化
        /// @attention すでに値が入っている場合はまずDestroy()を使ってね！
        /// @param index 要素番号
        /// @param value ムーブ元
        /// @return 作成されたオブジェクトへの参照
        T& InitializeAtUnsafe(ssize_t index, T&& value) requires ::std::move_constructible<T>;

        /// @brief 要素数
        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _length; }

        private:
        T* _p;
        ssize_t _length;

        void _finalize() noexcept;
    };

    template <class T>
    [[nodiscard]] constexpr bool operator==(Buffer<T> const& left, Buffer<T> const& right) noexcept { return left.Data() == right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator==(Buffer<T> const& left, std::nullptr_t) noexcept { return left.Data() == nullptr; }

    template <class T>
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, Buffer<T> const& right) noexcept { return nullptr == right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator!=(Buffer<T> const& left, Buffer<T> const& right) noexcept { return left.Data() != right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator!=(Buffer<T> const& left, std::nullptr_t) noexcept { return left.Data() != nullptr; }

    template <class T>
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, Buffer<T> const& right) noexcept { return nullptr != right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator<(Buffer<T> const& left, Buffer<T> const& right) noexcept { return left.Data() < right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator<(Buffer<T> const& left, std::nullptr_t) noexcept { return false; }

    template <class T>
    [[nodiscard]] constexpr bool operator<(std::nullptr_t, Buffer<T> const& right) noexcept { return nullptr != right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator<=(Buffer<T> const& left, Buffer<T> const& right) noexcept { return left.Data() <= right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator<=(Buffer<T> const& left, std::nullptr_t) noexcept { return left.Data() == nullptr; }

    template <class T>
    [[nodiscard]] constexpr bool operator<=(std::nullptr_t, Buffer<T> const& right) noexcept { return true; }

    template <class T>
    [[nodiscard]] constexpr bool operator>(Buffer<T> const& left, Buffer<T> const& right) noexcept { return left.Data() > right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator>(Buffer<T> const& left, std::nullptr_t) noexcept { return left.Data() != nullptr; }

    template <class T>
    [[nodiscard]] constexpr bool operator>(std::nullptr_t, Buffer<T> const& right) noexcept { return false; }

    template <class T>
    [[nodiscard]] constexpr bool operator>=(Buffer<T> const& left, Buffer<T> const& right) noexcept { return left.Data() >= right.Data(); }

    template <class T>
    [[nodiscard]] constexpr bool operator>=(Buffer<T> const& left, std::nullptr_t) noexcept { return true; }

    template <class T>
    [[nodiscard]] constexpr bool operator>=(std::nullptr_t, Buffer<T> const& right) noexcept { return right.Data() != nullptr; }

    template <class T>
    [[nodiscard]] constexpr std::strong_ordering operator<=>(Buffer<T> const& left, Buffer<T> const& right) noexcept { return left.Data() <=> right.Data(); }

    template <class T>
    [[nodiscard]] constexpr std::strong_ordering operator<=>(Buffer<T> const& left, std::nullptr_t) noexcept { return left.Data() == nullptr ? ::std::strong_ordering::equal : ::std::strong_ordering::greater; }

    template <class T>
    [[nodiscard]] constexpr std::strong_ordering operator<=>(std::nullptr_t, Buffer<T> const& right) noexcept { return right.Data() == nullptr ? ::std::strong_ordering::equal : ::std::strong_ordering::less; }
}

namespace KONGKONG_NAMESPACE::Memory
{
    template <class T>
    Buffer<T>::Buffer(ssize_t length) : _length(length)
    {
        Alloc(length);
    }

    template <class T>
    Buffer<T>::Buffer(Buffer&& right) noexcept : _p(right._p), _length(right._length)
    {
        right._p = nullptr;
    }

    template <class T>
    Buffer<T>::~Buffer()
    {
        if (_p != nullptr) _finalize();
    }

    template <class T>
    Buffer<T>& Buffer<T>::operator=(Buffer<T>&& right) noexcept
    {
        _finalize();

        _length = right._length;
        _p = right._p;

        right._p = nullptr;
    }

    template <class T>
    void Buffer<T>::Alloc(ssize_t length)
    {
        Collections::CollectionHelper::CheckLength(length);

        AllocUnsafe(length);
    }

    template <class T>
    void Buffer<T>::AllocUnsafe(ssize_t length)
    {
        _p = (T*)::malloc(length * ElementSize());

        MemoryAllocationException::CheckNull(_p);
    }

    template <class T>
    T& Buffer<T>::At(ssize_t index)
    {
        Collections::CollectionHelper::CheckIndex(index, _length);

        return _p[index];
    }

    template <class T>
    T const& Buffer<T>::At(ssize_t index) const
    {
        Collections::CollectionHelper::CheckIndex(index, _length);

        return _p[index];
    }

    template <class T>
    T& Buffer<T>::Back()
    {
        NullPointerException::CheckNull(_p, _name);

        return BackUnsafe();
    }

    template <class T>
    T const& Buffer<T>::Back() const
    {
        NullPointerException::CheckNull(_p, _name);

        return BackUnsafe();
    }

    template <class T>
    void Buffer<T>::DestoryAll() requires ::std::destructible<T>
    {
        NullPointerException::CheckNull(_p, _name);

        DestoryAllUnsafe();
    }

    template <class T>
    void Buffer<T>::DestoryAll()
    {
        NullPointerException::CheckNull(_p, _name);
    }

    template <class T>
    void Buffer<T>::DestoryAllUnsafe() noexcept requires ::std::destructible<T>
    {
        for (T& element : *this) {
            element.~T();
        }
    }

    template <class T>
    void Buffer<T>::DestoryAt(ssize_t index) requires ::std::default_initializable<T>
    {
        NullPointerException::CheckNull(_p, _name);
        Collections::CollectionHelper::CheckIndex(index, _length);

        _p[index].~T();
    }

    template <class T>
    void Buffer<T>::DestoryAt(ssize_t index)
    {
        NullPointerException::CheckNull(_p, u"Buffer<T>");
        Collections::CollectionHelper::CheckIndex(index, _length);
    }

    template <class T>
    void Buffer<T>::DestoryAtUnsafe(ssize_t index) noexcept requires ::std::default_initializable<T>
    {
        _p[index].~T();
    }

    template <class T>
    template <class... Args>
    T& Buffer<T>::EmplaceAt(ssize_t index, Args&&... args)
    {
        NullPointerException::CheckNull(_p, "Buffer<T>");
        Collections::CollectionHelper::CheckIndex(index, _length);

        return EmplaceAtUnsafe(index, std::forward(args)...);
    }

    template <class T>
    template <class... Args>
    T& Buffer<T>::EmplaceAtUnsafe(ssize_t index, Args&&... args)
    {
        T* p = _p + index;

        new(p) T(std::forward(args)...);

        return *p;
    }

    template <class T>
    void Buffer<T>::FreeMemory()
    {
        NullPointerException::CheckNull(_p, _name);

        ::free(_p);
        _p = nullptr;
        _length = 0;
    }

    template <class T>
    void Buffer<T>::FreeMemoryUnsafe() noexcept
    {
        ::free(_p);

        _p = nullptr;
        _length = 0;
    }

    template <class T>
    T& Buffer<T>::Front()
    {
        NullPointerException::CheckNull(_p, _name);

        return FrontUnsafe();
    }

    template <class T>
    T const& Buffer<T>::Front() const
    {
        NullPointerException::CheckNull(_p, _name);

        return FrontUnsafe();
    }

    template <class T>
    void Buffer<T>::InitializeAll() requires ::std::default_initializable<T>
    {
        NullPointerException::CheckNull(_p, _name);

        InitializeAllUnsafe();
    }

    template <class T>
    void Buffer<T>::InitializeAll(T const& defaultValue) requires ::std::copy_constructible<T>
    {
        NullPointerException::CheckNull(_p, _name);

        InitializeAllUnsafe(defaultValue);
    }

    template <class T>
    void Buffer<T>::InitializeAllUnsafe() requires ::std::default_initializable<T>
    {
        for (ssize_t i = 0; i < _length; i++) {
            try {
                new(_p + i) T();
            }
            catch (...) {
                auto ex = ::std::current_exception();

                for (ssize_t j = 0; j < i; j++) {
                    _p[j].~T();
                }

                ::std::rethrow_exception(ex);
            }
        }
    }

    template <class T>
    void Buffer<T>::InitializeAllUnsafe(T const& defaultValue) requires ::std::copy_constructible<T>
    {
        for (ssize_t i = 0; i < _length; i++) {
            try {
                new(_p + i) T(defaultValue);
            }
            catch (...) {
                auto ex = ::std::current_exception();

                for (ssize_t j = 0; j < i; j++) {
                    _p[j].~T();
                }

                ::std::rethrow_exception(ex);
            }
        }
    }

    template <class T>
    T& Buffer<T>::InitializeAt(ssize_t index)requires ::std::default_initializable<T>
    {
        NullPointerException::CheckNull(_p, _name);
        Collections::CollectionHelper::CheckIndex(index, _length);
        
        return InitializeAtUnsafe(index);
    }

    template <class T>
    T& Buffer<T>::InitializeAt(ssize_t index, T const& value) requires ::std::copy_constructible<T>
    {
        NullPointerException::CheckNull(_p, _name);
        Collections::CollectionHelper::CheckIndex(index, _length);

        return InitializeAtUnsafe(index, value);
    }

    template <class T>
    T& Buffer<T>::InitializeAt(ssize_t index, T&& value) requires ::std::move_constructible<T>
    {
        NullPointerException::CheckNull(_p, _name);
        Collections::CollectionHelper::CheckIndex(index, _length);

        return InitializeAtUnsafe(index, std::move(value));
    }

    template <class T>
    T& Buffer<T>::InitializeAtUnsafe(ssize_t index) requires ::std::default_initializable<T>
    {
        T* p = _p + index;

        new(p) T();

        return *p;
    }

    template <class T>
    T& Buffer<T>::InitializeAtUnsafe(ssize_t index, T const& value) requires ::std::copy_constructible<T>
    {
        T* p = _p + index;

        new(p) T(value);

        return *p;
    }

    template <class T>
    T& Buffer<T>::InitializeAtUnsafe(ssize_t index, T&& value) requires ::std::move_constructible<T>
    {
        T* p = _p + index;

        new(p) T(std::move(value));

        return *p;
    }

    template <class T>
    void Buffer<T>::_finalize() noexcept
    {
        ::free(_p);
    }
}

#endif //!KONGKONG_MEMORY_BUFFER_H
