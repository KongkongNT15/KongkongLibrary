#ifndef KONGKONG_NUMERIC_SHAPES_H
#define KONGKONG_NUMERIC_SHAPES_H

#include "Kongkong.Numeric.h"

namespace KONGKONG_NAMESPACE::Numeric::Shapes::IMPLEMENTATION
{
    template <ssize_t N> requires (N == 2 || N == 3)
    struct Shape : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using NumberType = double;
        using VectorType = Vector<NumberType, N>;

        Shape() noexcept;
        Shape(VectorType const& center) noexcept;
        Shape(NumberType x, NumberType y) noexcept requires (N == 2);
        Shape(NumberType x, NumberType y, NumberType z) noexcept requires (N == 3);

        /// @brief 重心を取得
        constexpr VectorType& Center() noexcept { return _center; }

        /// @brief 重心を取得
        constexpr VectorType& Center() const noexcept { return _center; }

        /// @brief 重心を設定
        virtual void Center(VectorType const& value) noexcept;

        /// @brief 座標が図形の内部か境界線上であるかを判定
        /// @param point 座標
        virtual bool Contains(VectorType const& point) const noexcept = 0;

        protected:

        /// @brief 重心
        VectorType _center;

        /// @brief numが負の値ならエラー
        /// @param num 確認する値
        static void _checkMinus(NumberType num);

    };

    /// @brief 2次元図形オブジェクト
    struct Shape2D : public Shape<2> {
        //ふはははは
        using Shape<2>::Shape;

        /// @brief 面積を取得
        virtual NumberType Area() const noexcept = 0;
    };

    /// @brief 円
    struct Circle final : public Shape2D {

        Circle() noexcept;
        explicit Circle(NumberType radius);
        explicit Circle(VectorType const& point) noexcept;
        explicit Circle(NumberType x, NumberType y) noexcept;
        explicit Circle(VectorType const& point, NumberType radius);
        explicit Circle(NumberType x, NumberType y, NumberType radius);

        NumberType Area() const noexcept override;

        bool Contains(VectorType const& point) const noexcept override;

        constexpr NumberType Radius() const noexcept { return _radius; }
        void Radius(NumberType value);

        private:
        NumberType _radius;
    };

    struct Line2D final : public Shape2D {

        Line2D() noexcept;
        explicit Line2D(VectorType const& start, VectorType const& end) noexcept;

        NumberType Area() const noexcept override;

        /// @brief 変更すると_endの位置が変わる
        void Center(VectorType const& value) noexcept override;

        bool Contains(VectorType const& point) const noexcept override;

        constexpr VectorType End() const noexcept { return _end; }
        void End(VectorType const& value) noexcept;

        NumberType Length() const noexcept;

        constexpr VectorType Start() const noexcept { return _start; }
        void Start(VectorType const& value) noexcept;

        constexpr VectorType Vector() const noexcept { return _end - _start; }

        private:
        VectorType _start;
        VectorType _end;

        /// @brief _start, _endの変更時に使用
        void _setCenter() noexcept;
    };

    /// @brief 点
    struct Point2D final : public Shape2D {
        //ふはははは
        using Shape2D::Shape2D;

        NumberType Area() const noexcept override;

        bool Contains(VectorType const& point) const noexcept override;

    };
}

namespace KONGKONG_NAMESPACE::Numeric::Shapes
{
    template <ssize_t N> requires (N == 2 || N == 3)
    class Shape : public Object {
        public:
        using ImplType = IMPLEMENTATION::Shape<N>;

        using NumberType = ImplType::NumberType;
        using VectorType = ImplType::VectorType;

        Shape() = delete;
        constexpr Shape(std::nullptr_t) noexcept : Object(nullptr) {}

        /// @brief 重心を取得
        [[nodiscard]]
        VectorType& Center() const;

        /// @brief 重心を設定
        void Center(VectorType const& value) const;

        /// @brief 座標が図形の内部か境界線上であるかを判定
        /// @param point 座標
        [[nodiscard]]
        bool Contains(VectorType const& point) const;
    };

    /// @brief 2次元図形オブジェクト
    class Shape2D : public Shape<2> {
        public:
        using ImplType = IMPLEMENTATION::Shape2D;

        Shape2D() = delete;
        constexpr Shape2D(std::nullptr_t) noexcept : Shape<2>(nullptr) {}

        /// @brief 面積を取得
        [[nodiscard]]
        NumberType Area() const;
    };

    class Circle final : public Shape2D {
        public:
        using ImplType = IMPLEMENTATION::Circle;

        Circle();
        explicit Circle(NumberType radius);
        explicit Circle(VectorType const& point);
        explicit Circle(NumberType x, NumberType y);
        explicit Circle(VectorType const& point, NumberType radius);
        explicit Circle(NumberType x, NumberType y, NumberType radius);
        constexpr Circle(std::nullptr_t) noexcept : Shape2D(nullptr) {}
    };

    class Line2D final : public Shape2D {
        public:
        using ImplType = IMPLEMENTATION::Line2D;

        Line2D();
        explicit Line2D(VectorType const& start, VectorType const& end);
        constexpr Line2D(std::nullptr_t) noexcept : Shape2D(nullptr) {}

        /// @brief 終点
        [[nodiscard]]
        VectorType End() const;

        /// @brief 終点を設定
        void End(VectorType const& value) const;

        /// @brief 線分の長さを取得
        [[nodiscard]]
        NumberType Length() const;

        /// @brief 始点を取得
        [[nodiscard]]
        VectorType Start() const;

        /// @brief 始点を設定
        void Start(VectorType const& value) const;

        /// @brief 線分を表すベクトルを取得
        [[nodiscard]]
        VectorType Vector() const;
    };

    class Point2D final : public Shape2D {
        public:
        using ImplType = IMPLEMENTATION::Point2D;

        Point2D();
        Point2D(VectorType const& center);
        Point2D(NumberType x, NumberType y);
        constexpr Point2D(std::nullptr_t) noexcept : Shape2D(nullptr) {}


    };
}

#endif //!KONGKONG_NUMERIC_SHAPES_H
