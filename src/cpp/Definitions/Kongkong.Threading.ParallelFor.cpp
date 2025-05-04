//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Threading
{
    AsyncAction ParallelFor::RunAsync(ssize_t begin, ssize_t end, void(*f)(ssize_t))
    {
        return RunAsync(::std::thread::hardware_concurrency(), begin, end, f);
    }

    AsyncAction ParallelFor::RunAsync(ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f)
    {
        return RunAsync(::std::thread::hardware_concurrency(), begin, end, f);
    }

    AsyncAction ParallelFor::RunAsync(ssize_t begin, ssize_t end, ::std::function<void(ssize_t)>&& f)
    {
        return RunAsync(::std::thread::hardware_concurrency(), begin, end, ::std::move(f));
    }

    AsyncAction ParallelFor::RunAsync(uint32_t threadCount, ssize_t begin, ssize_t end, void(*f)(ssize_t))
    {
        return _runAsync<void(*)(ssize_t)>(threadCount, begin, end, f);
    }

    AsyncAction ParallelFor::RunAsync(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f)
    {
        return _runAsync<::std::function<void(ssize_t)> const&>(threadCount, begin, end, f);
    }

    AsyncAction ParallelFor::RunAsync(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)>&& f)
    {
        ::std::function<void(ssize_t)> func = ::std::move(f);

        co_await RunAsync(threadCount, begin, end, func);
    }

    AsyncAction ParallelFor::RunAsyncSafe(uint32_t threadCount, ssize_t begin, ssize_t end, void(*f)(ssize_t))
    {
        _checkThreadCount(threadCount);
        return RunAsync(threadCount, begin, end, f);
    }

    AsyncAction ParallelFor::RunAsyncSafe(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f)
    {
        _checkThreadCount(threadCount);
        return RunAsync(threadCount, begin, end, f);
    }

    AsyncAction ParallelFor::RunAsyncSafe(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)>&& f)
    {
        _checkThreadCount(threadCount);
        return RunAsync(threadCount, begin, end, ::std::move(f));
    }

    template <class TFunc>
    AsyncAction ParallelFor::_runAsync(uint32_t threadCount, ssize_t begin, ssize_t end, TFunc f)
    {
        struct fArgs {
            ssize_t b;
            ssize_t e;
            TFunc f;
        };

        void(*func)(fArgs&) = [](fArgs& args) {
            while (args.b != args.e) {
                args.f(args.b);
                ++args.b;
            }
        };

        ssize_t count = end - begin;

        if (count <= 0) [[unlikely]] co_return;

        ssize_t listCapacity;

        if ((ssize_t)threadCount > count) listCapacity = count;
        else listCapacity = threadCount;

        Collections::Turbo::FastArrayList<AsyncAction> list = Collections::Turbo::FastArrayList<AsyncAction>::CreateWithCapacityUnsafe(listCapacity);

        ssize_t c = count % listCapacity;
        ssize_t d = count / listCapacity;

        if (c == 0) {
            for (ssize_t i = begin; i != end;) {
                list += ThreadPool::RunAsync(func, fArgs{ i, i += d, f });
            }
        }
        else {
            ssize_t n = d * (listCapacity * (d + 1) - count);
            ssize_t i = 0;

            while (i != n) {
                list += ThreadPool::RunAsync(func, fArgs{ i, i += d, f });
            }

            d++;

            while (i != count) {
                list += ThreadPool::RunAsync(func, fArgs{ i, i += d, f });
            }
        }

        for (AsyncAction& a : list) co_await a;

        co_return;
    }

    void ParallelFor::_checkThreadCount(ssize_t threadCount)
    {
        if (threadCount < 0) [[unlikely]] throw InvalidArgumentException(u"スレッド数にゼロ以下が指定されました");
        if (threadCount > 32767) [[unlikely]] throw ArgumentOutOfRangeException(u"スレッド数が多すぎます");
    }
}