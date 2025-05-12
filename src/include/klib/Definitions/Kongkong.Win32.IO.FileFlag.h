#ifndef KONGKONG_WIN32_IO_FILEFLAG_H
#define KONGKONG_WIN32_IO_FILEFLAG_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct FileFlag : unsigned {
        None              = 0,
        FirstPipeInstance = FILE_FLAG_FIRST_PIPE_INSTANCE,
        OpenNoRecall      = FILE_FLAG_OPEN_NO_RECALL,
        OpenReparsePoint  = FILE_FLAG_OPEN_REPARSE_POINT,
        SessionAware      = FILE_FLAG_SESSION_AWARE,
        PosixSemantics    = FILE_FLAG_POSIX_SEMANTICS,
        BackupSemantics   = FILE_FLAG_BACKUP_SEMANTICS,
        DeleteOnClose     = FILE_FLAG_DELETE_ON_CLOSE,
        SequentialScan    = FILE_FLAG_SEQUENTIAL_SCAN,
        RandomAccess      = FILE_FLAG_RANDOM_ACCESS,
        NoBuffering       = FILE_FLAG_NO_BUFFERING,
        Overlapped        = FILE_FLAG_OVERLAPPED,
        WriteThrough      = FILE_FLAG_WRITE_THROUGH,
    };

    CREATE_OPERATOR_AND_OR(FileFlag)
}

#endif //!KONGKONG_WIN32_IO_FILEFLAG_H
