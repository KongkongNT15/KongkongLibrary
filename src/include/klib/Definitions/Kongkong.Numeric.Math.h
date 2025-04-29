#ifndef KONGKONG_NUMERIC_MATH_H
#define KONGKONG_NUMERIC_MATH_H

#include "Base.h"

#include "Kongkong.ArgumentOutOfRangeException.h"
#include "Kongkong.ArithmeticException.h"
#include "Kongkong.DivideByZeroException.h"
#include "Kongkong.OutOfRangeException.h"

#include "Kongkong.Numeric.Sign.h"

#include <cmath>
#include <numbers>

namespace KONGKONG_NAMESPACE::Numeric
{
    //数学関数
    class Math final {
        public:

        STATIC_CLASS(Math)

        //ネイピアス
        static constexpr double E() noexcept { return std::numbers::e; }
        //円周率
        static constexpr double PI() noexcept { return std::numbers::pi; }
        static constexpr double InversePI() noexcept { return std::numbers::inv_pi; }
        //円周率 * 2.0
        static constexpr double Tau() noexcept { return std::numbers::pi * 2.0; }

        //絶対値
        static constexpr int8_t Abs(int8_t x) noexcept { return _abs(x); }
        static constexpr int16_t Abs(int16_t x) noexcept { return _abs(x); }
        static constexpr int32_t Abs(int32_t x) noexcept { return _abs(x); }
        static constexpr int64_t Abs(int64_t x) noexcept { return _abs(x); }
        static constexpr float Abs(float x) noexcept { return _abs(x); }
        static constexpr double Abs(double x) noexcept { return _abs(x); }
        static constexpr long double Abs(long double x) noexcept { return _abs(x); }

        //arccos
        static float Acos(float x) noexcept { return std::acos(x); }
        static double Acos(double x) noexcept { return std::acos(x); }
        static long double Acos(long double x) noexcept { return std::acos(x); }

        //arccosh
        static float Acosh(float x) noexcept { return std::acosh(x); }
        static double Acosh(double x) noexcept { return std::acosh(x); }
        static long double Acosh(long double x) noexcept { return std::acosh(x); }

        //arcsin
        static float Asin(float x) noexcept { return std::asin(x); }
        static double Asin(double x) noexcept { return std::asin(x); }
        static long double Asin(long double x) noexcept { return std::asin(x); }

        //arcsinh
        static float Asinh(float x) noexcept { return std::asinh(x); }
        static double Asinh(double x) noexcept { return std::asinh(x); }
        static long double Asinh(long double x) noexcept { return std::asinh(x); }

        //arctan
        static float Atan(float x) noexcept { return std::atan(x); }
        static double Atan(double x) noexcept { return std::atan(x); }
        static long double Atan(long double x) noexcept { return std::atan(x); }

        //arctan2
        static float Atan2(float y, float x) noexcept { return std::atan2(y, x); }
        static double Atan2(double y, double x) noexcept { return std::atan2(y, x); }
        static long double Atan2(long double y, long double x) noexcept { return std::atan2(y, x); }

        //arctanh
        static float Atanh(float x) noexcept { return std::atanh(x); }
        static double Atanh(double x) noexcept { return std::atanh(x); }
        static long double Atanh(long double x) noexcept { return std::atanh(x); }

        //立方根
        static float Cbrt(float x) noexcept { return std::cbrt(x); }
        static double Cbrt(double x) noexcept { return std::cbrt(x); }
        static long double Cbrt(long double x) noexcept { return std::cbrt(x); }

        //値以上の最小の整数値
        static float Ceiling(float x) noexcept { return std::ceil(x); }
        static double Ceiling(double x) noexcept { return std::ceil(x); }
        static long double Ceiling(long double x) noexcept { return std::ceil(x); }

