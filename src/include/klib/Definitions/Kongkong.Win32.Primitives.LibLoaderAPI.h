#ifndef KONGKONG_WIN32_PRIMITIVES_LIBLOADERAPI_H
#define KONGKONG_WIN32_PRIMITIVES_LIBLOADERAPI_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<libloaderapi.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/libloaderapi/
    class LibLoaderAPI final {
        public:

        STATIC_CLASS(LibLoaderAPI)

        /// @brief ふぁ！？っく
        static void FreeLibrary(std::nullptr_t) = delete;

        static void FreeLibrary(::HMODULE hLibraryModule);

        /// @brief ふぁ！？っく
        static String GetModuleFileName(std::nullptr_t) = delete;

        [[nodiscard]] static String GetModuleFileName(::HMODULE hModule);

        /// @brief ふぁ！？っく
        void* GetProcedureAdress(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void* GetProcedureAdress(::HMODULE, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        void* GetProcedureAdress(std::nullptr_t, const char*) = delete;

        /// @brief ふぁ！？っく
        void* GetProcedureAdress(std::nullptr_t, const char16_t*) = delete;

        [[nodiscard]] static void* GetProcedureAdress(::HMODULE hModule, const char* procName);
        [[nodiscard]] static void* GetProcedureAdress(::HMODULE hModule, const char16_t* procName);
        [[nodiscard]] static void* GetProcedureAdress(::HMODULE hModule, String const& procName);

        /// @brief ふぁ！？っく
        static ::HMODULE LoadLibrary(std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static ::HMODULE LoadLibrary(std::nullptr_t, LoadLibraryFlag flag) = delete;

        [[nodiscard]] static ::HMODULE LoadLibrary(const char16_t* libraryFileName);
        [[nodiscard]] static ::HMODULE LoadLibrary(String const& libraryFileName);
        [[nodiscard]] static ::HMODULE LoadLibrary(const char16_t* libraryFileName, LoadLibraryFlag flag);
        [[nodiscard]] static ::HMODULE LoadLibrary(String const& libraryFileName, LoadLibraryFlag flag);
    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_LIBLOADERAPI_H
