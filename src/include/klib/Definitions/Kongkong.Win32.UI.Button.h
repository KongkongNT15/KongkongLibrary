#ifndef KONGKONG_WIN32_UI_BUTTON_H
#define KONGKONG_WIN32_UI_BUTTON_H

#include "Base.h"
#include "Kongkong.Win32.UI.ButtonBase.h"

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    struct KONGKONG_INCOMPLETED_CLASS Button : public ButtonBase {

        Button();

        String ToString() const override;

    };
}

namespace KONGKONG_NAMESPACE::Win32::UI
{

}

#endif //!KONGKONG_WIN32_UI_BUTTON_H
