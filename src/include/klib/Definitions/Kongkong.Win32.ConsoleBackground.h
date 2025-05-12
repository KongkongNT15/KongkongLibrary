#ifndef KONGKONG_WIN32_CONSOLEBACKGROUND_H
#define KONGKONG_WIN32_CONSOLEBACKGROUND_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    enum struct ConsoleBackground : int16_t {
        Black        = 0,
        Blue         = BACKGROUND_BLUE,
        Green        = BACKGROUND_GREEN,
        Red          = BACKGROUND_RED,
        Intensity    = BACKGROUND_INTENSITY,
        Cyan         = Blue | Green,
        Magenta      = Blue | Red,
        Yellow       = Green | Red,
        LightBlue    = Blue | Intensity,
        LightGreen   = Green | Intensity,
        LightRed     = Red | Intensity,
        LightCyan    = Cyan | Intensity,
        LightMagenta = Magenta | Intensity,
        LightYellow  = Yellow | Intensity,
        White        = Blue | Green | Red,
    };
}

#endif //!KONGKONG_WIN32_CONSOLEBACKGROUND_H