        //よくわからんやつ
        static constexpr int8_t Clamp(int8_t value, int8_t min, int8_t max) { return _clamp(value, min, max); }
        static constexpr int16_t Clamp(int16_t value, int16_t min, int16_t max) { return _clamp(value, min, max); }
        static constexpr int32_t Clamp(int32_t value, int32_t min, int32_t max) { return _clamp(value, min, max); }
        static constexpr int64_t Clamp(int64_t value, int64_t min, int64_t max) { return _clamp(value, min, max); }
        static constexpr uint8_t Clamp(uint8_t value, uint8_t min, uint8_t max) { return _clamp(value, min, max); }
        static constexpr uint16_t Clamp(uint16_t value, uint16_t min, uint16_t max) { return _clamp(value, min, max); }
        static constexpr uint32_t Clamp(uint32_t value, uint32_t min, uint32_t max) { return _clamp(value, min, max); }
        static constexpr uint64_t Clamp(uint64_t value, uint64_t min, uint64_t max) { return _clamp(value, min, max); }
        static constexpr float Clamp(float value, float min, float max) { return _clamp(value, min, max); }
        static constexpr double Clamp(double value, double min, double max) { return _clamp(value, min, max); }
        static constexpr long double Clamp(long double value, long double min, long double max) { return _clamp(value, min, max); }

        //符号コピー
        static float CopySign(float x, float y) noexcept { return std::copysign(x, y); }
        static double CopySign(double x, double y) noexcept { return std::copysign(x, y); }
        static long double CopySign(long double x, long double y) noexcept { return std::copysign(x, y); }

        //cos
        static float Cos(float x) noexcept { return std::cos(x); }
        static double Cos(double x) noexcept { return std::cos(x); }
        static long double Cos(long double x) noexcept { return std::cos(x); }
        [[nodiscard]] static Complex<float> Cos(Complex<float> const& z) noexcept;
        [[nodiscard]] static Complex<double> Cos(Complex<double> const& z) noexcept;
        [[nodiscard]] static Complex<long double> Cos(Complex<long double> const& z) noexcept;
        [[nodiscard]] static PolarComplex<float> Cos(PolarComplex<float> const& z) noexcept;
        [[nodiscard]] static PolarComplex<double> Cos(PolarComplex<double> const& z) noexcept;
        [[nodiscard]] static PolarComplex<long double> Cos(PolarComplex<long double> const& z) noexcept;

        //cosh
        static float Cosh(float x) noexcept { return std::cosh(x); }
        static double Cosh(double x) noexcept { return std::cosh(x); }
        static long double Cosh(long double x) noexcept { return std::cosh(x); }

        //割り算の症とあまりの計算
        // left ÷ right
        static constexpr DivInt8 DivRem(int8_t left, int8_t right) { return _divRem(left, right); }
        static constexpr DivInt16 DivRem(int16_t left, int16_t right) { return _divRem(left, right); }
        static constexpr DivInt32 DivRem(int32_t left, int32_t right) { return _divRem(left, right); }
        static constexpr DivInt64 DivRem(int64_t left, int64_t right) { return _divRem(left, right); }
        static constexpr DivUInt8 DivRem(uint8_t left, uint8_t right) { return _divRem(left, right); }
        static constexpr DivUInt16 DivRem(uint16_t left, uint16_t right) { return _divRem(left, right); }
        static constexpr DivUInt32 DivRem(uint32_t left, uint32_t right) { return _divRem(left, right); }
        static constexpr DivUInt64 DivRem(uint64_t left, uint64_t right) { return _divRem(left, right); }

        //割り算の症とあまりの計算
        // a ÷ b
        //result: あまり
        //戻り値: 省
        static int8_t DivRem(int8_t a, int8_t b, int8_t& result) { return _divRem(a, b, result); }
        static int16_t DivRem(int16_t a, int16_t b, int16_t& result) { return _divRem(a, b, result); }
        static int32_t DivRem(int32_t a, int32_t b, int32_t& result) { return _divRem(a, b, result); }
        static int64_t DivRem(int64_t a, int64_t b, int64_t& result) { return _divRem(a, b, result); }
        static uint8_t DivRem(uint8_t a, uint8_t b, uint8_t& result) { return _divRem(a, b, result); }
        static uint16_t DivRem(uint16_t a, uint16_t b, uint16_t& result) { return _divRem(a, b, result); }
        static uint32_t DivRem(uint32_t a, uint32_t b, uint32_t& result) { return _divRem(a, b, result); }
        static uint64_t DivRem(uint64_t a, uint64_t b, uint64_t& result) { return _divRem(a, b, result); }

