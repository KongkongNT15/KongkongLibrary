//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    Collections::IReadOnlyArray<XmlAttribute::ProjType> XmlElement::Attributes() const
    {
        return _attributes;
    }
}
