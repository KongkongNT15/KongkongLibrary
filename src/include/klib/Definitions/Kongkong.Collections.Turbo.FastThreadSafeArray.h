#ifndef KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAY_H
#define KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAY_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo._fastThreadSafeArrayMethods.h"
#include "Kongkong.Collections.Turbo.FastArray.h"
#include "Kongkong.Threading.Mutex.h"
#include "Kongkong.Threading.ScopeLock.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastThreadSafeArray final : public ValueType, public _fastThreadSafeArrayMethods {

        /// @brief 要素数を指定して作成
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit FastThreadSafeArray(ssize_t length) requires ::std::default_initializable<T>
            : _array(length), _mutex()
        {
        }

        /// @brief 要素数と初期値を指定して作成
        /// @param length 長さ
        /// @param defaultValue 初期値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit FastThreadSafeArray(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T>
            : _array(length, defaultValue), _mutex()
        {
        }

        /// @brief 初期化リストから作成
        /// @param inil 初期化リスト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        FastThreadSafeArray(std::initializer_list<T> const& inil) requires ::std::copy_constructible<T>
            : _array(inil), _mutex()
        {
        }

        FastThreadSafeArray(FastArray<T> const& array) : _array(array), _mutex()
        {
        }

        FastThreadSafeArray(FastArray<T>&& array) : _array(std::move(array)), _mutex()
        {
        }

        FastThreadSafeArray(FastThreadSafeArray const& right) : _array(nullptr), _mutex()
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(right._mutex));

            new (&_array) FastArray<T>(right._array);
        }

        FastThreadSafeArray(FastThreadSafeArray&& right) noexcept : _array(nullptr), _mutex(std::move(right._mutex))
        {
            Threading::ScopeLock lock(_mutex);
            
            new (&_array) FastArray<T>(std::move(right._array));
        }

        FastThreadSafeArray& operator=(FastArray<T> const& right)
        {
            Threading::ScopeLock lock(_mutex);

            _array = right;
            
            return *this;
        }

        FastThreadSafeArray& operator=(FastArray<T>&& right)
        {
            Threading::ScopeLock lock(_mutex);

            _array = std::move(right);
            
            return *this;
        }

        FastThreadSafeArray& operator=(FastThreadSafeArray const& right)
        {
            Threading::ScopeLock lock1(_mutex);
            Threading::ScopeLock lock2(const_cast<Threading::Mutex&>(right._mutex));

            _array = right._array;
            
            return *this;
        }

        FastThreadSafeArray& operator=(FastThreadSafeArray&& right) noexcept
        {
            Threading::ScopeLock lock1(_mutex);
            Threading::ScopeLock lock2(right._mutex);

            _array = std::move(right._array);

            return *this;
        }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]]
        T& operator[] (ssize_t index) noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _array[index];
        }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]]
        T const& operator[] (ssize_t index) const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array[index];
        }

        [[nodiscard]] constexpr T* begin() noexcept { return _array.begin(); }
        [[nodiscard]] constexpr const T* begin() const noexcept { return _array.begin(); }
        [[nodiscard]] constexpr T* end() noexcept { return _array.end(); }
        [[nodiscard]] constexpr const T* end() const noexcept { return _array.end(); }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]]
        T& At(ssize_t index)
        {
            Threading::ScopeLock lock(_mutex);

            return _array.At(index);
        }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]] T const& At(ssize_t index) const
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.At(index);
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T& Back() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _array.Back();
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T const& Back() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.Back();
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T& BackUnsafe() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _array.BackUnsafe();
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T const& BackUnsafe() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.BackUnsafe();
        }

        /// @brief 指定した値が含まれるかを判定
        /// @param value 値
        [[nodiscard]]
        bool Contains(T const& value) const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.Contains(value);
        }

        /// @brief 配列へのポインター
        [[nodiscard]]
        T* Data() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _array.Data();
        }

        /// @brief 配列へのポインター
        [[nodiscard]]
        const T* Data() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.Data();
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        T& Front() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _array.Front();
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        T const& Front() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.Front();
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        T& FrontUnsafe() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _array.FrontUnsafe();
        }

        [[nodiscard]]
        T const& FrontUnsafe() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.FrontUnsafe();
        }

        /// @brief 指定した要素の番号を取得
        /// @param value 値
        /// @return 要素番号、要素が見つからなかった場合はCollectionHelper::NotFound()
        [[nodiscard]]
        ssize_t IndexOf(T const& value) const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.IndexOf(value);
        }

        /// @brief コレクションが空かを判定
        [[nodiscard]]
        bool IsEmpty() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.IsEmpty();
        }

        /// @brief 要素数
        [[nodiscard]]
        ssize_t Length() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.Length();
        }

        /// @brief 配列へのポインター
        [[nodiscard]]
        const T* Pointer() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _array.Pointer();
        }

        /// @brief 要素数を変更
        /// @attention MemoryAllocationExceptionが発生した場合はオブジェクトは変更されないよ！
        /// @param length 変更後の要素数
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Resize(ssize_t length) requires ::std::default_initializable<T>
        {
            Threading::ScopeLock lock(_mutex);

            _array.Resize(length);
        }
        
        /// @brief 要素数を変更
        /// @attention MemoryAllocationExceptionが発生した場合はオブジェクトは変更されないよ！
        /// @param length 変更後の要素数
        /// @param defaultValue 新たに追加される要素の初期値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: メモリの確保に失敗したとき
        void Resize(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T>
        {
            Threading::ScopeLock lock(_mutex);

            _array.Resize(length, defaultValue);
        }

        /// @brief 要素を逆順に入れ替え
        void Reverse() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            _array.Reverse();
        }

        private:

        FastArray<T> _array;
        Threading::Mutex _mutex;

        template <class U>
        friend bool operator==(FastThreadSafeArray<U> const&, FastThreadSafeArray<U> const&) noexcept;
    };

    template <class T>
    [[nodiscard]] bool operator==(FastThreadSafeArray<T> const& left, FastThreadSafeArray<T> const& right) noexcept
    {
        Threading::ScopeLock lock1(const_cast<Threading::Mutex&>(left._mutex));
        Threading::ScopeLock lock2(const_cast<Threading::Mutex&>(right._mutex));

        return left._array == right._array;
    }

    template <class T>
    [[nodiscard]] bool operator!=(FastThreadSafeArray<T> const& left, FastThreadSafeArray<T> const& right) noexcept
    {
        return !(left == right);
    }
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAY_H
