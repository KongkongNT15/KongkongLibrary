#ifndef KONGKONG_SYSTEM_BUILDCONFIG_H
#define KONGKONG_SYSTEM_BUILDCONFIG_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::System
{
    class BuildConfig {
        public:

        STATIC_CLASS(BuildConfig)

        [[nodiscard]]
        static constexpr bool IsDebugMode() noexcept
        {
#ifdef NDEBUG
            return false;
#else
            return true;
#endif
        }
    };
}

#endif //!KONGKONG_SYSTEM_BUILDCONFIG_H
