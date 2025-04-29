#ifndef KONGKONG_TEXT_STATICSTRINGDATACREATER_H
#define KONGKONG_TEXT_STATICSTRINGDATACREATER_H

#include "Base.h"
#include "Kongkong.Text.StaticStringData.h"

namespace KONGKONG_NAMESPACE::Text
{
    class StaticStringDataCreater final {
        public:

        STATIC_CLASS(StaticStringDataCreater)

        template <CharType TChar, ssize_t N>
        [[nodiscard]] static StaticStringData<TChar, N> Create(const TChar (&arr)[N]) noexcept { return StaticStringData<TChar, N>(arr); }
    };
}

#endif //!KONGKONG_TEXT_STATICSTRINGDATACREATER_H
