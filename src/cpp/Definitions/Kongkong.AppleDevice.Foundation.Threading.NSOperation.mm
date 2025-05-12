//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSOperation*)_instance())
#define INSTANCE_UNSAFE ((::NSOperation*)_instanceUnsafe())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    void NSOperation::AddDependency(NSOperation const& op) const
    {
        ArgumentNullException::CheckNull(op, u"op");
        _checkNull();

        AddDependencyUnsafe(op);
    }

    void NSOperation::AddDependencyUnsafe(NSOperation const& op) const noexcept
    {
        ::NSOperation* pOp = (::NSOperation*)NSObjectHelper::GetPointer(op);

        [INSTANCE_UNSAFE addDependency:pOp];
    }

    Collections::ArrayWrapper<NSOperation> NSOperation::Dependencies() const
    {
        _checkNull();

        return GetDependenciesUnsafe();
    }

    Collections::ArrayWrapper<NSOperation> NSOperation::GetDependenciesUnsafe() const noexcept
    {
        auto pArray = [INSTANCE_UNSAFE dependencies];
        [pArray retain];

        Collections::NSArray array = nullptr;

        NSObjectHelper::SetPointer(array, pArray);

        return Collections::ArrayWrapper<NSOperation>(std::move(array));
    }

    bool NSOperation::GetIsAsynchronous() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isAsynchronous];
    }

    bool NSOperation::GetIsCancelledUnsafe() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isCancelled];
    }

    bool NSOperation::GetIsExecutingUnsafe() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isExecuting];
    }

    bool NSOperation::GetIsFinishedUnsafe() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isFinished];
    }

    bool NSOperation::GetIsReadyUnsafe() const noexcept
    {
        return (bool)[INSTANCE_UNSAFE isReady];
    }

    NSString NSOperation::GetNameUnsafe() const noexcept
    {
        ::NSString* s = [INSTANCE_UNSAFE name];

        NSString str = nullptr;

        if (s == nullptr) return str;

        [s retain];

        NSObjectHelper::SetPointer(str, s);

        return str;
    }

    bool NSOperation::IsAsynchronous() const
    {
        return (bool)[INSTANCE isAsynchronous];
    }

    bool NSOperation::IsCancelled() const
    {
        return (bool)[INSTANCE isCancelled];
    }

    bool NSOperation::IsExecuting() const
    {
        return (bool)[INSTANCE isExecuting];
    }

    bool NSOperation::IsFinished() const
    {
        return (bool)[INSTANCE isFinished];
    }

    bool NSOperation::IsReady() const
    {
        return (bool)[INSTANCE isReady];
    }

    NSString NSOperation::Name() const
    {
        _checkNull();
        return GetNameUnsafe();
    }

    void NSOperation::Name(::std::nullptr_t) const
    {
        (INSTANCE).name = nullptr;
    }

    void NSOperation::Name(NSString const& name) const
    {
        _checkNull();
        SetNameUnsafe(name);
    }

    void NSOperation::SetNameUnsafe(::std::nullptr_t) const noexcept
    {
        (INSTANCE_UNSAFE).name = nullptr;
    }

    void NSOperation::SetNameUnsafe(NSString const& name) const noexcept
    {
        if (name == nullptr) [[unlikely]] {
            (INSTANCE_UNSAFE).name = nullptr;
            return;
        }

        (INSTANCE_UNSAFE).name = (::NSString*)NSObjectHelper::GetPointer(name);
    }

    void NSOperation::Start() const
    {
        @try {
            [INSTANCE start];
        }
        @catch (::NSException* e) {
            NSObjectHelper::Throw(e);
        }
    }

    bool NSOperation::StartUnsafe() const noexcept
    {
        @try {
            [INSTANCE_UNSAFE start];
        }
        @catch (::NSException* e) {
            return false;
        }

        return true;
    }

    void NSOperation::RemoveDependency(NSOperation const& op) const
    {
        ArgumentNullException::CheckNull(op, u"op");
        _checkNull();

        RemoveDependencyUnsafe(op);
    }

    void NSOperation::RemoveDependencyUnsafe(NSOperation const& op) const noexcept
    {
        auto pOp = (::NSOperation*)NSObjectHelper::GetPointer(op);

        [INSTANCE_UNSAFE removeDependency:pOp];
    }

    void NSOperation::WaitUntilFinished() const
    {
        [INSTANCE waitUntilFinished];
    }

    void NSOperation::WaitUntilFinishedUnsafe() const noexcept
    {
        [INSTANCE_UNSAFE waitUntilFinished];
    }
}

#undef INSTANCE
#undef INSTANCE_UNSAFE

