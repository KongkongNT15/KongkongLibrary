//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::IO
{
    OutputStreamBuffer OutputStreamBuffer::Create4096()
    {
        return OutputStreamBuffer(4096);
    }

    OutputStreamBuffer OutputStreamBuffer::Create8192()
    {
        return OutputStreamBuffer(8192);
    }

    OutputStreamBuffer::OutputStreamBuffer(uint32_t capacity)
        : m_capacity(capacity)
        , m_length(0)
        , m_p((uint8_t*)::malloc(capacity))
    {
        MemoryAllocationException::CheckNull(m_p);
    }

    OutputStreamBuffer::OutputStreamBuffer(OutputStreamBuffer const& right)
        : m_capacity(right.m_capacity)
        , m_length(right.m_length)
        , m_p((uint8_t*)::malloc(right.m_capacity))
    {
        MemoryAllocationException::CheckNull(m_p);

        m_copy(right);
    }

    OutputStreamBuffer::~OutputStreamBuffer()
    {
        if (m_p == nullptr) return;

        ::free(m_p);
    }

    OutputStreamBuffer& OutputStreamBuffer::operator=(OutputStreamBuffer const& right)
    {
        if (m_capacity < right.m_length) {
            ::free(m_p);
            m_p = (uint8_t*)::malloc(right.m_capacity);

            MemoryAllocationException::CheckNull(m_p);
        }

        m_copy(right);

        m_length = right.m_length;

        return *this;
    }

    OutputStreamBuffer& OutputStreamBuffer::operator=(OutputStreamBuffer&& right) noexcept
    {
        ::free(m_p);

        m_capacity = right.m_capacity;
        m_length = right.m_length;
        m_p = right.m_p;

        right.m_p = nullptr;

        return *this;
    }

    bool OutputStreamBuffer::Append(uint8_t data) noexcept
    {
        if (m_length == m_capacity) return false;

        m_p[m_length] = data;
        ++m_length;

        return true;
    }

    uint32_t OutputStreamBuffer::Append(ssize_t length, const void* data) noexcept
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

    String OutputStreamBuffer::ToString() const
    {
        return String::FromLiteral(u"Kongkong::IO::OutputStreamBuffer");
    }

    void OutputStreamBuffer::m_copy(OutputStreamBuffer const& right)
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