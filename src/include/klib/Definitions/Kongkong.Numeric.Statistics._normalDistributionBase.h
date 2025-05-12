#ifndef KONGKONG_NUMERIC_STATISTICS_NORMALDISTRIBUTIONBASE_H
#define KONGKONG_NUMERIC_STATISTICS_NORMALDISTRIBUTIONBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    struct _normalDistributionBase {
        using ResultType = TNum;

        [[nodiscard]]
        constexpr TNum Variance() const noexcept { return _variance; }

        private:
        TNum _variance;
        TNum _co1;
        TNum _co2;

        _normalDistributionBase(TNum variance);
        _normalDistributionBase(TNum variance, int) noexcept;

        friend NormalDistribution<TNum>;

        friend ZeroMeanNormalDistribution<TNum>;
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_NORMALDISTRIBUTIONBASE_H
