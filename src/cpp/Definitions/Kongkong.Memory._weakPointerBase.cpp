//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Memory
{
    bool _weakPointerBase::IsExpired() const noexcept
    {
        return !GC::_gc.contains(_p);
    }

    ssize_t _weakPointerBase::ReferenceCount() const noexcept
    {
        return GC::_userCount(_p);
    }

    String _weakPointerBase::ToString() const
    {
        return String::ValueOf(_p);
    }

    void _weakPointerBase::_checkNull() const
    {
        NullPointerException::CheckNull(_p, u"KONGKONG_NAMESPACE::WeakPointer<T>");
    }
}
