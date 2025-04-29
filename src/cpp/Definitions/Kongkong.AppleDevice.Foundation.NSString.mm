//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    NSString NSString::Empty() noexcept
    {
        return NSString();
    }

    NSString::NSString() noexcept : NSObject(nullptr)
    {
        NSObjectHelper::SetPointer(*this, [::NSString string]);
    }

    NSString::NSString(const char* str) : NSObject(nullptr)
    {
        @try {
            _setInstance([::NSString stringWithUTF8String: str]);
        }
        @catch (::NSException *exception) {
            ArgumentNullException::ThrowWithName(u"str");
        }
    }

    NSString::NSString(std::string const& str) : NSObject(nullptr)
    {
        _setInstance([::NSString stringWithUTF8String: str.c_str()]);
    }

    NSString::NSString(const char16_t* u16str) : NSObject(nullptr)
    {
        ArgumentNullException::CheckNull(u16str, u"u16str");
        _setInstance([::NSString stringWithCharacters:(const unichar*)u16str length: ::KONGKONG_NAMESPACE::Text::StringHelper::GetLengthUnsafe(u16str)]);
    }

    NSString::NSString(String const& str) : NSObject(nullptr)
    {
        _setInstance([::NSString stringWithCharacters:(const unichar*)str.c_str() length:str.Length()]);
    }

    char16_t NSString::operator[] (size_t index) const
    {
        @try {
            auto p = (::NSString*)_instance();
            char16_t result = [p characterAtIndex:index];

            return result;
        }
        @catch (::NSException* e) {
            return std::char_traits<char16_t>::eof();
        }
    }

    char16_t NSString::At(size_t index) const
    {
        @try {
            auto p = (::NSString*)_instance();
            char16_t result = [p characterAtIndex:index];

            return result;
        }
        @catch (::NSException* e) {
            throw ArgumentOutOfRangeException(u"指定されたインデックスは範囲外です");
        }
    }

    bool NSString::Contains(char16_t c) const
    {
        _checkNull();
        char16_t c16s[]{ c, u'\0' };

        return Contains(c16s);
    }

    bool NSString::Contains(const char16_t* u16str) const
    {
        _checkNull();

        NSString str = u16str;

        return Contains(str);
    }

    bool NSString::Contains(String const& str) const
    {
        _checkNull();

        NSString s = str;

        return Contains(s);
    }

    bool NSString::Contains(NSString const& str) const
    {
        auto p = (::NSString*)_instance();
        auto right = (::NSString*)NSObjectHelper::GetPointer(str);

        ArgumentNullException::CheckNull(right, u"str");

        auto result = [p containsString:right];

        return (bool)result;
    }

    NSString NSString::Copy() const
    {
        auto p = (::NSString*)_instance();
        auto result = [[::NSString alloc] initWithString:p];

        return NSStringHelper::FromHandle(result);
    }

    bool NSString::EndsWith(char16_t c) const
    {
        char16_t c16s[]{ c, u'\0' };

        return EndsWith(c16s);
    }

    bool NSString::EndsWith(const char16_t* u16str) const
    {
        _checkNull();

        NSString str = u16str;

        return EndsWith(str);
    }

    bool NSString::EndsWith(String const& str) const
    {
        _checkNull();

        NSString s = str;

        return EndsWith(s);
    }

    bool NSString::EndsWith(NSString const& str) const
    {
        auto p = (::NSString*)_instance();
        auto right = (::NSString*)NSObjectHelper::GetPointer(str);

        ArgumentNullException::CheckNull(right, u"str");

        auto result = [p hasSuffix:right];

        return (bool)result;
    }

    ssize_t NSString::Length() const
    {
        auto str = (::NSString*)_instance();
        
        return (ssize_t)str.length;
    }

    bool NSString::StartsWith(char16_t c) const
    {
        _checkNull();

        char16_t c16s[]{ c, u'\0' };

        return StartsWith(c16s);
    }

    bool NSString::StartsWith(const char16_t* u16str) const
    {
        _checkNull();

        NSString str = u16str;

        return StartsWith(str);
    }

    bool NSString::StartsWith(String const& str) const
    {
        _checkNull();

        NSString s = str;

        return StartsWith(s);
    }

    bool NSString::StartsWith(NSString const& str) const
    {
        auto p = (::NSString*)_instance();
        auto right = (::NSString*)NSObjectHelper::GetPointer(str);

        ArgumentNullException::CheckNull(right, u"str");

        auto result = [p hasPrefix:right];

        return (bool)result;
    }

    CharString NSString::ToCharString() const
    {
        return CharString::FromPointerUnsafe(Utf8String(), true);
    }

    Utf8String NSString::ToUtf8String() const
    {
        return Utf8String::FromPointerUnsafe((const char8_t*)Utf8String(), true);
    }

    const char* NSString::Utf8String() const
    {
        auto p = (::NSString*)_instance();

        return (const char*)p.UTF8String;
    }
}
