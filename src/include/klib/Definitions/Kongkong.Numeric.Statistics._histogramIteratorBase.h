#ifndef KONGKONG_NUMERIC_STATISTICS_HISTOGRAMITERATORBASE_H
#define KONGKONG_NUMERIC_STATISTICS_HISTOGRAMITERATORBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    struct _histogramIteratorBase {

        [[nodiscard]]
        String ToString() const;

        private:

        const uint32_t* _itr;

        constexpr _histogramIteratorBase(const uint32_t* itr) noexcept : _itr(itr) {}
        _histogramIteratorBase(_histogramIteratorBase const&) = default;
        _histogramIteratorBase(_histogramIteratorBase&&) = default;

        _histogramIteratorBase& operator=(_histogramIteratorBase const&) = default;
        _histogramIteratorBase& operator=(_histogramIteratorBase&&) = default;

        template <NumberType T>
        friend struct HistogramIterator;

        friend constexpr bool operator!=(_histogramIteratorBase const&, _histogramIteratorBase const&) noexcept;
    };

    [[nodiscard]]
    constexpr bool operator!=(_histogramIteratorBase const& left, _histogramIteratorBase const& right) noexcept { return left._itr != right._itr; }
}

#endif //!KONGKONG_NUMERIC_STATISTICS_HISTOGRAMITERATORBASE_H
