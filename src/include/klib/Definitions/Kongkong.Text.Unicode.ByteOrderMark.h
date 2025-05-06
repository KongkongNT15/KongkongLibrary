#ifndef KONGKONG_TEXT_UNICODE_BYTEORDERMARK_H
#define KONGKONG_TEXT_UNICODE_BYTEORDERMARK_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    /// @brief BOM
    /// @note 関数の戻り値はautoで受け取りましょうねぇ？
    class ByteOrderMark final {
        public:

        STATIC_CLASS(ByteOrderMark)

        template <ssize_t N>
        struct ImplType final {
            public:
            const uint8_t m_byteOrderMark[N];

            [[nodiscard]] constexpr const uint8_t* begin() const noexcept { return m_byteOrderMark; }
            [[nodiscard]] constexpr const uint8_t* end() const noexcept { return m_byteOrderMark + N; }

            [[nodiscard]] static constexpr ssize_t ElementSize() noexcept { return 1; }

            [[nodiscard]] constexpr const uint8_t* Data() const noexcept { return m_byteOrderMark; }

            [[nodiscard]] constexpr ssize_t Length() const noexcept { return N; }
        };

        /// @brief UTF-8
        [[nodiscard]]
        static consteval ImplType<3> Utf8() noexcept { return { 0xEF, 0xBB, 0xBF }; }

        /// @brief UTF-16BE
        [[nodiscard]]
        static consteval ImplType<2> Utf16BE() noexcept { return { 0xFE, 0xFF }; }

        /// @brief UTF-16LE
        [[nodiscard]]
        static consteval ImplType<2> Utf16LE() noexcept { return { 0xFF, 0xFE }; }
    
        /// @brief UTF32-BE
        [[nodiscard]]
        static consteval ImplType<4> Utf32BE() noexcept { return { 0x00, 0x00, 0xFE, 0xFF }; }

        /// @brief UTF-32LE
        [[nodiscard]]
        static consteval ImplType<4> Utf32LE() noexcept { return { 0xFF, 0xFE, 0x00, 0x00 }; }
    };
}

#endif //!KONGKONG_TEXT_UNICODE_BYTEORDERMARK_H