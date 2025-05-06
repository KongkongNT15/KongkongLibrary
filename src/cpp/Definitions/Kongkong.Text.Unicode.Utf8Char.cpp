//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    ssize_t Utf8Char::GetMultiByteCharLength(char16_t c)
    {
        if (c < 0x80) return 1;
        if (c < 0x800) return 2;

        if (!UnicodeTraits::IsValidCodePoint(c)) [[unlikely]] {
            if (UnicodeTraits::IsSurrogate(c)) throw InvalidCodePointException(u"指定されたコードポイントはサロゲートです");
            throw InvalidCodePointException();
        }
        
        return 3;
    }

    ssize_t Utf8Char::GetMultiByteCharLength(char32_t c)
    {
        if (c < 0x80) return 1;
        if (c < 0x800) return 2;

        if (!UnicodeTraits::IsValidCodePoint(c)) [[unlikely]] throw InvalidCodePointException();
        
        if (c < 0x10000) return 3;

        return 4;
    }

    Utf8Char::Utf8Char(char16_t c)
    {
        if (!UnicodeTraits::IsValidCodePoint(c)) [[unlikely]] {
            if (UnicodeTraits::IsSurrogate(c)) throw InvalidCodePointException(u"指定されたコードポイントはサロゲートです");
            throw InvalidCodePointException();
        }
        m_length = s_encode(c, m_multibyteChar);
    }

    Utf8Char::Utf8Char(char32_t c)
    {
        if (!UnicodeTraits::IsValidCodePoint(c)) [[unlikely]] throw InvalidCodePointException();
        m_length = s_encode(c, m_multibyteChar);
    }

    Utf8Char::Utf8Char(SurrogatePair pair) noexcept : Utf8Char(pair.ToUnicode(), true)
    {
    }
}