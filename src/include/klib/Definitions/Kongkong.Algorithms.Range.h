#ifndef KONGKONG_ALGORITHMS_RANGE_H
#define KONGKONG_ALGORITHMS_RANGE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Algorithms
{
    class Range final {
        public:
        STATIC_CLASS(Range)

        template <class T>
        [[nodiscard]]
        static bool ContainsUnsafe(T const& target, Collections::Iterators::Iterator<T> const& begin, Collections::Iterators::Iterator<T> const& end) { return _contains<T, Collections::Iterators::Iterator<T>>(target, begin, end); }

        template <class T>
        [[nodiscard]]
        static bool ContainsUnsafe(T const& target, Collections::Iterators::ConstIterator<T> const& begin, Collections::Iterators::ConstIterator<T> const& end) { return _contains<T, Collections::Iterators::ConstIterator<T>>(target, begin, end); }

        template <class T>
        [[nodiscard]] static constexpr bool ContainsUnsafe(T const& target, const T* begin, const T* end) noexcept { return _contains<T, const T*>(target, begin, end); }

        template <class T>
        [[nodiscard]] static constexpr bool ContainsUnsafe(T const& target, const T** begin, const T** end) noexcept
        {
            const T** p = begin;
            
            while (p != end) {
                if (**p == target) return true;
                ++p;
            }

            return false;
        }

        template <class T>
        static void DestoryUnsafe(T* begin, T* end) noexcept
        {
            T* p = begin;

            while (p != end) {
                p->~T();
                ++p;
            }
        }

        template <class T>
        static constexpr ssize_t IndexOfUnsafe(T const& target, const T* begin, ssize_t length) noexcept
        {
            const T* p = begin;
            const T* end = p + length;

            while (p != end) {
                if (*p == target) return p - begin;
                ++p;
            }

            return NotFound();
        }

        /// @brief 2つのアドレスが指す位置の内容が等しいかを判定します
        /// @param length 長さ
        /// @param left アドレス
        /// @param right アドレス
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        /// @throws ArgumentNullException: leftがnullptrのとき
        /// @throws ArgumentNullException: rightがnullptrのとき
        [[nodiscard]]
        static bool IsEqual(ssize_t length, const void* left, const void* right);

        /// @brief 2つのアドレスが指す位置の内容が等しいかを判定します
        /// @param length 長さ
        /// @param left アドレス
        /// @param right アドレス
        [[nodiscard]]
        static bool IsEqualUnsafe(ssize_t length, const void* left, const void* right) noexcept;

        [[nodiscard]]
        static constexpr ssize_t NotFound() noexcept { return -1; }

        template <class T>
        static void RemoveAtUnsafe(ssize_t index, T* begin, ssize_t length) noexcept
        {
            T* p = begin + index;
            p->~T();

            T* end = begin + length;
            p++;

            while (p != end) {
                new (p - 1) T(::std::move(*p));
                p->~T();
                ++p;
            }

        }

        template <class T>
        static bool RemoveUnsafe(T const& value, T* begin, ssize_t length) noexcept
        {
            T* p = begin;
            T* end = p + length;

            while (p != end) {
                if (*p == value) {
                    p->~T();

                    for (T* q = p + 1; q != end; ++q) {
                        new (q - 1) T(::std::move(*q));
                        q->~T();
                    }

                    return true;
                }
                ++p;
            }

            return false;
        }

        template <class T>
        static void ReverseUnsafe(ssize_t length, T* p) noexcept
        {
            ssize_t millde = length / 2 + 1;
            ssize_t back = length - 1;

            for (ssize_t i = 0; i < millde; i++) {
                T tmp = std::move(p[i]);
                p[i].~T();
                new (p + i) T(::std::move(p[back - i]));
                p[back - i].~T();
                new (p + (back - i)) T(::std::move(tmp));
            }
        }

        private:

        template <class TElement, class TIterator>
        static constexpr bool _contains(TElement const& target, TIterator p, TIterator end)
        {
            while (p != end) {
                if (*p == target) return true;
                ++p;
            }

            return false;
        }

        
    };

}

#endif //!KONGKONG_ALGORITHMS_RANGE_H
