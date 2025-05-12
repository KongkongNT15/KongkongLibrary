#ifndef KONGKONG_WIN32_UI_DPICHANGEDEVENTARGS_H
#define KONGKONG_WIN32_UI_DPICHANGEDEVENTARGS_H

#include "Base.h"
#include "Kongkong.Events.EventArgs.h"

namespace KONGKONG_NAMESPACE::Win32::UI
{
    struct DpiChangedEventArgs final : public ::KONGKONG_NAMESPACE::Events::EventArgs {

        /// @brief Dpiを指定して作成
        /// @param newDpi 変更後のDpi
        constexpr DpiChangedEventArgs(uint32_t newDpi) noexcept : _newDpi(newDpi), _newScale(newDpi / 96.0) {}

        /// @brief 変更後のDpi
        [[nodiscard]]
        constexpr uint32_t NewDpi() const noexcept { return _newDpi; }

        /// @brief 変更後の拡大率
        [[nodiscard]]
        constexpr double NewScale() const noexcept { return _newScale; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        uint32_t _newDpi;
        double _newScale;
    };
}

#endif //!KONGKONG_WIN32_UI_DPICHANGEDEVENTARGS_H
