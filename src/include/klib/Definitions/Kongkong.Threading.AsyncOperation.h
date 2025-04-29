#ifndef KONGKONG_THREADING_ASYNCOPERATION_H
#define KONGKONG_THREADING_ASYNCOPERATION_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.LazyObject.h"
#include "Kongkong.Threading._asyncOperationBase.h"
#include "Kongkong.Threading._awaiterBase.h"

#include <coroutine>

namespace KONGKONG_NAMESPACE::Threading
{
    template <class T> requires (::std::is_void_v<T> == false)
    struct AsyncOperation final : public ValueType, public _asyncOperationBase, public _awaiterBase {

        T&& await_resume()
        {
            _awaiterBase::_throw();
            return ::std::move(_obj.GetValueUnsafe());
        }

        struct promise_type final : public _awaiterBase::promise_type_base {

            auto get_return_object() { return AsyncOperation{*this}; }
            void return_value(T const& value) { if (this->__action != nullptr) static_cast<AsyncOperation*>(this->__action)->_obj.SetValue(value); }
            void return_value(T&& value) noexcept { if (this->__action != nullptr) static_cast<AsyncOperation*>(this->__action)->_obj.SetValue(::std::move(value)); }
        };

        AsyncOperation(AsyncOperation&& right) noexcept : _awaiterBase(::std::move(right)), _handle(::std::move(right._handle))
        {
            switch (right._status) {
                case TaskStatus::Canceled:
                case TaskStatus::Completed:
                case TaskStatus::Faulted:
                    break;
    
                default:
                    _handle.promise().__action = this;
                    break;
            }
            right._handle = nullptr;
        }

        ~AsyncOperation()
        {
            if (_handle == nullptr) return;
            
            switch (this->_status) {
                case TaskStatus::Canceled:
                case TaskStatus::Completed:
                case TaskStatus::Faulted:
                    break;

                default:
                    _handle.promise().__action = nullptr;
                    break;
            }
        }

        AsyncOperation& operator=(AsyncOperation&& right) noexcept
        {
            _handle = ::std::move(right._handle);

            right._handle = nullptr;

            return *this;
        }

        /// @brief 結果を取得
        /// @throws InvalidOperationException: このタスクが失敗したとき
        [[nodiscard]]
        T& GetResult()
        {
            this->Wait();

            if (this->_status != TaskStatus::Completed) [[unlikely]] _asyncOperationBase::_throw();

            return _obj.GetValueUnsafe();
        }

        /// @brief 結果を取得
        /// @throws InvalidOperationException: このタスクが失敗したとき
        [[nodiscard]]
        T const& GetResult() const
        {
            this->Wait();

            if (this->_status != TaskStatus::Completed) [[unlikely]] _asyncOperationBase::_throw();

            return _obj.GetValueUnsafe();
        }

        [[nodiscard]]
        TaskStatus Status() const noexcept { return _handle.promise().__status; }

        private:

        ::std::coroutine_handle<promise_type> _handle;
        LazyObject<T> _obj;

        explicit AsyncOperation(promise_type& promise) : _handle(::std::coroutine_handle<promise_type>::from_promise(promise)) { promise.__action = this; }
    };
}

#endif //!KONGKONG_THREADING_ASYNCOPERATION_H
