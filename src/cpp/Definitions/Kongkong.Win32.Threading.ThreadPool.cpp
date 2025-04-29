//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    ThreadPool::ThreadPool() : _threadPoolBase(::CreateThreadpool(nullptr))
    {
        if (_pool == nullptr) [[unlikely]] throw HResultException();
    }

    ThreadPool::~ThreadPool()
    {
        if (_pool != nullptr) ::CloseThreadpool(_pool);
    }

    ThreadPool& ThreadPool::operator=(ThreadPool&& right) noexcept
    {
        ThreadPool::~ThreadPool();

        _pool = right._pool;
        right._pool = nullptr;

        return *this;
    }

    ThreadPool& ThreadPool::operator=(std::nullptr_t) noexcept
    {
        ThreadPool::~ThreadPool();

        _pool = nullptr;

        return *this;
    }

    String ThreadPool::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Win32::Threading::ThreadPool");
    }
}
