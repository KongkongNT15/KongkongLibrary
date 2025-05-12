//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    XmlComment::XmlComment() : XmlNode(XmlNodeType::Comment)
    {
    }

    XmlComment::XmlComment(String const& value) : XmlNode(XmlNodeType::Comment), _xmlContent(value)
    {
    }

    String XmlComment::ToString() const
    {
        String str = String::FromPointerUnsafe(4, u"<!--");

        str.Append(_value);
        str.AppendUnsafe(3, u"-->");

        return str;
    }
}

namespace KONGKONG_NAMESPACE::Text::Xml
{
    XmlComment::XmlComment() : XmlNode(nullptr)
    {
        _setInstance(NEW ImplType());
    }

    XmlComment::XmlComment(String const& value) : XmlNode(nullptr)
    {
        _setInstance(NEW ImplType(value));
    }

    XmlComment::XmlComment(String&& value) : XmlNode(nullptr)
    {
        _setInstance(NEW ImplType(std::move(value)));
    }
}
