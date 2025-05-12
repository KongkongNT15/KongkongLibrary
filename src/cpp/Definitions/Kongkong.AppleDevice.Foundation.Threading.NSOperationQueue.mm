//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSOperationQueue*)_instance())
#define INSTANCE_UNSAFE ((::NSOperationQueue*)_instanceUnsafe())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    NSOperationQueue::NSOperationQueue() : NSObject(nullptr)
    {
        _setInstance([[::NSOperationQueue alloc] init]);
    }

    bool NSOperationQueue::AddOperationUnsafe(NSOperation const& op) const noexcept
    {
        ::NSOperation* p = (::NSOperation*)NSObjectHelper::GetPointer(op);

        @try {
            [INSTANCE_UNSAFE addOperation:p];
        }
        @catch (::NSException* e) {
            return false;
        }

        return true;
    }

    void NSOperationQueue::AddOperationWithBlockUnsafe(void(^block)(void)) const noexcept
    {
        [INSTANCE_UNSAFE addOperationWithBlock:block];
    }
}

#undef INSTANCE
#undef INSTANCE_UNSAFE

