#ifndef KONGKONG_CSTD_CFILEPOSITION_H
#define KONGKONG_CSTD_CFILEPOSITION_H

#include "Base.h"

#include <stdio.h>

namespace KONGKONG_NAMESPACE::Standard
{
    enum struct CFilePosition {
        Begin   = SEEK_SET,
        Current = SEEK_CUR,
        End     = SEEK_END,
    };
}

#endif //!KONGKONG_CSTD_CFILEPOSITION_H
