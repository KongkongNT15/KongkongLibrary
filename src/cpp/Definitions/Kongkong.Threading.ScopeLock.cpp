//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{
    ScopeLock::ScopeLock(Mutex& mutex) : _mutex(mutex)
    {
        mutex.Lock();
    }

    ScopeLock::~ScopeLock()
    {
        _mutex.Unlock();
    }

    String ScopeLock::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Threading::ScopeLock");
    }
}
