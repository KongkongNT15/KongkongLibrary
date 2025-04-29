#ifndef KONGKONG_COLLECTIONS_STACK_H
#define KONGKONG_COLLECTIONS_STACK_H

#include "Base.h"

#include "Kongkong.InvalidOperationException.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Object.h"

#include "Kongkong.Collections.StackElement.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    struct Stack final : public Kongkong::IMPLEMENTATION::Object {

        constexpr Stack() noexcept : _top(nullptr), _count(0) {}

        Stack(std::initializer_list<T> const& list)
            requires std::copy_constructible<T>
            : Stack<T>()
        {
            for (T const& child : list) {
                Push(child);
            }
        }

        Stack(Stack const& right) requires std::copy_constructible<T> :
            _top(nullptr),
            _count(right._count)
        {
            StackElement<T>* e = right._top;
            StackElement<T>* tmp;

            //rightの要素数がゼロならnullのまま
            while (e != nullptr) {
                tmp = e->Next();

                Push(e->Value());

                e = tmp;
            }
        }

        Stack(Stack&& right) noexcept :
            _top(right._top),
            _count(right._count)
        {
            right._top = nullptr;
            right._count = 0;
        }

        ~Stack()
        {
            Clear();
        }

        Stack& operator=(Stack const& right)
        {
            Clear();

            StackElement<T>* e = right._top;
            StackElement<T>* tmp;

            //rightの要素数がゼロならnullのまま
            while (e != nullptr) {
                tmp = e->Next();

                Push(e->Value());

                e = tmp;
            }

            return *this;
        }

        Stack& operator=(Stack&& right)
        {
            Clear();

            _top = right._top;
            _count = right._count;

            right._top = nullptr;
            right._count = 0;

            return *this;
        }

        void Clear()
        {
            StackElement<T>* e = _top;
            StackElement<T>* tmp;

            while (e != nullptr) {
                tmp = e->Next();

                delete e;

                e = tmp;
            }

            _top = nullptr;
            _count = 0;
        }

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _count; }

        void Pop()
        {
            if (_count == 0) [[unlikely]] throw InvalidOperationException(u"要素数がゼロです");

            StackElement<T>* next = _top->Next();
            delete _top;
            _top = next;
            --_count;
        }

        void Push() requires std::default_initializable<T>
        {
            _top = new StackElement<T>(_top);
            _count++;
        }

        void Push(T const& value) requires std::copyable<T>
        {
            _top = new StackElement<T>(value, _top);
            _count++;
        }

        void Push(T&& value) requires std::movable<T>
        {
            auto tmp = NEW StackElement<T>(std::move(value), _top);

            MemoryAllocationException::CheckNull(tmp);

            _top = tmp;
            _count++;
        }

        [[nodiscard]]
        T& Top()
        {
            if (_count == 0) [[unlikely]] throw InvalidOperationException(u"要素数がゼロです");
            return _top->Value();
        }

        [[nodiscard]]
        bool TryGetTop(T& result) const requires std::copyable<T>
        {
            if (_count == 0) return false;

            result = _top->Value();
            return true;
        }

        [[nodiscard]]
        bool TryPop() noexcept
        {
            if (_count == 0) return false;

            StackElement<T>* next = _top->Next();
            delete _top;
            _top = next;
            --_count;

            return true;
        }

        /// @brief 型名を取得
        [[nodiscard]]
        String ToString() const override { return String::FromLiteral(u"Kongkong::Collections::Stack<T>"); }

        private:

        StackElement<T> *_top;
        ssize_t _count;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    class Stack final : public Object {
        public:
        using ImplType = IMPLEMENTATION::Stack<T>;

        Stack() : Object(nullptr) { Object::_setInstance(NEW ImplType()); }
        Stack(std::initializer_list<T> const& list)
            requires std::copy_constructible<T>
            : Object(nullptr)
        {
            Object::_setInstance(NEW ImplType(list));
        }
        constexpr Stack(std::nullptr_t) noexcept : Object(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        Stack<T> const& operator+=(T const& value) const requires std::copyable<T>
        {
            Push(value);
            return *this;
        }

        Stack<T> const& operator+=(T&& value) const requires std::movable<T>
        {
            Push(std::move(value));
            return *this;
        }
    };
}

#endif //!KONGKONG_COLLECTIONS_STACK_H
