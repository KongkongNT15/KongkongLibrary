//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    _normalDistributionBase<TNum>::_normalDistributionBase(TNum variance) : _normalDistributionBase(variance, 0)
    {
        if (variance <= 0.0) [[unlikely]] throw InvalidArgumentException(u"分散にゼロ以下の値が指定されました");
    }

    template <::std::floating_point TNum>
    _normalDistributionBase<TNum>::_normalDistributionBase(TNum variance, int) noexcept :
        _variance(variance),
        _co1((TNum)(1.0 / (Math::Sqrt(Math::Tau() * variance)))),
        _co2((TNum)(-1.0 / (2.0 * variance)))
    {
    }

    template struct _normalDistributionBase<float>;
    template struct _normalDistributionBase<double>;
    template struct _normalDistributionBase<long double>;
}
