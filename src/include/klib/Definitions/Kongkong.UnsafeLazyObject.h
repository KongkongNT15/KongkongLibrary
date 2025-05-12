#ifndef KONGKONG_UNSAFELAZYOBJECT_H
#define KONGKONG_UNSAFELAZYOBJECT_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong._unsafeLazyObjectBase.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 値を保持しているかを確認しない遅延初期化オブジェクト
    /// @attention デストラクタで値を破棄しないから初期化した場合はユーザーが明示的にResetUnsafe()を呼ぶ必要があるよ！
    /// @tparam T 型
    template <class T>
    struct UnsafeLazyObject : public ValueType, public _unsafeLazyObjectBase {

        UnsafeLazyObject() = default;
        UnsafeLazyObject(UnsafeLazyObject const&) = delete;

        UnsafeLazyObject& operator=(UnsafeLazyObject const&) = delete;

        [[nodiscard]] constexpr T* GetPointerUnsafe() noexcept { return (T*)((void*)_placeHolder); }
        [[nodiscard]] constexpr const T* GetPointerUnsafe() const noexcept { return (const T*)((const void*)_placeHolder); }

        [[nodiscard]] constexpr T& GetValueUnsafe() noexcept { return *(T*)((void*)_placeHolder); }
        [[nodiscard]] constexpr T const& GetValueUnsafe() const noexcept { return *(const T*)((const void*)_placeHolder); }

        /// @brief 値を構築
        /// @tparam ...Args 引数テンプレート
        /// @param ...args コンストラクタ引数
        template <class... Args>
        void EmplaceUnsafe(Args&&... args) noexcept(noexcept(T(::std::forward<Args>(args)...)))
        {
            new (GetPointerUnsafe()) T(::std::forward<Args>(args)...);
        }

        /// @brief 値を破棄
        void ResetUnsafe() noexcept
        {
            GetPointerUnsafe()->~T();
        }

        private:
        uint8_t _placeHolder[sizeof(T)];
    };

    template <class T>
    [[nodiscard]] constexpr bool operator==(UnsafeLazyObject<T> const& left, UnsafeLazyObject<T> const& right) noexcept { return &left == &right; }

    template <class T>
    [[nodiscard]] constexpr bool operator!=(UnsafeLazyObject<T> const& left, UnsafeLazyObject<T> const& right) noexcept { return &left != &right; }

    template <class T>
    [[nodiscard]] constexpr bool operator<(UnsafeLazyObject<T> const& left, UnsafeLazyObject<T> const& right) noexcept { return &left < &right; }

    template <class T>
    [[nodiscard]] constexpr bool operator<=(UnsafeLazyObject<T> const& left, UnsafeLazyObject<T> const& right) noexcept { return &left <= &right; }

    template <class T>
    [[nodiscard]] constexpr bool operator>(UnsafeLazyObject<T> const& left, UnsafeLazyObject<T> const& right) noexcept { return &left > &right; }

    template <class T>
    [[nodiscard]] constexpr bool operator>=(UnsafeLazyObject<T> const& left, UnsafeLazyObject<T> const& right) noexcept { return &left >= &right; }

    template <class T>
    [[nodiscard]] constexpr ::std::strong_ordering operator<=>(UnsafeLazyObject<T> const& left, UnsafeLazyObject<T> const& right) noexcept { return &left <=> &right; }
}

#endif //!KONGKONG_UNSAFELAZYOBJECT_H
