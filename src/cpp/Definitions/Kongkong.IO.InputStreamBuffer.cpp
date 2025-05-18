//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::IO
{
    InputStreamBuffer InputStreamBuffer::Create4096()
    {
        return InputStreamBuffer(4096);
    }

    InputStreamBuffer InputStreamBuffer::Create8192()
    {
        return InputStreamBuffer(8192);
    }

    InputStreamBuffer::InputStreamBuffer(uint32_t capacity)
        : m_capacity(capacity)
        , m_length(0)
        , m_current(0)
        , m_p((uint8_t*)::malloc(capacity))
    {
        MemoryAllocationException::CheckNull(m_p);
    }

    InputStreamBuffer::~InputStreamBuffer()
    {
        if (m_p != nullptr) ::free(m_p);
    }

    uint32_t InputStreamBuffer::Load(IMPLEMENTATION::Stream& stream)
    {
        Clear();

        uint32_t result = (uint32_t)stream.ReadUnsafe(m_capacity, m_p);

        m_length = result;

        return result;
    }

    uint32_t InputStreamBuffer::LoadSafe(IMPLEMENTATION::Stream& stream)
    {
        if (!stream.CanRead()) [[unlikely]] throw IOException(u"このストリームは読み取りをサポートしていません");

        return Load(stream);
    }

    bool InputStreamBuffer::Read(uint8_t& data)
    {
        if (m_current == m_length) return false;

        data = m_p[m_current];
        ++m_current;

        return true;
    }

    uint32_t InputStreamBuffer::Read(ssize_t length, void* buffer)
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

    String InputStreamBuffer::ToString() const
    {
        return String::FromLiteral(u"Kongkong::IO::InputStreamBuffer");
    }
}