#ifndef KONGKONG_TEXT_H
#define KONGKONG_TEXT_H

#include "Definitions/Kongkong.Text.AsciiEncoding.h"
#include "Definitions/Kongkong.Text.Encoding.h"
#include "Definitions/Kongkong.Text.GenericFixedString.h"
#include "Definitions/Kongkong.Text.InvalidCodePointException.h"
#include "Definitions/Kongkong.Text.Utf8CharAttribute.h"
#include "Definitions/Kongkong.Text.StaticStringData.h"
#include "Definitions/Kongkong.Text.StringHelper.h"
#include "Definitions/Kongkong.Text.StringType.h"
//#include "Definitions/Kongkong.Text._stringGC.h"
#include "Definitions/Kongkong.Text._stringPointer.h"
#include "Definitions/Kongkong.Text._stringPointerBase.h"

#if 0
#include "Kongkong.h"
#include "Kongkong.Collections.h"
#include "Kongkong.Standard.h"

namespace KONGKONG_NAMESPACE::Text
{

    struct Char final : public ValueType {
        
        //型のサイズ
        [[nodiscard]] static constexpr ssize_t BitSize() noexcept { return (ssize_t)(sizeof(char16_t) * 8); }
        [[nodiscard]] static constexpr ssize_t ByteSize() noexcept { return (ssize_t)(sizeof(char16_t)); }

        //EOF
        [[nodiscard]] static constexpr char16_t EndOfLine() noexcept { return std::char_traits<char16_t>::eof(); }

        //アスキー文字かどうか
        [[nodiscard]] static constexpr bool IsAscii(char16_t c) noexcept { return c <= u'\u007F'; }
        [[nodiscard]] static constexpr bool IsAsciiDigit(char16_t c) noexcept { return u'0' <= c && c <= u'9'; }
        [[nodiscard]] static constexpr bool IsAsciiHexDigit(char16_t c) noexcept { return (u'0' <= c && c <= u'9') || (u'A' <= c && u'F') || (u'a' <= c && c <= u'f'); }
        [[nodiscard]] static constexpr bool IsAsciiHexDigitLower(char16_t c) noexcept { return (u'0' <= c && c <= u'9') || (u'a' <= c && c <= u'f'); }
        [[nodiscard]] static constexpr bool IsAsciiHexDigitUpper(char16_t c) noexcept { return (u'0' <= c && c <= u'9') || (u'A' <= c && u'F'); }
        [[nodiscard]] static constexpr bool IsAsciiLetter(char16_t c) noexcept { return (u'A' <= c && c <= u'Z') || (u'a' <= c && c <= u'z'); }
        [[nodiscard]] static constexpr bool IsAsciiLetterLower(char16_t c) noexcept { return u'a' <= c && c <= u'z'; }
        [[nodiscard]] static constexpr bool IsAsciiLetterUpper(char16_t c) noexcept { return u'A' <= c && c <= u'Z'; }

        //cがminValueとmaxValueの間にあるかを判定
        [[nodiscard]] static constexpr bool IsBetween(char16_t c, char16_t minValue, char16_t maxValue) { return minValue > maxValue ? throw ArgumentOutOfRangeException(u"'min' is larger than 'max'.") : (minValue <= c && c <= maxValue); }

        //制御文字かを判定
        [[nodiscard]] static constexpr bool IsControl(char16_t c) noexcept { return (u'\u0000' <= c && c <= u'\u001F') || (u'\u007F' <= c && c <= u'\u009F'); }

        //よくわからんやつ
        [[nodiscard]] static constexpr bool IsHighSurrogate(char16_t c) noexcept { return 0xD800 <= c && c <= 0xDBFF; }

        [[nodiscard]] static bool IsLetter(char16_t c) noexcept { return std::iswalpha(c); }
        [[nodiscard]] static bool IsLetterOrDigit(char16_t c) noexcept { return std::iswalpha(c) || std::iswdigit(c); }
        [[nodiscard]] static bool IsLower(char16_t c) noexcept { return std::iswlower(c); }

        //よくわからんやつ
        [[nodiscard]] static constexpr bool IsLowSurrogate(char16_t c) noexcept { return 0xDC00 <= c && c <= 0xDFFF; }

        [[nodiscard]] static constexpr bool IsNumber(char16_t c) noexcept { return (u'0' <= c && c <= u'9') || (u'０' <= c && c <= u'９'); }
        [[nodiscard]] static bool IsPunctuation(char16_t c) noexcept { return std::iswpunct(c); }
        [[nodiscard]] static constexpr bool IsSeparator(char16_t c) noexcept
        { 
            return 
            c == u'\u0020' ||
            c == u'\u00A0' ||
            c == u'\u1680' ||
            c == u'\u180E' ||
            (u'\u2000' <= c && c <= u'\u200A') ||
            c == u'\u202F' ||
            c == u'\u205F' ||
            c == u'\u3000';
        }
        [[nodiscard]] static constexpr bool IsSurrogate(char16_t c) noexcept { return 0xD800 <= c && c <= 0xDFFF; }

