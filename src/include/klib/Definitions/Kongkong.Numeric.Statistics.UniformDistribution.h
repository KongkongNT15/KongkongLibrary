#ifndef KONGKONG_NUMERIC_STATISTICS_UNIFORMDISTRIBUTION_H
#define KONGKONG_NUMERIC_STATISTICS_UNIFORMDISTRIBUTION_H

#include "Base.h"
#include "Kongkong.ValueType.h"

#define GET_DENSITY(value) \
    if (_min <= x && x <= _max) return _p;\
    return 0

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    struct UniformDistribution : public ValueType {
        using ResultType = TNum;

        [[nodiscard]]
        constexpr UniformDistribution CreateUnsafe(TNum min, TNum max) noexcept { return UniformDistribution(min, max, 0); }

        explicit UniformDistribution(TNum min, TNum max);

        [[nodiscard]]
        constexpr TNum operator()(TNum x) const noexcept { GET_DENSITY(x); }

        [[nodiscard]]
        constexpr TNum GetDensity(TNum x) const noexcept { GET_DENSITY(x); }

        [[nodiscard]]
        constexpr TNum Max() const noexcept { return _max; }

        [[nodiscard]]
        constexpr TNum Min() const noexcept { return _min; }

        [[nodiscard]]
        String ToString() const;

        private:
        TNum _min;
        TNum _max;
        TNum _p;

        constexpr UniformDistribution(TNum min, TNum max, int) noexcept : _min(min), _max(max), _p((TNum)1.0 / (max - min)) {}

        template <class T>
        friend constexpr bool operator==(UniformDistribution<T> const&, UniformDistribution<T> const&) noexcept;

        template <class T>
        friend constexpr bool operator!=(UniformDistribution<T> const&, UniformDistribution<T> const&) noexcept;
    };

    template <::std::floating_point TNum>
    [[nodiscard]] constexpr bool operator==(UniformDistribution<TNum> const& left, UniformDistribution<TNum> const& right) noexcept { return left._max == right._max && left._min == right._min; }

    template <::std::floating_point TNum>
    [[nodiscard]] constexpr bool operator!=(UniformDistribution<TNum> const& left, UniformDistribution<TNum> const& right) noexcept { return left._max != right._max || left._min != right._min; }
}

#undef GET_DENSITY

#endif //!KONGKONG_NUMERIC_STATISTICS_UNIFORMDISTRIBUTION_H
