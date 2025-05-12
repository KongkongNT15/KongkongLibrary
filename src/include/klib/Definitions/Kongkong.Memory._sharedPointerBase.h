#ifndef KONGKONG_MEMORY_SHAREDPOINTERBASE_H
#define KONGKONG_MEMORY_SHAREDPOINTERBASE_H

#include "Base.h"
#include "Kongkong.GC.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Threading.ScopeLock.h"

namespace KONGKONG_NAMESPACE::Memory
{
    struct _sharedPointerBase {

        friend constexpr bool operator==(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator==(_sharedPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator==(std::nullptr_t, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator!=(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator!=(_sharedPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator!=(std::nullptr_t, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator<(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator<(_sharedPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator<(std::nullptr_t, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator<=(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator<=(_sharedPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator<=(std::nullptr_t, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator>(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator>(_sharedPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator>(std::nullptr_t, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator>=(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept;
        friend constexpr bool operator>=(_sharedPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr bool operator>=(std::nullptr_t, _sharedPointerBase const& right) noexcept;
        friend constexpr std::strong_ordering operator<=>(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept;
        friend constexpr std::strong_ordering operator<=>(_sharedPointerBase const& left, std::nullptr_t) noexcept;
        friend constexpr std::strong_ordering operator<=>(std::nullptr_t, _sharedPointerBase const& right) noexcept;

        [[nodiscard]] constexpr bool operator!() const noexcept { return _ptr._p == nullptr; }
        [[nodiscard]] constexpr operator bool() const noexcept { return _ptr._p != nullptr; }

        [[nodiscard]] constexpr bool IsNull() const noexcept { return _ptr._p == nullptr; }

        /// @brief オブジェクトの参照カウントを取得
        [[nodiscard]]
        ssize_t ReferenceCount() const noexcept;

        /// @brief オブジェクトを解放
        /// @attention nulltprの場合は何もしないよ！
        void Release() noexcept;

        /// @brief アドレスの文字列表現を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _sharedPointerBase() = default;

        void _checkNull() const;

        template <class Ty>
        void _setInstance(Ty* ptr)
        {
            MemoryAllocationException::CheckNull(ptr);
            _setInstanceUnsafe(ptr);
        }

        template <class Ty>
        void _setInstanceUnsafe(Ty* ptr)
        {
            _ptr._p = ptr;

            Threading::ScopeLock lock(GC::_mutex);
            GC::_gc.emplace((void*)ptr, GC::__objectCounter(GC::_deleteP<Ty>));
        }

        template <class Ty>
        void _setInstanceUnsafe(Ty* pReal, void* p)
        {
            Threading::ScopeLock lock(GC::_mutex);
            GC::_gc.emplace((void*)pReal, GC::__objectCounter(GC::_deleteP<Ty>));

            new (&_ptr) GC::__objectPtr(p, pReal);
        }

        GC::__objectPtr _ptr;

        template <class T>
        friend struct SharedPointer;
    };

    [[nodiscard]] constexpr bool operator==(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept { return left._ptr._p == right._ptr._p; }
    [[nodiscard]] constexpr bool operator==(_sharedPointerBase const& left, std::nullptr_t) noexcept { return left._ptr._p == nullptr; }
    [[nodiscard]] constexpr bool operator==(std::nullptr_t, _sharedPointerBase const& right) noexcept { return nullptr == right._ptr._p; }
    [[nodiscard]] constexpr bool operator!=(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept { return left._ptr._p != right._ptr._p; }
    [[nodiscard]] constexpr bool operator!=(_sharedPointerBase const& left, std::nullptr_t) noexcept { return left._ptr._p != nullptr; }
    [[nodiscard]] constexpr bool operator!=(std::nullptr_t, _sharedPointerBase const& right) noexcept { return nullptr != right._ptr._p; }
    [[nodiscard]] constexpr bool operator<(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept { return left._ptr._p < right._ptr._p; }
    [[nodiscard]] constexpr bool operator<(_sharedPointerBase const& left, std::nullptr_t) noexcept { return false; }
    [[nodiscard]] constexpr bool operator<(std::nullptr_t, _sharedPointerBase const& right) noexcept { return nullptr != right._ptr._p; }
    [[nodiscard]] constexpr bool operator<=(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept { return left._ptr._p <= right._ptr._p; }
    [[nodiscard]] constexpr bool operator<=(_sharedPointerBase const& left, std::nullptr_t) noexcept { return left._ptr._p != nullptr; }
    [[nodiscard]] constexpr bool operator<=(std::nullptr_t, _sharedPointerBase const& right) noexcept { return nullptr != right._ptr._p; }
    [[nodiscard]] constexpr bool operator>(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept { return left._ptr._p > right._ptr._p; }
    [[nodiscard]] constexpr bool operator>(_sharedPointerBase const& left, std::nullptr_t) noexcept { return left._ptr._p != nullptr; }
    [[nodiscard]] constexpr bool operator>(std::nullptr_t, _sharedPointerBase const& right) noexcept { return false; }
    [[nodiscard]] constexpr bool operator>=(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept { return left._ptr._p >= right._ptr._p; }
    [[nodiscard]] constexpr bool operator>=(_sharedPointerBase const& left, std::nullptr_t) noexcept { return left._ptr._p != nullptr; }
    [[nodiscard]] constexpr bool operator>=(std::nullptr_t, _sharedPointerBase const& right) noexcept { return nullptr != right._ptr._p; }
    [[nodiscard]] constexpr std::strong_ordering operator<=>(_sharedPointerBase const& left, _sharedPointerBase const& right) noexcept { return left._ptr._p <=> right._ptr._p; }
    [[nodiscard]] constexpr std::strong_ordering operator<=>(_sharedPointerBase const& left, std::nullptr_t) noexcept { return left._ptr._p <=> (void*)nullptr; }
    [[nodiscard]] constexpr std::strong_ordering operator<=>(std::nullptr_t, _sharedPointerBase const& right) noexcept { return (void*)nullptr <=> right._ptr._p; }
}

#endif //!KONGKONG_MEMORY_SHAREDPOINTERBASE_H
