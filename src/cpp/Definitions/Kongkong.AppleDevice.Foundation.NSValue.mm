//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    NSValue::NSValue(const void* pointer) : NSObject(nullptr)
    {
        ArgumentNullException::CheckNull(pointer, u"pointer");
        _setInstance([::NSValue valueWithPointer:pointer]);
    }

    NSValue::NSValue(const void* pointer, const char* objCType) : NSObject(nullptr)
    {
        ArgumentNullException::CheckNull(pointer, u"pointer");
        ArgumentNullException::CheckNull(objCType, u"objCType");

        _setInstance([::NSValue valueWithBytes:pointer objCType:objCType]);
    }

    NSValue::NSValue(NSRange const& nsRange) : NSObject(nullptr)
    {
        ::NSRange range;
        range.location = nsRange.Location();
        range.length = nsRange.Length();

        _setInstance([::NSValue valueWithRange:range]);
    }

    

    bool NSValue::IsEqualToValue(NSValue const& nsValue) const
    {
        auto p = (::NSValue*)_instance();
        auto pRight = (::NSValue*)_instanceUnsafe();

        return (bool)[p isEqualToValue:pRight];
    }

    const char* NSValue::ObjCType() const
    {
        auto p = (::NSValue*)_instance();

        return p.objCType;
    }

    void* NSValue::PointerValue() const
    {
        auto p = (::NSValue*)_instance();

        return p.pointerValue;
    }

    NSRange NSValue::RangeValue() const
    {
        auto p = (::NSValue*)_instance();
        ::NSRange range = p.rangeValue;

        return NSRange(range.location, range.length);
    }
}
