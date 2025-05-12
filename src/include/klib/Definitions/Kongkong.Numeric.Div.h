#ifndef KONGKONG_NUMERIC_DIV_H
#define KONGKONG_NUMERIC_DIV_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"

#include <sstream>

namespace KONGKONG_NAMESPACE::Numeric
{
    //割り算の症とあまり
    template <NumberType TNum>
    struct Div final : public ValueType {

        constexpr Div(TNum quot, TNum rem) noexcept : _quotient(quot), _remainder(rem) {}

        /// @brief 余り
        [[nodiscard]]
        constexpr TNum Remainder() const noexcept { return _remainder; }
        
        /// @brief 商
        [[nodiscard]]
        constexpr TNum Quotient() const noexcept { return _quotient; }

        /// @brief 商とあまりの文字列表現を取得
        /// @return u"(商, 余)"
        [[nodiscard]]
        String ToString() const;

        private:
        TNum _remainder;
        TNum _quotient;

        template <NumberType UNum>
        friend constexpr bool operator==(Div<UNum> const&, Div<UNum> const&) noexcept;

        template <NumberType UNum>
        friend constexpr bool operator!=(Div<UNum> const&, Div<UNum> const&) noexcept;
    };

    template <NumberType TNum>
    [[nodiscard]] constexpr bool operator==(Div<TNum> const& left, Div<TNum> const& right) noexcept { return left._remainder == right._remainder && left._quotient == right._quotient; }

    template <NumberType TNum>
    [[nodiscard]] constexpr bool operator!=(Div<TNum> const& left, Div<TNum> const& right) noexcept { return left._remainder != right._remainder && left._quotient != right._quotient; }
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
