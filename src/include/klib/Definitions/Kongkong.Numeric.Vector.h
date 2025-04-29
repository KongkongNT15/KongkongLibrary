#ifndef KONGKONG_NUMERIC_VECTOR_H
#define KONGKONG_NUMERIC_VECTOR_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.Collections.CollectionHelper.h"

namespace KONGKONG_NAMESPACE::Numeric
{
    //数学のベクトル
    template <NumberType Num, ssize_t N> requires (N > 0)
    struct Vector : public ValueType {

        using ElementType = Num;
        using ArrayType = Num(&)[N];
        using ConstArrayType = const Num(&)[N];

        static constexpr Vector<Num, N> Down() noexcept requires (N == 2) { return Vector<Num, N>{ (Num)0, (Num)-1 }; }
        static constexpr Vector<Num, N> Left() noexcept requires (N == 2) { return Vector<Num, N>{ (Num)-1, (Num)0 }; }
        static constexpr Vector<Num, N> NegativeInfinity() noexcept requires (N == 2) { return Vector<Num, N>{ std::numeric_limits<Num>::min(), std::numeric_limits<Num>::min() }; }
        static constexpr Vector<Num, N> One() noexcept requires (N == 2) { return Vector<Num, N>{ (Num)1, (Num)1 }; }
        static constexpr Vector<Num, N> PositiveInfinity() noexcept requires (N == 2) { return Vector<Num, N>{ std::numeric_limits<Num>::max(), std::numeric_limits<Num>::max() }; }
        static constexpr Vector<Num, N> Right() noexcept requires (N == 2) { return Vector<Num, N>{ (Num)1, (Num)0 }; }
        static constexpr Vector<Num, N> Up() noexcept requires (N == 2) { return Vector<Num, N>{ (Num)0, (Num)1 }; }
        static constexpr Vector<Num, N> Zero() noexcept requires (N == 2) { return Vector<Num, N>{ (Num)0, (Num)0 }; }

        static constexpr Vector<Num, N> Back() noexcept requires (N == 3) { return Vector<Num, N>{ (Num)0, (Num)0, (Num)-1 }; }
        static constexpr Vector<Num, N> Down() noexcept requires (N == 3) { return Vector<Num, N>{ (Num)0, (Num)-1, (Num)0 }; }
        static constexpr Vector<Num, N> Forward() noexcept requires (N == 3) { return Vector<Num, N>{ (Num)0, (Num)0, (Num)1 }; }
        static constexpr Vector<Num, N> Left() noexcept requires (N == 3) { return Vector<Num, N>{ (Num)-1, (Num)0, (Num)0 }; }
        static constexpr Vector<Num, N> NegativeInfinity() noexcept requires (N == 3) { return Vector<Num, N>{ std::numeric_limits<Num>::min(), std::numeric_limits<Num>::min(), std::numeric_limits<Num>::min() }; }
        static constexpr Vector<Num, N> One() noexcept requires (N == 3) { return Vector<Num, N>{ (Num)1, (Num)1, (Num)1 }; }
        static constexpr Vector<Num, N> PositiveInfinity() noexcept requires (N == 3) { return Vector<Num, N>{ std::numeric_limits<Num>::max(), std::numeric_limits<Num>::max(), std::numeric_limits<Num>::max() }; }
        static constexpr Vector<Num, N> Right() noexcept requires (N == 3) { return Vector<Num, N>{ (Num)1, (Num)0, (Num)0 }; }
        static constexpr Vector<Num, N> Up() noexcept requires (N == 3) { return Vector<Num, N>{ (Num)0, (Num)1, (Num)0 }; }
        static constexpr Vector<Num, N> Zero() noexcept requires (N == 3) { return Vector<Num, N>{ (Num)0, (Num)0, (Num)0 }; }

        /// @brief ベクトルの次元を取得
        static constexpr ssize_t Dimension() noexcept { return N; }

        /// @brief 全ての要素をゼロで作成
        constexpr Vector() noexcept : _arr{} {}

        /// @brief x座標のみを設定して作成
        /// @param x x座標
        constexpr Vector(Num x) noexcept : _arr{ x } {}

        /// @brief x, y座標を設定して作成
        /// @param x x座標
        /// @param y y座標
        /// @attention N >= 2が必要
        constexpr Vector(Num x, Num y) noexcept requires (N >= 2) : _arr{ x, y } {}
        constexpr Vector(Num x, Num y, Num z) noexcept requires (N >= 3) : _arr{ x, y, z } {}

        template <class... Args>
        constexpr Vector(Args&&... args) noexcept requires (N >= 4 && sizeof...(Args) >= 4 && N >= sizeof...(Args)) : _arr{ ::std::forward<Args>(args)... } {}

