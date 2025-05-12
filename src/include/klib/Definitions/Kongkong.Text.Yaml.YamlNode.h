#ifndef KONGKONG_TEXT_YAML_YAMLNODE_H
#define KONGKONG_TEXT_YAML_YAMLNODE_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.Text.Yaml.YamlNodeType.h"
#include "Kongkong.Collections.ArrayList.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Text::Yaml
{
    class YamlNode : public Object {
        public:
        using ImplType = IMPLEMENTATION::YamlNode;

        /// @brief nullptrとして作成
        constexpr YamlNode(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

namespace KONGKONG_NAMESPACE::Text::Yaml::IMPLEMENTATION
{
    struct YamlNode : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Yaml::YamlNode;

        /// @brief 子要素リスト
        /// @attention このノードがコメント分の場合はnullptrになるよ！
        [[nodiscard]]
        Collections::IReadOnlyArray<ProjType> Children() const noexcept;

        /// @brief このノードの深さ
        [[nodiscard]]
        int32_t Level() const noexcept;

        /// @brief ノード名
        [[nodiscard]]
        String const& Name() const noexcept { return _name; }

        /// @brief 次のノード
        /// @attention ない場合はnullptrになるよ！
        [[nodiscard]]
        ProjType NextNode() const noexcept;

        /// @brief ノードの種類
        [[nodiscard]]
        constexpr YamlNodeType NodeType() const noexcept { return _nodeType; }

        /// @brief 親ノード
        /// @attention nullptrの場合があるよ！
        [[nodiscard]]
        constexpr ProjType const& Parent() const noexcept { return _parent; }

        /// @brief 前のノード
        /// @attention ない場合はnullptrになるよ！
        [[nodiscard]]
        ProjType PreviousNode() const noexcept;

        protected:
        YamlNode(YamlNodeType nodeType);
        YamlNode(YamlNodeType nodeType, ProjType const& parent);
        YamlNode(YamlNodeType nodeType, ProjType&& parent);
        YamlNode(YamlNodeType nodeType, String const& name);
        YamlNode(YamlNodeType nodeType, String&& name) noexcept;
        YamlNode(YamlNodeType nodeType, ProjType const& parent, String const& name);
        YamlNode(YamlNodeType nodeType, ProjType const& parent, String&& name) noexcept;
        YamlNode(YamlNodeType nodeType, ProjType&& parent, String const& name);
        YamlNode(YamlNodeType nodeType, ProjType&& parent, String&& name) noexcept;
        YamlNode(YamlNodeType nodeType, ProjType const& parent, String const& name, Collections::ArrayList<ProjType> const& children);
        YamlNode(YamlNodeType nodeType, ProjType const& parent, String const& name, Collections::ArrayList<ProjType>&& children);
        YamlNode(YamlNodeType nodeType, ProjType const& parent, String&& name, Collections::ArrayList<ProjType> const& children) noexcept;
        YamlNode(YamlNodeType nodeType, ProjType const& parent, String&& name, Collections::ArrayList<ProjType>&& children) noexcept;
        YamlNode(YamlNodeType nodeType, ProjType&& parent, String const& name, Collections::ArrayList<ProjType> const& children);
        YamlNode(YamlNodeType nodeType, ProjType&& parent, String const& name, Collections::ArrayList<ProjType>&& children);
        YamlNode(YamlNodeType nodeType, ProjType&& parent, String&& name, Collections::ArrayList<ProjType> const& children) noexcept;
        YamlNode(YamlNodeType nodeType, ProjType&& parent, String&& name, Collections::ArrayList<ProjType>&& children) noexcept;

        ProjType _parent;
        String _name;

        private:
        YamlNodeType _nodeType;
        
        Collections::ArrayList<ProjType> _children;
    };
}

#endif //!KONGKONG_TEXT_YAML_YAMLNODE_H
