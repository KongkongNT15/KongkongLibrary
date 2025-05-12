#ifndef KONGKONG_TEXT_XML_XMLCONTENT_H
#define KONGKONG_TEXT_XML_XMLCONTENT_H

#include "Base.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Text::Xml
{
    struct _xmlContent {

        [[nodiscard]] constexpr String& Value() noexcept { return _value; }
        [[nodiscard]] constexpr String const& Value() const noexcept { return _value; }

        void Value(String const& value);
        void Value(String&& value) noexcept;

        private:

        _xmlContent();
        _xmlContent(String const& value);
        constexpr _xmlContent(String&& value) noexcept : _value(std::move(value)) {}

        String _value;

        friend IMPLEMENTATION::XmlAttribute;
        friend IMPLEMENTATION::XmlComment;
        friend IMPLEMENTATION::XmlElement;
    };
}

#endif //!KONGKONG_TEXT_XML_XMLCONTENT_H
