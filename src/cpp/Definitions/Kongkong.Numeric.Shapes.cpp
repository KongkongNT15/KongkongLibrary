//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::Shapes::IMPLEMENTATION
{
    template <ssize_t N> requires (N == 2 || N == 3)
    Shape<N>::Shape() noexcept : _center()
    {
    }

    template <ssize_t N> requires (N == 2 || N == 3)
    Shape<N>::Shape(VectorType const& center) noexcept : _center(center)
    {
    }

    template <ssize_t N> requires (N == 2 || N == 3)
    Shape<N>::Shape(NumberType x, NumberType y) noexcept requires (N == 2): _center(x, y)
    {
    }

    template <ssize_t N> requires (N == 2 || N == 3)
    Shape<N>::Shape(NumberType x, NumberType y, NumberType z) noexcept requires (N == 3): _center(x, y, z)
    {
    }

    template <ssize_t N> requires (N == 2 || N == 3)
    void Shape<N>::Center(VectorType const& value) noexcept
    {
        _center = value;
    }

    template <ssize_t N> requires (N == 2 || N == 3)
    void Shape<N>::_checkMinus(NumberType num)
    {
        if (num < 0.0) [[unlikely]] throw InvalidArgumentException(u"負の値が設定されました");
    }

    Circle::Circle() noexcept :
        Shape2D(),
        _radius()
    {
    }

    Circle::Circle(NumberType radius) :
        Shape2D(),
        _radius(radius)
    {
        _checkMinus(radius);
    }

    Circle::Circle(VectorType const& point) noexcept :
        Shape2D(point),
        _radius()
    {
    }

    Circle::Circle(NumberType x, NumberType y) noexcept :
        Shape2D(x, y),
        _radius()
    {
    }

    Circle::Circle(VectorType const& point, NumberType radius) :
        Shape2D(point),
        _radius(radius)
    {
        _checkMinus(radius);
    }

    Circle::Circle(NumberType x, NumberType y, NumberType radius) :
        Shape2D(x, y),
        _radius(radius)
    {
        _checkMinus(radius);
    }

    Circle::NumberType Circle::Area() const noexcept
    {
        return _radius * _radius * Math::PI();
    }

    bool Circle::Contains(VectorType const& point) const noexcept
    {
        //距離
        auto&& vec = point - _center;

        return vec.SquareMagnitude() <= _radius * _radius;
    }

    void Circle::Radius(NumberType value)
    {
        _checkMinus(value);

        _radius = value;
    }

    Line2D::Line2D() noexcept : Shape2D(), _start(), _end()
    {
    }

    Line2D::Line2D(VectorType const& start, VectorType const& end) noexcept :
        Shape2D(),
        _start(start),
        _end(end)
    {
        _setCenter();
    }

    Line2D::NumberType Line2D::Area() const noexcept
    {
        return 0;
    }

    bool Line2D::Contains(VectorType const& point) const noexcept
    {
        if (point == _start) return true;
        if (point == _end) return true;

        auto&& vec1 = Vector();
        auto&& vec2 = point - _start;

        //ここでvec2のX(), Y()はともにゼロでない

        NumberType num1 = vec1.X() / vec2.X();
        NumberType num2 = vec1.Y() / vec2.Y();

        //ほとんどの場合falseになる
        return num1 == num2;
    }

    void Line2D::Center(VectorType const& value) noexcept
    {
        _center = value;

        _end = 2.0 * value - _start;
    }

    void Line2D::End(VectorType const& value) noexcept
    {
        _end = value;
        _setCenter();
    }

    Line2D::NumberType Line2D::Length() const noexcept
    {
        return Vector().Magnitude();
    }

    void Line2D::Start(VectorType const& value) noexcept
    {
        _start = value;
        _setCenter();
    }

    void Line2D::_setCenter() noexcept
    {
        _center = 0.5 * (_start + _end);
    }

    Point2D::NumberType Point2D::Area() const noexcept
    {
        return 0;
    }

    bool Point2D::Contains(VectorType const& point) const noexcept
    {
        return _center == point;
    }

}

namespace KONGKONG_NAMESPACE::Numeric::Shapes
{
    template <ssize_t N> requires (N == 2 || N == 3)
    Shape<N>::VectorType& Shape<N>::Center() const
    {
        return Object::_getPtr<ImplType>()->Center();
    }

    template <ssize_t N> requires (N == 2 || N == 3)
    void Shape<N>::Center(VectorType const& value) const
    {
        Object::_getPtr<ImplType>()->Center(value);
    }

    template <ssize_t N> requires (N == 2 || N == 3)
    bool Shape<N>::Contains(VectorType const& point) const
    {
        return Object::_getPtr<ImplType>()->Contains(point);
    }

    Shape2D::NumberType Shape2D::Area() const
    {
        return _getPtr<ImplType>()->Area();
    }

    Circle::Circle() : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType());
    }

    Circle::Circle(NumberType radius) : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType(radius));
    }

    Circle::Circle(VectorType const& point) : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType(point));
    }

    Circle::Circle(NumberType x, NumberType y) : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType(x, y));
    }

    Circle::Circle(VectorType const& point, NumberType radius) : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType(point, radius));
    }

    Circle::Circle(NumberType x, NumberType y, NumberType radius) : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType(x, y, radius));
    }

    Line2D::Line2D() : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType());
    }

    Line2D::Line2D(VectorType const& start, VectorType const& end) : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType(start, end));
    }

    Line2D::VectorType Line2D::End() const
    {
        return _getPtr<ImplType>()->End();
    }

    void Line2D::End(VectorType const& value) const
    {
        _getPtr<ImplType>()->End(value);
    }

    Line2D::NumberType Line2D::Length() const
    {
        return _getPtr<ImplType>()->Length();
    }

    Line2D::VectorType Line2D::Start() const
    {
        return _getPtr<ImplType>()->Start();
    }

    void Line2D::Start(VectorType const& value) const
    {
        _getPtr<ImplType>()->Start(value);
    }

    Point2D::Point2D() : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType());
    }

    Point2D::Point2D(VectorType const& center) : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType(center));
    }

    Point2D::Point2D(NumberType x, NumberType y) : Shape2D(nullptr)
    {
        _setInstance(NEW ImplType(x, y));
    }

}
