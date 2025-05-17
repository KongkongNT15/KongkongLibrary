#ifndef KONGKONG_IO_DEVICESTREAM_H
#define KONGKONG_IO_DEVICESTREAM_H

#include "Base.h"
#include "Kongkong.IO.Stream.h"

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    struct DeviceStream : public Stream {

        DeviceStream(DeviceStream const&) = delete;

        DeviceStream& operator=(DeviceStream const&) = delete;

#if KONGKONG_ENV_WINDOWS

        [[nodiscard]]
        constexpr bool CanRead() const noexcept override { return m_canRead; }

        [[nodiscard]]
        constexpr bool CanWrite() const noexcept override { return m_canWrite; }

        [[nodiscard]]
        int64_t GetLengthUnsafe() const override;

        ssize_t ReadUnsafe(ssize_t length, void* buffer) override;

        [[nodiscard]]
        int ReadByteUnsafe() override;

        ssize_t WriteUnsafe(ssize_t length, const void* buffer) override;

        bool WriteByteUnsafe(uint8_t data) override;
#elif KONGKONG_ENV_UNIX

        [[nodiscard]]
        constexpr bool CanRead() const noexcept override { return m_canRead; }

        [[nodiscard]]
        constexpr bool CanWrite() const noexcept override { return m_canWrite; }

        [[nodiscard]]
        int64_t GetLengthUnsafe() const override;

        ssize_t ReadUnsafe(ssize_t length, void* buffer) override;

        [[nodiscard]]
        int ReadByteUnsafe() override;

        ssize_t WriteUnsafe(ssize_t length, const void* buffer) override;

        bool WriteByteUnsafe(uint8_t data) override;

#else
        [[nodiscard]]
        constexpr bool CanRead() const noexcept override { return m_canRead; }

        [[nodiscard]]
        constexpr bool CanWrite() const noexcept override { return m_canWrite; }

        void Flush() override;

        [[nodiscard]]
        int64_t GetLengthUnsafe() const override;

        ssize_t ReadUnsafe(ssize_t length, void* buffer) override;

        [[nodiscard]]
        int ReadByteUnsafe() override;

        ssize_t WriteUnsafe(ssize_t length, const void* buffer) override;

        bool WriteByteUnsafe(uint8_t data) override;
#endif


        protected:


#if KONGKONG_ENV_WINDOWS
        ::HANDLE m_device;
        bool m_canRead;
        bool m_canWrite;

        constexpr DeviceStream() noexcept : m_device(nullptr), m_canRead(false), m_canWrite(false) {}
        constexpr DeviceStream(::HANDLE device) noexcept : m_device(device), m_canRead(false), m_canWrite(false) {}

        void m_close() noexcept override;
        void m_flush() override;
#elif KONGKONG_ENV_UNIX
        int m_device;
        bool m_canRead;
        bool m_canWrite;

        constexpr DeviceStream() noexcept : m_device(EOF), m_canRead(false), m_canWrite(false) {}

        void m_close() noexcept override;
        void m_flush() override;

        void m_seekBegin(int64_t offset) override;
        void m_seekCurrent(int64_t offset) override;
        void m_seekEnd(int64_t offset) override;
#else
        ::FILE* m_device;
        bool m_canRead;
        bool m_canWrite;

        void m_close() noexcept override;
        
        void m_seekBegin(int64_t offset) override;
        void m_seekCurrent(int64_t offset) override;
        void m_seekEnd(int64_t offset) override;
#endif
    };
}

namespace KONGKONG_NAMESPACE::IO
{
    class DeviceStream : public Stream {
        public:
        using ImplType = IMPLEMENTATION::DeviceStream;

        /// @brief nullptrとして作成
        constexpr DeviceStream(::std::nullptr_t) noexcept : Stream(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_IO_DEVICESTREAM_H