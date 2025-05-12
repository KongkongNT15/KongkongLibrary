#ifndef KONGKONG_COLLECTIONS_LINKELEMENT_H
#define KONGKONG_COLLECTIONS_LINKELEMENT_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    struct LinkElement final : public ValueType {
        LinkElement(LinkElement<T>* before, LinkElement<T>* next) requires std::default_initializable<T>
            : _before(before), _next(next), _value()
        {
        }

        LinkElement(LinkElement<T>* before, LinkElement<T>* next, T const& value)
            requires std::copy_constructible<T>
            : _value(value), _before(before), _next(next)
        {
        }

        LinkElement(LinkElement<T>* before, LinkElement<T>* next, T &&value)
            requires std::move_constructible<T>
            : _value(std::move(value)), _before(before), _next(next)
        {
        }

        constexpr void Before(LinkElement<T>* before) noexcept { _before = before; }
        [[nodiscard]] constexpr LinkElement<T>* Before() noexcept { return _before; }
        [[nodiscard]] constexpr const LinkElement<T>* Before() const noexcept { return _before; }

        constexpr void Next(LinkElement<T>* next) noexcept { _next = next; }
        [[nodiscard]] constexpr LinkElement<T>* Next() noexcept { return _next; }
        [[nodiscard]] constexpr const LinkElement<T>* Next() const noexcept { return _next; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき 
        [[nodiscard]]
        String ToString() const { return String::FromPointerUnsafe(u"Kongkong::Collections::LinkElement<T>", true); }

        void Value(T const& value) requires std::copyable<T>
        {
            _value = value;
        }

        void Value(T &&value) requires std::movable<T>
        {
            _value = std::move(value);
        }

        [[nodiscard]] constexpr T& Value() noexcept { return _value; }
        [[nodiscard]] constexpr T const& Value() const noexcept { return _value; }

    private:
        LinkElement<T>* _before;
        LinkElement<T>* _next;

        T _value;
    };
}

#endif //!KONGKONG_COLLECTIONS_LINKELEMENT_H
