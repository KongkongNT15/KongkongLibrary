#ifndef KONGKONG_THREADING_ASYNACTION_H
#define KONGKONG_THREADING_ASYNACTION_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Threading._awaiterBase.h"

#include <coroutine>

namespace KONGKONG_NAMESPACE::Threading
{
    struct AsyncAction final : public ValueType, public _awaiterBase {

        [[nodiscard]]
        static AsyncAction DelayAsync(uint32_t milliseconds) noexcept;

        void await_resume() const;

        struct promise_type : public _awaiterBase::promise_type_base {
            AsyncAction get_return_object();
            constexpr void return_void() noexcept {}
            
        };

        constexpr AsyncAction() : _handle(nullptr) {}
        AsyncAction(AsyncAction const&) = delete;

        AsyncAction(AsyncAction&& right) noexcept;

        ~AsyncAction();

        AsyncAction& operator=(AsyncAction const&) = delete;

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        using _handleType = std::coroutine_handle<promise_type>;

        _handleType _handle;

        explicit AsyncAction(promise_type& promise);
    };
}

#endif //!KONGKONG_THREADING_ASYNACTION_H
