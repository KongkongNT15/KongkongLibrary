//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Json::IMPLEMENTATION
{
    void JsonArray::Append(JsonValue const& value)
    {
        _list.Append(value);
    }

    void JsonArray::Append(JsonValue&& value)
    {
        _list.Append(::std::move(value));
    }

    bool JsonArray::Contains(JsonValue const& value) const noexcept
    {
        return _list.Contains(value);
    }

    ssize_t JsonArray::IndexOf(JsonValue const& value) const noexcept
    {
        return _list.IndexOf(value);
    }

    void JsonArray::Insert(ssize_t index, JsonValue const& value)
    {
        _list.Insert(index, value);
    }

    void JsonArray::Insert(ssize_t index, JsonValue&& value)
    {
        _list.Insert(index, ::std::move(value));
    }

    String JsonArray::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Text::Json::JsonArray");
    }
}

namespace KONGKONG_NAMESPACE::Text::Json
{
    JsonArray::JsonArray() : Object(nullptr)
    {
        _setInstance(NEW ImplType());
    }

    JsonArray const& JsonArray::operator+=(JsonValue const& value) const
    {
        _getPtr<ImplType>()->Append(value);
        return *this;
    }

    JsonArray const& JsonArray::operator+=(JsonValue&& value) const
    {
        _getPtr<ImplType>()->Append(::std::move(value));
        return *this;
    }

    JsonValue& JsonArray::operator[](ssize_t index) const
    {
        return _getPtr<ImplType>()->operator[](index);
    }
}
