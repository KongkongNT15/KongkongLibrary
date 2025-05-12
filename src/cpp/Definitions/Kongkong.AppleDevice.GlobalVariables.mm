//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice
{
    Foundation::NSString NSInvalidArgumentException() noexcept
    {
        [::NSInvalidArgumentException retain];

        return Foundation::NSStringHelper::FromHandle(::NSInvalidArgumentException);
    }

    ssize_t GlobalVariables::NSNotFound() noexcept
    {
        return (ssize_t)::NSNotFound;
    }
}