        //誤差関数
        static float Erf(float x) noexcept { return std::erf(x); }
        static double Erf(double x) noexcept { return std::erf(x); }
        static long double Erf(long double x) noexcept { return std::erf(x); }

        //相補誤差関数
        static float Erfc(float x) noexcept { return std::erfc(x); }
        static double Erfc(double x) noexcept { return std::erfc(x); }
        static long double Erfc(long double x) noexcept { return std::erfc(x); }

        //eの累乗
        static float Exp(float x) noexcept { return std::exp(x); }
        static double Exp(double x) noexcept { return std::exp(x); }
        static long double Exp(long double x) noexcept { return std::exp(x); }
        [[nodiscard]] Complex<float> Exp(Complex<float> const& z) noexcept;
        [[nodiscard]] Complex<double> Exp(Complex<double> const& z) noexcept;
        [[nodiscard]] Complex<long double> Exp(Complex<long double> const& z) noexcept;
        [[nodiscard]] PolarComplex<float> Exp(PolarComplex<float> const& z) noexcept;
        [[nodiscard]] PolarComplex<double> Exp(PolarComplex<double> const& z) noexcept;
        [[nodiscard]] PolarComplex<long double> Exp(PolarComplex<long double> const& z) noexcept;

        //nの階乗
        static constexpr int8_t Factorial(int8_t x) { return _factorial(x); }
        static constexpr int16_t Factorial(int16_t x) { return _factorial(x); }
        static constexpr int32_t Factorial(int32_t x) { return _factorial(x); }
        static constexpr int64_t Factorial(int64_t x) { return _factorial(x); }
        static constexpr uint8_t Factorial(uint8_t x) { return _factorial(x); }
        static constexpr uint16_t Factorial(uint16_t x) { return _factorial(x); }
        static constexpr uint32_t Factorial(uint32_t x) { return _factorial(x); }
        static constexpr uint64_t Factorial(uint64_t x) { return _factorial(x); }

        //x以下の最大の整数
        static float Floor(float x) noexcept { return std::floor(x); }
        static double Floor(double x) noexcept { return std::floor(x); }
        static long double Floor(long double x) noexcept { return std::floor(x); }

        //x * y + z
        static float FusedMultiplyAdd(float x, float y, float z) noexcept { return std::fma(x, y, z); }
        static double FusedMultiplyAdd(double x, double y, double z) noexcept { return std::fma(x, y, z); }
        static long double FusedMultiplyAdd(long double x, long double y, long double z) noexcept { return std::fma(x, y, z); }

        //ガンマ関数
        static float Gamma(float x) noexcept { return std::tgamma(x); }
        static double Gamma(double x) noexcept { return std::tgamma(x); }
        static long double Gamma(long double x) noexcept { return std::tgamma(x); }

        //log2(X)
        static int ILogB(float x) noexcept { return (int)std::log2(x); }
        static int ILogB(double x) noexcept { return (int)std::log2(x); }
        static int ILogB(long double x) noexcept { return (int)std::log2(x); }

        //log
        static float Log(float x) noexcept { return std::log(x); }
        static double Log(double x) noexcept { return std::log(x); }
        static long double Log(long double x) noexcept { return std::log(x); }

        //log_a(b) 
        static float Log(float a, float b) noexcept { return std::log(b) / std::log(a); }
        static double Log(double a, double b) noexcept { return std::log(b) / std::log(a); }
        static long double Log(long double a, long double b) noexcept { return std::log(b) / std::log(a); }

        //log_2(x)
        static float Log2(float x) noexcept { return std::log2(x); }
        static double Log2(double x) noexcept { return std::log2(x); }
        static long double Log2(long double x) noexcept { return std::log2(x); }

