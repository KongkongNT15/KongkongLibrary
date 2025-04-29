//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    PoissonDistribution<TNum>::PoissonDistribution(TNum lambda) : PoissonDistribution(lambda, true)
    {
        if (lambda < 0.0) [[unlikely]] throw InvalidArgumentException(u"平均値に負の値が指定されました");
    }

    template <::std::floating_point TNum>
    TNum PoissonDistribution<TNum>::operator()(uint64_t n) const noexcept
    {
        switch (n) {
            case 0: return m_co;
            case 1: return m_co * m_lambda;

            default:
            {
                TNum result = m_co * m_lambda;
                uint64_t e = n + 1;

                for (uint64_t i = 2; i != e; i++) {
                    result *= m_lambda;
                    result /= i;
                }

                return result;
            }

        }
#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif  
    }

    template <::std::floating_point TNum>
    String PoissonDistribution<TNum>::ToString() const
    {
        ::std::ostringstream sout;

        sout.write("p(", 2);
        sout << m_lambda;
        sout.put(')');

        return String::FromAscii(sout.str());
    }

    template <::std::floating_point TNum>
    PoissonDistribution<TNum>::PoissonDistribution(TNum lambda, bool) noexcept : m_lambda(lambda), m_co(::exp(-lambda))
    {
    }

    template struct PoissonDistribution<float>;
    template struct PoissonDistribution<double>;
    template struct PoissonDistribution<long double>;
}
