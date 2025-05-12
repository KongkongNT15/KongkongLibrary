#ifndef KONGKONG_TEXT_STRINGTYPE_H
#define KONGKONG_TEXT_STRINGTYPE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Text
{
    enum struct StringType : uint8_t {
        Static        = 0x1,
        Heap          = 0x2,
        Mutable       = 0x4,
        StaticMutable = Static | Mutable,
        HeapMutable   = Heap | Mutable,
    };

    CREATE_OPERATOR_AND_OR(StringType)
}

#endif //!KONGKONG_TEXT_STRINGTYPE_H
