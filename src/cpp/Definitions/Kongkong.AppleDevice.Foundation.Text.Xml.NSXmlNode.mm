//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSXMLNode*)_instance())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    NSXmlNode NSXmlNode::ChildAtIndex(ssize_t index) const
    {
        auto p = INSTANCE;

        ::NSXMLNode* pResult;

        @try {
            pResult = [p childAtIndex:(size_t)index];
        }
        @catch (::NSException* e) {
            throw ArgumentOutOfRangeException(NSStringHelper::FromHandle(e.reason).ToString());
        }

        if (pResult == nil) throw InvalidOperationException(u"このノードに子要素はありません");

        [pResult retain];

        NSXmlNode node = nullptr;

        NSObjectHelper::SetPointer(node, pResult);

        return node;
    }

    ssize_t NSXmlNode::ChildCount() const
    {
        auto p = INSTANCE;

        return (ssize_t)p.childCount;
    }

    Collections::ArrayWrapper<NSXmlNode> NSXmlNode::Children() const
    {
        auto p = INSTANCE;

        auto pResult = (::NSArray*)p.children;

        Collections::NSArray arr = nullptr;

        if (pResult == nil) return Collections::ArrayWrapper<NSXmlNode>(std::move(arr));

        [pResult retain];
        
        NSObjectHelper::SetPointer(arr, pResult);

        return Collections::ArrayWrapper<NSXmlNode>(std::move(arr));
    }

    void NSXmlNode::Detach() const
    {
        auto p = INSTANCE;

        [p detach];
    }

    ssize_t NSXmlNode::Index() const
    {
        auto p = INSTANCE;

        return (ssize_t)p.index;
    }

    NSXmlNodeKind NSXmlNode::Kind() const
    {
        auto p = INSTANCE;

        return NSEnumHelper::Convert(p.kind);
    }

    ssize_t NSXmlNode::Level() const
    {
        auto p = INSTANCE;

        return (ssize_t)p.level;
    }

    NSString NSXmlNode::LocalName() const
    {
        auto p = INSTANCE;

        auto pResult = (::NSString*)p.localName;

        if (pResult == nil) [[unlikely]] return nullptr;

        [pResult retain];

        return NSStringHelper::FromHandle(pResult);
    }

    NSString NSXmlNode::Name() const
    {
        auto p = INSTANCE;

        auto pStr = p.name;

        [pStr retain];

        return NSStringHelper::FromHandle(pStr);
    }

    void NSXmlNode::Name(NSString const& name) const
    {
        auto p = INSTANCE;

        ArgumentNullException::CheckNull(name, u"name");

        auto pName = (::NSString*)NSObjectHelper::GetPointer(name);

        p.name = pName;
    }

    NSXmlNode NSXmlNode::NextNode() const
    {
        auto p = INSTANCE;

        auto pResult = p.nextNode;

        NSXmlNode node = nullptr;

        if (pResult == nil) return node;

        [pResult retain];

        NSObjectHelper::SetPointer(node, pResult);

        return node;
    }

    NSXmlNode NSXmlNode::NextSibling() const
    {
        auto p = INSTANCE;

        auto pResult = p.nextSibling;

        NSXmlNode node = nullptr;

        if (pResult == nil) return node;

        [pResult retain];

        NSObjectHelper::SetPointer(node, pResult);

        return node;
    }

    NSObject NSXmlNode::ObjectValue() const
    {
        auto p = INSTANCE;

        ::NSObject* pResult = p.objectValue;

        [pResult retain];

        NSObject object = nullptr;
        NSObjectHelper::SetPointer(object, pResult);

        return object;
    }

    void NSXmlNode::ObjectValue(NSObject const& newValue) const
    {
        auto p = INSTANCE;

        ArgumentNullException::CheckNull(newValue, u"newValue");

        auto pNewValue = (::NSObject*)NSObjectHelper::GetPointer(newValue);

        p.objectValue = pNewValue;
    }

    NSXmlNode NSXmlNode::Parent() const
    {
        auto p = INSTANCE;

        auto pResult = (::NSXMLNode*)p.parent;

        if (pResult == nil) return nullptr;

        [pResult retain];

        NSXmlNode node = nullptr;

        NSObjectHelper::SetPointer(node, pResult);

        return node;
    }

    NSXmlNode NSXmlNode::PreviousNode() const
    {
        auto p = INSTANCE;

        auto pResult = p.previousNode;

        NSXmlNode node = nullptr;

        if (pResult == nil) return node;

        [pResult retain];

        NSObjectHelper::SetPointer(node, pResult);

        return node;
    }

    NSXmlNode NSXmlNode::PreviousSibling() const
    {
        auto p = INSTANCE;

        auto pResult = p.previousSibling;

        NSXmlNode node = nullptr;

        if (pResult == nil) return node;

        [pResult retain];

        NSObjectHelper::SetPointer(node, pResult);

        return node;
    }

    NSXmlDocument NSXmlNode::RootDocument() const
    {
        auto p = INSTANCE;

        auto pResult = (::NSXMLDocument*)p.rootDocument;

        if (pResult == nil) return nullptr;

        [pResult retain];

        NSXmlDocument document = nullptr;
        NSObjectHelper::SetPointer(document, pResult);

        return document;
    }

    NSString NSXmlNode::StringValue() const
    {
        auto p = INSTANCE;

        auto pResult = p.stringValue;

        [pResult retain];

        return NSStringHelper::FromHandle(pResult);
    }

    void NSXmlNode::StringValue(NSString const& newValue) const
    {
        auto p = INSTANCE;

        ArgumentNullException::CheckNull(newValue, u"newValue");

        auto pNewValue = (::NSString*)NSObjectHelper::GetPointer(newValue);

        p.stringValue = pNewValue;
    }

    NSString NSXmlNode::Uri() const
    {
        auto p = INSTANCE;

        auto pStr = [p URI];

        if (pStr != nil) [pStr retain];

        return NSStringHelper::FromHandle(pStr);
    }

    void NSXmlNode::Uri(std::nullptr_t) const
    {
        auto p = INSTANCE;

        [p setURI:nil];
    }

    void NSXmlNode::Uri(NSString const& value) const
    {
        auto p = INSTANCE;

        auto pStr = (::NSString*)NSObjectHelper::GetPointer(value);

        [p setURI:pStr];
    }

    NSString NSXmlNode::XmlString() const
    {
        auto p = INSTANCE;

        return NSStringHelper::FromHandle(p.XMLString);
    }

    NSString NSXmlNode::XPath() const
    {
        auto p = INSTANCE;

        auto pResult = p.XPath;

        if (pResult == nil) return nullptr;

        [pResult retain];

        return NSStringHelper::FromHandle(pResult);
    }
}

#undef INSTANCE
