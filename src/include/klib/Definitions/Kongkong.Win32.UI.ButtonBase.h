#ifndef KONGKONG_WIN32_UI_BUTTONBASE_H
#define KONGKONG_WIN32_UI_BUTTONBASE_H

#include "Base.h"
#include "Kongkong.Events.EventHandler.h"
#include "Kongkong.Win32.UI.Control.h"

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    struct KONGKONG_INCOMPLETED_CLASS ButtonBase : public Control {

        constexpr auto& Click() noexcept { return _click.List(); }

        ClickEventHandler _click;
    };
}

namespace KONGKONG_NAMESPACE::Win32::UI
{

}

#endif //!KONGKONG_WIN32_UI_BUTTONBASE_H
