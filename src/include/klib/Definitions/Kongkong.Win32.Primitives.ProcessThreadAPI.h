#ifndef KONGKONG_WIN32_PRIMITIVES_PROCESSTHREADAPI_H
#define KONGKONG_WIN32_PRIMITIVES_PROCESSTHREADAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<processthreadsapi.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/processthreadsapi/
    class ProcessThreadAPI final {
        public:

        STATIC_CLASS(ProcessThreadAPI)

        [[nodiscard]] static ::HANDLE CreateProcess(const char16_t* applicationName, const char16_t* commandLine, SECURITY_ATTRIBUTES& processAttribute, SECURITY_ATTRIBUTES& threadAttribute, bool inheritHandles);

        [[nodiscard]] static uint32_t GetExitCodeThread(::HANDLE hObject);
        [[nodiscard]] static uint32_t GetExitCodeThreadUnsafe(::HANDLE hObject) noexcept;

        [[nodiscard]] static uint32_t GetThreadId(::HANDLE hThread);

        [[nodiscard]] static uint32_t ResumeThread(::HANDLE hThread);

        [[nodiscard]] static uint32_t SuspendThread(::HANDLE hThread);

        static void TerminateThread(::HANDLE hThread, uint32_t exitCode);

    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_PROCESSTHREADAPI_H
