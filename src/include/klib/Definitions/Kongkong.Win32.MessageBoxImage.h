#ifndef KONGKONG_WIN32_MESSAGEBOXIMAGE_H
#define KONGKONG_WIN32_MESSAGEBOXIMAGE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct MessageBoxImage : long {
        None        = MB_OK,
        Error       = MB_ICONERROR,
        Question    = MB_ICONQUESTION,
        Warning     = MB_ICONWARNING,
        Information = MB_ICONINFORMATION,
    };
}

#endif //!KONGKONG_WIN32_MESSAGEBOXIMAGE_H
