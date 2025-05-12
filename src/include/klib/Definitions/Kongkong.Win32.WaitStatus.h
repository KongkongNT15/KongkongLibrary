#ifndef KONGKONG_WIN32_WAITSTATUS_H
#define KONGKONG_WIN32_WAITSTATUS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct WaitStatus : DWORD {
        Abandoned    = WAIT_ABANDONED,
        Object       = WAIT_OBJECT_0,
        Timeout      = WAIT_TIMEOUT,
        IOCompletion = WAIT_IO_COMPLETION,
        Failed       = WAIT_FAILED,
    };
}

#endif //!KONGKONG_WIN32_WAITSTATUS_H
