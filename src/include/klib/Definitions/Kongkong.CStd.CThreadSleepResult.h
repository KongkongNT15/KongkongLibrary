#ifndef KONGKONG_CSTD_CTHREADSLEEPRESULT_H
#define KONGKONG_CSTD_CTHREADSLEEPRESULT_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::CStd
{
    enum struct CThreadSleepResult {
        Success,
        Interrupted,
        Fail,
    };
}

#endif //!KONGKONG_CSTD_CTHREADSLEEPRESULT_H
