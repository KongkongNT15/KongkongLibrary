#ifndef KONGKONG_WIN32_CLASSTYPE_H
#define KONGKONG_WIN32_CLASSTYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct ClassType {
        Event,
        Handle,
        Mutex,
        Null,
        InputDevice,
        IODevice,
        OutputDevice,
        Semaphore,
        Stream,
        Thread,
        WaitHandle,
    };
}

#endif //!KONGKONG_WIN32_CLASSTYPE_H
