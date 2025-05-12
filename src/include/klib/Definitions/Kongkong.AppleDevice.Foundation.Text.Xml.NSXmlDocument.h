#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLDOCUMENT_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLDOCUMENT_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlNode.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    class NSXmlDocument : public NSXmlNode {
        public:

        /// @brief 空のドキュメントを作成
        NSXmlDocument();

        /// @brief nullptrとして作成
        constexpr NSXmlDocument(std::nullptr_t) noexcept : NSXmlNode(nullptr) {}
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLDOCUMENT_H
