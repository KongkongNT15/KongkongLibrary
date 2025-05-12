#ifndef KONGKONG_STD_GENERICOUTSTRING_H
#define KONGKONG_STD_GENERICOUTSTRING_H

#include "Base.h"
#include "Kongkong.StdType.h"
#include "Kongkong.Std.GenericStringBuffer.h"
#include "Kongkong.GenericStringView.h"

#include <ostream>

namespace KONGKONG_NAMESPACE::Standard::Cpp
{
    template <CharType TChar>
    class GenericOutStringStream final : public StdType, public ::std::basic_ostream<TChar, std::char_traits<TChar>> {
        public:
        using Base = ::std::basic_ostream<TChar, std::char_traits<TChar>>;

        GenericOutStringStream() : Base(&_buffer), _buffer() {}

        [[nodiscard]]
        constexpr ssize_t Capacity() const noexcept { return _buffer.Capacity(); }

        [[nodiscard]]
        GenericStringView<TChar> GetStringView() const noexcept { return _buffer.GetStringView(); }

        private:

        GenericStringBuffer<TChar> _buffer;
    };
}

#endif //!KONGKONG_STD_GENERICOUTSTRING_H
