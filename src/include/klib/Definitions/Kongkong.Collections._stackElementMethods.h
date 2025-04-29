#ifndef KONGKONG_COLLECTIONS_STACKELEMENTMETHODS_H
#define KONGKONG_COLLECTIONS_STACKELEMENTMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections
{
    struct _stackElementMethods {

        [[nodiscard]]
        String ToString() const;

        private:
        _stackElementMethods() = default;
        _stackElementMethods(_stackElementMethods const&) = default;
        _stackElementMethods(_stackElementMethods&&) = default;

        _stackElementMethods& operator=(_stackElementMethods const&) = default;
        _stackElementMethods& operator=(_stackElementMethods&&) = default;

        template <class T>
        friend struct StackElement;
    };
}

#endif //!KONGKONG_COLLECTIONS_STACKELEMENTMETHODS_H