        //log_10(x)
        static float Log10(float x) noexcept { return std::log10(x); }
        static double Log10(double x) noexcept { return std::log10(x); }
        static long double Log10(long double x) noexcept { return std::log10(x); }

        //大きいほう
        static constexpr int8_t Max(int8_t a, int8_t b) noexcept { return _max(a, b); }
        static constexpr int16_t Max(int16_t a, int16_t b) noexcept { return _max(a, b); }
        static constexpr int32_t Max(int32_t a, int32_t b) noexcept { return _max(a, b); }
        static constexpr int64_t Max(int64_t a, int64_t b) noexcept { return _max(a, b); }
        static constexpr uint8_t Max(uint8_t a, uint8_t b) noexcept { return _max(a, b); }
        static constexpr uint16_t Max(uint16_t a, uint16_t b) noexcept { return _max(a, b); }
        static constexpr uint32_t Max(uint32_t a, uint32_t b) noexcept { return _max(a, b); }
        static constexpr uint64_t Max(uint64_t a, uint64_t b) noexcept { return _max(a, b); }
        static constexpr float Max(float a, float b) noexcept { return _max(a, b); }
        static constexpr double Max(double a, double b) noexcept { return _max(a, b); }
        static constexpr long double Max(long double a, long double b) noexcept { return _max(a, b); }

        //小さいほう
        static constexpr int8_t Min(int8_t a, int8_t b) noexcept { return _min(a, b); }
        static constexpr int16_t Min(int16_t a, int16_t b) noexcept { return _min(a, b); }
        static constexpr int32_t Min(int32_t a, int32_t b) noexcept { return _min(a, b); }
        static constexpr int64_t Min(int64_t a, int64_t b) noexcept { return _min(a, b); }
        static constexpr uint8_t Min(uint8_t a, uint8_t b) noexcept { return _min(a, b); }
        static constexpr uint16_t Min(uint16_t a, uint16_t b) noexcept { return _min(a, b); }
        static constexpr uint32_t Min(uint32_t a, uint32_t b) noexcept { return _min(a, b); }
        static constexpr uint64_t Min(uint64_t a, uint64_t b) noexcept { return _min(a, b); }
        static constexpr float Min(float a, float b) noexcept { return _min(a, b); }
        static constexpr double Min(double a, double b) noexcept { return _min(a, b); }
        static constexpr long double Min(long double a, long double b) noexcept { return _min(a, b); }

        //整数部と小数部に分ける
        //x = a(整数部) + b(小数部)
        static void Mod(float x, float& a, float& b) { _mod(x, a, b); }
        static void Mod(double x, double& a, double& b) { _mod(x, a, b); }
        static void Mod(long double x, long double& a, long double& b) { _mod(x, a, b); }

