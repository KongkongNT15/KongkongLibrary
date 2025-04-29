#ifndef KONGKONG_WIN32_UI_SIZE_H
#define KONGKONG_WIN32_UI_SIZE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"

#include <sstream>

namespace KONGKONG_NAMESPACE::Win32::UI
{
    template <NumberType TNum>
    struct _Size final : public ValueType {

        constexpr _Size(TNum width, TNum height) noexcept : _width(width), _height(height) {}

        constexpr TNum Height() const noexcept { return _height; }
        constexpr TNum Height(TNum value) noexcept { _height = value; }

        String ToString() const
        {
            std::ostringstream sout;

            sout << Width() << ", " << Height();

            return String::FromAscii(sout.str());
        }

        constexpr TNum Width() const noexcept { return _width; }
        constexpr TNum Width(TNum value) noexcept { _width = value; }

        private:
        TNum _width;
        TNum _height;
    };
}

#endif //!KONGKONG_WIN32_UI_SIZE_H
