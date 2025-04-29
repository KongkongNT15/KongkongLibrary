#ifndef KONGKONG_COLLECTIONS_TURBO_FASTARRAYQUEUEBASE_H
#define KONGKONG_COLLECTIONS_TURBO_FASTARRAYQUEUEBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastArrayQueueBase {
        
        [[nodiscard]]
        constexpr ssize_t Capacity() const noexcept { return _capacity; }

        [[nodiscard]]
        constexpr bool IsEmpty() const noexcept { return _current == _end; }

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _end - _current; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        _fastArrayQueueBase() = default;
        constexpr _fastArrayQueueBase(ssize_t capacity) noexcept : _capacity(capacity), _current(0), _end(0) {}
        constexpr _fastArrayQueueBase(ssize_t capacity, ssize_t current, ssize_t end) noexcept : _capacity(capacity), _current(current), _end(end) {}

        ssize_t _capacity;
        ssize_t _current;
        ssize_t _end;

        template <class T>
        friend struct FastArrayQueue;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTARRAYQUEUEBASE_H
