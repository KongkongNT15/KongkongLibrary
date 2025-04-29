#ifndef KONGKONG_TEXT_XML_XMLELEMENT_H
#define KONGKONG_TEXT_XML_XMLELEMENT_H

#include "Base.h"
#include "Kongkong.Text.Xml._xmlContent.h"
#include "Kongkong.Text.Xml._xmlName.h"
#include "Kongkong.Text.Xml.XmlContainer.h"
#include "Kongkong.Text.Xml.XmlAttribute.h"
#include "Kongkong.Collections.ArrayList.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    struct KONGKONG_INCOMPLETED_CLASS XmlElement final : public XmlContainer, public _xmlContent, public _xmlName {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Xml::XmlElement;

        [[nodiscard]]
        Collections::IReadOnlyArray<XmlAttribute::ProjType> Attributes() const;

        private:
        Collections::ArrayList<XmlAttribute::ProjType> _attributes;
    };
}

namespace KONGKONG_NAMESPACE::Text::Xml
{
    class KONGKONG_INCOMPLETED_CLASS XmlElement final : public XmlContainer {
        public:
        using ImplType = IMPLEMENTATION::XmlElement;

        /// @brief nullptrとして作成
        constexpr XmlElement(std::nullptr_t) noexcept : XmlContainer(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_TEXT_XML_XMLELEMENT_H
