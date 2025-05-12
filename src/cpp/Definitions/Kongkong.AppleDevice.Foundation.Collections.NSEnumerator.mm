//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    NSObject NSEnumerator::NextObject() const
    {
        auto p = (::NSEnumerator*)_instance();

        ::NSObject* objp = [p nextObject];
        if (objp != nil) [objp retain];

        NSObject obj = nullptr;

        NSObjectHelper::SetPointer(obj, objp);

        return obj;
    }
}
