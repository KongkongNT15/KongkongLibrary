#ifndef KONGKONG_WIN32_VERSIONSUITE_H
#define KONGKONG_WIN32_VERSIONSUITE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    //よくわからんやつ
    enum struct VersionSuite : uint32_t {
        SmallBusiness           = VER_SUITE_SMALLBUSINESS,
        EnterPrise              = VER_SUITE_ENTERPRISE,
        BackOffice              = VER_SUITE_BACKOFFICE,
        Communications          = VER_SUITE_COMMUNICATIONS,
        Terminal                = VER_SUITE_TERMINAL,
        SmallBusinessRestricted = VER_SUITE_SMALLBUSINESS_RESTRICTED,
        Embeddednt              = VER_SUITE_EMBEDDEDNT,
        DataCenter              = VER_SUITE_DATACENTER,
        SingleUserts            = VER_SUITE_SINGLEUSERTS,
        Personal                = VER_SUITE_PERSONAL,
        Blade                   = VER_SUITE_BLADE,
        EmbeddedRestricted      = VER_SUITE_EMBEDDED_RESTRICTED,
        SecurityAppliance       = VER_SUITE_SECURITY_APPLIANCE,
        StorageServer           = VER_SUITE_STORAGE_SERVER,
        ComputeServer           = VER_SUITE_COMPUTE_SERVER,
        WHServer                = VER_SUITE_WH_SERVER,
        MultiUserts             = VER_SUITE_MULTIUSERTS,
        WorkstationNT           = VER_WORKSTATION_NT,
        ServerNT                = VER_SERVER_NT,
    };

    CREATE_OPERATOR_AND_OR(VersionSuite)
}

#endif //!KONGKONG_WIN32_VERSIONSUITE_H
