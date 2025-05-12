#ifndef KONGKONG_WIN32_MESSAGEBOXBUTTON_H
#define KONGKONG_WIN32_MESSAGEBOXBUTTON_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct MessageBoxButton : long {
        OK                = MB_OK,                //OK
        OKCancel          = MB_OKCANCEL,          //OK・キャンセル
        AbortRetryIgnore  = MB_ABORTRETRYIGNORE,  //中止・再試行・無視
        YesNoCancel       = MB_YESNOCANCEL,       //はい・いいえ・キャンセル
        YesNo             = MB_YESNO,             //はい・いいえ
        RetryCancel       = MB_RETRYCANCEL,       //再試行・キャンセル
        CancelTryContinue = MB_CANCELTRYCONTINUE, //キャンセル・再試行・続行
    };
}

#endif //!KONGKONG_WIN32_MESSAGEBOXBUTTON_H
