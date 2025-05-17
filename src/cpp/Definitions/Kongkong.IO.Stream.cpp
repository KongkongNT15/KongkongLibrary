//このcppファイルをコンパイルに含めないでください

#define FLUSH_NOT_SUPPORTED String::FromLiteral(u"このストリームはフラッシュできません")
#define IS_CLOSED String::FromLiteral(u"ストリームはすでに閉じられています")
#define READ_NOT_SUPPORTED String::FromLiteral(u"このストリームは読み込みをサポートしていません")
#define SEEK_NOT_SUPPORTED String::FromLiteral(u"このストリームはシークをサポートしていません")
#define WRITE_NOT_SUPPORTED String::FromLiteral(u"このストリームは書き込みをサポートしていません")

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    Stream::~Stream()
    {
        if (!m_isClosed) m_close();
    }

    bool Stream::Close()
    {
        if (m_isClosed) return false;

        m_close();

        return true;
    }

    void Stream::Flush()
    {
        if (!CanWrite()) [[unlikely]] throw NotSupportedException(FLUSH_NOT_SUPPORTED);

        m_flush();
    }

    int64_t Stream::Length() const
    {
        if (m_isClosed) [[unlikely]] throw IOException(IS_CLOSED);

        return GetLengthUnsafe();
    }

    int64_t Stream::Position() const
    {
        if (m_isClosed) [[unlikely]] throw IOException(IS_CLOSED);

        return GetPositionUnsafe();
    }

    ssize_t Stream::Read(ssize_t length, void* buffer)
    {
        Collections::CollectionHelper::CheckLength(length);
        m_checkReadable();

        return ReadUnsafe(length, buffer);
    }

    ssize_t Stream::ReadUnsafe(ssize_t length, void* buffer)
    {
        uint8_t* begin = (uint8_t*)buffer;
        uint8_t* p = begin;
        uint8_t* end = begin + length;

        int value;

        while (p != end) {
            value = ReadByteUnsafe();

            if (value == EOF) break;

            *p = (uint8_t)value;
            ++p;
        }

        return p - begin;
    }

    int Stream::ReadByte()
    {
        m_checkReadable();

        return ReadByteUnsafe();
    }

    void Stream::Seek(int64_t offset, SeekOrigin origin)
    {
        m_checkSeekable();

        SeekUnsafe(offset, origin);
    }

    void Stream::SeekUnsafe(int64_t offset, SeekOrigin origin)
    {
        switch (origin) {
            case SeekOrigin::Begin:   m_seekBegin(offset);   break;
            case SeekOrigin::Current: m_seekCurrent(offset); break;
            case SeekOrigin::End:     m_seekEnd(offset);     break;
            default: [[unlikely]]     throw InvalidArgumentException(u"SeekOrigin値が無効です");
        }
    }

    ssize_t Stream::Write(ssize_t length, const void* buffer)
    {
        Collections::CollectionHelper::CheckLength(length);
        ArgumentNullException::CheckNull(buffer, u"buffer");

        m_checkWritable();

        return WriteUnsafe(length, buffer);
    }

    ssize_t Stream::Write(Collections::Turbo::FastArray<uint8_t> const& buffer)
    {
        m_checkWritable();

        return WriteUnsafe(buffer.Length(), buffer.Data());
    }

    ssize_t Stream::Write(ssize_t count, Collections::Turbo::FastArray<uint8_t> const& buffer)
    {
        Collections::CollectionHelper::CheckCount(buffer.Length(), count);
        m_checkWritable();

        return WriteUnsafe(count, buffer.Data());
    }

    ssize_t Stream::Write(ssize_t offset, ssize_t count, Collections::Turbo::FastArray<uint8_t> const& buffer)
    {
        Collections::CollectionHelper::CheckOffset(buffer.Length(), offset, count);
        m_checkWritable();

        return WriteUnsafe(count, buffer.Data() + offset);
    }

    ssize_t Stream::Write(Collections::Turbo::FastArrayList<uint8_t> const& buffer)
    {
        m_checkWritable();

        return WriteUnsafe(buffer.Length(), buffer.Data());
    }

    ssize_t Stream::Write(ssize_t count, Collections::Turbo::FastArrayList<uint8_t> const& buffer)
    {
        Collections::CollectionHelper::CheckCount(buffer.Length(), count);
        m_checkWritable();

        return WriteUnsafe(count, buffer.Data());
    }

    ssize_t Stream::Write(ssize_t offset, ssize_t count, Collections::Turbo::FastArrayList<uint8_t> const& buffer)
    {
        Collections::CollectionHelper::CheckOffset(buffer.Length(), offset, count);
        m_checkWritable();

        return WriteUnsafe(count, buffer.Data() + offset);
    }

    ssize_t Stream::WriteUnsafe(Collections::Turbo::FastArray<uint8_t> const& buffer)
    {
        return WriteUnsafe(buffer.Length(), buffer.Data());
    }

    ssize_t Stream::WriteUnsafe(ssize_t count, Collections::Turbo::FastArray<uint8_t> const& buffer)
    {
        return WriteUnsafe(count, buffer.Data());
    }

    ssize_t Stream::WriteUnsafe(ssize_t offset, ssize_t count, Collections::Turbo::FastArray<uint8_t> const& buffer)
    {
        return WriteUnsafe(count, buffer.Data() + offset);
    }

    ssize_t Stream::WriteUnsafe(Collections::Turbo::FastArrayList<uint8_t> const& buffer)
    {
        return WriteUnsafe(buffer.Length(), buffer.Data());
    }

    ssize_t Stream::WriteUnsafe(ssize_t count, Collections::Turbo::FastArrayList<uint8_t> const& buffer)
    {
        return WriteUnsafe(count, buffer.Data());
    }

    ssize_t Stream::WriteUnsafe(ssize_t offset, ssize_t count, Collections::Turbo::FastArrayList<uint8_t> const& buffer)
    {
        return WriteUnsafe(count, buffer.Data() + offset);
    }

    bool Stream::WriteByte(uint8_t data)
    {
        if (!CanWrite()) [[unlikely]] throw NotSupportedException(WRITE_NOT_SUPPORTED);
        if (m_isClosed) [[unlikely]] throw IOException(IS_CLOSED);

        return WriteByteUnsafe(data);
    }

    bool Stream::WriteByteUnsafe(uint8_t data)
    {
        return (bool)WriteUnsafe(1, &data);
    }

    inline void Stream::m_checkReadable() const
    {
        if (!CanRead()) [[unlikely]] throw NotSupportedException(READ_NOT_SUPPORTED);
        if (m_isClosed) [[unlikely]] throw IOException(IS_CLOSED);
    }

    inline void Stream::m_checkSeekable() const
    {
        if (!CanSeek()) [[unlikely]] throw NotSupportedException(SEEK_NOT_SUPPORTED);
        if (m_isClosed) [[unlikely]] throw IOException(IS_CLOSED);
    }

    inline void Stream::m_checkWritable() const
    {
        if (!CanWrite()) [[unlikely]] throw NotSupportedException(WRITE_NOT_SUPPORTED);
        if (m_isClosed) [[unlikely]] throw IOException(IS_CLOSED);
    }
}

#undef IS_CLOSED
#undef READ_NOT_SUPPORTED
#undef SEEK_NOT_SUPPORTED
#undef WRITE_NOT_SUPPORTED