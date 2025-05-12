#ifndef KONGKONG_APPLEDEVICE_METAL_METALCOMMANDQUEUEDESCRIPTOR_H
#define KONGKONG_APPLEDEVICE_METAL_METALCOMMANDQUEUEDESCRIPTOR_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    class MetalCommandQueueDescriptor : public NSObject {
        public:

        MetalCommandQueueDescriptor();

        /// @brief nullptrとして作成
        constexpr MetalCommandQueueDescriptor(::std::nullptr_t) noexcept : NSObject(nullptr) {}

        [[nodiscard]]
        MetalLogState GetLogStateUnsafe() const noexcept;

        [[nodiscard]]
        size_t GetMaxCommandBufferCountUnsafe() const noexcept;

        [[nodiscard]]
        MetalLogState LogState() const;

        void LogState(::std::nullptr_t) const;

        void LogState(MetalLogState const& logState) const;

        [[nodiscard]]
        size_t MaxCommandBufferCount() const;

        void MaxCommandBufferCount(size_t value) const;

        void SetLogStateUnsafe(::std::nullptr_t) const noexcept;

        void SetLogStateUnsafe(MetalLogState const& logState) const noexcept;

        void SetMaxCommandBufferCountUnsafe(size_t value) const noexcept;
    };
}

#endif //!KONGKONG_APPLEDEVICE_METAL_METALCOMMANDQUEUEDESCRIPTOR_H
