#ifndef KONGKONG_NUMERIC_STATISTICS_ZEROMEANNORMALDISTRIBUTION_H
#define KONGKONG_NUMERIC_STATISTICS_ZEROMEANNORMALDISTRIBUTION_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Numeric.Statistics._normalDistributionBase.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    /// @brief 平均値がゼロの正規分布
    /// @tparam TNum 数値型
    template <::std::floating_point TNum>
    struct ZeroMeanNormalDistribution : public ValueType, public _normalDistributionBase<TNum> {

        /// @brief 作成
        /// @param variance 分散
        [[nodiscard]]
        static ZeroMeanNormalDistribution CreateUnsafe(TNum variance) noexcept { return ZeroMeanNormalDistribution(variance, 0); }

        /// @brief 作成
        /// @param variance 分散
        /// @throws InvalidArgumentException: varianceがゼロ以下のとき
        explicit ZeroMeanNormalDistribution(TNum variance);

        /// @brief 指定した値の確率密度を取得
        /// @param x 値
        [[nodiscard]]
        TNum operator()(TNum x) const noexcept;

        /// @brief 指定した値の確率密度を取得
        /// @param x 値
        [[nodiscard]]
        TNum GetDensity(TNum x) const noexcept;

        /// @brief 平均値
        [[nodiscard]]
        constexpr TNum Mean() const noexcept { return (TNum)0.0; }

        /// @brief 分布の文字列表現を取得
        /// @return u"U(Mean(), Variance())"
        [[nodiscard]]
        String ToString() const;

        private:

        ZeroMeanNormalDistribution(TNum variance, int) noexcept;
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_ZEROMEANNORMALDISTRIBUTION_H
