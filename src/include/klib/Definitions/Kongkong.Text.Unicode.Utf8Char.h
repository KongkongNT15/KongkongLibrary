#ifndef KONGKONG_TEXT_UNICODE_UTF8CHAR_H
#define KONGKONG_TEXT_UNICODE_UTF8CHAR_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    struct Utf8Char : public ValueType {

        [[nodiscard]]
        static constexpr Utf8Char CreateUnsafe(char16_t c) noexcept { return Utf8Char(c, true); }

        [[nodiscard]]
        static constexpr Utf8Char CreateUnsafe(char32_t c) noexcept { return Utf8Char(c, true); }

        [[nodiscard]]
        static ssize_t GetMultiByteCharLength(char16_t c);

        [[nodiscard]]
        static ssize_t GetMultiByteCharLength(char32_t c);

        [[nodiscard]]
        static constexpr ssize_t GetMultiByteCharLengthUnsafe(char16_t c) noexcept
        {
            if (c < 0x80) return 1;
            if (c < 0x800) return 2;
            
            return 3;
        }

        [[nodiscard]]
        static constexpr ssize_t GetMultiByteCharLengthUnsafe(char32_t c) noexcept
        {
            if (c < 0x80) return 1;
            if (c < 0x800) return 2;
            if (c < 0x10000) return 3;

            return 4;
        }

        Utf8Char(char16_t c);
        Utf8Char(char32_t c);
        Utf8Char(SurrogatePair pair) noexcept;

        [[nodiscard]] constexpr const char8_t* begin() const noexcept { return m_multibyteChar; }
        [[nodiscard]] constexpr const char8_t* end() const noexcept { return m_multibyteChar + m_length; }

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return m_length; }

        [[nodiscard]]
        String ToString() const;

        private:
        static constexpr ssize_t s_arrLength = 4;

        char8_t m_multibyteChar[s_arrLength];
        uint8_t m_length;

        static constexpr uint8_t s_encode(char16_t c, char8_t* arr) noexcept
        {
#if KONGKONG_HAS_CPP23
            [[assume(arr != nullptr)]];
#endif
            if (c < 0x80) {
                *arr = (char8_t)c;
                return 1;
            }
            if (c < 0x800) {
                *arr = (char8_t)(0xC0 | ((c >> 6) & 0x1F));
                arr[1] = (char8_t)(0x80 | (c & 0x3F));
                
                return 2;
            }

            arr[0] = (char8_t)(0xE0 | ((c >> 12) & 0x0F));
            arr[1] = (char8_t)(0x80 | ((c >> 6) & 0x3F));
            arr[2] = (char8_t)(0x80 | (c & 0x3F));
            
            return 3;
        }

        static constexpr uint8_t s_encode(char32_t c, char8_t* arr) noexcept
        {
#if KONGKONG_HAS_CPP23
            [[assume(arr != nullptr)]];
#endif
            if (c < 0x80) {
                *arr = (char8_t)c;
                return 1;
            }
            if (c < 0x800) {
                *arr = (char8_t)(0xC0 | ((c >> 6) & 0x1F));
                arr[1] = (char8_t)(0x80 | (c & 0x3F));
                
                return 2;
            }
            if (c < 0x10000) {
                arr[0] = (char8_t)(0xE0 | ((c >> 12) & 0x0F));
                arr[1] = (char8_t)(0x80 | ((c >> 6) & 0x3F));
                arr[2] = (char8_t)(0x80 | (c & 0x3F));
                
                return 3;
            }
            if (c < 0x110000) {
                arr[0] = (char8_t)(0xF0 | ((c >> 18) & 0x07));
                arr[1] = (char8_t)(0x80 | ((c >> 12) & 0x3F));
                arr[2] = (char8_t)(0x80 | ((c >> 6) & 0x3F));
                arr[3] = (char8_t)(0x80 | (c & 0x3F));
                
                return 4;
            }

            return (uint8_t)-1;
        }

        constexpr Utf8Char(char16_t c, bool) noexcept : m_length(s_encode(c, m_multibyteChar)) {}
        constexpr Utf8Char(char32_t c, bool) noexcept : m_length(s_encode(c, m_multibyteChar)) {}
    };
}

#endif //!KONGKONG_TEXT_UNICODE_UTF8CHAR_H