//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    Collections::IReadOnlyArray<::KONGKONG_NAMESPACE::Text::Xml::XmlElement> XmlContainer::Elements() const
    {
        Collections::Turbo::FastArrayList<::KONGKONG_NAMESPACE::Text::Xml::XmlElement> list;

        auto& nodes = Object::ProjType::GetInstanceUnsafe(_nodes);

        auto p = nodes.Data();
        auto end = p + nodes.Length();

        while (p != end) {
            if ((*p)->NodeType() == XmlNodeType::Element) list.Append((*p).As<::KONGKONG_NAMESPACE::Text::Xml::XmlElement>());
            p++;
        }

        return Collections::ArrayList<::KONGKONG_NAMESPACE::Text::Xml::XmlElement>(std::move(list));
    }

    Collections::IReadOnlyArray<::KONGKONG_NAMESPACE::Text::Xml::XmlNode> XmlContainer::Nodes() const
    {
        return _nodes;
    }
}
