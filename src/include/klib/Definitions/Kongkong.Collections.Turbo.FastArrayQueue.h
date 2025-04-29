#ifndef KONGKONG_COLLECTIONS_TURBO_FASTARRAYQUEUE_H
#define KONGKONG_COLLECTIONS_TURBO_FASTARRAYQUEUE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo._fastArrayQueueBase.h"
#include "Kongkong.Collections.CollectionHelper.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.InvalidOperationException.h"
#include "Kongkong.Collections.KeyValuePair.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastArrayQueue final : public ValueType, public _fastArrayQueueBase {

        FastArrayQueue() : _fastArrayQueueBase(Collections::CollectionHelper::DefaultCapacity()), _p((T*)::malloc(Collections::CollectionHelper::DefaultCapacity() * sizeof(T)))
        {
            MemoryAllocationException::CheckNull(_p);
        }

        FastArrayQueue(FastArrayQueue const& right) : _fastArrayQueueBase(Collections::CollectionHelper::CreateCapacity(right._Length()), 0, right.Length()), _p((T*)::malloc(this->_capacity * sizeof(T)))
        {
            MemoryAllocationException::CheckNull(_p);

            ssize_t length = right.Length();

            for (ssize_t i = 0; i < length; i++) {
                try {
                    new (_p + i) T(right._p[i + right._current]);
                }
                catch (...) {
                    for (ssize_t j = 0; j < i; j++) {
                        _p[j].~T();
                    }

                    ::free(_p);
    
                    ::std::rethrow_exception(::std::current_exception());
                }
            }
            
        }

        FastArrayQueue(FastArrayQueue&& right) noexcept : _fastArrayQueueBase(right), _p(right._p)
        {
            right._p = nullptr;
        }

        ~FastArrayQueue()
        {
            if (_p == nullptr) return;

            for (T& element : *this) {
                element.~T();
            }

            ::free(_p);
        }

        /// @brief 値をコピー
        /// @attention 操作に失敗すると*thisのデータが消滅するよ！
        /// @param right コピー元
        /// @return *this
        FastArrayQueue& operator=(FastArrayQueue const& right)
        {
            ssize_t rLength = right.Length();

            if (this->_capacity < rLength) {
                FastArrayQueue::~FastArrayQueue();

                this->_capacity = Collections::CollectionHelper::CreateCapacity(rLength);

                _p = (T*)::malloc(this->_capacity * sizeof(T));

                MemoryAllocationException::CheckNull(_p);
            }
            else {
                for (T& element : *this) {
                    element.~T();
                }
            }

            this->_current = 0;
            this->_end = rLength;

            for (ssize_t i = 0; i < rLength; i++) {
                try {
                    new (_p + i) T(right._p[i + right._current]);
                }
                catch (...) {
                    for (ssize_t j = 0; j < i; j++) {
                        _p[j].~T();
                    }

                    ::free(_p);
    
                    ::std::rethrow_exception(::std::current_exception());
                }
            }
            
            return *this;
        }

        FastArrayQueue& operator=(FastArrayQueue&& right) noexcept
        {
            FastArrayQueue::~FastArrayQueue();

            _fastArrayQueueBase::operator=(right);

            this->_p = right._p;

            right._p = nullptr;

            return *this;
        }

        [[nodiscard]] constexpr T* begin() noexcept { return _p + this->_current; }
        [[nodiscard]] constexpr const T* begin() const noexcept { return _p + this->_current; }
        [[nodiscard]] constexpr T* end() noexcept { return _p + this->_end; }
        [[nodiscard]] constexpr const T* end() const noexcept { return _p + this->_end; }

        [[nodiscard]]
        T& Back()
        {
            CollectionHelper::CheckBackFront(this->Length());

            return GetBackUnsafe();
        }

        [[nodiscard]]
        T const& Back() const
        {
            CollectionHelper::CheckBackFront(this->Length());

            return GetBackUnsafe();
        }

        template <class... Args>
        void Emplace(Args&&... args)
        {
            _increateCapacity();

            new (_p + this->_end) T(::std::forward<Args>(args)...);
            
            ++this->_end;
        }

        [[nodiscard]]
        T& Front()
        {
            CollectionHelper::CheckBackFront(this->Length());

            return GetFrontUnsafe();
        }

        [[nodiscard]]
        T const& Front() const
        {
            CollectionHelper::CheckBackFront(this->Length());

            return GetFrontUnsafe();
        }

        [[nodiscard]] constexpr T& GetBackUnsafe() noexcept { return _p[this->_end - 1]; }
        [[nodiscard]] constexpr T const& GetBackUnsafe() const noexcept { return _p[this->_end - 1]; }

        [[nodiscard]] constexpr T& GetFrontUnsafe() noexcept { return _p[this->_current]; }
        [[nodiscard]] constexpr T const& GetFrontUnsafe() const noexcept { return _p[this->_current]; }

        [[nodiscard]]
        T Pop()
        {
            CollectionHelper::CheckBackFront(this->Length());

            return PopUnsafe();
        }

        [[nodiscard]]
        T PopUnsafe() noexcept
        {
            return std::move(_p[this->_current++]);
        }

        void Push() requires ::std::default_initializable<T>
        {
            Emplace();
        }

        void Push(T const& value) requires ::std::copy_constructible<T>
        {
            Emplace<T const&>(value);
        }

        void Push(T&& value) requires ::std::move_constructible<T>
        {
            Emplace<T&&>(std::move(value));
        }

        private:
        T* _p;

        void _increateCapacity()
        {
            ssize_t nextEnd = this->_end + 1;
            ssize_t oldLength = this->Length();

            if (nextEnd > this->_capacity) {
                if (oldLength < this->_capacity) {
                    for (ssize_t i = 0; i < oldLength; i++) {
                        new (_p + i) T(std::move(_p[i + _current]));
                    }
                }
                else {
                    ssize_t newCapacity = Collections::CollectionHelper::CreateCapacity(oldLength + 1);
                    T* p = (T*)::malloc(newCapacity * sizeof(T));

                    MemoryAllocationException::CheckNull(p);

                    for (T& element : *this) {
                        element.~T();
                    }
        
                    ::free(_p);

                    _p = p;
                    this->_capacity = newCapacity;
                }
            }
        }
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTARRAYQUEUE_H
