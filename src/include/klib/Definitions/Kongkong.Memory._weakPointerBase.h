#ifndef KONGKONG_MEMORY_WEAKPOINTERBASE_H
#define KONGKONG_MEMORY_WEAKPOINTERBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Memory
{
    struct _weakPointerBase {

        friend constexpr bool operator==(_weakPointerBase const& left, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator==(_weakPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator==(std::nullptr_t, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator!=(_weakPointerBase const& left, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator!=(_weakPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator!=(std::nullptr_t, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator<(_weakPointerBase const& left, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator<(_weakPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator<(std::nullptr_t, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator<=(_weakPointerBase const& left, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator<=(_weakPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator<=(std::nullptr_t, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator>(_weakPointerBase const& left, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator>(_weakPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator>(std::nullptr_t, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator>=(_weakPointerBase const& left, _weakPointerBase const& right) noexcept;
        friend constexpr bool operator>=(_weakPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator>=(std::nullptr_t, _weakPointerBase const& right) noexcept;
        friend constexpr std::strong_ordering operator<=>(_weakPointerBase const& left, _weakPointerBase const& right) noexcept;
        friend constexpr std::strong_ordering operator<=>(_weakPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr std::strong_ordering operator<=>(std::nullptr_t, _weakPointerBase const& right) noexcept;

        [[nodiscard]] constexpr bool operator!() const noexcept { return _p == nullptr; }
        [[nodiscard]] constexpr operator bool() const noexcept { return _p != nullptr; }

        /// @brief ポインターがリンク切れであるか
        [[nodiscard]]
        bool IsExpired() const noexcept;

        [[nodiscard]] constexpr bool IsNull() const noexcept { return _p == nullptr; }

        /// @brief オブジェクトの参照カウントを取得
        [[nodiscard]]
        ssize_t ReferenceCount() const noexcept;

        /// @brief nullptrに設定
        constexpr void Reset() noexcept { _p = nullptr; }

        /// @brief アドレスの文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        constexpr _weakPointerBase(void* p) noexcept : _p(p) {}
        constexpr _weakPointerBase(std::nullptr_t) noexcept : _p(nullptr) {}

        void _checkNull() const;

        void* _p;

        template <class T>
        friend struct WeakPointer;
    };

    [[nodiscard]] constexpr bool operator==(_weakPointerBase const& left, _weakPointerBase const& right) noexcept { return left._p == right._p; }
    [[nodiscard]] constexpr bool operator==(_weakPointerBase const& left, std::nullptr_t) noexcept { return left._p == nullptr; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, _weakPointerBase const& right) noexcept { return nullptr == right._p; }
    [[nodiscard]] constexpr bool operator!=(_weakPointerBase const& left, _weakPointerBase const& right) noexcept { return left._p != right._p; }
    [[nodiscard]] constexpr bool operator!=(_weakPointerBase const& left, std::nullptr_t) noexcept { return left._p != nullptr; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, _weakPointerBase const& right) noexcept { return nullptr != right._p; }
    [[nodiscard]] constexpr bool operator<(_weakPointerBase const& left, _weakPointerBase const& right) noexcept { return left._p < right._p; }
    [[nodiscard]] constexpr bool operator<(_weakPointerBase const& left, std::nullptr_t) noexcept { return false; }
    [[nodiscard]] constexpr bool operator<(std::nullptr_t, _weakPointerBase const& right) noexcept { return nullptr != right._p; }
    [[nodiscard]] constexpr bool operator<=(_weakPointerBase const& left, _weakPointerBase const& right) noexcept { return left._p <= right._p; }
    [[nodiscard]] constexpr bool operator<=(_weakPointerBase const& left, std::nullptr_t) noexcept { return left._p != nullptr; }
    [[nodiscard]] constexpr bool operator<=(std::nullptr_t, _weakPointerBase const& right) noexcept { return nullptr != right._p; }
    [[nodiscard]] constexpr bool operator>(_weakPointerBase const& left, _weakPointerBase const& right) noexcept { return left._p > right._p; }
    [[nodiscard]] constexpr bool operator>(_weakPointerBase const& left, std::nullptr_t) noexcept { return left._p != nullptr; }
    [[nodiscard]] constexpr bool operator>(std::nullptr_t, _weakPointerBase const& right) noexcept { return false; }
    [[nodiscard]] constexpr bool operator>=(_weakPointerBase const& left, _weakPointerBase const& right) noexcept { return left._p >= right._p; }
    [[nodiscard]] constexpr bool operator>=(_weakPointerBase const& left, std::nullptr_t) noexcept { return left._p != nullptr; }
    [[nodiscard]] constexpr bool operator>=(std::nullptr_t, _weakPointerBase const& right) noexcept { return nullptr != right._p; }
    [[nodiscard]] constexpr std::strong_ordering operator<=>(_weakPointerBase const& left, _weakPointerBase const& right) noexcept { return left._p <=> right._p; }
    [[nodiscard]] constexpr std::strong_ordering operator<=>(_weakPointerBase const& left, std::nullptr_t) noexcept { return left._p <=> (void*)nullptr; }
    [[nodiscard]] constexpr std::strong_ordering operator<=>(std::nullptr_t, _weakPointerBase const& right) noexcept { return (void*)nullptr <=> right._p; }
}

#endif //!KONGKONG_MEMORY_WEAKPOINTERBASE_H
