#ifndef KONGKONG_IO_PIPEDIRECTION_H
#define KONGKONG_IO_PIPEDIRECTION_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::IO
{
    enum struct PipeDirection {
        In,
        Out,
        InOut
    };
}

#endif //!KONGKONG_IO_PIPEDIRECTION_H