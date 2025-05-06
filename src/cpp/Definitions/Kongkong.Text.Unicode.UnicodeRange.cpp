//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    String UnicodeRange::ToString() const
    {
        constexpr ssize_t capacity = 24;
        char str[capacity];

        ::snprintf(str, capacity, "[\\U%08lX:\\U%08lX]", (unsigned long)m_firstCodePoint, (unsigned long)(m_firstCodePoint + m_length - 1));

        return String::FromAsciiUnsafe(capacity - 1, str);
    }
}