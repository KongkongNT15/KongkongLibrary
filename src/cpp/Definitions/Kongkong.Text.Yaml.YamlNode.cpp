//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Yaml::IMPLEMENTATION
{
    YamlNode::YamlNode(YamlNodeType nodeType) : _nodeType(nodeType), _parent(nullptr), _name(true), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType const& parent) : _nodeType(nodeType), _parent(parent), _name(true), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType&& parent) : _nodeType(nodeType), _parent(std::move(parent)), _name(true), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, String const& name) : _nodeType(nodeType), _parent(nullptr), _name(name), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, String&& name) noexcept : _nodeType(nodeType), _parent(nullptr), _name(std::move(name)), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType const& parent, String const& name) : _nodeType(nodeType), _parent(parent), _name(name), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType const& parent, String&& name) noexcept : _nodeType(nodeType), _parent(parent), _name(std::move(name)), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType&& parent, String const& name) : _nodeType(nodeType), _parent(std::move(parent)), _name(name), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType&& parent, String&& name) noexcept : _nodeType(nodeType), _parent(std::move(parent)), _name(std::move(name)), _children(nullptr)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType const& parent, String const& name, Collections::ArrayList<ProjType> const& children) : _nodeType(nodeType), _parent(parent), _name(name), _children(children)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType const& parent, String const& name, Collections::ArrayList<ProjType>&& children) : _nodeType(nodeType), _parent(parent), _name(name), _children(std::move(children))
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType const& parent, String&& name, Collections::ArrayList<ProjType> const& children) noexcept : _nodeType(nodeType), _parent(parent), _name(std::move(name)), _children(children)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType const& parent, String&& name, Collections::ArrayList<ProjType>&& children) noexcept : _nodeType(nodeType), _parent(parent), _name(std::move(name)), _children(std::move(children))
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType&& parent, String const& name, Collections::ArrayList<ProjType> const& children) : _nodeType(nodeType), _parent(std::move(parent)), _name(name), _children(children)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType&& parent, String const& name, Collections::ArrayList<ProjType>&& children) : _nodeType(nodeType), _parent(std::move(parent)), _name(name), _children(std::move(children))
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType&& parent, String&& name, Collections::ArrayList<ProjType> const& children) noexcept : _nodeType(nodeType), _parent(std::move(parent)), _name(std::move(name)), _children(children)
    {
    }

    YamlNode::YamlNode(YamlNodeType nodeType, ProjType&& parent, String&& name, Collections::ArrayList<ProjType>&& children) noexcept : _nodeType(nodeType), _parent(std::move(parent)), _name(std::move(name)), _children(std::move(children))
    {
    }

    Collections::IReadOnlyArray<YamlNode::ProjType> YamlNode::Children() const noexcept
    {
        return _children;
    }

    int32_t YamlNode::Level() const noexcept
    {
        int32_t level = 0;
        ProjType parent = _parent;
        
        while (parent != nullptr) {
            YamlNode& node = Object::ProjType::GetInstanceUnsafe(parent);
            parent = node._parent;
            level++;
        }

        return level;
    }

    YamlNode::ProjType YamlNode::NextNode() const noexcept
    {
        if (_parent == nullptr) return nullptr;

        auto& parent = Object::ProjType::GetInstanceUnsafe(_parent);
        auto& list = Object::ProjType::GetInstanceUnsafe(parent._children);
        ssize_t length = list.Length();

        //NextNodeの要素番号
        ssize_t index;

        for (index = 0; index != length; index++) {
            if (list[index].RawPointer() == this) {
                index++;
                break;
            }
        }

        if (index == length) return nullptr;

        return list[index];
    }

    YamlNode::ProjType YamlNode::PreviousNode() const noexcept
    {
        if (_parent == nullptr) return nullptr;

        auto& parent = Object::ProjType::GetInstanceUnsafe(_parent);
        auto& list = Object::ProjType::GetInstanceUnsafe(parent._children);
        ssize_t length = list.Length();

        //PreviousNodeの要素番号
        ssize_t index;

        for (index = 0; index != length; index++) {
            if (list[index].RawPointer() == this) {
                break;
            }
        }

        if (index == 0) return nullptr;

        return list[index - 1];
    }
}
