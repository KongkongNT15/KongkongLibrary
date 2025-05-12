#ifndef KONGKONG_TEXT_UNICODE_UNICODERANGEITERATOR_H
#define KONGKONG_TEXT_UNICODE_UNICODERANGEITERATOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    struct UnicodeRangeIterator : public ValueType {

        constexpr UnicodeRangeIterator(char32_t c) noexcept : m_current(c) {}

        constexpr UnicodeRangeIterator& operator++() noexcept
        {
            ++m_current;
            return *this;
        }

        constexpr UnicodeRangeIterator operator++(int) noexcept
        {
            UnicodeRangeIterator result = *this;
            ++m_current;

            return result;
        }

        [[nodiscard]]
        constexpr char32_t operator*() const noexcept { return m_current; }

        [[nodiscard]]
        String ToString() const;

        private:
        char32_t m_current;

        friend constexpr bool operator==(UnicodeRangeIterator, UnicodeRangeIterator) noexcept;
        friend constexpr bool operator!=(UnicodeRangeIterator, UnicodeRangeIterator) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(UnicodeRangeIterator left, UnicodeRangeIterator right) noexcept { return left.m_current == right.m_current; }
    [[nodiscard]] constexpr bool operator!=(UnicodeRangeIterator left, UnicodeRangeIterator right) noexcept { return left.m_current != right.m_current; }
}

#endif //!KONGKONG_TEXT_UNICODE_UNICODERANGEITERATOR_H