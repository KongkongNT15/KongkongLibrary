//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    CallbackEnvironment::CallbackEnvironment() noexcept
    {
        ::TpInitializeCallbackEnviron(this);
    }

    void CallbackEnvironment::Pool(::std::nullptr_t) noexcept
    {
        ::SetThreadpoolCallbackPool(this, nullptr);
    }

    void CallbackEnvironment::Pool(::PTP_POOL pool) noexcept
    {
        ::SetThreadpoolCallbackPool(this, pool);
    }

    void CallbackEnvironment::Pool(ThreadPoolView const& pool) noexcept
    {
        ::SetThreadpoolCallbackPool(this, pool._pool);
    }

    void CallbackEnvironment::Pool(ThreadPool const& pool) noexcept
    {
        ::SetThreadpoolCallbackPool(this, pool._pool);
    }
}
