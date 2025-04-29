#ifndef KONGKONG_WIN32_UI_CONTROL_H
#define KONGKONG_WIN32_UI_CONTROL_H

#include "Base.h"
#include "Kongkong.Win32.UI.UIElement.h"

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    struct KONGKONG_INCOMPLETED_CLASS Control : public UIElement {
        static uint16_t _idCount;

        Control() : _id(_idCount++) {}

        constexpr uint16_t Id() const noexcept { return _id; }

        String ToString() const override;

        private:
        uint16_t _id;
    };
}

namespace KONGKONG_NAMESPACE::Win32::UI
{

}

#endif //!KONGKONG_WIN32_UI_CONTROL_H
