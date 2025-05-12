#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLNODETYPE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLNODETYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    enum struct NSXmlNodeKind : size_t {
        Invalid,
        Document,
        Element,
        Attribute,
        Namespace,
        ProcessingInstruction,
        Comment,
        Text,
        Dtd,
        EntityDeclaration,
        AttributeDeclaration,
        ElementDeclaration,
        NotationDeclaration
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLNODETYPE_H
