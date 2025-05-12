#ifndef KONGKONG_DIAGNOSTICS_DEBUG_H
#define KONGKONG_DIAGNOSTICS_DEBUG_H

#include "Base.h"

#ifdef NDEBUG
    #define KONGKONG_DEBUG_CONSTEXPR constexpr
    #define KONGKONG_DEBUG_ENABLED false
    #define KONGKONG_DEBUG_INLINE {}
#else
    #define KONGKONG_DEBUG_CONSTEXPR
    #define KONGKONG_DEBUG_ENABLED true
    #define KONGKONG_DEBUG_INLINE ;
#endif

namespace KONGKONG_NAMESPACE::Diagnostics
{
    class Debug final {
        public:

        STATIC_CLASS(Debug)

        [[nodiscard]]
        static constexpr bool IsDebugEnabled() noexcept { return KONGKONG_DEBUG_ENABLED; }
    };
}

#undef KONGKONG_DEBUG_CONSTEXPR
#undef KONGKONG_DEBUG_ENABLED
#undef KONGKONG_DEBUG_INLINE

#endif //!KONGKONG_DIAGNOSTICS_DEBUG_H
