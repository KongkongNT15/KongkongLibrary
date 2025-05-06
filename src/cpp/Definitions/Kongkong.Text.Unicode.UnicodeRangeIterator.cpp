//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    String UnicodeRangeIterator::ToString() const
    {
        constexpr ssize_t capacity = 11;
        char str[capacity];

        ::snprintf(str, capacity, "\\U%08lX", (unsigned long)m_current);

        return String::FromAsciiUnsafe(capacity - 1, str);
    }
}