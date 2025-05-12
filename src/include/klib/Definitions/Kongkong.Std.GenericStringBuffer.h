#ifndef KONGKONG_STANDARD_CPP_GENERICSTRINGBUFFER_H
#define KONGKONG_STANDARD_CPP_GENERICSTRINGBUFFER_H

#include "Base.h"
#include <streambuf>
#include <string>

#include "Kongkong.StdType.h"

namespace KONGKONG_NAMESPACE::Standard::Cpp
{
    template <CharType TChar>
    class GenericStringBuffer final : public StdType, public ::std::basic_streambuf<TChar, std::char_traits<TChar>> {
        public:
        using Base = ::std::basic_streambuf<TChar, std::char_traits<TChar>>;

        GenericStringBuffer();
        GenericStringBuffer(GenericStringBuffer const& right);
        GenericStringBuffer(GenericStringBuffer&& right) noexcept;

        ~GenericStringBuffer();

        GenericStringBuffer& operator=(GenericStringBuffer const& right);
        GenericStringBuffer& operator=(GenericStringBuffer&& right) noexcept;

        [[nodiscard]]
        constexpr ssize_t Capacity() const noexcept { return _capacity; }

        [[nodiscard]]
        GenericStringView<TChar> GetStringView() const noexcept;

        protected:
        Base::int_type overflow(Base::int_type c) override;

        std::streamsize xsputn(const TChar* s, std::streamsize n) override;

        private:
        TChar* _buffer;
        ssize_t _capacity;

        void _setgp(ssize_t defg, ssize_t defp) noexcept;

        TChar* _getEndPtr() const noexcept;

        bool _expandBuffer(ssize_t append = _defaultCapacity) noexcept;

        static constexpr ssize_t _defaultCapacity = 128;
    };
}

#endif //!KONGKONG_STANDARD_CPP_GENERICSTRINGBUFFER_H
