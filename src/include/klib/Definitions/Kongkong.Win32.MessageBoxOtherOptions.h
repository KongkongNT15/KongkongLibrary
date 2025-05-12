#ifndef KONGKONG_WIN32_MESSAGEBOXOTHEROPTIONS_H
#define KONGKONG_WIN32_MESSAGEBOXOTHEROPTIONS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    //1つ以上使う
    enum struct MessageBoxOtherOptions : long {
        None                = MB_OK,
        SetForeground       = MB_SETFOREGROUND,
        DefaultDesktopOnly  = MB_DEFAULT_DESKTOP_ONLY,
        TopMost             = MB_TOPMOST,
        RightAlign          = MB_RIGHT,
        RightToLeftReading  = MB_RTLREADING,
        ServiceNotification = MB_SERVICE_NOTIFICATION,
    };

    CREATE_OPERATOR_AND_OR(MessageBoxOtherOptions)
}

#endif //!KONGKONG_WIN32_MESSAGEBOXOTHEROPTIONS_H
