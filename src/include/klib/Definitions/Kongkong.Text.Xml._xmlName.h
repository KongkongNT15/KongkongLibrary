#ifndef KONGKONG_TEXT_XML_XMLNAME_H
#define KONGKONG_TEXT_XML_XMLNAME_H

#include "Base.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Text::Xml
{
    struct _xmlName {

        [[nodiscard]] constexpr String& Name() noexcept { return _name; }
        [[nodiscard]] constexpr String const& Name() const noexcept { return _name; }

        void Name(String const& name);
        void Name(String&& name) noexcept;

        private:

        _xmlName();
        _xmlName(String const& name);
        constexpr _xmlName(String&& name) noexcept : _name(std::move(name)) {}

        String _name;

        friend IMPLEMENTATION::XmlAttribute;
        friend IMPLEMENTATION::XmlElement;
    };
}

#endif //!KONGKONG_TEXT_XML_XMLNAME_H
