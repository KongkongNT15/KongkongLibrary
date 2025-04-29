#ifndef KONGKONG_MEMORY_SHAREDHANDLEBASE_H
#define KONGKONG_MEMORY_SHAREDHANDLEBASE_H

#include "Base.h"
#include "Kongkong.GC.h"

namespace KONGKONG_NAMESPACE::Memory
{
    class _sharedHandleBase {
        public:

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _ptr._p != nullptr; }

        [[nodiscard]]
        String ToString() const;

        private:
        GC::__objectPtr _ptr;

        _sharedHandleBase(void* handle, void(*destory)(void*));
        constexpr _sharedHandleBase(::std::nullptr_t) noexcept : _ptr() {}

        template <class THandle>
        friend class SharedHandle;
    };
}

#endif //!KONGKONG_MEMORY_SHAREDHANDLEBASE_H
