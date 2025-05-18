#ifndef KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYLIST_H
#define KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYLIST_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo._fastBuiltInArrayListMethods.h"
#include "Kongkong.Collections.Turbo._fastCollection.h"
#include "Kongkong.Collections.Turbo._builtInArrayBase.h"
#include "Kongkong.Collections.CollectionHelper.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
    struct BuiltInArrayList final : public ValueType, public _fastBuiltInArrayListMethods, public _fastCollection, public _builtInArrayBase<T, N> {

        constexpr BuiltInArrayList() noexcept : _fastCollection(0) {}
        BuiltInArrayList(::std::initializer_list<T> const& list) : BuiltInArrayList(list.size(), list.begin(), 0) {}

        template <ssize_t N1 = N>
        BuiltInArrayList(BuiltInArrayList<T, N1> const& right) : BuiltInArrayList(right.Length(), right.Data(), 0) {}

        template <ssize_t N1 = N>
        BuiltInArrayList(BuiltInArrayList<T, N1>&& right) : BuiltInArrayList(right.Length(), right.Data(), false) {}

        ~BuiltInArrayList()
        {
            s_finalize();
        }

        template <ssize_t N1 = N>
        BuiltInArrayList& operator=(BuiltInArrayList<T, N1> const& right) noexcept(::std::is_nothrow_copy_constructible_v<T>)
        {
            s_finalize();
            ssize_t minLength = N < right.Length() ? N : right.Length();

            auto p = this->Data();
            auto e = p + minLength;
            auto pRight = right.Data();

            if constexpr (::std::is_nothrow_copy_constructible_v<T>) {
                while (p != e) {
                    new (p) T(*pRight);
                    ++p;
                    ++pRight;
                }
            }
            else {
                try {
                    while (p != e) {
                        new (p) T(*pRight);
                        ++p;
                        ++pRight;
                    }
                }
                catch (...) {
                    this->_length = p - this->Data();

                    ::std::rethrow_exception(::std::current_exception());
                }
            }

            this->_length = minLength;
        }

        template <ssize_t N1 = N>
        BuiltInArrayList& operator=(BuiltInArrayList<T, N1>&& right) noexcept
        {
            s_finalize();;
            ssize_t minLength = N < right.Length() ? N : right.Length();

            auto p = this->Data();
            auto e = p + minLength;
            auto pRight = right.Data();

            while (p != e) {
                new (p) T(::std::move(*pRight));
                ++p;
                ++pRight;
            }

            this->_length = minLength;
        }

        BuiltInArrayList& operator+=(T const& value) noexcept(::std::is_nothrow_copy_assignable_v<T>) requires ::std::copy_constructible<T>
        {
            Append(value);
            return *this;
        }

        BuiltInArrayList& operator+=(T&& value) noexcept requires ::std::move_constructible<T>
        {
            Append(::std::move(value));
            return *this;
        }

        BuiltInArrayList& operator-=(T const& value) noexcept
        {
            Remove(value);
            return *this;
        }

        [[nodiscard]] constexpr T* end() noexcept { return this->Data() + this->_length; }
        [[nodiscard]] constexpr const T* end() const noexcept { return this->Data() + this->_length; }

        bool Append() noexcept(::std::is_nothrow_constructible_v<T>) requires ::std::default_initializable<T>
        {
            return Emplace();
        }

        bool Append(T const& value) noexcept(::std::is_nothrow_copy_constructible_v<T>) requires ::std::copy_constructible<T>
        {
            return Emplace<T const&>(value);
        }

        bool Append(T&& value) noexcept requires ::std::move_constructible<T>
        {
            return Emplace<T&&>(::std::move(value));
        }

        [[nodiscard]]
        T& At(ssize_t index)
        {
            CollectionHelper::CheckIndex(index, this->_length);
            return this->Data()[index];
        }

        [[nodiscard]]
        T const& At(ssize_t index) const
        {
            CollectionHelper::CheckIndex(index, this->_length);
            return this->Data()[index];
        }

        void Clear() noexcept
        {
            s_finalize();
            this->_length = 0;
        }

        [[nodiscard]]
        constexpr bool Contains(T const& value) const noexcept
        {
            return Algorithms::Range::ContainsUnsafe(value, this->Data(), this->Data() + this->_length);
        }

        template <class... Args>
        bool Emplace(Args&&... args) noexcept(noexcept(T(::std::forward<Args>(args)...)))
        {
#if KONGKONG_HAS_CPP23
            [[assume(0 <= this->_length && this->_length < N)]];
#endif
            if (this->_length == N) return false;

            new (this->Data() + this->_length) T(::std::forward<Args>(args)...);

            ++this->_length;

            return true;
        }

        template <class... Args>
        bool EmplaceAt(ssize_t index, Args&&... args)
        {
            CollectionHelper::CheckIndex(index, this->_length + 1);
            return EmplaceAtUnsafe(index, ::std::forward<Args>(args)...);
        }

        template <class... Args>
        bool EmplaceAtUnsafe(ssize_t index, Args&&... args) noexcept(noexcept(T(::std::forward<Args>(args)...)))
        {
#if KONGKONG_HAS_CPP23
            [[assume(0 <= this->_length && this->_length < N)]];
#endif
            if (index == this->_length) [[unlikely]] {
                return Emplace<Args&&...>(::std::forward<Args>(args)...);
            }

            if (this->_length == N) [[unlikely]] return false;

            T* p = this->Data();

            T tmp = std::move(p[index]);
            p[index].~T();
            try {
                new (p + index) T(::std::forward<Args>(args)...);
            }
            catch (...) {
                new (p + index) T(::std::move(tmp));

                ::std::rethrow_exception(::std::current_exception());
            }

            T* p1 = p + (index + 1);
            T* end = p + this->_length;

            while (p1 != end) {
                T tmp1 = ::std::move(*p1);
                p1->~T();
                new (p1) T(::std::move(tmp));
                tmp.~T();
                new (&tmp) T(::std::move(tmp1));
                ++p1;
            }

            ++this->_length;
        }

        /// @brief 最初の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T& Front()
        {
            CollectionHelper::CheckBackFront(this->_length);
            return *(this->Data());
        }

        /// @brief 最初の要素を取得
        /// @throws InvalidOperationException: コンテナが空のとき
        [[nodiscard]]
        T const& Front() const
        {
            CollectionHelper::CheckBackFront(this->_length);
            return *(this->Data());
        }

        [[nodiscard]] T& GetBackUnsafe() noexcept { return this->Data()[this->_length - 1]; }
        [[nodiscard]] T const& GetBackUnsafe() const noexcept { return this->Data()[this->_length - 1]; }

        [[nodiscard]] T& GetFrontUnsafe() noexcept { return *(this->Data()); }
        [[nodiscard]] T const& GetFrontUnsafe() const noexcept { return *(this->Data()); }

        [[nodiscard]]
        constexpr ssize_t IndexOf(T const& value) const noexcept
        {
            return Algorithms::Range::IndexOfUnsafe(value, this->Data(), this->_length);
        }

        bool Insert(ssize_t index, T const& value)
        {
            return EmplaceAt<T const&>(index, value);
        }

        bool Insert(ssize_t index, T&& value)
        {
            return EmplaceAt<T&&>(index, ::std::move(value));
        }

        bool InsertUnsafe(ssize_t index, T const& value) noexcept(::std::is_nothrow_copy_constructible_v<T>)
        {
            return EmplaceAtUnsafe<T const&>(index, value);
        }

        bool InsertUnsafe(ssize_t index, T&& value) noexcept
        {
            return EmplaceAtUnsafe<T&&>(index, ::std::move(value));
        }

        /// @brief 指定した要素を削除
        /// @return 要素を削除すればtrue
        /// @return 指定した要素が見つからなければfalse
        bool Remove(T const& value) noexcept
        {
            if (Algorithms::Range::RemoveUnsafe(value, this->Data(), this->_length)) {
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
            Algorithms::Range::RemoveAtUnsafe(index, this->Data(), this->_length);

            --this->_length;
        }

        void RemoveBack()
        {
            CollectionHelper::CheckBackFront(this->_length);
            RemoveBackUnsafe();
        }

        void RemoveBackUnsafe() noexcept
        {
            GetBackUnsafe().~T();

            --this->_length;
        }

        void RemoveFront()
        {
            CollectionHelper::CheckBackFront(this->_length);
            RemoveFrontUnsafe();
        }

        void RemoveFrontUnsafe() noexcept
        {
            this->Data()->~T();
            --this->_length;

            T* p = this->Data();
            T* e = p + this->_length;

            while (p != e) {
                new (p) T(*(p + 1));
                ++p;
                p->~T();
            }
        }

        void Reverse() noexcept
        {
#if KONGKONG_HAS_CPP23
            [[assume(this->_length >= 0)]];
#endif
            switch (this->_length) {
                case 0:
                case 1:
                    return;

                default:
                    Algorithms::Range::ReverseUnsafe(this->_length, this->Data());
                    break;
            }
#if KONGKONG_HAS_CPP23
            ::std::unreachable();
#endif
        }

        private:

        template <class TIterator>
        BuiltInArrayList(ssize_t length, TIterator&& itr, int)
        {
#if KONGKONG_HAS_CPP23
            [[assume(length >= 0)]];
#endif
            ssize_t maxlen = length < N ? length : N;
            this->_length = maxlen;

            T* pThis = this->Data();
            T* end = pThis + maxlen;

            while (pThis != end) {
                new (pThis) T(*itr);
                ++itr;
                ++pThis;
            }
        }

        template <class TIterator>
        BuiltInArrayList(ssize_t length, TIterator&& itr, bool)
        {
#if KONGKONG_HAS_CPP23
            [[assume(length >= 0)]];
#endif
            ssize_t maxlen = length < N ? length : N;
            this->_length = maxlen;

            T* pThis = this->Data();
            T* end = pThis + maxlen;

            while (pThis != end) {
                new (pThis) T(::std::move(*itr));
                ++itr;
                ++pThis;
            }
        }

        void s_finalize() noexcept
        {
            Algorithms::Range::DestoryUnsafe(this->Data(), end());
        }
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_BUILTINARRAYLIST_H
