#ifndef KONGKONG_TEXT_XML_XMLOBJECT_H
#define KONGKONG_TEXT_XML_XMLOBJECT_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.Text.Xml.XmlNodeType.h"

namespace KONGKONG_NAMESPACE::Text::Xml
{
    class XmlObject : public Object {
        public:
        using ImplType = IMPLEMENTATION::XmlObject;

        /// @brief nullptrとして作成
        constexpr XmlObject(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

namespace KONGKONG_NAMESPACE::Text::Xml::IMPLEMENTATION
{
    struct XmlObject : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Text::Xml::XmlObject;

        [[nodiscard]]
        int32_t Level() const noexcept;

        [[nodiscard]]
        constexpr XmlNodeType NodeType() const noexcept { return _nodeType; }

        [[nodiscard]]
        constexpr ProjType const& Parent() const noexcept { return _parent; }

        protected:
        constexpr XmlObject(XmlNodeType nodeType) : _nodeType(nodeType), _parent(nullptr) {}

        private:
        
        XmlNodeType _nodeType;
        ProjType _parent;
    };
}

#endif //!KONGKONG_TEXT_XML_XMLOBJECT_H
