//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((id<MTLLogState>)_instance())
#define INSTANCE_UNSAFE ((id<MTLLogState>)_instanceUnsafe())
#define HANDLER_TYPE void(^)(::NSString*, ::NSString*, id<MTLLogLevel>, ::NSString*)
#define HANDLER ^(::NSString* subSystem, ::NSString* category, id<MTLLogLevel> logLevel, ::NSString* message) \
    {   \
        Foundation::NSString subSystem1 = nullptr;  \
        Foundation::NSString category1 = nullptr;   \
        Foundation::NSString message1 = nullptr;    \
        [subSystem retain];                         \
        [category retain];                          \
        [message retain];                           \
        NSObjectHelper::SetPointer(subSystem1, subSystem);  \
        NSObjectHelper::SetPointer(category1, category);    \
        NSObjectHelper::SetPointer(message1, message);      \
        func(subSystem1, category1, NSEnumHelper::Convert(logLevel), message1);            \
    }   \

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    void MetalLogState::AddLogHandler(void(*func)(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)) const
    {
        _checkNull();
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
        
        AddLogHandlerUnsafe(func);
    }

    void MetalLogState::AddLogHandler(void(^func)(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)) const
    {
        _checkNull();
        AddLogHandlerUnsafe(func);
    }

    void MetalLogState::AddLogHandler(::std::function<void(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)> const& func) const
    {
        _checkNull();
        AddLogHandlerUnsafe(func);
    }

    void MetalLogState::AddLogHandlerUnsafe(void(*func)(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)) const noexcept
    {
        //using hType = HANDLER_TYPE;
        //hType f = HANDLER;

        [INSTANCE_UNSAFE addLogHandler:HANDLER];
    }

    void MetalLogState::AddLogHandlerUnsafe(void(^)(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&) func) const noexcept
    {
        //using hType = HANDLER_TYPE;
        //hType f = HANDLER;

        [INSTANCE_UNSAFE addLogHandler:HANDLER];
    }

    void MetalLogState::AddLogHandlerUnsafe(::std::function<void(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)> const& func) const noexcept
    {
        //using hType = HANDLER_TYPE;
        //hType f = HANDLER;

        [INSTANCE_UNSAFE addLogHandler:HANDLER];
    }
}

#undef INSTANCE
#undef INSTANCE_UNSAFE
#undef HANDLER_TYPE
#undef HANDLER
