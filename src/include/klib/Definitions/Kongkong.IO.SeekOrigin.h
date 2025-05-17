#ifndef KONGKONG_IO_SEEKORIGIN_H
#define KONGKONG_IO_SEEKORIGIN_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::IO
{
    enum struct SeekOrigin {
        Begin,
        Current,
        End
    };
}

#endif //!KONGKONG_IO_SEEKORIGIN_H