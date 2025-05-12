#ifndef KONGKONG_WIN32_MESSAGEBOXMODALITY_H
#define KONGKONG_WIN32_MESSAGEBOXMODALITY_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct MessageBoxModality : long {
        ApplicationModal = MB_APPLMODAL,
        SystemModal      = MB_SYSTEMMODAL,
        TaskModal        = MB_TASKMODAL,
    };
}

#endif //!KONGKONG_WIN32_MESSAGEBOXMODALITY_H
