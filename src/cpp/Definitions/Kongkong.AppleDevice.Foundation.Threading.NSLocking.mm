//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((id<NSLocking>)_instance())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    void NSLocking::Lock() const
    {
        auto d = INSTANCE;

        [d lock];
    }

    void NSLocking::Unlock() const
    {
        auto d = INSTANCE;

        [d unlock];
    }
}

#undef INSTANCE
