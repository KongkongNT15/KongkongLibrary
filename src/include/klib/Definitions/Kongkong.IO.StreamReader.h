#ifndef KONGKONG_IO_STREAMREADER_H
#define KONGKONG_IO_STREAMREADER_H

#include "Base.h"
#include "Kongkong.Object.h"

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    struct StreamReader : public ::KONGKONG_NAMESPACE::Object {

        virtual char16_t Read() = 0;
        virtual String ReadLine() = 0;

        protected:

        private:
    };
}

namespace KONGKONG_NAMESPACE::IO
{
    class StreamReader : public Object {
        public:
        using ImplType = IMPLEMENTATION::StreamReader;

        /// @brief nullptrとして作成
        constexpr StreamReader(::std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_IO_STREAMREADER_H