//このcppファイルをコンパイルに含めないでください

#define CO1(type) (::std::numbers::inv_sqrtpi_v<type> / ::std::numbers::sqrt2_v<type>)
#define CO2(type) ((type)-0.5)
#define GET_DENSITY(type, x) CO1(type) * ::exp(CO2(type) * x * x)

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
#if KONGKONG_HAS_CPP23

    template <::std::floating_point TNum>
    TNum StandardNormalDistribution<TNum>::operator()(TNum x) noexcept
    {
        return GET_DENSITY(TNum, x);
    }

#endif //KONGKONG_HAS_CPP23

    template <::std::floating_point TNum>
    TNum StandardNormalDistribution<TNum>::GetDensity(TNum x) noexcept
    {
        return GET_DENSITY(TNum, x);
    }
    
    template class StandardNormalDistribution<float>;
    template class StandardNormalDistribution<double>;
    template class StandardNormalDistribution<long double>;
}

#undef CO1
#undef CO2
#undef GET_DENSITY
