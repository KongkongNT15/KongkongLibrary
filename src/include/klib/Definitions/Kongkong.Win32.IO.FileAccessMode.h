#ifndef KONGKONG_WIN32_IO_FILEACCESSMODE_H
#define KONGKONG_WIN32_IO_FILEACCESSMODE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct FileAccessMode : unsigned long {
        Read         = GENERIC_READ,
        Write        = GENERIC_WRITE,
        ReadAndWrite = Read | Write,
    };
}

#endif //!KONGKONG_WIN32_IO_FILEACCESSMODE_H
