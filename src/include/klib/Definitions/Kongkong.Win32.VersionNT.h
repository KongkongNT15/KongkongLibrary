#ifndef KONGKONG_WIN32_VERSIONNT_H
#define KONGKONG_WIN32_VERSIONNT_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct VersionNT : uint8_t {
        Workstation      = VER_NT_WORKSTATION,
        DomainController = VER_NT_DOMAIN_CONTROLLER,
        Server           = VER_NT_SERVER,
    };
}

#endif //!KONGKONG_WIN32_VERSIONNT_H
