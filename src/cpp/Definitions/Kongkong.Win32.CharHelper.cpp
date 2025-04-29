//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32
{
    bool CharHelper::IsAlpha(char16_t c) noexcept
    {
        return (bool)::IsCharAlphaW(c);
    }

    bool CharHelper::IsLower(char16_t c) noexcept
    {
        return (bool)::IsCharLowerW(c);
    }

    bool CharHelper::IsUpper(char16_t c) noexcept
    {
        return (bool)::IsCharUpperW(c);
    }

    char16_t CharHelper::ToLower(char16_t c) noexcept
    {
        char16_t* p = (char16_t*)::CharLowerW((wchar_t*)&c);

        return *p;
    }

    char16_t CharHelper::ToUpper(char16_t c) noexcept
    {
        char16_t* p = (char16_t*)::CharUpperW((wchar_t*)&c);

        return *p;
    }
}
