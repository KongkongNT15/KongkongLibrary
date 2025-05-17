#ifndef KONGKONG_IO_PIPESTREAM_H
#define KONGKONG_IO_PIPESTREAM_H

#include "Base.h"
#include "Kongkong.IO.Stream.h"

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    struct KONGKONG_INCOMPLETED_CLASS PipeStream : public Stream {

        PipeStream();

        [[nodiscard]]
        constexpr bool CanRead() const noexcept override { return true; }

        [[nodiscard]]
        constexpr bool CanSeek() const noexcept override { return false; }

        [[nodiscard]]
        constexpr bool CanWrite() const noexcept override { return true; }

        [[nodiscard]]
        int64_t GetLengthUnsafe() const override;

        ssize_t ReadUnsafe(ssize_t length, void* buffer) override;

        [[nodiscard]]
        int ReadByteUnsafe() override;

        [[nodiscard]]
        String ToString() const override;

        ssize_t WriteUnsafe(ssize_t length, const void* buffer) override;

        bool WriteByteUnsafe(uint8_t data) override;
        
        protected:

#if KONGKONG_ENV_WINDOWS

        ::HANDLE m_in;
        ::HANDLE m_out;

#elif KONGKONG_ENV_UNIX

#endif
    };
}

namespace KONGKONG_NAMESPACE::IO
{
    class PipeStream : public Stream {
        public:
        using ImplType = IMPLEMENTATION::PipeStream;

        /// @brief nullptrとして作成
        constexpr PipeStream(::std::nullptr_t) noexcept : Stream(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_IO_PIPESTREAM_H