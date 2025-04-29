//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::Statistics
{
    template <::std::floating_point TNum>
    UniformDistribution<TNum>::UniformDistribution(TNum min, TNum max) : UniformDistribution(min, max, 0)
    {
        if (max <= min) [[unlikely]] throw InvalidArgumentException(u"'max'が'min'以下です");
    }

    template <::std::floating_point TNum>
    String UniformDistribution<TNum>::ToString() const
    {
        ::std::ostringstream sout;

        sout.write("U(", 2);
        sout << _min;
        sout.write(", ", 2);
        sout << _max;
        sout.put(')');

        return String::FromAscii(sout.str());
    }

    template struct UniformDistribution<float>;
    template struct UniformDistribution<double>;
    template struct UniformDistribution<long double>;
}
