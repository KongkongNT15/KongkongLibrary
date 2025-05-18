#ifndef KONGKONG_STD_POSIXIOBUFFER_H
#define KONGKONG_STD_POSIXIOBUFFER_H

#include "Base.h"
#include "Kongkong.StdType.h"

#include <streambuf>

namespace KONGKONG_NAMESPACE::Std
{
    template <CharType TChar>
    class GenericPosixIOBuffer : public StdType, public ::std::basic_streambuf<TChar, ::std::char_traits<TChar>> {
        public:
        using Base = ::std::basic_streambuf<TChar, ::std::char_traits<TChar>>;

        GenericPosixIOBuffer(GenericPosixIOBuffer const&) = delete;

        GenericPosixIOBuffer& operator=(GenericPosixIOBuffer const&) = delete;

        protected:

        ::std::streamsize xsgetn(TChar* s, ::std::streamsize n) noexcept override;

        ::std::streamsize xsputn(const TChar* str, ::std::streamsize n) noexcept override;

        

        private:
        int _ioDevice;

        GenericPosixIOBuffer(int ioDevice);

        friend GenericPosixFileIOBuffer<TChar>;
    };
}

#endif //!KONGKONG_STD_POSIXIOBUFFER_H
