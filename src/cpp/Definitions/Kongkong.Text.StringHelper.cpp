//このcppファイルをコンパイルに含めないでください

#define CHECK_ERROR_MESSAGE u"文字列が空でした"

namespace KONGKONG_NAMESPACE::Text
{
    void StringHelper::CheckEmpty(const char16_t* p)
    {
        ArgumentNullException::CheckNull(p, u"p");
        CheckEmptyUnsafe(p);
    }

    void StringHelper::CheckEmpty(String const& str)
    {
        if (str.Length() == 0) [[unlikely]] throw InvalidArgumentException(CHECK_ERROR_MESSAGE);
    }

    void StringHelper::CheckEmpty(StringView const& str)
    {
        if (str.Length() == 0) [[unlikely]] throw InvalidArgumentException(CHECK_ERROR_MESSAGE);
    }

    void StringHelper::CheckEmptyUnsafe(const char16_t* p)
    {
        if (*p == u'\0') [[unlikely]] throw InvalidArgumentException(CHECK_ERROR_MESSAGE);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const char* source, char target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _containsUnsafe(lengthSource, source, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const wchar_t* source, wchar_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _containsUnsafe(lengthSource, source, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const char8_t* source, char8_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _containsUnsafe(lengthSource, source, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const char16_t* source, char16_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _containsUnsafe(lengthSource, source, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const char32_t* source, char32_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _containsUnsafe(lengthSource, source, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const char* source, ssize_t lengthTarget, const char* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _containsUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const wchar_t* source, ssize_t lengthTarget, const wchar_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _containsUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const char8_t* source, ssize_t lengthTarget, const char8_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _containsUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const char16_t* source, ssize_t lengthTarget, const char16_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _containsUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::Contains(ssize_t lengthSource, const char32_t* source, ssize_t lengthTarget, const char32_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _containsUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const char* source, char target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _endsWithUnsafe(lengthSource, source, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const wchar_t* source, wchar_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _endsWithUnsafe(lengthSource, source, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const char8_t* source, char8_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _endsWithUnsafe(lengthSource, source, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const char16_t* source, char16_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _endsWithUnsafe(lengthSource, source, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const char32_t* source, char32_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _endsWithUnsafe(lengthSource, source, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const char* source, ssize_t lengthTarget, const char* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _endsWithUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const wchar_t* source, ssize_t lengthTarget, const wchar_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _endsWithUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const char8_t* source, ssize_t lengthTarget, const char8_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _endsWithUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const char16_t* source, ssize_t lengthTarget, const char16_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _endsWithUnsafe(lengthSource, source, lengthTarget, target);
    }

    bool StringHelper::EndsWith(ssize_t lengthSource, const char32_t* source, ssize_t lengthTarget, const char32_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _endsWithUnsafe(lengthSource, source, lengthTarget, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const char* source, char target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _findUnsafe(lengthSource, source, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const wchar_t* source, wchar_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");

        return _findUnsafe(lengthSource, source, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const char8_t* source, char8_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");

        return _findUnsafe(lengthSource, source, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const char16_t* source, char16_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _findUnsafe(lengthSource, source, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const char32_t* source, char32_t target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _findUnsafe(lengthSource, source, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const char* source, ssize_t lengthTarget, const char* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _findUnsafe(lengthSource, source, lengthTarget, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const wchar_t* source, ssize_t lengthTarget, const wchar_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _findUnsafe(lengthSource, source, lengthTarget, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const char8_t* source, ssize_t lengthTarget, const char8_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _findUnsafe(lengthSource, source, lengthTarget, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const char16_t* source, ssize_t lengthTarget, const char16_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _findUnsafe(lengthSource, source, lengthTarget, target);
    }

    ssize_t StringHelper::Find(ssize_t lengthSource, const char32_t* source, ssize_t lengthTarget, const char32_t* target)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(target, u"target");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(lengthTarget);

        return _findUnsafe(lengthSource, source, lengthTarget, target);
    }

    ssize_t StringHelper::GetLength(const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return _getLengthUnsafe(str);
    }

    ssize_t StringHelper::GetLength(const wchar_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return _getLengthUnsafe(str);
    }

    ssize_t StringHelper::GetLength(const char8_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return _getLengthUnsafe(str);
    }

    ssize_t StringHelper::GetLength(const char16_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return _getLengthUnsafe(str);
    }

    ssize_t StringHelper::GetLength(const char32_t* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return _getLengthUnsafe(str);
    }

    ssize_t StringHelper::GetMultiByteLengthUnsafe(const char8_t* str) noexcept
    {
        const char8_t* p = str;

        while (*p != u8'\0') {
            p += (std::underlying_type_t<Utf8CharAttribute>)(CharAttribute(*p));
        }

        return p - str;
    }

    ssize_t StringHelper::GetMultiByteLengthUnsafe(const char16_t* str) noexcept
    {
        const char16_t* p = str;

        while (*p) {
            p += (u'\xD800' <= *p && *p <= u'\xDBFF') ? 2 : 1;
        }

        return str - p;
    }

    ssize_t StringHelper::GetMultiByteLengthUnsafe(const char32_t* str) noexcept
    {
        return _getLengthUnsafe(str);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const char* source, char prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _startsWithUnsafe(lengthSource, source, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const wchar_t* source, wchar_t prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _startsWithUnsafe(lengthSource, source, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const char8_t* source, char8_t prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _startsWithUnsafe(lengthSource, source, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const char16_t* source, char16_t prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _startsWithUnsafe(lengthSource, source, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const char32_t* source, char32_t prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);

        return _startsWithUnsafe(lengthSource, source, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const char* source, ssize_t prefixLength, const char* prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(prefix, u"prefix");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(prefixLength);

        return _startsWithUnsafe(lengthSource, source, prefixLength, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const wchar_t* source, ssize_t prefixLength, const wchar_t* prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(prefix, u"prefix");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(prefixLength);

        return _startsWithUnsafe(lengthSource, source, prefixLength, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const char8_t* source, ssize_t prefixLength, const char8_t* prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(prefix, u"prefix");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(prefixLength);

        return _startsWithUnsafe(lengthSource, source, prefixLength, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const char16_t* source, ssize_t prefixLength, const char16_t* prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(prefix, u"prefix");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(prefixLength);

        return _startsWithUnsafe(lengthSource, source, prefixLength, prefix);
    }

    bool StringHelper::StartsWith(ssize_t lengthSource, const char32_t* source, ssize_t prefixLength, const char32_t* prefix)
    {
        ArgumentNullException::CheckNull(source, u"source");
        ArgumentNullException::CheckNull(prefix, u"prefix");
        Collections::CollectionHelper::CheckMinusLength(lengthSource);
        Collections::CollectionHelper::CheckMinusLength(prefixLength);

        return _startsWithUnsafe(lengthSource, source, prefixLength, prefix);
    }

    CharString StringHelper::ToCharStringUnsafe(ssize_t length, const char* str)
    {
        return CharString::FromPointerUnsafe(length, str, true);
    }

    CharString StringHelper::ToCharStringUnsafe(ssize_t length, const wchar_t* str)
    {
        if (length == 0) [[unlikely]] return CharString(true);

#if KONGKONG_ENV_WINDOWS
        int capacity = ::WideCharToMultiByte(CP_ACP, 0, str, (int)length, nullptr, 0, nullptr, nullptr);

        char* p = CharString::AllocMemoryUnsafe(capacity);

        ::WideCharToMultiByte(CP_ACP, 0, str, (int)length, p, capacity, nullptr, nullptr);

        return CharString::WrapUnsafe(capacity, capacity - 1, p);
#else
        ::std::filesystem::path p = str;
        auto stdString = p.generic_string();

        return CharString::FromPointerUnsafe(stdString.size(), stdString.c_str(), true);
#if 0
        size_t capacity;
        ::wcstombs_s(&capacity, nullptr, 0, str, length);

        char* p = CharString::AllocMemoryUnsafe(capacity);

        ::wcstombs_s(nullptr, p, capacity, str, length);

        return CharString::WrapUnsafe(capacity, capacity - 1, p);
#endif
#endif
    }

    CharString StringHelper::ToCharStringUnsafe(ssize_t length, const char8_t* str)
    {
        ::std::filesystem::path p = str;

        ::std::string str1 = p.generic_string();

        return CharString::FromPointerUnsafe(str1.size(), str1.c_str());
    }

    CharString StringHelper::ToCharStringUnsafe(ssize_t length, const char16_t* str)
    {
#if KONGKONG_ENV_WINDOWS
        return ToCharStringUnsafe(length, (const wchar_t*)str);
#else
        if (length == 0) [[unlikely]] return CharString(true);

        ::std::filesystem::path p = str;

        ::std::string str1 = p.generic_string();

        return CharString::FromPointerUnsafe(str1.size(), str1.c_str());
#endif
    }

    CharString StringHelper::ToCharStringUnsafe(ssize_t length, const char32_t* str)
    {
        if (length == 0) [[unlikely]] return CharString(true);
        
        ::std::filesystem::path p = str;

        ::std::string str1 = p.generic_string();

        return CharString::FromPointerUnsafe(str1.size(), str1.c_str());
    }

    String StringHelper::ToStringUnsafe(ssize_t length, const char* str)
    {
        if (length == 0) [[unlikely]] return String(true); 
#if KONGKONG_ENV_WINDOWS
        int capacity = ::MultiByteToWideChar(CP_ACP, 0, str, (int)length, nullptr, 0) + 1;

        char16_t* p = String::AllocMemoryUnsafe(capacity);

        ::MultiByteToWideChar(CP_ACP, 0, str, (int)length, (wchar_t*)p, capacity);

        return String::WrapUnsafe(capacity, capacity - 1, p);
        
#else
        ::std::filesystem::path p = str;

        ::std::u16string str1 = p.generic_u16string();

        return String::FromPointerUnsafe(str1.size(), str1.c_str());
#endif
    }

    String StringHelper::ToStringUnsafe(ssize_t length, const wchar_t* str)
    {
        if (length == 0) [[unlikely]] return String(true); 
#if KONGKONG_ENV_WINDOWS
        
        return String::FromPointerUnsafe(length, (const char16_t*)str, true);
        
#else
        ::std::filesystem::path p = str;

        ::std::u16string str1 = p.generic_u16string();

        return String::FromPointerUnsafe(str1.size(), str1.c_str());
#endif
    }

    String StringHelper::ToStringUnsafe(ssize_t length, const char8_t* str)
    {
        if (length == 0) [[unlikely]] return String(true); 
#if KONGKONG_ENV_WINDOWS
        int capacity = ::MultiByteToWideChar(CP_UTF8, 0, (const char*)str, (int)length, nullptr, 0) + 1;

        char16_t* p = String::AllocMemoryUnsafe(capacity);

        ::MultiByteToWideChar(CP_UTF8, 0, (const char*)str, (int)length, (wchar_t*)p, capacity);

        return String::WrapUnsafe(capacity, capacity - 1, p);

#else
        ::std::filesystem::path p = str;

        ::std::u16string str1 = p.generic_u16string();

        return String::FromPointerUnsafe(str1.size(), str1.c_str());
#endif
    }

    String StringHelper::ToStringUnsafe(ssize_t length, const char16_t* str)
    {
        if (length == 0) [[unlikely]] return String(true); 

        return String::FromPointerUnsafe(length, str, true);
    }

    String StringHelper::ToStringUnsafe(ssize_t length, const char32_t* str)
    {
        ::std::filesystem::path p = str;

        ::std::u16string str1 = p.generic_u16string();

        return String::FromPointerUnsafe(str1.size(), str1.c_str());
    }
}

#undef CHECK_ERROR_MESSAGE
