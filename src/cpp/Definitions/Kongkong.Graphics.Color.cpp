//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Graphics
{
    String Color::ToString() const
    {
        constexpr ssize_t length = 23;
        char wcs[length];
        //0xFF, 0xFF, 0xFF, 0xFF
        std::snprintf(wcs, length, "0x%02hhX, 0x%02hhX, 0x%02hhX, 0x%02hhX", m_a, m_r, m_g, m_b);

        return String::FromAsciiUnsafe(length - 1, wcs);
    }
}