//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    NSRange NSRange::FromNSString(NSString const& str) noexcept
    {
        auto p = (::NSString*)NSObjectHelper::GetPointer(str);

        ::NSRange range = ::NSRangeFromString(p);

        return NSRange(range.location, (ssize_t)range.length);
    }

    NSString NSRange::ToNSString() const
    {
        ::NSString* p = ::NSStringFromRange({ _location, _length });

        return NSStringHelper::FromHandle(p);
    }

    String NSRange::ToString() const
    {
        return ToNSString().ToString();
    }
}
