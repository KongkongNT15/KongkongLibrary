//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::IMPLEMENTATION
{
    constinit StringView AsciiEncoding::s_encodingName = StringView::FromLiteral(u"US-ASCII");

    Collections::Turbo::FastArray<uint8_t> AsciiEncoding::GetBytesUnsafe(ssize_t length, const char16_t* str) const
    {
        Collections::Turbo::FastArray<uint8_t> arr(length);

        char16_t c;
        auto p = arr.begin();
        auto e = arr.end();

        while (p != e) {
            c = *str;

            if (c > '\u007F') [[unlikely]] *p = '?';
            else *p = (uint8_t)c;

            ++p;
            ++str;
        }

        return arr;
    }

    String AsciiEncoding::GetStringUnsafe(ssize_t length, const void* str) const
    {
        ssize_t capacity = length + 1;
        char16_t* p = String::AllocMemoryUnsafe(length + 1);

        const uint8_t* pc = (const uint8_t*)str;
        const uint8_t* e = pc + length;
        char16_t* p1 = p;
        uint8_t c;

        while (pc != e) {
            c = *pc;

            if (c > '\u007F') [[unlikely]] *p1 = u'?';
            else *p1 = c;

            ++p1;
            ++pc;
        }

        *p1 = u'\0';

        return String::WrapUnsafe(capacity, length, p);
    }

    Utf8String AsciiEncoding::GetUtf8StringUnsafe(ssize_t length, const void* str) const
    {
        ssize_t capacity = length + 1;
        char8_t* p = Utf8String::AllocMemoryUnsafe(length + 1);

        const uint8_t* pc = (const uint8_t*)str;
        const uint8_t* e = pc + length;
        char8_t* p1 = p;
        uint8_t c;

        while (pc != e) {
            c = *pc;

            if (c > '\u007F') [[unlikely]] *p1 = u8'?';
            else *p1 = c;

            ++p1;
            ++pc;
        }

        *p1 = u'\0';

        return Utf8String::WrapUnsafe(capacity, length, p);
    }
}

namespace KONGKONG_NAMESPACE::Text
{
    AsciiEncoding::AsciiEncoding() : Encoding(nullptr)
    {
        _setInstance(NEW ImplType());
    }
}