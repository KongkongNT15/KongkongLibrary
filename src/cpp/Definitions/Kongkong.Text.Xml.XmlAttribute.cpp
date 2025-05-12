//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    XmlAttribute::XmlAttribute(String const& name) : XmlObject(XmlNodeType::Attribute),_xmlName(name)
    {
    }

    XmlAttribute::XmlAttribute(String&& name) : XmlObject(XmlNodeType::Attribute), _xmlName(std::move(name))
    {
    }

    XmlAttribute::XmlAttribute(String const& name, String const& value) : XmlObject(XmlNodeType::Attribute), _xmlContent(value), _xmlName(name)
    {
    }

    XmlAttribute::XmlAttribute(String const& name, String&& value) : XmlObject(XmlNodeType::Attribute), _xmlContent(std::move(value)), _xmlName(name)
    {
    }

    XmlAttribute::XmlAttribute(String&& name, String const& value) : XmlObject(XmlNodeType::Attribute), _xmlContent(value), _xmlName(std::move(name))
    {
    }

    XmlAttribute::ProjType XmlAttribute::NextAttribute() const noexcept
    {
        if (Parent() == nullptr) return nullptr;

        auto xmlElement = Parent().As<XmlElement::ProjType>();

        auto&& attributes = Object::ProjType::GetInstanceUnsafe(xmlElement).Attributes();

        auto& attributesRef = Object::ProjType::GetInstanceUnsafe(attributes);

        ssize_t index;
        ssize_t length = attributesRef.Length();

        for (index = 0; index != length; index++) {
            if (attributesRef[index].RawPointer() == this) {
                index++;
                break;
            }
        }

        if (index == length) return nullptr;

        return attributesRef[index];
    }

    XmlAttribute::ProjType XmlAttribute::PreviousAttribute() const noexcept
    {
        if (Parent() == nullptr) return nullptr;

        auto xmlElement = Parent().As<XmlElement::ProjType>();

        auto&& attributes = Object::ProjType::GetInstanceUnsafe(xmlElement).Attributes();

        auto& attributesRef = Object::ProjType::GetInstanceUnsafe(attributes);

        ssize_t index;
        ssize_t length = attributesRef.Length();

        for (index = 0; index != length; index++) {
            if (attributesRef[index].RawPointer() == this) break;
        }

        if (index == 0 || index == length) return nullptr;

        return attributesRef[index - 1];
    }

    String XmlAttribute::ToString() const
    {
        ssize_t capacity = 4 + _name.Length() + _value.Length();
        char16_t* p = String::AllocMemoryUnsafe(capacity);
        ssize_t length;

        length = _name.Length() * sizeof(char16_t);
        char* re = (char*)p;
        ::memcpy(re, _name.c_str(), length);

        re += length;

        length = 2 * sizeof(char16_t);

        ::memcpy(re, u"=\"", length);

        re += length;

        length = _value.Length() * sizeof(char16_t);

        ::memcpy(re, _value.c_str(), length);
        
        re += length;

        char16_t* rec = (char16_t*)re;

        *rec = u'"';
        *(rec + 1) = u'\0';

        return String::WrapUnsafe(capacity, capacity - 1, p);
    }
}

namespace KONGKONG_NAMESPACE::Text::Xml
{
    XmlAttribute::XmlAttribute(String const& name) : XmlObject(nullptr)
    {
        _setInstance(NEW ImplType(name));
    }

    XmlAttribute::XmlAttribute(String&& name) : XmlObject(nullptr)
    {
        _setInstance(NEW ImplType(std::move(name)));
    }

    XmlAttribute::XmlAttribute(String const& name, String const& value) : XmlObject(nullptr)
    {
        _setInstance(NEW ImplType(name, value));
    }

    XmlAttribute::XmlAttribute(String const& name, String&& value) : XmlObject(nullptr)
    {
        _setInstance(NEW ImplType(name, std::move(value)));
    }

    XmlAttribute::XmlAttribute(String&& name, String const& value) : XmlObject(nullptr)
    {
        _setInstance(NEW ImplType(std::move(name), value));
    }

    XmlAttribute::XmlAttribute(String&& name, String&& value) : XmlObject(nullptr)
    {
        _setInstance(NEW ImplType(std::move(name), std::move(value)));
    }
}
