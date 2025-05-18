//このcppファイルをコンパイルに含めないでください

#if KONGKONG_ENV_WINDOWS
    #define PIPESTREAM_IN  m_in
    #define PIPESTREAM_OUT m_out
#elif KONGKONG_ENV_UNIX
    #define PIPESTREAM_IN  m_in
    #define PIPESTREAM_OUT m_out
#endif

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
#if KONGKONG_ENV_WINDOWS
    PipeStream::PipeStream()
    {
        if (!CreatePipe(&m_in, &m_out, nullptr, 0)) [[unlikely]] throw MemoryAllocationException();
    }
#elif KONGKONG_ENV_UNIX

#endif
    

    String PipeStream::ToString() const
    {
        return String::FromLiteral(u"Kongkong::IO::PipeStream");
    }

    int64_t PipeStream::GetLengthUnsafe() const
    {
        return c_ioHelper::GetLengthUnsafe(PIPESTREAM_IN);
    }

    ssize_t PipeStream::ReadUnsafe(ssize_t length, void* buffer)
    {
        return c_ioHelper::ReadUnsafe(PIPESTREAM_IN, length, buffer);
    }

    int PipeStream::ReadByteUnsafe()
    {
        return c_ioHelper::ReadByteUnsafe(PIPESTREAM_IN);
    }

    ssize_t PipeStream::WriteUnsafe(ssize_t length, const void* buffer)
    {
        return c_ioHelper::WriteUnsafe(PIPESTREAM_OUT, length, buffer);
    }

    bool PipeStream::WriteByteUnsafe(uint8_t data)
    {
        return c_ioHelper::WriteByteUnsafe(PIPESTREAM_OUT, data);
    }
    
}

#undef PIPESTREAM_IN
#undef PIPESTREAM_OUT 