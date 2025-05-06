﻿#ifndef KONGKONG_TEXT_UNICODE_UNICODETRAITS_H
#define KONGKONG_TEXT_UNICODE_UNICODETRAITS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    class UnicodeTraits final {
        public:

        STATIC_CLASS(UnicodeTraits)

        [[nodiscard]]
        static constexpr bool IsHighSurrogate(char16_t c) noexcept { return 0xD7FF < c && c < 0xDC00; }

        [[nodiscard]]
        static constexpr bool IsLowSurrogate(char16_t c) noexcept { return 0xDBFF < c && c < 0xE000; }

        [[nodiscard]]
        static constexpr bool IsSurrogate(char16_t c) noexcept { return 0xD7FF < c && c < 0xE000; }

        [[nodiscard]]
        static constexpr bool IsSurrogatePairRequired(char32_t c) noexcept { return U'\U00010000' <= c &&  c <= U'\U0010FFFF'; }

        [[nodiscard]]
        static constexpr bool IsValidCodePoint(char16_t c) noexcept
        {
            switch (c) {
                case 0xFFFE: [[unlikely]]
                case 0xFFFF: [[unlikely]]
                    return false;

                default: [[likely]]
                {
                    if (c < 0xD800) return true;

                    // ここで c >= U'\uD800'
                    // サロゲートペア
                    if (c < 0xE000) return false;

                    // ここで c >= U'\uE000'
                    if (c < 0xFDD0) return true;

                    // ここで c >= U'\uFDD0'
                    // 非文字
                    if (c < 0xFDF0) return false;

                    return true;
                }
            }

#if KONGKONG_HAS_CPP23
            ::std::unreachable();
#endif
        }

        [[nodiscard]]
        static constexpr bool IsValidCodePoint(char32_t c) noexcept
        {
            if (c < 0xD800) return true;

            // ここで c >= U'\uD800'
            // サロゲートペア
            if (c < 0xE000) return false;

            // ここで c >= U'\uE000'
            if (c < 0xFDD0) return true;

            // ここで c >= U'\uFDD0'
            // 非文字
            if (c < 0xFDF0) return false;

            if ((c & 0xFFFF) == 0xFFFF || (c & 0xFFFE) == 0xFFFE) [[unlikely]] return false;

            return c < 0x00110000;
                
            

#if KONGKONG_HAS_CPP23
            ::std::unreachable();
#endif
        }
    };
}

#endif //!KONGKONG_TEXT_UNICODE_UNICODETRAITS_H