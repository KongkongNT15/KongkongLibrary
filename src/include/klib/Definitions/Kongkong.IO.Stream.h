#ifndef KONGKONG_IO_STREAM_H
#define KONGKONG_IO_STREAM_H

#include "Base.h"
#include "Kongkong.Object.h"

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    struct Stream : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::IO::Stream;

        ~Stream();

        [[nodiscard]]
        virtual constexpr bool CanRead() const noexcept { return false; }

        [[nodiscard]]
        virtual constexpr bool CanSeek() const noexcept { return false; }

        [[nodiscard]]
        virtual constexpr bool CanWrite() const noexcept { return false; }

        bool Close();
        
        void Flush();

        [[nodiscard]]
        virtual int64_t GetLengthUnsafe() const = 0;

        [[nodiscard]]
        virtual int64_t GetPositionUnsafe() const = 0;

        [[nodiscard]]
        constexpr bool IsClosed() const noexcept { return m_isClosed; }

        [[nodiscard]]
        int64_t Length() const;

        [[nodiscard]]
        int64_t Position() const;

        /// @brief ふぁ！？っく
        ssize_t Read(ssize_t, ::std::nullptr_t) = delete;

        ssize_t Read(ssize_t length, void* buffer);

        /// @brief ふぁ！？っく
        ssize_t ReadUnsafe(ssize_t, ::std::nullptr_t) = delete;

        virtual ssize_t ReadUnsafe(ssize_t length, void* buffer);

        [[nodiscard]]
        int ReadByte();

        [[nodiscard]]
        virtual int ReadByteUnsafe() { return EOF; }

        void Seek(int64_t offset, SeekOrigin origin);

        void SeekUnsafe(int64_t offset, SeekOrigin origin);

        /// @brief ふぁ！？っく
        ssize_t Write(ssize_t, ::std::nullptr_t) = delete;

        ssize_t Write(ssize_t length, const void* buffer);
        ssize_t Write(Collections::Turbo::FastArray<uint8_t> const& buffer);
        ssize_t Write(ssize_t count, Collections::Turbo::FastArray<uint8_t> const& buffer);
        ssize_t Write(ssize_t offset, ssize_t count, Collections::Turbo::FastArray<uint8_t> const& buffer);
        ssize_t Write(Collections::Turbo::FastArrayList<uint8_t> const& buffer);
        ssize_t Write(ssize_t count, Collections::Turbo::FastArrayList<uint8_t> const& buffer);
        ssize_t Write(ssize_t offset, ssize_t count, Collections::Turbo::FastArrayList<uint8_t> const& buffer);

        /// @brief ふぁ！？っく
        ssize_t WriteUnsafe(ssize_t, ::std::nullptr_t) = delete;

        virtual constexpr ssize_t WriteUnsafe(ssize_t length, const void* buffer) { return 0; }

        ssize_t WriteUnsafe(Collections::Turbo::FastArray<uint8_t> const& buffer);
        ssize_t WriteUnsafe(ssize_t count, Collections::Turbo::FastArray<uint8_t> const& buffer);
        ssize_t WriteUnsafe(ssize_t offset, ssize_t count, Collections::Turbo::FastArray<uint8_t> const& buffer);
        ssize_t WriteUnsafe(Collections::Turbo::FastArrayList<uint8_t> const& buffer);
        ssize_t WriteUnsafe(ssize_t count, Collections::Turbo::FastArrayList<uint8_t> const& buffer);
        ssize_t WriteUnsafe(ssize_t offset, ssize_t count, Collections::Turbo::FastArrayList<uint8_t> const& buffer);

        bool WriteByte(uint8_t data);

        virtual bool WriteByteUnsafe(uint8_t data);

        protected:

        constexpr Stream() noexcept : m_isClosed(false) {}
        Stream(Stream const&) = default;
        Stream(Stream&&) = default;

        Stream& operator=(Stream const&) = default;
        Stream& operator=(Stream&&) = default;

        virtual constexpr void m_close() noexcept {}

        virtual constexpr void m_flush() {}

        virtual constexpr void m_seekBegin(int64_t) {}
        virtual constexpr void m_seekCurrent(int64_t) {}
        virtual constexpr void m_seekEnd(int64_t) {}

        constexpr void m_setClosed() noexcept { m_isClosed = true; }

        private:

        bool m_isClosed;

        void m_checkReadable() const;
        void m_checkSeekable() const;
        void m_checkWritable() const;
    };
}

namespace KONGKONG_NAMESPACE::IO
{
    class Stream : public Object {
        public:
        using ImplType = IMPLEMENTATION::Stream;

        /// @brief nullptrとして作成
        constexpr Stream(::std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

    };
}

#endif //!KONGKONG_IO_STREAM_H