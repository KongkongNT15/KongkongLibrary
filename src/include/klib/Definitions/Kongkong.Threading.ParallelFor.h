#ifndef KONGKONG_THREADING_PARALLELFOR_H
#define KONGKONG_THREADING_PARALLELFOR_H

#include "Base.h"
#include <functional>

namespace KONGKONG_NAMESPACE::Threading
{
    class ParallelFor final {
        public:

        STATIC_CLASS(ParallelFor)

        static AsyncAction RunAsync(ssize_t begin, ssize_t end, void(*f)(ssize_t));
        static AsyncAction RunAsync(ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f);
        static AsyncAction RunAsync(ssize_t begin, ssize_t end, ::std::function<void(ssize_t)>&& f);
        static AsyncAction RunAsync(uint32_t threadCount, ssize_t begin, ssize_t end, void(*f)(ssize_t));
        static AsyncAction RunAsync(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f);
        static AsyncAction RunAsync(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)>&& f);
        
        static AsyncAction RunAsyncSafe(uint32_t threadCount, ssize_t begin, ssize_t end, void(*f)(ssize_t));
        static AsyncAction RunAsyncSafe(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)> const& f);
        static AsyncAction RunAsyncSafe(uint32_t threadCount, ssize_t begin, ssize_t end, ::std::function<void(ssize_t)>&& f);

        private:
        template <class TFunc>
        static AsyncAction _runAsync(uint32_t threadCount, ssize_t begin, ssize_t end, TFunc f);

        static void _checkThreadCount(ssize_t threadCount);
    };
}

#endif //!KONGKONG_THREADING_PARALLELFOR_H