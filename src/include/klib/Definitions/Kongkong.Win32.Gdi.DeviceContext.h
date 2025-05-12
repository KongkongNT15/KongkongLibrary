#ifndef KONGKONG_WIN32_GDI_DEVICECONTEXT_H
#define KONGKONG_WIN32_GDI_DEVICECONTEXT_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Win32::Gdi
{
    /// @brief HDCのラッパー
    struct DeviceContext final : public ValueType {

        /// @brief ふぁ！？っく
        DeviceContext(std::nullptr_t, bool) = delete;

        /// @brief HDCをラップ
        /// @param dc HDC
        /// @param autoRelease デストラクタでハンドルを解放するかどうかを指定
        DeviceContext(::HDC dc, bool autoRelease);

        DeviceContext(DeviceContext const&) = delete;
        DeviceContext(DeviceContext&& right) noexcept;

        ~DeviceContext();

        DeviceContext& operator=(DeviceContext const&) = delete;
        DeviceContext& operator=(DeviceContext&& right) noexcept;

        /// @brief ハンドルを閉じる
        /// @throws InvalidOperationException: ハンドルが既に閉じられているとき
        void Close();

        /// @brief ハンドルが有効かどうか
        [[nodiscard]]
        constexpr bool IsValid() const noexcept { return _dc != nullptr; }

        /// @brief 四角形を描画
        /// @param left 左端のx座標
        /// @param top 上端のy座標
        /// @param right 右端のx座標
        /// @param bottom 下端のy座標
        /// @throws InvalidOperationException: ハンドルが既に閉じられているとき
        /// @throws HResultException: 操作に失敗したとき
        void PaintRectangle(int left, int top, int right, int bottom);

        /// @brief 四角形を描画
        /// @param rect 四角形
        /// @throws InvalidOperationException: ハンドルが既に閉じられているとき
        /// @throws HResultException: 操作に失敗したとき
        void PaintRectangle(::RECT const& rect);

        /// @brief 四角形を描画
        /// @param rect 四角形
        /// @throws InvalidOperationException: ハンドルが既に閉じられているとき
        /// @throws HResultException: 操作に失敗したとき
        void PaintRectangle(UI::Rect const& rect);

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;


        private:

        ::HDC _dc;
        ::HWND _hwnd;
        bool _autoRelease;

        void _checkHandle() const;
    };
}

#endif //!KONGKONG_WIN32_GDI_DEVICECONTEXT_H
