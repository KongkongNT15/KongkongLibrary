//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::UI
{
    String Color::ToString() const
    {
        constexpr ssize_t length = 23;
        char wcs[length];
        //0xFF, 0xFF, 0xFF, 0xFF
        std::snprintf(wcs, length, "0x%02hhX, 0x%02hhX, 0x%02hhX, 0x%02hhX", A(), R(), G(), B());

        return String::FromAsciiUnsafe(length - 1, wcs);
    }
}
