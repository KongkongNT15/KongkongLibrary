#ifndef KONGKONG_COLLECTIONS_TURBO_FASTBUILTINARRAYLISTMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTBUILTINARRAYLISTMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastBuiltInArrayListMethods {

        [[nodiscard]]
        String ToString() const;

        private:

        _fastBuiltInArrayListMethods() = default;

        template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
        friend struct BuiltInArrayList;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTBUILTINARRAYLISTMETHODS_H
