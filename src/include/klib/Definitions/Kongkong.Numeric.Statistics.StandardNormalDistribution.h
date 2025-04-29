#ifndef KONGKONG_NUMERIC_STATISTICS_STANDARDNORMALDISTRIBUTION_H
#define KONGKONG_NUMERIC_STATISTICS_STANDARDNORMALDISTRIBUTION_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    class StandardNormalDistribution final {
        public:
        using ResultType = TNum;

        STATIC_CLASS(StandardNormalDistribution)

#if KONGKONG_HAS_CPP23

        [[nodiscard]]
        static TNum operator()(TNum x) noexcept;

#endif //KONGKONG_HAS_CPP23

        [[nodiscard]]
        static TNum GetDensity(TNum x) noexcept;

        [[nodiscard]]
        static constexpr TNum Mean() noexcept { return (TNum)0.0; }

        [[nodiscard]]
        static constexpr TNum Variance() noexcept { return (TNum)1.0; }
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_STANDARDNORMALDISTRIBUTION_H
