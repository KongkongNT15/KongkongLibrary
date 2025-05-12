#ifndef KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYLISTMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYLISTMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastThreadSafeArrayListMethods {

        [[nodiscard]]
        String ToString() const;

        private:
        _fastThreadSafeArrayListMethods() = default;

        template <class T>
        friend struct FastThreadSafeArrayList;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYLISTMETHODS_H
