#ifndef KONGKONG_INTERFACE_H
#define KONGKONG_INTERFACE_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.InterfaceType.h"

namespace KONGKONG_NAMESPACE
{
    KONGKONG_INTERFACE Interface : public Object, public InterfaceType {

        Object::ImplType* operator->() const = delete;

        protected:
        constexpr Interface(std::nullptr_t) noexcept : Object(nullptr) {}
    };
}

#endif //!KONGKONG_INTERFACE_H
