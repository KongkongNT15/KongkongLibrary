//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Yaml::IMPLEMENTATION
{
    YamlText::YamlText(String const& text, YamlNode::ProjType const& parent) noexcept : YamlNode(YamlNodeType::Text, parent, text)
    {
    }

    YamlText::YamlText(String const& text, YamlNode::ProjType&& parent) noexcept : YamlNode(YamlNodeType::Text, std::move(parent), text)
    {
    }

    YamlText::YamlText(String&& text, YamlNode::ProjType const& parent) noexcept : YamlNode(YamlNodeType::Text, parent, std::move(text))
    {
    }

    YamlText::YamlText(String&& text, YamlNode::ProjType&& parent) noexcept : YamlNode(YamlNodeType::Text, std::move(parent), std::move(text))
    {
    }

    void YamlText::Value(String const& newValue)
    {
        _name = newValue;
    }

    void YamlText::Value(String&& newValue) noexcept
    {
        _name = std::move(newValue);
    }
}

namespace KONGKONG_NAMESPACE::Text::Yaml
{
    YamlText::YamlText(String const& text, YamlNode const& parent) : YamlNode(nullptr)
    {
        _setInstance(NEW ImplType(text, parent));
    }

    YamlText::YamlText(String const& text, YamlNode&& parent) : YamlNode(nullptr)
    {
        _setInstance(NEW ImplType(text, std::move(parent)));
    }

    YamlText::YamlText(String&& text, YamlNode const& parent) : YamlNode(nullptr)
    {
        _setInstance(NEW ImplType(std::move(text), parent));
    }

    YamlText::YamlText(String&& text, YamlNode&& parent) : YamlNode(nullptr)
    {
        _setInstance(NEW ImplType(std::move(text), std::move(parent)));
    }
}
