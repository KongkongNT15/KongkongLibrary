#ifndef KONGKONG_WIN32_CONSOLEFOREGROUND_H
#define KONGKONG_WIN32_CONSOLEFOREGROUND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct ConsoleForeground : int16_t {
        Black     = 0,
        Blue      = FOREGROUND_BLUE,
        Green     = FOREGROUND_GREEN,
        Red       = FOREGROUND_RED,
        Intensity = FOREGROUND_INTENSITY,
        Cyan      = Blue | Green,
        Magenta   = Blue | Red,
        Yellow    = Green | Red,
        White     = Blue | Green | Red,
    };
}

#endif //!KONGKONG_WIN32_CONSOLEFOREGROUND_H
