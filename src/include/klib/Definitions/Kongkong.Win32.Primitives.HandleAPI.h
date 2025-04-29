#ifndef KONGKONG_WIN32_PRIMITIVES_HANDLEAPI_H
#define KONGKONG_WIN32_PRIMITIVES_HANDLEAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<Handleapi.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/handleapi/
    class HandleAPI final {
        public:

        STATIC_CLASS(HandleAPI)

        static void Close(::HANDLE hObject);

        [[nodiscard]] HandleFrag GetFrags(::HANDLE hObject);

        [[nodiscard]] bool IsEqual(::HANDLE left, ::HANDLE right) noexcept;

        [[nodiscard]] static constexpr ::HANDLE InvalidValue() noexcept { return INVALID_HANDLE_VALUE; }
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_HANDLEAPI_H
