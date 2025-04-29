#ifndef KONGKONG_WIN32_CHARHELPER_H
#define KONGKONG_WIN32_CHARHELPER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class CharHelper final {
        public:

        STATIC_CLASS(CharHelper)

        [[nodiscard]] static bool IsAlpha(char16_t c) noexcept;
        [[nodiscard]] static bool IsLower(char16_t c) noexcept;
        [[nodiscard]] static bool IsUpper(char16_t c) noexcept;

        [[nodiscard]] static char16_t ToLower(char16_t c) noexcept;
        [[nodiscard]] static char16_t ToUpper(char16_t c) noexcept;

    };
}

#endif //!KONGKONG_WIN32_CHARHELPER_H
