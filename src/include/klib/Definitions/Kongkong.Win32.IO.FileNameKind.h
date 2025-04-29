#ifndef KONGKONG_WIN32_IO_FILENAMEKIND_H
#define KONGKONG_WIN32_IO_FILENAMEKIND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct FileNameKind {
        Normalized = FILE_NAME_NORMALIZED,
        Opened     = FILE_NAME_OPENED,
    };
}

#endif //!KONGKONG_WIN32_IO_FILENAMEKIND_H
