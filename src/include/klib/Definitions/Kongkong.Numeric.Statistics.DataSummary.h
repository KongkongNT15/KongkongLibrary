#ifndef KONGKONG_NUMERIC_STATISTICS_DATASUMMARY_H
#define KONGKONG_NUMERIC_STATISTICS_DATASUMMARY_H

#include "Base.h"
#include "Kongkong.Collections.Turbo.FastArrayList.h"
#include "Kongkong.InvalidArgumentException.h"
#include "Kongkong.InvalidOperationException.h"
#include "Kongkong.Collections.KeyValuePair.h"
#include "Kongkong.Numeric.Statistics.Histogram.h"
#include "Kongkong.Numeric.Matrix.h"
#include <math.h>
#include <utility>

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <class TNum> requires NumberType<TNum> || ::std::same_as<TNum, void>
    struct DataSummary : public Collections::Turbo::FastArrayList<TNum> {
        using Base = Collections::Turbo::FastArrayList<TNum>;

        using Collections::Turbo::FastArrayList<TNum>::FastArrayList;

        /// @brief 平均値を計算
        /// @return 計算結果
        [[nodiscard]]
        constexpr TNum ComputeMeanUnsafe() const noexcept requires ::std::floating_point<TNum>
        {
            return Sum() / this->Length();
        }

        /// @brief 平均値を計算
        /// @return 計算結果
        [[nodiscard]]
        constexpr double ComputeMeanUnsafe() const noexcept
        {
            return (double)Sum() / this->Length();
        }

        /// @brief 分散を計算
        /// @return 計算結果
        [[nodiscard]]
        constexpr TNum ComputeVarianceUnsafe() const noexcept requires ::std::floating_point<TNum>
        {
            TNum mean = ComputeMeanUnsafe();
            TNum tmp;

            TNum bunsi{};

            for (TNum v : *this) {
                tmp = v - mean;
                bunsi += tmp * tmp;
            }

            return bunsi / this->Length();
        }

        /// @brief 分散を計算
        /// @return 計算結果
        [[nodiscard]]
        constexpr double ComputeVarianceUnsafe() const noexcept
        {
            double mean = ComputeMeanUnsafe();
            double tmp;

            double bunsi{};

            for (TNum v : *this) {
                tmp = v - mean;
                bunsi += tmp * tmp;
            }

            return bunsi / this->Length();
        }

        [[nodiscard]]
        Histogram<TNum> CreateHistogram(TNum minValue, TNum binWidth, ssize_t length) const
        {
            Histogram<TNum> histogram(minValue, binWidth, length);

            for (TNum v : *this) histogram += v;

            return histogram;
        }

        /// @brief 最大値
        /// @throws InvalidOperationException: データ数がゼロのとき
        [[nodiscard]]
        constexpr TNum Max() const
        {
            auto p = this->begin();
            auto e = this->end();

            if (p == e) [[unlikely]] throw InvalidOperationException(u"データがありません");

            TNum max = *p;
            ++p;

            while (p != e) {
                if (*p > max) max = p;

                ++p;
            }

            return max;
        }

        /// @brief 平均値
        /// @throws InvalidOperationException: データ数がゼロのとき
        [[nodiscard]]
        constexpr TNum Mean() const requires ::std::floating_point<TNum>
        {
            ssize_t length = this->Length();

            if (length == 0) [[unlikely]] throw InvalidOperationException(u"データがありません");

            return Sum() / length;
        }

        /// @brief 平均値
        /// @throws InvalidOperationException: データ数がゼロのとき
        [[nodiscard]]
        constexpr double Mean() const
        {
            ssize_t length = this->Length();

            if (length == 0) [[unlikely]] throw InvalidOperationException(u"データがありません");

            return (double)Sum() / length;
        }

        /// @brief 最小値
        /// @throws InvalidOperationException: データ数がゼロのとき
        [[nodiscard]]
        constexpr TNum Min() const
        {
            auto p = this->begin();
            auto e = this->end();

            if (p == e) [[unlikely]] throw InvalidOperationException(u"データがありません");

            TNum min = *p;
            ++p;

            while (p != e) {
                if (*p < min) min = p;

                ++p;
            }

            return min;
        }

        /// @brief 最小値と最大値のペアを取得
        /// @return { 最小値, 最大値 }
        [[nodiscard]]
        constexpr Collections::KeyValuePair<TNum, TNum> Range() const
        {
            auto p = this->begin();
            auto e = this->end();

            if (p == e) [[unlikely]] throw InvalidOperationException(u"データがありません");

            TNum min = *p;
            TNum max = *p;
            ++p;

            while (p != e) {
                if (*p < min) min = p;
                else if (*p > max) max = p;

                ++p;
            }

            return Collections::KeyValuePair<TNum, TNum>(min, max);
        }

        /// @brief 合計値
        [[nodiscard]]
        constexpr TNum Sum() const noexcept
        {
            TNum result{};
            for (TNum v : *this) {
                result += v;
            }

            return result;
        }

        /// @brief 分散
        [[nodiscard]]
        constexpr auto Variance() const
        {
            if (this->Length() == 0) [[unlikely]] throw InvalidOperationException(u"データがありません");

            return ComputeVarianceUnsafe();
        }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const
        {
            return String::FromPointerUnsafe(48, u"Kongkong::Numeric::Statistics::DataSummary<TNum>", true);
        }
    };

    template <>
    struct DataSummary<void> final {
        STATIC_CLASS(DataSummary)

        /// @brief 相関係数を計算
        /// @tparam TNum 数値型
        /// @tparam UNum 数値型
        /// @param left データ
        /// @param right データ
        template <NumberType TNum, NumberType UNum>
        [[nodiscard]] static auto ComputeCorrelationUnsafe(DataSummary<TNum> const& left, DataSummary<UNum> const& right) noexcept
        {
            auto lMean = left.ComputeMeanUnsafe();
            auto rMean = right.ComputeMeanUnsafe();

            auto pLeft = left.begin();
            auto pRight = right.begin();
            auto eLeft = left.end();

            decltype(lMean + rMean) bunsi{};
            decltype(lMean) lv{};
            decltype(lMean) lTmp;
            decltype(rMean) rv{};
            decltype(rMean) rTmp;

            while (pLeft != eLeft) {
                lTmp = *pLeft - lMean;
                rTmp = *pRight - rMean;

                bunsi += lTmp * rTmp;

                lv += lTmp * lTmp;
                rv += rTmp * rTmp;

                pLeft++;
                pRight++;
            }

            return bunsi / (::sqrt(lv * rv));
        }

        /// @brief 分散共分散行列を計算
        /// @tparam TNum 数値型
        /// @tparam UNum 数値型
        /// @param left データ
        /// @param right データ
        template <NumberType TNum, NumberType UNum>
        [[nodiscard]] static constexpr SquareMatrix<decltype(::std::declval<DataSummary<TNum>>().Variance() + ::std::declval<DataSummary<UNum>>().Variance()), 2> ComputeCovarianceMatrixUnsafe(DataSummary<TNum> const& left, DataSummary<UNum> const& right) noexcept
        {
            using NumType = decltype(::std::declval<DataSummary<TNum>>().Variance() + ::std::declval<DataSummary<UNum>>().Variance());
            auto q12 = ComputeCovarianceUnsafe(left, right);
            return SquareMatrix<NumType, 2>((NumType)left.ComputeVarianceUnsafe(), (NumType)q12, (NumType)q12, (NumType)right.ComputeVarianceUnsafe());
        }

        /// @brief 共分散を計算
        /// @tparam TNum 数値型
        /// @tparam UNum 数値型
        /// @param left データ
        /// @param right データ
        template <NumberType TNum, NumberType UNum>
        [[nodiscard]] static constexpr auto ComputeCovarianceUnsafe(DataSummary<TNum> const& left, DataSummary<UNum> const& right) noexcept
        {
            auto lMean = left.ComputeMeanUnsafe();
            auto rMean = right.ComputeMeanUnsafe();

            decltype(lMean + rMean) bunsi{};

            auto pLeft = left.begin();
            auto pRight = right.begin();
            auto eLeft = left.end();

            while (pLeft != eLeft) {
                bunsi += (*pLeft - lMean) * (*pRight - rMean);

                pLeft++;
                pRight++;
            }

            return bunsi / left.Length();
        }

        /// @brief 相関係数を計算
        /// @tparam TNum 数値型
        /// @tparam UNum 数値型
        /// @param left データ
        /// @param right データ
        /// @throws InvalidArgumentException: データ数が一致していないとき
        /// @throws InvalidArgumentException: データ数がゼロのとき
        template <NumberType TNum, NumberType UNum>
        [[nodiscard]] static auto Correlation(DataSummary<TNum> const& left, DataSummary<UNum> const& right)
        {
            _checkLength(left.Length(), right.Length());

            return ComputeCorrelationUnsafe(left, right);
        }

        /// @brief 共分散を計算
        /// @tparam TNum 数値型
        /// @tparam UNum 数値型
        /// @param left データ
        /// @param right データ
        /// @throws InvalidArgumentException: データ数が一致していないとき
        /// @throws InvalidArgumentException: データ数がゼロのとき
        template <NumberType TNum, NumberType UNum>
        [[nodiscard]] static constexpr auto Covariance(DataSummary<TNum> const& left, DataSummary<UNum> const& right)
        {
            _checkLength(left.Length(), right.Length());

            return ComputeCovarianceUnsafe(left, right);
        }

        /// @brief 分散共分散行列を計算
        /// @tparam TNum 数値型
        /// @tparam UNum 数値型
        /// @param left データ
        /// @param right データ
        /// @throws InvalidArgumentException: データ数が一致していないとき
        /// @throws InvalidArgumentException: データ数がゼロのとき
        template <NumberType TNum, NumberType UNum>
        [[nodiscard]] static constexpr auto CovarianceMatrix(DataSummary<TNum> const& left, DataSummary<UNum> const& right)
        {
            _checkLength(left.Length(), right.Length());
            return ComputeCovarianceMatrixUnsafe(left, right);
        }

        private:
        static constexpr void _checkLength(ssize_t lLength, ssize_t rLength)
        {
            if (lLength != rLength) [[unlikely]] throw InvalidArgumentException(u"データ数が一致していません");
            if (lLength == 0) [[unlikely]] throw InvalidArgumentException(u"データがありません");
        }
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_DATASUMMARY_H
