//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Std
{
    template <CharType TChar>
    GenericPosixFileIOBuffer<TChar>::GenericPosixFileIOBuffer(int ioDevice) : Base(ioDevice)
    {
    }
    
    template <CharType TChar>
    int GenericPosixFileIOBuffer<TChar>::sync() noexcept
    {
        return ::fsync(Base::_ioDevice);
    }

    template class GenericPosixFileIOBuffer<char>;
    template class GenericPosixFileIOBuffer<wchar_t>;
    template class GenericPosixFileIOBuffer<char8_t>;
    template class GenericPosixFileIOBuffer<char16_t>;
    template class GenericPosixFileIOBuffer<char32_t>;
}
