#ifndef KONGKONG_TEXT_JSON_JSONVALUETYPE_H
#define KONGKONG_TEXT_JSON_JSONVALUETYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text::Json
{
    enum struct JsonValueType : uint8_t {
        Array,
        Boolean,
        Number,
        Null,
        Object,
        String,
    };
}

#endif //!KONGKONG_TEXT_JSON_JSONVALUETYPE_H
