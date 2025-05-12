#ifndef KONGKONG_TEXT_UNICODE_UNICODERANGE_H
#define KONGKONG_TEXT_UNICODE_UNICODERANGE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Text.Unicode.UnicodeRangeIterator.h"
#include "Kongkong.Collections.CollectionHelper.h"

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    struct UnicodeRange : public ValueType {

        [[nodiscard]]
        constexpr UnicodeRange CreateUnsafe(char32_t firstCodePoint, char32_t lastCodePoint) noexcept { return UnicodeRange(firstCodePoint, (uint32_t)(lastCodePoint - firstCodePoint + 1)); }

        constexpr UnicodeRange(char32_t firstCodePoint, uint32_t length) noexcept : m_firstCodePoint(firstCodePoint), m_length(length) {}

        [[nodiscard]]
        constexpr char32_t operator[](int32_t index) const noexcept { return (char32_t)(m_firstCodePoint + index); }

        [[nodiscard]] constexpr UnicodeRangeIterator begin() const noexcept { return UnicodeRangeIterator(m_firstCodePoint); }
        [[nodiscard]] constexpr UnicodeRangeIterator end() const noexcept { return UnicodeRangeIterator((char32_t)(m_firstCodePoint + m_length)); }

        [[nodiscard]]
        constexpr bool Contains(char32_t c) const noexcept
        {
            if (c < m_firstCodePoint) return false;
            if (c >= (char32_t)(m_firstCodePoint + m_length)) return false;

            return true;
        }

        [[nodiscard]]
        constexpr char32_t FirstCodePoint() const noexcept { return m_firstCodePoint; }

        [[nodiscard]]
        constexpr ssize_t IndexOf(char32_t c) const noexcept
        {
            if (c < m_firstCodePoint) return Collections::CollectionHelper::NotFound();
            if (c >= (char32_t)(m_firstCodePoint + m_length)) return Collections::CollectionHelper::NotFound();

            return (ssize_t)(c - m_firstCodePoint);
        }

        [[nodiscard]]
        constexpr uint32_t Length() const noexcept { return m_length; }

        /// @brief 文字列表現を取得
        /// @return u"[\U{first},\U{last}]"
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        char32_t m_firstCodePoint;
        uint32_t m_length;

        friend constexpr bool operator==(UnicodeRange const&, UnicodeRange const&) noexcept;
        friend constexpr bool operator!=(UnicodeRange const&, UnicodeRange const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(UnicodeRange const& left, UnicodeRange const& right) noexcept { return left.m_firstCodePoint == right.m_firstCodePoint && left.m_length == right.m_length; }
    [[nodiscard]] constexpr bool operator!=(UnicodeRange const& left, UnicodeRange const& right) noexcept { return left.m_firstCodePoint != right.m_firstCodePoint && left.m_length != right.m_length; }
}

#endif //!KONGKONG_TEXT_UNICODE_UNICODERANGE_H