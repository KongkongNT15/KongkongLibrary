//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Json
{
    JsonValue::JsonValue(JsonArray const& value) noexcept : _value(value), _valueType(value == nullptr ? JsonValueType::Null : JsonValueType::Array)
    {
    }

    JsonValue::JsonValue(JsonArray&& value) noexcept : _value(::std::move(value)), _valueType(value == nullptr ? JsonValueType::Null : JsonValueType::Array)
    {
    }

    JsonValue::JsonValue(bool value) : _value(Object::BoxValue(value)), _valueType(JsonValueType::Boolean)
    {
    }

    JsonValue::JsonValue(double value) : _value(Object::BoxValue(value)), _valueType(JsonValueType::Number)
    {
    }

    JsonValue::JsonValue(JsonObject const& value) noexcept : _value(value), _valueType(value == nullptr ? JsonValueType::Null : JsonValueType::Object)
    {
    }

    JsonValue::JsonValue(JsonObject&& value) noexcept : _value(::std::move(value)), _valueType(value == nullptr ? JsonValueType::Null : JsonValueType::Object)
    {
    }

    JsonValue::JsonValue(String const& value) : _value(Object::BoxValue(value)), _valueType(JsonValueType::String)
    {
    }

    JsonValue::JsonValue(String&& value) : _value(Object::BoxValue(::std::move(value))), _valueType(JsonValueType::String)
    {
    }

    JsonArray JsonValue::GetArray() const
    {
        return _value.Cast<JsonArray>();
    }

    bool& JsonValue::GetBoolean() const
    {
        return _value.Cast<bool>();
    }

    double& JsonValue::GetNumber() const
    {
        return _value.Cast<double>();
    }

    JsonObject JsonValue::GetObject() const
    {
        return _value.Cast<JsonObject>();
    }

    String& JsonValue::GetString() const
    {
        return _value.Cast<String>();
    }

    void JsonValue::Value(::std::nullptr_t) noexcept
    {
        _value = nullptr;
        _valueType = JsonValueType::Null;
    }

    void JsonValue::Value(bool value)
    {
        if (_valueType == JsonValueType::Boolean) {
            auto& v = _value.As<bool>();
            v = value;
            return;
        }

        _value = Object::BoxValue(value);
        _valueType = JsonValueType::Boolean;
    }

    void JsonValue::Value(double value)
    {
        if (_valueType == JsonValueType::Number) {
            auto& v = _value.As<double>();
            v = value;
            return;
        }

        _value = Object::BoxValue(value);
        _valueType = JsonValueType::Number;
    }

    void JsonValue::Value(JsonArray const& value) noexcept
    {
        if (value == nullptr) [[unlikely]] {
            Value(nullptr);
            return;
        }

        _value = value;
        _valueType = JsonValueType::Array;
    }

    void JsonValue::Value(JsonObject const& value) noexcept
    {
        if (value == nullptr) [[unlikely]] {
            Value(nullptr);
            return;
        }

        _value = value;
        _valueType = JsonValueType::Object;
    }

    void JsonValue::Value(String const& value)
    {
        if (_valueType == JsonValueType::String) {
            auto& v = _value.As<String>();
            v = value;
            return;
        }

        _value = Object::BoxValue(value);
        _valueType = JsonValueType::String;
    }

    void JsonValue::Value(String&& value)
    {
        if (_valueType == JsonValueType::String) {
            auto& v = _value.As<String>();
            v = ::std::move(value);
            return;
        }

        _value = Object::BoxValue(::std::move(value));
        _valueType = JsonValueType::String;
    }

    bool operator==(JsonValue const& left, JsonValue const& right) noexcept
    {
        return left._valueType == right._valueType && left._value.RawPointer() == right._value.RawPointer();
    }

    bool operator!=(JsonValue const& left, JsonValue const& right) noexcept
    {
        return left._valueType != right._valueType && left._value.RawPointer() != right._value.RawPointer();
    }

    bool operator<(JsonValue const& left, JsonValue const& right) noexcept
    {
        if (left._valueType < right._valueType) return true;
        return left._value.RawPointer() < right._value.RawPointer();
    }

    bool operator<=(JsonValue const& left, JsonValue const& right) noexcept
    {
        if (left._valueType <= right._valueType) return true;
        return left._value.RawPointer() <= right._value.RawPointer();
    }

    bool operator>(JsonValue const& left, JsonValue const& right) noexcept
    {
        if (left._valueType > right._valueType) return true;
        return left._value.RawPointer() > right._value.RawPointer();
    }

    bool operator>=(JsonValue const& left, JsonValue const& right) noexcept
    {
        if (left._valueType >= right._valueType) return true;
        return left._value.RawPointer() >= right._value.RawPointer();
    }
}
