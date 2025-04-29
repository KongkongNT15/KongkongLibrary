#ifndef KONGKONG_TEXT_JSON_JSONVALUE_H
#define KONGKONG_TEXT_JSON_JSONVALUE_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.BoxValueObject.h"
#include "Kongkong.Text.Json.JsonValueType.h"

namespace KONGKONG_NAMESPACE::Text::Json
{
    struct JsonValue final : public ValueType {

        constexpr JsonValue() noexcept : _valueType(JsonValueType::Null), _value(nullptr) {}
        constexpr JsonValue(::std::nullptr_t) noexcept : _valueType(JsonValueType::Null), _value(nullptr) {}
        JsonValue(JsonArray const& value) noexcept;
        JsonValue(JsonArray&& value) noexcept;
        JsonValue(bool value);
        JsonValue(double value);
        JsonValue(JsonObject const& value) noexcept;
        JsonValue(JsonObject&& value) noexcept;
        JsonValue(String const& value);
        JsonValue(String&& value);

        /// @brief 値を取得
        /// @tparam T 値の型
        /// @return 値
        /// @return 型が間違っている場合はnullptr
        template <class T> requires (::std::same_as<T, JsonArray> || ::std::same_as<T, JsonObject>)
        T As() const noexcept { return _value.As<T>(); }

        /// @brief 値を取得
        /// @tparam T 値の型
        /// @return 値の参照
        /// @return 型が間違っている場合は未定義
        template <class T> requires (::std::same_as<T, bool> || ::std::same_as<T, double> || ::std::same_as<T, String>)
        T& As() const noexcept { return _value.As<T>(); }

        /// @brief 値を取得
        /// @tparam T 値の型
        /// @return 値
        /// @throws InvalidCastException: 型が間違っているとき
        template <class T> requires (::std::same_as<T, JsonArray> || ::std::same_as<T, JsonObject>)
        T Cast() const { return _value.Cast<T>(); }

        /// @brief 値を取得
        /// @tparam T 値の型
        /// @return 値の参照
        /// @throws InvalidCastException: 型が間違っているとき
        template <class T> requires (::std::same_as<T, bool> || ::std::same_as<T, double> || ::std::same_as<T, String>)
        T& Cast() const { return _value.Cast<T>(); }

        [[nodiscard]]
        JsonArray GetArray() const;

        [[nodiscard]]
        bool& GetBoolean() const;

        [[nodiscard]]
        double& GetNumber() const;

        [[nodiscard]]
        JsonObject GetObject() const;

        [[nodiscard]]
        String& GetString() const;

        [[nodiscard]]
        String ToString() const;

        [[nodiscard]]
        String ToString(uint32_t indent1, uint32_t indent2, uint32_t indent3) const;

        [[nodiscard]]
        constexpr Object const& Value() const noexcept { return _value; }

        void Value(::std::nullptr_t) noexcept;
        void Value(bool value);
        void Value(double value);
        void Value(JsonArray const& value) noexcept;
        void Value(JsonObject const& value) noexcept;
        void Value(String const& value);
        void Value(String&& value);

        [[nodiscard]]
        constexpr JsonValueType ValueType() const noexcept { return _valueType; }

        private:
        JsonValueType _valueType;
        Object _value;

        friend bool operator==(JsonValue const&, JsonValue const&) noexcept;
        friend bool operator!=(JsonValue const&, JsonValue const&) noexcept;
        friend bool operator<(JsonValue const&, JsonValue const&) noexcept;
        friend bool operator<=(JsonValue const&, JsonValue const&) noexcept;
        friend bool operator>(JsonValue const&, JsonValue const&) noexcept;
        friend bool operator>=(JsonValue const&, JsonValue const&) noexcept;
    };

    [[nodiscard]] bool operator==(JsonValue const& left, JsonValue const& right) noexcept;
    [[nodiscard]] bool operator!=(JsonValue const& left, JsonValue const& right) noexcept;
    [[nodiscard]] bool operator<(JsonValue const& left, JsonValue const& right) noexcept;
    [[nodiscard]] bool operator<=(JsonValue const& left, JsonValue const& right) noexcept;
    [[nodiscard]] bool operator>(JsonValue const& left, JsonValue const& right) noexcept;
    [[nodiscard]] bool operator>=(JsonValue const& left, JsonValue const& right) noexcept;
}

#endif //!KONGKONG_TEXT_JSON_JSONVALUE_H
