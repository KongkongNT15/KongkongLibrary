DEFINE_CAST_APPLEOBJECT(AppKit::NSColor, NSColor)
DEFINE_CAST_APPLEOBJECT(Foundation::NSData, NSData)
DEFINE_CAST_APPLEOBJECT(Foundation::NSError, NSError)
DEFINE_CAST_APPLEOBJECT(Foundation::NSNumber, NSNumber)
DEFINE_CAST_APPLEOBJECT(Foundation::NSString, NSString)
DEFINE_CAST_APPLEOBJECT(Foundation::NSValue, NSValue)
DEFINE_CAST_APPLEOBJECT(Foundation::Collections::NSArray, NSArray)
DEFINE_CAST_APPLEOBJECT(Foundation::Collections::NSDictionary, NSDictionary)
DEFINE_CAST_APPLEOBJECT(Foundation::Collections::NSEnumerator, NSEnumerator)
DEFINE_CAST_APPLEOBJECT(Foundation::Collections::NSMutableArray, NSMutableArray)
DEFINE_CAST_APPLEOBJECT(Foundation::Collections::NSNull, NSNull)
DEFINE_CAST_APPLEOBJECT(Foundation::FileSystem::NSFileManager, NSFileManager)
DEFINE_CAST_APPLEOBJECT(Foundation::Streams::NSInputStream, NSInputStream)
DEFINE_CAST_APPLEOBJECT(Foundation::Streams::NSStream, NSStream)
DEFINE_CAST_APPLEOBJECT(Foundation::Text::NSScanner, NSScanner)
DEFINE_CAST_APPLEOBJECT(Foundation::Text::Xml::NSXmlDocument, NSXMLDocument)
DEFINE_CAST_APPLEOBJECT(Foundation::Text::Xml::NSXmlElement, NSXMLElement)
DEFINE_CAST_APPLEOBJECT(Foundation::Text::Xml::NSXmlNode, NSXMLNode)
DEFINE_CAST_APPLEOBJECT(Foundation::Threading::NSBlockOperation, NSBlockOperation)
DEFINE_CAST_APPLEOBJECT(Foundation::Threading::NSLock, NSLock)
DEFINE_PROTOCOL_CAST_APPLEOBJECT(Foundation::Threading::NSLocking, NSLocking)
DEFINE_CAST_APPLEOBJECT(Foundation::Threading::NSOperation, NSOperation)
DEFINE_CAST_APPLEOBJECT(Foundation::Threading::NSOperationQueue, NSOperationQueue)
DEFINE_CAST_APPLEOBJECT(Foundation::Threading::NSThread, NSThread)

#ifdef KONGKONG_OBJECTIVE_C_METAL_ENABLED
DEFINE_CAST_APPLEOBJECT(Metal::MetalCommandQueueDescriptor, MTLCommandQueueDescriptor)
DEFINE_PROTOCOL_CAST_APPLEOBJECT(Metal::MetalDevice, MTLDevice)
DEFINE_PROTOCOL_CAST_APPLEOBJECT(Metal::MetalLogState, MTLLogState)
#endif //KONGKONG_OBJECTIVE_C_METAL_ENABLED

namespace KONGKONG_NAMESPACE::AppleDevice
{
    template <>                                                             
    bool NSObject::Is<Foundation::Text::Xml::NSXmlAttribute>() const noexcept 
    {
        if (!Is<Foundation::Text::Xml::NSXmlNode>()) return false;

        auto p = (::NSXMLNode*)_ptr.__p;

        return p.kind == ::NSXMLNodeKind::NSXMLAttributeKind;
    }

    template <>
    Foundation::Text::Xml::NSXmlAttribute NSObject::Cast<Foundation::Text::Xml::NSXmlAttribute>() const
    {
        if (!Is<Foundation::Text::Xml::NSXmlAttribute>()) throw InvalidCastException();

        return As<Foundation::Text::Xml::NSXmlAttribute>();
    }

    template <>                                                             
    bool NSObject::Is<Foundation::Text::Xml::NSXmlText>() const noexcept 
    {
        if (!Is<Foundation::Text::Xml::NSXmlNode>()) return false;

        auto p = (::NSXMLNode*)_ptr.__p;

        return p.kind == ::NSXMLNodeKind::NSXMLTextKind;
    }

    template <>
    Foundation::Text::Xml::NSXmlText NSObject::Cast<Foundation::Text::Xml::NSXmlText>() const
    {
        if (!Is<Foundation::Text::Xml::NSXmlText>()) throw InvalidCastException();

        return As<Foundation::Text::Xml::NSXmlText>();
    }
}
