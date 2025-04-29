//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSBlockOperation*)_instance())
#define INSTANCE_UNSAFE ((::NSBlockOperation*)_instanceUnsafe())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    NSBlockOperation NSBlockOperation::CreateUnsafe(BlockType block)
    {
        NSBlockOperation op = nullptr;

        op._setInstance([::NSBlockOperation blockOperationWithBlock:block]);

        return op;
    }

    NSBlockOperation NSBlockOperation::CreateUnsafe(VoidFuncType func)
    {
        NSBlockOperation op = nullptr;

        op._setInstance([::NSBlockOperation blockOperationWithBlock:^{ func(); }]);

        return op;
    }

    NSBlockOperation NSBlockOperation::CreateUnsafe(ArgsFuncType func)
    {
        NSBlockOperation op = nullptr;

        op._setInstance([::NSBlockOperation blockOperationWithBlock:^{ func(nullptr); }]);

        return op;
    }

    NSBlockOperation NSBlockOperation::CreateUnsafe(ArgsFuncType func, void* args)
    {
        NSBlockOperation op = nullptr;

        op._setInstance([::NSBlockOperation blockOperationWithBlock:^{ func(args); }]);

        return op;
    }

    NSBlockOperation NSBlockOperation::CreateUnsafe(ArgsFuncType func, std::nullptr_t)
    {
        NSBlockOperation op = nullptr;

        op._setInstance([::NSBlockOperation blockOperationWithBlock:^{ func(nullptr); }]);

        return op;
    }

    NSBlockOperation::NSBlockOperation(BlockType block) : NSOperation(nullptr)
    {
        if (block == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"block");
        _setInstance([::NSBlockOperation blockOperationWithBlock:block]);
    }

    NSBlockOperation::NSBlockOperation(VoidFuncType func) : NSOperation(nullptr)
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
        _setInstance([::NSBlockOperation blockOperationWithBlock:^{ func(); }]);
    }

    NSBlockOperation::NSBlockOperation(ArgsFuncType func) : NSOperation(nullptr)
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
        _setInstance([::NSBlockOperation blockOperationWithBlock:^{ func(nullptr); }]);
    }

    NSBlockOperation::NSBlockOperation(ArgsFuncType func, void* args) : NSOperation(nullptr)
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
        _setInstance([::NSBlockOperation blockOperationWithBlock:^{ func(args); }]);
    }

    NSBlockOperation::NSBlockOperation(ArgsFuncType func, std::nullptr_t) : NSBlockOperation(func)
    {
    }

    void NSBlockOperation::AddExecutionBlock(BlockType block) const
    {
        if (block == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"block");
        _checkNull();

        AddExecutionBlockUnsafe(block);
    }

    void NSBlockOperation::AddExecutionBlock(VoidFuncType func) const
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
        _checkNull();

        AddExecutionBlockUnsafe(func);
    }

    void NSBlockOperation::AddExecutionBlock(ArgsFuncType func) const
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
        _checkNull();

        AddExecutionBlockUnsafe(func);
    }

    void NSBlockOperation::AddExecutionBlock(ArgsFuncType func, void* args) const
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
        _checkNull();

        AddExecutionBlockUnsafe(func, args);
    }

    void NSBlockOperation::AddExecutionBlock(ArgsFuncType func, std::nullptr_t) const
    {
        if (func == nullptr) [[unlikely]] ArgumentNullException::ThrowWithName(u"func");
        _checkNull();

        AddExecutionBlockUnsafe(func);
    }

    void NSBlockOperation::AddExecutionBlockUnsafe(BlockType block) const noexcept
    {
        [INSTANCE_UNSAFE addExecutionBlock:block];
    }

    void NSBlockOperation::AddExecutionBlockUnsafe(VoidFuncType func) const noexcept
    {
        [INSTANCE_UNSAFE addExecutionBlock:^{ func(); }];
    }

    void NSBlockOperation::AddExecutionBlockUnsafe(ArgsFuncType func) const noexcept
    {
        [INSTANCE_UNSAFE addExecutionBlock:^{ func(nullptr); }];
    }

    void NSBlockOperation::AddExecutionBlockUnsafe(ArgsFuncType func, void* args) const noexcept
    {
        [INSTANCE_UNSAFE addExecutionBlock:^{ func(args); }];
    }

    void NSBlockOperation::AddExecutionBlockUnsafe(ArgsFuncType func, std::nullptr_t) const noexcept
    {
        [INSTANCE_UNSAFE addExecutionBlock:^{ func(nullptr); }];
    }

    Collections::BlockArrayWrapper<NSBlockOperation::BlockType> NSBlockOperation::ExecutionBlocks() const
    {
        _checkNull();
        return GetExecutionBlocksUnsafe();
    }

    Collections::BlockArrayWrapper<NSBlockOperation::BlockType> NSBlockOperation::GetExecutionBlocksUnsafe() const noexcept
    {
        ::NSArray* p = [INSTANCE_UNSAFE executionBlocks];
        [p retain];

        Collections::NSArray arr = nullptr;
        NSObjectHelper::SetPointer(arr, p);

        return Collections::BlockArrayWrapper<BlockType>(std::move(arr));
    }
}

#undef INSTANCE
#undef INSTANCE_UNSAFE

