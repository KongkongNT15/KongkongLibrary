#ifndef KONGKONG_WIN32_UI_TITLEBAR_H
#define KONGKONG_WIN32_UI_TITLEBAR_H

#include "Base.h"
#include "Kongkong.Object.h"
#include "Kongkong.Win32.UI.ElementTheme.h"

namespace KONGKONG_NAMESPACE::Win32::UI::IMPLEMENTATION
{
    struct KONGKONG_INCOMPLETED_CLASS TitleBar final : public ::KONGKONG_NAMESPACE::IMPLEMENTATION::Object {
        using ProjType = ::KONGKONG_NAMESPACE::Win32::UI::TitleBar;

        void BackDrop(SystemBackDrop backDrop);
        SystemBackDrop BackDrop() const;

        String ToString() const override;

        private:
        constexpr TitleBar(::HWND hWindow) noexcept : _hWindow(hWindow), _requestedTheme(ElementTheme::Default) {}

        ::HWND _hWindow;
        ElementTheme _requestedTheme;

        friend ProjType;
    };
}

namespace KONGKONG_NAMESPACE::Win32::UI
{
    /// @brief タイトルバー
    class KONGKONG_INCOMPLETED_CLASS TitleBar final : public Object {
        public:
        using ImplType = IMPLEMENTATION::TitleBar;

        /// @brief nullptrとして作成
        constexpr TitleBar(std::nullptr_t) noexcept : Object(nullptr) {}

        /// @brief タイトルバーの透明効果の種類を設定
        /// @attention 実行環境はWindows 11じゃないとだめだよ！
        /// @param backDrop 透明効果の種類
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws HResultException: 操作に失敗したとき
        void BackDrop(SystemBackDrop backDrop) const;

        /// @brief タイトルバーの透明効果の種類を取得
        /// @attention 実行環境はWindows 11じゃないとだめだよ！
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        /// @throws HResultException: 操作に失敗したとき
        SystemBackDrop BackDrop() const;

        private:
        friend IMPLEMENTATION::Window;

        /// @brief 作成
        /// @param hWindow ウィンドウハンドル
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        TitleBar(::HWND hWindow);
    };
}

#endif //!KONGKONG_WIN32_UI_TITLEBAR_H
