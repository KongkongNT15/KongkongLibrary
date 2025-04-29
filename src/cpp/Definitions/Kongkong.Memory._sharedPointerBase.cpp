//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Memory
{
    ssize_t _sharedPointerBase::ReferenceCount() const noexcept
    {
        return GC::_userCount(_ptr._p);
    }

    void _sharedPointerBase::Release() noexcept
    {
        _ptr.__erase();
        _ptr._p = nullptr;
    }

    String _sharedPointerBase::ToString() const
    {
        return String::ValueOf(_ptr._p);
    }

    void _sharedPointerBase::_checkNull() const
    {
        NullPointerException::CheckNull(_ptr._p, u"KONGKONG_NAMESPACE::SharedPointer<T>");
    }
}