        //累乗
        //x ^ y
        static constexpr int8_t Pow(int8_t x, int8_t y) noexcept { return _pow(x, y); }
        static constexpr int16_t Pow(int16_t x, int16_t y) noexcept { return _pow(x, y); }
        static constexpr int32_t Pow(int32_t x, int32_t y) noexcept { return _pow(x, y); }
        static constexpr int64_t Pow(int64_t x, int64_t y) noexcept { return _pow(x, y); }
        static constexpr uint8_t Pow(uint8_t x, uint8_t y) noexcept { return _pow(x, y); }
        static constexpr uint16_t Pow(uint16_t x, uint16_t y) noexcept { return _pow(x, y); }
        static constexpr uint32_t Pow(uint32_t x, uint32_t y) noexcept { return _pow(x, y); }
        static constexpr uint64_t Pow(uint64_t x, uint64_t y) noexcept { return _pow(x, y); }
        static float Pow(float x, float y) noexcept { return std::pow(x, y); }
        static double Pow(double x, double y) noexcept { return std::pow(x, y); }
        static long double Pow(long double x, long double y) noexcept { return std::pow(x, y); }
        [[nodiscard]] static Complex<float> Pow(Complex<float> const& z1, Complex<float> const& z2);
        [[nodiscard]] static Complex<double> Pow(Complex<double> const& z1, Complex<double> const& z2);
        [[nodiscard]] static Complex<long double> Pow(Complex<long double> const& z1, Complex<long double> const& z2);
        [[nodiscard]] static PolarComplex<float> Pow(PolarComplex<float> const& z1, PolarComplex<float> const& z2);
        [[nodiscard]] static PolarComplex<double> Pow(PolarComplex<double> const& z1, PolarComplex<double> const& z2);
        [[nodiscard]] static PolarComplex<long double> Pow(PolarComplex<long double> const& z1, PolarComplex<long double> const& z2);
        [[nodiscard]] static Complex<float> Pow(Complex<float> const& z1, float z2);
        [[nodiscard]] static Complex<double> Pow(Complex<double> const& z1, double z2);
        [[nodiscard]] static Complex<long double> Pow(Complex<long double> const& z1, long double z2);
        [[nodiscard]] static PolarComplex<float> Pow(PolarComplex<float> const& z1, float z2);
        [[nodiscard]] static PolarComplex<double> Pow(PolarComplex<double> const& z1, double z2);
        [[nodiscard]] static PolarComplex<long double> Pow(PolarComplex<long double> const& z1, long double z2);
        [[nodiscard]] static Complex<float> Pow(float z1, Complex<float> const& z2);
        [[nodiscard]] static Complex<double> Pow(double z1, Complex<double> const& z2);
        [[nodiscard]] static Complex<long double> Pow(long double z1, Complex<long double> const& z2);
        [[nodiscard]] static PolarComplex<float> Pow(float z1, PolarComplex<float> const& z2);
        [[nodiscard]] static PolarComplex<double> Pow(double z1, PolarComplex<double> const& z2);
        [[nodiscard]] static PolarComplex<long double> Pow(long double z1, PolarComplex<long double> const& z2);

        //値を整数に丸める
        static float Round(float x) noexcept { return std::round(x); }
        static double Round(double x) noexcept { return std::round(x); }
        static long double Round(long double x) noexcept { return std::round(x); }

        //和の式
        //ret = 1 + 2 + 3 + ... + x;
        static constexpr int8_t Sigma(int8_t x) { return _sigma(x); }
        static constexpr int16_t Sigma(int16_t x) { return _sigma(x); }
        static constexpr int32_t Sigma(int32_t x) { return _sigma(x); }
        static constexpr int64_t Sigma(int64_t x) { return _sigma(x); }
        static constexpr uint8_t Sigma(uint8_t x) { return _sigma(x); }
        static constexpr uint16_t Sigma(uint16_t x) { return _sigma(x); }
        static constexpr uint32_t Sigma(uint32_t x) { return _sigma(x); }
        static constexpr uint64_t Sigma(uint64_t x) { return _sigma(x); }

