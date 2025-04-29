#ifndef KONGKONG_WIN32_PRIMITIVES_WINDOWSEREGISTRY_H
#define KONGKONG_WIN32_PRIMITIVES_WINDOWSEREGISTRY_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Primitives
{
    //<winreg.h>
    //https://learn.microsoft.com/ja-jp/windows/win32/api/winreg/
    class WinRegistry final {
        public:

        STATIC_CLASS(WinRegistry)

        /// @brief ふぁ！？っく
        static void CloseKey(std::nullptr_t) = delete;

        /// @brief レジストリキーのハンドルを閉じる
        /// @param hKey 閉じるハンドル
        /// @throws HResultException: 操作に失敗したとき 
        static void CloseKey(::HKEY hKey);

        /// @brief ふぁ！？っく
        static void DeleteSubKey(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void DeleteSubKey(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static void DeleteSubKey(std::nullptr_t, String const&) = delete;

        /// @brief ふぁ！？っく
        static void DeleteSubKey(::HKEY, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void DeleteSubKey(std::nullptr_t, std::nullptr_t, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static void DeleteSubKey(std::nullptr_t, const char16_t*, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static void DeleteSubKey(std::nullptr_t, String const&, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static void DeleteSubKey(::HKEY, std::nullptr_t, RegistryKeyAccessRight) = delete;

        static void DeleteSubKey(::HKEY hKey, const char16_t* subKeyName);
        static void DeleteSubKey(::HKEY hKey, String const& subKeyName);
        static void DeleteSubKey(::HKEY hKey, const char16_t* subKeyName, RegistryKeyAccessRight accessRight);
        static void DeleteSubKey(::HKEY hKey, String const& subKeyName, RegistryKeyAccessRight accessRight);

        /// @brief ふぁ！？っく
        static int32_t DeleteSubKeyUnsafe(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteSubKeyUnsafe(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteSubKeyUnsafe(std::nullptr_t, String const&) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteSubKeyUnsafe(::HKEY, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteSubKeyUnsafe(std::nullptr_t, std::nullptr_t, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteSubKeyUnsafe(std::nullptr_t, const char16_t*, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteSubKeyUnsafe(std::nullptr_t, String const&, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteSubKeyUnsafe(::HKEY, std::nullptr_t, RegistryKeyAccessRight) = delete;

        static int32_t DeleteSubKeyUnsafe(::HKEY hKey, const char16_t* subKeyName) noexcept;
        static int32_t DeleteSubKeyUnsafe(::HKEY hKey, String const& subKeyName) noexcept;
        static int32_t DeleteSubKeyUnsafe(::HKEY hKey, const char16_t* subKeyName, RegistryKeyAccessRight accessRight) noexcept;
        static int32_t DeleteSubKeyUnsafe(::HKEY hKey, String const& subKeyName, RegistryKeyAccessRight accessRight) noexcept;

        /// @brief ふぁ！？っく
        static void DeleteTree(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void DeleteTree(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static void DeleteTree(std::nullptr_t, String const&) = delete;

        /// @brief ふぁ！？っく
        static void DeleteTree(::HKEY, std::nullptr_t) = delete;

        static void DeleteTree(::HKEY hKey, const char16_t* subKeyName);
        static void DeleteTree(::HKEY hKey, String const& subKeyName);

        /// @brief ふぁ！？っく
        static int32_t DeleteTreeUnsafe(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteTreeUnsafe(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteTreeUnsafe(std::nullptr_t, String const&) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteTreeUnsafe(::HKEY, std::nullptr_t) = delete;

        static int32_t DeleteTreeUnsafe(::HKEY hKey, const char16_t* subKeyName) noexcept;
        static int32_t DeleteTreeUnsafe(::HKEY hKey, String const& subKeyName) noexcept;

        /// @brief ふぁ！？っく
        static void DeleteValue(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static void DeleteValue(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static void DeleteValue(std::nullptr_t, String const&) = delete;

        /// @brief ふぁ！？っく
        static void DeleteValue(::HKEY, std::nullptr_t) = delete;

        static void DeleteValue(::HKEY hKey, const char16_t* valueName);
        static void DeleteValue(::HKEY hKey, String const& valueName);

        /// @brief ふぁ！？っく
        static int32_t DeleteValueUnsafe(std::nullptr_t, std::nullptr_t) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteValueUnsafe(std::nullptr_t, const char16_t*) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteValueUnsafe(std::nullptr_t, String const&) = delete;

        /// @brief ふぁ！？っく
        static int32_t DeleteValueUnsafe(::HKEY, std::nullptr_t) = delete;

        static int32_t DeleteValueUnsafe(::HKEY hKey, const char16_t* valueName) noexcept;
        static int32_t DeleteValueUnsafe(::HKEY hKey, String const& valueName) noexcept;

        /// @brief ふぁ！？っく
        static void FlushKey(std::nullptr_t) = delete;

        /// @brief データをすべて書き込む
        /// @param hKey キーのハンドル
        /// @throws HResultException: 操作に失敗したとき
        static void FlushKey(::HKEY hKey);

        [[nodiscard]] static constexpr uint32_t MaxRegistryKeyNameLength() noexcept { return 255; }
        [[nodiscard]] static constexpr uint32_t MaxRegistryValueNameLength() noexcept { return 16383; }

        /// @brief ふぁ！？っく
        static ::HKEY OpenKey(std::nullptr_t, std::nullptr_t, RegistryOption, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static ::HKEY OpenKey(std::nullptr_t, const char16_t*, RegistryOption, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static ::HKEY OpenKey(std::nullptr_t, String const&, RegistryOption, RegistryKeyAccessRight) = delete;

        /// @brief ふぁ！？っく
        static ::HKEY OpenKey(::HKEY, std::nullptr_t, RegistryOption, RegistryKeyAccessRight) = delete;

        [[nodiscard]] static ::HKEY OpenKey(::HKEY hKey, const char16_t* subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight);
        [[nodiscard]] static ::HKEY OpenKey(::HKEY hKey, String const& subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight);

        [[nodiscard]] static ::HKEY OpenKeyUnsafe(::HKEY hKey, const char16_t* subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) noexcept;
        [[nodiscard]] static ::HKEY OpenKeyUnsafe(::HKEY hKey, String const& subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) noexcept;

    };
}

#endif //!KONGKONG_WIN32_PRIMITIVES_WINDOWSEREGISTRY_H
