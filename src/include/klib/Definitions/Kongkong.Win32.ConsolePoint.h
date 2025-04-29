#ifndef KONGKONG_WIN32_CONSOLEPOINT_H
#define KONGKONG_WIN32_CONSOLEPOINT_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Win32
{
    /// @brief コンソール上の座標
    struct ConsolePoint final : public ValueType {

        /// @brief 原点を作成
        constexpr ConsolePoint() noexcept : _coord({0, 0}) {}

        /// @brief 座標を指定して作成
        /// @param x X座標
        /// @param y Y座標
        constexpr ConsolePoint(int16_t x, int16_t y) : _coord({ x, y }) {}

        /// @brief ::COORDから作成
        /// @param coord コピー元の値
        constexpr ConsolePoint(::COORD const& coord) noexcept : _coord(coord) {}

        /// @brief ::COORDに変換
        constexpr operator ::COORD() const noexcept { return _coord; }

        /// @brief ::COORDからコピー
        /// @param coord コピー元の値
        constexpr ConsolePoint& operator=(::COORD const& coord) noexcept {  _coord = coord; return *this; }

        [[nodiscard]]
        constexpr bool IsOrigin() const noexcept { return _coord.X == 0 && _coord.Y == 0; }

        [[nodiscard]]
        constexpr int16_t X() const noexcept { return _coord.X; }

        constexpr void X(int16_t value) noexcept { _coord.X = value; }

        [[nodiscard]]
        constexpr int16_t Y() const noexcept { return _coord.Y; }

        constexpr void Y(int16_t value) noexcept { _coord.Y = value; }

        /// @brief 座標を取得
        /// @return u"X(), Y()"
        [[nodiscard]]
        String ToString() const;

        private:
        ::COORD _coord;
    };
}

#endif //!KONGKONG_WIN32_CONSOLEPOINT_H
