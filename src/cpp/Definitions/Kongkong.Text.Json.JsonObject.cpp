//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Json::IMPLEMENTATION
{
    JsonValue& JsonObject::operator[](String const& name)
    {
        return _map.At(name);
    }

    void JsonObject::Insert(String const& key, JsonValue const& value)
    {
        auto pair = _map.TryEmplace(key, value);

        if (!pair.Value()) [[unlikely]] {
            *pair.Key() = value;
        }
    }

    void JsonObject::Insert(String const& key, JsonValue&& value)
    {
        auto pair = _map.TryEmplace(key, ::std::move(value));

        if (!pair.Value()) [[unlikely]] {
            *pair.Key() = value;
        }
    }

    void JsonObject::Insert(String&& key, JsonValue const& value)
    {
        auto pair = _map.TryEmplace(::std::move(key), value);

        if (!pair.Value()) [[unlikely]] {
            *pair.Key() = value;
        }
    }

    void JsonObject::Insert(String&& key, JsonValue&& value)
    {
        auto pair = _map.TryEmplace(::std::move(key), ::std::move(value));

        if (!pair.Value()) [[unlikely]] {
            *pair.Key() = ::std::move(value);
        }
    }

    bool JsonObject::Remove(String const& name) noexcept
    {
        return _map.Remove(name);
    }
}

namespace KONGKONG_NAMESPACE::Text::Json
{
    JsonObject::JsonObject() : Object(nullptr)
    {
        _setInstance(NEW ImplType());
    }
}
