#ifndef KONGKONG_WIN32_REGISTRYKEYVIEW_H
#define KONGKONG_WIN32_REGISTRYKEYVIEW_H

#include "Base.h"
#include "Kongkong.Win32.RegistryKeyBase.h"
#include "Kongkong.Win32.RegistryKey.h"

namespace KONGKONG_NAMESPACE::Win32
{
    class RegistryKeyView final : public RegistryKeyBase {
        public:

        /// @brief nullptrとして作成
        constexpr RegistryKeyView(std::nullptr_t) noexcept : RegistryKeyBase(nullptr) {}

        constexpr RegistryKeyView(RegistryKey const& right) noexcept : RegistryKeyBase(right._key) {}

        /// @brief コンストラクタの直後にキーハンドルが破棄されるので使ってはいけない
        /// @param  
        RegistryKeyView(RegistryKey&&) = delete;

        constexpr RegistryKeyView(RegistryKeyView const& right) noexcept : RegistryKeyBase(right._key) {}
        constexpr RegistryKeyView(RegistryKeyView&& right) noexcept : RegistryKeyBase(right._key) {}

        constexpr RegistryKeyView& operator=(std::nullptr_t) noexcept { _key = nullptr; return *this; }
        
        constexpr RegistryKeyView& operator=(RegistryKey const& right) noexcept { _key = right._key; return *this; }

        /// @brief 代入の直後にキーハンドルが破棄されるので使ってはいけない
        RegistryKeyView& operator=(RegistryKey&&) = delete;

        constexpr RegistryKeyView& operator=(RegistryKeyView const& right) noexcept { _key = right._key; return *this; }
        constexpr RegistryKeyView& operator=(RegistryKeyView&& right) noexcept { _key = right._key; return *this; }

        private:
        using RegistryKeyBase::RegistryKeyBase;
    };
}

#endif //!KONGKONG_WIN32_REGISTRYKEYVIEW_H
