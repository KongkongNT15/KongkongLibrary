//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text
{
    Threading::Mutex _stringPointerBase::_mutex;

    _stringPointerBase::_stringPointerBase(_stringPointerBase const& right) noexcept : __p(right.__p)
    {
        if (__p == nullptr) return;

        _mutex.Lock();

        __addCountUnsafe();

        _mutex.Unlock();
    }

    void _stringPointerBase::__destory() noexcept
    {
        if (__p == nullptr) return;

        Threading::ScopeLock lock(_mutex);

        __removeCountUnsafe();

        if (__getCountUnsafe() != 0) return;

        switch (__getTypeUnsafe()) {
            case StringType::Heap:
            case StringType::HeapMutable:

                ::free(__p);

                break;

            default: break;
        }
    }
}
