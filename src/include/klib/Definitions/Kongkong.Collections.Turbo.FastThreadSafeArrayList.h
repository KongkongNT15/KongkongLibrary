#ifndef KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYLIST_H
#define KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYLIST_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo._fastThreadSafeArrayListMethods.h"
#include "Kongkong.Collections.Turbo.FastArrayList.h"
#include "Kongkong.Threading.Mutex.h"
#include "Kongkong.Threading.ScopeLock.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastThreadSafeArrayList final : public ValueType, public _fastThreadSafeArrayMethods {

        FastThreadSafeArrayList() : _list(), _mutex() {}

        /// @brief 要素数を指定して作成
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit FastThreadSafeArrayList(ssize_t length) requires ::std::default_initializable<T>
            : _list(length), _mutex()
        {
        }

        /// @brief 要素数と初期値を指定して作成
        /// @param length 長さ
        /// @param defaultValue 初期値
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit FastThreadSafeArrayList(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T>
            : _list(length, defaultValue), _mutex()
        {
        }

        /// @brief 初期化リストから作成
        /// @param inil 初期化リスト
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        FastThreadSafeArrayList(std::initializer_list<T> const& inil) requires ::std::copy_constructible<T>
            : _list(inil), _mutex()
        {
        }

        FastThreadSafeArrayList(FastArrayList<T> const& list) : _list(list), _mutex()
        {
        }

        FastThreadSafeArrayList(FastArrayList<T>&& list) : _list(std::move(list)), _mutex()
        {
        }

        FastThreadSafeArrayList(FastThreadSafeArrayList const& right) : _list(nullptr), _mutex()
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(right._mutex));

            new (&_list) FastArrayList<T>(right._list);
        }

        FastThreadSafeArrayList(FastThreadSafeArrayList&& right) noexcept : _list(nullptr), _mutex(std::move(right._mutex))
        {
            Threading::ScopeLock lock(_mutex);
            
            new (&_list) FastArrayList<T>(std::move(right._list));
        }

        FastThreadSafeArrayList& operator=(FastArrayList<T> const& right)
        {
            Threading::ScopeLock lock(_mutex);

            _list = right;
            
            return *this;
        }

        FastThreadSafeArrayList& operator=(FastArrayList<T>&& right)
        {
            Threading::ScopeLock lock(_mutex);

            _list = std::move(right);
            
            return *this;
        }

        FastThreadSafeArrayList& operator=(FastThreadSafeArrayList const& right)
        {
            Threading::ScopeLock lock1(_mutex);
            Threading::ScopeLock lock2(const_cast<Threading::Mutex&>(right._mutex));

            _list = right._list;
            
            return *this;
        }

        FastThreadSafeArrayList& operator=(FastThreadSafeArrayList&& right) noexcept
        {
            Threading::ScopeLock lock1(_mutex);
            Threading::ScopeLock lock2(right._mutex);

            _list = std::move(right._list);

            return *this;
        }

        FastThreadSafeArrayList& operator+=(T const& value) requires ::std::copy_constructible<T>
        {
            Threading::ScopeLock lock(_mutex);

            _list.Append(value);

            return *this;
        }

        FastThreadSafeArrayList& operator+=(T&& value) requires ::std::move_constructible<T>
        {
            Threading::ScopeLock lock(_mutex);

            _list.Append(::std::move(value));
            
            return *this;
        }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]]
        T& operator[] (ssize_t index) noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _list[index];
        }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]]
        T const& operator[] (ssize_t index) const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list[index];
        }

        [[nodiscard]] constexpr T* begin() noexcept { return _list.begin(); }
        [[nodiscard]] constexpr const T* begin() const noexcept { return _list.begin(); }
        [[nodiscard]] constexpr T* end() noexcept { return _list.end(); }
        [[nodiscard]] constexpr const T* end() const noexcept { return _list.end(); }

        void Append() requires ::std::default_initializable<T>
        {
            Threading::ScopeLock lock(_mutex);

            _list.Append();
        }

        void Append(T const& value) requires ::std::copy_constructible<T>
        {
            Threading::ScopeLock lock(_mutex);

            _list.Append(value);
        }

        void Append(T&& value) requires ::std::move_constructible<T>
        {
            Threading::ScopeLock lock(_mutex);

            _list.Append(::std::move(value));
        }

        void Append(FastArrayList<T> const& list) requires ::std::copy_constructible<T>
        {
            Threading::ScopeLock lock(_mutex);

            _list.Append(list);
        }

        void Append(FastArrayList<T>&& list) requires ::std::move_constructible<T>
        {
            Threading::ScopeLock lock(_mutex);

            _list.Append(std::move(list));
        }

        void Append(FastThreadSafeArrayList const& list) requires ::std::copy_constructible<T>
        {
            Threading::ScopeLock lock(_mutex);
            Threading::ScopeLock lock2(const_cast<Threading::Mutex&>(list._mutex));

            _list.Append(list._list);
        }

        void Append(FastThreadSafeArrayList&& list) requires ::std::move_constructible<T>
        {
            Threading::ScopeLock lock1(_mutex);
            Threading::ScopeLock lock2(list._mutex);

            _list.Append(std::move(list._list));
        }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]]
        T& At(ssize_t index)
        {
            Threading::ScopeLock lock(_mutex);

            return _list.At(index);
        }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]] T const& At(ssize_t index) const
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.At(index);
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T& Back() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _list.Back();
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T const& Back() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.Back();
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T& BackUnsafe() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _list.BackUnsafe();
        }

        /// @brief 最後の要素を取得
        [[nodiscard]]
        T const& BackUnsafe() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.BackUnsafe();
        }

        /// @brief 容量
        [[nodiscard]]
        ssize_t Capacity() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.Capacity();
        }

        void Capacity(ssize_t newCapacity)
        {
            Threading::ScopeLock lock(_mutex);

            _list.Capacity(newCapacity);
        }

        /// @brief 要素をすべて削除
        void Clear() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            _list.Clear();
        }

        /// @brief 指定した値が含まれるかを判定
        /// @param value 値
        [[nodiscard]]
        bool Contains(T const& value) const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.Contains(value);
        }

        /// @brief 配列へのポインター
        [[nodiscard]]
        T* Data() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _list.Data();
        }

        /// @brief 配列へのポインター
        [[nodiscard]]
        const T* Data() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.Data();
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        T& Front() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _list.Front();
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        T const& Front() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.Front();
        }

        /// @brief 最初の要素を取得
        [[nodiscard]]
        T& FrontUnsafe() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _list.FrontUnsafe();
        }

        [[nodiscard]]
        T const& FrontUnsafe() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.FrontUnsafe();
        }

        /// @brief 指定した要素の番号を取得
        /// @param value 値
        /// @return 要素番号、要素が見つからなかった場合はCollectionHelper::NotFound()
        [[nodiscard]]
        ssize_t IndexOf(T const& value) const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.IndexOf(value);
        }

        void Insert(ssize_t index, T const& value)
        {
            Threading::ScopeLock lock(_mutex);

            _list.Insert(index, value);
        }

        void Insert(ssize_t index, T&& value)
        {
            Threading::ScopeLock lock(_mutex);

            _list.Insert(index, std::move(value));
        }

        /// @brief コレクションが空かを判定
        [[nodiscard]]
        bool IsEmpty() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.IsEmpty();
        }

        /// @brief 要素数
        [[nodiscard]]
        ssize_t Length() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.Length();
        }

        /// @brief 配列へのポインター
        [[nodiscard]]
        const T* Pointer() const noexcept
        {
            Threading::ScopeLock lock(const_cast<Threading::Mutex&>(_mutex));

            return _list.Pointer();
        }

        /// @brief 指定した要素を削除
        /// @return 要素を削除すればtrue
        /// @return 指定した要素が見つからなければfalse
        bool Remove(T const& value) noexcept
        {
            Threading::ScopeLock lock(_mutex);

            return _list.Remove(value);
        }

        void RemoveAt(ssize_t index)
        {
            Threading::ScopeLock lock(_mutex);

            _list.RemoveAt(index);
        }

        void RemoveAtUnsafe(ssize_t index) noexcept
        {
            Threading::ScopeLock lock(_mutex);

            _list.RemoveAtUnsafe(index);
        }

        void RemoveBack()
        {
            Threading::ScopeLock lock(_mutex);

            _list.RemoveBack();
        }

        void RemoveBackUnsafe() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            _list.RemoveBackUnsafe();
        }

        void RemoveFront()
        {
            Threading::ScopeLock lock(_mutex);

            _list.RemoveFront();
        }

        void RemoveFrontUnsafe() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            _list.RemoveFrontUnsafe();
        }

        /// @brief 要素を逆順に入れ替え
        void Reverse() noexcept
        {
            Threading::ScopeLock lock(_mutex);

            _list.Reverse();
        }

        void SetCapacityUnsafe(ssize_t newCapacity)
        {
            Threading::ScopeLock lock(_mutex);

            _list.SetCapacityUnsafe(newCapacity);
        }

        void ShrinkToFit()
        {
            Threading::ScopeLock lock(_mutex);

            _list.ShrinkToFit();
        }

        private:
        FastArrayList<T> _list;
        Threading::Mutex _mutex;

        template <class U>
        friend bool operator==(FastThreadSafeArrayList<U> const&, FastThreadSafeArrayList<U> const&) noexcept;
    };

    template <class T>
    [[nodiscard]] bool operator==(FastThreadSafeArrayList<T> const& left, FastThreadSafeArrayList<T> const& right) noexcept
    {
        Threading::ScopeLock lock1(const_cast<Threading::Mutex&>(left._mutex));
        Threading::ScopeLock lock2(const_cast<Threading::Mutex&>(right._mutex));

        return left._list == right._list;
    }

    template <class T>
    [[nodiscard]] bool operator!=(FastThreadSafeArrayList<T> const& left, FastThreadSafeArrayList<T> const& right) noexcept
    {
        return !(left == right);
    }
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYLIST_H
