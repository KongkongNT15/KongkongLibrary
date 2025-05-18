//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    template <class TChar> requires CharType<TChar>
    TChar* GenericString<TChar>::AllocMemory(ssize_t capacity)
    {
        if (capacity <= 0) [[unlikely]] throw InvalidArgumentException(u"要素数にゼロ以下が指定されました");

        return AllocMemoryUnsafe(capacity);
    }

    template <class TChar> requires CharType<TChar>
    TChar* GenericString<TChar>::AllocMemoryUnsafe(ssize_t capacity)
    {
        TChar* p = (TChar*)::malloc(capacity * sizeof(ElementSize()));

        MemoryAllocationException::CheckNull(p);

        return p;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::CreateWithCapacity(ssize_t capacity)
    {
        TChar* p = AllocMemory(capacity);

        *p = (TChar)'\0';

        return WrapUnsafe(capacity, 0, p);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::CreateWithCapacityUnsafe(ssize_t capacity)
    {
        TChar* p = AllocMemoryUnsafe(capacity);

        *p = (TChar)'\0';
        
        return WrapUnsafe(capacity, 0, p);
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::FreeMemory(TChar* memoryBlock)
    {
        ArgumentNullException::CheckNull(memoryBlock, u"memoryBlock");

        FreeMemoryUnsafe(memoryBlock);
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::FreeMemoryUnsafe(TChar* memoryBlock) noexcept
    {
        ::free(memoryBlock);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromAscii(const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        return FromAsciiUnsafe((ssize_t)::strlen(str), str);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromAscii(ssize_t length, const char* str)
    {
        ArgumentNullException::CheckNull(str, u"str");

        if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"文字列の長さにゼロ以下の値が指定されました");
        
        ssize_t len = (ssize_t)::strlen(str);

        if (length > len) [[unlikely]] throw InvalidArgumentException(u"lengthがstrの長さを超えています");

        return FromAsciiUnsafe(length, str);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromAsciiUnsafe(const char* str)
    {
        return FromAsciiUnsafe((ssize_t)::strlen(str), str);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromAsciiUnsafe(ssize_t length, const char* str)
    {
        ssize_t capacity = length + 1;
        TChar* p = AllocMemoryUnsafe(capacity);

        for (ssize_t i = 0; i < length; i++) {
            p[i] = (TChar)str[i];
        }

        p[length] = (TChar)'\0';

        return GenericString<TChar>(p, capacity, length, 0);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromAscii(std::string const& str)
    {
        return FromAsciiUnsafe(str.size(), str.data());
    }

#if 0
    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromChar(char c, bool isFited)
    {
        return FromChar((char16_t)c, isFited);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromChar(char8_t c, bool isFited)
    {
        return FromChar((char16_t)c, isFited);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromChar(char16_t c, bool isFited)
    {
        constexpr ssize_t length = 1;
        ssize_t capacity = isFited ? 2 : _createCapacity(length);

        TChar* p = AllocMemoryUnsafe(capacity);
        p[0] = c;
        p[1] = (TChar)'\0';

        return WrapUnsafe(capacity, length, p);
    }

#endif //0

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromCStrings(const TChar* left, const TChar* right, bool isFited)
    {
        ArgumentNullException::CheckNull(left, u"left");
        ArgumentNullException::CheckNull(right, u"right");

        ssize_t lLength = Text::StringHelper::GetLengthUnsafe(left);
        ssize_t rLength = Text::StringHelper::GetLengthUnsafe(right);

        ssize_t length = lLength + rLength;

        ssize_t capacity = isFited ? (length + 1) : _createCapacity(length);

        TChar* p = AllocMemory(capacity);

        ::memcpy(p, left, lLength * ElementSize());
        ::memcpy(p + lLength, right, rLength * ElementSize());

        p[length] = (TChar)'\0';

        return GenericString<TChar>(p, capacity, length, 0);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromPointerUnsafe(const TChar* p, bool isFited)
    {
        return FromPointerUnsafe(Text::StringHelper::GetLengthUnsafe(p), p, isFited);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::FromPointerUnsafe(ssize_t length, const TChar* p, bool isFited)
    {
        ssize_t capacity = isFited ? length + 1 : _createCapacity(length);

        TChar* block = AllocMemoryUnsafe(capacity);

        ::memcpy(block, p, length * ElementSize());

        block[length] = (TChar)'\0';

        return GenericString<TChar>(block, capacity, length, 0);
    }

    template <>
    CharString CharString::ValueOf(bool value)
    {
        return value ? FromLiteral("true") : FromLiteral("false");
    }

    template <>
    WideString WideString::ValueOf(bool value)
    {
        return value ? FromLiteral(L"true") : FromLiteral(L"false");
    }

    template <>
    Utf8String Utf8String::ValueOf(bool value)
    {
        return value ? FromLiteral(u8"true") : FromLiteral(u8"false");
    }

    template <>
    String String::ValueOf(bool value)
    {
        return value ? FromLiteral(u"true") : FromLiteral(u"false");
    }

    template <>
    Utf32String Utf32String::ValueOf(bool value)
    {
        return value ? FromLiteral(U"true") : FromLiteral(U"false");
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(signed char value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(short value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(int value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(long value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(long long value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(unsigned char value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(unsigned short value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(unsigned int value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(unsigned long value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(unsigned long long value)
    {
        return _valueOfInteger(value);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(float value)
    {
        std::ostringstream sout;
        sout << value;

        return FromAscii(sout.str());
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(double value)
    {
        std::ostringstream sout;
        sout << value;

        return FromAscii(sout.str());
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(long double value)
    {
        std::ostringstream sout;
        sout << value;

        return FromAscii(sout.str());
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::ValueOf(const void* value)
    {
        constexpr size_t pointerSize = sizeof(void*) * 2;
        // + 2: "0x"の部分
        // + 1: Null文字用
        constexpr size_t bufferSize = pointerSize + 2 + 1;
        char str[bufferSize];
        const char* format;

        if constexpr (pointerSize == 2) format = "0x%02zx";
        else if constexpr (pointerSize == 4) format = "0x%04zx";
        else if constexpr (pointerSize == 8) format = "0x%08zx";
        else if constexpr (pointerSize == 16) format = "0x%016zx";
        else if constexpr (pointerSize == 32) format = "0x%032zx";
        else if constexpr (pointerSize == 64) format = "0x%064zx";
        else if constexpr (pointerSize == 128) format = "0x%0128zx";

        ::snprintf(str, bufferSize, format, (size_t)value);

        return FromAsciiUnsafe(bufferSize - 1, str);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::Wrap(ssize_t capacity, TChar* p)
    {
        if (capacity <= 0) [[unlikely]] throw InvalidArgumentException(u"容量がゼロ以下でした");
        ArgumentNullException::CheckNull(p, u"p");

        ssize_t length = -1;

        for (ssize_t i = 0; i < capacity; i++) {
            if (p[i] == (TChar)'\0') {
                length = i;
                break;
            }
        }

        if (length == -1) [[unlikely]] throw InvalidArgumentException(u"文字列がnullで終了しませんでした");

        return WrapUnsafe(capacity, length, p);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::WrapUnsafe(ssize_t capacity, TChar* p) noexcept
    {
        ssize_t length = -1;

        for (ssize_t i = 0; i < capacity; i++) {
            if (p[i] == (TChar)'\0') {
                length = i;
                break;
            }
        }

        if (length == -1) [[unlikely]] {
            length = capacity - 1;
            p[length] = (TChar)'\0';
        }

        return GenericString<TChar>(p, capacity, length, 0);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::Wrap(ssize_t capacity, ssize_t length, TChar* p)
    {
        ArgumentNullException::CheckNull(p, u"p");
        if (length + 1 > capacity) [[unlikely]] throw ArgumentOutOfRangeException(u"length + 1がcapacityを超えました");
        p[length] = (TChar)'\0';

        return GenericString<TChar>(p, capacity, length, 0);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::WrapUnsafe(ssize_t capacity, ssize_t length, TChar* p) noexcept
    {
        return GenericString<TChar>(p, capacity, length, 0);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(bool isFited) : _p(nullptr), _length(0), _capacity(_defaultCapacity)
    {
        TChar* p;
        if (isFited) {
            p = AllocMemoryUnsafe(1);
            _capacity = 1;
        }
        else {
            p = AllocMemoryUnsafe(_defaultCapacity);
        }

        *p = (TChar)'\0';
        _p = p;
        
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(GenericString<TChar> const& right, bool isFited) : GenericString(GenericStringView<TChar>(right), isFited)
    {
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(std::basic_string<TChar, std::char_traits<TChar>> const& right, bool isFited) : GenericString(GenericStringView<TChar>(right), isFited)
    {
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(GenericStringView<TChar> const& right, bool isFited) : 
        _p(nullptr),
        _capacity(isFited ? right.Length() + 1 : (((right.Length() + 1) / _defaultCapacity) + 1) * _defaultCapacity),
        _length(right.Length())
    {
        _p = AllocMemoryUnsafe(_capacity);

        ssize_t length = right.Length();

        for (ssize_t i = 0; i < length; i++) {
            _p[i] = right[i];
        }

        _setEndNull();
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(const TChar* p, bool isFited) : GenericString(GenericStringView<TChar>(p), isFited)
    {
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(ssize_t length, TChar c, bool isFited) : _p(nullptr), _length(length), _capacity(0)
    {
        if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"文字数にゼロ以下が指定されました");

        _capacity = isFited ? length + 1 : _createCapacity(length);

        _p = AllocMemoryUnsafe(_capacity);

        for (TChar& element : *this) {
            element = c;
        }

        _setEndNull();
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(ssize_t length, const TChar* p, bool isFited) : GenericString(GenericStringView<TChar>(length, p), isFited)
    {
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(const char* right) requires std::same_as<TChar, char16_t> : GenericString(0)
    {
        ArgumentNullException::CheckNull(right, u"right");
        
        std::string_view view(right, ::strlen(right));

        *this = GenericString<TChar>(view);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(std::string_view const& right) requires std::same_as<TChar, char16_t> : _p(nullptr), _length(0), _capacity(0)
    {
#if KONGKONG_ENV_WINDOWS

        size_t length = right.length() + 1;

        TChar* wcs = AllocMemoryUnsafe(length);

        if (::MultiByteToWideChar(CP_ACP, 0, right.data(), (int)right.size(), (wchar_t*)wcs, (int)length) == 0) [[unlikely]] throw InvalidArgumentException(EXCEPTION_MESSAGE);

        _p = wcs;
        _capacity = length;
        _length = Text::StringHelper::GetLengthUnsafe(wcs);

#else

        //UNIXのcharはutf8

        std::filesystem::path p = right;

        *this = p.generic_u16string();

#endif //
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::GenericString(std::string const& right) requires std::same_as<TChar, char16_t> : GenericString<TChar>(std::string_view(right.c_str(), right.size()))
    {
    }
    

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::~GenericString()
    {
        if (_p != nullptr) _finalize();
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>& GenericString<TChar>::operator=(GenericString<TChar> const& right)
    {
        return operator=(GenericStringView<TChar>(right));
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>& GenericString<TChar>::operator=(GenericString<TChar>&& right) noexcept
    {
        _finalize();

        _p = right._p;
        _capacity = right._capacity;
        _length = right._length;

        right._p = nullptr;

        return *this;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>& GenericString<TChar>::operator=(GenericStringView<TChar> const& view)
    {
        if (view.Length() > _length) {
            ssize_t newCapacity = _createCapacity(view.Length());

            TChar* tmp = AllocMemoryUnsafe(newCapacity);

            _finalize();

            _p = tmp;
        }

        _length = view.Length();

        for (ssize_t i = 0; i < _length; i++) {
            _p[i] = view[i];
        }

        _setEndNull();

        return *this;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>& GenericString<TChar>::operator=(const TChar* p)
    {
        return operator=(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>& GenericString<TChar>::operator=(std::basic_string<TChar, std::char_traits<TChar>> const& u16str)
    {
        return operator=(GenericStringView<TChar>(u16str));
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>::operator std::basic_string<TChar, std::char_traits<TChar>>() const
    {
        return std::basic_string<TChar, std::char_traits<TChar>>(_p, (size_t)_length);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>& GenericString<TChar>::operator+=(const TChar* p)
    {
        Append(p);

        return *this;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>& GenericString<TChar>::operator+=(GenericStringView<TChar> const& right)
    {
        try {
            Append(right);
        }
        catch (ArgumentNullException) {
            ArgumentNullException::ThrowWithName(u"right");
        }

        return *this;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar>& GenericString<TChar>::operator+=(GenericString<TChar> const& right)
    {
        Append(right);

        return *this;
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Append(TChar c)
    {
        _increaseCapacity(1);

        BackUnsafe() = c;
        
        _setEndNull();
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Append(const TChar* p)
    {
        ArgumentNullException::CheckNull(p, u"p");
        ssize_t length = Text::StringHelper::GetLengthUnsafe(p);

        AppendUnsafe(length, p);
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Append(ssize_t count, TChar c)
    {
        if (count <= 0) [[unlikely]] throw InvalidArgumentException(u"追加する文字数は正の値にする必要があります");
        
        AppendUnsafe(count, c);
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Append(ssize_t length, const TChar* p)
    {
        ArgumentNullException::CheckNull(p, u"p");
        if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"追加する文字数は正の値にする必要があります");

        ssize_t len = Text::StringHelper::GetLengthUnsafe(p);
    
        AppendUnsafe(length < len ? length : len, p);
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Append(GenericStringView<TChar> const& value)
    {
        AppendUnsafe(value.Length(), value.c_str());
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Append(GenericString<TChar> const& value)
    {
        AppendUnsafe(value.Length(), value.c_str());
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::AppendNewLine()
    {
#if KONGKONG_ENV_WINDOWS
        constexpr TChar newLine[]{ (TChar)'\r', (TChar)'\n' };
        AppendUnsafe(2, newLine);
#elif KONGKONG_ENV_UNIX
        Append((TChar)'\n');
#else
        Append((TChar)'\n');
#endif
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::AppendUnsafe(ssize_t count, TChar c)
    {
        ssize_t i = _length;
        _increaseCapacity(count);

        for (; i < _length; i++) {
            _p[i] = c;
        }

        _setEndNull();
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::AppendUnsafe(const TChar* p)
    {
        return AppendUnsafe(Text::StringHelper::GetLengthUnsafe(p), p);
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::AppendUnsafe(ssize_t length, const TChar* p)
    {
        ssize_t oldLength = _length;
        _increaseCapacity(length);

        for (ssize_t i = 0; i < length; i++) {
            _p[i + oldLength] = p[i];
        }

        _setEndNull();
    }

    template <class TChar> requires CharType<TChar>
    TChar& GenericString<TChar>::At(ssize_t index)
    {
        Collections::CollectionHelper::CheckIndex(index, _length);
        return _p[index];
    }

    template <class TChar> requires CharType<TChar>
    const TChar& GenericString<TChar>::At(ssize_t index) const
    {
        Collections::CollectionHelper::CheckIndex(index, _length);
        return _p[index];
    }

    template <class TChar> requires CharType<TChar>
    TChar& GenericString<TChar>::Back()
    {
        InvalidOperationException::CheckZeroLength(_length);

        return BackUnsafe();
    }

    template <class TChar> requires CharType<TChar>
    TChar const& GenericString<TChar>::Back() const
    {
        InvalidOperationException::CheckZeroLength(_length);

        return BackUnsafe();
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Capacity(ssize_t capacity)
    {
        if (capacity <= 0) [[unlikely]] throw InvalidArgumentException(u"容量にゼロ以下が指定されました");

        SetCapacityUnsafe(capacity);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::Contains(TChar c) const noexcept
    {
        return Text::StringHelper::ContainsUnsafe(_length, _p, c);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::Contains(const TChar* p) const
    {
        return Contains(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::Contains(GenericStringView<TChar> const& view) const
    {
        return Text::StringHelper::ContainsUnsafe(_length, _p, view._length, view._p);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::Contains(GenericString<TChar> const& value) const noexcept
    {
        return Text::StringHelper::ContainsUnsafe(_length, _p, value._length, value._p);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::EndsWith(TChar c) const noexcept
    {
        return Text::StringHelper::EndsWithUnsafe(_length, _p, c);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::EndsWith(const TChar* p) const
    {
        return EndsWith(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::EndsWith(GenericStringView<TChar> const& view) const noexcept
    {
        return Text::StringHelper::EndsWithUnsafe(_length, _p, view._length, view._p);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::EndsWith(GenericString<TChar> const& value) const noexcept
    {
        return Text::StringHelper::EndsWithUnsafe(_length, _p, value._length, value._p);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericString<TChar>::Find(TChar c) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length, _p, c);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericString<TChar>::Find(const TChar* p) const
    {
        return Find(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericString<TChar>::Find(GenericStringView<TChar> const& view) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length, _p, view._length, view._p);
    }

    template <class TChar> requires CharType<TChar>
    ssize_t GenericString<TChar>::Find(GenericString<TChar> const& value) const noexcept
    {
        return Text::StringHelper::FindUnsafe(_length, _p, value._length, value._p);
    }

    template <class TChar> requires CharType<TChar>
    TChar& GenericString<TChar>::Front()
    {
        InvalidOperationException::CheckZeroLength(_length);

        return *_p;
    }

    template <class TChar> requires CharType<TChar>
    TChar const& GenericString<TChar>::Front() const
    {
        InvalidOperationException::CheckZeroLength(_length);

        return *_p;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::Replace(GenericStringView<TChar> const& oldValue, GenericStringView<TChar> const& newValue) const
    {
        GenericString<TChar> str;

        GenericStringView<TChar> view = *this;

        ssize_t index = 0;
        ssize_t indexNext;

        while (true) {
            indexNext = view.FindUnsafe(oldValue, index);

            //元の文字列の一部
            //str.Append(tmpstr.substr(index, indexNext - index));
            str.Append(indexNext - index, view.c_str() + index);

            //置き換えた衣装が見つからなかったら終了
            if (indexNext == GenericStringView<TChar>::NotFound()) break;

            //置き換え
            str.Append(newValue);

            index = indexNext + oldValue.Length();
        }

        return str;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::Replace(GenericStringView<TChar> const& oldValue, TChar newValue) const
    {
        GenericString<TChar> str;

        GenericStringView<TChar> view = *this;

        size_t index = 0;
        size_t indexNext;

        while (true) {
            indexNext = view.FindUnsafe(oldValue, index);

            //元の文字列の一部
            //str.Append(tmpstr.substr(index, indexNext - index));
            str.Append(indexNext - index, view.c_str() + index);

            //置き換えた衣装が見つからなかったら終了
            if (indexNext == GenericStringView<TChar>::NotFound()) break;

            //置き換え
            str.Append(newValue);

            index = indexNext + oldValue.Length();
        }

        return str;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::Replace(TChar oldValue, GenericStringView<TChar> const& newValue) const
    {
        GenericString<TChar> str;

        GenericStringView<TChar> view = *this;

        size_t index = 0;
        size_t indexNext;

        while (true) {
            indexNext = view.FindUnsafe(oldValue, index);

            //元の文字列の一部
            //str.Append(tmpstr.substr(index, indexNext - index));
            str.Append(indexNext - index, view.c_str() + index);

            //置き換えた衣装が見つからなかったら終了
            if (indexNext == GenericStringView<TChar>::NotFound()) break;

            //置き換え
            str.Append(newValue);

            index = indexNext + 1;
        }

        return str;
    }
        

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::Replace(TChar oldValue, TChar newValue) const
    {   
        GenericString<TChar> str = *this;

        for (ssize_t i = 0; i < _length; ++i) {
            if (str[i] == oldValue) str[i] = newValue;
        }

        return str;
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::RemoveBack()
    {
        if (_length == 0) [[unlikely]] throw InvalidOperationException(u"要素数はすでにゼロです");
        RemoveBackUnsafe();
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Resize(ssize_t newLength)
    {
        Resize(newLength, (TChar)'\0');
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::Resize(ssize_t newLength, TChar c)
    {
        if (newLength < 0) [[unlikely]] throw InvalidArgumentException(u"文字列の長さに長さに負の値が指定されました");
    
        ResizeUnsafe(newLength, c);
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::ResizeUnsafe(ssize_t newLength)
    {
        ResizeUnsafe(newLength, (TChar)'\0');
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::ResizeUnsafe(ssize_t newLength, TChar c)
    {
        if (newLength < _length) {
            _length = newLength;

            _setEndNull();
        }
        else {
            AppendUnsafe(newLength - _length, c);
        }
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::SetCapacityUnsafe(ssize_t capacity)
    {
        TChar* tmp = (TChar*)::realloc(_p, capacity * ElementSize());

        MemoryAllocationException::CheckNull(tmp);

        _p = tmp;

        if (capacity < _capacity) {
            _length = capacity - 1;
            _setEndNull();
        }

        _capacity = capacity;
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::ShrinkToFit()
    {
        ssize_t newCapacity = _length + 1;

        TChar* tmp = (TChar*)::realloc(_p, newCapacity * ElementSize());

        MemoryAllocationException::CheckNull(tmp);

        _p = tmp;
        _capacity = newCapacity;
    }

    template <class TChar> requires CharType<TChar>
    Collections::IArray<GenericString<TChar>> GenericString<TChar>::Split(const TChar* del) const
    {
        return Split(GenericStringView<TChar>(del));
    }

    template <class TChar> requires CharType<TChar>
    Collections::IArray<GenericString<TChar>> GenericString<TChar>::Split(GenericStringView<TChar> const& del) const
    {
        return _splitUnsafe(del);
    }

    template <class TChar> requires CharType<TChar>
    Collections::IArray<GenericString<TChar>> GenericString<TChar>::Split(TChar del) const
    {
        TChar c16s[]{ del, (TChar)'\0' };

        return _splitUnsafe(GenericStringView<TChar>(c16s));
    }

    template <class TChar> requires CharType<TChar>
    Collections::IArray<GenericString<TChar>> GenericString<TChar>::Split(GenericString<TChar> const& del) const
    {
        return _splitUnsafe(GenericStringView<TChar>(del));
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::StartsWith(const TChar* p) const
    {
        return StartsWith(GenericStringView<TChar>(p));
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::StartsWith(GenericStringView<TChar> const& view) const noexcept
    {
        return Text::StringHelper::StartsWithUnsafe(_length, _p, view._length, view._p);
    }

    template <class TChar> requires CharType<TChar>
    bool GenericString<TChar>::StartsWith(GenericString<TChar> const& value) const noexcept
    {
        return Text::StringHelper::StartsWithUnsafe(_length, _p, value._length, value._p);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::SubString(ssize_t count, bool isFited) const
    {
        if (count <= 0) [[unlikely]] throw InvalidArgumentException(u"文字数にゼロ以下の値が指定されました");

        return SubStringUnsafe(0, count, isFited);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::SubString(ssize_t offset, ssize_t count, bool isFited) const
    {
        Collections::CollectionHelper::CheckIndex(offset, _length);
        if (count <= 0) [[unlikely]] throw InvalidArgumentException(u"文字数にゼロ以下の値が指定されました");

        return SubStringUnsafe(offset, count, isFited);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::SubStringUnsafe(ssize_t count, bool isFited) const
    {
        return SubStringUnsafe(0, count, isFited);
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> GenericString<TChar>::SubStringUnsafe(ssize_t offset, ssize_t count, bool isFited) const
    {
        GenericString<TChar> str(0);

        str._length = count;
        str._capacity = isFited ? count + 1 : _createCapacity(count + 1);

        TChar* p = (TChar*)::malloc(str._capacity * ElementSize());

        MemoryAllocationException::CheckNull(p);

        for (ssize_t i = 0; i < count; i++) {
            p[i] = _p[i + offset];
        }

        p[count] = (TChar)'\0';

        str._p = p;

        return str;
    }

    template <class TChar> requires CharType<TChar>
    Collections::Array<TChar> GenericString<TChar>::ToCharArray() const
    {
        Collections::Array<TChar> arr(_length + 1);
        Collections::IMPLEMENTATION::Array<TChar>& ref = Object::GetInstanceUnsafe(arr);

        for (ssize_t i = 0; i < _length; ++i) {
            ref[i] = _p[i];
        }

        ref.BackUnsafe() = (TChar)'\0';

        return arr;
    }

    template <class TChar> requires CharType<TChar>
    Collections::IArray<GenericString<TChar>> GenericString<TChar>::_splitUnsafe(GenericStringView<TChar> const& del) const
    {
        Collections::Turbo::FastArrayList<GenericString<TChar>> vec;
        GenericString<TChar> tmp = *this;
        ssize_t index;
        ssize_t delimiterLength = del.Length();

        while ((index = tmp.Find(del)) != NotFound()) {
            vec.Append(tmp.SubString(index));
            tmp = tmp.SubString(index + delimiterLength, NotFound());
        }
        vec.Append(tmp);

        return Collections::ArrayList<GenericString<TChar>>(std::move(vec));
    }

    template <class TChar> requires CharType<TChar>
    CharString GenericString<TChar>::ToAscii() const
    {
        char* p = CharString::AllocMemoryUnsafe(_length + 1);

        for (ssize_t i = 0; i < _length; i++) {
            p[i] = (char)_p[i];
        }

        p[_length] = '\0';

        return CharString::WrapUnsafe(_length + 1, _length, p);
    }

    template <>
    CharString CharString::ToLower() const
    {
        char* p = AllocMemoryUnsafe(_length + 1);

        for (ssize_t i = 0; i < _length; i++) {
            p[i] = ::tolower(_p[i]);
        }

        p[_length] = '\0';

        return WrapUnsafe(_length + 1, _length, p);
    }

    template <>
    WideString WideString::ToLower() const
    {
        wchar_t* p = AllocMemoryUnsafe(_length + 1);

        for (ssize_t i = 0; i < _length; i++) {
            p[i] = ::towlower(_p[i]);
        }

        p[_length] = L'\0';

        return WrapUnsafe(_length + 1, _length, p);
    }

    template <>
    Utf8String Utf8String::ToLower() const
    {
        char8_t* p = AllocMemoryUnsafe(_length + 1);

        for (ssize_t i = 0; i < _length; i++) {
            p[i] = ::tolower(_p[i]);
        }

        p[_length] = u8'\0';

        return WrapUnsafe(_length + 1, _length, p);
    }

    template <>
    String String::ToLower() const
    {
#if KONGKONG_ENV_WINDOWS
        return Win32::StringHelper::ToLower(*this);
#else
        constexpr char16_t zenkaku = u'ａ' - u'Ａ';
        constexpr char16_t hankaku = u'a' - u'A';

        String str = CreateWithCapacityUnsafe(_length + 1);

        for (char16_t c : *this) {
            if (u'A' <= c && c <= u'Z') str.Append(c + hankaku);
            else if (u'Ａ' <= c && c <= u'Ｚ') str.Append(c + zenkaku);
            else str.Append(c);
        }

        return str;
#endif
    }

    template <>
    Utf32String Utf32String::ToLower() const
    {
        constexpr char32_t zenkaku = U'ａ' - U'Ａ';
        constexpr char32_t hankaku = U'a' - U'A';

        Utf32String str = CreateWithCapacityUnsafe(_length + 1);

        for (char32_t c : *this) {
            if (U'A' <= c && c <= U'Z') str.Append(c + hankaku);
            else if (U'Ａ' <= c && c <= U'Ｚ') str.Append(c + zenkaku);
            else str.Append(c);
        }

        return str;
    }

    template <>
    CharString CharString::ToUpper() const
    {
        char* p = AllocMemoryUnsafe(_length + 1);

        for (ssize_t i = 0; i < _length; i++) {
            p[i] = ::toupper(_p[i]);
        }

        p[_length] = '\0';

        return WrapUnsafe(_length + 1, _length, p);
    }

    template <>
    WideString WideString::ToUpper() const
    {
        wchar_t* p = AllocMemoryUnsafe(_length + 1);

        for (ssize_t i = 0; i < _length; i++) {
            p[i] = ::towupper(_p[i]);
        }

        p[_length] = L'\0';

        return WrapUnsafe(_length + 1, _length, p);
    }

    template <>
    Utf8String Utf8String::ToUpper() const
    {
        char8_t* p = AllocMemoryUnsafe(_length + 1);

        for (ssize_t i = 0; i < _length; i++) {
            p[i] = ::toupper(_p[i]);
        }

        p[_length] = u8'\0';

        return WrapUnsafe(_length + 1, _length, p);
    }

    template <>
    String String::ToUpper() const
    {
#if KONGKONG_ENV_WINDOWS
        return Win32::StringHelper::ToUpper(*this);
#else
        constexpr char16_t zenkaku = u'ａ' - u'Ａ';
        constexpr char16_t hankaku = u'a' - u'A';

        String str = CreateWithCapacityUnsafe(_length + 1);

        for (char16_t c : *this) {
            if (u'a' <= c && c <= u'z') str.Append(c - hankaku);
            else if (u'ａ' <= c && c <= u'ｚ') str.Append(c - zenkaku);
            else str.Append(c);
        }

        return str;
#endif
    }

    template <>
    Utf32String Utf32String::ToUpper() const
    {
        constexpr char32_t zenkaku = U'ａ' - U'Ａ';
        constexpr char32_t hankaku = U'a' - U'A';

        Utf32String str = CreateWithCapacityUnsafe(_length + 1);

        for (char32_t c : *this) {
            if (U'a' <= c && c <= U'z') str.Append(c - hankaku);
            else if (U'ａ' <= c && c <= U'ｚ') str.Append(c - zenkaku);
            else str.Append(c);
        }

        return str;
    }

    template <class TChar> requires CharType<TChar>
    CharString GenericString<TChar>::ToCharString() const
    {
        return Text::StringHelper::ToCharStringUnsafe(_length, _p);
    }

    template <class TChar> requires CharType<TChar>
    String GenericString<TChar>::ToString() const
    {
        return Text::StringHelper::ToStringUnsafe(_length, _p);
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::_increaseCapacity(ssize_t size)
    {
        ssize_t newLength = _length + size;

        if (newLength + 1 > _capacity) {
            ssize_t newCapacity = _createCapacity(newLength);
            

            TChar* tmp = (TChar*)::realloc(_p, newCapacity * ElementSize());

            MemoryAllocationException::CheckNull(tmp);

            _p = tmp;
            _capacity = newCapacity;
   
        }

        _length = newLength;
    }

    template <class TChar> requires CharType<TChar>
    template <class TInt>
    GenericString<TChar> GenericString<TChar>::_valueOfInteger(TInt value)
    {
        GenericString<TChar> result;
        bool isMinus;
        constexpr intmax_t radix = 10;

        if (value == 0) {
            TChar c = (TChar)'0';

            return FromPointerUnsafe(1, &c, false);
        }

        if constexpr (::std::signed_integral<TInt>) {
            if (value < 0) {
                isMinus = true;
                value = value * -1;
            }
            else {
                isMinus = false;
            }
        }

        while (value > 0) {
            result.Append((TChar)(value % radix) + (TChar)'0');
            value /= radix;
        }

        if constexpr (::std::signed_integral<TInt>) {
            if (isMinus) result.Append((TChar)'-');
        }

        ssize_t harfLength = result._length / 2;
        ssize_t length = result._length;
        TChar* p = result._p;

        for (ssize_t i = 0; i < harfLength; i++) {
            TChar tmp = p[i];
            ssize_t iTmp = length - i - 1;
            p[i] = p[iTmp];
            p[iTmp] = tmp;
        }

        return result;
    }

    template <class TChar> requires CharType<TChar>
    void GenericString<TChar>::_finalize() noexcept
    {
        ::free(_p);
    }

    template <class TChar> requires CharType<TChar>
    bool operator==(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept
    {
        if (left.Length() != right.Length()) return false;

        ssize_t length = left.Length();

        for (ssize_t i = 0; i < length; i++) {
            if (left[i] != right[i]) return false;
        }

        return true;
    }

    template <class TChar> requires CharType<TChar>
    bool operator!=(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept
    {
        return !(left == right);
    }

    template <class TChar> requires CharType<TChar>
    bool operator<(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept
    {
        bool isMin = left.Length() < right.Length();
        ssize_t length = isMin ? left.Length() : right.Length();

        for (ssize_t i = 0; i < length; i++) {
            if (left[i] == right[i]) continue;
            if (left[i] < right[i]) return true;
            return false;
        }

        return isMin;
    }

    template <class TChar> requires CharType<TChar>
    bool operator<=(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept
    {
        bool isMin = left.Length() <= right.Length();
        ssize_t length = isMin ? left.Length() : right.Length();

        for (ssize_t i = 0; i < length; i++) {
            if (left[i] == right[i]) continue;
            if (left[i] < right[i]) return true;
            return false;
        }

        return isMin;
    }

    template <class TChar> requires CharType<TChar>
    bool operator>(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept
    {
        return right < left;
    }

    template <class TChar> requires CharType<TChar>
    bool operator>=(GenericString<TChar> const& left, GenericString<TChar> const& right) noexcept
    {
        return right <= left;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar> const& left, GenericString<TChar> const& right)
    {
        GenericString<TChar> str = left;
        str.Append(right);

        return str;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar>&& left, GenericString<TChar> const& right)
    {
        left.Append(right);

        return left;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar> const& left, GenericString<TChar>&& right)
    {
        return left + right;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar>&& left, GenericString<TChar>&& right)
    {
        return std::move(left) + right;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar> const& left, const TChar* right)
    {
        GenericString<TChar> str = left;

        try {
            str.Append(right);
        }
        catch (...) {
            ArgumentNullException::ThrowWithName(u"right");
        }

        return str;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(GenericString<TChar>&& left, const TChar* right)
    {
        try {
            left.Append(right);
        }
        catch (...) {
            ArgumentNullException::ThrowWithName(u"right");
        }

        return left;
    }

    template <class TChar> requires CharType<TChar>
    GenericString<TChar> operator+(const TChar* left, GenericString<TChar> const& right)
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

    String operator+(String const& left, Object const& right)
    {
        Object::ImplType& obj = Object::GetInstance(right, u"right");
        
        return left + obj;
    }

    String operator+(String&& left, Object const& right)
    {
        Object::ImplType& obj = Object::GetInstance(right, u"right");

        return std::move(left) + obj;
    }

    String operator+(Object const& left, String const& right)
    {
        auto& instance = Object::GetInstance(left, u"left");

        return instance + right;
    }

    String operator+(String const& left, IMPLEMENTATION::Object const& right)
    {
        String str = left;

        str.Append(right.ToString());

        return str;
    }

    String operator+(String&& left, IMPLEMENTATION::Object const& right)
    {
        left.Append(right.ToString());

        return left;
    }

    String operator+(IMPLEMENTATION::Object const& left, String const& right)
    {
        String str = left.ToString();

        str.Append(right);

        return str;
    }

    template struct GenericString<char>;
    template struct GenericString<wchar_t>;
    template struct GenericString<char8_t>;
    template struct GenericString<char16_t>;
    template struct GenericString<char32_t>;
    
    template bool operator==(CharString const&, CharString const&);
    template bool operator==(WideString const&, WideString const&);
    template bool operator==(Utf8String const&, Utf8String const&);
    template bool operator==(String const&, String const&);
    template bool operator==(Utf32String const&, Utf32String const&);

    template bool operator!=(CharString const&, CharString const&);
    template bool operator!=(WideString const&, WideString const&);
    template bool operator!=(Utf8String const&, Utf8String const&);
    template bool operator!=(String const&, String const&);
    template bool operator!=(Utf32String const&, Utf32String const&);

    template bool operator<(CharString const&, CharString const&);
    template bool operator<(WideString const&, WideString const&);
    template bool operator<(Utf8String const&, Utf8String const&);
    template bool operator<(String const&, String const&);
    template bool operator<(Utf32String const&, Utf32String const&);

    template bool operator<=(CharString const&, CharString const&);
    template bool operator<=(WideString const&, WideString const&);
    template bool operator<=(Utf8String const&, Utf8String const&);
    template bool operator<=(String const&, String const&);
    template bool operator<=(Utf32String const&, Utf32String const&);

    template bool operator>(CharString const&, CharString const&);
    template bool operator>(WideString const&, WideString const&);
    template bool operator>(Utf8String const&, Utf8String const&);
    template bool operator>(String const&, String const&);
    template bool operator>(Utf32String const&, Utf32String const&);

    template bool operator>=(CharString const&, CharString const&);
    template bool operator>=(WideString const&, WideString const&);
    template bool operator>=(Utf8String const&, Utf8String const&);
    template bool operator>=(String const&, String const&);
    template bool operator>=(Utf32String const&, Utf32String const&);

    template CharString operator+(CharString const&, CharString const&);
    template WideString operator+(WideString const&, WideString const&);
    template Utf8String operator+(Utf8String const&, Utf8String const&);
    template String operator+(String const&, String const&);
    template Utf32String operator+(Utf32String const&, Utf32String const&);

    template CharString operator+(CharString&&, CharString const&);
    template WideString operator+(WideString&&, WideString const&);
    template Utf8String operator+(Utf8String&&, Utf8String const&);
    template String operator+(String&&, String const&);
    template Utf32String operator+(Utf32String&&, Utf32String const&);

    template CharString operator+(CharString const&, CharString&&);
    template WideString operator+(WideString const&, WideString&&);
    template Utf8String operator+(Utf8String const&, Utf8String&&);
    template String operator+(String const&, String&&);
    template Utf32String operator+(Utf32String const&, Utf32String&&);

    template CharString operator+(CharString&&, CharString&&);
    template WideString operator+(WideString&&, WideString&&);
    template Utf8String operator+(Utf8String&&, Utf8String&&);
    template String operator+(String&&, String&&);
    template Utf32String operator+(Utf32String&&, Utf32String&&);

    template CharString operator+(CharString const&, const char*);
    template WideString operator+(WideString const&, const wchar_t*);
    template Utf8String operator+(Utf8String const&, const char8_t*);
    template String operator+(String const&, const char16_t*);
    template Utf32String operator+(Utf32String const&, const char32_t*);

    template CharString operator+(CharString &&, const char*);
    template WideString operator+(WideString &&, const wchar_t*);
    template Utf8String operator+(Utf8String &&, const char8_t*);
    template String operator+(String&&, const char16_t*);
    template Utf32String operator+(Utf32String &&, const char32_t*);

    template CharString operator+(const char*, CharString const&);
    template WideString operator+(const wchar_t*, WideString const&);
    template Utf8String operator+(const char8_t*, Utf8String const&);
    template String operator+(const char16_t*, String const&);
    template Utf32String operator+(const char32_t*, Utf32String const&);
}
