#ifndef KONGKONG_WIN32_REGISTRYACCESSRIGHT_H
#define KONGKONG_WIN32_REGISTRYACCESSRIGHT_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    //レジストリのキーへのアクセス権
    enum struct RegistryKeyAccessRight {
        QueryValue       = KEY_QUERY_VALUE,
        SetValue         = KEY_SET_VALUE,
        CreateSubKey     = KEY_CREATE_SUB_KEY,
        EnumerateSubKeys = KEY_ENUMERATE_SUB_KEYS,
        Notify           = KEY_NOTIFY,
        CreateLink       = KEY_CREATE_LINK,
        WOW64_64Key      = KEY_WOW64_64KEY,
        WOW64_32Key      = KEY_WOW64_32KEY,
        WOW64Res         = KEY_WOW64_RES,
        Read             = KEY_READ,
        Write            = KEY_WRITE,
        Execute          = KEY_EXECUTE,
        AllAccess        = KEY_ALL_ACCESS,
    };
}

#endif //!KONGKONG_WIN32_REGISTRYACCESSRIGHT_H
