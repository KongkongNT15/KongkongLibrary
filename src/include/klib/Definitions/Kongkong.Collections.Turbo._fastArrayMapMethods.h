#ifndef KONGKONG_COLLETIONS_TURBO_FASTARRAYMAPMETHODS_H
#define KONGKONG_COLLETIONS_TURBO_FASTARRAYMAPMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastArrayMapMethods {
        [[nodiscard]]
        String ToString() const;

        private:
        _fastArrayMapMethods() = default;
        _fastArrayMapMethods(_fastArrayMapMethods const&) = default;
        _fastArrayMapMethods(_fastArrayMapMethods&&) = default;

        _fastArrayMapMethods& operator=(_fastArrayMapMethods const&) = default;
        _fastArrayMapMethods& operator=(_fastArrayMapMethods&&) = default;
        
        template <class TKey, class TValue>
        friend struct FastArrayMap;
    };
}

#endif //!KONGKONG_COLLETIONS_TURBO_FASTARRAYMAPMETHODS_H
