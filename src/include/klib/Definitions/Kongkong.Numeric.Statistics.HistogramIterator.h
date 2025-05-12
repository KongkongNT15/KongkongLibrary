#ifndef KONGKONG_NUMERIC_STATISTICS_HISTOGRAMITERATOR_H
#define KONGKONG_NUMERIC_STATISTICS_HISTOGRAMITERATOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Numeric.Statistics._histogramIteratorBase.h"
#include "Kongkong.Numeric.Statistics.Bin.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <NumberType T>
    struct HistogramIterator : public ValueType, public _histogramIteratorBase {

        constexpr HistogramIterator(T minValue, T binWidth, const uint32_t* itr) noexcept : _histogramIteratorBase(itr), _currentValue(minValue), _binWidth(binWidth) {}

        HistogramIterator& operator++() noexcept
        {
            _currentValue += _binWidth;
            ++this->_itr;
            
            return *this;
        }

        HistogramIterator operator++(int) noexcept
        {
            auto result = *this;
            operator++();

            return result;
        }

        [[nodiscard]]
        constexpr Bin<T> operator*() const noexcept
        {
            return Bin<T>(_currentValue, _currentValue + _binWidth, *this->_itr);
        }

        private:
        T _currentValue;
        T _binWidth;
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_HISTOGRAMITERATOR_H
