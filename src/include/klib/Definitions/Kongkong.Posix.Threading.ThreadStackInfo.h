#ifndef KONGKONG_POSIX_THREADING_THREADSTACKINFO_H
#define KONGKONG_POSIX_THREADING_THREADSTACKINFO_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    struct ThreadStackInfo final : public ValueType {

        constexpr ThreadStackInfo(void* stackAddress, size_t stackSize) noexcept : _stackAddress(stackAddress), _stackSize(stackSize) {}

        [[nodiscard]]
        constexpr void* StackAddress() const noexcept { return _stackAddress; }

        [[nodiscard]]
        constexpr size_t StackSize() const noexcept { return _stackSize; }

        [[nodiscard]]
        String ToString() const;

        private:
        void* _stackAddress;
        size_t _stackSize;
    };
}

#endif //!KONGKONG_POSIX_THREADING_THREADSTACKINFO_H
