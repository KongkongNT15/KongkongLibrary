//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    std::strong_ordering CString::Compare(const char* left, const char* right)
    {
        return _compare(left, right);
    }

    std::strong_ordering CString::Compare(const wchar_t* left, const wchar_t* right)
    {
        return _compare(left, right);
    }

    std::strong_ordering CString::Compare(const char8_t* left, const char8_t* right)
    {
        return _compare(left, right);
    }

    std::strong_ordering CString::Compare(const char16_t* left, const char16_t* right)
    {
        return _compare(left, right);
    }

    std::strong_ordering CString::Compare(const char32_t* left, const char32_t* right)
    {
        return _compare(left, right);
    }

    std::partial_ordering CString::Compare(size_t count, const char* left, const char* right)
    {
        return _compare(count, left, right);
    }

    std::partial_ordering CString::Compare(size_t count, const wchar_t* left, const wchar_t* right)
    {
        return _compare(count, left, right);
    }

    std::partial_ordering CString::Compare(size_t count, const char8_t* left, const char8_t* right)
    {
        return _compare(count, left, right);
    }

    std::partial_ordering CString::Compare(size_t count, const char16_t* left, const char16_t* right)
    {
        return _compare(count, left, right);
    }

    std::partial_ordering CString::Compare(size_t count, const char32_t* left, const char32_t* right)
    {
        return _compare(count, left, right);
    }

    size_t CString::CountMultibyteChars(const char* mbChars)
    {
        ArgumentNullException::CheckNull(mbChars, u"mbChars");

        size_t count = 0;
        int res;

        const char* p = mbChars;

        while (*p != '\0') {
            res = ::mblen(p, MB_CUR_MAX);
            if (res == EOF) [[unlikely]] throw CStdException();

            p += res;
            count++;
        }

        return count;
    }

    char* CString::Dump(const char* str)
    {
        return _dump(str);
    }

    wchar_t* CString::Dump(const wchar_t* str)
    {
        return _dump(str);
    }

    char8_t* CString::Dump(const char8_t* str)
    {
        return _dump(str);
    }

    char16_t* CString::Dump(const char16_t* str)
    {
        return _dump(str);
    }

    char32_t* CString::Dump(const char32_t* str)
    {
        return _dump(str);
    }

    size_t CString::Find(const char* str, const char* subString)
    {
        ArgumentNullException::CheckNull(str, u"str");
        ArgumentNullException::CheckNull(subString, u"subString");

        const char* result = ::strstr(str, subString);
        
        if (result == nullptr) return NotFound();

        return result - str;
    }

    size_t CString::Find(const wchar_t* str, const wchar_t* subString)
    {
        ArgumentNullException::CheckNull(str, u"str");
        ArgumentNullException::CheckNull(subString, u"subString");

        const wchar_t* result = ::wcsstr(str, subString);
        
        if (result == nullptr) return NotFound();

        return result - str;
    }

    bool CString::IsEqual(const char* left, const char* right)
    {
        return _isEqual(left, right);
    }

    bool CString::IsEqual(const wchar_t* left, const wchar_t* right)
    {
        return _isEqual(left, right);
    }

    bool CString::IsEqual(const char8_t* left, const char8_t* right)
    {
        return _isEqual(left, right);
    }

    bool CString::IsEqual(const char16_t* left, const char16_t* right)
    {
        return _isEqual(left, right);
    }

    bool CString::IsEqual(const char32_t* left, const char32_t* right)
    {
        return _isEqual(left, right);
    }

    bool CString::IsEqual(size_t count, const char* left, const char* right)
    {
        return _isEqual(count, left, right);
    }

    bool CString::IsEqual(size_t count, const wchar_t* left, const wchar_t* right)
    {
        return _isEqual(count, left, right);
    }

    bool CString::IsEqual(size_t count, const char8_t* left, const char8_t* right)
    {
        return _isEqual(count, left, right);
    }

    bool CString::IsEqual(size_t count, const char16_t* left, const char16_t* right)
    {
        return _isEqual(count, left, right);
    }

    bool CString::IsEqual(size_t count, const char32_t* left, const char32_t* right)
    {
        return _isEqual(count, left, right);
    }

    size_t CString::ToDouble(double& target, const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return ToDoubleUnsafe(target, str);
    }

    size_t CString::ToDoubleUnsafe(double& target, const char* str) noexcept
    {
        char* end;

        target = ::strtod(str, &end);

        return end - str;
    }

    size_t CString::ToLLong(long long& target, const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return ToLLongUnsafe(target, str);
    }

    size_t CString::ToLLong(long long& target, const char* str, int radix)
    {
        ArgumentNullException::CheckNull(str, u"str");
        _checkRadix(radix);

        return ToLLongUnsafe(target, str, radix);
    }

    size_t CString::ToLLongUnsafe(long long& target, const char* str) noexcept
    {
        char* end;

        target = ::strtoll(str, &end, 10);
        
        return end - str;
    }

    size_t CString::ToLLongUnsafe(long long& target, const char* str, int radix) noexcept
    {
        char* end;

        target = ::strtoll(str, &end, radix);

        return end - str;
    }

    void CString::ToLower(char* str)
    {
        //ここでnullチェックが入る
        size_t length = Text::StringHelper::GetLength(str);

        _toLowerUncehck(length, str);
    }

    void CString::ToLower(size_t length, char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        _toLowerUncehck(length, str);
    }

    void CString::ToLower(CharString& str) noexcept
    {
        _toLowerUncehck(str.Length(), str.Data());
    }

    void CString::ToLower(wchar_t* str)
    {
        //ここでnullチェックが入る
        size_t length = Text::StringHelper::GetLength(str);

        _toLowerUncehck(length, str);
    }

    void CString::ToLower(size_t length, wchar_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        _toLowerUncehck(length, str);
    }

    void CString::ToLower(WideString& str) noexcept
    {
        _toLowerUncehck(str.Length(), str.Data());
    }

    void CString::ToUpper(char* str)
    {
        //ここでnullチェックが入る
        size_t length = Text::StringHelper::GetLength(str);

        _toUpperUncehck(length, str);
    }

    void CString::ToUpper(size_t length, char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        _toUpperUncehck(length, str);
    }

    void CString::ToUpper(CharString& str) noexcept
    {
        _toUpperUncehck(str.Length(), str.Data());
    }

    void CString::ToUpper(wchar_t* str)
    {
        //ここでnullチェックが入る
        size_t length = Text::StringHelper::GetLength(str);

        _toUpperUncehck(length, str);
    }

    void CString::ToUpper(size_t length, wchar_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        _toUpperUncehck(length, str);
    }

    void CString::ToUpper(WideString& str) noexcept
    {
        _toUpperUncehck(str.Length(), str.Data());
    }

    size_t CString::ToLong(long& target, const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return ToLongUnsafe(target, str);
    }

    size_t CString::ToLong(long& target, const char* str, int radix)
    {
        ArgumentNullException::CheckNull(str, u"str");
        _checkRadix(radix);

        return ToLongUnsafe(target, str, radix);
    }

    size_t CString::ToLongDouble(long double& target, const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return ToLongDoubleUnsafe(target, str);
    }

    size_t CString::ToLongDoubleUnsafe(long double& target, const char* str) noexcept
    {
        char* end;

        target = ::strtold(str, &end);

        return end - str;
    }

    size_t CString::ToLongUnsafe(long& target, const char* str) noexcept
    {
        char* end;

        target = ::strtol(str, &end, 10);
        
        return end - str;
    }

    size_t CString::ToLongUnsafe(long& target, const char* str, int radix) noexcept
    {
        char* end;

        target = ::strtol(str, &end, radix);

        return end - str;
    }

    CharString CString::ToMultiByte(wchar_t c)
    {
        char mb[MB_LEN_MAX + 1];

        if (::wctomb(mb, c) == EOF) [[unlikely]] throw CStdException();

        return mb;
    }

    CharString CString::ToMultiByte(const wchar_t* wcs)
    {
        ArgumentNullException::CheckNull(wcs, u"wcs");

        size_t length = ::wcstombs(nullptr, wcs, 0);

        if (length == (size_t)EOF) [[unlikely]] throw CStdException();
        char* p = CharString::AllocMemoryUnsafe(length);

        ::wcstombs(p, wcs, length);
        
        return CharString::WrapUnsafe(length, length - 1, p);
    }

    CharString CString::ToMultiByte(WideString const& wstr)
    {
        return ToMultiByte(wstr.c_str());
    }

    size_t CString::ToNumber(long& target, const char* str)
    {
        return ToLong(target, str);
    }

    size_t CString::ToNumber(unsigned long& target, const char* str)
    {
        return ToULong(target, str);
    }

    size_t CString::ToNumber(long long& target, const char* str)
    {
        return ToLLong(target, str);
    }

    size_t CString::ToNumber(unsigned long long& target, const char* str)
    {
        return ToULLong(target, str);
    }

    size_t CString::ToNumber(float& target, const char* str)
    {
        return ToSingle(target, str);
    }

    size_t CString::ToNumber(double& target, const char* str)
    {
        return ToDouble(target, str);
    }

    size_t CString::ToNumber(long double& target, const char* str)
    {
        return ToLongDouble(target, str);
    }

    size_t CString::ToNumber(long& target, const char* str, int radix)
    {
        return ToLong(target, str, radix);
    }

    size_t CString::ToNumber(unsigned long& target, const char* str, int radix)
    {
        return ToULong(target, str, radix);
    }

    size_t CString::ToNumber(long long& target, const char* str, int radix)
    {
        return ToLLong(target, str, radix); 
    }

    size_t CString::ToNumber(unsigned long long& target, const char* str, int radix)
    {
        return ToULLong(target, str, radix);
    }

    size_t CString::ToNumberUnsafe(long& target, const char* str) noexcept
    {
        return ToLongUnsafe(target, str);
    }

    size_t CString::ToNumberUnsafe(unsigned long& target, const char* str) noexcept
    {
        return ToULongUnsafe(target, str);
    }

    size_t CString::ToNumberUnsafe(long long& target, const char* str) noexcept
    {
        return ToLLongUnsafe(target, str);
    }

    size_t CString::ToNumberUnsafe(unsigned long long& target, const char* str) noexcept
    {
        return ToULLongUnsafe(target, str);
    }

    size_t CString::ToNumberUnsafe(float& target, const char* str) noexcept
    {
        return ToSingleUnsafe(target, str);
    }

    size_t CString::ToNumberUnsafe(double& target, const char* str) noexcept
    {
        return ToDoubleUnsafe(target, str);
    }

    size_t CString::ToNumberUnsafe(long double& target, const char* str) noexcept
    {
        return ToLongDoubleUnsafe(target, str);
    }

    size_t CString::ToNumberUnsafe(long& target, const char* str, int radix) noexcept
    {
        return ToLongUnsafe(target, str, radix);
    }

    size_t CString::ToNumberUnsafe(unsigned long& target, const char* str, int radix) noexcept
    {
        return ToULongUnsafe(target, str, radix);
    }

    size_t CString::ToNumberUnsafe(long long& target, const char* str, int radix) noexcept
    {
        return ToLLongUnsafe(target, str, radix); 
    }

    size_t CString::ToNumberUnsafe(unsigned long long& target, const char* str, int radix) noexcept
    {
        return ToULLongUnsafe(target, str, radix);
    }

    size_t CString::ToSingle(float& target, const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return ToSingleUnsafe(target, str);
    }

    size_t CString::ToSingleUnsafe(float& target, const char* str) noexcept
    {
        char* end;

        target = ::strtof(str, &end);

        return end - str;
    }

    size_t CString::ToULLong(unsigned long long& target, const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return ToULLongUnsafe(target, str);
    }

    size_t CString::ToULLong(unsigned long long& target, const char* str, int radix)
    {
        ArgumentNullException::CheckNull(str, u"str");
        _checkRadix(radix);

        return ToULLongUnsafe(target, str, radix);
    }

    size_t CString::ToULLongUnsafe(unsigned long long& target, const char* str) noexcept
    {
        char* end;

        target = ::strtoull(str, &end, 10);
        
        return end - str;
    }

    size_t CString::ToULLongUnsafe(unsigned long long& target, const char* str, int radix) noexcept
    {
        char* end;

        target = ::strtoull(str, &end, radix);

        return end - str;
    }

    size_t CString::ToULong(unsigned long& target, const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return ToULongUnsafe(target, str);
    }

    size_t CString::ToULong(unsigned long& target, const char* str, int radix)
    {
        ArgumentNullException::CheckNull(str, u"str");
        _checkRadix(radix);

        return ToULongUnsafe(target, str, radix);
    }

    size_t CString::ToULongUnsafe(unsigned long& target, const char* str) noexcept
    {
        char* end;

        target = ::strtoul(str, &end, 10);
        
        return end - str;
    }

    size_t CString::ToULongUnsafe(unsigned long& target, const char* str, int radix) noexcept
    {
        char* end;

        target = ::strtoul(str, &end, radix);

        return end - str;
    }

