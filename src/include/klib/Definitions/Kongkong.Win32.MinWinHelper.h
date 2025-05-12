#ifndef KONGKONG_WIN32_MINWINHELPER_H
#define KONGKONG_WIN32_MINWINHELPER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class MinWinHelper final {
        public:

        STATIC_CLASS(MinWinHelper)

        [[nodiscard]]
        static uint64_t ToUInt64(uint32_t high, uint32_t low) noexcept;

    };
}

#endif //!KONGKONG_WIN32_MINWINHELPER_H
