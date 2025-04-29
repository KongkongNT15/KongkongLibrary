#ifndef KONGKONG_WIN32_IO_FILESHAREMODE_H
#define KONGKONG_WIN32_IO_FILESHAREMODE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct FileShareMode {
        Private     = 0,
        ShareRead   = FILE_SHARE_READ,
        ShareWrite  = FILE_SHARE_WRITE,
        ShareDelete = FILE_SHARE_DELETE,
    };
}

#endif //!KONGKONG_WIN32_IO_FILESHAREMODE_H
