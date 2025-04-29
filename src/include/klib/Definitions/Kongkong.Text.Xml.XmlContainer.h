#ifndef KONGKONG_TEXT_XML_XMLCONTAINER_H
#define KONGKONG_TEXT_XML_XMLCONTAINER_H

#include "Base.h"
#include "Kongkong.Text.Xml.XmlNode.h"
#include "Kongkong.Collections.ArrayList.h"

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    struct XmlContainer : public XmlNode {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Xml::XmlContainer;

        using XmlNode::XmlNode;

        [[nodiscard]]
        Collections::IReadOnlyArray<::KONGKONG_NAMESPACE::Text::Xml::XmlElement> Elements() const;

        [[nodiscard]]
        Collections::IReadOnlyArray<::KONGKONG_NAMESPACE::Text::Xml::XmlNode> Nodes() const;

        protected:

        Collections::ArrayList<::KONGKONG_NAMESPACE::Text::Xml::XmlNode> _nodes;
    };
}

namespace KONGKONG_NAMESPACE::Text::Xml
{
    class XmlContainer : public XmlNode {
        public:
        using ImplType = IMPLEMENTATION::XmlContainer;

        /// @brief nullptrとして作成
        constexpr XmlContainer(std::nullptr_t) noexcept : XmlNode(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_TEXT_XML_XMLCONTAINER_H
