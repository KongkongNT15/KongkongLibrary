#ifndef KONGKONG_POSIX_THREADING_THREADSCOPE_H
#define KONGKONG_POSIX_THREADING_THREADSCOPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    enum struct ThreadScope {
        Process = PTHREAD_SCOPE_PROCESS,
        System  = PTHREAD_SCOPE_SYSTEM,
    };
}

#endif //!KONGKONG_POSIX_THREADING_THREADSCOPE_H
