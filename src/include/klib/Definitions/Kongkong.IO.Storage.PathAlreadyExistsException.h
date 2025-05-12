#ifndef KONGKONG_IO_STORAGE_PATHALREADYEXISTSEXCEPTION_H
#define KONGKONG_IO_STORAGE_PATHALREADYEXISTSEXCEPTION_H

#include "Base.h"
#include "Kongkong.IOException.h"

namespace KONGKONG_NAMESPACE::IO::Storage
{
    /// @brief パスが既に存在しているとき
    struct PathAlreadyExistsException : public IOException {
        using IOException::IOException;
    };
}

#endif //!KONGKONG_IO_STORAGE_PATHALREADYEXISTSEXCEPTION_H
