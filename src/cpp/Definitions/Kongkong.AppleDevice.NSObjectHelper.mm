//このObjective-C++ファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::AppleDevice
{
    void NSObjectHelper::Throw(::NSException* e, bool throwInvalidOperationException)
    {
        Foundation::NSString reason = Foundation::NSStringHelper::FromHandle(e.reason);

        if ([e.name isEqualToString: ::NSInvalidArgumentException]) {
            if (throwInvalidOperationException) throw InvalidOperationException(reason.ToString());
            else throw InvalidArgumentException(reason.ToString());
        }
        
        throw NotImplementedException(u"ふぁ！？っく");
    }
}
