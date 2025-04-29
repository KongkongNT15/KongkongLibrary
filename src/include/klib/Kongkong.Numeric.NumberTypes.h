#ifndef KONGKONG_NUMERIC_NUMBERTYPES_H
#define KONGKONG_NUMERIC_NUMBERTYPES_H
#include "Kongkong.h"

namespace KONGKONG_NAMESPACE::Numeric::NumberTypes
{
    //template数値型
    template <NumberType Num>
    class NumberTemplate final {

        public:

        STATIC_CLASS(NumberTemplate)

        //型のサイズ
        static constexpr ssize_t BitSize() noexcept { return (ssize_t)(sizeof(Num) * 8); }
        static constexpr ssize_t ByteSize() noexcept { return (ssize_t)(sizeof(Num)); }

        //正負の判定
        static constexpr bool IsNegative(Num value) noexcept { return value < Num(); }
        static constexpr bool IsPositive(Num value) noexcept { return value > Num(); }

        //2つの数値のうち大きいほうを取得
        static constexpr Num Max(Num left, Num right) noexcept { return left > right ? left : right; }

        //型の最大値
        static constexpr Num MaxValue() noexcept { return std::numeric_limits<Num>::max(); }

        //2つの数値のうち小さいほうを取得
        static constexpr Num Min(Num left, Num right) noexcept { return left < right ? left : right; }

        //型の最小値
        static constexpr Num MinValue() noexcept { return std::numeric_limits<Num>::min(); }

        //Stringから数値に変換
        static Num Parse(String const& value);

        static bool TryParse(String const& s, Num& result) noexcept;

        private:

        //文字型として使われる整数型を正しく変換する用
        //int8_t, uint8_t, int16_t, uint16_t 
        static Num _parseCharType(String const& str);

    };

    template<>
    int8_t Int8::Parse(String const& str);
    template<>
    int16_t Int16::Parse(String const& str);
    template<>
    uint8_t UInt8::Parse(String const& str);
    template<>
    uint16_t UInt16::Parse(String const& str);
    

    //メソッドの実装
    template <NumberType Num>
    Num NumberTemplate<Num>::Parse(String const& value)
    {

        if (value.Length() == 0) [[unlikely]] throw FormatException(value);

        std::istringstream wsin{ std::to_string(value).c_str() };
        Num ret;

        wsin >> ret;

        if (wsin.fail()) {
            wsin.clear();
            if (wsin.peek() == std::char_traits<char>::eof()) throw OverflowException(u"Arithmetic operation resulted in an overflow.");
            else throw FormatException(value);
        }

        if (wsin.peek() != std::char_traits<char>::eof()) throw FormatException(value);

        return ret; 
    }

    template <NumberType Num>
    bool NumberTemplate<Num>::TryParse(String const& s, Num& result) noexcept
    {
        try {
            result = Parse(s);
            return true;
        }
        catch (...) {
            return false;
        }
    }

    

}

#endif //!KONGKONG_NUMERIC_NUMBERTYPES_H