        //よくわからんやつ
        [[nodiscard]] static constexpr bool IsSurrogatePair(char16_t highSurrogate, char16_t lowSurrogate) noexcept { return IsHighSurrogate(highSurrogate) && IsLowSurrogate(lowSurrogate); }

        //記号
        [[nodiscard]] static bool IsSymbol(char16_t c) noexcept;

        [[nodiscard]] static bool IsUpper(char16_t c) noexcept { return std::iswupper(c); }

        [[nodiscard]] static constexpr bool IsWhiteSpace(char16_t c) noexcept { return c == u'\u0020' ||
            c == u'\u00A0' ||
            c == u'\u1680' ||
            (u'\u2000' <= c && c <= u'\u200A') ||
            c == u'\u202F' ||
            c == u'\u205F' ||
            c == u'\u3000';
        }

        [[nodiscard]] static constexpr char16_t MaxValue() noexcept { return u'\uFFFF'; }
        [[nodiscard]] static constexpr char16_t MinValue() noexcept { return u'\0'; }

        [[nodiscard]] static char16_t ToLower(char16_t c) noexcept { return std::towlower(c); }
        [[nodiscard]] static char16_t ToUpper(char16_t c) noexcept { return std::towlower(c); }

        [[nodiscard]] static String ToString(char16_t c);

        constexpr Char() : _c() {}
        constexpr Char(char16_t c) : _c(c) {}

        constexpr operator char16_t() const noexcept { return _c; }
        Char& operator=(char16_t c) noexcept;

        [[nodiscard]] char16_t ToLower() const noexcept { return std::towlower(_c); }
        [[nodiscard]] char16_t ToUpper() const noexcept { return std::towupper(_c); }

        [[nodiscard]] String ToString() const;
        

        [[nodiscard]] constexpr char16_t Value() const noexcept { return _c; }

        private:
        char16_t _c;

    };

    /// @brief 多分動作が速い文字列クラス
    /// @tparam TChar 文字型
    template <CharType TChar>
    struct ReadOnlyString : public ValueType {
        /// @brief 型の大きさを取得
        [[nodiscard]]
        static constexpr ssize_t ElementSize() noexcept { return (ssize_t)sizeof(TChar); }
        
        /// @brief Null文字を取得
        [[nodiscard]]
        static constexpr TChar NullChar() noexcept { return (TChar)0; }

        ReadOnlyString();
        ReadOnlyString(TChar c);
        ReadOnlyString(ssize_t count, TChar c);
        ReadOnlyString(std::nullptr_t) noexcept;
        ReadOnlyString(const TChar* cstr);
        ReadOnlyString(ssize_t length, const TChar* cstr);
        ReadOnlyString(ReadOnlyString const& right);
        ReadOnlyString(ReadOnlyString&& right);
        ReadOnlyString(String const& str) requires std::derived_from<TChar, char16_t>;

        virtual ~ReadOnlyString();

        ReadOnlyString& operator=(ReadOnlyString const& right);
        ReadOnlyString& operator=(ReadOnlyString&& right);

        [[nodiscard]] constexpr const TChar* begin() const noexcept { return _data; }
        [[nodiscard]] constexpr const TChar* end() const noexcept { return _data + _length; }

        [[nodiscard]]
        constexpr const TChar* c_str() const noexcept { return _data; }

        /// @brief 境界チェックなしで要素にアクセス DataがNULLの場合はランタイムエラーでアプリケーションが強制終了する可能性あり
        /// @param index 要素番号
        /// @return 指定したインデックスの要素
        [[nodiscard]]
        TChar const& operator[] (ssize_t index) const noexcept { return _data[index]; }

        [[nodiscard]]
        TChar const& At(ssize_t index) const;

        [[nodiscard]]
        constexpr const TChar* Data() const noexcept { return _data; }

        [[nodiscard]]
        constexpr bool HasData() const noexcept { return _length != _nullLength; }

        /// @brief 文字列の長さ
        /// @return 文字列の長さ
        /// @return nullの場合は-1
        [[nodiscard]]
        ssize_t Length() const noexcept { return _length; }

        [[nodiscard]]
        String ToString() const override { return u"Kongkong::Text::ReadOnlyString<T>"; }

        private:

        void _copy(ssize_t count, const TChar* str);
        static void _checkZero(ssize_t count) { if (count <= 0) [[unlikely]] throw InvalidArgumentException(u"文字数にゼロ以下が指定されました"); }

        /// @brief Nullの時の長さ
        static constexpr ssize_t _nullLength = -1;

        TChar* _data;
        ssize_t _length;

    };

    //BOM
    class ByteOrderMark final {
        public:

        STATIC_CLASS(ByteOrderMark)

        [[nodiscard]] static Collections::IReadOnlyArray<uint8_t> const& Utf8() { return _utf8; }
        [[nodiscard]] static Collections::IReadOnlyArray<uint8_t> const& Utf16LE() { return _utf16LE; }
        [[nodiscard]] static Collections::IReadOnlyArray<uint8_t> const& Utf16BE() { return _utf16BE; }
        [[nodiscard]] static Collections::IReadOnlyArray<uint8_t> const& Utf32LE() { return _utf32LE; }
        [[nodiscard]] static Collections::IReadOnlyArray<uint8_t> const& Utf32BE() { return _utf32BE; }
        
