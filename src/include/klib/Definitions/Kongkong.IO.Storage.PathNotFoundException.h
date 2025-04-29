#ifndef KONGKONG_IO_STORAGE_PATHNOTFOUNDEXCEPTION_H
#define KONGKONG_IO_STORAGE_PATHNOTFOUNDEXCEPTION_H

#include "Base.h"
#include "Kongkong.IOException.h"

namespace KONGKONG_NAMESPACE::IO::Storage
{
    struct PathNotFoundException : public IOException {
        using IOException::IOException;
    };
}

#endif //!KONGKONG_IO_STORAGE_PATHNOTFOUNDEXCEPTION_H
