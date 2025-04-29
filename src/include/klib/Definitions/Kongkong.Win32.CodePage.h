#ifndef KONGKONG_WIN32_CODEPAGE_H
#define KONGKONG_WIN32_CODEPAGE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    //Kongkong::Win32::StringHelper::ToString()
    //で使用
    enum struct CodePage : unsigned {
        DefaultANSI        = CP_ACP,
        DefaultOEM         = CP_OEMCP,
        DefaultMacintosh   = CP_MACCP,
        CurrentThreadsANSI = CP_THREAD_ACP,
        Symbol             = CP_SYMBOL,
        Utf7               = CP_UTF7,
        Utf8               = CP_UTF8,
    };
}

#endif //!KONGKONG_WIN32_CODEPAGE_H
