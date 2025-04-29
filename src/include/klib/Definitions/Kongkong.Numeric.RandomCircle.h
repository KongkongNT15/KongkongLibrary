#ifndef KONGKONG_NUMERIC_RANDOMCIRCLE_H
#define KONGKONG_NUMERIC_RANDOMCIRCLE_H

#include "Base.h"
#include "Kongkong.Numeric.RandomCircleBase.h"

#include <random>

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    //円の中に一様な点を生成
    struct RandomCircle final : public RandomCircleBase {

        explicit RandomCircle(double radius);
        explicit RandomCircle(double radius, unsigned seed);

        [[nodiscard]]
        Vector2Double Next() noexcept override;

        void Seed() noexcept;
        void Seed(unsigned seed) noexcept;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const override;

        private:

        std::mt19937 _mt;
        std::uniform_real_distribution<> _urd;
    };

}

namespace KONGKONG_NAMESPACE::Numeric
{
    //円の中に一様な点を生成
    class RandomCircle final : public RandomCircleBase {
        public:
        using ImplType = IMPLEMENTATION::RandomCircle;

        explicit RandomCircle(double radius);
        explicit RandomCircle(double radius, unsigned seed);

        /// @brief nullptrとして作成
        constexpr RandomCircle(std::nullptr_t) noexcept : RandomCircleBase(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_NUMERIC_RANDOMCIRCLE_H
