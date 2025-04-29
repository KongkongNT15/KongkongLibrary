#ifndef KONGKONG_WIN32_UI_WINDOWACTIVATE_H
#define KONGKONG_WIN32_UI_WINDOWACTIVATE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    enum struct WindowActivate {
        Inactive    = WA_INACTIVE,      //非アクティブ
        Active      = WA_ACTIVE,        //キーボードやAPIによるアクティブ化
        ClickActive = WA_CLICKACTIVE,   //マウスクリックによるアクティブ化
    };
}

#endif //!KONGKONG_WIN32_UI_WINDOWACTIVATE_H
