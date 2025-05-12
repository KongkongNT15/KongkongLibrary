#ifndef KONGKONG_WIN32_HANDLEFRAG_H
#define KONGKONG_WIN32_HANDLEFRAG_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct HandleFrag : unsigned long {
        Inherit          = HANDLE_FLAG_INHERIT,
        ProtectFromClose = HANDLE_FLAG_PROTECT_FROM_CLOSE,
    };

    CREATE_OPERATOR_AND_OR(HandleFrag)
}

#endif //!KONGKONG_WIN32_HANDLEFRAG_H
