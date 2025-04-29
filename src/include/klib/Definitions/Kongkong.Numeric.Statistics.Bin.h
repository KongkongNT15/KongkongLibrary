#ifndef KONGKONG_NUMERIC_STATISTICS_BIN_H
#define KONGKONG_NUMERIC_STATISTICS_BIN_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Numeric.Statistics.Bin.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <NumberType T>
    struct Bin : public ValueType, public _binBase {

        constexpr Bin(T minValue, T maxValue, uint32_t frequency) noexcept : _binBase(frequency), _minValue(minValue), _maxValue(maxValue) {}

        [[nodiscard]]
        constexpr T Center() const noexcept { return (_maxValue + _minValue) / (T)2; }

        [[nodiscard]]
        constexpr T MaxValue() const noexcept { return _maxValue; }

        [[nodiscard]]
        constexpr T MinValue() const noexcept { return _minValue; }

        private:
        T _minValue;
        T _maxValue;
        
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_BIN_H
