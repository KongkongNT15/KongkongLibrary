#ifndef KONGKONG_NUMERIC_STATISTICS_HISTOGRAMBASE_H
#define KONGKONG_NUMERIC_STATISTICS_HISTOGRAMBASE_H

#include "Base.h"
#include "Kongkong.Collections.Turbo.FastArray.h"

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    struct HistogramBase {
        public:

        [[nodiscard]] constexpr uint32_t operator[](ssize_t index) const noexcept { return _frequencies[index]; }

        void Clear() noexcept;

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _frequencies.Length(); }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        [[nodiscard]]
        uint32_t TotalFrequency() const noexcept;

        private:
        Collections::Turbo::FastArray<uint32_t> _frequencies;

        HistogramBase(ssize_t length);
        HistogramBase(HistogramBase const&) = default;
        HistogramBase(HistogramBase&&) = default;

        HistogramBase& operator=(HistogramBase const&) = default;
        HistogramBase& operator=(HistogramBase&&) = default;

        template <NumberType T>
        friend struct Histogram;
    };
}

#endif //!KONGKONG_NUMERIC_STATISTICS_HISTOGRAMBASE_H
