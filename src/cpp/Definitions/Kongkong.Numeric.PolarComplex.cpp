//このcppファイルをコンパイルに含めないでください

#define FMOD(value) (::fmod(value, std::numbers::pi_v<TFloat>))
#define TAU ((TFloat)(std::numbers::pi * 2.0))

namespace KONGKONG_NAMESPACE::Numeric
{
    template <std::floating_point TFloat>
    PolarComplex<TFloat>::PolarComplex(TFloat radius, TFloat theta) : _radius(radius), _theta(FMOD(theta))
    {
        _checkRadius(radius);
    }

    template <std::floating_point TFloat>
    void PolarComplex<TFloat>::Argument(TFloat value) noexcept
    {
        _theta = FMOD(value);
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> PolarComplex<TFloat>::Cos() const noexcept
    {
        return ToComplex().Cos().ToPolarComplex();
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> PolarComplex<TFloat>::Exp() const noexcept
    {
        TFloat theta = FMOD(_radius * ::sin(_theta));

        if (theta < 0.0) theta += TAU;

        return PolarComplex<TFloat>(::exp(_radius * ::cos(_theta)), theta, 0);
    }

    template <std::floating_point TFloat>
    TFloat PolarComplex<TFloat>::Imag() const noexcept
    {
        return _radius * ::sin(_theta);
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> PolarComplex<TFloat>::Pow(TFloat pow) const noexcept
    {
        TFloat radius = ::pow(_radius, pow);
        TFloat theta = FMOD(_theta * pow);

        if (theta < 0.0) theta += TAU;

        return PolarComplex<TFloat>(radius, theta);
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> PolarComplex<TFloat>::Pow(PolarComplex<TFloat> const& pow) const noexcept
    {
        if (_radius < std::numeric_limits<TFloat>::epsilon()) return PolarComplex<TFloat>();
        if (pow._theta < std::numeric_limits<TFloat>::epsilon()) return Pow(pow._radius);
        if (_theta < std::numeric_limits<TFloat>::epsilon()) return Math::Pow(_radius, pow);

        const TFloat cosTheta2 = ::cos(pow._theta);
        const TFloat sinTheta2 = ::sin(pow._theta);

        const TFloat arg = pow._radius * (::log(_radius) * sinTheta2 + _theta * cosTheta2);

        TFloat theta = FMOD(arg);

        if (theta < 0.0) theta += TAU;

        const TFloat r1 = ::pow(_radius, pow._radius * cosTheta2);
        const TFloat r2 = ::exp(-pow._radius * _theta * sinTheta2);

        return PolarComplex<TFloat>(r1 * r2, theta);
    }

    template <std::floating_point TFloat>
    void PolarComplex<TFloat>::Radius(TFloat value)
    {
        _checkRadius(value);

        _radius = value;
    }

    template <std::floating_point TFloat>
    TFloat PolarComplex<TFloat>::Real() const noexcept
    {
        return _radius * ::cos(_theta);
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> PolarComplex<TFloat>::Sin() const noexcept
    {
        return ToComplex().Sin().ToPolarComplex();
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> PolarComplex<TFloat>::Tan() const noexcept
    {
        return ToComplex().Tan().ToPolarComplex();
    }

    template <std::floating_point TFloat>
    Complex<TFloat> PolarComplex<TFloat>::ToComplex() const noexcept
    {
        TFloat x = _radius * ::cos(_theta);
        TFloat y = _radius * ::sin(_theta);

        return Complex<TFloat>(x, y);
    }

    template <std::floating_point TFloat>
    String PolarComplex<TFloat>::ToString() const
    {
        std::stringstream sout;
        sout << "[ " << _radius << ", " << _theta << ']';

        return String::FromAscii(sout.str());
    }

    template <std::floating_point TFloat>
    void PolarComplex<TFloat>::_checkRadius(TFloat value)
    {
        if (value < 0.0) [[unlikely]] throw InvalidArgumentException(u"半径に負の値が指定されました");
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> operator*(PolarComplex<TFloat> const& left, PolarComplex<TFloat> const& right) noexcept
    {
        TFloat radius = left._radius * right._radius;
        TFloat theta = FMOD(left._theta + right._theta);

        return PolarComplex<TFloat>(radius, theta, 0);
    }

    template <std::floating_point TFloat>
    PolarComplex<TFloat> operator/(PolarComplex<TFloat> const& left, PolarComplex<TFloat> const& right)
    {
        if (right._radius == 0.0) [[unlikely]] throw DivideByZeroException();

        TFloat radius = left._radius / right._radius;
        TFloat theta = left._theta - right._theta;

        if (theta < 0.0) theta += TAU;

        return PolarComplex<TFloat>(radius, theta, 0);
    }

    template struct PolarComplex<float>;
    template struct PolarComplex<double>;
    template struct PolarComplex<long double>;
}

#undef FMOD
#undef TAU
