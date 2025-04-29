#ifndef KONGKONG_WIN32_REGISTRYKEYBASE_H
#define KONGKONG_WIN32_REGISTRYKEYBASE_H

#include "Base.h"
#include "Kongkong.HandleType.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class RegistryKeyBase : public HandleType {
        public:

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _key != nullptr; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return _key == nullptr; }

        /// @brief ふぁ！？っく
        void DeleteSubKey(std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        void DeleteSubKey(std::nullptr_t, RegistryKeyAccessRight) const = delete;

        void DeleteSubKey(const char16_t* subKeyName) const;
        void DeleteSubKey(String const& subKeyName) const;
        void DeleteSubKey(const char16_t* subKeyName, RegistryKeyAccessRight accessRight) const;
        void DeleteSubKey(String const& subKeyName, RegistryKeyAccessRight accessRight) const;

        /// @brief ふぁ！？っく
        int32_t DeleteSubKeyUnsafe(std::nullptr_t) const = delete;

        /// @brief ふぁ！？っく
        int32_t DeleteSubKeyUnsafe(std::nullptr_t, RegistryKeyAccessRight) const = delete;

        int32_t DeleteSubKeyUnsafe(const char16_t* subKeyName) const noexcept;
        int32_t DeleteSubKeyUnsafe(String const& subKeyName) const noexcept;
        int32_t DeleteSubKeyUnsafe(const char16_t* subKeyName, RegistryKeyAccessRight accessRight) const noexcept;
        int32_t DeleteSubKeyUnsafe(String const& subKeyName, RegistryKeyAccessRight accessRight) const noexcept;

        /// @brief ふぁ！？っく
        void DeleteTree(std::nullptr_t) const = delete;

        void DeleteTree(const char16_t* subKeyName) const;
        void DeleteTree(String const& subKeyName) const;

        /// @brief ふぁ！？っく
        int32_t DeleteTreeUnsafe(std::nullptr_t) const = delete;

        int32_t DeleteTreeUnsafe(const char16_t* subKeyName) const noexcept;
        int32_t DeleteTreeUnsafe(String const& subKeyName) const noexcept;

        /// @brief ふぁ！？っく
        void DeleteValue(std::nullptr_t) const = delete;

        void DeleteValue(const char16_t* valueName) const;
        void DeleteValue(String const& valueName) const;

        /// @brief ふぁ！？っく
        int32_t DeleteValueUnsafe(std::nullptr_t) const = delete;

        int32_t DeleteValueUnsafe(const char16_t* valueName) const noexcept;
        int32_t DeleteValueUnsafe(String const& valueName) const noexcept;

        /// @brief データをすべて書き込む
        /// @throws HResultException: 操作に失敗したとき
        void Flush() const;

        /// @brief データをすべて書き込む
        /// @return LRESULT
        int32_t FlushUnsafe() const noexcept;

        [[nodiscard]] RegistryKey GetSubKey(const char16_t* subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) const;
        [[nodiscard]] RegistryKey GetSubKey(String const& subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) const;

        [[nodiscard]] RegistryKey GetSubKeyUnsafe(const char16_t* subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) const noexcept;
        [[nodiscard]] RegistryKey GetSubKeyUnsafe(String const& subKeyName, RegistryOption option, RegistryKeyAccessRight accessRight) const noexcept;

        /// @brief 値を取得
        /// @param name 値の名前
        /// @throws HResultException: エラーが発生したとき
        /// @throws MemoryAllocationException: 操作に必要なヒープの作成に失敗したとき
        [[nodiscard]] RegistryValue GetValue(const char16_t* name) const;
        [[nodiscard]] RegistryValue GetValue(String const& name) const;

        /// @brief キーが開かれているかどうか
        [[nodiscard]]
        constexpr bool IsOpen() const noexcept { return _key != nullptr; }

        private:
        ::HKEY _key;

        /// @brief nullptrとして作成
        constexpr RegistryKeyBase(std::nullptr_t) noexcept : _key(nullptr) {}
        constexpr RegistryKeyBase(::HKEY key) noexcept : _key(key) {}

        friend RegistryKey;
        friend RegistryKeyView;
    };
}

#endif //!KONGKONG_WIN32_REGISTRYKEYBASE_H
