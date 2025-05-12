//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSXMLElement*)_instance())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    NSXmlElement::NSXmlElement(NSString const& name) : NSXmlNode(nullptr)
    {
        auto pName = (::NSString*)NSObjectHelper::GetPointer(name);

        ArgumentNullException::CheckNull(pName, u"name");

        _setInstance([[::NSXMLElement alloc] initWithName:pName]);
    }

    NSXmlElement::NSXmlElement(NSString const& name, ::std::nullptr_t) : NSXmlElement(name)
    {
    }

    NSXmlElement::NSXmlElement(NSString const& name, NSString const& stringValue) : NSXmlNode(nullptr)
    {
        auto pName = (::NSString*)NSObjectHelper::GetPointer(name);

        ArgumentNullException::CheckNull(pName, u"name");

        auto pStringValue = (::NSString*)NSObjectHelper::GetPointer(stringValue);

        _setInstance([[::NSXMLElement alloc] initWithName:pName stringValue:pStringValue]);
    }

    void NSXmlElement::AddAttribute(NSXmlAttribute const& attribute) const
    {
        auto p = INSTANCE;

        auto pAttribute = (NSXMLNode*)NSObjectHelper::GetPointer(attribute);

        ArgumentNullException::CheckNull(pAttribute, u"attribute");

        [p addAttribute:pAttribute];
    }

    void NSXmlElement::AddChild(NSXmlNode const& node) const
    {
        auto p = INSTANCE;

        auto pNode = (::NSXMLNode*)_checkAddChild(node);

        [p addChild:pNode];
    }

    Collections::ArrayWrapper<NSXmlAttribute> NSXmlElement::Attributes() const
    {
        auto p = INSTANCE;

        auto pArray = p.attributes;

        [pArray retain];

        Collections::NSArray arr = nullptr;

        NSObjectHelper::SetPointer(arr, pArray);

        return Collections::ArrayWrapper<NSXmlAttribute>(std::move(arr));
    }

    void NSXmlElement::Attributes(std::nullptr_t) const
    {
        auto p = INSTANCE;

        p.attributes = nil;
    }

    void NSXmlElement::Attributes(Collections::ArrayWrapper<NSXmlAttribute> const& attributes) const
    {
        auto p = INSTANCE;

        auto pArray = (::NSArray*)NSObjectHelper::GetPointer(attributes.Array());

        p.attributes = pArray;
    }

    void NSXmlElement::Children(std::nullptr_t) const
    {
        auto p = INSTANCE;

        [p setChildren:nil];
    }

    void NSXmlElement::Children(Collections::ArrayWrapper<NSXmlNode> const& children) const
    {
        auto p = INSTANCE;

        auto pChildren = (::NSArray*)NSObjectHelper::GetPointer(children.Array());

        ArgumentNullException::CheckNull(pChildren, u"children");

        [p setChildren:pChildren];
    }

    NSXmlAttribute NSXmlElement::GetAttribute(NSString const& name) const
    {
        auto p = INSTANCE;

        auto pName = (::NSString*)NSObjectHelper::GetPointer(name);

        ArgumentNullException::CheckNull(pName, u"name");

        NSXmlAttribute attribute = nullptr;
        auto pResult = [p attributeForName:pName];

        if (pResult == nil) return attribute;

        [pResult retain];

        NSObjectHelper::SetPointer(attribute, pResult);

        return attribute;
    }

    Collections::ArrayWrapper<NSXmlElement> NSXmlElement::GetElements(NSString const& name) const
    {
        auto p = INSTANCE;

        auto pName = (::NSString*)NSObjectHelper::GetPointer(name);

        ArgumentNullException::CheckNull(pName, u"name");

        Collections::NSArray arr = nullptr;

        auto pResult = [p elementsForName:pName];

        NSObjectHelper::SetPointer(arr, pResult);

        return Collections::ArrayWrapper<NSXmlElement>(std::move(arr));
    }

    void NSXmlElement::InsertChild(ssize_t index, NSXmlNode const& node) const
    {
        auto p = INSTANCE;

        auto pNode = (::NSXMLNode*)_checkAddChild(node);

        @try {
            [p insertChild:pNode atIndex:(size_t)index];
        }
        @catch (::NSException* e) {
            throw ArgumentOutOfRangeException(NSStringHelper::FromHandle(e.reason).ToString());
        }
    }

    void NSXmlElement::InsertChildren(ssize_t index, Collections::ArrayWrapper<NSXmlNode> const& children) const
    {
        auto p = INSTANCE;

        auto pChildren = (::NSArray*)NSObjectHelper::GetPointer(children.Array());

        ArgumentNullException::CheckNull(pChildren, u"children");

        @try {
            [p insertChildren:pChildren atIndex:(size_t)index];
        }
        @catch (::NSException* e) {
            throw ArgumentOutOfRangeException(NSStringHelper::FromHandle(e.reason).ToString());
        }
    }

    void NSXmlElement::RemoveAttributeForName(NSString const& name) const
    {
        auto p = INSTANCE;

        auto pName = (::NSString*)NSObjectHelper::GetPointer(name);
    
        ArgumentNullException::CheckNull(pName, u"name");

        [p removeAttributeForName:pName];
    }

    void NSXmlElement::RemoveChildAtIndex(ssize_t index) const
    {
        auto p = INSTANCE;

        @try {
            [p removeChildAtIndex:(size_t)index];
        }
        @catch (::NSException* e) {
            throw ArgumentOutOfRangeException(NSStringHelper::FromHandle(e.reason).ToString());
        }

    }

    void NSXmlElement::ReplaceChildAtIndex(ssize_t index, NSXmlNode const& node) const
    {
        auto p = INSTANCE;

        auto pNode = (::NSXMLNode*)_checkAddChild(node);

        @try {
            [p replaceChildAtIndex:(size_t)index withNode:pNode];
        }
        @catch (::NSException* e) {
            throw ArgumentOutOfRangeException(NSStringHelper::FromHandle(e.reason).ToString());
        }
    }

    void* NSXmlElement::_checkAddChild(NSXmlNode const& node) const
    {
        auto p = (::NSXMLNode*)_instanceUnsafe();

        auto pNode = NSObjectHelper::GetPointer(node);

        ArgumentNullException::CheckNull(pNode, u"node");

        if (p == pNode) [[unlikely]] throw InvalidArgumentException(u"*thisを子要素に追加しようとしました");

        while ((p = p.parent) != nil) {
            if (p == pNode) [[unlikely]] throw InvalidArgumentException(u"指定されたノードは親です");
        }

        return pNode;
    }
}

#undef INSTANCE

