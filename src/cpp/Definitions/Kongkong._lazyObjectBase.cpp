//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    void _lazyObjectBase::_checkIntialized() const
    {
        if (!_isInitialized) [[unlikely]] throw InvalidOperationException(u"LasyObject<T>は初期化されていません");
    }

    void _lazyObjectBase::_checkNotIntialized() const
    {
        if (_isInitialized) [[unlikely]] throw InvalidOperationException(u"LasyObject<T>はすでに値を持っています");
    }

    String _lazyObjectBase::_toStringDefault() const
    {
        return String::FromLiteral(u"初期化されたLasyObject<T>");
    }

    String _lazyObjectBase::_toStringNotInitialized() const
    {
        return String::FromLiteral(u"初期化されていないLasyObject<T>");
    }
}
