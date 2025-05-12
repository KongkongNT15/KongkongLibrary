#ifndef KONGKONG_WIN32_CTRLKEYEVENTKIND_H
#define KONGKONG_WIN32_CTRLKEYEVENTKIND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct CtrlKeyEventKind {
        C        = CTRL_C_EVENT,
        Break    = CTRL_BREAK_EVENT,
        Close    = CTRL_CLOSE_EVENT,
        Logoff   = CTRL_LOGOFF_EVENT,
        Shutdown = CTRL_SHUTDOWN_EVENT,
    };
}

#endif //!KONGKONG_WIN32_CTRLKEYEVENTKIND_H
