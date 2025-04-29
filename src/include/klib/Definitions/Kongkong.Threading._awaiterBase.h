#ifndef KONGKONG_THREADING_AWAITERBASE_H
#define KONGKONG_THREADING_AWAITERBASE_H

#include "Base.h"

#include "Kongkong.Threading.TaskStatus.h"

#include <coroutine>

namespace KONGKONG_NAMESPACE::Threading
{
    struct _awaiterBase {

        constexpr bool await_ready() const noexcept { return false; }
        void await_suspend(std::coroutine_handle<> h);

        [[nodiscard]]
        constexpr TaskStatus Status() const noexcept { return _status; }

        void Wait() const noexcept;

        struct promise_type_base {

            constexpr promise_type_base() noexcept : __action(nullptr) {}

            static constexpr auto initial_suspend() noexcept { return ::std::suspend_never{}; }
            ::std::suspend_never final_suspend() noexcept;
            constexpr void unhandled_exception() noexcept { if (__action != nullptr) __action->_status = TaskStatus::Faulted; }

            _awaiterBase* __action;
        };

        private:
        constexpr _awaiterBase() noexcept : _status(TaskStatus::Running), _hOther(nullptr) {}
        _awaiterBase(_awaiterBase const&) = default;
        _awaiterBase(_awaiterBase&&) = default;

        _awaiterBase& operator=(_awaiterBase const&) = default;
        _awaiterBase& operator=(_awaiterBase&&) = default;

        TaskStatus _status;
        ::std::coroutine_handle<> _hOther;
        void _throw() const;

        friend AsyncAction;

        template <class T> requires (::std::is_void_v<T> == false)
        friend struct AsyncOperation;
    };
}

#endif //!KONGKONG_THREADING_AWAITERBASE_H
