#ifndef KONGKONG_NUMERIC_DIV_H
#define KONGKONG_NUMERIC_DIV_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"

#include <sstream>

namespace KONGKONG_NAMESPACE::Numeric
{
    //割り算の症とあまり
    template <NumberType Num>
    struct Div final : public ValueType {

        constexpr Div(Num quot, Num rem) noexcept : _quotient(quot), _remainder(rem) {}

        //あまり
        constexpr Num Remainder() const noexcept { return _remainder; }
        //省
        constexpr Num Quotient() const noexcept { return _quotient; }

        /// @brief 商とあまりの文字列表現を取得
        /// @return u"(商, 余)"
        [[nodiscard]]
        String ToString() const;

        private:
        Num _remainder;
        Num _quotient;
    };
}

namespace KONGKONG_NAMESPACE::Numeric
{
    template <NumberType Num>
    String Div<Num>::ToString() const
    {
        std::ostringstream sout;

        sout << '(' << Quotient() << ", " << Remainder() << ')';

        return String::FromAscii(sout.str());
    }
}

#endif //!KONGKONG_NUMERIC_VECTOR_H
