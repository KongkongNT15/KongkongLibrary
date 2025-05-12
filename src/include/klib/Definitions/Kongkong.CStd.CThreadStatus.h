#ifndef KONGKONG_CSTD_CTHREADSTATUS_H
#define KONGKONG_CSTD_CTHREADSTATUS_H

#include "Base.h"

#include <threads.h>

namespace KONGKONG_NAMESPACE::CStd
{
    enum struct CThreadStatus {
        Success  = ::thrd_success,
        Nomemory = ::thrd_nomem,
        Timeout  = ::thrd_timedout,
        Busy     = ::thrd_busy,
        Error    = ::thrd_error,
    };
}

#endif //!KONGKONG_CSTD_CTHREADSTATUS_H
