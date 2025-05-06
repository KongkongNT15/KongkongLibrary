//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::IMPLEMENTATION
{
    Encoding::ProjType Encoding::GetEncoding(int32_t codePage)
    {
        switch (codePage) {
            case AsciiEncoding::s_codePage: return AsciiEncoding::ProjType();

            default: [[unlikely]]
            {
                if (codePage < 0) throw InvalidArgumentException(u"無効なコードページです");
                if (65535 < codePage) throw ArgumentOutOfRangeException(u"コードページの範囲外の値が指定されましtあ");
                throw ArgumentException(u"このコードページはサポートされていません");
            }
        }

#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif
    }

    ssize_t Encoding::GetByteCount(const char16_t* str) const
    {
        ArgumentNullException::CheckNull(str, u"str");
        return GetByteCountUnsafe(str);
    }

    ssize_t Encoding::GetByteCount(ssize_t length, const char16_t* str) const
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return GetByteCountUnsafe(length, str);
    }

    ssize_t Encoding::GetByteCount(String const& str) const noexcept
    {
        return GetByteCountUnsafe(str.Length(), str.c_str());
    }

    ssize_t Encoding::GetByteCount(StringView const& str) const noexcept
    {
        return GetByteCountUnsafe(str.Length(), str.c_str());
    }

    ssize_t Encoding::GetByteCount(Collections::Array<char16_t> const& chars) const
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetByteCountUnsafe(ref.Length(), ref.Data());
    }

    ssize_t Encoding::GetByteCount(Collections::ArrayList<char16_t> const& chars) const
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetByteCountUnsafe(ref.Length(), ref.Data());
    }

    ssize_t Encoding::GetByteCount(Collections::Turbo::FastArray<char16_t> const& chars) const noexcept
    {
        return GetByteCountUnsafe(chars.Length(), chars.Data());
    }

    ssize_t Encoding::GetByteCount(Collections::Turbo::FastArrayList<char16_t> const& chars) const noexcept
    {
        return GetByteCountUnsafe(chars.Length(), chars.Data());
    }

    ssize_t Encoding::GetByteCountUnsafe(const char16_t* str) const noexcept
    {
        return GetByteCount(StringHelper::GetLengthUnsafe(str), str);
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytes(const char16_t* str) const
    {
        ArgumentNullException::CheckNull(str, u"str");
        return GetBytesUnsafe(str);
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytes(ssize_t length, const char16_t* str) const
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(str, u"str");

        return GetBytesUnsafe(length, str);
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytes(String const& str) const
    {
        return GetBytesUnsafe(str.Length(), str.c_str());
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytes(StringView const& str) const
    {
        return GetBytesUnsafe(str.Length(), str.c_str());
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytes(Collections::Array<char16_t> const& chars) const
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetBytesUnsafe(ref.Length(), ref.Data());
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytes(Collections::ArrayList<char16_t> const& chars) const
    {
        auto& ref = Object::GetInstance(chars, u"chars");

        return GetBytesUnsafe(ref.Length(), ref.Data());
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytes(Collections::Turbo::FastArray<char16_t> const& chars) const
    {
        return GetBytesUnsafe(chars.Length(), chars.Data());
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytes(Collections::Turbo::FastArrayList<char16_t> const& chars) const
    {
        return GetBytesUnsafe(chars.Length(), chars.Data());
    }

    Collections::Turbo::FastArray<uint8_t> Encoding::GetBytesUnsafe(const char16_t* str) const
    {
        return GetBytes(StringHelper::GetLengthUnsafe(str), str);
    }

    String Encoding::GetString(const void* bytes) const
    {
        ArgumentNullException::CheckNull(bytes, u"bytes");
        return GetStringUnsafe(bytes);
    }

    String Encoding::GetString(ssize_t length, const void* bytes) const
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(bytes, u"bytes");

        return GetStringUnsafe(length, bytes);
    }

    String Encoding::GetString(Collections::Array<uint8_t> const& bytes)
    {
        auto& ref = Object::GetInstance(bytes, u"bytes");

        return GetStringUnsafe(ref.Length(), ref.Data());
    }

    String Encoding::GetString(Collections::ArrayList<uint8_t> const& bytes)
    {
        auto& ref = Object::GetInstance(bytes, u"bytes");

        return GetStringUnsafe(ref.Length(), ref.Data());
    }

    String Encoding::GetString(Collections::Turbo::FastArray<uint8_t> const& bytes)
    {
        return GetStringUnsafe(bytes.Length(), bytes.Data());
    }

    String Encoding::GetString(Collections::Turbo::FastArrayList<uint8_t> const& bytes)
    {
        return GetStringUnsafe(bytes.Length(), bytes.Data());
    }

    String Encoding::GetStringUnsafe(const void* bytes) const
    {
        return GetStringUnsafe(StringHelper::GetLengthUnsafe((const char*)bytes), bytes);
    }

    Utf8String Encoding::GetUtf8String(const void* bytes) const
    {
        ArgumentNullException::CheckNull(bytes, u"bytes");
        return GetUtf8StringUnsafe(bytes);
    }

    Utf8String Encoding::GetUtf8String(ssize_t length, const void* bytes) const
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(bytes, u"bytes");

        return GetUtf8StringUnsafe(length, bytes);
    }

    Utf8String Encoding::GetUtf8String(Collections::Array<uint8_t> const& bytes)
    {
        auto& ref = Object::GetInstance(bytes, u"bytes");

        return GetUtf8StringUnsafe(ref.Length(), ref.Data());
    }

    Utf8String Encoding::GetUtf8String(Collections::ArrayList<uint8_t> const& bytes)
    {
        auto& ref = Object::GetInstance(bytes, u"bytes");

        return GetUtf8StringUnsafe(ref.Length(), ref.Data());
    }

    Utf8String Encoding::GetUtf8String(Collections::Turbo::FastArray<uint8_t> const& bytes)
    {
        return GetUtf8StringUnsafe(bytes.Length(), bytes.Data());
    }

    Utf8String Encoding::GetUtf8String(Collections::Turbo::FastArrayList<uint8_t> const& bytes)
    {
        return GetUtf8StringUnsafe(bytes.Length(), bytes.Data());
    }

    Utf8String Encoding::GetUtf8StringUnsafe(const void* bytes) const
    {
        return GetUtf8StringUnsafe(StringHelper::GetLengthUnsafe((const char*)bytes), bytes);
    }
}