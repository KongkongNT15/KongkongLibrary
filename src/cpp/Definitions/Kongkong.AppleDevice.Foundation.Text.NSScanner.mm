//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSScanner*)_instance())

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Text
{
    NSScanner::NSScanner(NSString const& str) : NSObject(nullptr)
    {
        ArgumentNullException::CheckNull(str, u"str");

        ::NSString* pStr = (::NSString*)NSObjectHelper::GetPointer(str);

        _setInstance([::NSScanner scannerWithString:pStr]);
    }

    NSScanner::NSScanner(NSString const& str, bool isLocalized) : NSObject(nullptr)
    {
        ArgumentNullException::CheckNull(str, u"str");

        ::NSString* pStr = (::NSString*)NSObjectHelper::GetPointer(str);

        _setInstance(isLocalized ? [::NSScanner localizedScannerWithString:pStr] : [::NSScanner scannerWithString:pStr]);
    }

    bool NSScanner::AtEnd() const
    {
        auto p = INSTANCE;

        return (bool)p.atEnd;
    }

    bool NSScanner::CaseSensitive() const
    {
        auto p = INSTANCE;

        return (bool)p.caseSensitive;
    }

    void NSScanner::CaseSensitive(bool value) const
    {
        auto p = INSTANCE;

        p.caseSensitive = value ? YES : NO;
    }

    bool NSScanner::ScanDecimal(NSDecimal& target) const
    {
        auto p = INSTANCE;

        ::NSDecimal* pD = (::NSDecimal*)target._p;

        return (bool)[p scanDecimal:pD];
    }

    bool NSScanner::ScanDouble(double& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanDouble:&target];
    }

    bool NSScanner::ScanFloat(float& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanFloat:&target];
    }

    bool NSScanner::ScanHexDouble(double& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanHexDouble:&target];
    }

    bool NSScanner::ScanHexFloat(float& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanHexFloat:&target];
    }

    bool NSScanner::ScanHexInt(unsigned int& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanHexInt:&target];
    }

    bool NSScanner::ScanHexLongLong(unsigned long long& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanHexLongLong:&target];
    }

    bool NSScanner::ScanInt(int& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanInt:&target];
    }

    bool NSScanner::ScanInteger(ssize_t& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanInteger:&target];
    }

    ssize_t NSScanner::ScanLocation() const
    {
        auto p = INSTANCE;

        return (ssize_t)[p scanLocation];
    }

    bool NSScanner::ScanLongLong(long long& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanLongLong:&target];
    }

    bool NSScanner::ScanString(NSString const& str) const
    {
        auto p = INSTANCE;
        ArgumentNullException::CheckNull(str, u"str");

        auto pStr = (::NSString*)NSObjectHelper::GetPointer(str);

        return (bool)[p scanString:pStr intoString:nil];
    }

    bool NSScanner::ScanString(NSString const& str, NSString& result) const
    {
        auto p = INSTANCE;
        ArgumentNullException::CheckNull(str, u"str");

        auto pStr = (::NSString*)NSObjectHelper::GetPointer(str);
        ::NSString* result1 = nil;

        bool v = (bool)[p scanString:pStr intoString:&result1];

        if (v) {
            auto resultStr = (::NSString*)NSObjectHelper::GetPointer(result);

            if (resultStr != nil) {
                [resultStr release];
            }

            NSObjectHelper::SetPointer(result, result1);
        }

        return v;
    }

    bool NSScanner::ScanUpToString(NSString const& str) const
    {
        auto p = INSTANCE;
        ArgumentNullException::CheckNull(str, u"str");

        auto pStr = (::NSString*)NSObjectHelper::GetPointer(str);

        return (bool)[p scanUpToString:pStr intoString:nil];
    }

    bool NSScanner::ScanUpToString(NSString const& str, NSString& result) const
    {
        auto p = INSTANCE;
        ArgumentNullException::CheckNull(str, u"str");

        auto pStr = (::NSString*)NSObjectHelper::GetPointer(str);
        ::NSString* result1 = nil;

        bool v = (bool)[p scanUpToString:pStr intoString:&result1];

        if (v) {
            auto resultStr = (::NSString*)NSObjectHelper::GetPointer(result);

            if (resultStr != nil) {
                [resultStr release];
            }

            NSObjectHelper::SetPointer(result, result1);
        }

        return v;
    }

    bool NSScanner::ScanUnsignedLongLong(unsigned long long& target) const
    {
        auto p = INSTANCE;

        return (bool)[p scanUnsignedLongLong:&target];
    }

    NSString NSScanner::String() const
    {
        auto p = INSTANCE;

        auto pStr = p.string;
        [pStr retain];
        
        return NSStringHelper::FromHandle(pStr);
    }
}



#undef INSTANCE
