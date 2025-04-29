//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    RandomCircleBase::RandomCircleBase(double radius) :
        _radius(radius)
    { 
        _checkRadius(radius);
    }

    void RandomCircleBase::Radius(double value)
    {
        _checkRadius(value);
        _radius = value;
    }

    String RandomCircleBase::ToString() const
    {
        return u"KONGKONG_NAMESPACE::Numeric::RandomCircleBase";
    }

    void RandomCircleBase::_checkRadius(double value)
    {
        if (value <= 0.0) [[unlikely]] throw InvalidArgumentException(u"半径にゼロ以下の値が指定されました");
    }
}

namespace KONGKONG_NAMESPACE::Numeric
{
    Vector2Double RandomCircleBase::Next() const
    {
        return _getPtr<ImplType>()->Next();
    }

    double RandomCircleBase::Radius() const
    {
        return _getPtr<ImplType>()->Radius();
    }

    void RandomCircleBase::Radius(double value) const
    {
        _getPtr<ImplType>()->Radius(value);
    }
}
