#ifndef KONGKONG_WIN32_IO_FILETYPE_H
#define KONGKONG_WIN32_IO_FILETYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct FileType {
        Unknown  = FILE_TYPE_UNKNOWN,
        DiskFile = FILE_TYPE_DISK,
        Char     = FILE_TYPE_CHAR,
        Pipe     = FILE_TYPE_PIPE,
        Remote   = FILE_TYPE_REMOTE,
    };
}

#endif //!KONGKONG_WIN32_IO_FILETYPE_H
