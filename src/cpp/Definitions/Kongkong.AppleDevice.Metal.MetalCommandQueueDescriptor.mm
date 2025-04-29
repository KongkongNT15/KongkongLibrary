//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::MTLCommandQueueDescriptor*)_instance())
#define INSTANCE_UNSAFE ((::MTLCommandQueueDescriptor*)_instanceUnsafe())

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    MetalCommandQueueDescriptor::MetalCommandQueueDescriptor() : NSObject(nullptr)
    {
        _setInstance([[::MTLCommandQueueDescriptor alloc] init]);
    }
    
    MetalLogState MetalCommandQueueDescriptor::GetLogStateUnsafe() const noexcept
    {
        auto p = INSTANCE_UNSAFE.logState;

        if (p == nullptr) return nullptr;

        MetalLogState state = nullptr;
        [p retain];

        NSObjectHelper::SetPointer(state, p);

        return state;
    }

    size_t MetalCommandQueueDescriptor::GetMaxCommandBufferCountUnsafe() const noexcept
    {
        return INSTANCE_UNSAFE.maxCommandBufferCount;
    }

    MetalLogState MetalCommandQueueDescriptor::LogState() const
    {
        _checkNull();
        return GetLogStateUnsafe();
    }

    void MetalCommandQueueDescriptor::LogState(::std::nullptr_t) const
    {
        INSTANCE.logState = nil;
    }

    void MetalCommandQueueDescriptor::LogState(MetalLogState const& logState) const
    {
        INSTANCE.logState = (id<MTLLogState>)NSObjectHelper::GetPointer(logState);
    }

    size_t MetalCommandQueueDescriptor::MaxCommandBufferCount() const
    {
        return INSTANCE.maxCommandBufferCount;
    }

    void MetalCommandQueueDescriptor::MaxCommandBufferCount(size_t value) const
    {
        INSTANCE.maxCommandBufferCount = value;
    }

    void MetalCommandQueueDescriptor::SetLogStateUnsafe(::std::nullptr_t) const noexcept
    {
        INSTANCE_UNSAFE.logState = nil;
    }

    void MetalCommandQueueDescriptor::SetLogStateUnsafe(MetalLogState const& logState) const noexcept
    {
        INSTANCE_UNSAFE.logState = (id<MTLLogState>)NSObjectHelper::GetPointer(logState);
    }

    void MetalCommandQueueDescriptor::SetMaxCommandBufferCountUnsafe(size_t value) const noexcept
    {
        INSTANCE_UNSAFE.maxCommandBufferCount = value;
    }
}

#undef INSTANCE
#undef INSTANCE_UNSAFE
