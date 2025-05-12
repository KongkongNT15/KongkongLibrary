#ifndef KONGKONG_CSTD_CRANDOMGENERATOR_H
#define KONGKONG_CSTD_CRANDOMGENERATOR_H

#include "Base.h"

#include <stdlib.h>

namespace KONGKONG_NAMESPACE::CStd
{
    /// @brief C標準の乱数生成器
    class CRandomGenerator final {
        public:

        STATIC_CLASS(CRandomGenerator)

        /// @brief 乱数の最大値を取得
        [[nodiscard]]
        static constexpr int MaxValue() noexcept { return RAND_MAX; }

        /// @brief 乱数の最小値を取得
        [[nodiscard]]
        static constexpr int MinValue() noexcept { return 0; }

        /// @brief 乱数を生成
        /// @return 生成された乱数
        [[nodiscard]] static int Next() noexcept;

        /// @brief 乱数を生成
        /// @return 生成された乱数 (0 <= result < maxValue)
        /// @throws InvalidArgumentException: maxValueが負の値のとき
        [[nodiscard]] static int Next(int maxValue);

        /// @brief 乱数を生成
        /// @return 生成された乱数 (0 <= minValue < result < maxValue)
        /// @throws InvalidArgumentException: minValueが負の値のとき minValue > maxValueのとき
        [[nodiscard]] static int Next(int minValue, int maxValue);

        /// @brief 乱数のシード値を設定
        /// @param seed シード値
        static void Seed(unsigned seed) noexcept;
    };
}

#endif //!KONGKONG_CSTD_CRANDOMGENERATOR_H
