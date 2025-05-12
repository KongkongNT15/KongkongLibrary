#ifndef KONGKONG_CSTD_BUILTINARRAY_H
#define KONGKONG_CSTD_BUILTINARRAY_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief 組み込み配列の便利関数？
    class BuiltInArray final {
        public:

        STATIC_CLASS(BuiltInArray)

        /// @brief Find()で見つからなかった時の戻り値
        [[nodiscard]]
        static constexpr size_t NotFound() noexcept { return (size_t)-1; }

        /// @brief 配列のすべての要素を指定した値で埋める
        /// @tparam T 配列の要素の型
        /// @tparam N 要素数
        /// @param array 配列の参照
        /// @param value 置き換える値
        template <class T, size_t N>
        static void Fill(T(&array)[N], T const& value)
        {
            for (T& element : array) {
                element = value;
            }
        }

        /// @brief 配列内のメモリをすべてゼロ埋めする
        /// @tparam T 配列の要素の型
        /// @tparam N 要素数
        /// @param array 配列の参照
        template <class T, size_t N>
        static void FillWithZero(T(&array)[N]) noexcept
        {
            constexpr size_t size = sizeof(array);

            uint8_t* p = (uint8_t*)array;
            uint8_t* end = p + size;

            while (p != end) {
                *p = (uint8_t)0;
                ++p;
            }

        }

        /// @brief 指定したオブジェクトがある要素番号を取得
        /// @tparam T 要素の型
        /// @tparam N 要素数
        /// @param array 配列
        /// @param target 探すオブジェクト
        /// @return 要素番号、見つからない場合はNotFound()
        template <class T, size_t N>
        static size_t Find(T const(&array)[N], T const& target)
        {
            for (size_t i = 0; i < N; i++) {
                if (array[i] == target) return i;
            }

            return NotFound();
        }

        /// @brief 配列の要素数を取得
        /// @tparam T 配列の要素の型
        /// @tparam N 要素数
        /// @param array 配列の参照
        /// @return 配列の要素数
        template <class T, size_t N>
        [[nodiscard]] static constexpr size_t GetLength(const T(&array)[N]) noexcept { return N; }

    };
}

#endif //!KONGKONG_CSTD_BUILTINARRAY_H
