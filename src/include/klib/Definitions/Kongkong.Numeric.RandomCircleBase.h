#ifndef KONGKONG_NUMERIC_RANDOMCIRCLEBASE_H
#define KONGKONG_NUMERIC_RANDOMCIRCLEBASE_H

#include "Base.h"
#include "Kongkong.Object.h"

namespace KONGKONG_NAMESPACE::Numeric::IMPLEMENTATION
{
    //円形の範囲内のランダムな点を作成
    struct RandomCircleBase : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {

        explicit RandomCircleBase(double radius);

        //ランダムな点を取得
        virtual Vector2Double Next() = 0;

        //半径
        constexpr double Radius() const noexcept { return _radius; }
        void Radius(double value);

        String ToString() const override;

        private:

        static void _checkRadius(double value);

        double _radius;

    };
}

namespace KONGKONG_NAMESPACE::Numeric
{
    //円形の範囲内のランダムな点を作成
    class RandomCircleBase : public Object {
        public:
        using ImplType = IMPLEMENTATION::RandomCircleBase;

        RandomCircleBase() = delete;
        constexpr RandomCircleBase(std::nullptr_t) noexcept : Object(nullptr) {}

        //ランダムな点を取得
        [[nodiscard]]
        Vector2Double Next() const;

        //半径
        [[nodiscard]]
        double Radius() const;

        void Radius(double value) const;
    };
}

#endif //!KONGKONG_NUMERIC_RANDOMCIRCLEBASE_H
