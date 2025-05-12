#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLTEXT_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLTEXT_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlNode.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    class NSXmlText : public NSXmlNode {
        public:

        /// @brief テキストを設定して作成
        /// @param stringValue テキスト
        explicit NSXmlText(NSString const& stringValue);

        /// @brief nullptrとして作成
        constexpr NSXmlText(std::nullptr_t) noexcept : NSXmlNode(nullptr) {}
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLTEXT_H
