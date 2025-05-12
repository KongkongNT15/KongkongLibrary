//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    String StringHelper::ToLower(const char16_t* wcs)
    {
        String str = String(wcs, true);

        ::CharLowerW((wchar_t*)str.Data());

        return str;
    }

    String StringHelper::ToLower(String const& right)
    {
        String str = String(right, true);

        ::CharLowerW((wchar_t*)str.Data());

        return str;
    }

    String StringHelper::ToString(const char* ansiStr)
    {
        return ToString(-1, ansiStr, CodePage::DefaultANSI);
    }

    String StringHelper::ToString(std::string const& ansiStr)
    {
        return ToString((ssize_t)ansiStr.size(), ansiStr.c_str());
    }

    String StringHelper::ToString(const char8_t* u8Str) 
    {
        return ToString(-1, (const char*)u8Str, CodePage::Utf8);
    }

    String StringHelper::ToString(std::u8string const& u8Str) 
    {
        return ToString((ssize_t)u8Str.size(), (const char*)u8Str.c_str(), CodePage::Utf8);
    }

    String StringHelper::ToString(ssize_t length, const char* ansiStr)
    {
        return ToString(length, ansiStr, CodePage::DefaultANSI);
    }

    String StringHelper::ToString(ssize_t length, const char8_t* u8Str)
    {
        return ToString(length, (const char*)u8Str, CodePage::Utf8);
    }

    String StringHelper::ToString(const char* str, CodePage codePage) 
    {
        return ToString(-1, str, codePage);
    }

    String StringHelper::ToString(ssize_t length, const char* str, CodePage codePage)
    {
        if (length < 1) {
            if (length == -1) {
                length = std::strlen(str);
            }
            throw ArgumentOutOfRangeException(EXCEPTION_MESSAGE);
        }

        char16_t* wcs = String::AllocMemoryUnsafe(length);
        ssize_t writtenLength;
        if ((writtenLength = ::MultiByteToWideChar((UINT)codePage, 0, str, (int)length, (wchar_t*)wcs, (int)length)) == 0) throw HResultException();

        wcs[writtenLength] = u'\0';

        return String::Wrap(length, wcs);
    }

    String StringHelper::ToUpper(const char16_t* wcs)
    {
        String str = String(wcs, true);

        ::CharUpperW((wchar_t*)str.Data());

        return str;
    }

    String StringHelper::ToUpper(String const& right)
    {
        String str = String(right, true);

        ::CharUpperW((wchar_t*)str.Data());

        return str;
    }
}
