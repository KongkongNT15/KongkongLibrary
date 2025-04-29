#ifndef KONGKONG_WIN32_THRADING_STACKINFO_H
#define KONGKONG_WIN32_THRADING_STACKINFO_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    struct StackInfo final : public ValueType, private ::TP_POOL_STACK_INFORMATION {

        [[nodiscard]]
        constexpr size_t Commit() const noexcept { return ::TP_POOL_STACK_INFORMATION::StackCommit; }

        [[nodiscard]]
        constexpr size_t Reserve() const noexcept { return ::TP_POOL_STACK_INFORMATION::StackReserve; }

        friend _threadPoolBase;
    };
}

#endif //!KONGKONG_WIN32_THRADING_STACKINFO_H
