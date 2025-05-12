#ifndef KONGKONG_WIN32_UI_WINDOWCREATINGEVENTARGS_H
#define KONGKONG_WIN32_UI_WINDOWCREATINGEVENTARGS_H

#include "Base.h"
#include "Kongkong.Events.EventArgs.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct WindowCreatingEventArgs final : public ::KONGKONG_NAMESPACE::Events::EventArgs {

        constexpr WindowCreatingEventArgs() noexcept : WindowCreatingEventArgs(true) {}
        constexpr WindowCreatingEventArgs(bool create) noexcept : _create(create), _p(&_create) {}

        constexpr void Create(bool value) const noexcept { *_p = value; }
        
        [[nodiscard]]
        constexpr bool Create() const noexcept { return _create; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        bool _create;

        //ふぁ！？っく
        bool* _p;
    };
}

#endif //!KONGKONG_WIN32_UI_WINDOWCREATINGEVENTARGS_H
