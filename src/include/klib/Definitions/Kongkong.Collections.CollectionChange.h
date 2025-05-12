#ifndef KONGKONG_COLLECTIONS_COLLECTIONCHANGE_H
#define KONGKONG_COLLECTIONS_COLLECTIONCHANGE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections
{
    enum struct CollectionChange : uint8_t {
        ItemInserted,
        ItemRemoved,
        ItemChanged,
        Reset,
        Reverse,
    };
}

#endif //!KONGKONG_COLLECTIONS_COLLECTIONCHANGE_H
