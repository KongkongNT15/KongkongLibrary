#ifndef KONGKONG_ALGORITHMS_OTHELLO_OTHELLOFIELD_H
#define KONGKONG_ALGORITHMS_OTHELLO_OTHELLOFIELD_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Algorithms.Othello.OthelloValue.h"

namespace KONGKONG_NAMESPACE::Algorithms::Othello
{
    struct KONGKONG_INCOMPLETED_CLASS OthelloField final : public ValueType {

        /// @brief 横の長さ
        [[nodiscard]]
        static constexpr ssize_t ColumnLength() noexcept { return _columnLength; }

        /// @brief 縦の長さ
        [[nodiscard]]
        static constexpr ssize_t RowLength() noexcept { return _rowLength; }

        /// @brief 作成
        constexpr OthelloField() noexcept : _values{} { _setDefaultValues(); }

        /// @brief 指定した位置の情報を取得
        /// @param row 縦
        /// @param column 横
        /// @throws InvalidArgumentException: row, columnが負の値の時
        /// @throws ArgumentOutOfRangeException: 範囲外の場所を指定したとき
        [[nodiscard]]
        OthelloElement const& At(ssize_t row, ssize_t column) const;

        /// @brief 指定した位置の情報を取得
        /// @param row 縦
        /// @param column 横
        [[nodiscard]]
        constexpr OthelloElement const& AtUnsafe(ssize_t row, ssize_t column) const noexcept { return _values[row][column]; }

        /// @brief 黒の個数
        [[nodiscard]]
        constexpr ssize_t BlackCount() const noexcept { return _count(OthelloValue::Black); }

        /// @brief 初期状態に復元
        constexpr void Reset() noexcept;

        /// @brief 空白部分の個数
        [[nodiscard]]
        constexpr ssize_t SpaceCount() const noexcept { return _count(OthelloValue::None); }

        /// @brief フィールド
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき 
        [[nodiscard]]
        String ToString() const;

        /// @brief 白の個数
        [[nodiscard]]
        constexpr ssize_t WhiteCount() const noexcept { return _count(OthelloValue::White); }

        private:

        static constexpr ssize_t _columnLength = 8;
        static constexpr ssize_t _rowLength = 8;

        static void _checkColumn(ssize_t column);
        static void _checkRow(ssize_t row);

        constexpr void _setDefaultValues() noexcept;

        constexpr ssize_t _count(OthelloValue value) const noexcept;
        
        OthelloElement _values[_rowLength][_columnLength];
    };
}

namespace KONGKONG_NAMESPACE::Algorithms::Othello
{
    constexpr void OthelloField::Reset() noexcept
    {
        for (ssize_t i = 0; i < _rowLength; i++) {
            for (ssize_t j = 0; j < _columnLength; j++) {
                _values[i][j]._reset();
            }
        }
        _setDefaultValues();
    }

    constexpr ssize_t OthelloField::_count(OthelloValue value) const noexcept
    {
        ssize_t count = 0;

        for (ssize_t i = 0; i < _rowLength; i++) {
            for (ssize_t j = 0; j < _columnLength; j++) {
                if (_values[i][j]._value == value) count++;
            }
        }

        return count;
    }

    constexpr void OthelloField::_setDefaultValues() noexcept
    {
        _values[3][3]._value = OthelloValue::Black;
        _values[4][4]._value = OthelloValue::Black;
        _values[3][4]._value = OthelloValue::White;
        _values[4][3]._value = OthelloValue::White;
    }
}


#endif //!KONGKONG_ALGORITHMS_OTHELLO_OTHELLOFIELD_H
