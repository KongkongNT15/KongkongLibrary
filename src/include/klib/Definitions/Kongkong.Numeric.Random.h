#ifndef KONGKONG_NUMERIC_RANDOM_H
#define KONGKONG_NUMERIC_RANDOM_H

#include "Base.h"
#include "Kongkong.Numeric.RandomBase.h"

#include <limits>
#include <random>

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    struct Random : public RandomBase {
        Random();
        explicit Random(int64_t seed);

        double NextDouble() noexcept override;
        int64_t _nextInt64Unsafe(int64_t minValue, int64_t maxValue) noexcept override;

        String ToString() const override;

        std::mt19937_64 _mt64;
        std::uniform_real_distribution<> _urd;

        static constexpr int64_t _int64MaxValue = std::numeric_limits<int64_t>::max();
    };
}

namespace KONGKONG_NAMESPACE::Numeric
{
    class Random : public RandomBase {
        public:
        using ImplType = IMPLEMENTATION::Random;

        Random();
        explicit Random(int64_t seed);
        constexpr Random(std::nullptr_t) noexcept : RandomBase(nullptr) {}

    };
}

#endif //!KONGKONG_NUMERIC_RANDOM_H
