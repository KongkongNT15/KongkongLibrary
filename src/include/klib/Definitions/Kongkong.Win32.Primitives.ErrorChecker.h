#ifndef KONGKONG_WIN32_PRIMITIVES_ERRORCHECKER_H
#define KONGKONG_WIN32_PRIMITIVES_ERRORCHECKER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    /// @brief Win32APIのエラーチェック
    class ErrorChecker final {
        public:

        STATIC_CLASS(ErrorChecker)

        static void CheckBool(::BOOL value);
        static void CheckHResult(::HRESULT value);
        static void CheckSystemError(::DWORD value);

        static void CheckError(::BOOL value);
        static void CheckError(::HRESULT value);
        static void CheckError(::DWORD value);

        [[nodiscard]] static uint32_t LastError() noexcept;
        static void LastError(uint32_t errorCode) noexcept;
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_ERRORCHECKER_H
