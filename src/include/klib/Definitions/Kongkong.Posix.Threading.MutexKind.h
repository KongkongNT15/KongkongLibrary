#ifndef KONGKONG_POSIX_THREADING_MUTEXKIND_H
#define KONGKONG_POSIX_THREADING_MUTEXKIND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    enum struct MutexKind {
        Normal = PTHREAD_MUTEX_NORMAL,
        ErrorCheck = PTHREAD_MUTEX_ERRORCHECK,
        Recursive = PTHREAD_MUTEX_RECURSIVE,
    };
}

#endif //!KONGKONG_POSIX_THREADING_MUTEXKIND_H
