#ifndef KONGKONG_WIN32_IO_DRIVEKIND_H
#define KONGKONG_WIN32_IO_DRIVEKIND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::IO
{
    enum struct DriveKind {
        Unknown         = DRIVE_UNKNOWN,
        NoRootDirectory = DRIVE_NO_ROOT_DIR,
        Removable       = DRIVE_REMOVABLE,
        Fixed           = DRIVE_FIXED,
        Remote          = DRIVE_REMOTE,
        CDROM           = DRIVE_CDROM,
        RAMDisk         = DRIVE_RAMDISK,
    };
}

#endif //!KONGKONG_WIN32_IO_DRIVEKIND_H
