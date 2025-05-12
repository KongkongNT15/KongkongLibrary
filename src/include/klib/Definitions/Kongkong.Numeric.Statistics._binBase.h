#ifndef KONGKONG_NUMERIC_STATISTICS_BINBASE_H
#define KONGKONG_NUMERIC_STATISTICS_BINBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    struct _binBase {

        /// @brief 度数
        [[nodiscard]]
        constexpr uint32_t Frequency() const noexcept { return _frequency; }

        [[nodiscard]]
        String ToString() const;

        private:

        uint32_t _frequency;

        constexpr _binBase(uint32_t frequency) noexcept : _frequency(frequency) {}
        _binBase(_binBase const&) = default;
        _binBase(_binBase&&) = default;

        _binBase& operator=(_binBase const&) = default;
        _binBase& operator=(_binBase&&) = default;

        template <NumberType T>
        friend struct Bin;
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_BINBASE_H
