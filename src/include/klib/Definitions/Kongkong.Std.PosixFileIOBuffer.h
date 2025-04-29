#ifndef KONGKONG_STD_POSIXFILEIOBUFFER_H
#define KONGKONG_STD_POSIXFILEIOBUFFER_H

#include "Base.h"
#include "Kongkong.Std.PosixIOBuffer.h"

namespace KONGKONG_NAMESPACE::Std
{
    template <CharType TChar>
    class GenericPosixFileIOBuffer final : public GenericPosixIOBuffer<TChar> {
        public:
        using Base = GenericPosixIOBuffer<TChar>;

        protected:

        int sync() noexcept override;

        private:

        GenericPosixFileIOBuffer(int ioDevice);
    };
}

#endif //!KONGKONG_STD_POSIXFILEIOBUFFER_H
