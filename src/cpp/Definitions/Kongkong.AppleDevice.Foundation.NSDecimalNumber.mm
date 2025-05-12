//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSNumber*)_instance())
#define CAST(object) ((::NSNumber*)object._instanceUnsafe())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    NSDecimalNumber NSDecimalNumber::NaN() noexcept
    {
        NSDecimalNumber num = nullptr;
        auto p = [::NSDecimalNumber notANumber];
        [p retain];

        NSObjectHelper::SetPointer(num, p);

        return num;
    }

    NSDecimalNumber NSDecimalNumber::One() noexcept
    {
        NSDecimalNumber num = nullptr;
        auto p = [::NSDecimalNumber one];
        [p retain];

        NSObjectHelper::SetPointer(num, p);

        return num;
    }

    NSDecimalNumber NSDecimalNumber::Zero() noexcept
    {
        NSDecimalNumber num = nullptr;
        auto p = [::NSDecimalNumber zero];
        [p retain];

        NSObjectHelper::SetPointer(num, p);

        return num;
    }
}

#undef INSTANCE
#undef CAST
