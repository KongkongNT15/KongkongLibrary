//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Net
{
    String IPv4Address::ToString() const
    {
        constexpr ssize_t strSize = 16;
        int result;
        char str[strSize];

        result = ::snprintf(str, strSize, "%hhu.%hhu.%hhu.%hhu", _octetA, _octetB, _octetC, _octetD);

        return String::FromAsciiUnsafe(result, str);
    }
}
