//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::IO
{
    StreamBuffer StreamBuffer::Create4096()
    {
        return StreamBuffer(4096);
    }

    StreamBuffer StreamBuffer::Create8192()
    {
        return StreamBuffer(8192);
    }

    StreamBuffer::StreamBuffer(uint32_t capacity)
        : m_capacity(capacity)
        , m_length(0)
        , m_current(0)
        , m_p((uint8_t*)::malloc(capacity))
    {
        MemoryAllocationException::CheckNull(m_p);
    }

    StreamBuffer::StreamBuffer(StreamBuffer const& right)
        : m_capacity(right.m_capacity)
        , m_length(right.m_length)
        , m_current(right.m_current)
        , m_p((uint8_t*)::malloc(right.m_capacity))
    {
        MemoryAllocationException::CheckNull(m_p);

        m_copy(right);
    }

    StreamBuffer::~StreamBuffer()
    {
        if (m_p == nullptr) return;

        ::free(m_p);
    }

    StreamBuffer& StreamBuffer::operator=(StreamBuffer const& right)
    {
        if (m_capacity < right.m_length) {
            ::free(m_p);
            m_p = (uint8_t*)::malloc(right.m_capacity);

            MemoryAllocationException::CheckNull(m_p);
        }

        m_copy(right);

        m_length = right.m_length;
        m_current = right.m_current;

        return *this;
    }

    StreamBuffer& StreamBuffer::operator=(StreamBuffer&& right) noexcept
    {
        ::free(m_p);

        m_capacity = right.m_capacity;
        m_length = right.m_length;
        m_current = right.m_current;
        m_p = right.m_p;

        right.m_p = nullptr;

        return *this;
    }

    bool StreamBuffer::Append(uint8_t data) noexcept
    {
        if (m_length == m_capacity) return false;

        m_p[m_length] = data;
        ++m_length;

        return true;
    }

    uint32_t StreamBuffer::Append(ssize_t length, const void* data) noexcept
    {
        uint32_t tmp0 = (uint32_t)length;
        uint32_t tmp1 = m_capacity - m_length;

        uint32_t writableLength = tmp0 < tmp1 ? tmp0 : tmp1;

        const uint8_t* p = (const uint8_t*)data;
        const uint8_t* e = p + writableLength;
        uint8_t* mp = m_p + m_length;

        while (p != e) {
            *mp = *p;
            ++mp;
            ++p;
        }

        return writableLength;
    }

    uint32_t StreamBuffer::Load(IMPLEMENTATION::BufferedStream& stream)
    {
        Clear();

        uint32_t result = (uint32_t)(stream. IMPLEMENTATION::DeviceStream::ReadUnsafe(m_capacity, m_p));

        m_length = result;

        return result;
    }

    uint32_t StreamBuffer::LoadSafe(IMPLEMENTATION::BufferedStream& stream)
    {
        if (!stream.CanRead()) [[unlikely]] throw IOException(u"このストリームは読み取りをサポートしていません");

        return Load(stream);
    }

    bool StreamBuffer::Read(uint8_t& data)
    {
        if (m_current == m_length) return false;

        data = m_p[m_current];
        ++m_current;

        return true;
    }

    uint32_t StreamBuffer::Read(ssize_t length, void* buffer)
    {
        uint32_t tmp0 = (uint32_t)length;
        uint32_t tmp1 = m_length - m_current;

        uint32_t readableLength = tmp0 < tmp1 ? tmp0 : tmp1;

        uint8_t* bp = (uint8_t*)buffer;
        const uint8_t* mp = m_p + m_current;
        const uint8_t* me = mp + readableLength;

        while (mp != me) {
            *bp = *mp;

            ++mp;
            ++bp;
        }

        return readableLength;
    }

    String StreamBuffer::ToString() const
    {
        return String::FromLiteral(u"Kongkong::IO::StreamBuffer");
    }

    void StreamBuffer::m_copy(StreamBuffer const& right)
    {
        uint8_t* mp = m_p;
        uint8_t* rp = right.m_p;
        uint8_t* re = rp + right.m_length;

        while (rp != re) {
            *mp = *rp;

            ++rp;
            ++re;
        }
    }
}