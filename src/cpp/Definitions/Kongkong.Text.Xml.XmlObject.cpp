//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    int32_t XmlObject::Level() const noexcept
    {
        int32_t level = 0;

        ProjType parent = _parent;

        while (parent != nullptr) {
            auto& instance = Object::ProjType::GetInstanceUnsafe(parent);

            if (instance.NodeType() == XmlNodeType::Document) break;

            parent = instance._parent;
            ++level;
        }

        return level;
    }
}
