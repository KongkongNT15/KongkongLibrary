//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric
{
    Complex<float> Math::Cos(Complex<float> const& z) noexcept
    {
        return z.Cos();
    }

    Complex<double> Math::Cos(Complex<double> const& z) noexcept
    {
        return z.Cos();
    }

    Complex<long double> Math::Cos(Complex<long double> const& z) noexcept
    {
        return z.Cos();
    }

    PolarComplex<float> Math::Cos(PolarComplex<float> const& z) noexcept
    {
        return z.Cos();
    }

    PolarComplex<double> Math::Cos(PolarComplex<double> const& z) noexcept
    {
        return z.Cos();
    }

    PolarComplex<long double> Math::Cos(PolarComplex<long double> const& z) noexcept
    {
        return z.Cos();
    }

    Complex<float> Math::Exp(Complex<float> const& z) noexcept
    {
        return z.Exp();
    }

    Complex<double> Math::Exp(Complex<double> const& z) noexcept
    {
        return z.Exp();
    }

    Complex<long double> Math::Exp(Complex<long double> const& z) noexcept
    {
        return z.Exp();
    }

    PolarComplex<float> Math::Exp(PolarComplex<float> const& z) noexcept
    {
        return z.Exp();
    }

    PolarComplex<double> Math::Exp(PolarComplex<double> const& z) noexcept
    {
        return z.Exp();
    }

    PolarComplex<long double> Math::Exp(PolarComplex<long double> const& z) noexcept
    {
        return z.Exp();
    }

    Complex<float> Math::Pow(Complex<float> const& z1, Complex<float> const& z2)
    {
        return z1.Pow(z2);
    }

    Complex<double> Math::Pow(Complex<double> const& z1, Complex<double> const& z2)
    {
        return z1.Pow(z2);
    }

    Complex<long double> Math::Pow(Complex<long double> const& z1, Complex<long double> const& z2)
    {
        return z1.Pow(z2);
    }

    PolarComplex<float> Math::Pow(PolarComplex<float> const& z1, PolarComplex<float> const& z2)
    {
        return z1.Pow(z2);
    }

    PolarComplex<double> Math::Pow(PolarComplex<double> const& z1, PolarComplex<double> const& z2)
    {
        return z1.Pow(z2);
    }

    PolarComplex<long double> Math::Pow(PolarComplex<long double> const& z1, PolarComplex<long double> const& z2)
    {
        return z1.Pow(z2);
    }

    Complex<float> Math::Pow(Complex<float> const& z1, float z2)
    {
        return z1.Pow(z2);
    }

    Complex<double> Math::Pow(Complex<double> const& z1, double z2)
    {
        return z1.Pow(z2);
    }

    Complex<long double> Math::Pow(Complex<long double> const& z1, long double z2)
    {
        return z1.Pow(z2);
    }

    PolarComplex<float> Math::Pow(PolarComplex<float> const& z1, float z2)
    {
        return z1.Pow(z2);
    }

    PolarComplex<double> Math::Pow(PolarComplex<double> const& z1, double z2)
    {
        return z1.Pow(z2);
    }

    PolarComplex<long double> Math::Pow(PolarComplex<long double> const& z1, long double z2)
    {
        return z1.Pow(z2);
    }

    Complex<float> Math::Pow(float z1, Complex<float> const& z2)
    {
        return _pow(z1, z2.ToPolarComplex()).ToComplex();
    }

    Complex<double> Math::Pow(double z1, Complex<double> const& z2)
    {
        return _pow(z1, z2.ToPolarComplex()).ToComplex();
    }

    Complex<long double> Math::Pow(long double z1, Complex<long double> const& z2)
    {
        return _pow(z1, z2.ToPolarComplex()).ToComplex();
    }

    PolarComplex<float> Math::Pow(float z1, PolarComplex<float> const& z2)
    {
        return _pow(z1, z2);
    }

    PolarComplex<double> Math::Pow(double z1, PolarComplex<double> const& z2)
    {
        return _pow(z1, z2);
    }

    PolarComplex<long double> Math::Pow(long double z1, PolarComplex<long double> const& z2)
    {
        return _pow(z1, z2);
    }

    Complex<float> Math::Sin(Complex<float> const& z) noexcept
    {
        return z.Sin();
    }

    Complex<double> Math::Sin(Complex<double> const& z) noexcept
    {
        return z.Sin();
    }

    Complex<long double> Math::Sin(Complex<long double> const& z) noexcept
    {
        return z.Sin();
    }

    PolarComplex<float> Math::Sin(PolarComplex<float> const& z) noexcept
    {
        return z.Sin();
    }

    PolarComplex<double> Math::Sin(PolarComplex<double> const& z) noexcept
    {
        return z.Sin();
    }

    PolarComplex<long double> Math::Sin(PolarComplex<long double> const& z) noexcept
    {
        return z.Sin();
    }

    Complex<float> Math::Tan(Complex<float> const& z) noexcept
    {
        return z.Tan();
    }

    Complex<double> Math::Tan(Complex<double> const& z) noexcept
    {
        return z.Tan();
    }

    Complex<long double> Math::Tan(Complex<long double> const& z) noexcept
    {
        return z.Tan();
    }

    PolarComplex<float> Math::Tan(PolarComplex<float> const& z) noexcept
    {
        return z.Tan();
    }

    PolarComplex<double> Math::Tan(PolarComplex<double> const& z) noexcept
    {
        return z.Tan();
    }

    PolarComplex<long double> Math::Tan(PolarComplex<long double> const& z) noexcept
    {
        return z.Tan();
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> Math::_pow(TFloat z1, PolarComplex<TFloat> const& z2) noexcept
    {
        TFloat radius = ::pow(z1, z2.Radius() * ::cos(z2.Argument()));
        TFloat theta = ::fmod(z2.Radius() * ::log(z1) * ::sin(z2.Argument()), (TFloat)std::numbers::pi);

        if (theta < 0.0) theta += (TFloat)(std::numbers::pi * 2.0);

        return PolarComplex<TFloat>::CreateUnsafe(radius, theta);
    }
}
