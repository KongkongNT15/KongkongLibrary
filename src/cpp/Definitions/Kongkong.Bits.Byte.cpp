//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Bits
{
    String Byte::ToString() const
    {
        constexpr size_t arrSize = 5;
        char str[arrSize];

        ::snprintf(str, arrSize, "0x%02hhX", _value);

        return String::FromAsciiUnsafe(arrSize - 1, str);
    }
}
