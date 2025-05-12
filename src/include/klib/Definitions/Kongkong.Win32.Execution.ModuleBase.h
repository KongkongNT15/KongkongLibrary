#ifndef KONGKONG_WIN32_MODULEBASE_H
#define KONGKONG_WIN32_MODULEBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Execution
{
    class ModuleBase : public KongkongTypeBase {
        public:

        ModuleBase(ModuleBase const& module) = delete;
        ModuleBase(ModuleBase&& module) = delete;

        ModuleBase& operator=(ModuleBase const& module) = delete;
        ModuleBase& operator=(ModuleBase&& module) = delete;

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _module != nullptr; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return _module == nullptr; }

        [[nodiscard]] String FullPath() const;

        /// @brief ふぁ！？っく
        void* GetProcedureAdress(std::nullptr_t) const = delete;

        [[nodiscard]] void* GetProcedureAdress(const char* procName) const;
        [[nodiscard]] void* GetProcedureAdress(const char16_t* procName) const;
        [[nodiscard]] void* GetProcedureAdress(String const& procName) const;

        [[nodiscard]]
        constexpr bool IsLoaded() const noexcept { return _module != nullptr; }

        [[nodiscard]]
        String ToString() const;
        
        private:
        ::HMODULE _module;

        constexpr ModuleBase(::HMODULE module) noexcept : _module(module) {}

        /// @brief nullptrとして作成
        constexpr ModuleBase(std::nullptr_t) noexcept : _module(nullptr) {}

        friend Module;
        friend ModuleWeakRef;

        friend constexpr bool operator==(ModuleWeakRef const& left, ModuleWeakRef const& right) noexcept;
        friend constexpr bool operator!=(ModuleWeakRef const& left, ModuleWeakRef const& right) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(ModuleBase const& module, std::nullptr_t) noexcept { return !module; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, ModuleBase const& module) noexcept { return !module; }
    [[nodiscard]] constexpr bool operator!=(ModuleBase const& module, std::nullptr_t) noexcept { return (bool)module; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, ModuleBase const& module) noexcept { return (bool)module; }
}

#endif //!KONGKONG_WIN32_MODULEBASE_H
