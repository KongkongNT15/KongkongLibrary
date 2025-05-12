#ifndef KONGKONG_POSIX_IO_FILEMODE_H
#define KONGKONG_POSIX_IO_FILEMODE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    enum struct FileMode : mode_t {
        FileMask        = S_IFMT,
        FIFO            = S_IFIFO,
        CharacterFile   = S_IFCHR,
        Directory       = S_IFDIR,
        BlockFile       = S_IFBLK,
        RegularFile     = S_IFREG,
        SymbolicLink    = S_IFLNK,
        Socket          = S_IFSOCK,
        RWXForUser      = S_IRWXU,
        ReadForUser     = S_IRUSR,
        WriteForUser    = S_IWUSR,
        ExecuteForUser  = S_IXUSR,
        RWXForGroup     = S_IRWXG,
        ReadForGroup    = S_IRGRP,
        WriteForGroup   = S_IWGRP,
        ExecuteForGroup = S_IXGRP,
        RWXForOther     = S_IRWXO,
        ReadForOther    = S_IROTH,
        WriteForOther   = S_IWOTH,
        ExecuteForOther = S_IXOTH,
        SetUID          = S_ISUID,
        SetGID          = S_ISGID,
        SetVTX          = S_ISVTX,

        ReadForAll = ReadForUser | ReadForGroup | ReadForOther,
        WriteForAll = WriteForUser | WriteForGroup | WriteForOther,
        RWXForAll = RWXForUser | RWXForGroup | RWXForOther,
    };

    CREATE_OPERATOR_AND_OR(FileMode)
}

#endif //!KONGKONG_POSIX_IO_FILEMODE_H
