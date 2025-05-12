//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::System
{
    String BuildVersion::ToString() const
    {
        constexpr size_t strLength = 34;
        char str[strLength];

        int length = ::snprintf(str, strLength, "%hu.%hu.%ld%ld", m_major, m_minor, m_patch, m_buildNumber);

        return String::FromAsciiUnsafe(length, str);
    }
}
