//このcppファイルをコンパイルに含めないでください

#define GET_DENSITY(value) this->_co1 * ::exp(this->_co2 * value * value)

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    ZeroMeanNormalDistribution<TNum>::ZeroMeanNormalDistribution(TNum variance) :
        _normalDistributionBase<TNum>(variance)
    {
    }

    template <::std::floating_point TNum>
    TNum ZeroMeanNormalDistribution<TNum>::operator()(TNum x) const noexcept
    {
        return GET_DENSITY(x);
    }

    template <::std::floating_point TNum>
    TNum ZeroMeanNormalDistribution<TNum>::GetDensity(TNum x) const noexcept
    {
        return GET_DENSITY(x);
    }

    template <::std::floating_point TNum>
    String ZeroMeanNormalDistribution<TNum>::ToString() const
    {
        ::std::ostringstream sout;

        sout.write("N(0, ", 5);
        sout << this->_variance;
        sout.put(')');

        return String::FromAscii(sout.str());
    }

    template <::std::floating_point TNum>
    ZeroMeanNormalDistribution<TNum>::ZeroMeanNormalDistribution(TNum variance, int) noexcept :
        _normalDistributionBase<TNum>(variance, 0)
    {
    }

    template struct ZeroMeanNormalDistribution<float>;
    template struct ZeroMeanNormalDistribution<double>;
    template struct ZeroMeanNormalDistribution<long double>;
}

#undef GET_DENSITY
