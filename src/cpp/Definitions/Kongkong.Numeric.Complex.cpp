//このcppファイルをコンパイルに含めないでください

#define TAU ((TFloat)(std::numbers::pi * 2.0))

namespace KONGKONG_NAMESPACE::Numeric
{
    template <std::floating_point TFloat>
    Complex<TFloat>& Complex<TFloat>::operator/=(TFloat value)
    {
        if (value == 0.0) [[unlikely]] throw DivideByZeroException();

        TFloat inv_value = (TFloat)1.0 / value;

        _real *= inv_value;
        _imag *= inv_value;

        return *this;
    }

    template <std::floating_point TFloat>
    TFloat Complex<TFloat>::Argument() const noexcept
    {
        TFloat radius = Length();

        TFloat cosValue = _real / radius;
        TFloat theta = ::acos(cosValue);

        if (_imag < 0.0) theta = TAU - theta;

        return theta;
    }

    template <std::floating_point TFloat>
    Complex<TFloat> Complex<TFloat>::Cos() const noexcept
    {
        constexpr TFloat inv_two = 0.5;
        TFloat sinx = ::sin(_real);
        TFloat cosx = ::cos(_real);

        TFloat e_y = ::exp(_imag);
        TFloat inv_e_y = (TFloat)1.0 / e_y;

        return Complex<TFloat>((e_y + inv_e_y) * cosx * inv_two, (inv_e_y - e_y) * sinx * inv_two);
    }

    template <std::floating_point TFloat>
    Complex<TFloat> Complex<TFloat>::Exp() const noexcept
    {
        const TFloat e_x = ::exp(_real);

        return Complex<TFloat>(e_x * ::cos(_imag), e_x * ::sin(_imag));
    }

    template <std::floating_point TFloat>
    TFloat Complex<TFloat>::Length() const noexcept
    {
        return ::sqrt(SquareLength());
    }

    template <std::floating_point TFloat>
    Complex<TFloat> Complex<TFloat>::Pow(TFloat pow) const noexcept
    {
        return ToPolarComplex().Pow(pow).ToComplex();
    }

    template <std::floating_point TFloat>
    Complex<TFloat> Complex<TFloat>::Pow(Complex<TFloat> const& pow) const noexcept
    {
        return ToPolarComplex().Pow(pow.ToPolarComplex()).ToComplex();
    }

    template <std::floating_point TFloat>
    Complex<TFloat> Complex<TFloat>::Sin() const noexcept
    {
        constexpr TFloat inv_two = 0.5;
        TFloat sinx = ::sin(_real);
        TFloat cosx = ::cos(_real);

        TFloat e_y = ::exp(_imag);
        TFloat inv_e_y = (TFloat)1.0 / e_y;

        return Complex<TFloat>((e_y + inv_e_y) * sinx * inv_two, (e_y - inv_e_y) * cosx * inv_two);
    }

    template <std::floating_point TFloat>
    Complex<TFloat> Complex<TFloat>::Tan() const noexcept
    {
        constexpr TFloat one = 1.0;
        constexpr TFloat two = 2.0;
        constexpr TFloat four = 4.0;
        const TFloat sin2x = ::sin(two * _real);
        const TFloat cos2x = ::cos(two * _real);

        const TFloat e_2y = ::exp(two * _imag);
        const TFloat e_4y = e_2y * e_2y;
        const TFloat e_4y_1 = e_4y + one;

        const TFloat inv_bunnbo = one / (e_4y_1 + two * e_2y * cos2x);
        const TFloat bunnsiReal = e_4y_1 * sin2x;
        const TFloat bunnsiImag = (e_4y - one) * cos2x;

        return Complex<TFloat>(bunnsiReal * inv_bunnbo, bunnsiImag * inv_bunnbo);
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> Complex<TFloat>::ToPolarComplex() const noexcept
    {
        TFloat radius = Length();

        if (radius == 0.0) return PolarComplex<TFloat>();

        TFloat cosValue = _real / radius;
        TFloat theta = ::acos(cosValue);

        if (_imag < 0.0) theta = (TFloat)std::numbers::pi * (TFloat)2.0 - theta;

        return PolarComplex<TFloat>(radius, theta, 0);
    }

    template <std::floating_point TFloat>
    String Complex<TFloat>::ToString() const
    {
        std::stringstream sout;
        sout << "[ " << _real << ", " << _imag << ']';

        return String::FromAscii(sout.str());
    }

    template <std::floating_point TFloat>
    Complex<TFloat> operator/(Complex<TFloat> const& left, Complex<TFloat> const& right)
    {
        TFloat bunnbo = right._real * right._real + right._imag * right._imag;

        if (bunnbo == 0.0) [[unlikely]] throw DivideByZeroException();

        TFloat inv_bunnbo = (TFloat)1.0 / bunnbo;

        TFloat bunnshiReal = left._real * right._real + left._imag * right._imag;
        TFloat bunnshiImag = left._imag * right._real - left._real * right._imag;

        return Complex<TFloat>(bunnshiReal * inv_bunnbo, bunnshiImag * inv_bunnbo);
    }

    template <std::floating_point TFloat>
    Complex<TFloat> operator/(Complex<TFloat> const& left, TFloat right)
    {
        if (right == 0.0) [[unlikely]] throw DivideByZeroException();

        TFloat inv_right = (TFloat)1.0 / right;

        return Complex<TFloat>(left._real * inv_right, left._imag * inv_right);
    }

    template <std::floating_point TFloat>
    Complex<TFloat> operator/(TFloat left, Complex<TFloat> const& right)
    {
        TFloat bunnbo = right._real * right._real + right._imag * right._imag;

        if (bunnbo == 0.0) [[unlikely]] throw DivideByZeroException();

        TFloat bunnshiReal = left * right._real;
        TFloat bunnshiImag = -left * right._imag;

        return Complex<TFloat>(bunnshiReal / bunnbo, bunnshiImag / bunnbo);
    }

    template struct Complex<float>;
    template struct Complex<double>;
    template struct Complex<long double>;

    template Complex<float> operator/(Complex<float> const&, Complex<float> const&);
    template Complex<double> operator/(Complex<double> const&, Complex<double> const&);
    template Complex<long double> operator/(Complex<long double> const&, Complex<long double> const&);

    template Complex<float> operator/(Complex<float> const&, float);
    template Complex<double> operator/(Complex<double> const&, double);
    template Complex<long double> operator/(Complex<long double> const&, long double);

    template Complex<float> operator/(float, Complex<float> const&);
    template Complex<double> operator/(double, Complex<double> const&);
    template Complex<long double> operator/(long double, Complex<long double> const&);
}

#undef TAU
