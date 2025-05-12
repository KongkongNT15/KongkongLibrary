//このObjective-C++ファイルをコンパイルに含めないでください

#define CAST(object) (::NSDecimal*)((object)._p)
#define INSTANCE (::NSDecimal*)_p

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    NSDecimal::NSDecimal() : _p(NEW ::NSDecimal())
    {
        MemoryAllocationException::CheckNull(_p);
    }

    NSDecimal::NSDecimal(NSDecimal const& right) : _p(NEW ::NSDecimal(*(CAST(right))))
    {
        MemoryAllocationException::CheckNull(_p);
    }

    NSDecimal::NSDecimal(NSDecimal&& right) noexcept : _p(right._p)
    {
        right._p = nullptr;
    }

    NSDecimal::~NSDecimal()
    {
        if (_p != nullptr) delete INSTANCE;
    }

    NSDecimal& NSDecimal::operator=(NSDecimal const& right) noexcept
    {
        auto p = INSTANCE;
        auto pRight = CAST(right);

        new (p) ::NSDecimal(*pRight);

        return *this;
    }

    NSDecimal& NSDecimal::operator=(NSDecimal&& right) noexcept
    {
        NSDecimal::~NSDecimal();

        _p = right._p;
        right._p = nullptr;

        return *this;
    }

    NSString NSDecimal::ToNSString() const
    {
        return NSStringHelper::FromHandle(::NSDecimalString(INSTANCE, nil));
    }

    String NSDecimal::ToString() const
    {
        return ToNSString().ToString();
    }

    bool operator==(NSDecimal const& left, NSDecimal const& right) noexcept
    {
        return ::NSDecimalCompare(CAST(left), CAST(right)) == ::NSComparisonResult::NSOrderedSame;
    }

    bool operator!=(NSDecimal const& left, NSDecimal const& right) noexcept
    {
        return ::NSDecimalCompare(CAST(left), CAST(right)) != ::NSComparisonResult::NSOrderedSame;
    }

    bool operator<(NSDecimal const& left, NSDecimal const& right) noexcept
    {
        return ::NSDecimalCompare(CAST(left), CAST(right)) == ::NSComparisonResult::NSOrderedAscending;
    }

    bool operator<=(NSDecimal const& left, NSDecimal const& right) noexcept
    {
        return ::NSDecimalCompare(CAST(left), CAST(right)) != ::NSComparisonResult::NSOrderedDescending;
    }

    bool operator>(NSDecimal const& left, NSDecimal const& right) noexcept
    {
        return ::NSDecimalCompare(CAST(left), CAST(right)) == ::NSComparisonResult::NSOrderedDescending;
    }

    bool operator>=(NSDecimal const& left, NSDecimal const& right) noexcept
    {
        return ::NSDecimalCompare(CAST(left), CAST(right)) != ::NSComparisonResult::NSOrderedAscending;
    }

    std::strong_ordering operator<=>(NSDecimal const& left, NSDecimal const& right) noexcept
    {
        switch (::NSDecimalCompare(CAST(left), CAST(right))) {
            case ::NSComparisonResult::NSOrderedSame: return std::strong_ordering::equal;
            case ::NSComparisonResult::NSOrderedAscending: return std::strong_ordering::less;
            case ::NSComparisonResult::NSOrderedDescending: return std::strong_ordering::greater;
            default: [[unlikely]] return std::strong_ordering::equal;
        }
    }
}

#undef CAST
#undef INSTANCE
