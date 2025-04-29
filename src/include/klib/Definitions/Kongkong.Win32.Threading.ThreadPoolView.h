#ifndef KONGKONG_WIN32_THREADPOOLVIEW_H
#define KONGKONG_WIN32_THREADPOOLVIEW_H

#include "Base.h"
#include "Kongkong.HandleType.h"
#include "Kongkong.Win32.Threading._threadPoolBase.h"
#include "Kongkong.Win32.Threading.ThreadPool.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class KONGKONG_INCOMPLETED_CLASS ThreadPoolView final : public HandleType, public _threadPoolBase {
        public:

        constexpr ThreadPoolView(::PTP_POOL pool) noexcept : _threadPoolBase(pool) {}
        constexpr ThreadPoolView(ThreadPool const& pool) noexcept : _threadPoolBase(pool._pool) {}
        ThreadPoolView(ThreadPool&&) = delete;

        /// @brief nullptrとして作成
        constexpr ThreadPoolView(::std::nullptr_t) noexcept : _threadPoolBase(nullptr) {}

        constexpr ThreadPoolView& operator=(::PTP_POOL pool) noexcept { _pool = pool; return *this; }
        constexpr ThreadPoolView& operator=(ThreadPool const& pool) noexcept { _pool = pool._pool; return *this; }
        constexpr ThreadPoolView& operator=(::std::nullptr_t) noexcept { _pool = nullptr; return *this; }
        ThreadPoolView& operator=(ThreadPool&&) = delete;

        [[nodiscard]]
        String ToString() const;
    };
}

#endif //!KONGKONG_WIN32_THREADPOOLVIEW_H
