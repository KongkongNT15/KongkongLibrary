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

    String JsonObject::ToString() const
    {
        return ToString(0, 4, 0);
    }

    String JsonObject::ToString(uint32_t indent1, uint32_t indent2, uint32_t indent3) const
    {
        String str;

        if (indent1 != 0) str.AppendUnsafe(indent1, u' ');

        str.Append(u'{');
        str.AppendNewLine();

        auto indentTmp = indent2 + indent3;

        for (auto&& pair : _map) {
            if (indentTmp != 0) str.AppendUnsafe(indentTmp, u' ');

            str.Append(u'"');
            str.Append(pair.Key());
            str.AppendUnsafe(u": ");

            str.Append(pair.Value().ToString(1, indent2, indentTmp));

            str.AppendNewLine();
        }

        if (indent3 != 0) str.AppendUnsafe(indent3, u' ');

        str.Append(u'}');

        return str;
    }
}

namespace KONGKONG_NAMESPACE::Text::Json
{
    JsonObject::JsonObject() : Object(nullptr)
    {
        _setInstance(NEW ImplType());
    }
    
    JsonValue& JsonObject::operator[](String const& name) const
    {
        return _getPtr<ImplType>()->operator[](name);
    }
}
