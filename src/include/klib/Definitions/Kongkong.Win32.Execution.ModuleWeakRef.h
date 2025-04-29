#ifndef KONGKONG_WIN32_MODULEWEAKREF_H
#define KONGKONG_WIN32_MODULEWEAKREF_H

#include "Base.h"
#include "Kongkong.Win32.Execution.ModuleBase.h"

namespace KONGKONG_NAMESPACE::Win32::Execution
{
    class ModuleWeakRef final : public ModuleBase {
        public:
        
        constexpr ModuleWeakRef(Module const& module) noexcept : ModuleBase(module._module) {}

        /// @brief コンストラクタの直後にModuleが破棄されるので使用してはいけない
        ModuleWeakRef(Module&&) = delete;

        constexpr ModuleWeakRef(ModuleWeakRef const& module) noexcept : ModuleBase(module._module) {}
        constexpr ModuleWeakRef(ModuleWeakRef&& module)  noexcept : ModuleBase(module._module) {}
        
        /// @brief nullptrとして作成
        constexpr ModuleWeakRef(std::nullptr_t) noexcept : ModuleBase(nullptr) {}

        constexpr ModuleWeakRef& operator=(Module const& module) noexcept { _module = module._module; return *this; }
        /// @brief コンストラクタの直後にModuleが破棄されるので使用してはいけない
        ModuleWeakRef& operator=(Module&&) = delete;
        constexpr ModuleWeakRef& operator=(ModuleWeakRef const& module) noexcept { _module = module._module; return *this; }
        constexpr ModuleWeakRef& operator=(ModuleWeakRef&& module) noexcept { _module = module._module; return *this; }
        constexpr ModuleWeakRef& operator=(std::nullptr_t) noexcept { _module = nullptr; return *this; }
    };

    [[nodiscard]] constexpr bool operator==(ModuleWeakRef const& left, ModuleWeakRef const& right) noexcept { return left._module == right._module; }
    [[nodiscard]] constexpr bool operator==(ModuleWeakRef const& module, std::nullptr_t) noexcept { return !module; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, ModuleWeakRef const& module) noexcept { return !module; }
    [[nodiscard]] constexpr bool operator!=(ModuleWeakRef const& left, ModuleWeakRef const& right) noexcept { return left._module != right._module; }
    [[nodiscard]] constexpr bool operator!=(ModuleWeakRef const& module, std::nullptr_t) noexcept { return (bool)module; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, ModuleWeakRef const& module) noexcept { return (bool)module; }
}

#endif //!KONGKONG_WIN32_MODULEWEAKREF_H
