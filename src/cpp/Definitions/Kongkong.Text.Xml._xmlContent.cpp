//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml
{
    _xmlContent::_xmlContent() : _value(true)
    {
    }

    _xmlContent::_xmlContent(String const& value) : _value(value, true)
    {
    }

    void _xmlContent::Value(String const& value)
    {
        _value = value;
    }

    void _xmlContent::Value(String&& value) noexcept
    {
        _value = std::move(value);
    }
}
