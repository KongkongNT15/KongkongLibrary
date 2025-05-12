#ifndef KONGKONG_WIN32_THREADPOOL_H
#define KONGKONG_WIN32_THREADPOOL_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.Win32.Threading._threadPoolBase.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class KONGKONG_INCOMPLETED_CLASS ThreadPool final : public HandleType, public _threadPoolBase {
        public:

        ThreadPool();
        ThreadPool(ThreadPool const&) = delete;
        constexpr ThreadPool(ThreadPool&& right) noexcept : _threadPoolBase(right._pool) { right._pool = nullptr; }

        /// @brief nullptrとして作成
        constexpr ThreadPool(std::nullptr_t) noexcept : _threadPoolBase(nullptr) {}

        ~ThreadPool();

        ThreadPool& operator=(ThreadPool const&) = delete;
        ThreadPool& operator=(ThreadPool&& right) noexcept;

        ThreadPool& operator=(std::nullptr_t) noexcept;

        [[nodiscard]]
        String ToString() const;
    };
}

#endif //!KONGKONG_WIN32_THREADPOOL_H
