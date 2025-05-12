#ifndef KONGKONG_COLLECTIONS_TURBO_FASTARRAYLIST_H
#define KONGKONG_COLLECTIONS_TURBO_FASTARRAYLIST_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Turbo._fastArrayBase.h"
#include "Kongkong.Collections.Turbo._fastArrayListMethods.h"
#include "Kongkong.Algorithms.Range.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastArrayList : public ValueType, public _fastArrayBase<T>, public _fastArrayListMethods {

        static FastArrayList CreateWithCapacity(ssize_t capacity)
        {
            CollectionHelper::CheckLength(capacity);

            return CreateWithCapacityUnsafe(capacity);
        }

        static FastArrayList CreateWithCapacityUnsafe(ssize_t capacity)
        {
            FastArrayList list = nullptr;

            list._p = (T*)::malloc(capacity * sizeof(T));

            MemoryAllocationException::CheckNull(list._p);

            list._length = 0;
            list._capacity = capacity;

            return list;
        }

        FastArrayList() : _fastArrayBase<T>(0, (T*)::malloc(CollectionHelper::DefaultCapacity() * sizeof(T))), _capacity(CollectionHelper::DefaultCapacity())
        {
            MemoryAllocationException::CheckNull(this->_p);
        }

        explicit FastArrayList(ssize_t length) requires ::std::default_initializable<T> : _fastArrayBase<T>(length)
        {
            CollectionHelper::CheckLength(length);

            _capacity = CollectionHelper::CreateCapacity(length);

            this->_p = (T*)::malloc(_capacity * sizeof(T));

            MemoryAllocationException::CheckNull(this->_p);

            auto p = this->_p;
            auto end = p + length;

            while (p != end) {
                try {
                    new (p) T();
                }
                catch (...) {
                    auto q = this->_p;

                    while (q != p) {
                        q->~T();
                        q++;
                    }

                    ::free(this->_p);

                    ::std::rethrow_exception(::std::current_exception());
                }
                
                p++;
            }
        }

        explicit FastArrayList(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T> : _fastArrayBase<T>(length)
        {
            CollectionHelper::CheckLength(length);

            _capacity = CollectionHelper::CreateCapacity(length);

            this->_p = (T*)::malloc(_capacity * sizeof(T));

            MemoryAllocationException::CheckNull(this->_p);

            auto p = this->_p;
            auto end = p + length;

            while (p != end) {
                try {
                    new (p) T(defaultValue);
                }
                catch (...) {
                    auto q = this->_p;

                    while (q != p) {
                        q->~T();
                        q++;
                    }

                    ::free(this->_p);

                    ::std::rethrow_exception(::std::current_exception());
                }
                
                p++;
            }
        }

        FastArrayList(std::initializer_list<T> const& inil) requires ::std::copy_constructible<T> : _fastArrayBase<T>((ssize_t)inil.size())
        {
            _capacity = CollectionHelper::CreateCapacity((ssize_t)inil.size());

            this->_p = (T*)::malloc(_capacity * sizeof(T));

            MemoryAllocationException::CheckNull(this->_p);

            auto p = this->_p;

            for (T const& value : inil) {
                try {
                    new (p) T(value);
                }
                catch (...) {
                    auto q = this->_p;

                    while (q != p) {
                        q->~T();
                        q++;
                    }

                    ::free(this->_p);

                    ::std::rethrow_exception(::std::current_exception());
                }
                
                p++;
            }
        }

        FastArrayList(FastArrayList const& right) requires ::std::copy_constructible<T> : _fastArrayBase<T>(right._length, (T*)::malloc(right._capacity * sizeof(T))), _capacity(right._capacity)
        {
            MemoryAllocationException::CheckNull(this->_p);

            for (ssize_t i = 0; i < this->_length; i++) {
                try {
                    new (this->_p + i) T(right._p[i]);
                }
                catch (...) {
                    for (ssize_t j = 0; j < i; j++) {
                        this->_p[j].~T();
                    }

                    ::free(this->_p);

                    ::std::rethrow_exception(::std::current_exception());
                }
            }
        }

        constexpr FastArrayList(FastArrayList&& right) noexcept : _fastArrayBase<T>(right._length, right._p), _capacity(right._capacity)
        {
            right._p = nullptr;
        }

        ~FastArrayList()
        {
            this->_destroy();
        }

        /// @brief 
        /// @param right 
        /// @return 
        FastArrayList& operator=(FastArrayList const& right) requires ::std::copy_constructible<T>
        {
            if constexpr (::std::is_nothrow_copy_constructible<T>::value) {
                if (right._length < this->_length) {
                    ssize_t i;

                    for (i = right._length; i < this->_length; i++) {
                        this->_p[i].~T();
                    }

                    for (i = 0; i < right._length; i++) {
                        this->_p[i] = right._p[i];
                    }

                    return *this;
                }
            }
            
            return *this = FastArrayList(right);
        }

        FastArrayList& operator=(FastArrayList&& right) noexcept
        {
            this->_destroy();

            this->_p = right._p;
            this->_length = right._length;
            _capacity = right._capacity;

            right._p = nullptr;

            return *this;
        }

        FastArrayList& operator+=(T const& value) requires ::std::copy_constructible<T>
        {
            Append(value);

            return *this;
        }

        FastArrayList& operator+=(T&& value) requires ::std::move_constructible<T>
        {
            Append(::std::move(value));
            return *this;
        }

        FastArrayList& operator-=(T const& value) noexcept
        {
            Remove(value);
            return *this;
        }

        void Append() requires ::std::default_initializable<T>
        {
            ssize_t oldLength = this->_length;
            _increaseLength();

            try {
                new (this->_p + oldLength) T();
            }
            catch (...) {
                this->_length = oldLength;

                ::std::rethrow_exception(::std::current_exception());
            }
        }

        void Append(T const& value) requires ::std::copy_constructible<T>
        {
            ssize_t oldLength = this->_length;
            _increaseLength();

            try {
                new (this->_p + oldLength) T(value);
            }
            catch (...) {
                this->_length = oldLength;

                ::std::rethrow_exception(::std::current_exception());
            }
        }

        void Append(T&& value) requires ::std::move_constructible<T>
        {
            ssize_t oldLength = this->_length;
            _increaseLength();

            new (this->_p + oldLength) T(std::move(value));
        }

        void Append(FastArrayList const& list) requires ::std::copy_constructible<T>
        {
            if (list._length == 0) [[unlikely]] return;

            ssize_t oldLength = this->_length;

            //ここでthis->_lengthが書き変わる
            _increaseLength(list._length);

            for (ssize_t i = 0; i < list._length; i++) {
                try {
                    new (this->_p + oldLength + i) T(list._p[i]);
                }
                catch (...) {

                    for (ssize_t j = oldLength, k = oldLength + i; j < k; j++) {
                        this->_p[j].~T();
                    }

                    this->_length = oldLength;

                    std::rethrow_exception(std::current_exception());
                }

                
            }
        }

        void Append(FastArrayList&& list) requires ::std::move_constructible<T>
        {
            if (list._length == 0) [[unlikely]] return;

            ssize_t oldLength = this->_length;

            //ここでthis->_lengthが書き変わる
            _increaseLength(list._length);

            for (ssize_t i = 0; i < list._length; i++) {
                new (this->_p + oldLength + i) T(std::move(list._p[i]));
            }

            ::free(list._p);
            list._p = nullptr;
        }

        /// @brief 最後の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T& Back()
        {
            CollectionHelper::CheckBackFront(this->_length);
            return this->_p[this->_length - 1];
        }

        /// @brief 最後の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T const& Back() const
        {
            CollectionHelper::CheckBackFront(this->_length);
            return this->_p[this->_length - 1];
        }

        /// @brief 容量
        [[nodiscard]]
        constexpr ssize_t Capacity() const noexcept { return _capacity; }

        void Capacity(ssize_t newCapacity)
        {
            CollectionHelper::CheckCapacity(newCapacity);

            SetCapacityUnsafe(newCapacity);
        }

        /// @brief 要素をすべて削除
        constexpr void Clear() noexcept
        {
            auto p = this->_p;
            auto end = p + this->_length;

            while (p != end) {
                p->~T();
                p++;
            }
            
            this->_length = 0;
        }

        template <class... Args>
        void Emplace(Args&&... args)
        {
            ssize_t oldLength = this->_length;
            _increaseLength();

            try {
                new (this->_p + oldLength) T(::std::forward<Args>(args)...);
            }
            catch (...) {
                this->_length = oldLength;

                ::std::rethrow_exception(::std::current_exception());
            }
        }

        template <class... Args>
        void EmplaceAt(ssize_t index, Args&&... args)
        {
            CollectionHelper::CheckIndex(index, this->_length + 1);
            EmplaceAtUnsafe(index, ::std::forward<Args>(args)...);
        }

        template <class... Args>
        void EmplaceAtUnsafe(ssize_t index, Args&&... args)
        {
            if (index == this->_length) [[unlikely]] {
                Emplace<Args...>(::std::forward<Args>(args)...);
                return;
            }

            ssize_t oldLength = this->_length;

            _increaseLength();

            T tmp = std::move(this->_p[index]);
            try {
                new (this->_p + index) T(::std::forward<Args>(args)...);
            }
            catch (...) {
                new (this->_p + index) T(std::move(tmp));

                ::std::rethrow_exception(::std::current_exception());
            }

            _insertSwap(index, oldLength, tmp);
        }

        /// @brief 最初の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T& Front()
        {
            CollectionHelper::CheckBackFront(this->_length);
            return this->_p[0];
        }

        /// @brief 最初の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T const& Front() const
        {
            CollectionHelper::CheckBackFront(this->_length);
            return this->_p[0];
        }

        void Insert(ssize_t index, T const& value)
        {
            EmplaceAt<T const&>(index, value);
        }

        void Insert(ssize_t index, T&& value)
        {
            EmplaceAt<T&&>(index, ::std::move(value));
        }

        void InsertUnsafe(ssize_t index, T const& value)
        {
            EmplaceAtUnsafe<T const&>(index, value);
        }

        void InsertUnsafe(ssize_t index, T&& value)
        {
            EmplaceAtUnsafe<T&&>(index, ::std::move(value));
        }

        /// @brief 指定した要素を削除
        /// @return 要素を削除すればtrue
        /// @return 指定した要素が見つからなければfalse
        bool Remove(T const& value) noexcept
        {
            if (Algorithms::Range::RemoveUnsafe(value, this->begin(), this->_length)) {
                --this->_length;
                return true;
            }

            return false;
        }

        void RemoveAt(ssize_t index)
        {
            CollectionHelper::CheckIndex(index, this->_length);

            RemoveAtUnsafe(index);
        }

        void RemoveAtUnsafe(ssize_t index) noexcept
        {
            Algorithms::Range::RemoveAtUnsafe(index, this->_p, this->_length);

            --this->_length;
        }

        void RemoveBack()
        {
            CollectionHelper::CheckBackFront(this->_length);
            RemoveBackUnsafe();
        }

        void RemoveBackUnsafe() noexcept
        {
            this->_p[this->_length - 1].~T();

            --this->_length;
        }

        void RemoveFront()
        {
            CollectionHelper::CheckBackFront(this->_length);
            RemoveFrontUnsafe();
        }

        void RemoveFrontUnsafe() noexcept
        {
            this->_p->~T();

            ssize_t length = this->_length - 1;

            // 全ての要素を手前にずらす
            for (ssize_t i = 0; i < length; ++i) {
                new (this->_p + i) T(std::move(this->_p[i + 1]));
            }

            this->_length = length;
        }

        void Reverse() noexcept
        {
            if (this->_length == 0 || this->_length == 1) return;

            Algorithms::Range::ReverseUnsafe(this->_length, this->_p);
        }

        void SetCapacityUnsafe(ssize_t newCapacity)
        {
            if (newCapacity == _capacity) [[unlikely]] return;

            ssize_t i;
            T* p = (T*)::malloc(newCapacity * sizeof(T));
            
            MemoryAllocationException::CheckNull(p);

            if (newCapacity < this->_length) {
                for (i = 0; i < newCapacity; i++) {
                    new (p + i) T(std::move(this->_p[i]));
                }

                for (; i < this->_length; i++) {
                    this->_p[i].~T();
                }

                this->_length = newCapacity;
            }
            else {
                for (i = 0; i < this->_length; i++) {
                    new (p + i) T(std::move(this->_p[i]));
                }
            }

            ::free(this->_p);

            this->_p = p;
            _capacity = newCapacity;
        }

        void ShrinkToFit()
        {
            if (this->_length == 0) [[unlikely]] {
                ::free(this->_p);
                _capacity = 0;
                return;
            }
            
            T* p = (T*)::malloc(this->_length * sizeof(T));

            MemoryAllocationException::CheckNull(p);

            for (ssize_t i = 0; i < this->_length; i++) {
                new (p + i) T(std::move(this->_p[i]));
            }

            ::free(this->_p);

            this->_p = p;
            this->_capacity = this->_length;
        }

        private:
        ssize_t _capacity;

        constexpr FastArrayList(::std::nullptr_t) noexcept {}
        constexpr FastArrayList(ssize_t capacity, ssize_t length, T* p) noexcept : _fastArrayBase<T>(length, p), _capacity(capacity) {}

        void _increaseLength(ssize_t append = 1)
        {
            ssize_t newLength = this->_length + append;

            if (newLength > _capacity) {
                ssize_t newCapacity = CollectionHelper::CreateCapacity(newLength);

                T* p = (T*)::malloc(newCapacity * sizeof(T));

                MemoryAllocationException::CheckNull(p);

                for (ssize_t i = 0; i < this->_length; i++) {
                    new (p + i) T(std::move(this->_p[i]));
                }

                ::free(this->_p);

                this->_p = p;
                _capacity = newCapacity;
            }

            this->_length = newLength;
        }

        void _insertSwap(ssize_t index, ssize_t oldLength, T& tmp) noexcept
        {
            for (ssize_t i = index + 1; i < oldLength; i++) {
                T tmp1 = std::move(this->_p[i]);
                new (this->_p + i) T(std::move(tmp));
                new (&tmp) T(std::move(tmp1));
            }

            new (this->_p + oldLength) T(std::move(tmp));
        }

        friend ArrayHelper;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTARRAYLIST_H
