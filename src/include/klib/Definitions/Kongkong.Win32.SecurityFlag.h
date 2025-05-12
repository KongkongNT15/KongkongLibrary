#ifndef KONGKONG_WIN32_SECURITYFLAG_H
#define KONGKONG_WIN32_SECURITYFLAG_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct SecurityFlag {
        None            = 0,
        Anonymous       = SECURITY_ANONYMOUS,
        Identification  = SECURITY_IDENTIFICATION,
        Impersonation   = SECURITY_IMPERSONATION,
        Delegation      = SECURITY_DELEGATION,
        ContextTracking = SECURITY_CONTEXT_TRACKING,
        EffectivrOnly   = SECURITY_EFFECTIVE_ONLY,
    };

    CREATE_OPERATOR_AND_OR(SecurityFlag)
}

#endif //!KONGKONG_WIN32_SECURITYFLAG_H
