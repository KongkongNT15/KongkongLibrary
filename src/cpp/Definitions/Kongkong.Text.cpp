//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text
{

    Char& Char::operator=(char16_t c) noexcept
    {
        _c = c;
        return *this;
    }

    String Char::ToString(char16_t c)
    {
        char16_t* p = String::AllocMemoryUnsafe(2);

        p[0] = c;
        p[1] = u'\0';

        return String::WrapUnsafe(2, 1, p);
    }

    String Char::ToString() const
    {
        return ToString(_c);
    }

    Collections::IReadOnlyArray<uint8_t> ByteOrderMark::_utf8 = Collections::Array<uint8_t>({ 0xEF, 0xBB, 0xBF });
    Collections::IReadOnlyArray<uint8_t> ByteOrderMark::_utf16LE = Collections::Array<uint8_t>({ 0xFF, 0xFE });
    Collections::IReadOnlyArray<uint8_t> ByteOrderMark::_utf16BE = Collections::Array<uint8_t>({ 0xFE, 0xFF });
    Collections::IReadOnlyArray<uint8_t> ByteOrderMark::_utf32LE = Collections::Array<uint8_t>({ 0xFF, 0xFE, 0x00, 0x00 });
    Collections::IReadOnlyArray<uint8_t> ByteOrderMark::_utf32BE = Collections::Array<uint8_t>({ 0x00, 0x00, 0xFE, 0xFF });
    

    String StringHelper::ToCharCode(String const& str)
    {
        std::ostringstream wsout;

        wsout << std::hex;
        wsout << std::uppercase;
        wsout.fill('0');

        for (ssize_t i = 0; i < str.Length(); ++i) {
            wsout.width(4);
            wsout << (int)str[i] << ' ';
        }

        //最後の空白を削除してreturn
        auto s = wsout.str();
        s.pop_back();

        return s.c_str();
    }

}
