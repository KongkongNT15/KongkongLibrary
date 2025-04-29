#ifndef KONGKONG_WIN32_REGISTRYOPTION_H
#define KONGKONG_WIN32_REGISTRYOPTION_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    //レジストリ
    enum struct RegistryOption : long {
        Reserved       = REG_OPTION_RESERVED,
        NonVolatile    = REG_OPTION_NON_VOLATILE,
        Volatile       = REG_OPTION_VOLATILE,
        CreateLink     = REG_OPTION_CREATE_LINK,
        BackupRestore  = REG_OPTION_BACKUP_RESTORE,
        Link           = REG_OPTION_OPEN_LINK,
        DontVirtualize = REG_OPTION_DONT_VIRTUALIZE,
    };

    CREATE_OPERATOR_AND_OR(RegistryOption)
}

#endif //!KONGKONG_WIN32_REGISTRYOPTION_H
