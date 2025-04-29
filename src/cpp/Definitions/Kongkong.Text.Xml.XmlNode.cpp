//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    XmlNode::ProjType XmlNode::NextNode() const noexcept
    {
        if (Parent() == nullptr) return nullptr;

        auto xmlElement = Parent().As<XmlContainer::ProjType>();

        if (xmlElement == nullptr) return nullptr;

        auto&& nodes = Object::ProjType::GetInstanceUnsafe(xmlElement).Nodes();

        auto& nodesRef = Object::ProjType::GetInstanceUnsafe(nodes);

        ssize_t index;
        ssize_t length = nodesRef.Length();

        for (index = 0; index != length; index++) {
            if (nodesRef[index].RawPointer() == this) {
                index++;
                break;
            }
        }

        if (index == length) return nullptr;

        return nodesRef[index];
    }

    XmlNode::ProjType XmlNode::PreviousNode() const noexcept
    {
        if (Parent() == nullptr) return nullptr;

        auto xmlElement = Parent().As<XmlContainer::ProjType>();

        if (xmlElement == nullptr) return nullptr;

        auto&& nodes = Object::ProjType::GetInstanceUnsafe(xmlElement).Nodes();

        auto& nodesRef = Object::ProjType::GetInstanceUnsafe(nodes);

        ssize_t index;
        ssize_t length = nodesRef.Length();

        for (index = 0; index != length; index++) {
            if (nodesRef[index].RawPointer() == this) break;
        }

        if (index == 0) return nullptr;

        return nodesRef[index - 1];
    }
}
