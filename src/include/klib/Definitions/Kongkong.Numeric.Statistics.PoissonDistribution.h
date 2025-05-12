#ifndef KONGKONG_NUMERIC_STATISTICS_POISSONDISTRIBUTION_H
#define KONGKONG_NUMERIC_STATISTICS_POISSONDISTRIBUTION_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    struct PoissonDistribution : public ValueType {

        [[nodiscard]]
        static PoissonDistribution CreateUnsafe(TNum lambda) noexcept { return PoissonDistribution(lambda, true); }

        explicit PoissonDistribution(TNum lambda);

        [[nodiscard]]
        TNum operator()(uint64_t n) const noexcept;

        [[nodiscard]]
        constexpr TNum Lambda() const noexcept { return m_lambda; }

        [[nodiscard]]
        constexpr TNum Mean() const noexcept { return m_lambda; }

        [[nodiscard]]
        String ToString() const;

        private:
        TNum m_lambda;
        TNum m_co;

        PoissonDistribution(TNum lambda, bool) noexcept;

        template <::std::floating_point UNum>
        friend constexpr bool operator==(PoissonDistribution const&, PoissonDistribution const&) noexcept;

        template <::std::floating_point UNum>
        friend constexpr bool operator!=(PoissonDistribution const&, PoissonDistribution const&) noexcept;
    };

    template <::std::floating_point TNum>
    [[nodiscard]] constexpr bool operator==(PoissonDistribution<TNum> const& left, PoissonDistribution<TNum> const& right) noexcept { return left.m_lambda == right.m_lambda; }

    template <::std::floating_point TNum>
    [[nodiscard]] constexpr bool operator!=(PoissonDistribution<TNum> const& left, PoissonDistribution<TNum> const& right) noexcept { return left.m_lambda != right.m_lambda; }
}

#endif //!KONGKONG_NUMERIC_STATISTICS_POISSONDISTRIBUTION_H
