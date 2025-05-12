#ifndef KONGKONG_TEXT_YAML_YAMLTEXT_H
#define KONGKONG_TEXT_YAML_YAMLTEXT_H

#include "Base.h"
#include "Kongkong.Text.Yaml.YamlNode.h"

namespace KONGKONG_NAMESPACE::Text::Yaml::IMPLEMENTATION
{
    struct YamlText : public YamlNode {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Yaml::YamlText;

        [[nodiscard]]
        constexpr String const& Value() const noexcept { return _name; }

        void Value(String const& newValue);
        void Value(String&& newValue) noexcept;

        private:
        explicit YamlText(String const& text, YamlNode::ProjType const& parent) noexcept;
        explicit YamlText(String const& text, YamlNode::ProjType&& parent) noexcept;
        explicit YamlText(String&& text, YamlNode::ProjType const& parent) noexcept;
        explicit YamlText(String&& text, YamlNode::ProjType&& parent) noexcept;

        friend ProjType;
    };
}

namespace KONGKONG_NAMESPACE::Text::Yaml
{
    class YamlText : public YamlNode {
        public:
        using ImplType = IMPLEMENTATION::YamlText;

        explicit YamlText(String const& text, YamlNode const& parent);
        explicit YamlText(String const& text, YamlNode&& parent);
        explicit YamlText(String&& text, YamlNode const& parent);
        explicit YamlText(String&& text, YamlNode&& parent);

        /// @brief nullptrとして作成
        constexpr YamlText(std::nullptr_t) noexcept : YamlNode(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_TEXT_YAML_YAMLTEXT_H
