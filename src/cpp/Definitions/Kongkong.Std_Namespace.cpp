//このcppファイルをコンパイルに含めないでください

namespace std
{

    string to_string(::KONGKONG_NAMESPACE::String const& value)
    {
#if KONGKONG_ENV_WINDOWS

        return to_string(::KONGKONG_NAMESPACE::StringView(value));

#elif KONGKONG_ENV_UNIX

        std::filesystem::path p(value.begin(), value.end());

        return p.generic_string();

#endif
    }

    string to_string(::KONGKONG_NAMESPACE::StringView const& value)
    {
        if (value.Length() == 0) [[unlikely]] return string();

#if KONGKONG_ENV_WINDOWS

        ssize_t size = (value.Length() + 1) * sizeof(char16_t);
        char* mbs = NEW char[size];

        ::KONGKONG_NAMESPACE::MemoryAllocationException::CheckNull(mbs);

        int result = ::WideCharToMultiByte(CP_ACP, 0, (const wchar_t*)value.c_str(), (int)value.Length(), mbs, (int)size, nullptr, nullptr);

        if (result == 0) [[unlikely]] {
            delete[] mbs;
            throw KONGKONG_NAMESPACE::InvalidArgumentException(u"");
        }

        mbs[result] = '\0';

        string str(mbs);

        delete[] mbs;

        return str;

#else

        std::filesystem::path p(value.begin(), value.end());

        return p.generic_string();
        
#endif
    }

    string to_string(const char16_t* value)
    {
#if KONGKONG_ENV_WINDOWS

        try {
            return to_string(::KONGKONG_NAMESPACE::StringView(value));
        }
        catch (::KONGKONG_NAMESPACE::ArgumentNullException) {
            ::KONGKONG_NAMESPACE::ArgumentNullException::ThrowWithName(u"value");
        }

#elif KONGKONG_ENV_UNIX

        std::filesystem::path p = value;

        return p.generic_string();

#endif
    }

    string to_string(char16_t value)
    {
        char16_t str[2];
        str[0] = value;
        str[1] = u'\0';

        return to_string(str);
    }

    u8string to_u8string(::KONGKONG_NAMESPACE::String const& value)
    {
#if KONGKONG_ENV_WINDOWS

        uint32_t length = (uint32_t)((value.Length() + 1) * 3);

        char8_t* c8s = new char8_t[length];

        if (::WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)value.c_str(), -1, (char*)c8s, length, nullptr, nullptr) == 0) [[unlikely]] throw KONGKONG_NAMESPACE::InvalidArgumentException(EXCEPTION_MESSAGE);

        u8string str = c8s;

        delete[] c8s;

        return str;

#elif KONGKONG_ENV_UNIX

        std::filesystem::path p = value.c_str();

        return p.generic_u8string();

#endif
    }

    u8string to_u8string(::KONGKONG_NAMESPACE::StringView const& value)
    {
        ssize_t size = (ssize_t)((value.Length() + 1) * 3);

        char16_t* tmp = new char16_t[value.Length() + 1];

        for (ssize_t i = 0; i < value.Length(); ++i) {
            tmp[i] = value[i];
        }

        tmp[value.Length()] = u'\0';

#if KONGKONG_ENV_WINDOWS

        char8_t* mbs = new char8_t[size];

        if (::WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)tmp, -1, (char*)mbs, (int)size, nullptr, nullptr) == 0) [[unlikely]] throw KONGKONG_NAMESPACE::InvalidArgumentException(EXCEPTION_MESSAGE);

        u8string str(mbs);

        delete[] mbs;
        delete[] tmp;

        return str;

#elif KONGKONG_ENV_UNIX

        std::filesystem::path p = tmp;

        delete[] tmp;

        return p.generic_u8string();
        
#endif
    }

    u8string to_u8string(const char16_t* value)
    {
#if KONGKONG_ENV_WINDOWS

        ssize_t size = (ssize_t)((::KONGKONG_NAMESPACE::Text::StringHelper::GetLength(value) + 1) * 3);

        char8_t* mbs = NEW char8_t[size];

        ::KONGKONG_NAMESPACE::MemoryAllocationException::CheckNull(mbs);

        if (::WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)value, -1, (char*)mbs, (int)size, nullptr, nullptr) == 0) [[unlikely]] throw KONGKONG_NAMESPACE::InvalidArgumentException(EXCEPTION_MESSAGE);

        u8string str(mbs);

        delete[] mbs;

        return str;

#elif KONGKONG_ENV_UNIX

        std::filesystem::path p = value;

        return p.generic_u8string();

#endif
    }
    u8string to_u8string(char16_t value)
    {
        char16_t str[2];
        str[0] = value;
        str[1] = u'\0';

        return to_u8string(str);
    }

    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object const& object)
    {
        return out << object.ToString();
    }

    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::Object const& object)
    {
        if (object == nullptr) [[unlikely]] return out.write("Null", 4);
        else return out << to_string(object->ToString());
    }

    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::String const& str)
    {
        return out << to_string(str);
    }

    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::Exception const& e)
    {
        return out << to_string(e.Message());
    }

    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::CharString const& str)
    {
        return out.write(str.c_str(), str.Length());
    }
    
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::CharStringView const& str)
    {
        return out.write(str.c_str(), str.Length());
    }

#if KONGKONG_OBJECTIVE_C_ENABLED
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::AppleDevice::NSObject const& nsObject)
    {
        if (nsObject == nullptr) [[unlikely]] return out << "Null";

        return out << nsObject.ToNSString().Utf8String();
    }

    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::AppleDevice::Foundation::NSString const& nsString)
    {
        if (nsString == nullptr) [[unlikely]] return out << "Null";

        return out << nsString.Utf8String();
    }
#endif
}
