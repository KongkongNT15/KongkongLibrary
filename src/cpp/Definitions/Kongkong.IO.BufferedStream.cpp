//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    BufferedStream::BufferedStream()
        : m_buffer(StreamBuffer::Create4096())
    {
    }

    BufferedStream::BufferedStream(uint32_t bufferSize)
        : m_buffer(bufferSize)
    {
    }

    ssize_t BufferedStream::ReadUnsafe(ssize_t length, void* buffer)
    {
        ssize_t result = m_buffer.Read(length, buffer);

        if (result == length) return result;

        if (m_buffer.Load(*this) == 0) return result;

        ssize_t nokori = length - result;

        uint8_t* tmp = (uint8_t*)buffer;

        return nokori + ReadUnsafe(nokori, tmp + result);
    }

    int BufferedStream::ReadByteUnsafe()
    {
        uint8_t data;

        if (m_buffer.Read(data)) return data;

        if (m_buffer.Load(*this) == 0) return EOF;

        return BufferedStream::ReadByteUnsafe();
    }

    ssize_t BufferedStream::WriteUnsafe(ssize_t length, const void* buffer)
    {
        ssize_t result = m_buffer.Append(length, buffer);

        if (result == length) return;

        // すべて書き込めなかったとき

        ssize_t nokori = length - result;

        BufferedStream::m_flush();
        
        const uint8_t* tmp = (const uint8_t*)buffer;

        return result + BufferedStream::WriteUnsafe(nokori, tmp + result);
    }

    bool BufferedStream::WriteByteUnsafe(uint8_t data)
    {
        if (m_buffer.Append(data)) return;

        // 書き込み失敗時
        BufferedStream::m_flush();
        
        m_buffer.Append(data);
    }

    void BufferedStream::m_flush()
    {
        DeviceStream::WriteUnsafe(m_buffer.Length(), m_buffer.Data());

        m_buffer.Clear();
    }
}