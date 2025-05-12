#ifndef KONGKONG_NUMERIC_STATISTICS_NORMALDISTRIBUTION_H
#define KONGKONG_NUMERIC_STATISTICS_NORMALDISTRIBUTION_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Numeric.Statistics._normalDistributionBase.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    struct NormalDistribution : public ValueType, public _normalDistributionBase<TNum> {

        [[nodiscard]]
        constexpr NormalDistribution CreateUnsafe(TNum mean, TNum variance) noexcept { return NormalDistribution(mean, variance, 0); }

        explicit NormalDistribution(TNum mean, TNum variance);

        [[nodiscard]]
        TNum operator()(TNum x) const noexcept;

        /// @brief 平均値
        [[nodiscard]]
        constexpr TNum Mean() const noexcept { return _mean; }

        [[nodiscard]]
        String ToString() const;

        private:
        TNum _mean;

        NormalDistribution(TNum mean, TNum variance, int) noexcept;
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_NORMALDISTRIBUTION_H
