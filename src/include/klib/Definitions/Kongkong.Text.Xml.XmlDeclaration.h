#ifndef KONGKONG_TEXT_XML_XMLDECLARATION_H
#define KONGKONG_TEXT_XML_XMLDECLARATION_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Text::Xml
{
    struct XmlDeclaration final : public ValueType {

        explicit XmlDeclaration();
        explicit XmlDeclaration(String const& version, String const& encoding);
        explicit XmlDeclaration(String const& version, String&& encoding);
        explicit XmlDeclaration(String&& version, String const& encoding);
        explicit XmlDeclaration(String&& version, String&& encoding);
        explicit XmlDeclaration(String const& version, String const& encoding, String const& standalone);
        explicit XmlDeclaration(String const& version, String const& encoding, String&& standalone);
        explicit XmlDeclaration(String const& version, String&& encoding, String const& standalone);
        explicit XmlDeclaration(String const& version, String&& encoding, String&& standalone);
        explicit XmlDeclaration(String&& version, String const& encoding, String const& standalone);
        explicit XmlDeclaration(String&& version, String const& encoding, String&& standalone);
        explicit XmlDeclaration(String&& version, String&& encoding, String const& standalone);
        explicit constexpr XmlDeclaration(String&& version, String&& encoding, String&& standalone) noexcept : _version(std::move(version)), _encoding(std::move(encoding)), _standalone(std::move(standalone)) {}

        [[nodiscard]] constexpr String& Encoding() noexcept { return _encoding; }
        [[nodiscard]] constexpr String const& Encoding() const noexcept { return _encoding; }

        void Encoding(String const& value);
        void Encoding(String&& value) noexcept;

        [[nodiscard]] constexpr String& Standalone() noexcept { return _standalone; }
        [[nodiscard]] constexpr String const& Standalone() const noexcept { return _standalone; }

        void Standalone(String const& value);
        void Standalone(String&& value) noexcept;

        /// @brief こオブジェクトのXML表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        [[nodiscard]] constexpr String& Version() noexcept { return _version; }
        [[nodiscard]] constexpr String const& Version() const noexcept { return _version; }

        void Version(String const& value);
        void Version(String&& value) noexcept;

        private:
        String _encoding;
        String _standalone;
        String _version;
    };
}

#endif //!KONGKONG_TEXT_XML_XMLDECLARATION_H
