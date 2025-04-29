#ifndef KONGKONG_COLLECTIONS_STACKELEMENT_H
#define KONGKONG_COLLECTIONS_STACKELEMENT_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    struct StackElement final : public ValueType {

        template <class... Args>
        StackElement(StackElement<T>* next, Args&&... args)
            : _value(std::forward(args)...), _next(next)
        {
        }

        constexpr StackElement<T>* Next() noexcept { return _next; }
        constexpr const StackElement<T>* Next() const noexcept { return _next; }
        constexpr void Next(StackElement<T>* value) noexcept { _next = value; }

        constexpr T& Value() noexcept { return _value; }
        constexpr T const& Value() const noexcept { return _value; }
        
        void Value(T const& value) requires std::copyable<T>
        {
            _value = value;
        }

        void Value(T&& value) requires std::movable<T>
        {
            _value = std::move(value);
        }

    private:
        StackElement<T>* _next;
        T _value;
    };
}

#endif //!KONGKONG_COLLECTIONS_STACKELEMENT_H
