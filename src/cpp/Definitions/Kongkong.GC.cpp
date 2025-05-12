//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    std::map<void*, GC::__objectCounter> GC::_gc;
    Threading::Mutex GC::_mutex;

    ssize_t GC::HandleCount() noexcept
    {
        Threading::ScopeLock lock(_mutex);

        ssize_t count = 0;

        for (auto const& pair : _gc) {
            count += pair.second._count;
        }

        return count;
    }

    ssize_t GC::ObjectCount() noexcept
    {
        Threading::ScopeLock lock(_mutex);

        ssize_t count = 0;

        for (auto const& pair : _gc) {
            if (!pair.second.__isNotReal) [[likely]] count++;
        }

        return count;
    }

    ssize_t GC::_userCount(void* p) noexcept
    {
        Threading::ScopeLock lock(_mutex);

        if (p == nullptr) return 0;

        if (!_gc.contains(p)) return 0;

        auto& counter = _gc[p];

        if (counter.__isNotReal) {
            auto& honmono = _gc[counter.__realPointer];

            return (ssize_t)honmono._count;
        }

        return (ssize_t)counter._count;
    }

    GC::__objectPtr::__objectPtr(ImplType* p) noexcept : _p(p)
    {
        Threading::ScopeLock lock(_mutex);

        ++_gc[p];
    }

    GC::__objectPtr::__objectPtr(ImplType* p, ImplType* pReal) : _p(p)
    {
        Threading::ScopeLock lock(_mutex);

        ++_gc[pReal];

        auto pair = _gc.try_emplace(p, pReal);

        if (!pair.second) {
            ++_gc[p];
        }

    }

    GC::__objectPtr::__objectPtr(GC::__objectPtr const& right) noexcept : _p(right._p)
    {
        if (_p != nullptr) {
            Threading::ScopeLock lock(_mutex);

            ++_gc[_p];
        }
    }

    GC::__objectPtr& GC::__objectPtr::operator=(GC::__objectPtr const& right)
    {
        __erase();
        _p = right._p;

        Threading::ScopeLock lock(_mutex);

        if (_p != nullptr) {
            auto& oc = _gc[_p];
            ++oc;
            //オブジェクトがインターフェースでポインタの位置がずれているとき
            if (oc.__isNotReal) {
                ++_gc[oc.__realPointer];
            }
        }
        return *this;
    }

    GC::__objectPtr& GC::__objectPtr::operator=(GC::__objectPtr&& right) noexcept
    {
        __erase();
        _p = right._p;
        right._p = nullptr;
        return *this;
    }

    void GC::__objectPtr::__erase()
    {
        if (_p == nullptr) return;
        
        _mutex.Lock();

        auto& oc = _gc[_p];

        _mutex.Unlock();
        
        oc.__erase(_p);
    }

    void GC::__objectCounter::__erase(void* p)
    {
        operator--();

        Threading::ScopeLock lock(_mutex);

        if (__isNotReal) {
            auto& oc = _gc[__realPointer];
            oc.__erase(__realPointer);
            if (__hasNoReference()) _gc.erase(p);
        }
        else {
            if (__hasNoReference()) {
                operator()(p);
                _gc.erase(p);
            }
        }
    }
    
}
