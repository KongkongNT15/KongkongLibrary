//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Standard::Cpp
{
    std::string StdString::FromCStrings(const char* cString1, const char* cString2)
    {
        return _fromCStrings(cString1, cString2);
    }

    std::wstring StdString::FromCStrings(const wchar_t* cString1, const wchar_t* cString2)
    {
        return _fromCStrings(cString1, cString2);
    }
    
    std::u8string StdString::FromCStrings(const char8_t* cString1, const char8_t* cString2)
    {
        return _fromCStrings(cString1, cString2);
    }
    
    std::u16string StdString::FromCStrings(const char16_t* cString1, const char16_t* cString2)
    {
        return _fromCStrings(cString1, cString2);
    }
    
    std::u32string StdString::FromCStrings(const char32_t* cString1, const char32_t* cString2)
    {
        return _fromCStrings(cString1, cString2);
    }

    std::string StdString::FromCStringsUnsafe(const char* cString1, const char* cString2)
    {
        return _fromCStringsUnsafe(cString1, cString2);
    }

    std::wstring StdString::FromCStringsUnsafe(const wchar_t* cString1, const wchar_t* cString2)
    {
        return _fromCStringsUnsafe(cString1, cString2);
    }
    
    std::u8string StdString::FromCStringsUnsafe(const char8_t* cString1, const char8_t* cString2)
    {
        return _fromCStringsUnsafe(cString1, cString2);
    }
    
    std::u16string StdString::FromCStringsUnsafe(const char16_t* cString1, const char16_t* cString2)
    {
        return _fromCStringsUnsafe(cString1, cString2);
    }
    
    std::u32string StdString::FromCStringsUnsafe(const char32_t* cString1, const char32_t* cString2)
    {
        return _fromCStringsUnsafe(cString1, cString2);
    }

    template <class TChar>
    std::basic_string<TChar, std::char_traits<TChar>> StdString::_fromCStrings(const TChar* cString1, const TChar* cString2)
    {
        ArgumentNullException::CheckNull(cString1, u"cString1");
        ArgumentNullException::CheckNull(cString2, u"cString2");

        return _fromCStringsUnsafe(cString1, cString2);
    }

    template <class TChar>
    std::basic_string<TChar, std::char_traits<TChar>> StdString::_fromCStringsUnsafe(const TChar* cString1, const TChar* cString2)
    {
        std::basic_string<TChar, std::char_traits<TChar>> str = cString1;
        str.append(cString2);

        return str;
    }
}
