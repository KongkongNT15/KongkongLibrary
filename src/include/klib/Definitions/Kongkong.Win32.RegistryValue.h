#ifndef KONGKONG_WIN32_REGISTRYVCALUE_H
#define KONGKONG_WIN32_REGISTRYVCALUE_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.Win32.RegistryValueType.h"

namespace KONGKONG_NAMESPACE::Win32
{
    /// @brief レジストリの値のラッパー
    struct RegistryValue final : public ValueType {

        RegistryValue(Object const& value, RegistryValueType type) noexcept : _value(value), _type(type) {}
        constexpr RegistryValue(Object&& value, RegistryValueType type) noexcept : _value(std::move(value)), _type(type) {}

        /// @brief 値本体
        [[nodiscard]]
        constexpr Object const& Value() const noexcept { return _value; }

        /// @brief 値の型名を取得
        [[nodiscard]]
        String ToString() const;

        /// @brief 値の型の種類を取得
        [[nodiscard]]
        constexpr RegistryValueType Type() const noexcept { return _type; }

        private:
        Object _value;
        RegistryValueType _type;
    };

    [[nodiscard]] bool operator==(RegistryValue const& left, RegistryValue const& right) noexcept;
    [[nodiscard]] bool operator!=(RegistryValue const& left, RegistryValue const& right) noexcept;
}

#endif //!KONGKONG_WIN32_REGISTRYVCALUE_H
