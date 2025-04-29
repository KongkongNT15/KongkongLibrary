#ifndef KONGKONG_WIN32_IO_VOLUMENAMEKIND_H
#define KONGKONG_WIN32_IO_VOLUMENAMEKIND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct VolumeNameKind {
        DOS  = VOLUME_NAME_DOS,
        GUID = VOLUME_NAME_GUID,
        NT   = VOLUME_NAME_NT,
        None = VOLUME_NAME_NONE,
    };
}

#endif //!KONGKONG_WIN32_IO_VOLUMENAMEKIND_H
