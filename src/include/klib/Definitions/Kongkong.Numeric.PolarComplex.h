#ifndef KONGKONG_NUMERIC_POLARCOMPLEX_H
#define KONGKONG_NUMERIC_POLARCOMPLEX_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Numeric
{
    /// @brief 複素数の極形式
    /// @tparam TFloat 数値型
    template <std::floating_point TFloat>
    struct PolarComplex final : public ValueType {
        using FloatType = TFloat;

        template <std::floating_point TF2>
        friend PolarComplex<TF2> operator*(PolarComplex<TF2> const& left, PolarComplex<TF2> const& right) noexcept;

        template <std::floating_point TF2>
        friend PolarComplex<TF2> operator/(PolarComplex<TF2> const& left, PolarComplex<TF2> const& right);

        /// @brief 半径と角度の整合性を確認せずに作成
        /// @param radius 半径
        /// @param theta 角度
        [[nodiscard]]
        static constexpr PolarComplex CreateUnsafe(TFloat radius, TFloat theta) noexcept { return PolarComplex(radius, theta, 0); }

        /// @brief ゼロで作成
        constexpr PolarComplex() noexcept : _radius(), _theta() {}

        /// @brief 半径と角度を指定して作成
        /// @attention Theta()には theta % pi が代入されるよ！
        /// @param radius 半径
        /// @param theta 角度
        /// @throws InvalidArgumentException: radiusが負の値の時
        PolarComplex(TFloat radius, TFloat theta);

        /// @brief 偏角
        [[nodiscard]]
        constexpr TFloat Argument() const noexcept { return _theta; }

        /// @brief 偏角を設定
        /// @attention value % pi が代入されるよ！
        /// @param value 偏角
        void Argument(TFloat value) noexcept;

        /// @brief Cos(*this)を取得
        [[nodiscard]]
        PolarComplex Cos() const noexcept;

        /// @brief exp(*this)を取得
        [[nodiscard]]
        PolarComplex Exp() const noexcept;

        /// @brief 虚部
        [[nodiscard]]
        TFloat Imag() const noexcept;

        /// @brief ゼロであるかどうか
        [[nodiscard]]
        constexpr bool IsZero() const noexcept { return _radius == 0.0; }

        /// @brief 長さ
        [[nodiscard]]
        constexpr TFloat Length() const noexcept { return _radius; }

        /// @brief *this の pow 乗を取得
        /// @param pow 累乗
        [[nodiscard]]
        PolarComplex Pow(TFloat pow) const noexcept;

        /// @brief *this の pow 乗を取得
        /// @param pow 累乗
        [[nodiscard]]
        PolarComplex Pow(PolarComplex const& pow) const noexcept;

        /// @brief 半径
        [[nodiscard]]
        constexpr TFloat Radius() const noexcept { return _radius; }

        /// @brief 実部
        [[nodiscard]]
        TFloat Real() const noexcept;

        /// @brief 半径を設定
        /// @param value 半径
        /// @throws InvalidArgumentException: valueが負の値の時
        void Radius(TFloat value);

        /// @brief 角度をそのまま設定
        /// @param value 角度
        constexpr void SetArgumentUnsafe(TFloat value) noexcept { _theta = value; }

        /// @brief 半径を設定
        /// @param value 半径
        constexpr void SetRadiusUnsafe(TFloat value) noexcept { _radius = value; }

        /// @brief Sin(*this)を取得
        [[nodiscard]]
        PolarComplex Sin() const noexcept;

        /// @brief Tan(*this)を取得
        [[nodiscard]]
        PolarComplex Tan() const noexcept;

        /// @brief Complex<>に変換
        [[nodiscard]]
        Complex<TFloat> ToComplex() const noexcept;

        /// @brief 値の文字列表現を取得
        /// @return u"[ Radius(), Argument() ]"
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        TFloat _radius;
        TFloat _theta;

        constexpr PolarComplex(TFloat radius, TFloat theta, int) noexcept : _radius(radius), _theta(theta) {}

        static void _checkRadius(TFloat value);

        friend Complex<TFloat>;
    };

    template <std::floating_point TFloat>
    [[nodiscard]] PolarComplex<TFloat> operator*(PolarComplex<TFloat> const& left, PolarComplex<TFloat> const& right) noexcept;

    template <std::floating_point TFloat>
    [[nodiscard]] PolarComplex<TFloat> operator/(PolarComplex<TFloat> const& left, PolarComplex<TFloat> const& right);
}

#endif //!KONGKONG_NUMERIC_POLARCOMPLEX_H