        template <class NumFrom>
        Vector(Vector<NumFrom, N> const& right) noexcept requires (!::std::is_same_v<Num, NumFrom>) { _copy(right); }

        [[nodiscard]] constexpr Num* begin() noexcept { return _arr; }
        [[nodiscard]] constexpr const Num* begin() const noexcept { return _arr; }
        [[nodiscard]] constexpr Num* end() noexcept { return _arr + N; }
        [[nodiscard]] constexpr const Num* end() const noexcept { return _arr + N; }
        
        //thisの変更
        constexpr Vector<Num, N>& operator+=(Vector<Num, N> const& right) noexcept
        {
            auto p = _arr;
            auto pRight = right._arr;
            auto e = p + N;

            while (p != e) {
                *p += *pRight;
                ++p;
                ++pRight;
            }

            return *this;
        }

        //thisの変更
        constexpr Vector<Num, N>& operator-=(Vector<Num, N> const& right) noexcept
        {
            auto p = _arr;
            auto pRight = right._arr;
            auto e = p + N;

            while (p != e) {
                *p -= *pRight;
                ++p;
                ++pRight;
            }

            return *this;
        }

        //thisの変更
        constexpr Vector<Num, N>& operator*=(Vector<Num, N> const& right) noexcept
        {
            auto p = _arr;
            auto pRight = right._arr;
            auto e = p + N;

            while (p != e) {
                *p *= *pRight;
                ++p;
                ++pRight;
            }

            return *this;
        }

        //thisの変更
        constexpr Vector<Num, N>& operator*=(Num right) noexcept
        {
            for (Num& v : _arr) {
                v *= right;
            }

            return *this;
        }

        //thisの変更
        Vector<Num, N>& operator/=(Num right)
        {
            for (Num& v : _arr) {
                v /= right;
            }

            return *this;
        }

        //ベクトル同士の演算
        friend Vector<Num, N> operator+(Vector<Num, N> const& left, Vector<Num, N> const& right) noexcept
        {
            Vector<Num, N> vec;

            for (ssize_t i = 0; i < N; ++i) {
                vec[i] = left[i] + right[i];
            }

            return vec;
        }
        friend Vector<Num, N> operator+(Vector<Num, N>&& left, Vector<Num, N> const& right) noexcept
        {
            for (ssize_t i = 0; i < N; ++i) {
                left[i] += right[i];
            }

            return left;
        }
        friend Vector<Num, N> operator+(Vector<Num, N> const& left, Vector<Num, N>&& right) noexcept { return std::move(right) + left; }
        friend Vector<Num, N> operator+(Vector<Num, N>&& left, Vector<Num, N>&& right) noexcept { return std::move(right) + left; }
        friend Vector<Num, N> operator-(Vector<Num, N> const& left, Vector<Num, N> const& right) noexcept
        {
            Vector<Num, N> vec;

            for (ssize_t i = 0; i < N; ++i) {
                vec[i] = left[i] - right[i];
            }

            return vec;
        }
        friend Vector<Num, N> operator-(Vector<Num, N>&& left, Vector<Num, N> const& right) noexcept
        {
            for (ssize_t i = 0; i < N; ++i) {
                left[i] -= right[i];
            }

            return left;
        }
        friend Vector<Num, N> operator-(Vector<Num, N> const& left, Vector<Num, N>&& right) noexcept { return std::move(right) - left; }
        friend Vector<Num, N> operator-(Vector<Num, N>&& left, Vector<Num, N>&& right) noexcept { return std::move(right) - left; }

