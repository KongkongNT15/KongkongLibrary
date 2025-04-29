#ifndef KONGKONG_WIN32_REGISTRYKEY_H
#define KONGKONG_WIN32_REGISTRYKEY_H

#include "Base.h"
#include "Kongkong.Win32.RegistryKeyBase.h"

namespace KONGKONG_NAMESPACE::Win32
{
    /// @brief レジストリ操作
    class RegistryKey final : public RegistryKeyBase {
        public:

        /// @brief HKEY_CLASSES_ROOT
        [[nodiscard]]
        static RegistryKeyView ClassesRoot() noexcept;
        
        /// @brief HKEY_CURRENT_USER
        [[nodiscard]]
        static RegistryKeyView CurrentConfig() noexcept;
        
        /// @brief HKEY_LOCAL_MACHINE
        [[nodiscard]]
        static RegistryKeyView CurrentUser() noexcept;
        
        /// @brief HKEY_USERS
        [[nodiscard]]
        static RegistryKeyView LocalMachine() noexcept;
        
        /// @brief HKEY_CURRENT_CONFIG
        [[nodiscard]]
        static RegistryKeyView Users() noexcept;

        RegistryKey(RegistryKey const&) = delete;

        constexpr RegistryKey(RegistryKey&& right) noexcept : RegistryKeyBase(right._key) {}

        /// @brief nullptrとして作成
        constexpr RegistryKey(std::nullptr_t) noexcept : RegistryKeyBase(nullptr) {}

        ~RegistryKey();

        RegistryKey& operator=(RegistryKey const&) = delete;

        RegistryKey& operator=(RegistryKey&& right) noexcept;

        private:
        using RegistryKeyBase::RegistryKeyBase;

    };
}


#endif //!KONGKONG_WIN32_REGISTRYKEY_H
