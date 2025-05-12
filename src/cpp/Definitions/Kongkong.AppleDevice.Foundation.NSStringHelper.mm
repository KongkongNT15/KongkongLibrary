//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    NSString NSStringHelper::FromHandle(::NSString* p)
    {
        NSString str = nullptr;
        str._ptr.__p = p;

        return str;
    }
}