#ifdef KONGKONG_ENV_WINDOWS

    std::u8string CString::ToUtf8(char16_t c)
    {
        std::u8string u8str;

        _c16rToMultiByte(u8str, c);

        return u8str;
    }

    std::u8string CString::ToUtf8(const char16_t* c16s)
    {
        ArgumentNullException::CheckNull(c16s, u"c16s");

        const char16_t* p = c16s;
        std::u8string u8str;

        while (*p != u'\0') {
            _c16rToMultiByte(u8str, *p);
            ++p;
        }

        return u8str;
    }

    std::u8string CString::ToUtf8(size_t length, const char16_t* c16s)
    {
        ArgumentNullException::CheckNull(c16s, u"c16s");

        const char16_t* p = c16s;
        const char16_t* end = p + length;
        std::u8string u8str;

        while (p != end) {
            _c16rToMultiByte(u8str, *p);
            ++p;
        }

        return u8str;
    }

    std::u8string CString::ToUtf8(std::u16string const& c16str)
    {
        std::u8string u8str;

        for (char16_t c : c16str) {
            _c16rToMultiByte(u8str, c);
        }

        return u8str;
    }
#endif

    WideString CString::ToWide(const char* mbs)
    {
        ArgumentNullException::CheckNull(mbs, u"mbs");

        size_t length = ::mbstowcs(nullptr, mbs, 0);

        if (length == (size_t)EOF) [[unlikely]] throw CStdException();

        wchar_t* p = WideString::AllocMemoryUnsafe(length);

        ::mbstowcs(p, mbs, length);

        return WideString::WrapUnsafe(length, length - 1, p);
    }

    WideString CString::ToWide(CharString const& str)
    {
        return ToWide(str.c_str());
    }

    wchar_t CString::ToWideChar(const char* mbc)
    {
        ArgumentNullException::CheckNull(mbc, u"mbc");

        wchar_t wc;

        if (::mbtowc(&wc, mbc, MB_LEN_MAX) == EOF) [[unlikely]] throw CStdException();

        return wc;
    }

    wchar_t CString::ToWideChar(CharString const& mbc)
    {
        return ToWideChar(mbc.c_str());
    }

    template <class TC>
    std::strong_ordering CString::_compare(const TC* left, const TC* right)
    {
        ArgumentNullException::CheckNull(left, u"left");
        ArgumentNullException::CheckNull(right, u"right");

        constexpr TC nullChar = (TC)0;

        while (true) {
            if (*left == *right) {
                if (*left == nullChar) return std::strong_ordering::equal;
                ++left;
                ++right;
                continue;
            }

            if (*left < *right) return std::strong_ordering::less;
            if (*left > *right) return std::strong_ordering::greater;

            ++left;
            ++right;
        }

    }

    template <class TC>
    std::partial_ordering CString::_compare(size_t count, const TC* left, const TC* right)
    {
        ArgumentNullException::CheckNull(left, u"left");
        ArgumentNullException::CheckNull(right, u"right");

        constexpr TC nullChar = (TC)0;

        for (size_t i = 0; i < count; i++) {
            if (left[i] < right[i]) return std::partial_ordering::less;
            if (left[i] > right[i]) return std::partial_ordering::greater;
        }

        return std::partial_ordering::equivalent;
    }

