//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    bool NSDebug::DeallocateZombies() noexcept
    {
        return (bool)::NSDeallocateZombies;
    }

    bool NSDebug::DebugEnabled() noexcept
    {
        return (bool)::NSDebugEnabled;
    }

    bool NSDebug::ZombieEnabled() noexcept
    {
        return (bool)::NSZombieEnabled;
    }
}
