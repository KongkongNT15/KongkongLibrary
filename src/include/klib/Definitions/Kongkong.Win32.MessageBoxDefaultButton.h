#ifndef KONGKONG_WIN32_MESSAGEBOXDEFAULTBUTTON_H
#define KONGKONG_WIN32_MESSAGEBOXDEFAULTBUTTON_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct MessageBoxDefaultButton : long {
        Button1 = MB_DEFBUTTON1,
        Button2 = MB_DEFBUTTON2,
        Button3 = MB_DEFBUTTON3,
        Button4 = MB_DEFBUTTON4,
    };
}

#endif //!KONGKONG_WIN32_MESSAGEBOXDEFAULTBUTTON_H
