#ifndef KONGKONG_ALGORITHMS_SUDOKU_SUDOKUELEMENT_H
#define KONGKONG_ALGORITHMS_SUDOKU_SUDOKUELEMENT_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Algorithms.Sudoku.SudokuNumber.h"

namespace KONGKONG_NAMESPACE::Algorithms::Sudoku
{
    struct SudokuElement final : public ValueType {

        static constexpr ssize_t HolderLength() noexcept { return 9; }

        SudokuElement() noexcept;
        explicit SudokuElement(SudokuNumber number);

        /// @brief 初期状態に戻す
        void Clear();

        /// @brief 正しい値を持っているかどうか
        [[nodiscard]]
        constexpr bool HasValidNumber() const noexcept { return SudokuNumber::Empty <= _value && _value <= SudokuNumber::Nine; }

        /// @brief valueがマスに入る可能性があるか
        /// @param value 確認したい数字
        [[nodiscard]]
        bool IsAcceptable(SudokuNumber number) const;

        /// @brief valueがマスに入る可能性があるか
        /// @param value 確認したい数字
        [[nodiscard]]
        bool IsAcceptableUnsafe(SudokuNumber number) const noexcept;

        /// @brief そのマスが埋まっているか
        [[nodiscard]]
        constexpr bool IsFilled() const noexcept { return _value != SudokuNumber::Empty; }

        /// @brief そのマスが初めから埋まっているか
        [[nodiscard]]
        constexpr bool IsPreFilled() const noexcept { return _isPreFilled; }

        /// @brief マスに数字を入れる
        /// @param value 入れる数字
        void Number(SudokuNumber value);

        /// @brief マスに入っている数字を取得
        [[nodiscard]]
        constexpr SudokuNumber Number() const noexcept { return _value; }

        /// @brief マスに入る可能性がある数字の変更
        /// @param number 対象の数字
        /// @param isAcceptable マスに入る可能性があるかどうか
        void SetAcceptable(SudokuNumber number, bool isAcceptable);

        /// @brief マスに入る可能性がある数字の変更
        /// @param number 対象の数字
        /// @param isAcceptable マスに入る可能性があるかどうか
        void SetAcceptableUnsafe(SudokuNumber number, bool isAcceptable) noexcept;

        /// @brief マスに数字を入れる
        /// @param value 入れる数字
        void SetNumberUnsafe(SudokuNumber value) noexcept;

        String ToString() const;

        
        private:
        static void _checkValue(SudokuNumber value);
        static constexpr short _defaultHolderValue = -1;

        SudokuNumber _value;

        bool _isPreFilled;

        short _candidateNumbersHolder;

    };
    
}

#endif //!KONGKONG_ALGORITHMS_SUDOKU_SUDOKUELEMENT_H
