#ifndef KONGKONG_MEMORY_SHAREDHANDLE_H
#define KONGKONG_MEMORY_SHAREDHANDLE_H

#include "Base.h"
#include "Kongkong.GC.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.Memory._sharedHandleBase.h"

namespace KONGKONG_NAMESPACE::Memory
{
    template <class THandle>
    class SharedHandle final : public HandleType, public _sharedHandleBase {
        public:

        SharedHandle(THandle handle, void(*destory)(void*)) : _sharedHandleBase(handle, destory) {}
        constexpr SharedHandle(::std::nullptr_t) noexcept : _sharedHandleBase(nullptr) {}

        [[nodiscard]]
        constexpr THandle Handle() const noexcept { return (THandle)this->_ptr._p; }

        
    };
}

#endif //!KONGKONG_MEMORY_SHAREDHANDLE_H
