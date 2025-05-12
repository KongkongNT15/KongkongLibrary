#ifndef KONGKONG_WIN32_MESSEGEBEEPKIND_H
#define KONGKONG_WIN32_MESSEGEBEEPKIND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct MessageBeepKind : long {
        DefaultBeep = MB_OK,
        Error       = MB_ICONERROR,
        Question    = MB_ICONQUESTION,
        Warning     = MB_ICONWARNING,
        Information = MB_ICONINFORMATION,
        SimpleBeep  = -1L,
    };
}

#endif //!KONGKONG_WIN32_MESSEGEBEEPKIND_H
