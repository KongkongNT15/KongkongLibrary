//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Memory
{
    String _sharedHandleBase::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Memory::SharedHandle<T>");
    }

    _sharedHandleBase::_sharedHandleBase(void* handle, void(*destory)(void*)) : _ptr(nullptr)
    {
        _ptr._p = handle;
        Threading::ScopeLock lock(GC::_mutex);
        GC::_gc.emplace(handle, destory);
    }
}