        //ベクトルと数値の演算
        friend Vector<Num, N> operator*(Vector<Num, N> const& left, Vector<Num, N> const& right) noexcept
        {
            Vector<Num, N> vec;

            for (ssize_t i = 0; i < N; ++i) {
                vec[i] = left[i] * right[i];
            }

            return vec;
        }
        friend Vector<Num, N> operator*(Vector<Num, N>&& left, Vector<Num, N> const& right) noexcept
        {
            for (ssize_t i = 0; i < N; ++i) {
                left[i] *= right[i];
            }

            return left;
        }
        friend Vector<Num, N> operator*(Vector<Num, N> const& left, Vector<Num, N>&& right) noexcept { return std::move(right) * left; }
        friend Vector<Num, N> operator*(Vector<Num, N>&& left, Vector<Num, N>&& right) noexcept { return std::move(right) * left; }
        friend Vector<Num, N> operator*(Vector<Num, N> const& left, Num right) noexcept
        {
            Vector<Num, N> vec;

            for (ssize_t i = 0; i < N; ++i) {
                vec[i] = left[i] * right;
            }

            return vec;
        }
        friend Vector<Num, N> operator*(Vector<Num, N>&& left, Num right) noexcept
        {
            for (ssize_t i = 0; i < N; ++i) {
                left[i] *= right;
            }

            return left;
        }
        friend Vector<Num, N> operator*(Num left, Vector<Num, N> const& right) noexcept { return right * left; }
        friend Vector<Num, N> operator*(Num left, Vector<Num, N>&& right) noexcept { return std::move(right) * left; }
        friend Vector<Num, N> operator/(Vector<Num, N> const& left, Num right)
        {
            Vector<Num, N> vec;

            for (ssize_t i = 0; i < N; ++i) {
                vec[i] = left[i] / right;
            }

            return vec;
        }
        friend Vector<Num, N> operator/(Vector<Num, N>&& left, Num right)
        {
            for (ssize_t i = 0; i < N; ++i) {
                left[i] /= right;
            }

            return left;
        }
        friend Vector<Num, N> operator/(Num left, Vector<Num, N> const& right) { return right / left; }
        friend Vector<Num, N> operator/(Num left, Vector<Num, N>&& right) { return std::move(right) / left; }
        

        //等値判定
        friend bool operator==(Vector<Num, N> const& left, Vector<Num, N> const& right) noexcept
        {
            for (ssize_t i = 0; i < N; ++i) {
                if (left[i] != right[i]) return false;
            }
            return true;
        }
        friend bool operator!=(Vector<Num, N> const& left, Vector<Num, N> const& right) noexcept { return !(left == right); }

        //要素にアクセス
        [[nodiscard]] constexpr Num& operator[](ssize_t index) noexcept { return this->_arr[index]; }
        [[nodiscard]] constexpr Num const& operator[](ssize_t index) const noexcept { return this->_arr[index]; }

        //要素の肩を返還
        template <class NumFrom> //requires !(std::derived_from<NumFrom, Num>)
        Vector<Num, N>& operator=(Vector<NumFrom, N> const& right) noexcept
        {
            _copy(right);
            return *this;
        }

        /// @brief 関数 TNum func(TNum v) を各要素に適用
        /// @param func 関数ポインタ
        void ApplyToAll(Num(*func)(Num))
        {
            for (Num& value : _arr) {
                value = func(value);
            }
        }

        /// @brief 関数 void func(TNum& v) を各要素に適用
        /// @param func 関数ポインタ
        void ApplyToAll(void(*func)(Num&))
        {
            for (Num& value : _arr) {
                func(value);
            }
        }

        /// @brief 配列への参照
        [[nodiscard]]
        constexpr ArrayType Array() noexcept { return _arr; }

        /// @brief 配列への参照
        [[nodiscard]]
        constexpr ConstArrayType Array() const noexcept { return _arr; }

        template <NumberType UNum>
        [[nodiscard]] constexpr Vector<UNum, N> As() const noexcept
        {
            if constexpr (::std::is_same_v<Num, UNum>) return *this;
            else {
                Vector<UNum, N> vec;

                auto p = vec.begin();
                auto e = p + N;
                auto pThis = _arr;

                while (p != e) {
                    *p = (UNum)*pThis;
                    ++p;
                    ++pThis;
                }

                return vec;
            }
#if KONGKONG_HAS_CPP23
            ::std::unreachable();
#endif
        }

        /// @brief 指定した要素番号の値を取得
        /// @param index 要素番号
        /// @throws OutOfRangeException: 要素番号が範囲外の時
        [[nodiscard]]
        Num& At(ssize_t index)
        {
            Collections::CollectionHelper::CheckIndex(index, N);
            return this->_arr[index];
        }

        /// @brief 指定した要素番号の値を取得
        /// @param index 要素番号
        /// @throws OutOfRangeException: 要素番号が範囲外の時
        [[nodiscard]]
        Num const& At(ssize_t index) const
        {
            Collections::CollectionHelper::CheckIndex(index, N);
            return this->_arr[index];
        }

        /// @brief 平均値を取得
        [[nodiscard]] 
        constexpr Num Average() const noexcept requires std::floating_point<Num>
        {
            return Sum() / N;
        }

        /// @brief 平均値を取得
        [[nodiscard]]
        constexpr double Average() const noexcept requires std::integral<Num>
        {
            return (double)Sum() / N;
        }

        /// @brief 配列へのポインターを取得
        [[nodiscard]]
        constexpr Num* Data() noexcept { return _arr; }

        /// @brief 配列へのポインターを取得
        [[nodiscard]]
        constexpr const Num* Data() const noexcept { return _arr; }

        /// @brief 全ての要素を指定した値で埋める
        /// @param value 値
        constexpr void Fill(Num value) noexcept
        {
            for (Num& n : _arr) {
                n = value;
            }
        }

