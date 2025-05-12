#ifndef KONGKONG_TEXT_XML_XMLNODETYPE_H
#define KONGKONG_TEXT_XML_XMLNODETYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text::Xml
{
    enum struct XmlNodeType : uint8_t {
        Attribute,
        Comment,
        Document,
        Element,
    };
}

#endif //!KONGKONG_TEXT_XML_XMLNODETYPE_H
