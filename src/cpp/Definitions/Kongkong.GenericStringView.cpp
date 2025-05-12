//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    template <>
    constinit const char CharStringView::_emptyHolder = '\0';

    template <>
    constinit const wchar_t WideStringView::_emptyHolder = L'\0';

    template <>
    constinit const char8_t Utf8StringView::_emptyHolder = u8'\0';

    template <>
    constinit const char16_t StringView::_emptyHolder = u'\0';

    template <>
    constinit const char32_t Utf32StringView::_emptyHolder = U'\0';

    template <>
    constinit const CharStringView CharStringView::_empty = CharStringView();

    template <>
    constinit const WideStringView WideStringView::_empty = WideStringView();

    template <>
    constinit const Utf8StringView Utf8StringView::_empty = Utf8StringView();

    template <>
    constinit const StringView StringView::_empty = StringView();

    template <>
    constinit const Utf32StringView Utf32StringView::_empty = Utf32StringView();

    template <class TChar> requires CharType<TChar>
    GenericStringView<TChar> GenericStringView<TChar>::FromPointerUnsafe(const TChar* p) noexcept
    {
        return GenericStringView<TChar>(p, Text::StringHelper::GetLengthUnsafe(p), 0);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::IsWeakEqual(GenericStringView<TChar> const& left, GenericStringView<TChar> const& right) noexcept
    {
        if (left._length != right._length) return false;

        for (ssize_t i = 0; i < left._length; i++) {
            if (left._p[i] != right._p[i]) return false;
        }

        return true;
    }

    template <class TChar> requires CharType<TChar>
    GenericStringView<TChar>::GenericStringView(ssize_t length, const TChar* p) : _p(p), _length(length)
    {
        ArgumentNullException::CheckNull(p, u"p");
        if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"文字列の長さにゼロ以下の値が指定されました");
        ssize_t len = Text::StringHelper::GetLengthUnsafe(p);
        if (length > len) [[unlikely]] throw ArgumentOutOfRangeException(u"'length' is larger than the maximum length of the string.");
    }

    template <class TChar> requires CharType<TChar>
    GenericStringView<TChar>::GenericStringView(const TChar* p) : _p(p), _length(Text::StringHelper::GetLength(p))
    {
    }

    template <class TChar> requires CharType<TChar>
    TChar GenericStringView<TChar>::At(ssize_t index) const
    {
        Collections::CollectionHelper::CheckIndex(index, _length);
        
        return _p[index];
    }

    template <class TChar> requires CharType<TChar>
    TChar GenericStringView<TChar>::Back() const
    {
        Collections::CollectionHelper::CheckLength(_length);

        return _p[_length - 1];
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::Contains(TChar c) const noexcept
    {
        return Text::StringHelper::ContainsUnsafe(_length, _p, c);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::Contains(const TChar* p) const
    {
        return Contains(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::Contains(GenericStringView<TChar> const& view) const noexcept
    {
        return Text::StringHelper::ContainsUnsafe(_length, _p, view._length, view._p);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::Contains(GenericString<TChar> const& str) const noexcept
    {
        return Text::StringHelper::ContainsUnsafe(_length, _p, str._length, str._p);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::EndsWith(TChar c) const noexcept
    {
        return Text::StringHelper::EndsWithUnsafe(_length, _p, c);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::EndsWith(const TChar* p) const
    {
        return EndsWith(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::EndsWith(GenericStringView<TChar> const& view) const noexcept
    {
        return Text::StringHelper::EndsWithUnsafe(_length, _p, view._length, view._p);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::EndsWith(GenericString<TChar> const& str) const noexcept
    {
        return Text::StringHelper::EndsWithUnsafe(_length, _p, str._length, str._p);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::Find(TChar c) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length, _p, c);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::Find(const TChar* p) const
    {
        return Find(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::Find(GenericStringView<TChar> const& view) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length, _p, view._length, view._p);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::Find(GenericString<TChar> const& str) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length, _p, str._length, str._p);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::Find(TChar c, ssize_t offset) const
    {
        _checkOffset(offset);

        return FindUnsafe(c, offset);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::Find(const TChar* p, ssize_t offset) const
    {
        ArgumentNullException::CheckNull(p, u"p");
        _checkOffset(offset);

        return FindUnsafe(p, offset);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::Find(GenericStringView<TChar> const& view, ssize_t offset) const
    {
        _checkOffset(offset);

        return FindUnsafe(view, offset);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::Find(GenericString<TChar> const& str, ssize_t offset) const
    {
        _checkOffset(offset);

        return FindUnsafe(str, offset);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::FindUnsafe(TChar c, ssize_t offset) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length - offset, _p + offset, c) + offset;
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::FindUnsafe(const TChar* p, ssize_t offset) const noexcept
    {
        ssize_t pLength = Text::StringHelper::GetLengthUnsafe(p);

        return Text::StringHelper::FindUnsafe(_length - offset, _p + offset, pLength, p);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::FindUncheckOffsetUnsafe(const TChar* p, ssize_t offset) const
    {
        ArgumentNullException::CheckNull(p, u"p");

        return FindUnsafe(p, offset);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::FindUncheckPointerUnsafe(const TChar* p, ssize_t offset) const
    {
        _checkOffset(offset);

        return FindUnsafe(p, offset);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::FindUnsafe(GenericStringView<TChar> const& view, ssize_t offset) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length - offset, _p + offset, view._length, view._p) + offset;
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericStringView<TChar>::FindUnsafe(GenericString<TChar> const& str, ssize_t offset) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length - offset, _p + offset, str._length, str._p) + offset;
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::IsWeakEqual(GenericStringView<TChar> const& right) const noexcept
    {
        return IsWeakEqual(*this, right);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::StartsWith(TChar c) const noexcept
    {
        return Text::StringHelper::StartsWithUnsafe(_length, _p, c);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::StartsWith(const TChar* p) const
    {
        return StartsWith(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::StartsWith(GenericStringView<TChar> const& view) const noexcept
    {
        return Text::StringHelper::StartsWithUnsafe(_length, _p, view._length, view._p);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericStringView<TChar>::StartsWith(GenericString<TChar> const& str) const
    {
        return Text::StringHelper::StartsWithUnsafe(_length, _p, str._length, str._p);
    }

    template <class TChar> requires CharType<TChar>
    GenericStringView<TChar> GenericStringView<TChar>::SubString(ssize_t offset, ssize_t count) const
    {
        _checkCount(offset, count);

        return GenericStringView<TChar>(count, _p + offset);
    }

    template <class TChar> requires CharType<TChar>
    GenericStringView<TChar> GenericStringView<TChar>::SubString(ssize_t count) const
    {
        _checkCount(0, count);
        
        return GenericStringView<TChar>(count, _p);
    }

    template <class TChar> requires CharType<TChar>
    CharString GenericStringView<TChar>::ToCharString() const
    {
        return Text::StringHelper::ToCharStringUnsafe(_length, _p);
    }

    template <class TChar> requires CharType<TChar>
    String GenericStringView<TChar>::ToString() const
    {
        return Text::StringHelper::ToStringUnsafe(_length, _p);
    }

    template <class TChar> requires CharType<TChar>
    void GenericStringView<TChar>::_checkCount(ssize_t offset, ssize_t count) const
    {
        if (count <= 0) [[unlikely]] throw InvalidArgumentException(u"文字数にゼロ以下の値が指定されました");
        
        ssize_t len = Text::StringHelper::GetLengthUnsafe(_p);

        if (offset >= len) [[unlikely]] throw ArgumentOutOfRangeException(u"開始位置が範囲外です");

        if (offset + count > len) [[unlikely]] throw ArgumentOutOfRangeException(u"終了位置が範囲外です");
    }

    template <class TChar> requires CharType<TChar>
    void GenericStringView<TChar>::_checkOffset(ssize_t offset) const
    {
        if (offset >= _length) [[unlikely]] throw ArgumentOutOfRangeException(u"開始位置が範囲外です");
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericStringView<TChar> const& left, GenericStringView<TChar> const& right)
    {
        GenericString<TChar> str = left;
        str.Append(right);

        return str;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar> const& left, GenericStringView<TChar> const& right)
    {
        GenericString<TChar> str = left;
        str.Append(right);

        return str;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar>&& left, GenericStringView<TChar> const& right)
    {
        left.Append(right);

        return left;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericStringView<TChar> const& left, GenericString<TChar> const& right)
    {
        return right + left;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericStringView<TChar> const& left, const TChar* right)
    {
        GenericString<TChar> str = left;

        return std::move(str) + right;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(const TChar* left, GenericStringView<TChar> const& right)
    {
        try {
            GenericString<TChar> str = left;
            str.Append(right);

            return str;
        }
        catch (...) {
            ArgumentNullException::ThrowWithName(u"left");
        }
    }

    template struct GenericStringView<char>;
    template struct GenericStringView<wchar_t>;
    template struct GenericStringView<char8_t>;
    template struct GenericStringView<char16_t>;
    template struct GenericStringView<char32_t>;

    template CharString operator+(CharStringView const&, CharStringView const&);
    template WideString operator+(WideStringView const&, WideStringView const&);
    template Utf8String operator+(Utf8StringView const&, Utf8StringView const&);
    template String operator+(StringView const&, StringView const&);
    template Utf32String operator+(Utf32StringView const&, Utf32StringView const&);

    template CharString operator+(CharString const&, CharStringView const&);
    template WideString operator+(WideString const&, WideStringView const&);
    template Utf8String operator+(Utf8String const&, Utf8StringView const&);
    template String operator+(String const&, StringView const&);
    template Utf32String operator+(Utf32String const&, Utf32StringView const&);

    template CharString operator+(CharString&&, CharStringView const&);
    template WideString operator+(WideString&&, WideStringView const&);
    template Utf8String operator+(Utf8String&&, Utf8StringView const&);
    template String operator+(String&&, StringView const&);
    template Utf32String operator+(Utf32String&&, Utf32StringView const&);

    template CharString operator+(CharStringView const&, CharString const&);
    template WideString operator+(WideStringView const&, WideString const&);
    template Utf8String operator+(Utf8StringView const&, Utf8String const&);
    template String operator+(StringView const&, String const&);
    template Utf32String operator+(Utf32StringView const&, Utf32String const&);

    template CharString operator+(CharStringView const&, const char*);
    template WideString operator+(WideStringView const&, const wchar_t*);
    template Utf8String operator+(Utf8StringView const&, const char8_t*);
    template String operator+(StringView const&, const char16_t*);
    template Utf32String operator+(Utf32StringView const&, const char32_t*);

    template CharString operator+(const char*, CharStringView const&);
    template WideString operator+(const wchar_t*, WideStringView const&);
    template Utf8String operator+(const char8_t*, Utf8StringView const&);
    template String operator+(const char16_t*, StringView const&);
    template Utf32String operator+(const char32_t*, Utf32StringView const&);
}
