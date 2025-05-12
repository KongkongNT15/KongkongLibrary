#ifndef KONGKONG_WIN32_UI_WINDOWCLOSINGEVENTARGS_H
#define KONGKONG_WIN32_UI_WINDOWCLOSINGEVENTARGS_H

#include "Base.h"
#include "Kongkong.Events.EventArgs.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct WindowClosingEventArgs : public ::KONGKONG_NAMESPACE::Events::EventArgs {

        constexpr WindowClosingEventArgs() noexcept : WindowClosingEventArgs(false) {} 
        constexpr WindowClosingEventArgs(bool cancel) noexcept : _cancel(cancel), _p(&_cancel) {}

        [[nodiscard]]
        constexpr bool Cancel() const noexcept { return _cancel; }
        
        constexpr void Cancel(bool value) const noexcept { *_p = value; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        bool _cancel;

        //ふぁ！？っく
        bool* _p;
    };
}

#endif //!KONGKONG_WIN32_UI_WINDOWCLOSINGEVENTARGS_H
