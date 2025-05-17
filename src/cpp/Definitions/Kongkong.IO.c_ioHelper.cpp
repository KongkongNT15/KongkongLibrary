//このcppファイルをコンパイルに含めないでください

#define FLUSH_FAIL String::FromLiteral(u"ストリームのフラッシュに失敗しました")
#define GET_LENGTH_FAIL String::FromLiteral(u"ストリームのサイズの取得に失敗しました")
#define READ_FAIL String::FromLiteral(u"ストリームからの読み込みに失敗しました")
#define WRITE_FAIL String::FromLiteral(u"ストリームへの書き込みに失敗しました")

namespace KONGKONG_NAMESPACE::IO
{
#if KONGKONG_ENV_WINDOWS

    inline void c_ioHelper::Flush(t_handle handle)
    {
        if (::FlushFileBuffers(handle) == FALSE) [[unlikely]] throw IOException(FLUSH_FAIL);
    }

    inline int64_t c_ioHelper::GetLengthUnsafe(t_handle handle)
    {
        ::LARGE_INTEGER integer;
        if (::GetFileSizeEx(handle, &integer) == 0) [[unlikely]] throw IOException(u"ストリームの長さの取得に失敗しました");

        return integer.QuadPart;
    }

    inline ssize_t c_ioHelper::ReadUnsafe(t_handle handle, ssize_t length, void* buffer)
    {
        ::DWORD readBytes;

        if (::ReadFile(handle, buffer, (::DWORD)length, &readBytes, nullptr) == FALSE) [[unlikely]] throw IOException(READ_FAIL);

        return readBytes;
    }

    inline int c_ioHelper::ReadByteUnsafe(t_handle handle)
    {
        uint8_t value;
        ::DWORD readBytes;

        ::BOOL result = ::ReadFile(handle, &value, 1, &readBytes, nullptr);

        if (result == FALSE) [[unlikely]] throw IOException(READ_FAIL);
        if (readBytes == 0) return EOF;

        return value;
    }

    inline ssize_t c_ioHelper::WriteUnsafe(t_handle handle, ssize_t length, const void* buffer)
    {
        DWORD writtenLength;

        if (::WriteFile(handle, buffer, (::DWORD)length, &writtenLength, nullptr) == FALSE) [[unlikely]] throw IOException(WRITE_FAIL);

        return writtenLength;
    }

    inline bool c_ioHelper::WriteByteUnsafe(t_handle handle, uint8_t data)
    {
        DWORD tmp;
        if (::WriteFile(handle, &data, 1, &tmp, nullptr) == 0) [[unlikely]] throw IOException(WRITE_FAIL);

        return (bool)tmp;
    }

#elif KONGKONG_ENV_UNIX

    inline void c_ioHelper::Flush(t_handle handle)
    {
        if (fsync(handle)) [[unlikely]] throw IOException(FLUSH_FAIL);
    }

    inline int64_t c_ioHelper::GetLengthUnsafe(t_handle handle)
    {
        struct ::stat st;

        if (::fstat(handle, &st) == EOF) [[unlikely]] throw IOException(GET_LENGTH_FAIL);

        return st.st_size;
    }

    inline ssize_t c_ioHelper::ReadUnsafe(t_handle handle, ssize_t length, void* buffer)
    {
        ssize_t result = ::read(handle, buffer, length);

        if (result == EOF) [[unlikely]] throw IOException(READ_FAIL);

        return result;
    }

    inline int c_ioHelper::ReadByteUnsafe(t_handle handle)
    {
        uint8_t data;
        switch (::read(handle, &data, 1)) {
            case EOF: [[unlikely]] throw IOException(READ_FAIL);
            case 0: return EOF;
            default: [[likely]] return data;
        }

#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif
    }

    inline ssize_t c_ioHelper::WriteUnsafe(t_handle handle, ssize_t length, const void* buffer)
    {
        ssize_t result = ::write(handle, buffer, length);

        if (result == EOF) [[unlikely]] throw IOException(WRITE_FAIL);

        return result;
    }

    inline bool c_ioHelper::WriteByteUnsafe(t_handle handle, uint8_t data)
    {
        switch(::write(handle, &data, 1)) {
            case EOF: [[unlikely]] throw IOException(WRITE_FAIL);
            case 0: [[unlikely]] return false;
            default: [[likely]] return true;
        }
        
#if KONGKONG_HAS_CPP23
        ::std::unreachable();
#endif
    }
#else

    inline void c_ioHelper::Flush(t_handle handle)
    {
        if (::fflush(handle) == EOF) [[unlikely]] throw IOException(FLUSH_FAIL);
    }

    inline int64_t c_ioHelper::GetLengthUnsafe(t_handle handle)
    {
        ::fpos_t pos1, pos2;
        if (::fgetpos(handle, &pos1) == EOF) [[unlikely]] throw IOException(GET_LENGTH_FAIL);

        ::fseek(handle, 0, SEEK_END);

        ::fgetpos(handle, &pos2);

        ::fseek(handle, pos1, SEEK_SET);

        return pos2;
    }

    inline ssize_t c_ioHelper::ReadUnsafe(t_handle handle, ssize_t length, void* buffer)
    {
        ssize_t result = ::fread(buffer, 1, length, handle);

        if (result != length) [[unlikely]] {
            if (::ferror(handle)) [[likely]] throw IOException(READ_FAIL);
        }

        return result;
    }

    inline int c_ioHelper::ReadByteUnsafe(t_handle handle)
    {
        return ::fgetc(handle);
    }

    inline ssize_t c_ioHelper::WriteUnsafe(t_handle handle, ssize_t length, const void* buffer)
    {
        ssize_t result = ::fwrite(buffer, 1, length, handle);

        if (result != length) [[unlikely]] {
            if (::ferror(handle)) [[likely]] throw IOException(WRITE_FAIL); 
        }

        return result;
    }

    inline bool c_ioHelper::WriteByteUnsafe(t_handle handle, uint8_t data)
    {
        if (::fputc(data, handle) == EOF) [[unlikely]] {
            if (::ferror(handle)) [[likeky]] throw IOException(WRITE_FAIL);

            return false;
        }

        return true;
    }
#endif
}

#undef FLUSH_FAIL
#undef GET_LENGTH_FAIL
#undef READ_FAIL
#undef WRITE_FAIL