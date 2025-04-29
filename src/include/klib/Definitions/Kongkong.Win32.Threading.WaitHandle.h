#ifndef KONGKONG_WIN32_THREADING_WAITHANDLE_H
#define KONGKONG_WIN32_THREADING_WAITHANDLE_H

#include "Base.h"
#include "Kongkong.Win32.Handle.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class WaitHandle : public Handle {
        public:
        using Handle::Handle;

        WaitStatus Wait() const;
        WaitStatus Wait(uint32_t milliSeconds) const;

        WaitStatus WaitUnsafe() const noexcept;
        WaitStatus WaitUnsafe(uint32_t milliSeconds) const noexcept;
    };
}

#endif //!KONGKONG_WIN32_THREADING_WAITHANDLE_H
