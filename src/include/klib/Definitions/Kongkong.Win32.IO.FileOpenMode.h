#ifndef KONGKONG_WIN32_IO_FILEOPENMODE_H
#define KONGKONG_WIN32_IO_FILEOPENMODE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct FileOpenMode {
        CreateNew        = CREATE_NEW,
        CreateAlways     = CREATE_ALWAYS,
        OpenExisting     = OPEN_EXISTING,
        OpenAlways       = OPEN_ALWAYS,
        TruncateExisting = TRUNCATE_EXISTING,
    };
}

#endif //!KONGKONG_WIN32_IO_FILEOPENMODE_H
