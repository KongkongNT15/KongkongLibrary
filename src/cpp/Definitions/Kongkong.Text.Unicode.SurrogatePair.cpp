//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    char32_t SurrogatePair::ToUnicode(char16_t highSurrogate, char16_t lowSurrogate)
    {
        _checkPair(highSurrogate, lowSurrogate);
        return ToUnicodeUnsafe(highSurrogate, lowSurrogate);
    }

    SurrogatePair::SurrogatePair(char32_t c)
    {
        if (c < U'\U00010000' || U'\U0010FFFF' < c) [[unlikely]] throw ArgumentOutOfRangeException(u"コードポイントは U+10000～U+10FFFF の範囲である必要があります。");

        uint32_t cpPrime = c - 0x10000;
        m_highSurrogate = (char16_t)(0xD800 + (cpPrime >> 10));
        m_lowSurrogate  = (char16_t)(0xDC00 + (cpPrime & 0x3FF));
    }

    SurrogatePair::SurrogatePair(char16_t highSurrogate, char16_t lowSurrogate) : m_highSurrogate(highSurrogate), m_lowSurrogate(lowSurrogate)
    {
        _checkPair(highSurrogate, lowSurrogate);
    }

    String SurrogatePair::ToString() const
    {
        constexpr ssize_t capacity = 14;
        char str[capacity];

        ::snprintf(str, capacity, "\\u%04lX,\\u%04lX", (unsigned long)m_highSurrogate, (unsigned long)m_lowSurrogate);

        return String::FromAsciiUnsafe(capacity - 1, str);
    }

    void SurrogatePair::_checkPair(char16_t highSurrogate, char16_t lowSurrogate)
    {
        if (highSurrogate < 0xD800 || 0xDBFF < highSurrogate) [[unlikely]] {
            throw ArgumentOutOfRangeException(u"high サロゲートが無効です（0xD800～0xDBFF の範囲外）");
        }
        if (lowSurrogate < 0xDC00 || lowSurrogate > 0xDFFF) [[unlikely]] {
            throw ArgumentOutOfRangeException(u"low サロゲートが無効です（0xDC00～0xDFFF の範囲外）");
        }
    }
}