        private:

        static Collections::IReadOnlyArray<uint8_t> _utf8;
        static Collections::IReadOnlyArray<uint8_t> _utf16LE;
        static Collections::IReadOnlyArray<uint8_t> _utf16BE;
        static Collections::IReadOnlyArray<uint8_t> _utf32LE;
        static Collections::IReadOnlyArray<uint8_t> _utf32BE;
    };


    class StringHelper final {

        public:

        STATIC_CLASS(StringHelper)

        //文字列を文字コードで取得
        //u"あいうえお" => u"3042 3044 3046 3048 304A"
        //マジでいらん
        static String ToCharCode(String const& str);


    };

    //
    class SourceCodeFormatter final {
        public:

        STATIC_CLASS(SourceCodeFormatter)

        static String FormatCPlusPlusCode(String const& sourceCode, ssize_t spacing = 4);
        static String FormatCSharpCode(String const& sourceCode, ssize_t spacing = 4);
        static String FormatJavaCode(String const& sourceCode, ssize_t spacing = 4);
        static String FormatXmlCode(String const& sourceCode, ssize_t spacing = 4);


    };
}

//メソッドの実装
namespace KONGKONG_NAMESPACE::Text
{
    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString() :
        _data((TChar*)Standard::CStdMemoryManager::AllocMemory(sizeof(TChar))),
        _length(0)
    {
        *_data = (TChar)0;
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString(TChar c) :
        _data((TChar*)Standard::CStdMemoryManager::AllocMemory(sizeof(TChar) * 2)),
        _length(1)
    {
        *_data = c;
        _data[1] = (TChar)0;
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString(ssize_t count, TChar c) :
        _data(nullptr),
        _length(count)
    {
        _checkZero(count);
    
        _data = (TChar*)Standard::CStdMemoryManager(sizeof(TChar) * (count + 1));

        TChar* p = _data;
        TChar* end = p + count;

        while (p != end) {
            *p = c;
            ++p;
        }

        *end = (TChar)0;
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString(std::nullptr_t) noexcept :
        _data(nullptr),
        _length(_nullLength)
    {
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString(const TChar* cstr) :
        _data(nullptr),
        _length(_nullLength)
    {
        if (cstr == nullptr) [[unlikely]] return;

        const TChar* p = cstr;

        while (*p != (TChar)0) {
            ++p;
        }

        ssize_t count = p - cstr;
        _length = count;

        _copy(count, cstr);
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString(ssize_t length, const TChar* cstr) :
        _length(length),
        _data(nullptr)
    {
        ArgumentNullException::CheckNull(cstr, u"cstr");
        _checkZero(length);
        
        _copy(length, cstr);
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString(ReadOnlyString const& right) :
        _length(right._length),
        _data((TChar*)Standard::CStdMemoryManager::AllocMemory(sizeof(TChar) * (right._length + 1)))
    {
        ::memcpy(_data, right._data, _length + 1);
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString(ReadOnlyString&& right) :
        _length(right._length),
        _data(right._data)
    {
        right._data = nullptr;
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::ReadOnlyString(String const& str) requires std::derived_from<TChar, char16_t> :
        _length(str.Length()),
        _data((TChar*)Standard::CStdMemoryManager::AllocMemory(sizeof(TChar) * (str.Length() + 1)))
    {
        ::memcpy(_data, str.Data(), _length + 1);
    }

    template <CharType TChar>
    ReadOnlyString<TChar>::~ReadOnlyString<TChar>()
    {
        if (_data != nullptr) ::free(_data);
    }

    template <CharType TChar>
    ReadOnlyString<TChar>& ReadOnlyString<TChar>::operator=(ReadOnlyString<TChar> const& right)
    {
        ::free(_data);
        if (right._length == _nullLength) {
            _length = _nullLength;
            _data = nullptr;
        }
        else {
            _copy(right._length, right._data);
            _length = right._length;
        }

        return *this;
    }

    template <CharType TChar>
    ReadOnlyString<TChar>& ReadOnlyString<TChar>::operator=(ReadOnlyString<TChar>&& right)
    {
        _data = right._data;
        _length = right._length;

        right._data = nullptr;

        return *this;
    }

    template <CharType TChar>
    TChar const& ReadOnlyString<TChar>::At(ssize_t index) const
    {
        if (_length == _nullLength) [[unlikely]] throw NullPointerException(u"Data()がNullでした");
        if (index < 0 || _length <= index) [[unlikely]] throw InvalidArgumentException(u"インデックスが範囲外です");

        return _data[index];
    }

    template <CharType TChar>
    void ReadOnlyString<TChar>::_copy(ssize_t count, const TChar* str)
    {
        _data = (TChar*)Standard::CStdMemoryManager::AllocMemory(sizeof(TChar) * (count + 1));

        ::memcpy(_data, str, count);

        _data[count] = (TChar)0;
    }
}

#endif //0
#endif //!KONGKONG_TEXT_H
