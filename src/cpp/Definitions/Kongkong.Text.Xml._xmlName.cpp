//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml
{
    _xmlName::_xmlName() : _name(true)
    {
    }

    _xmlName::_xmlName(String const& name) : _name(name, true)
    {
    }

    void _xmlName::Name(String const& name)
    {
        _name = name;
    }

    void _xmlName::Name(String&& name) noexcept
    {
        _name = std::move(name);
    }
}
