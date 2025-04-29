//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    HistogramBase::HistogramBase(ssize_t length) : _frequencies(length)
    {
    }

    void HistogramBase::Clear() noexcept
    {
        for (uint32_t& v : _frequencies) v = 0;
    }

    String HistogramBase::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Numeric::Statistics::Histogram<T>");
    }

    uint32_t HistogramBase::TotalFrequency() const noexcept
    {
        uint32_t total{};

        for (uint32_t v : _frequencies) {
            total += v;
        }

        return total;
    }
}
