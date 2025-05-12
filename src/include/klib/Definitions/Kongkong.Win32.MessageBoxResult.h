#ifndef KONGKONG_WIN32_MESSAGEBOXRESULT_H
#define KONGKONG_WIN32_MESSAGEBOXRESULT_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct MessageBoxResult {
        OK       = IDOK,
        Cancel   = IDCANCEL,
        Abort    = IDABORT,
        Retry    = IDRETRY,
        Ignore   = IDIGNORE,
        Yes      = IDYES,
        No       = IDNO,
        TryAgain = IDTRYAGAIN,
        Continue = IDCONTINUE,
    };
}

#endif //!KONGKONG_WIN32_MESSAGEBOXRESULT_H