#ifdef KONGKONG_ENV_WINDOWS
    void CString::_c16rToMultiByte(std::u8string& u8str, char16_t c)
    {
        ::mbstate_t state;
        char mbs[MB_LEN_MAX + 1];
        size_t ret;

        ret = ::c16rtomb(mbs, c, &state);

        if (ret == (size_t)EOF) [[unlikely]] throw CStdException();

        mbs[ret] = '\0';

        u8str.append((char8_t*)mbs);
    }
#endif

    void CString::_checkRadix(int radix)
    {
        if (radix < 0 || radix == 1 || radix > 36) [[unlikely]] throw InvalidArgumentException(u"基数が無効です");
    }

    template <class TC>
    TC* CString::_dump(const TC* str)
    {
        size_t count = Text::StringHelper::GetLength(str) + 1;

        TC* dump = (TC*)::malloc(count * sizeof(TC));

        MemoryAllocationException::CheckNull(dump);

        for (size_t i = 0; i < count; i++) {
            dump[i] = str[i];
        }

        return dump;
    }

    template <class TC>
    bool CString::_isEqual(const TC* left, const TC* right)
    {
        ArgumentNullException::CheckNull(left, u"left");
        ArgumentNullException::CheckNull(right, u"right");

        constexpr TC nullChar = (TC)0;

        while (true) {
            if (*left != *right) return false;

            //この時点で
            //*left == *right
            if (*left == nullChar) return true;

            ++left;
            ++right;
        }
    }

    template <class TC>
    bool CString::_isEqual(size_t count, const TC* left, const TC* right)
    {
        for (size_t i = 0; i < count; i++) {
            if (left[i] != right[i]) return false;
        }

        return true;
    }

    void CString::_toLowerUncehck(size_t length, char* str)
    {
        char* p = str;
        char* end = str + length;

        while (p != end) {
            *p = ::tolower(*p);
            ++p;
        }
    }

    void CString::_toLowerUncehck(size_t length, wchar_t* str)
    {
        wchar_t* p = str;
        wchar_t* end = str + length;

        while (p != end) {
            *p = ::towlower(*p);
            ++p;
        }
    }

    void CString::_toUpperUncehck(size_t length, char* str)
    {
        char* p = str;
        char* end = str + length;

        while (p != end) {
            *p = ::toupper(*p);
            ++p;
        }
    }

    void CString::_toUpperUncehck(size_t length, wchar_t* str)
    {
        wchar_t* p = str;
        wchar_t* end = str + length;

        while (p != end) {
            *p = ::towupper(*p);
            ++p;
        }
    }
}
