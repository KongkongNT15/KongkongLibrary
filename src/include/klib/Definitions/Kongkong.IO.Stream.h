#ifndef KONGKONG_IO_STREAM_H
#define KONGKONG_IO_STREAM_H

#include "Base.h"
#include "Kongkong.Object.h"

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    struct Stream : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::IO::Stream;
        
        virtual void Flush() = 0;

        [[nodiscard]]
        virtual ssize_t Length() const noexcept = 0;

        [[nodiscard]]
        virtual int64_t Position() const noexcept = 0;

        [[nodiscard]]
        virtual int ReadByte();

        virtual void WriteByte(uint8_t data);
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