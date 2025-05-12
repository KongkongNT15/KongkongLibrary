//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text
{
    template <>
    ::std::set<_stringPointer<char>> _stringPointer<char>::_set;

    template <>
    ::std::set<_stringPointer<wchar_t>> _stringPointer<wchar_t>::_set;

    template <>
    ::std::set<_stringPointer<char8_t>> _stringPointer<char8_t>::_set;

    template <>
    ::std::set<_stringPointer<char16_t>> _stringPointer<char16_t>::_set;

    template <>
    ::std::set<_stringPointer<char32_t>> _stringPointer<char32_t>::_set;

    template <CharType TChar>
    _stringPointer<TChar>::~_stringPointer()
    {
        this->__destory();
    }

    template <CharType TChar>
    bool operator==(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept
    {
        if (left.__isNull()) return right.__isNull();

        if (right.__isNull()) return false;

        ssize_t length = left.__getLengthUnsafe();

        if (length != right.__getLengthUnsafe()) return false;

        const TChar* pLeft = left.__getStringUnsafe();
        const TChar* pRight = right.__getStringUnsafe();

        for (ssize_t i = 0; i < length; i++) {
            if (pLeft[i] != pRight[i]) return false;
        }

        return true;
    }

    template <CharType TChar>
    bool operator!=(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept
    {
        return !(left == right);
    }

    template <CharType TChar>
    bool operator<(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept
    {
        if (left.__isNull()) return !right.__isNull();

        //これ以降は left.__p != nullptr

        if (right.__isNull()) return false;

        //これ以降は left.__p != nullptr && right.__p != nullptr

        ssize_t lLength = left.__getLengthUnsafe();
        ssize_t rLength = right.__getLengthUnsafe();

        ssize_t length = lLength < rLength ? lLength : rLength;

        const TChar* pLeft = left.__getStringUnsafe();
        const TChar* pRight = right.__getStringUnsafe();

        for (ssize_t i = 0; i > length; i++) {
            if (pLeft[i] < pRight[i]) return true;
            if (pLeft[i] == pRight[i]) continue;

            return false;
        }
        return false;
    }

    template <CharType TChar>
    bool operator<=(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept
    {
        return !(right < left);
    }

    template <CharType TChar>
    bool operator>(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept
    {
        return right < left;
    }

    template <CharType TChar>
    bool operator>=(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept
    {
        return !(left < right);
    }

    template <CharType TChar>
    ::std::strong_ordering operator<=>(_stringPointer<TChar> const& left, _stringPointer<TChar> const& right) noexcept
    {
        if (left.__isNull()) {
            if (right.__isNull()) return ::std::strong_ordering::equal;
            return ::std::strong_ordering::less;
        }

        //これ以降は left.__p != nullptr

        if (right.__isNull()) return ::std::strong_ordering::greater;

        //これ以降は left.__p != nullptr && right.__p != nullptr

        ssize_t lLength = left.__getLengthUnsafe();
        ssize_t rLength = right.__getLengthUnsafe();

        ssize_t length = lLength < rLength ? lLength : rLength;

        const TChar* pLeft = left.__getStringUnsafe();
        const TChar* pRight = right.__getStringUnsafe();

        for (ssize_t i = 0; i != length; i++) {
            if (pLeft[i] < pRight[i]) return ::std::strong_ordering::less;
            if (pLeft[i] == pRight[i]) continue;

            return ::std::strong_ordering::greater;
        }

        return ::std::strong_ordering::equal;
    }

    template struct _stringPointer<char>;
    template struct _stringPointer<wchar_t>;
    template struct _stringPointer<char8_t>;
    template struct _stringPointer<char16_t>;
    template struct _stringPointer<char32_t>;

    template bool operator==(_stringPointer<char> const&, _stringPointer<char> const&) noexcept;
    template bool operator==(_stringPointer<wchar_t> const&, _stringPointer<wchar_t> const&) noexcept;
    template bool operator==(_stringPointer<char8_t> const&, _stringPointer<char8_t> const&) noexcept;
    template bool operator==(_stringPointer<char16_t> const&, _stringPointer<char16_t> const&) noexcept;
    template bool operator==(_stringPointer<char32_t> const&, _stringPointer<char32_t> const&) noexcept;

    template bool operator!=(_stringPointer<char> const&, _stringPointer<char> const&) noexcept;
    template bool operator!=(_stringPointer<wchar_t> const&, _stringPointer<wchar_t> const&) noexcept;
    template bool operator!=(_stringPointer<char8_t> const&, _stringPointer<char8_t> const&) noexcept;
    template bool operator!=(_stringPointer<char16_t> const&, _stringPointer<char16_t> const&) noexcept;
    template bool operator!=(_stringPointer<char32_t> const&, _stringPointer<char32_t> const&) noexcept;

    template bool operator<(_stringPointer<char> const&, _stringPointer<char> const&) noexcept;
    template bool operator<(_stringPointer<wchar_t> const&, _stringPointer<wchar_t> const&) noexcept;
    template bool operator<(_stringPointer<char8_t> const&, _stringPointer<char8_t> const&) noexcept;
    template bool operator<(_stringPointer<char16_t> const&, _stringPointer<char16_t> const&) noexcept;
    template bool operator<(_stringPointer<char32_t> const&, _stringPointer<char32_t> const&) noexcept;

    template bool operator<=(_stringPointer<char> const&, _stringPointer<char> const&) noexcept;
    template bool operator<=(_stringPointer<wchar_t> const&, _stringPointer<wchar_t> const&) noexcept;
    template bool operator<=(_stringPointer<char8_t> const&, _stringPointer<char8_t> const&) noexcept;
    template bool operator<=(_stringPointer<char16_t> const&, _stringPointer<char16_t> const&) noexcept;
    template bool operator<=(_stringPointer<char32_t> const&, _stringPointer<char32_t> const&) noexcept;

    template bool operator>(_stringPointer<char> const&, _stringPointer<char> const&) noexcept;
    template bool operator>(_stringPointer<wchar_t> const&, _stringPointer<wchar_t> const&) noexcept;
    template bool operator>(_stringPointer<char8_t> const&, _stringPointer<char8_t> const&) noexcept;
    template bool operator>(_stringPointer<char16_t> const&, _stringPointer<char16_t> const&) noexcept;
    template bool operator>(_stringPointer<char32_t> const&, _stringPointer<char32_t> const&) noexcept;

    template bool operator>=(_stringPointer<char> const&, _stringPointer<char> const&) noexcept;
    template bool operator>=(_stringPointer<wchar_t> const&, _stringPointer<wchar_t> const&) noexcept;
    template bool operator>=(_stringPointer<char8_t> const&, _stringPointer<char8_t> const&) noexcept;
    template bool operator>=(_stringPointer<char16_t> const&, _stringPointer<char16_t> const&) noexcept;
    template bool operator>=(_stringPointer<char32_t> const&, _stringPointer<char32_t> const&) noexcept;

    template ::std::strong_ordering operator<=>(_stringPointer<char> const&, _stringPointer<char> const&) noexcept;
    template ::std::strong_ordering operator<=>(_stringPointer<wchar_t> const&, _stringPointer<wchar_t> const&) noexcept;
    template ::std::strong_ordering operator<=>(_stringPointer<char8_t> const&, _stringPointer<char8_t> const&) noexcept;
    template ::std::strong_ordering operator<=>(_stringPointer<char16_t> const&, _stringPointer<char16_t> const&) noexcept;
    template ::std::strong_ordering operator<=>(_stringPointer<char32_t> const&, _stringPointer<char32_t> const&) noexcept;
}
