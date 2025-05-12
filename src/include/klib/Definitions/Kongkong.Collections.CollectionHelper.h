#ifndef KONGKONG_COLLECTIONS_COLLECTIONHELPER_H
#define KONGKONG_COLLECTIONS_COLLECTIONHELPER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections
{
    class CollectionHelper final {
        public:
        static void CheckBackFront(ssize_t length);

        static void CheckCapacity(ssize_t capacity);

        /// @brief 要素番号が範囲内かを判定
        /// @attention lengthにゼロ以下を指定しないでね！
        /// @param index 要素番号
        /// @param length バッファーの長さ
        /// @throws InvalidArgumentException: indexが負の値のとき
        /// @throws ArgumentOutOfRangeException: indexが範囲外のとき
        static void CheckIndex(ssize_t index, ssize_t length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(int8_t length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(short length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(int length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(long length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(long long length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(uint8_t length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(unsigned short length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(unsigned int length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(unsigned long length);

        /// @brief 引数に与えられた値が適切かを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthがゼロ以下のとき
        static void CheckLength(unsigned long long length);

        /// @brief 引数に与えられた長さが負の値でないかを判定
        /// @param length 長さ
        /// @throws InvalidArgumentException: lengthが負の値の時
        static void CheckMinusLength(ssize_t length);

        static constexpr ssize_t CreateCapacity(ssize_t length) noexcept { return ((length / _defaultCapacity) + 1) * _defaultCapacity; }
        static constexpr ssize_t CreateCapacity(ssize_t length, ssize_t defaultCapacity) noexcept { return ((length / defaultCapacity) + 1) * defaultCapacity; }

        [[nodiscard]]
        static constexpr ssize_t DefaultCapacity() noexcept { return _defaultCapacity; }

        /// @brief コンテナ型のFind()、IndexOf()などで要素が見つからなかった時の戻り値
        [[nodiscard]]
        static constexpr ssize_t NotFound() noexcept { return -1; }

        private:
        static constexpr ssize_t _defaultCapacity = 16;
    };
}

#endif //!KONGKONG_COLLECTIONS_COLLECTIONHELPER_H
