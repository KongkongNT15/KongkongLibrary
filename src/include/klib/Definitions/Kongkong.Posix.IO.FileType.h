#ifndef KONGKONG_POSIX_IO_FILETYPE_H
#define KONGKONG_POSIX_IO_FILETYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Posix::IO
{
    enum struct FileType {
        Unknown         = DT_UNKNOWN,
        FIFO            = DT_FIFO,
        CharacterFile   = DT_CHR,
        Directory       = DT_DIR,
        BlockFile       = DT_BLK,
        RegularFile     = DT_REG,
        SybolicLink     = DT_LNK,
        Socket          = DT_SOCK,
        WhiteOut        = DT_WHT,
    };
}

#endif //!KONGKONG_POSIX_IO_FILETYPE_H
