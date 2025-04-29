//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Std
{
    template <CharType TChar>
    GenericPosixIOBuffer<TChar>::GenericPosixIOBuffer(int ioDevice) : _ioDevice(ioDevice)
    {
    }

    template <CharType TChar>
    ::std::streamsize GenericPosixIOBuffer<TChar>::xsputn(const TChar* str, ::std::streamsize n) noexcept
    {
        if constexpr (sizeof(TChar) == 1) return Posix::IO::IOHelper::WriteUnsafe(_ioDevice, n, str);
        else return Posix::IO::IOHelper::WriteUnsafe(_ioDevice, n * sizeof(TChar), str) / sizeof(TChar);
    }

    template class GenericPosixIOBuffer<char>;
    template class GenericPosixIOBuffer<wchar_t>;
    template class GenericPosixIOBuffer<char8_t>;
    template class GenericPosixIOBuffer<char16_t>;
    template class GenericPosixIOBuffer<char32_t>;
}
