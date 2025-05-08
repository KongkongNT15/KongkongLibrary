//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    RandomCircle::RandomCircle(double radius) :
        RandomCircleBase(radius),
        _urd(0.0, 1.0),
        _mt()
    {
    }

    RandomCircle::RandomCircle(double radius, unsigned seed) :
        RandomCircleBase(radius),
        _urd(0.0, 1.0),
        _mt(seed)
    {
    }

    Vector2Double RandomCircle::Next() noexcept
    {
        double theta = _urd(_mt) * (::std::numbers::pi * 2.0);
        double r = ::sqrt(_urd(_mt)) * Radius();

        return Vector2Double(r * ::cos(theta), r * ::sin(theta));
    }

    void RandomCircle::Seed() noexcept
    {
        _mt.seed();
    }

    void RandomCircle::Seed(unsigned seed) noexcept
    {
        _mt.seed(seed);
    }

    String RandomCircle::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Numeric::RandomCircle");
    }

} // namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION


namespace KONGKONG_NAMESPACE::Numeric
{
    RandomCircle::RandomCircle(double radius) : RandomCircleBase(nullptr)
    {
        _setInstance(NEW ImplType(radius));
    }

    RandomCircle::RandomCircle(double radius, unsigned seed) : RandomCircleBase(nullptr)
    {
        _setInstance(NEW ImplType(radius, seed));
    }
}
