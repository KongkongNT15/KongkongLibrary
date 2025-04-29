#ifndef KONGKONG_NUMERIC_EQUATION2_H
#define KONGKONG_NUMERIC_EQUATION2_H

#include "Base.h"

#include "Kongkong.InvalidArgumentException.h"
#include "Kongkong.InvalidOperationException.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"

#include <cmath>

namespace KONGKONG_NAMESPACE::Numeric
{
    //2次方程式
    template <std::floating_point TNum>
    struct Equation2 : ValueType {
        Equation2(TNum a, TNum b, TNum c) : _a(a), _b(b), _c(c)
        {
            if (a == (TNum)0.0) [[unlikely]] throw InvalidArgumentException(u"係数Aにゼロを代入しようとしました。"); 
        }

        String ToString() const { return u"Kongkong::Numeric::Equation2<T>"; }

        //係数
        constexpr TNum A() const noexcept { return _a; }
        void A(TNum value)
        {
            if (value == (TNum)0.0) throw InvalidArgumentException(u"係数Aにゼロを代入しようとしました。");

            _a = value;
        }
        

        constexpr TNum B() const noexcept { return _b; }
        constexpr void B(TNum value) noexcept { _b = value; }

        constexpr TNum C() const noexcept { return _c; }
        constexpr void C(TNum value) noexcept { _c = value; }

        //判別式
        constexpr TNum Discriminant() const noexcept { return _b * _b - (TNum)4.0 * _a * _c; }

        //会が存在するか
        constexpr bool HasSolution() const noexcept { return SolutionCount() != 0; }

        //回の個数
        constexpr int SolutionCount() const noexcept
        {
            TNum discriminant = Discriminant();

            if (discriminant > (TNum)0.0) return 2;
            if (discriminant == (TNum)0.0) return 1;

            return 0;
        }

        //買
        Collections::IArray<TNum> Solution() const
        {
            Collections::ArrayList<TNum> list;
            switch (SolutionCount()) {

                case 0:
                    throw InvalidOperationException(u"解が存在しません");
                    break;

                case 1:
                    list.Append(_b * _b / ((TNum)2 * _a));
                    break;

                case 2:
                    TNum b2 = _b * _b;
                    TNum bunbo = (TNum)2.0 * _a;
                    TNum dq = std::sqrt(Discriminant());

                    list.Append((b2 + dq) / bunbo);
                    list.Append((b2 - dq) / bunbo);
                    break;
            }

            return list;
        }

        private:

        TNum _a;
        TNum _b;
        TNum _c;
    };
}

#endif //!KONGKONG_NUMERIC_EQUATION2_H
