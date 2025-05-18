#ifndef KONGKONG_IO_BUFFERDSTREAM_H
#define KONGKONG_IO_BUFFERDSTREAM_H

#include "Base.h"
#include "Kongkong.IO.DeviceStream.h"

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    struct BufferedStream : public DeviceStream {

        [[nodiscard]]
        int64_t GetLengthUnsafe() const override;

        ssize_t ReadUnsafe(ssize_t length, void* buffer) override;

        [[nodiscard]]
        int ReadByteUnsafe() override;

        ssize_t WriteUnsafe(ssize_t length, const void* buffer) override;

        bool WriteByteUnsafe(uint8_t data) override;

        protected:

        BufferedStream();
        BufferedStream(uint32_t bufferSize);

        void m_flush() override;

        private:

        OutputStreamBuffer m_buffer;
    };
}

namespace KONGKONG_NAMESPACE::IO
{
    class BufferedStream : public DeviceStream {
        public:
        using ImplType = IMPLEMENTATION::BufferedStream;

        /// @brief nullptrとして作成
        constexpr BufferedStream(::std::nullptr_t) noexcept : DeviceStream(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_IO_BUFFERDSTREAM_H