        template <ssize_t NIndex>
        [[nodiscard]] constexpr Num& GetAt() noexcept requires (0 <= NIndex && NIndex < N) { return _arr[NIndex]; }

        template <ssize_t NIndex>
        [[nodiscard]] constexpr Num const& GetAt() const noexcept requires (0 <= NIndex && NIndex < N) { return _arr[NIndex]; }


        /// @brief ベクトルの長さを取得
        [[nodiscard]]
        constexpr Num Length() const noexcept requires std::floating_point<Num> { return (Num)std::sqrt(SquareMagnitude()); }
        
        /// @brief ベクトルの長さを取得
        [[nodiscard]]
        constexpr double Length() const noexcept requires std::integral<Num> { return (Num)std::sqrt((double)SquareMagnitude()); }

        /// @brief 正規化したベクトルを取得
        /// @attention ElementTypeが浮動小数点数型のみ使用可能
        constexpr Vector<Num, N> Normalized() const noexcept requires std::floating_point<Num>
        {
            auto length = Length();

            switch (length) {
                case 0.0: [[unlikely]]
                {
                    Vector ret;

                    for (Num& v : ret) v = 1.0 / N;

                    return ret;
                }
                case 1.0: [[unlikely]] return *this;

                default: [[likely]]
                {
                    Vector ret;
                    for (ssize_t i = 0; i < N; ++i) {
                        ret[i] = _arr[i] / length;
                    }
                    return ret;
                }
                
            }

#if KONGKONG_HAS_CPP23
            ::std::unreachable();
#endif
        }

        /// @brief ベクトルの長さの2乗を取得
        [[nodiscard]]
        constexpr Num SquareMagnitude() const noexcept
        {
            Num ret{};

            for (Num v : *this) {
                ret += v * v;
            }

            return ret;
        }

        /// @brief 要素の合計値を取得
        constexpr Num Sum() const noexcept
        {
            Num result{};

            for (Num const& n : _arr) {
                result += n;
            }

            return result;
        }

        /// @brief 座標を出力
        [[nodiscard]]
        String ToString() const
        {
            std::ostringstream wsout;

            for (ssize_t i = 0; i < N; ++i) {
                wsout << _arr[i];

                if (i == N - 1) wsout << ' ';
                else wsout << ", ";
            }

            return String::FromAscii(wsout.str());
        }

        /// @brief 2次元ベクトルに変換
        [[nodiscard]]
        constexpr Vector2<Num> ToVector2() const noexcept
        {
            Vector2<Num> vec;

            ssize_t size;

            if constexpr (N < Vector2<Num>::Dimension()) {
                size = N;
            }
            else {
                size = Vector2<Num>::Dimension();
            }

            for (ssize_t i = 0; i < size; i++) {
                vec[i] = this->_arr[i];
            }

            return vec;
        }

        /// @brief 3次元ベクトルに変換
        [[nodiscard]]
        constexpr Vector3<Num> ToVector3() const noexcept
        {
            Vector3<Num> vec;

            ssize_t size;

            if constexpr (N < Vector3<Num>::Dimension()) {
                size = N;
            }
            else {
                size = Vector3<Num>::Dimension();
            }

            for (ssize_t i = 0; i < size; i++) {
                vec[i] = this->_arr[i];
            }

            return vec;
        }

        constexpr void X(Num value) noexcept { _arr[0] = value; }
        [[nodiscard]] constexpr Num& X() noexcept { return this->_arr[0]; }
        [[nodiscard]] constexpr Num const& X() const noexcept { return this->_arr[0]; }

        constexpr void Y(Num value) noexcept requires (N >= 2) { _arr[1] = value; }
        [[nodiscard]] constexpr Num& Y() noexcept requires (N >= 2) { return this->_arr[1]; }
        [[nodiscard]] constexpr Num const& Y() const noexcept requires (N >= 2) { return this->_arr[1]; }

        constexpr void Z(Num value) noexcept requires (N >= 3) { _arr[2] = value; }
        [[nodiscard]] constexpr Num& Z() noexcept requires (N >= 3) { return this->_arr[2]; }
        [[nodiscard]] constexpr Num const& Z() const noexcept requires (N >= 3) { return this->_arr[2]; }

        protected:
        Num _arr[N];

        private:

        //要素の肩を返還
        template <class NumFrom>
        void _copy(Vector<NumFrom, N> const& right) noexcept
        {
            for (ssize_t i = 0; i < N; ++i) {
                this->_arr[i] = (Num)right[i];
            }
        }
    };
}

#endif //!KONGKONG_NUMERIC_VECTOR_H
