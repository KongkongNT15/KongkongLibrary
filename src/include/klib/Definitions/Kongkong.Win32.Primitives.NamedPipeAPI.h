#ifndef KONGKONG_WIN32_PRIMITIVES_NAMEDPIPEAPI_H
#define KONGKONG_WIN32_PRIMITIVES_NAMEDPIPEAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<namedpipeapi.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/namedpipeapi/
    class NamedPipeAPI final {
        public:

        STATIC_CLASS(NamedPipeAPI)

        //匿名パイプ
        static void Create(HANDLE& hReadPipe, HANDLE& hWritePipe);
        static void Create(HANDLE& hReadPipe, HANDLE& hWritePipe, uint32_t bufferSize);
        static void Create(HANDLE& hReadPipe, HANDLE& hWritePipe, ::SECURITY_ATTRIBUTES& securityAttributes);
        static void Create(HANDLE& hReadPipe, HANDLE& hWritePipe, ::SECURITY_ATTRIBUTES& securityAttributes, uint32_t bufferSize);

        static void WaitNamedPipe(const char16_t* pipeName);
        static void WaitNamedPipe(String const& pipeName);
        static void WaitNamedPipe(const char16_t* pipeName, uint32_t wait);
        static void WaitNamedPipe(String const& pipeName, uint32_t wait);

        static void WaitNamedPipeForever(const char16_t* pipeName);
        static void WaitNamedPipeForever(String const& pipeName);
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_NAMEDPIPEAPI_H
