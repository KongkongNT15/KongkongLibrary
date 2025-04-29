//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric::NumberTypes
{
    template<>
    int8_t Int8::Parse(String const& str) { return _parseCharType(str); }
    template<>
    int16_t Int16::Parse(String const& str) { return _parseCharType(str); }
    template<>
    uint8_t UInt8::Parse(String const& str) { return _parseCharType(str); }
    template<>
    uint16_t UInt16::Parse(String const& str) { return _parseCharType(str); }

    template <NumberType Num>
    Num NumberTemplate<Num>::_parseCharType(String const& str)
    {
        int v = Int::Parse(str);
        if (v < MinValue() || MaxValue() < v) throw OverflowException(u"整数がオーバーフローしました");
        return (Num)v;
    }
}
