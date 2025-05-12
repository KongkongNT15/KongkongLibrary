#ifndef KONGKONG_POSIX_IO_FILEOPEN_H
#define KONGKONG_POSIX_IO_FILEOPEN_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    enum struct FileOpen {
        ReadOnly          = O_RDONLY,
        WriteOnly         = O_WRONLY,
        ReadWrite         = O_RDWR,
        NoDelay           = O_NONBLOCK,
        Append            = O_APPEND,
        SharedFileLock    = O_SHLOCK,
        ExclusiveFileLock = O_EXLOCK,
        Async             = O_ASYNC,
        Sync              = O_FSYNC,
        NoFollowSymlinks  = O_NOFOLLOW,
        Create            = O_CREAT,
        Trunc             = O_TRUNC,
        ErrorIfExists     = O_EXCL,
    };

    CREATE_OPERATOR_AND_OR(FileOpen)
}

#endif //!KONGKONG_POSIX_IO_FILEOPEN_H
