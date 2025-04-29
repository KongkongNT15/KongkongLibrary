//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text::Xml
{
    XmlDeclaration::XmlDeclaration() : _encoding(true), _standalone(true), _version(true)
    {
    }

    XmlDeclaration::XmlDeclaration(String const& version, String const& encoding) : _encoding(encoding, true), _standalone(true), _version(version, true)
    {
    }

    XmlDeclaration::XmlDeclaration(String const& version, String&& encoding) : _encoding(std::move(encoding)), _standalone(true), _version(version, true)
    {
    }

    XmlDeclaration::XmlDeclaration(String&& version, String const& encoding) : _encoding(encoding, true), _standalone(true), _version(std::move(version))
    {
    }

    XmlDeclaration::XmlDeclaration(String&& version, String&& encoding) : _encoding(std::move(encoding)), _standalone(true), _version(std::move(version))
    {
    }

    XmlDeclaration::XmlDeclaration(String const& version, String const& encoding, String const& standalone) : _encoding(encoding, true), _standalone(standalone, true), _version(version, true)
    {
    }

    XmlDeclaration::XmlDeclaration(String const& version, String const& encoding, String&& standalone) : _encoding(encoding, true), _standalone(std::move(standalone)), _version(version, true)
    {
    }

    XmlDeclaration::XmlDeclaration(String const& version, String&& encoding, String const& standalone) : _encoding(std::move(encoding)), _standalone(standalone, true), _version(version, true)
    {
    }

    XmlDeclaration::XmlDeclaration(String const& version, String&& encoding, String&& standalone) : _encoding(std::move(encoding)), _standalone(std::move(standalone)), _version(version, true)
    {
    }

    XmlDeclaration::XmlDeclaration(String&& version, String const& encoding, String const& standalone) : _encoding(encoding, true), _standalone(standalone, true), _version(std::move(version))
    {
    }

    XmlDeclaration::XmlDeclaration(String&& version, String const& encoding, String&& standalone) : _encoding(encoding, true), _standalone(std::move(standalone)), _version(std::move(version))
    {
    }

    XmlDeclaration::XmlDeclaration(String&& version, String&& encoding, String const& standalone) : _encoding(std::move(encoding)), _standalone(standalone, true), _version(std::move(version))
    {
    }

    void XmlDeclaration::Encoding(String const& value)
    {
        _encoding = value;
    }

    void XmlDeclaration::Encoding(String&& value) noexcept
    {
        _encoding = std::move(value);
    }

    void XmlDeclaration::Standalone(String const& value)
    {
        _standalone = value;
    }

    void XmlDeclaration::Standalone(String&& value) noexcept
    {
        _standalone = std::move(value);
    }

    

    String XmlDeclaration::ToString() const
    {
        constexpr char16_t version[] = u"version=\"";
        constexpr char16_t encoding[] = u"encoding=\"";
        constexpr char16_t standalone[] = u"standalone=\"";
        constexpr char16_t prefix[] = u"<?xml ";
        constexpr char16_t suffix[] = u"?>";
        constexpr ssize_t versionLength = (sizeof(version) / sizeof(char16_t)) - 1;
        constexpr ssize_t encodingLength = (sizeof(encoding) / sizeof(char16_t)) - 1;
        constexpr ssize_t standaloneLength = (sizeof(standalone) / sizeof(char16_t)) - 1;
        constexpr ssize_t prefixLength = (sizeof(prefix) / sizeof(char16_t)) - 1;
        constexpr ssize_t suffixLength = (sizeof(suffix) / sizeof(char16_t)) - 1;

        ssize_t length = 8;
        ssize_t capacity;
        char16_t* p;
        char16_t* current;
        int attributeCount = 0;

        if (!_version.IsEmpty()) {
            length += versionLength + _version.Length();
            ++attributeCount;
        }
        if (!_encoding.IsEmpty()) {
            length += encodingLength + _encoding.Length();
            ++attributeCount;
        }
        if (!_standalone.IsEmpty()) {
            length += standaloneLength + _standalone.Length();
            ++attributeCount;
        }

        length += (attributeCount - 1) * 2 - 1;
        capacity = length + 1;
        
        p = String::AllocMemoryUnsafe(capacity);

        ::memcpy(p, prefix, prefixLength * sizeof(char16_t));

        current = p + prefixLength;

        if (!_version.IsEmpty()) {
            ::memcpy(current, _version.c_str(), _version.Length() * sizeof(char16_t));

            current += _version.Length();
            *current = u'"';
            ++current;

            if (attributeCount > 1) {
                *current = u' ';
                ++current;
            }
        }

        if (!_encoding.IsEmpty()) {
            ::memcpy(current, _encoding.c_str(), _encoding.Length() * sizeof(char16_t));

            current += _encoding.Length();
            *current = u'"';
            ++current;

            if (!_standalone.IsEmpty()) {
                *current = u' ';
                ++current;
            }
        }
        
        if (!_standalone.IsEmpty()) {
            ::memcpy(current, _standalone.c_str(), _standalone.Length() * sizeof(char16_t));

            current += _standalone.Length();
            *current = u'"';
            ++current;
        }

        ::memcpy(current, suffix, suffixLength * sizeof(char16_t));

        p[length] = u'\0';

        return String::WrapUnsafe(capacity, length, p);
    }

    void XmlDeclaration::Version(String const& value)
    {
        _version = value;
    }

    void XmlDeclaration::Version(String&& value) noexcept
    {
        _version = std::move(value);
    }

}
