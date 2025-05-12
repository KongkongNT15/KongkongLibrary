#ifndef KONGKONG_NUMERIC_MATRIX_H
#define KONGKONG_NUMERIC_MATRIX_H

#include "Base.h"
#include "Kongkong.ArithmeticException.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"

namespace KONGKONG_NAMESPACE::Numeric
{
    //行列
    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    struct Matrix : public ValueType {

        Matrix() = default; 

        template <class... Args>
        constexpr Matrix(Args&&... args) noexcept : _arr{ ::std::forward<Args>(args)... } {}

        Matrix& operator+=(Matrix const& right) noexcept
        {
            auto pLeft = begin();
            auto pRight = right.begin();

            for (ssize_t i = 0; i != NRow * NColumn; i++) {
                pLeft[i] += pRight[i];
            }
            return *this;
        }

        Matrix& operator-=(Matrix const& right) noexcept
        {
            auto pLeft = begin();
            auto pRight = right.begin();

            for (ssize_t i = 0; i != NRow * NColumn; i++) {
                pLeft[i] -= pRight[i];
            }
            return *this;
        }

        Matrix& operator*=(TNum value) noexcept
        {
            for (TNum& v : *this) v *= value;

            return *this;
        }

        Matrix& operator*=(Matrix<TNum, NColumn, NColumn> const& right) noexcept;

        [[nodiscard]] constexpr TNum* operator[](ssize_t index) noexcept { return _arr[index]; }
        [[nodiscard]] constexpr const TNum* operator[](ssize_t index) const noexcept { return _arr[index]; }

        [[nodiscard]] constexpr TNum* begin() noexcept { return _arr[0]; }
        [[nodiscard]] constexpr const TNum* begin() const noexcept { return _arr[0]; }
        [[nodiscard]] constexpr TNum* end() noexcept { return _arr[0] + NRow * NColumn; }
        [[nodiscard]] constexpr const TNum* end() const noexcept { return _arr[0] + NRow * NColumn; }

        template <NumberType UNum>
        [[nodiscard]] Matrix<UNum, NRow, NColumn> As() const noexcept
        {
            if constexpr (::std::same_as<UNum, TNum>) return *this;
            else {
                Matrix<UNum, NRow, NColumn> result;
                auto pResult = result.begin();
                auto pThis = begin();

                for (ssize_t i = 0; i != NRow * NColumn; i++) {
                    result[i] = (UNum)pThis[i];
                }

                return result;
            }

#if KONGKONG_HAS_CPP23
            ::std::unreachable();
#endif
        }

        /// @brief 列の長さ
        [[nodiscard]]
        constexpr ssize_t Column() const noexcept { return NColumn; }

        void Fill(TNum value) noexcept
        {
            for (TNum& v : *this) v = value;
        }

        [[nodiscard]]
        constexpr bool IsSquare() const noexcept { return NRow == NColumn; }

        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return NRow * NColumn; }

        /// @brief 行の長さ
        [[nodiscard]]
        constexpr ssize_t Row() const noexcept { return NRow; }

        private:
        TNum _arr[NRow][NColumn];
    };

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator+(Matrix<TNum, NRow, NColumn> const& left, Matrix<TNum, NRow, NColumn> const& right) noexcept
    {
        Matrix<TNum, NRow, NColumn> result;
        auto pResult = result.begin();
        auto pLeft = left.begin();
        auto pRight = right.begin();

        for (ssize_t i = 0; i != NRow * NColumn; i++) {
            pResult[i] = pLeft[i] + pRight[i];
        }

        return result;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator+(Matrix<TNum, NRow, NColumn>&& left, Matrix<TNum, NRow, NColumn> const& right) noexcept
    {
        auto pLeft = left.begin();
        auto pRight = right.begin();

        for (ssize_t i = 0; i != NRow * NColumn; i++) {
            pLeft[i] += pRight[i];
        }

        return left;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator+(Matrix<TNum, NRow, NColumn> const& left, Matrix<TNum, NRow, NColumn>&& right) noexcept
    {
        return std::move(right) + left;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator-(Matrix<TNum, NRow, NColumn> const& left, Matrix<TNum, NRow, NColumn> const& right) noexcept
    {
        Matrix<TNum, NRow, NColumn> result;
        auto pResult = result.begin();
        auto pLeft = left.begin();
        auto pRight = right.begin();

        for (ssize_t i = 0; i != NRow * NColumn; i++) {
            pResult[i] = pLeft[i] - pRight[i];
        }

        return result;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator-(Matrix<TNum, NRow, NColumn>&& left, Matrix<TNum, NRow, NColumn> const& right) noexcept
    {
        auto pLeft = left.begin();
        auto pRight = right.begin();

        for (ssize_t i = 0; i != NRow * NColumn; i++) {
            pLeft[i] -= pRight[i];
        }

        return left;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator-(Matrix<TNum, NRow, NColumn> const& left, Matrix<TNum, NRow, NColumn>&& right) noexcept
    {
        auto pLeft = left.begin();
        auto pRight = right.begin();

        for (ssize_t i = 0; i != NRow * NColumn; i++) {
            pRight[i] = pLeft[i] - pRight[i];
        }

        return right;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator*(Matrix<TNum, NRow, NColumn> const& left, TNum right) noexcept
    {
        Matrix<TNum, NRow, NColumn> result;
        auto pResult = result.begin();
        auto pLeft = left.begin();

        for (ssize_t i = 0; i != NRow * NColumn; i++) {
            pResult[i] = pLeft[i] * right;
        }

        return result;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator*(Matrix<TNum, NRow, NColumn>&& left, TNum right) noexcept
    {
        for (TNum& v : left) v *= right;

        return left;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator*(TNum left, Matrix<TNum, NRow, NColumn> const& right) noexcept
    {
        return right * left;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    [[nodiscard]] Matrix<TNum, NRow, NColumn> operator*(TNum left, Matrix<TNum, NRow, NColumn>&& right) noexcept
    {
        return std::move(right) * left;
    }

    template <NumberType TNum, ssize_t N1, ssize_t N2, ssize_t N3> requires (N1 >= 1 && N2 >= 1 && N3 >= 1)
    [[nodiscard]] Matrix<TNum, N1, N3> operator*(Matrix<TNum, N1, N2> const& left, Matrix<TNum, N2, N3> const& right) noexcept
    {
        Matrix<TNum, N1, N3> result;

        for (ssize_t i = 0; i < N1; ++i) {
            for (ssize_t j = 0; j < N3; ++j) {
                TNum value{};
                for (ssize_t k = 0; k < N2; ++k) {
                    value += left[i][k] * right[k][j];
                }
                result[i][j] = value;
            }
        }

        return result;
    }

    template <NumberType TNum, ssize_t NRow, ssize_t NColumn> requires (NRow >= 1 && NColumn >= 1)
    Matrix<TNum, NRow, NColumn>& Matrix<TNum, NRow, NColumn>::operator*=(Matrix<TNum, NColumn, NColumn> const& right) noexcept
    {
        return *this = (*this * right);
    }

}

#endif //!KONGKONG_NUMERIC_MATRIX_H
