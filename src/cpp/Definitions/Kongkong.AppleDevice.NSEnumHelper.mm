//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice
{
    constexpr Foundation::NSCalculationError NSEnumHelper::Convert(::NSCalculationError const& value) noexcept
    {
        switch (value) {
            case ::NSCalculationError::NSCalculationNoError: return Foundation::NSCalculationError::NoError;
            case ::NSCalculationError::NSCalculationLossOfPrecision: return Foundation::NSCalculationError::LossOfPrecision;
            case ::NSCalculationError::NSCalculationUnderflow: return Foundation::NSCalculationError::Underflow;
            case ::NSCalculationError::NSCalculationOverflow: return Foundation::NSCalculationError::Overflow;
            case ::NSCalculationError::NSCalculationDivideByZero: return Foundation::NSCalculationError::DivideByZero;
            default: [[unlikely]] return (Foundation::NSCalculationError)-1;
        }
    }

    constexpr Foundation::Text::Xml::NSXmlNodeKind NSEnumHelper::Convert(::NSXMLNodeKind const& value) noexcept
    {
        switch (value) {
            case NSXMLInvalidKind: return Foundation::Text::Xml::NSXmlNodeKind::Invalid;
            case NSXMLDocumentKind: return Foundation::Text::Xml::NSXmlNodeKind::Document;
            case NSXMLElementKind: return Foundation::Text::Xml::NSXmlNodeKind::Element;
            case NSXMLAttributeKind: return Foundation::Text::Xml::NSXmlNodeKind::Attribute;
            case NSXMLNamespaceKind: return Foundation::Text::Xml::NSXmlNodeKind::Namespace;
            case NSXMLProcessingInstructionKind: return Foundation::Text::Xml::NSXmlNodeKind::ProcessingInstruction;
            case NSXMLCommentKind: return Foundation::Text::Xml::NSXmlNodeKind::Comment;
            case NSXMLTextKind: return Foundation::Text::Xml::NSXmlNodeKind::Text;
            case NSXMLDTDKind: return Foundation::Text::Xml::NSXmlNodeKind::Dtd;
            case NSXMLEntityDeclarationKind: return Foundation::Text::Xml::NSXmlNodeKind::EntityDeclaration;
            case NSXMLAttributeDeclarationKind: return Foundation::Text::Xml::NSXmlNodeKind::AttributeDeclaration;
            case NSXMLElementDeclarationKind: return Foundation::Text::Xml::NSXmlNodeKind::ElementDeclaration;
            case NSXMLNotationDeclarationKind: return Foundation::Text::Xml::NSXmlNodeKind::NotationDeclaration;
            default: [[unlikely]] return (Foundation::Text::Xml::NSXmlNodeKind)-1;
        }
    }

    constexpr ::MTLLogLevel NSEnumHelper::Convert(Metal::MetalLogLevel value) noexcept
    {
        switch (value) {
            case Metal::MetalLogLevel::Debug: return ::MTLLogLevel::MTLLogLevelDebug;
            case Metal::MetalLogLevel::Info: return ::MTLLogLevel::MTLLogLevelInfo;
            case Metal::MetalLogLevel::Notice: return ::MTLLogLevel::MTLLogLevelNotice;
            case Metal::MetalLogLevel::Error: return ::MTLLogLevel::MTLLogLevelError;
            case Metal::MetalLogLevel::Fault: return ::MTLLogLevel::MTLLogLevelFault;
            case Metal::MetalLogLevel::Undefined: return ::MTLLogLevel::MTLLogLevelUndefined;
            default: [[unlikely]] return (::MTLLogLevel)-1;
        }
    }

    constexpr Metal::MetalLogLevel NSEnumHelper::Convert(::MTLLogLevel value) noexcept
    {
        switch (value) {
            case ::MTLLogLevel::MTLLogLevelDebug: return Metal::MetalLogLevel::Debug;
            case ::MTLLogLevel::MTLLogLevelInfo: return Metal::MetalLogLevel::Info;
            case ::MTLLogLevel::MTLLogLevelNotice: return Metal::MetalLogLevel::Notice;
            case ::MTLLogLevel::MTLLogLevelError: return Metal::MetalLogLevel::Error;
            case ::MTLLogLevel::MTLLogLevelFault: return Metal::MetalLogLevel::Fault;
            case ::MTLLogLevel::MTLLogLevelUndefined: return Metal::MetalLogLevel::Undefined;
            default: [[unlikely]] return (Metal::MetalLogLevel)-1;
        }
    }
}
