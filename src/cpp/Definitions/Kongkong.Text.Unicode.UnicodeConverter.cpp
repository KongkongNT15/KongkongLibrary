//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Unicode
{
    ssize_t UnicodeConverter::GetCharCount(const char32_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return GetCharCountUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    ssize_t UnicodeConverter::GetCharCount(ssize_t length, const char32_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return GetCharCountUnsafe(length, str);
    }

    ssize_t UnicodeConverter::GetCharCount(Utf32String const& str)
    {
        return GetCharCountUnsafe(str.Length(), str.c_str());
    }

    ssize_t UnicodeConverter::GetCharCount(Utf32StringView const& str)
    {
        return GetCharCountUnsafe(str.Length(), str.c_str());
    }

    ssize_t UnicodeConverter::GetCharCount(Collections::Array<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetCharCountUnsafe(ref.Length(), ref.Data());
    }

    ssize_t UnicodeConverter::GetCharCount(Collections::ArrayList<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetCharCountUnsafe(ref.Length(), ref.Data());
    }

    ssize_t UnicodeConverter::GetCharCount(Collections::Turbo::FastArray<char32_t> const& chars)
    {
        return GetCharCountUnsafe(chars.Length(), chars.Data());
    }

    ssize_t UnicodeConverter::GetCharCount(Collections::Turbo::FastArrayList<char32_t> const& chars)
    {
        return GetCharCountUnsafe(chars.Length(), chars.Data());
    }

    ssize_t UnicodeConverter::GetCharCountUnsafe(const char32_t* str)
    {
        return GetCharCountUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    ssize_t UnicodeConverter::GetCharCountUnsafe(ssize_t length, const char32_t* str)
    {
        ssize_t surrogatePairCount = 0;

        const char32_t* p = str;
        const char32_t* e = p + length;
        char32_t c;

        while (p != e) {
            c = *p;
            if (!UnicodeTraits::IsValidCodePoint(c)) [[unlikely]] throw InvalidCodePointException();
            if (UnicodeTraits::IsSurrogatePairRequired(c)) ++surrogatePairCount;

            ++p;
        }

        return length + surrogatePairCount;
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(const char16_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return GetUtf8CharCountUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(const char32_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return GetUtf8CharCountUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(ssize_t length, const char16_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return GetUtf8CharCountUnsafe(length, str);
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(ssize_t length, const char32_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return GetUtf8CharCountUnsafe(length, str);
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(String const& str)
    {
        return GetUtf8CharCountUnsafe(str.Length(), str.c_str());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Utf32String const& str)
    {
        return GetUtf8CharCountUnsafe(str.Length(), str.c_str());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(StringView const& str)
    {
        return GetUtf8CharCountUnsafe(str.Length(), str.c_str());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Utf32StringView const& str)
    {
        return GetUtf8CharCountUnsafe(str.Length(), str.c_str());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Collections::Array<char16_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetUtf8CharCountUnsafe(ref.Length(), ref.Data());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Collections::Array<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetUtf8CharCountUnsafe(ref.Length(), ref.Data());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Collections::ArrayList<char16_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetUtf8CharCountUnsafe(ref.Length(), ref.Data());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Collections::ArrayList<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetUtf8CharCountUnsafe(ref.Length(), ref.Data());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Collections::Turbo::FastArray<char16_t> const& chars)
    {
        return GetUtf8CharCountUnsafe(chars.Length(), chars.Data());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Collections::Turbo::FastArray<char32_t> const& chars)
    {
        return GetUtf8CharCountUnsafe(chars.Length(), chars.Data());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Collections::Turbo::FastArrayList<char16_t> const& chars)
    {
        return GetUtf8CharCountUnsafe(chars.Length(), chars.Data());
    }

    ssize_t UnicodeConverter::GetUtf8CharCount(Collections::Turbo::FastArrayList<char32_t> const& chars)
    {
        return GetUtf8CharCountUnsafe(chars.Length(), chars.Data());
    }

    ssize_t UnicodeConverter::GetUtf8CharCountUnsafe(const char16_t* str)
    {
        return GetUtf8CharCountUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    ssize_t UnicodeConverter::GetUtf8CharCountUnsafe(const char32_t* str)
    {
        return GetUtf8CharCountUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    ssize_t UnicodeConverter::GetUtf8CharCountUnsafe(ssize_t length, const char16_t* str)
    {
        ssize_t result = 0;

        const char16_t* p = str;
        const char16_t* e = p + length;
        char16_t c;

        for (; p != e; ++p) {
            c = *p;
            
            if (!UnicodeTraits::IsValidCodePoint(c)) {
                if (UnicodeTraits::IsHighSurrogate(c)) {
                    char16_t c1;
                    ++p;
    
                    if (p == e) [[unlikely]] throw InvalidCodePointException(u"下位サロゲートが見つかりませんでした");
    
                    c1 = *p;

                    if (!UnicodeTraits::IsLowSurrogate(c1)) [[unlikely]] throw InvalidCodePointException();
    
                    result += Utf8Char::GetMultiByteCharLengthUnsafe(SurrogatePair::ToUnicodeUnsafe(c, c1));
    
                    continue;
                }

                throw InvalidCodePointException();
            }

            result += Utf8Char::GetMultiByteCharLengthUnsafe(c);
        }

        return result;
    }

    ssize_t UnicodeConverter::GetUtf8CharCountUnsafe(ssize_t length, const char32_t* str)
    {
        ssize_t result = 0;

        const char32_t* p = str;
        const char32_t* e = p + length;
        char32_t c;

        while (p != e) {
            c = *p;

            if (!UnicodeTraits::IsValidCodePoint(c)) [[unlikely]] throw InvalidCodePointException();

            result += Utf8Char::GetMultiByteCharLengthUnsafe(c);

            ++p;
        }

        return result;
    }
    
    Threading::Generator<char16_t> UnicodeConverter::IterateChars(const char32_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return IterateCharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateChars(ssize_t length, const char32_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return IterateCharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateChars(Utf32String const& str)
    {
        return IterateCharsUnsafe(str.Length(), str.c_str());
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateChars(Utf32StringView const& str)
    {
        return IterateCharsUnsafe(str.Length(), str.c_str());
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateCharsUnsafe(const char32_t* str)
    {
        return IterateCharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateChars(Collections::Array<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return IterateCharsUnsafe(ref.Length(), ref.Data());
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateChars(Collections::ArrayList<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return IterateCharsUnsafe(ref.Length(), ref.Data());
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateChars(Collections::Turbo::FastArray<char32_t> const& chars)
    {
        return IterateCharsUnsafe(chars.Length(), chars.Data());
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateChars(Collections::Turbo::FastArrayList<char32_t> const& chars)
    {
        return IterateCharsUnsafe(chars.Length(), chars.Data());
    }

    Threading::Generator<char16_t> UnicodeConverter::IterateCharsUnsafe(ssize_t length, const char32_t* str)
    {
        const char32_t* p = str;
        const char32_t* e = p + length;
        char32_t c;

        for (; p != e; ++p) {
            c = *p;
            if (!UnicodeTraits::IsValidCodePoint(c)) [[unlikely]] throw InvalidCodePointException(u"無効なコードポイントが見つかりました");

            if (UnicodeTraits::IsSurrogatePairRequired(c)) {
                SurrogatePair pair = SurrogatePair::CreateUnsafe(c);

                co_yield pair.HighSurrogate();
                co_yield pair.LowSurrogate();

                continue;
            }

            co_yield (char16_t)c;
        }

        co_return;
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(const char16_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return IterateUtf8CharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(const char32_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return IterateUtf8CharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(ssize_t length, const char16_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return IterateUtf8CharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(ssize_t length, const char32_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return IterateUtf8CharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(String const& str)
    {
        return IterateUtf8CharsUnsafe(str.Length(), str.c_str());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Utf32String const& str)
    {
        return IterateUtf8CharsUnsafe(str.Length(), str.c_str());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(StringView const& str)
    {
        return IterateUtf8CharsUnsafe(str.Length(), str.c_str());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Utf32StringView const& str)
    {
        return IterateUtf8CharsUnsafe(str.Length(), str.c_str());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8CharsUnsafe(const char16_t* str)
    {
        return IterateUtf8CharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8CharsUnsafe(const char32_t* str)
    {
        return IterateUtf8CharsUnsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Collections::Array<char16_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return IterateUtf8CharsUnsafe(ref.Length(), ref.Data());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Collections::Array<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return IterateUtf8CharsUnsafe(ref.Length(), ref.Data());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Collections::ArrayList<char16_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return IterateUtf8CharsUnsafe(ref.Length(), ref.Data());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Collections::ArrayList<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return IterateUtf8CharsUnsafe(ref.Length(), ref.Data());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Collections::Turbo::FastArray<char16_t> const& chars)
    {
        return IterateUtf8CharsUnsafe(chars.Length(), chars.Data());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Collections::Turbo::FastArray<char32_t> const& chars)
    {
        return IterateUtf8CharsUnsafe(chars.Length(), chars.Data());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Collections::Turbo::FastArrayList<char16_t> const& chars)
    {
        return IterateUtf8CharsUnsafe(chars.Length(), chars.Data());
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8Chars(Collections::Turbo::FastArrayList<char32_t> const& chars)
    {
        return IterateUtf8CharsUnsafe(chars.Length(), chars.Data());
    }
    
    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8CharsUnsafe(ssize_t length, const char16_t* str)
    {
        const char16_t* p = str;
        const char16_t* e = p + length;
        char16_t c;

        for (; p != e; ++p) {
            c = *p;
            if (!UnicodeTraits::IsValidCodePoint(c)) {
                if (UnicodeTraits::IsHighSurrogate(c)) {
                    ++p;
    
                    if (p == e) [[unlikely]] throw InvalidCodePointException(u"下位サロゲートが見つかりませんでした");
    
                    char16_t c1 = *p;
    
                    if (!UnicodeTraits::IsLowSurrogate(c1)) [[unlikely]] throw InvalidCodePointException();
    
                    for (char8_t c8 : Utf8Char::CreateUnsafe((SurrogatePair::ToUnicodeUnsafe(c, c1)))) {
                        co_yield c8;
                    }
    
                    continue;
                }

                throw InvalidCodePointException();
            }

            for (char8_t c8 : Utf8Char::CreateUnsafe(c)) {
                co_yield c8;
            }
        }

        co_return;
    }

    Threading::Generator<char8_t> UnicodeConverter::IterateUtf8CharsUnsafe(ssize_t length, const char32_t* str)
    {
        const char32_t* p = str;
        const char32_t* e = p + length;

        for (; p != e; ++p) {
            for (char8_t c : Utf8Char(*p)) {
                co_yield c;
            }
        }

        co_return;
    }

    Utf8String UnicodeConverter::ToUtf8(const char16_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return ToUtf8Unsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Utf8String UnicodeConverter::ToUtf8(const char32_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return ToUtf8Unsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Utf8String UnicodeConverter::ToUtf8(ssize_t length, const char16_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return ToUtf8Unsafe(length, str);
    }

    Utf8String UnicodeConverter::ToUtf8(ssize_t length, const char32_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return ToUtf8Unsafe(length, str);
    }

    Utf8String UnicodeConverter::ToUtf8(Utf32String const& str)
    {
        return ToUtf8Unsafe(str.Length(), str.c_str());
    }

    Utf8String UnicodeConverter::ToUtf8(String const& str)
    {
        return ToUtf8Unsafe(str.Length(), str.c_str());
    }

    Utf8String UnicodeConverter::ToUtf8(StringView const& str)
    {
        return ToUtf8Unsafe(str.Length(), str.c_str());
    }

    Utf8String UnicodeConverter::ToUtf8(Utf32StringView const& str)
    {
        return ToUtf8Unsafe(str.Length(), str.c_str());
    }

    Utf8String UnicodeConverter::ToUtf8(Collections::Array<char16_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return ToUtf8Unsafe(ref.Length(), ref.Data());
    }

    Utf8String UnicodeConverter::ToUtf8(Collections::Array<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return ToUtf8Unsafe(ref.Length(), ref.Data());
    }

    Utf8String UnicodeConverter::ToUtf8(Collections::ArrayList<char16_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return ToUtf8Unsafe(ref.Length(), ref.Data());
    }

    Utf8String UnicodeConverter::ToUtf8(Collections::ArrayList<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return ToUtf8Unsafe(ref.Length(), ref.Data());
    }

    Utf8String UnicodeConverter::ToUtf8(Collections::Turbo::FastArray<char16_t> const& chars)
    {
        return ToUtf8Unsafe(chars.Length(), chars.Data());
    }

    Utf8String UnicodeConverter::ToUtf8(Collections::Turbo::FastArray<char32_t> const& chars)
    {
        return ToUtf8Unsafe(chars.Length(), chars.Data());
    }

    Utf8String UnicodeConverter::ToUtf8(Collections::Turbo::FastArrayList<char16_t> const& chars)
    {
        return ToUtf8Unsafe(chars.Length(), chars.Data());
    }

    Utf8String UnicodeConverter::ToUtf8(Collections::Turbo::FastArrayList<char32_t> const& chars)
    {
        return ToUtf8Unsafe(chars.Length(), chars.Data());
    }

    Utf8String UnicodeConverter::ToUtf8Unsafe(const char16_t* str)
    {
        return ToUtf8Unsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Utf8String UnicodeConverter::ToUtf8Unsafe(const char32_t* str)
    {
        return ToUtf8Unsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    Utf8String UnicodeConverter::ToUtf8Unsafe(ssize_t length, const char16_t* str)
    {
        ssize_t u8Length = GetUtf8CharCountUnsafe(length, str);

        char8_t* p = Utf8String::AllocMemoryUnsafe(u8Length + 1);

        char8_t* itr = p;
        char8_t* e = p + u8Length;
        const char16_t* itr16 = str;
        char16_t c;

        for (; itr != e; ++itr16) {
            c = *itr16;
            if (UnicodeTraits::IsHighSurrogate(c)) {
                ++itr16;
                for (char8_t c1 : Utf8Char::CreateUnsafe(SurrogatePair::ToUnicodeUnsafe(c, *itr16))) {
                    *itr = c1;
                    ++itr;
                }

                continue;
            }

            for (char8_t c1 : Utf8Char::CreateUnsafe(c)) {
                *itr = c1;
                ++itr;
            }
        }

        *e = u8'\0';

        return Utf8String::WrapUnsafe(u8Length + 1, u8Length, p);
    }

    Utf8String UnicodeConverter::ToUtf8Unsafe(ssize_t length, const char32_t* str)
    {
        ssize_t u8Length = GetUtf8CharCountUnsafe(length, str);

        char8_t* p = Utf8String::AllocMemoryUnsafe(u8Length + 1);

        char8_t* itr = p;
        char8_t* e = p + u8Length;
        const char32_t* itr32 = str;

        while (itr != e) {
            for (char8_t c : Utf8Char::CreateUnsafe(*itr32)) {
                *itr = c;
                ++itr;
            }

            ++itr32;
        }

        *e = u8'\0';

        return Utf8String::WrapUnsafe(u8Length + 1, u8Length, p);
    }

    String UnicodeConverter::ToUtf16(const char32_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");
        return ToUtf16Unsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    String UnicodeConverter::ToUtf16(ssize_t length, const char32_t* str)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return ToUtf16Unsafe(length, str);
    }

    String UnicodeConverter::ToUtf16(Utf32String const& str)
    {
        return ToUtf16Unsafe(str.Length(), str.c_str());
    }

    String UnicodeConverter::ToUtf16(Utf32StringView const& str)
    {
        return ToUtf16Unsafe(str.Length(), str.c_str());
    }

    String UnicodeConverter::ToUtf16(Collections::Array<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return ToUtf16Unsafe(ref.Length(), ref.Data());
    }

    String UnicodeConverter::ToUtf16(Collections::ArrayList<char32_t> const& chars)
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return ToUtf16Unsafe(ref.Length(), ref.Data());
    }

    String UnicodeConverter::ToUtf16(Collections::Turbo::FastArray<char32_t> const& chars)
    {
        return ToUtf16Unsafe(chars.Length(), chars.Data());
    }

    String UnicodeConverter::ToUtf16(Collections::Turbo::FastArrayList<char32_t> const& chars)
    {
        return ToUtf16Unsafe(chars.Length(), chars.Data());
    }

    String UnicodeConverter::ToUtf16Unsafe(const char32_t* str)
    {
        return ToUtf16Unsafe(StringHelper::GetLengthUnsafe(str), str);
    }

    String UnicodeConverter::ToUtf16Unsafe(ssize_t length, const char32_t* str)
    {
        ssize_t u16Length = GetCharCountUnsafe(length, str);
        char16_t* p = String::AllocMemoryUnsafe(u16Length + 1);

        char16_t* itr = p;
        char16_t* e = p + u16Length;
        const char32_t* itr32 = str;

        if (u16Length == length) {
            while (itr != e) {
                *itr = (char16_t)*itr32;

                ++itr;
                ++itr32;
            }
        }
        else {
            char32_t c;
            while (itr != e) {
                c = *itr32;
                if (UnicodeTraits::IsSurrogatePairRequired(c)) {
                    SurrogatePair pair = SurrogatePair::CreateUnsafe(c);
                    *itr = pair.HighSurrogate();
                    ++itr;
                    *itr = pair.LowSurrogate();
                }
                else {
                    *itr = (char16_t)c;
                }

                ++itr;
                ++itr32;
            }
        }

        *e = u'\0';

        return String::WrapUnsafe(u16Length + 1, u16Length, p);
    }

}