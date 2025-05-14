#ifndef KONGKONG_STD_NAMESPACE_H
#define KONGKONG_STD_NAMESPACE_H

#include "Base.h"
#include <ostream>
#include <string>

namespace std
{
    //Kongkong::Stringからstd::stringに変換
    string to_string(::KONGKONG_NAMESPACE::String const& value);
    string to_string(::KONGKONG_NAMESPACE::StringView const& value);
    string to_string(const char16_t* value);
    string to_string(char16_t value);
    
    u8string to_u8string(::KONGKONG_NAMESPACE::String const& value);
    u8string to_u8string(::KONGKONG_NAMESPACE::StringView const& value);
    u8string to_u8string(const char16_t* value);
    u8string to_u8string(char16_t value);

    //
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object const& object);
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::Object const& object);
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::String const& str);
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::Exception const& e);
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::CharString const& str);
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::CharStringView const& str);

    template <::KONGKONG_NAMESPACE::KongkongValueType TValue>
    ostream& operator<<(ostream& out, TValue const& value)
    {
        return out << value.ToString();
    }

#if KONGKONG_OBJECTIVE_C_ENABLED
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::AppleDevice::NSObject const& nsObject);
    ostream& operator<<(ostream& out, ::KONGKONG_NAMESPACE::AppleDevice::Foundation::NSString const& nsString);
#endif

}

#endif //!KONGKONG_STD_NAMESPACE_H
