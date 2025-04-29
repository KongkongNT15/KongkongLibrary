#ifndef KONGKONG_COLLECTIONS_TURBO_FASTPOINTERLIST_H
#define KONGKONG_COLLECTIONS_TURBO_FASTPOINTERLIST_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo._fastPointerListMethods.h"
#include "Kongkong.Collections.Turbo.ConstFastPointerArrayIterator.h"
#include "Kongkong.Collections.Turbo.FastPointerArrayIterator.h"
#include "Kongkong.Collections.Turbo._fastCollection.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastPointerList final : public ValueType, public _fastPointerListMethods, public _fastCollection {

        static FastPointerList CreateWithCapacity(ssize_t capacity)
        {
            CollectionHelper::CheckLength(capacity);

            return CreateWithCapacityUnsafe(capacity);
        }

        static FastPointerList CreateWithCapacityUnsafe(ssize_t capacity)
        {
            FastPointerList list = nullptr;

            list._p = (T**)::malloc(capacity * sizeof(T*));

            MemoryAllocationException::CheckNull(list._p);

            list._length = 0;
            list._capacity = capacity;

            return list;
        }

        FastPointerList() : _fastCollection(0), _p((T**)::malloc(CollectionHelper::DefaultCapacity() * sizeof(T*))), _capacity(CollectionHelper::DefaultCapacity())
        {
            MemoryAllocationException::CheckNull(_p);
        }

        FastPointerList(ssize_t length) requires ::std::default_initializable<T> : _fastCollection(length)
        {
            CollectionHelper::CheckLength(length);

            _capacity = CollectionHelper::CreateCapacity(length);

            _p = (T**)::malloc(_capacity * sizeof(T*));

            MemoryAllocationException::CheckNull(_p);

            auto p = _p;
            auto end = p + length;

            while (p != end) {
                try {
                    T* instance = NEW T();

                    MemoryAllocationException::CheckNull(instance);

                    *p = instance;
                }
                catch (...) {
                    auto q = _p;

                    while (q != p) {
                        delete *q;
                        q++;
                    }

                    ::free(_p);

                    ::std::rethrow_exception(::std::current_exception());
                }
                
                p++;
            }
        }

        FastPointerList(ssize_t length, T const& defaultValue) requires ::std::copy_constructible<T> : _fastCollection(length)
        {
            CollectionHelper::CheckLength(length);

            _capacity = CollectionHelper::CreateCapacity(length);

            _p = (T**)::malloc(_capacity * sizeof(T*));

            MemoryAllocationException::CheckNull(_p);

            auto p = _p;
            auto end = p + length;

            while (p != end) {
                try {
                    T* instance = NEW T(defaultValue);

                    MemoryAllocationException::CheckNull(instance);

                    *p = instance;
                }
                catch (...) {
                    auto q = _p;

                    while (q != p) {
                        delete *q;
                        q++;
                    }

                    ::free(_p);

                    ::std::rethrow_exception(::std::current_exception());
                }
                
                p++;
            }
        }

        FastPointerList(std::initializer_list<T> const& inil) requires ::std::copy_constructible<T> : _fastCollection((ssize_t)inil.size())
        {
            _capacity = CollectionHelper::CreateCapacity((ssize_t)inil.size());

            _p = (T**)::malloc(_capacity * sizeof(T*));

            MemoryAllocationException::CheckNull(_p);

            auto p = _p;

            for (T const& value : inil) {
                try {
                    T* instance = NEW T(value);

                    MemoryAllocationException::CheckNull(instance);

                    *p = instance;
                }
                catch (...) {
                    auto q = _p;

                    while (q != p) {
                        delete *q;
                        q++;
                    }

                    ::free(_p);

                    ::std::rethrow_exception(::std::current_exception());
                }
                
                p++;
            }
        }

        FastPointerList(FastPointerList const& right) requires ::std::copy_constructible<T> : _fastCollection(right._length), _p((T**)::malloc(right._capaicty * sizeof(T*))), _capacity(right._capacity)
        {
            MemoryAllocationException::CheckNull(_p);

            for (ssize_t i = 0; i < this->_length; i++) {
                try {
                    T* instance = NEW T(*right._p[i]);
                    
                    MemoryAllocationException::CheckNull(instance);

                    _p[i] = instance;
                }
                catch (...) {
                    for (ssize_t j = 0; j < i; j++) {
                        delete _p[j];
                    }

                    ::free(_p);

                    ::std::rethrow_exception(::std::current_exception());
                }
            }
        }

        FastPointerList(FastPointerList&& right) noexcept : _fastCollection(right._length), _p(right._p), _capacity(right._capacity)
        {
            right._p = nullptr;
        }

        ~FastPointerList()
        {
            if (_p == nullptr) return;

            auto p = _p;
            auto end = p + this->_length;

            while (p != end) {
                delete *p;
                p++;
            }

            ::free(_p);
        }

        /// @brief 
        /// @param right 
        /// @return 
        FastPointerList& operator=(FastPointerList const& right) requires ::std::copy_constructible<T>
        {
            return *this = FastPointerList(right);
        }

        FastPointerList& operator=(FastPointerList&& right) noexcept
        {
            FastPointerList::~FastPointerList();

            _p = right._p;
            this->_length = right._length;
            _capacity = right._capacity;

            right._p = nullptr;

            return *this;
        }

        FastPointerList& operator+=(T const& value) requires ::std::copy_constructible<T>
        {
            Append(value);

            return *this;
        }

        FastPointerList& operator+=(T&& value) requires ::std::move_constructible<T>
        {
            Append(::std::move(value));
            
            return *this;
        }

        FastPointerList& operator+=(FastPointerList const& list) requires ::std::copy_constructible<T>
        {
            Append(list);

            return *this;
        }

        FastPointerList& operator+=(FastPointerList&& list) requires ::std::move_constructible<T>
        {
            Append(::std::move(list));
            
            return *this;
        }

        /// @brief 指定した番号の要素を取得
        /// @attention 範囲外の要素を指定した場合の動作は未定義だよ
        /// @param index 要素番号
        [[nodiscard]] constexpr T& operator[] (ssize_t index) noexcept { return *_p[index]; }
        [[nodiscard]] constexpr T const& operator[] (ssize_t index) const noexcept { return *_p[index]; }

        [[nodiscard]] constexpr FastPointerArrayIterator<T> begin() noexcept { return FastPointerArrayIterator<T>(_p); }
        [[nodiscard]] constexpr ConstFastPointerArrayIterator<T> begin() const noexcept { return ConstFastPointerArrayIterator<T>((const T**)_p); }
        [[nodiscard]] constexpr FastPointerArrayIterator<T> end() noexcept { return FastPointerArrayIterator<T>(_p + this->_length); }
        [[nodiscard]] constexpr ConstFastPointerArrayIterator<T> end() const noexcept { return ConstFastPointerArrayIterator<T>((const T**)(_p + this->_length)); }

        void Append() requires ::std::default_initializable<T>
        {
            Emplace();
        }

        void Append(T const& value) requires ::std::copy_constructible<T>
        {
            Emplace<T const&>(value);
        }

        void Append(T&& value) requires ::std::move_constructible<T>
        {
            Emplace<T&&>(std::move(value));
        }

        void Append(FastPointerList const& list) requires ::std::copy_constructible<T>
        {
            if (list._length == 0) [[unlikely]] return;

            ssize_t oldLength = this->_length;

            //ここでthis->_lengthが書き変わる
            _increaseLength(list._length);

            for (ssize_t i = 0; i < list._length; i++) {
                try {
                    T* tmp = NEW T(*list._p[i]);

                    MemoryAllocationException::CheckNull(tmp);

                    _p[oldLength + i] = tmp;
                }
                catch (...) {

                    for (ssize_t j = oldLength, k = oldLength + i; j < k; j++) {
                        delete _p[j];
                    }

                    this->_length = oldLength;

                    ::std::rethrow_exception(::std::current_exception());
                }
            }
        }

        void Append(FastPointerList&& list) requires ::std::copy_constructible<T>
        {
            if (list._length == 0) [[unlikely]] return;

            ssize_t oldLength = this->_length;

            //ここでthis->_lengthが書き変わる
            _increaseLength(list._length);

            for (ssize_t i = 0; i < list._length; i++) {
                _p[oldLength + i] = list._p[i];
            }

            ::free(list._p);
            list._p = nullptr;
        }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]]
        T& At(ssize_t index)
        {
            CollectionHelper::CheckIndex(index, _length);
            return *_p[index];
        }

        /// @brief 指定した番号の要素を取得
        /// @param index 要素番号
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        [[nodiscard]] T const& At(ssize_t index) const
        {
            CollectionHelper::CheckIndex(index, _length);
            return *_p[index];
        }

        /// @brief 最後の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T& Back()
        {
            CollectionHelper::CheckBackFront(this->_length);
            return *_p[this->_length - 1];
        }

        /// @brief 最後の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T const& Back() const
        {
            CollectionHelper::CheckBackFront(this->_length);
            return *_p[this->_length - 1];
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
        void Clear() noexcept
        {
            auto p = _p;
            auto end = p + _length;

            while (p != end) {
                delete *p;
                p++;
            }

            this->_length = 0;
        }

        /// @brief 指定した値が含まれるかを判定
        /// @param value 値
        [[nodiscard]]
        bool Contains(T const& value) const noexcept
        {
            auto p = _p;
            auto end = p + _length;

            while (p != end) {
                if (**p == value) return true;
                p++;
            }

            return false;
        }

        /// @brief 配列へのポインター
        [[nodiscard]] constexpr T** Data() noexcept { return _p; }
        [[nodiscard]] constexpr const T** Data() const noexcept { return (const T**)_p; }

        template <class... Args>
        void Emplace(Args&&... args)
        {
            ssize_t oldLength = this->_length;
            _increaseLength();

            try {
                T* instance = NEW T(std::forward<Args>(args)...);

                MemoryAllocationException::CheckNull(instance);

                _p[oldLength] = instance;
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

            if (index == this->_length) [[unlikely]] {
                Emplace<Args...>(::std::forward<Args>(args)...);
                return;
            }

            ssize_t oldLength = this->_length;

            _increaseLength();

            T* tmp = _p[index];
            try {
                T* instance = NEW T(::std::forward<Args>(args)...);

                MemoryAllocationException::CheckNull(instance);

                _p[index] = instance;
            }
            catch (...) {
                _p[index] = tmp;

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
            return *_p[0];
        }

        /// @brief 最初の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T const& Front() const
        {
            CollectionHelper::CheckBackFront(this->_length);
            return *_p[0];
        }

        /// @brief 最後の要素を取得
        [[nodiscard]] constexpr T& GetBackUnsafe() noexcept { return *_p[this->_length - 1]; }
        [[nodiscard]] constexpr T const& GetBackUnsafe() const noexcept { return *_p[this->_length - 1]; }

        /// @brief 最初の要素を取得
        [[nodiscard]] constexpr T& GetFrontUnsafe() noexcept { return **_p; }
        [[nodiscard]] constexpr T const& GetFrontUnsafe() const noexcept { return **_p; }

        /// @brief 指定した要素の番号を取得
        /// @param value 値
        /// @return 要素番号、要素が見つからなかった場合はCollectionHelper::NotFound()
        [[nodiscard]]
        ssize_t IndexOf(T const& value) const noexcept
        {
            auto p = _p;
            auto end = p + _length;

            while (p != end) {
                if (**p == value) return true;
                p++;
            }

            return CollectionHelper::NotFound();
        }

        void Insert(ssize_t index, T const& value)
        {
            EmplaceAt<T const&>(index, value);
        }

        void Insert(ssize_t index, T&& value)
        {
            EmplaceAt<T&&>(index, std::move(value));
        }

        /// @brief リストが空かを判定
        [[nodiscard]]
        constexpr bool IsEmpty() const noexcept { return this->_length != 0; }

        /// @brief 配列へのポインター
        [[nodiscard]]
        constexpr const T** Pointer() const noexcept { return (const T**)_p; }

        /// @brief 指定した要素を削除
        /// @return 要素を削除すればtrue
        /// @return 指定した要素が見つからなければfalse
        bool Remove(T const& value) noexcept
        {
            for (ssize_t i = 0; i < this->_length; ++i) {
                if (*_p[i] == value) {
                    delete _p[i];
                    for (ssize_t j = i + 1; j < this->_length; ++j) {
                        _p[j - 1] = _p[j];
                    }
                    --this->_length;
                    return true;
                }
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
            delete _p[index];

            ssize_t length = this->_length - 1;

            for (ssize_t i = index; i < length; ++i) {
                _p[i] = _p[i + 1];
            }

            --this->_length;
        }

        void RemoveBack()
        {
            CollectionHelper::CheckBackFront(this->_length);
            RemoveBackUnsafe();
        }

        void RemoveBackUnsafe() noexcept
        {
            delete _p[this->_length - 1];

            --this->_length;
        }

        void RemoveFront()
        {
            CollectionHelper::CheckBackFront(this->_length);
            RemoveFrontUnsafe();
        }

        void RemoveFrontUnsafe() noexcept
        {
            //delete _p[0];
            delete *_p;

            ssize_t length = this->_length - 1;

            // 全ての要素を手前にずらす
            for (ssize_t i = 0; i < length; ++i) {
                _p[i] = _p[i + 1];
            }

            this->_length = length;
        }

        void Reverse() noexcept
        {
            if (this->_length == 0 || this->_length == 1) return;

            ssize_t millde = _length / 2 + 1;
            ssize_t back = _length - 1;

            for (ssize_t i = 0; i < millde; i++) {
                T* tmp = _p[i];
                _p[i] = _p[back - i];
                _p[back - i] = tmp;
            }
        }

        void SetCapacityUnsafe(ssize_t newCapacity)
        {
            if (newCapacity == _capacity) [[unlikely]] return;

            ssize_t i;
            T** p = (T**)::malloc(newCapacity * sizeof(T*));
            
            MemoryAllocationException::CheckNull(p);

            if (newCapacity < this->_length) {
                for (i = newCapacity; i < this->_length; i++) {
                    delete _p[i];
                }

                this->_length = newCapacity;
            }

            for (i = 0; i < this->_length; i++) {
                p[i] = _p[i];
            }

            ::free(this->_p);

            this->_p = p;
            _capacity = newCapacity;
        }

        void ShrinkToFit()
        {
            if (this->_length == 0) [[unlikely]] {
                ::free(_p);
                _capacity = 0;
                return;
            }

            T** p = (T**)::realloc(_p, this->_length * sizeof(T*));

            MemoryAllocationException::CheckNull(p);

            ::free(_p);

            _p = p;
            this->_capacity = this->_length;
        }

        private:
        ssize_t _capacity;
        T** _p;

        constexpr FastPointerList(::std::nullptr_t) noexcept {}

        void _increaseLength(ssize_t append = 1)
        {
            ssize_t newLength = this->_length + append;

            if (newLength > _capacity) {
                ssize_t newCapacity = CollectionHelper::CreateCapacity(newLength);
                T** p = (T**)::realloc(_p, newCapacity * sizeof(T*));

                MemoryAllocationException::CheckNull(p);

                _p = p;
                _capacity = newCapacity;
            }

            this->_length = newLength;
        }

        void _insertSwap(ssize_t index, ssize_t oldLength, T* tmp) noexcept
        {
            for (ssize_t i = index + 1; i < oldLength; i++) {
                T* tmp1 = _p[i];
                _p[i] = tmp;
                tmp = tmp1;
            }

            _p[oldLength] = tmp;
        }
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTPOINTERLIST_H
