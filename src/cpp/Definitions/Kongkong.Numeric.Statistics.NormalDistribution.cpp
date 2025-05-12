//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    NormalDistribution<TNum>::NormalDistribution(TNum mean, TNum variance) :
        _normalDistributionBase<TNum>(variance),
        _mean(mean)
    {
    }

    template <::std::floating_point TNum>
    TNum NormalDistribution<TNum>::operator()(TNum x) const noexcept
    {
        TNum tmp = x - _mean;
        tmp *= tmp;

        return this->_co1 * ::exp(this->_co2 * tmp);
    }

    template <::std::floating_point TNum>
    String NormalDistribution<TNum>::ToString() const
    {
        ::std::ostringstream sout;

        sout.write("N(", 2);
        sout << _mean;
        sout.write(", ", 2);
        sout << this->_variance;
        sout.put(')');

        return String::FromAscii(sout.str());
    }

    template <::std::floating_point TNum>
    NormalDistribution<TNum>::NormalDistribution(TNum mean, TNum variance, int) noexcept :
        _normalDistributionBase<TNum>(variance, 0),
        _mean(mean)
    {
    }

    template struct NormalDistribution<float>;
    template struct NormalDistribution<double>;
    template struct NormalDistribution<long double>;
}
