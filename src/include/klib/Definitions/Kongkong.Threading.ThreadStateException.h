#ifndef KONGKONG_THREADING_THREADSTATEEXCEPTION_H
#define KONGKONG_THREADING_THREADSTATEEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE::Threading
{
    struct ThreadStateException : public Exception {
        using Exception::Exception;
    };
}

#endif //!KONGKONG_THREADING_THREADSTATEEXCEPTION_H
