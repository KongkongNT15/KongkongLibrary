//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSNumber*)_instance())
#define CAST(object) ((::NSNumber*)object._instanceUnsafe())

#define DEF_INSTANCE \
    ArgumentNullException::CheckNull(left, u"left");                        \
    ArgumentNullException::CheckNull(right, u"right");                      \
    auto pLeft = (::NSNumber*)NSObjectHelper::GetPointer(left);             \
    auto pRight = (::NSNumber*)NSObjectHelper::GetPointer(right)

#define COMPARE [pLeft compare:pRight]

#define RETURN_COMPARE  \
    DEF_INSTANCE;       \
    return COMPARE

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    NSNumber::NSNumber(bool value) : NSValue(nullptr)
    {
        BOOL v = value ? YES : NO;
        _setInstance([::NSNumber numberWithBool:v]);
    }

    NSNumber::NSNumber(char value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithChar:value]);
    }

    NSNumber::NSNumber(short value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithShort:value]);
    }

    NSNumber::NSNumber(int value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithInt:value]);
    }

    NSNumber::NSNumber(long value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithLong:value]);
    }

    NSNumber::NSNumber(long long value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithLongLong:value]);
    }

    NSNumber::NSNumber(unsigned char value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithUnsignedChar:value]);
    }

    NSNumber::NSNumber(unsigned short value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithUnsignedShort:value]);
    }

    NSNumber::NSNumber(unsigned int value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithUnsignedInt:value]);
    }

    NSNumber::NSNumber(unsigned long value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithUnsignedLong:value]);
    }

    NSNumber::NSNumber(unsigned long long value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithUnsignedLongLong:value]);
    }

    NSNumber::NSNumber(float value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithFloat:value]);
    }

    NSNumber::NSNumber(double value) : NSValue(nullptr)
    {
        _setInstance([::NSNumber numberWithDouble:value]);
    }

    NSNumber::operator bool() const
    {
        return BoolValue();
    }

    NSNumber::operator char() const
    {
        return CharValue();
    }

    NSNumber::operator short() const
    {
        return ShortValue();
    }

    NSNumber::operator int() const
    {
        return IntValue();
    }

    NSNumber::operator long() const
    {
        return LongValue();
    }

    NSNumber::operator long long() const
    {
        return LongLongValue();
    }

    NSNumber::operator unsigned char() const
    {
        return UnsignedCharValue();
    }

    NSNumber::operator unsigned short() const
    {
        return UnsignedShortValue();
    }

    NSNumber::operator unsigned int() const
    {
        return UnsignedIntValue();
    }

    NSNumber::operator unsigned long() const
    {
        return UnsignedLongValue();
    }

    NSNumber::operator unsigned long long() const
    {
        return UnsignedLongLongValue();
    }

    NSNumber::operator float() const
    {
        return FloatValue();
    }

    NSNumber::operator double() const
    {
        return DoubleValue();
    }

    NSNumber::operator NSDecimal() const
    {
        return DecimalValue();
    }

    bool NSNumber::BoolValue() const
    {
        return (bool)(INSTANCE.boolValue);
    }

    char NSNumber::CharValue() const
    {
        return INSTANCE.charValue;
    }

    std::strong_ordering NSNumber::Compare(NSNumber const& value)
    {
        auto p = INSTANCE;
        ArgumentNullException::CheckNull(value, u"value");

        auto pRight = CAST(value);

        switch ([p compare:pRight]) {
            case ::NSComparisonResult::NSOrderedSame: return std::strong_ordering::equal;
            case ::NSComparisonResult::NSOrderedAscending: return std::strong_ordering::less;
            case ::NSComparisonResult::NSOrderedDescending: return std::strong_ordering::greater;
            default: [[unlikely]] return std::strong_ordering::equal;
        }
    }

    short NSNumber::ShortValue() const
    {
        return INSTANCE.shortValue;
    }

    NSString NSNumber::StringValue() const
    {
        auto p = INSTANCE;
        ::NSString* s = p.stringValue;
        [s retain];

        return NSStringHelper::FromHandle(s);
    }

    int NSNumber::IntValue() const
    {
        return INSTANCE.intValue;
    }

    long NSNumber::LongValue() const
    {
        return INSTANCE.longValue;
    }

    long long NSNumber::LongLongValue() const
    {
        return INSTANCE.longLongValue;
    }

    unsigned char NSNumber::UnsignedCharValue() const
    {
        return INSTANCE.unsignedCharValue;
    }

    unsigned short NSNumber::UnsignedShortValue() const
    {
        return INSTANCE.unsignedShortValue;
    }

    unsigned int NSNumber::UnsignedIntValue() const
    {
        return INSTANCE.unsignedIntValue;
    }

    unsigned long NSNumber::UnsignedLongValue() const
    {
        return INSTANCE.unsignedLongValue;
    }

    unsigned long long NSNumber::UnsignedLongLongValue() const
    {
        return INSTANCE.unsignedLongLongValue;
    }

    float NSNumber::FloatValue() const
    {
        return INSTANCE.floatValue;
    }

    double NSNumber::DoubleValue() const
    {
        return INSTANCE.doubleValue;
    }

    NSDecimal NSNumber::DecimalValue() const
    {
        ::NSDecimal v = INSTANCE.decimalValue;

        NSDecimal dec;

        auto pDec = (::NSDecimal*)dec._p;

        *pDec = v;

        return dec;
    }

    bool operator==(NSNumber const& left, NSNumber const& right)
    {
        RETURN_COMPARE == ::NSComparisonResult::NSOrderedSame;
    }

    bool operator!=(NSNumber const& left, NSNumber const& right)
    {
        RETURN_COMPARE != ::NSComparisonResult::NSOrderedSame;
    }

    bool operator<(NSNumber const& left, NSNumber const& right)
    {
        RETURN_COMPARE == ::NSComparisonResult::NSOrderedAscending;
    }

    bool operator<=(NSNumber const& left, NSNumber const& right)
    {
        RETURN_COMPARE != ::NSComparisonResult::NSOrderedDescending;
    }

    bool operator>(NSNumber const& left, NSNumber const& right)
    {
        RETURN_COMPARE == ::NSComparisonResult::NSOrderedDescending;
    }

    bool operator>=(NSNumber const& left, NSNumber const& right)
    {
        RETURN_COMPARE != ::NSComparisonResult::NSOrderedAscending;
    }

    std::strong_ordering operator<=>(NSNumber const& left, NSNumber const& right)
    {
        DEF_INSTANCE;

        switch (COMPARE) {
            case ::NSComparisonResult::NSOrderedSame: return std::strong_ordering::equal;
            case ::NSComparisonResult::NSOrderedAscending: return std::strong_ordering::less;
            case ::NSComparisonResult::NSOrderedDescending: return std::strong_ordering::greater;
            default: [[unlikely]] return std::strong_ordering::equal;
        }
    }
}

#undef INSTANCE
#undef RETURN_COMPARE
#undef COMPARE
#undef CAST
#undef DEF_INSTANCE
