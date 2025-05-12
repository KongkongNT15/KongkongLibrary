//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    MetalDevice MetalDevice::DefaultDevice() noexcept
    {
        id<MTLDevice> i = ::MTLCreateSystemDefaultDevice();

        [i retain];

        MetalDevice device = nullptr;

        NSObjectHelper::SetPointer(device, (void*)i);

        return device;
    }
}
