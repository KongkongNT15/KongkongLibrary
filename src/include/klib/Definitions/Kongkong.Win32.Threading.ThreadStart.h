#ifndef KONGKONG_WIN32_THREADSTART_H
#define KONGKONG_WIN32_THREADSTART_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    enum struct ThreadStart {
        RightAway                        = 0,
        Suspended                        = CREATE_SUSPENDED,
        StackSizeParameterIsAReservation = STACK_SIZE_PARAM_IS_A_RESERVATION,
    };
}

#endif //!KONGKONG_WIN32_THREADSTART_H
