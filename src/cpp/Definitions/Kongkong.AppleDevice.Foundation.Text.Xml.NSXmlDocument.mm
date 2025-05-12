//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSXMLDocument*)_instance())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    NSXmlDocument::NSXmlDocument() : NSXmlNode(nullptr)
    {
        _setInstance([::NSXMLNode document]);
    }
}



#undef INSTANCE
