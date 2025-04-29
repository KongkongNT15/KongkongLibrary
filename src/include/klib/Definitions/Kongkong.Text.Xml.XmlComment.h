#ifndef KONGKONG_TEXT_XML_XMLCOMMENT_H
#define KONGKONG_TEXT_XML_XMLCOMMENT_H

#include "Base.h"
#include "Kongkong.Text.Xml.XmlNode.h"
#include "Kongkong.Text.Xml._xmlContent.h"

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    struct XmlComment final : public XmlNode, public _xmlContent {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Xml::XmlComment;

        /// @brief コメント文のXML表現を取得
        [[nodiscard]]
        String ToString() const;

        private:

        XmlComment();
        XmlComment(String const& value);
        constexpr XmlComment(String&& value) noexcept : XmlNode(XmlNodeType::Comment), _xmlContent(std::move(value)) {}

        friend ProjType;
    };
}

namespace KONGKONG_NAMESPACE::Text::Xml
{
    class XmlComment final : public XmlNode {
        public:
        using ImplType = IMPLEMENTATION::XmlComment;

        explicit XmlComment();
        explicit XmlComment(String const& value);
        explicit XmlComment(String&& value);

        /// @brief nullptrとして作成
        constexpr XmlComment(std::nullptr_t) noexcept : XmlNode(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_TEXT_XML_XMLCOMMENT_H
