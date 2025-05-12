#ifndef KONGKONG_TEXT_XML_XMLENTITIES_H
#define KONGKONG_TEXT_XML_XMLENTITIES_H

#include "Base.h"
#include "Kongkong.GenericStringView.h"

namespace KONGKONG_NAMESPACE::Text::Xml
{
    class XmlEntities final {
        public:

        STATIC_CLASS(XmlEntities)

        /// @brief 特殊文字'&'
        [[nodiscard]]
        static constexpr StringView Ampersand() noexcept { return _amp; }

        [[nodiscard]]
        static constexpr char16_t AmpersandChar() noexcept { return u'&'; }

        /// @brief 特殊文字'\''
        [[nodiscard]]
        static constexpr StringView Apostrophe() noexcept { return _apos; }

        [[nodiscard]]
        static constexpr char16_t ApostropheChar() noexcept { return u'\''; }

        /// @brief 特殊文字'>'
        [[nodiscard]]
        static constexpr StringView GreaterThan() noexcept { return _gt; }

        [[nodiscard]]
        static constexpr char16_t GreaterThanChar() noexcept { return u'>'; }

        [[nodiscard]]
        static constexpr bool IsXmlEntity(char16_t c) noexcept;
        
        /// @brief 特殊文字'<'
        [[nodiscard]]
        static constexpr StringView LessThan() noexcept { return _lt; }

        [[nodiscard]]
        static constexpr char16_t LessThanChar() noexcept { return u'<'; }

        /// @brief 特殊文字'"'
        [[nodiscard]]
        static constexpr StringView Quotation() noexcept { return _quot; }

        [[nodiscard]]
        static constexpr char16_t QuotationChar() noexcept { return u'"'; }

        /// @brief 右辺値は参照しない
        static StringView ToXmlChar(char16_t&&) = delete;

        [[nodiscard]]
        static constexpr StringView ToXmlChar(char16_t const& c) noexcept
        {
            switch (c) {
                case AmpersandChar():   return _amp;
                case ApostropheChar():  return _apos;
                case GreaterThanChar(): return _gt;
                case LessThanChar():    return _lt;
                case QuotationChar():   return _quot;
                default:                return StringView::FromChar(c);
            }

            //C++23 ::std::unreachable();
        }

        private:
        static constexpr StringView _amp = StringView::FromLiteral(u"&amp;");
        static constexpr StringView _apos = StringView::FromLiteral(u"&apos;");
        static constexpr StringView _gt = StringView::FromLiteral(u"&gt;");
        static constexpr StringView _lt = StringView::FromLiteral(u"&lt;");
        static constexpr StringView _quot = StringView::FromLiteral(u"&quot;");
    };

    constexpr bool XmlEntities::IsXmlEntity(char16_t c) noexcept
    {
        switch (c) {
            case AmpersandChar():
            case ApostropheChar():
            case GreaterThanChar():
            case LessThanChar():
            case QuotationChar():
                return true;
            default:
                return false;
        }

        //C++23 ::std::unreachable();
    }
}

#endif //!KONGKONG_TEXT_XML_XMLENTITIES_H
