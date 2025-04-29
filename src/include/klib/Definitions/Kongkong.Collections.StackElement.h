#ifndef KONGKONG_COLLECTIONS_STACKELEMENT_H
#define KONGKONG_COLLECTIONS_STACKELEMENT_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections._stackElementMethods.h"

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    struct StackElement : public ValueType, public _stackElementMethods {

        template <class... Args>
        explicit StackElement(StackElement<T>* next, Args&&... args) noexcept(noexcept(T(::std::forward<Args>(args)...)))
            : _next(next), _value(std::forward(args)...)
        {
        }

        [[nodiscard]] constexpr StackElement<T>* Next() noexcept { return _next; }
        [[nodiscard]] constexpr const StackElement<T>* Next() const noexcept { return _next; }
        constexpr void Next(StackElement<T>* value) noexcept { _next = value; }

        [[nodiscard]] constexpr T& Value() noexcept { return _value; }
        [[nodiscard]] constexpr T const& Value() const noexcept { return _value; }
        
        void Value(T const& value) noexcept(::std::is_nothrow_copy_assignable_v<T>) requires std::copyable<T>
        {
            _value = value;
        }

        void Value(T&& value) noexcept(::std::is_nothrow_move_assignable_v<T>) requires std::movable<T>
        {
            _value = std::move(value);
        }

    private:
        StackElement<T>* _next;
        T _value;
    };
}

#endif //!KONGKONG_COLLECTIONS_STACKELEMENT_H
