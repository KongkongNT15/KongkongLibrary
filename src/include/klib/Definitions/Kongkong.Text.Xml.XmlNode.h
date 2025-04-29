#ifndef KONGKONG_TEXT_XML_XMLNODE_H
#define KONGKONG_TEXT_XML_XMLNODE_H

#include "Base.h"
#include "Kongkong.Text.Xml.XmlObject.h"

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    struct XmlNode : public XmlObject {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Xml::XmlNode;
        using XmlObject::XmlObject;

        [[nodiscard]]
        ProjType NextNode() const noexcept;

        [[nodiscard]]
        ProjType PreviousNode() const noexcept;
    };
}

namespace KONGKONG_NAMESPACE::Text::Xml
{
    class XmlNode : public XmlObject {
        public:
        using ImplType = IMPLEMENTATION::XmlNode;

        /// @brief nullptrとして作成
        constexpr XmlNode(std::nullptr_t) noexcept : XmlObject(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_TEXT_XML_XMLNODE_H
