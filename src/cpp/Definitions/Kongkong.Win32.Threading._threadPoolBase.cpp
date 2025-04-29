//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    Threading::StackInfo _threadPoolBase::GetStackInfoUnsafe() const noexcept
    {
        Threading::StackInfo info;

        ::QueryThreadpoolStackInformation(_pool, &info);

        return info;
    }

    void _threadPoolBase::SetThreadMaximum(uint32_t value) const
    {
        NullPointerException::CheckNull(_pool, u"ThreadPool");
        ::SetThreadpoolThreadMaximum(_pool, value);
    }

    void _threadPoolBase::SetThreadMaximumUnsafe(uint32_t value) const noexcept
    {
        ::SetThreadpoolThreadMaximum(_pool, value);
    }

    void _threadPoolBase::SetThreadMinimum(uint32_t value) const
    {
        NullPointerException::CheckNull(_pool, u"ThreadPool");
        ::SetThreadpoolThreadMinimum(_pool, value);
    }

    void _threadPoolBase::SetThreadMinimumUnsafe(uint32_t value) const noexcept
    {
        ::SetThreadpoolThreadMinimum(_pool, value);
    }

    Threading::StackInfo _threadPoolBase::StackInfo() const
    {
        Threading::StackInfo info;

        if (::QueryThreadpoolStackInformation(_pool, &info) == 0) [[unlikely]] throw HResultException();

        return info;
    }
}
