//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    uint64_t MinWinHelper::ToUInt64(uint32_t high, uint32_t low) noexcept
    {
        uint64_t v;

        uint32_t *p32 = (uint32_t*)&v;

        p32[0] = low;
        p32[1] = high;

        return v;
    }
}
