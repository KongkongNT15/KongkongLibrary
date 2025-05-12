//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    NSNull NSNull::Null() noexcept
    {
        ::NSNull* p = [::NSNull null];
        //意味ないぞ
        [p retain];

        NSNull result = nullptr;

        NSObjectHelper::SetPointer(result, p);

        return result;
    }
}

