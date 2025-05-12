#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSTHREADATTRIBUTE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSTHREADATTRIBUTE_H

#include "Base.h"
#include "Kongkong.HandleType.h"

namespace KONGKONG_NAMESPACE::Posix::Threading
{
    class ThreadAttribute final : public HandleType, private ::pthread_attr_t {
        public:

        ThreadAttribute();
        ThreadAttribute(ThreadAttribute const&) = delete;
        ThreadAttribute(ThreadAttribute&&) = delete;

        ~ThreadAttribute();

        ThreadAttribute& operator=(ThreadAttribute const&) = delete;
        ThreadAttribute& operator=(ThreadAttribute&&) = delete;
        
        [[nodiscard]] constexpr ::pthread_attr_t& pthread_attr_t() noexcept { return *this; }
        [[nodiscard]] constexpr ::pthread_attr_t const& pthread_attr_t() const noexcept { return *this; }

        [[nodiscard]]
        ThreadCreate DetachState() const noexcept;

        void DetachState(ThreadCreate value);

        [[nodiscard]]
        size_t GuardSize() const noexcept;

        void GuardSize(size_t guardSize);

        [[nodiscard]]
        ThreadScope Scope() const noexcept;

        void Scope(ThreadScope scope);

        int SetDetachStateUnsafe(ThreadCreate value) noexcept;
        int SetGuardSizeUnsafe(size_t guardSize) noexcept;
        int SetScopeUnsafe(ThreadScope scope) noexcept;
        int SetStackSizeUnsafe(size_t size) noexcept;
        int SetStackUnsafe(ThreadStackInfo const& info) noexcept;
        int SetStackUnsafe(void* stackAddress, size_t stackSize) noexcept;

        [[nodiscard]]
        ThreadStackInfo Stack() const noexcept;

        void Stack(ThreadStackInfo const& info);
        void Stack(void* stackAddress, size_t stackSize);

        [[nodiscard]]
        void* StackAddress() const noexcept;

        [[nodiscard]]
        size_t StackSize() const noexcept;

        void StackSize(size_t size);

        [[nodiscard]]
        String ToString() const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSTHREADATTRIBUTE_H
