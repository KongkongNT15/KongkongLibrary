#ifndef KONGKONG_IO_C_IOHELPER_H
#define KONGKONG_IO_C_IOHELPER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::IO
{
    class c_ioHelper final {
        public:

        STATIC_CLASS(c_ioHelper)

        private:

        using t_handle = 
#if KONGKONG_ENV_WINDOWS
            ::HANDLE;
#elif KONGKONG_ENV_UNIX
            int;
#else
            FILE*;
#endif

        static void Flush(t_handle handle);

        [[nodiscard]]
        static int64_t GetLengthUnsafe(t_handle handle);

        static ssize_t ReadUnsafe(t_handle handle, ssize_t length, void* buffer);

        [[nodiscard]]
        static int ReadByteUnsafe(t_handle handle);

        static ssize_t WriteUnsafe(t_handle handle, ssize_t length, const void* buffer);

        static bool WriteByteUnsafe(t_handle handle, uint8_t data);

        friend IMPLEMENTATION::DeviceStream;
        friend IMPLEMENTATION::PipeStream;
    };
}

#endif //!KONGKONG_IO_C_IOHELPER_H