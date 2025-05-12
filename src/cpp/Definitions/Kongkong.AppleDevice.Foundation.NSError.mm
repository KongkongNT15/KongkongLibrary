//このObjective-C++ファイルをコンパイルに含めないでください

#define INSTANCE ((::NSError*)_instance())

#define GET_ERRORDOMAIN(domainName) \
    ::NSString* p = domainName;   \
    [p retain];                     \
    return NSStringHelper::FromHandle(p);

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    NSString NSError::CocoaErrorDomain() noexcept
    {
        GET_ERRORDOMAIN(NSCocoaErrorDomain);
    }

    NSString NSError::PosixErrorDomain() noexcept
    {
        GET_ERRORDOMAIN(NSPOSIXErrorDomain);
    }

    NSError::NSError(NSString const& domain, ssize_t code) : NSObject(nullptr)
    {
        ::NSString* pDomain = (::NSString*)NSObjectHelper::GetPointer(domain);

        ArgumentNullException::CheckNull(pDomain, u"domain");

        _setInstance([::NSError errorWithDomain:pDomain code:code userInfo:nil]);
    }

    NSError::NSError(NSString const& domain, ssize_t code, std::nullptr_t) : NSError(domain, code)
    {
    }

    NSError::NSError(NSString const& domain, ssize_t code, Collections::DictionaryWrapper<NSString, NSObject> const& userInfo) : NSObject(nullptr)
    {
        ::NSString* pDomain = (::NSString*)NSObjectHelper::GetPointer(domain);

        ArgumentNullException::CheckNull(pDomain, u"domain");

        auto const& dictionary = userInfo.Dictionary();

        ::NSDictionary* pDictionary = (::NSDictionary*)NSObjectHelper::GetPointer(dictionary);

        _setInstance([::NSError errorWithDomain:pDomain code:code userInfo:pDictionary]);
    }

    ssize_t NSError::Code() const
    {
        return INSTANCE.code;
    }

    NSString NSError::Domain() const
    {
        ::NSString* str = INSTANCE.domain;
        [str retain];

        return NSStringHelper::FromHandle(str);
    }

    NSString NSError::LocalizedDescription() const
    {
        ::NSString* str = INSTANCE.localizedDescription;
        [str retain];

        return NSStringHelper::FromHandle(str);
    }

    Collections::ArrayWrapper<NSString> NSError::LocalizedRecoveryOptions() const
    {
        ::NSArray* pArr = INSTANCE.localizedRecoveryOptions;

        Collections::NSArray arr = nullptr;

        if (pArr != nil) {
            [pArr retain];
            NSObjectHelper::SetPointer(arr, pArr);
        }

        return Collections::ArrayWrapper<NSString>(std::move(arr));
    }

    Collections::DictionaryWrapper<NSString, NSObject> NSError::UserInfo() const
    {
        ::NSDictionary* dic = INSTANCE.userInfo;

        Collections::NSDictionary result = nullptr;

        if (dic != nil) {
            [dic retain];
            NSObjectHelper::SetPointer(result, dic);
        }

        return Collections::DictionaryWrapper<NSString, NSObject>(std::move(result));
    }
}

#undef INSTANCE
#undef GET_ERRORDOMAIN

