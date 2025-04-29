//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSXMLNode*)_instance())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    NSXmlAttribute::NSXmlAttribute(NSString const& name) : NSXmlNode(nullptr)
    {
        auto pName = (::NSString*)NSObjectHelper::GetPointer(name);

        ArgumentNullException::CheckNull(pName, u"name");

        _setInstance([::NSXMLNode attributeWithName:pName stringValue:@""]);
    }

    NSXmlAttribute::NSXmlAttribute(NSString const& name, std::nullptr_t) : NSXmlAttribute(name)
    {
    }

    NSXmlAttribute::NSXmlAttribute(NSString const& name, NSString const& stringValue) : NSXmlNode(nullptr)
    {
        auto pName = (::NSString*)NSObjectHelper::GetPointer(name);

        ArgumentNullException::CheckNull(pName, u"name");

        auto pStringValue = (::NSString*)NSObjectHelper::GetPointer(stringValue);

        _setInstance([::NSXMLNode attributeWithName:pName stringValue:(pStringValue == nil ? @"" : pStringValue)]);
    }
}

#undef INSTANCE

