#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSDEBUG_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSDEBUG_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    class NSDebug final {
        public:
        STATIC_CLASS(NSDebug)

        [[nodiscard]]
        static bool DeallocateZombies() noexcept;

        [[nodiscard]]
        static bool DebugEnabled() noexcept;

        [[nodiscard]]
        static bool ZombieEnabled() noexcept;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSDEBUG_H