        //値の符号を取得
        //戻り値が
        //1:  正の値
        //0:  ゼロ
        //-1: 負の値
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(int8_t x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(int16_t x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(int32_t x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(int64_t x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(uint8_t x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(uint16_t x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(uint32_t x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(uint64_t x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(float x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(double x) noexcept { return _sign(x); }
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign Sign(long double x) noexcept { return _sign(x); }

        //sin
        static float Sin(float x) noexcept { return std::sin(x); }
        static double Sin(double x) noexcept { return std::sin(x); }
        static long double Sin(long double x) noexcept { return std::sin(x); }
        [[nodiscard]] static Complex<float> Sin(Complex<float> const& z) noexcept;
        [[nodiscard]] static Complex<double> Sin(Complex<double> const& z) noexcept;
        [[nodiscard]] static Complex<long double> Sin(Complex<long double> const& z) noexcept;
        [[nodiscard]] static PolarComplex<float> Sin(PolarComplex<float> const& z) noexcept;
        [[nodiscard]] static PolarComplex<double> Sin(PolarComplex<double> const& z) noexcept;
        [[nodiscard]] static PolarComplex<long double> Sin(PolarComplex<long double> const& z) noexcept;

        //sinh
        static float Sinh(float x) noexcept { return std::sinh(x); }
        static double Sinh(double x) noexcept { return std::sinh(x); }
        static long double Sinh(long double x) noexcept { return std::sinh(x); }

        //平方根
        static float Sqrt(float x) noexcept { return std::sqrt(x); }
        static double Sqrt(double x) noexcept { return std::sqrt(x); }
        static long double Sqrt(long double x) noexcept { return std::sqrt(x); }

        //tan
        static float Tan(float x) noexcept { return std::tan(x); }
        static double Tan(double x) noexcept { return std::tan(x); }
        static long double Tan(long double x) noexcept { return std::tan(x); }
        [[nodiscard]] static Complex<float> Tan(Complex<float> const& z) noexcept;
        [[nodiscard]] static Complex<double> Tan(Complex<double> const& z) noexcept;
        [[nodiscard]] static Complex<long double> Tan(Complex<long double> const& z) noexcept;
        [[nodiscard]] static PolarComplex<float> Tan(PolarComplex<float> const& z) noexcept;
        [[nodiscard]] static PolarComplex<double> Tan(PolarComplex<double> const& z) noexcept;
        [[nodiscard]] static PolarComplex<long double> Tan(PolarComplex<long double> const& z) noexcept;

        //tanh
        static float Tanh(float x) noexcept { return std::tanh(x); }
        static double Tanh(double x) noexcept { return std::tanh(x); }
        static long double Tanh(long double x) noexcept { return std::tanh(x); }


        private:

        template <NumberType Num>
        static constexpr Num _abs(Num value) noexcept { return value > (Num)0 ? value : -value; }

        template <NumberType FN>
        static constexpr FN _clamp(FN value, FN min, FN max)
        {
            if (min > max) [[unlikely]] throw ArgumentOutOfRangeException(u"'min' is larger than 'max'.");
            if (value < min) return min;
            if (value > max) return max;
            return value;
        }

        template <NumberType Num>
        static constexpr Div<Num> _divRem(Num left, Num right) { return right == (Num)0 ? throw DivideByZeroException() : Div<Num>(left / right, left % right); }

        template <NumberType Num>
        static Num _divRem(Num a, Num b, Num& result)
        {
            if (b == (Num)0) [[unlikely]] throw DivideByZeroException();

            result = a % b;

            return a / b;
        }

        template <std::integral I>
        static constexpr I _factorial(I x)
        {
            if (x < (I)0) [[unlikely]] throw ArithmeticException(u"A negative value was passed to 'x'.");
            I ret = (I)1;

            for (I n = (I)2; n < x; ++n) {
                ret *= n;
            }

            return ret;
        }

        template <NumberType Num>
        static constexpr Num _max(Num x, Num y) noexcept { return x > y ? x : y; }

        template <NumberType Num>
        static constexpr Num _min(Num x, Num y) noexcept { return x < y ? x : y; }

        template <std::floating_point F>
        static void _mod(F x, F& a, F& b) noexcept { b = std::modf(x, &a); }

        template <std::integral I>
        static constexpr I _pow(I x, I y) noexcept
        {
            if (y < (I)0) {
                if (x == (I)1) return (I)1;
                return (I)0;
            }

            I n = 1;
            for (I i = 0; i < y; ++i) {
                n *= x;
            }

            return n;
        }

        template <std::floating_point TFloat>
        static PolarComplex<TFloat> _pow(TFloat z1, PolarComplex<TFloat> const& z2) noexcept;

        template <std::integral I>
        static constexpr I _sigma(I x)
        {
            if (x < (I)0) [[unlikely]] throw ArithmeticException(u"A negative value was passed to 'x'.");
            return x * (x + 1) / 2;
        }

        template <NumberType Num>
        static constexpr ::KONGKONG_NAMESPACE::Numeric::Sign _sign(Num x) noexcept
        {
            if (x == (Num)0) return ::KONGKONG_NAMESPACE::Numeric::Sign::Zero;
            if (x > (Num)0) return ::KONGKONG_NAMESPACE::Numeric::Sign::Plus;
            return ::KONGKONG_NAMESPACE::Numeric::Sign::Minus;
        }

    };
}

#endif //!KONGKONG_NUMERIC_MATH_H
