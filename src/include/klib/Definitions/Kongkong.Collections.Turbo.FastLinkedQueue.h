#ifndef KONGKONG_COLLECTIONS_TURBO_FASTLINKEDQUEUE_H
#define KONGKONG_COLLECTIONS_TURBO_FASTLINKEDQUEUE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.Collections.StackElement.h"
#include "Kongkong.Collections.Turbo._fastCollection.h"
#include "Kongkong.Collections.Turbo._fastLinkedQueueMethods.h"
#include "Kongkong.MemoryAllocationException.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastLinkedQueue final : public ValueType, public _fastCollection, public _fastLinkedQueueMethods {

        constexpr FastLinkedQueue() : _fastCollection(0), _current(nullptr), _last(nullptr) {}

        FastLinkedQueue(FastLinkedQueue const& right) : FastLinkedQueue()
        {
            try {
                _copyFrom(right);
            }
            catch (...) {
                FastLinkedQueue::~FastLinkedQueue();

                ::std::rethrow_exception(::std::current_exception());
            }
            
        }

        constexpr FastLinkedQueue(FastLinkedQueue&& right) noexcept : _fastCollection(right), _current(right._current), _last(right._last)
        {
            right._current = nullptr;
        }

        ~FastLinkedQueue()
        {
            if (_current == nullptr) return;

            StackElement<T>* e = _current;
            StackElement<T>* tmp;

            while (e != nullptr) {
                tmp = e->Next();

                delete e;

                e = tmp;
            }
        }

        FastLinkedQueue& operator=(FastLinkedQueue const& right)
        {
            FastLinkedQueue::~FastLinkedQueue();

            _copyFrom(right);

            return *this;
        }

        FastLinkedQueue& operator=(FastLinkedQueue&& right) noexcept
        {
            FastLinkedQueue::~FastLinkedQueue();

            _current = right._current;
            _last = right._last;

            return *this;
        }

        [[nodiscard]]
        T& Back()
        {
            CollectionHelper::CheckBackFront(this->_length);

            return GetBackUnsafe();
        }

        [[nodiscard]]
        T const& Back() const
        {
            CollectionHelper::CheckBackFront(this->_length);

            return GetBackUnsafe();
        }

        template <class... Args>
        void Emplace(Args&&... args)
        {
            StackElement<T>* e = NEW StackElement<T>(nullptr, std::forward<Args>(args)...);
            MemoryAllocationException::CheckNull(e);

            if (this->_length == 0) {
                _current = e;
                _last = e;
                ++this->_length;

                return;
            }

            _last->Next(e);
            _last = e;
            ++this->_length;
        }

        [[nodiscard]]
        T& Front()
        {
            CollectionHelper::CheckBackFront(this->_length);

            return GetFrontUnsafe();
        }

        [[nodiscard]]
        T const& Front() const
        {
            CollectionHelper::CheckBackFront(this->_length);

            return GetFrontUnsafe();
        }

        [[nodiscard]] constexpr T& GetBackUnsafe() noexcept { return _last->Value(); }
        [[nodiscard]] constexpr T const& GetBackUnsafe() const noexcept { return _last->Value(); }

        [[nodiscard]] constexpr T& GetFrontUnsafe() noexcept { return _current->Value(); }
        [[nodiscard]] constexpr T const& GetFrontUnsafe() const noexcept { return _current->Value(); }

        [[nodiscard]]
        T Pop()
        {
            CollectionHelper::CheckBackFront(this->_length);
            return PopUnsafe();
        }

        [[nodiscard]]
        T PopUnsafe() noexcept
        {
            T value = std::move(_current->Value());

            StackElement<T>* tmp = _current->Next();

            delete _current;

            _current = tmp;

            --this->_length;

            return value;
        }

        void Push() requires ::std::default_initializable<T>
        {
            Emplace();
        }

        void Push(T const& value) requires ::std::copy_constructible<T>
        {
            Emplace(value);
        }

        void Push(T&& value) requires ::std::move_constructible<T>
        {
            Emplace(std::move(value));
        }

        private:
        StackElement<T>* _current;
        StackElement<T>* _last;

        void _copyFrom(FastLinkedQueue const& right)
        {
            StackElement<T>* e = right._current;
            StackElement<T>* tmp;

            while (e != nullptr) {
                tmp = e->Next();

                Push(e->Value());

                e = tmp;
            }
        }
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTLINKEDQUEUE_H
