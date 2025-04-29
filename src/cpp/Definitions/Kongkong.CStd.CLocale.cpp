//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    char* CLocale::All() noexcept
    {
        return GetLocaleUnsafe(CLocaleCategory::All);
    }

    char* CLocale::All(const char* locale)
    {
        return SetLocale(CLocaleCategory::All, locale);
    }

    char* CLocale::All(CharString const& locale)
    {
        return SetLocale(CLocaleCategory::All, locale.c_str());
    }

    char* CLocale::Collate() noexcept
    {
        return GetLocaleUnsafe(CLocaleCategory::Collate); 
    }

    char* CLocale::Collate(const char* locale)
    {
        return SetLocale(CLocaleCategory::Collate, locale);
    }

    char* CLocale::Collate(CharString const& locale)
    {
        return SetLocale(CLocaleCategory::Collate, locale.c_str());
    }

    char* CLocale::CharType() noexcept
    {
        return GetLocale(CLocaleCategory::CharType); 
    }

    char* CLocale::CharType(const char* locale)
    {
        return SetLocale(CLocaleCategory::CharType, locale);
    }

    char* CLocale::CharType(CharString const& locale)
    {
        return SetLocale(CLocaleCategory::CharType, locale.c_str());
    }

    char* CLocale::Monetary() noexcept
    {
        return GetLocale(CLocaleCategory::Monetary);
    }

    char* CLocale::Monetary(const char* locale)
    {
        return SetLocale(CLocaleCategory::Monetary, locale);
    }

    char* CLocale::Monetary(CharString const& locale)
    {
        return SetLocale(CLocaleCategory::Monetary, locale.c_str());
    }

    char* CLocale::Numeric() noexcept
    {
        return GetLocale(CLocaleCategory::Numeric);
    }

    char* CLocale::Numeric(const char* locale)
    {
        return SetLocale(CLocaleCategory::Numeric, locale);
    }

    char* CLocale::Numeric(CharString const& locale)
    {
        return SetLocale(CLocaleCategory::Numeric, locale.c_str());
    }

    char* CLocale::Time() noexcept
    {
        return GetLocale(CLocaleCategory::Time);
    }

    char* CLocale::Time(const char* locale)
    {
        return SetLocale(CLocaleCategory::Time, locale);
    }

    char* CLocale::Time(CharString const& locale)
    {
        return SetLocale(CLocaleCategory::Time, locale.c_str());
    }

    char* CLocale::GetLocale(CLocaleCategory category)
    {
        char* locale = GetLocaleUnsafe(category);
        if (locale == nullptr) [[unlikely]] throw CStdException();

        return locale;
    }

    char* CLocale::GetLocaleUnsafe(CLocaleCategory category) noexcept
    {
        return ::setlocale((int)category, nullptr);
    }

    char* CLocale::SetLocale(CLocaleCategory category, const char* locale)
    {
        char* ret = ::setlocale((int)category, locale);
        if (ret == nullptr) [[unlikely]] throw InvalidOperationException(u"ロケールが無効です");

        return ret;
    }

    char* CLocale::SetLocale(CLocaleCategory category, CharString const& locale)
    {
        return SetLocale(category, locale.c_str());
    }

}
