//このcppファイルをコンパイルに含めないでください

#define SEEK_FAIL String::FromLiteral(u"ストリームのシークに失敗しました")

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
#if KONGKONG_ENV_WINDOWS

    int64_t DeviceStream::GetLengthUnsafe() const
    {
        return c_ioHelper::GetLengthUnsafe(m_device);
    }

    ssize_t DeviceStream::ReadUnsafe(ssize_t length, void* buffer)
    {
        return c_ioHelper::ReadUnsafe(m_device, length, buffer);
    }

    int DeviceStream::ReadByteUnsafe()
    {
        return c_ioHelper::ReadByteUnsafe(m_device);
    }

    ssize_t DeviceStream::WriteUnsafe(ssize_t length, const void* buffer)
    {
        return c_ioHelper::WriteUnsafe(m_device, length, buffer);
    }

    bool DeviceStream::WriteByteUnsafe(uint8_t data)
    {
        return c_ioHelper::WriteByteUnsafe(m_device, data);
    }

    void DeviceStream::m_close() noexcept
    {
        ::CloseHandle(m_device);
    }

    void DeviceStream::m_flush()
    {
        return c_ioHelper::Flush(m_device);
    }

#elif KONGKONG_ENV_UNIX

    int64_t DeviceStream::GetLengthUnsafe() const
    {
        return c_ioHelper::GetLengthUnsafe(m_device);
    }

    ssize_t DeviceStream::ReadUnsafe(ssize_t length, void* buffer)
    {
        return c_ioHelper::ReadUnsafe(m_device, length, buffer);
    }

    int DeviceStream::ReadByteUnsafe()
    {
        return c_ioHelper::ReadByteUnsafe(m_device);
    }

    ssize_t DeviceStream::WriteUnsafe(ssize_t length, const void* buffer)
    {
        return c_ioHelper::WriteUnsafe(m_device, length, buffer);
    }

    bool DeviceStream::WriteByteUnsafe(uint8_t data)
    {
        return c_ioHelper::WriteByteUnsafe(m_device, data);
    }

    void DeviceStream::m_close() noexcept
    {
        ::close(m_device);
    }

    void DeviceStream::m_flush()
    {
        return c_ioHelper::Flush(m_device);
    }

    void DeviceStream::m_seekBegin(int64_t offset)
    {
        if (::lseek(m_device, offset, SEEK_SET) == EOF) [[unlikely]] throw IOException(SEEK_FAIL);
    }

    void DeviceStream::m_seekCurrent(int64_t offset)
    {
        if (::lseek(m_device, offset, SEEK_CUR) == EOF) [[unlikely]] throw IOException(SEEK_FAIL);
    }

    void DeviceStream::m_seekEnd(int64_t offset)
    {
        if (::lseek(m_device, offset, SEEK_END) == EOF) [[unlikely]] throw IOException(SEEK_FAIL);
    }
#else

    int64_t DeviceStream::GetLengthUnsafe() const
    {
        return c_ioHelper::GetLengthUnsafe(m_device);
    }

    ssize_t DeviceStream::ReadUnsafe(ssize_t length, void* buffer)
    {
        return c_ioHelper::ReadUnsafe(m_device, length, buffer);
    }

    int DeviceStream::ReadByteUnsafe()
    {
        return c_ioHelper::ReadByteUnsafe(m_device);
    }

    ssize_t DeviceStream::WriteUnsafe(ssize_t length, const void* buffer)
    {
        return c_ioHelper::WriteUnsafe(m_device, length, buffer);
    }

    bool DeviceStream::WriteByteUnsafe(uint8_t data)
    {
        return c_ioHelper::WriteByteUnsafe(m_device, data);
    }

    void DeviceStream::m_close() noexcept
    {
        ::fclose(m_device);
    }

    void DeviceStream::m_flush()
    {
        return c_ioHelper::Flush(m_device);
    }

    void DeviceStream::m_seekBegin(int64_t offset)
    {
        if (::fseek(m_device, offset, SEEK_SET) == EOF) [[unlikely]] throw IOException(SEEK_FAIL);
    }

    void DeviceStream::m_seekCurrent(int64_t offset)
    {
        if (::fseek(m_device, offset, SEEK_CUR) == EOF) [[unlikely]] throw IOException(SEEK_FAIL);
    }

    void DeviceStream::m_seekEnd(int64_t offset)
    {
        if (::fseek(m_device, offset, SEEK_END) == EOF) [[unlikely]] throw IOException(SEEK_FAIL);
    }
#endif
}

#undef SEEK_FAIL