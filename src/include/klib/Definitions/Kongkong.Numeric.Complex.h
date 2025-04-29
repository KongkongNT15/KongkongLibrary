#ifndef KONGKONG_NUMERIC_COMPLEX_H
#define KONGKONG_NUMERIC_COMPLEX_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Numeric
{
    /// @brief 複素数
    /// @tparam TFloat 数値型
    template <std::floating_point TFloat>
    struct Complex final : public ValueType {
        using FloatType = TFloat;

        [[nodiscard]] friend constexpr bool operator==(Complex const& left, Complex const& right) noexcept { return left._real == right._real && left._imag == right._imag; }
        [[nodiscard]] friend constexpr bool operator==(Complex const& left, TFloat right) noexcept { return left._real == right && left._imag == 0.0; }
        [[nodiscard]] friend constexpr bool operator==(TFloat left, Complex const& right) noexcept { return left == right._real && right._imag == 0.0; }
        [[nodiscard]] friend constexpr bool operator!=(Complex const& left, Complex const& right) noexcept { return left._real != right._real || left._imag != right._imag; }
        [[nodiscard]] friend constexpr bool operator!=(Complex const& left, TFloat right) noexcept { return left._real != right || left._imag != 0.0; }
        [[nodiscard]] friend constexpr bool operator!=(TFloat left, Complex const& right) noexcept { return left != right._real || right._imag != 0.0; }

        [[nodiscard]] friend constexpr Complex operator+(Complex const& left, Complex const& right) noexcept { return Complex(left._real + right._real, left._imag + right._imag); }
        [[nodiscard]] friend constexpr Complex operator+(Complex const& left, TFloat right) noexcept { return Complex(left._real + right, left._imag); }
        [[nodiscard]] friend constexpr Complex operator+(TFloat left, Complex const& right) noexcept { return Complex(left + right._real, right._imag); }
        [[nodiscard]] friend constexpr Complex operator-(Complex const& left, Complex const& right) noexcept { return Complex(left._real - right._real, left._imag - right._imag); }
        [[nodiscard]] friend constexpr Complex operator-(Complex const& left, TFloat right) noexcept { return Complex(left._real - right, left._imag); }
        [[nodiscard]] friend constexpr Complex operator-(TFloat left, Complex const& right) noexcept { return Complex(left - right._real, right._imag); }
        [[nodiscard]] friend constexpr Complex operator*(Complex const& left, Complex const& right) noexcept { return Complex(left._real * right._real - left._imag * right._imag, left._imag * right._real + left._real * right._imag); }
        [[nodiscard]] friend constexpr Complex operator*(Complex const& left, TFloat right) noexcept { return Complex(left._real * right, left._imag * right); }
        [[nodiscard]] friend constexpr Complex operator*(TFloat left, Complex const& right) noexcept { return Complex(left * right._real, left * right._imag); }

        template <std::floating_point TF2>
        friend Complex<TF2> operator/(Complex<TF2> const& left, Complex<TF2> const& right);

        template <std::floating_point TF2>
        friend Complex<TF2> operator/(Complex<TF2> const& left, TF2 right);

        template <std::floating_point TF2>
        friend Complex<TF2> operator/(TF2 left, Complex<TF2> const& right);

        constexpr Complex() noexcept : _real(), _imag() {}
        constexpr Complex(TFloat real) noexcept : _real(real), _imag() {}
        constexpr Complex(TFloat real, TFloat imag) noexcept : _real(real), _imag(imag) {}

        constexpr Complex& operator+=(TFloat value) noexcept { _real += value; return *this; }
        constexpr Complex& operator+=(Complex const& value) noexcept { _real += value._real; _imag += value._imag; return *this; }
        constexpr Complex& operator-=(TFloat value) noexcept { _real -= value; return *this; }
        constexpr Complex& operator-=(Complex const& value) noexcept { _real -= value._real; _imag -= value._imag; return *this; }
        constexpr Complex& operator*=(TFloat value) noexcept { _real *= value; _imag *= value; return *this; }
        Complex& operator/=(TFloat value);

        /// @brief 偏角
        [[nodiscard]]
        TFloat Argument() const noexcept;

        /// @brief 複素共役を取得
        [[nodiscard]]
        constexpr Complex Conjugate() const noexcept { return Complex(_real, -_imag); }

        /// @brief Cos(*this)を取得
        [[nodiscard]]
        Complex Cos() const noexcept;

        /// @brief exp(*this)を取得
        [[nodiscard]]
        Complex Exp() const noexcept;

        /// @brief 虚部
        [[nodiscard]] constexpr TFloat Imag() const noexcept { return _imag; }

        /// @brief 虚部を設定
        /// @param value 設定する値
        constexpr void Imag(TFloat value) noexcept { _imag = value; }

        /// @brief ゼロであるかどうか
        [[nodiscard]]
        constexpr bool IsZero() const noexcept { return _real == 0.0 && _imag == 0.0; }

        /// @brief 長さ
        [[nodiscard]]
        TFloat Length() const noexcept;

        /// @brief *this の pow 乗を取得
        /// @param pow 累乗
        [[nodiscard]]
        Complex Pow(TFloat pow) const noexcept;

        /// @brief *this の pow 乗を取得
        /// @param pow 累乗
        [[nodiscard]]
        Complex Pow(Complex const& pow) const noexcept;

        /// @brief 実部
        [[nodiscard]] constexpr TFloat Real() const noexcept { return _real; }

        /// @brief 実部を設定
        /// @param value 設定する値
        constexpr void Real(TFloat value) noexcept { _real = value; }

        /// @brief Sin(*this)を取得
        [[nodiscard]]
        Complex Sin() const noexcept;

        /// @brief 長さの2乗
        [[nodiscard]]
        constexpr TFloat SquareLength() const noexcept { return _real * _real + _imag * _imag; }

        /// @brief Tan(*this)を取得
        [[nodiscard]]
        Complex Tan() const noexcept;

        /// @brief 極形式に変換
        [[nodiscard]]
        PolarComplex<TFloat> ToPolarComplex() const noexcept;

        /// @brief 値の文字列表現を取得
        /// @return u"[ Read(), Imag() ]"
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        TFloat _real;
        TFloat _imag;
    };

    /// @brief 複素数の割り算
    /// @tparam TFloat 数値型
    /// @param left 割られる数
    /// @param right 割る数
    /// @return 計算結果
    /// @throws DivideByZeroException: rightがゼロの時
    template <std::floating_point TFloat>
    [[nodiscard]] Complex<TFloat> operator/(Complex<TFloat> const& left, Complex<TFloat> const& right);

    /// @brief 複素数の割り算
    /// @tparam TFloat 数値型
    /// @param left 割られる数
    /// @param right 割る数
    /// @return 計算結果
    /// @throws DivideByZeroException: rightがゼロの時
    template <std::floating_point TFloat>
    [[nodiscard]] Complex<TFloat> operator/(Complex<TFloat> const& left, TFloat right);

    /// @brief 複素数の割り算
    /// @tparam TFloat 数値型
    /// @param left 割られる数
    /// @param right 割る数
    /// @return 計算結果
    /// @throws DivideByZeroException: rightがゼロの時
    template <std::floating_point TFloat>
    [[nodiscard]] Complex<TFloat> operator/(TFloat left, Complex<TFloat> const& right);
}

#endif //!KONGKONG_NUMERIC_COMPLEX_H
