#ifndef KONGKONG_WIN32_THREADPOOLBASE_H
#define KONGKONG_WIN32_THREADPOOLBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Win32::Threading
{
    class _threadPoolBase {
        public:

        [[nodiscard]]
        constexpr operator bool() const noexcept { return _pool != nullptr; }

        [[nodiscard]]
        constexpr bool operator!() const noexcept { return _pool == nullptr; }

        [[nodiscard]]
        Threading::StackInfo GetStackInfoUnsafe() const noexcept;

        /// @brief 最大スレッド数を設定
        /// @param value 最大スレッド数
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void SetThreadMaximum(uint32_t value) const;

        /// @brief 最大スレッド数を設定
        /// @attention thisがnullptrのときにこの関数を呼ぶとプロセスがクラッシュするよ！
        /// @param value 最大スレッド数
        void SetThreadMaximumUnsafe(uint32_t value) const noexcept;

        /// @brief 最小スレッド数を設定
        /// @param value 最小スレッド数
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void SetThreadMinimum(uint32_t value) const;

        /// @brief 最小スレッド数を設定
        /// @attention thisがnullptrのときにこの関数を呼ぶとプロセスがクラッシュするよ！
        /// @param value 最小スレッド数
        void SetThreadMinimumUnsafe(uint32_t value) const noexcept;

        [[nodiscard]]
        Threading::StackInfo StackInfo() const;

        private:

        ::PTP_POOL _pool;

        _threadPoolBase() = default;
        _threadPoolBase(_threadPoolBase const&) = default;
        _threadPoolBase(_threadPoolBase&&) = default;

        constexpr _threadPoolBase(::PTP_POOL pool) noexcept : _pool(pool) {}
        constexpr _threadPoolBase(::std::nullptr_t) noexcept : _pool(nullptr) {}

        _threadPoolBase& operator=(_threadPoolBase const&) = default;
        _threadPoolBase& operator=(_threadPoolBase&&) = default;

        friend ThreadPool;
        friend ThreadPoolView;
        friend CallbackEnvironment;
        friend constexpr bool operator==(_threadPoolBase const&, _threadPoolBase const&) noexcept;
        friend constexpr bool operator==(_threadPoolBase const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator==(::std::nullptr_t, _threadPoolBase const&) noexcept;
        friend constexpr bool operator!=(_threadPoolBase const&, _threadPoolBase const&) noexcept;
        friend constexpr bool operator!=(_threadPoolBase const&, ::std::nullptr_t) noexcept;
        friend constexpr bool operator!=(::std::nullptr_t, _threadPoolBase const&) noexcept;
    };

    [[nodiscard]] constexpr bool operator==(_threadPoolBase const& left, _threadPoolBase const& right) noexcept { return left._pool == right._pool; }
    [[nodiscard]] constexpr bool operator==(_threadPoolBase const& left, ::std::nullptr_t) noexcept { return left._pool == nullptr; }
    [[nodiscard]] constexpr bool operator==(::std::nullptr_t, _threadPoolBase const& right) noexcept { return nullptr == right._pool; }
    [[nodiscard]] constexpr bool operator!=(_threadPoolBase const& left, _threadPoolBase const& right) noexcept { return left._pool != right._pool; }
    [[nodiscard]] constexpr bool operator!=(_threadPoolBase const& left, ::std::nullptr_t) noexcept { return left._pool != nullptr; }
    [[nodiscard]] constexpr bool operator!=(::std::nullptr_t, _threadPoolBase const& right) noexcept { return nullptr != right._pool; }
}

#endif //!KONGKONG_WIN32_THREADPOOLBASE_H
