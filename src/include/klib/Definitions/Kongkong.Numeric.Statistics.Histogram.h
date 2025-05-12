#ifndef KONGKONG_NUMERIC_STATISTICS_HISTOGRAM_H
#define KONGKONG_NUMERIC_STATISTICS_HISTOGRAM_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Numeric.Statistics.HistogramBase.h"
#include "Kongkong.Numeric.Statistics.HistogramIterator.h"
#include "Kongkong.Collections.CollectionHelper.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <NumberType T>
    struct Histogram : public ValueType, public HistogramBase {

        Histogram(T minValue, T binWidth, ssize_t length) : HistogramBase(length), _binWidth(binWidth), _minValue(minValue)
        {
            if constexpr (::std::is_unsigned_v<T>) {
                if (binWidth == 0) [[unlikely]] throw InvalidArgumentException(u"階級の幅にゼロが指定されました");
            }
            else {
                if (binWidth <= 0) [[unlikely]] throw InvalidArgumentException(u"階級の幅にゼロ以下が指定されました");
            }
        }

        /// @brief 値を追加
        /// @param value 値
        Histogram& operator+=(T value) noexcept
        {
            Append(value);
            return *this;
        }

        Histogram& operator+=(Histogram const& histogram)
        {
            AppendHistogram(histogram);
            return *this;
        }

        [[nodiscard]] constexpr HistogramIterator<T> begin() const noexcept { return HistogramIterator<T>(_minValue, _binWidth, this->_frequencies.begin()); }
        [[nodiscard]] constexpr HistogramIterator<T> end() const noexcept { return HistogramIterator<T>(0, 0, this->_frequencies.end()); }

        /// @brief 値を追加
        /// @param value 値
        /// @return 値を追加できればtrue
        /// @return 値が範囲外の時はfalse
        constexpr bool Append(T value) noexcept
        {
            T converted = value - _minValue;
            ssize_t index = (ssize_t)(converted / _binWidth);

            if (0 <= index && index < this->_frequencies.Length()) {
                ++this->_frequencies[index];
                return true;
            }

            return false;
        }

        constexpr void AppendHistogram(Histogram const& histogram)
        {
            if (histogram._binWidth != _binWidth) [[unlikely]] throw InvalidArgumentException(u"階級の幅が一致していません");
            if (histogram._minValue != _minValue) [[unlikely]] throw InvalidArgumentException(u"最小値が一致していません");
            if (histogram._frequencies.Length() != this->_frequencies.Length()) [[unlikely]] throw InvalidArgumentException(u"階級の数が一致していません");

            AppendHistogramUnsafe(histogram);
        }

        constexpr void AppendHistogramUnsafe(Histogram const& histogram) noexcept
        {
            auto p = this->_frequencies.begin();
            auto e = this->_frequencies.end();
            auto pH = histogram._frequencies.begin();

            while (p != e) {
                *p += *pH;
                ++p;
                ++pH;
            }
        }

        /// @brief 階級の幅
        [[nodiscard]]
        constexpr T BinWidth() const noexcept { return _binWidth; }

        [[nodiscard]]
        constexpr ssize_t GetIndex(T value) const noexcept
        {
            T converted = value - _minValue;
            ssize_t index = (ssize_t)(converted / _binWidth);

            if (0 <= index && index < this->_frequencies.Length()) return index;

            return Collections::CollectionHelper::NotFound();
        }

        [[nodiscard]]
        constexpr T MaxValue() const noexcept { return (T)(_minValue + _binWidth * this->_frequencies.Length()); }

        [[nodiscard]]
        constexpr T MinValue() const noexcept { return _minValue; }

        private:
        T _binWidth;
        T _minValue;
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_HISTOGRAM_H
