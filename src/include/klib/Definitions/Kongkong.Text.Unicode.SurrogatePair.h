#ifndef KONGKONG_TEXT_UNICODE_SURROGATEPAIR_H
#define KONGKONG_TEXT_UNICODE_SURROGATEPAIR_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    /// @brief UTF-16のサロゲートペア
    struct SurrogatePair : public ValueType {

        [[nodiscard]]
        static SurrogatePair CreateUnsafe(char32_t c) noexcept { return SurrogatePair(c, true); }

        [[nodiscard]]
        static char32_t ToUnicode(char16_t highSurrogate, char16_t lowSurrogate);

        [[nodiscard]]
        static constexpr char32_t ToUnicodeUnsafe(char16_t highSurrogate, char16_t lowSurrogate) noexcept { return (char32_t)(((highSurrogate - 0xD800) << 10) + lowSurrogate + (-0xDC00 + 0x10000));}

        SurrogatePair(char32_t c);
        SurrogatePair(char16_t highSurrogate, char16_t lowSurrogate);

        [[nodiscard]]
        constexpr char16_t HighSurrogate() const noexcept { return m_highSurrogate; }

        [[nodiscard]]
        constexpr char16_t LowSurrogate() const noexcept { return m_lowSurrogate; }

        [[nodiscard]]
        String ToString() const;

        [[nodiscard]]
        constexpr char32_t ToUnicode() const noexcept { return ToUnicodeUnsafe(m_highSurrogate, m_lowSurrogate); }

        private:
        char16_t m_highSurrogate;
        char16_t m_lowSurrogate;

        static void _checkPair(char16_t highSurrogate, char16_t lowSurrogate);

        constexpr SurrogatePair(char32_t c, bool) noexcept
        {
            uint32_t cpPrime = c - 0x10000;
            m_highSurrogate = (char16_t)(0xD800 + (cpPrime >> 10));
            m_lowSurrogate  = (char16_t)(0xDC00 + (cpPrime & 0x3FF));
        }
    };
}

#endif //!KONGKONG_TEXT_UNICODE_SURROGATEPAIR_H