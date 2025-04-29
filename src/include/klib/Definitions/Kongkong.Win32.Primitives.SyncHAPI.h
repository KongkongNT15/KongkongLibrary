#ifndef KONGKONG_WIN32_PRIMITIVES_SYNCHAPI_H
#define KONGKONG_WIN32_PRIMITIVES_SYNCHAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<Synchapi.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/
    class SyncHAPI final {
        public:

        STATIC_CLASS(SyncHAPI)

        /// @brief ふぁ！？っく
        static void ResetEvent(std::nullptr_t) = delete;

        static void ResetEvent(::HANDLE hEvent);

        /// @brief ふぁ！？っく
        static bool ResetEventUnsafe(std::nullptr_t) = delete;

        static bool ResetEventUnsafe(::HANDLE hEvent) noexcept;

        /// @brief ふぁ！？っく
        static void SetEvent(std::nullptr_t) = delete;

        static void SetEvent(::HANDLE hEvent);

        /// @brief ふぁ！？っく
        static bool SetEventUnsafe(std::nullptr_t) = delete;

        static bool SetEventUnsafe(::HANDLE hEvent) noexcept;

        /// @brief ふぁ！？っく
        static WaitStatus WaitForSingleObject(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static WaitStatus WaitForSingleObject(std::nullptr_t, uint32_t) = delete;

        static WaitStatus WaitForSingleObject(HANDLE hObject);
        static WaitStatus WaitForSingleObject(HANDLE hObject, uint32_t milliseconds);

        /// @brief ふぁ！？っく
        static WaitStatus WaitForSingleObjectUnsafe(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static WaitStatus WaitForSingleObjectUnsafe(std::nullptr_t, uint32_t) = delete;

        static WaitStatus WaitForSingleObjectUnsafe(HANDLE hObject) noexcept;
        static WaitStatus WaitForSingleObjectUnsafe(HANDLE hObject, uint32_t milliseconds) noexcept;

        /// @brief ふぁ！？っく
        static WaitObjectInfo WaitForSingleThread(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static WaitObjectInfo WaitForSingleThread(std::nullptr_t, uint32_t) = delete;

        static WaitObjectInfo WaitForSingleThread(HANDLE hObject);
        static WaitObjectInfo WaitForSingleThread(HANDLE hObject, uint32_t milliseconds);

    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_SYNCHAPI_H
