#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLATTRIBUTE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLATTRIBUTE_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Text.Xml.NSXmlNode.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text::Xml
{
    class NSXmlAttribute : public NSXmlNode {
        public:

        /// @brief 名前を指定して作成
        /// @param name 名前
        /// @throws ArgumentNullException: nameがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSXmlAttribute(NSString const& name);

        /// @brief 名前を指定して作成
        /// @param name 名前
        /// @throws ArgumentNullException: nameがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSXmlAttribute(NSString const& name, std::nullptr_t);

        /// @brief 名前と値を指定して作成
        /// @param name 名前
        /// @param stringValue 値
        /// @throws ArgumentNullException: nameがnullptrのとき
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        explicit NSXmlAttribute(NSString const& name, NSString const& stringValue);

        /// @brief nullptrとして作成
        constexpr NSXmlAttribute(std::nullptr_t) noexcept : NSXmlNode(nullptr) {}
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_TEXT_XML_NSXMLATTRIBUTE_H
