#ifndef KONGKONG_TEXT_XML_XMLATTRIBUTE_H
#define KONGKONG_TEXT_XML_XMLATTRIBUTE_H

#include "Base.h"
#include "Kongkong.Text.Xml.XmlObject.h"
#include "Kongkong.Text.Xml._xmlContent.h"
#include "Kongkong.Text.Xml._xmlName.h"

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    struct XmlAttribute final : public XmlObject, public _xmlContent, public _xmlName {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Xml::XmlAttribute;

        [[nodiscard]]
        ProjType NextAttribute() const noexcept;

        [[nodiscard]]
        ProjType PreviousAttribute() const noexcept;

        /// @brief XML表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const override;

        private:
        explicit XmlAttribute(String const& name);
        explicit XmlAttribute(String&& name);
        explicit XmlAttribute(String const& name, String const& value);
        explicit XmlAttribute(String const& name, String&& value);
        explicit XmlAttribute(String&& name, String const& value);
        explicit constexpr XmlAttribute(String&& name, String&& value) noexcept : XmlObject(XmlNodeType::Attribute), _xmlContent(std::move(value)), _xmlName(std::move(name)) {}

        friend ProjType;
    };
}

namespace KONGKONG_NAMESPACE::Text::Xml
{
    class XmlAttribute final : public XmlObject {
        public:
        using ImplType = IMPLEMENTATION::XmlAttribute;

        explicit XmlAttribute(String const& name);
        explicit XmlAttribute(String&& name);
        explicit XmlAttribute(String const& name, String const& value);
        explicit XmlAttribute(String const& name, String&& value);
        explicit XmlAttribute(String&& name, String const& value);
        explicit XmlAttribute(String&& name, String&& value);

        /// @brief nullptrとして作成
        constexpr XmlAttribute(std::nullptr_t) noexcept : XmlObject(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_TEXT_XML_XMLATTRIBUTE_H
