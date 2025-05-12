#ifndef KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastThreadSafeArrayMethods {

        [[nodiscard]]
        String ToString() const;

        private:
        _fastThreadSafeArrayMethods() = default;

        template <class T>
        friend struct FastThreadSafeArray;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTTHREADSAFEARRAYMETHODS_H
