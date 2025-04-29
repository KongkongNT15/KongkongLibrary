#ifndef KONGKONG_COLLECTIONS_TURBO_BUILTINARRAY_H
#define KONGKONG_COLLECTIONS_TURBO_BUILTINARRAY_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.Collections.Turbo._builtInArrayBase.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
    struct BuiltInArray : public ValueType, public _builtInArrayBase<T, N> {

        BuiltInArray() noexcept(::std::is_nothrow_constructible_v<T>) requires ::std::default_initializable<T>
        {
            auto p = this->Data();
            auto e = end();

            if constexpr (::std::is_nothrow_constructible_v<T>) {
                while (p != e) {
                    new (p) T();
                    ++p;
                }
            }
            else {
                try {
                    while (p != e) {
                        new (p) T();
                        ++p;
                    }
                }
                catch (...) {
                    Algorithms::Range::DestoryUnsafe(this->Data(), p);
    
                    ::std::rethrow_exception(::std::current_exception());
                }
            }

            
        }

        BuiltInArray(T const& value) noexcept(::std::is_nothrow_copy_constructible_v<T>) requires ::std::copy_constructible<T>
        {
            auto p = this->Data();
            auto e = end();

            if constexpr (::std::is_nothrow_copy_constructible_v<T>) {
                while (p != e) {
                    new (p) T(value);
                    ++p;
                }
            }
            else {
                try {
                    while (p != e) {
                        new (p) T(value);
                        ++p;
                    }
                }
                catch (...) {
                    Algorithms::Range::DestoryUnsafe(this->Data(), p);
    
                    ::std::rethrow_exception(::std::current_exception());
                }
            }

            
        }

        BuiltInArray(T&& value) noexcept(::std::is_nothrow_copy_constructible_v<T>) requires (::std::copy_constructible<T> && ::std::move_constructible<T>)
        {
            auto p = this->Data();
            auto e = end() - 1;

            if constexpr (::std::is_nothrow_copy_constructible_v<T>) {
                while (p != e) {
                    new (p) T(value);
                    ++p;
                }
            }
            else {
                try {
                    while (p != e) {
                        new (p) T(value);
                        ++p;
                    }
                }
                catch (...) {
                    Algorithms::Range::DestoryUnsafe(this->Data(), p);
    
                    ::std::rethrow_exception(::std::current_exception());
                }
            }

            new (e) T(::std::move(value));
        }

        template <class... Args> requires (2 <= sizeof...(Args) && sizeof...(Args) <= N)
        BuiltInArray(Args&&... args)
        {
            constexpr ssize_t length = sizeof...(Args);

            _create(this->Data(), ::std::forward<Args>(args)...);

            if constexpr (length == N) {
                return;
            }
            else {
                auto p = this->Data() + length;
                auto e = end();
                
                try {
                    while (p != e) {
                        new (p) T();
                        ++p;
                    }
                }
                catch (...) {
                    Algorithms::Range::DestoryUnsafe(this->Data(), p);
                    ::std::rethrow_exception(::std::current_exception());
                }
            }
        }

        BuiltInArray(BuiltInArray const& right) noexcept(::std::is_nothrow_copy_constructible_v<T>) requires ::std::copy_constructible<T>
        {
            auto p = this->Data();
            auto e = end();
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
                    Algorithms::Range::DestoryUnsafe(this->Data(), p);
                    ::std::rethrow_exception(::std::current_exception());
                }
            }
            
        }

        BuiltInArray(BuiltInArray&& right) noexcept
        {
            auto p = this->Data();
            auto e = end();
            auto pRight = right.Data();

            while (p != e) {
                new (p) T(::std::move(*pRight));
                ++p;
                ++pRight;
            }
        }

        ~BuiltInArray()
        {
            Algorithms::Range::DestoryUnsafe(this->Data(), end());
        }

        BuiltInArray& operator=(BuiltInArray const& right) noexcept(::std::is_nothrow_copy_assignable_v<T>) requires ::std::is_copy_assignable_v<T>
        {
            auto p = this->Data();
            auto e = end();
            auto pRight = right.Data();

            if constexpr (::std::is_nothrow_copy_assignable_v<T>) {
                while (p != e) {
                    *p = *pRight;
                    ++p;
                    ++pRight;
                }
            }
            else {
                try {
                    while (p != e) {
                        *p = *pRight;
                        ++p;
                        ++pRight;
                    }
                }
                catch (...) {
                    Algorithms::Range::DestoryUnsafe(this->Data(), p);
                    ::std::rethrow_exception(::std::current_exception());
                }
            }
            
        }

        BuiltInArray& operator=(BuiltInArray&& right) noexcept requires ::std::is_move_assignable_v<T>
        {
            auto p = this->Data();
            auto e = end();
            auto pRight = right.Data();

            while (p != e) {
                *p = ::std::move(*pRight);
                ++p;
                ++pRight;
            }
        }

        [[nodiscard]] constexpr T* end() noexcept { return this->Data() + N; }
        [[nodiscard]] constexpr const T* end() const noexcept { return this->Data() + N; }

        [[nodiscard]]
        T& At(ssize_t index)
        {
            CollectionHelper::CheckIndex(index, N);
            return this->Data()[index];
        }

        [[nodiscard]]
        T const& At(ssize_t index) const
        {
            CollectionHelper::CheckIndex(index, N);
            return this->Data()[index];
        }

        [[nodiscard]] T& Back() noexcept { return this->Data()[N - 1]; }
        [[nodiscard]] T const& Back() const noexcept { return this->Data()[N - 1]; }

        [[nodiscard]]
        constexpr bool Contains(T const& value) const noexcept
        {
            return Algorithms::Range::ContainsUnsafe(value, this->Data(), this->Data() + N);
        }

        [[nodiscard]] T& Front() noexcept { return *(this->Data()); }
        [[nodiscard]] T const& Front() const noexcept { return *(this->Data()); }

        template <ssize_t NIndex> requires (0 <= NIndex && NIndex < N)
        [[nodiscard]] constexpr T& GetAt() noexcept { return this->Data()[NIndex]; }

        template <ssize_t NIndex> requires (0 <= NIndex && NIndex < N)
        [[nodiscard]] constexpr T const& GetAt() const noexcept { return this->Data()[NIndex]; }

        [[nodiscard]]
        constexpr ssize_t IndexOf(T const& value) const noexcept
        {
            return Algorithms::Range::IndexOfUnsafe(value, this->Data(), N);
        }

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return N; }

        void Reverse() noexcept
        {
            if constexpr (N == 1) return;

            Algorithms::Range::ReverseUnsafe(N, this->Data());
        }

        private:

        template <class U, class... Args>
        void _create(T* p, U const& value, Args&&... args)
        {
            try {
                new (p) T(value);
            }
            catch (...) {
                Algorithms::Range::DestoryUnsafe(this->Data(), p);

                ::std::rethrow_exception(::std::current_exception());
            }
            if constexpr (sizeof...(Args) != 0) _create(p + 1, ::std::forward<Args>(args)...);
        }

        template <class U, class... Args>
        void _create(T* p, U&& value, Args&&... args)
        {
            if constexpr (::std::same_as<T, U>) {
                new (p) T(::std::move(value));
            }
            else {
                try {
                    new (p) T(::std::move(value));
                }
                catch (...) {
                    Algorithms::Range::DestoryUnsafe(this->Data(), p);
    
                    ::std::rethrow_exception(::std::current_exception());
                }
            }
            if constexpr (sizeof...(Args) != 0) _create(p + 1, ::std::forward<Args>(args)...);
        }
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_BUILTINARRAY_H
