#ifndef KONGKONG_ALGORITHMS_SUDOKU_SUDOKUFIELD_H
#define KONGKONG_ALGORITHMS_SUDOKU_SUDOKUFIELD_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Algorithms.Sudoku.SudokuElement.h"
#include "Kongkong.Algorithms.Sudoku.SudokuNumber.h"

namespace KONGKONG_NAMESPACE::Algorithms::Sudoku
{
    struct KONGKONG_INCOMPLETED_CLASS SudokuField final : public ValueType {

        [[nodiscard]] static constexpr ssize_t ColumnLength() noexcept { return 9; }
        [[nodiscard]] static constexpr ssize_t LowLength() noexcept { return 9; }

        [[nodiscard]] static constexpr ssize_t BlockColumnLength() noexcept { return 3; }
        [[nodiscard]] static constexpr ssize_t BlockLowLength() noexcept { return 3; }

        SudokuField() noexcept;

        [[nodiscard]] constexpr SudokuElement* begin() noexcept { return Data(); }
        [[nodiscard]] constexpr const SudokuElement* begin() const noexcept { return Data(); }
        [[nodiscard]] constexpr SudokuElement* end() noexcept { return Data() + LowLength() * ColumnLength(); }
        [[nodiscard]] constexpr const SudokuElement* end() const noexcept { return Data() + LowLength() * ColumnLength(); }

        [[nodiscard]]
        SudokuElement& At(ssize_t low, ssize_t column);

        [[nodiscard]]
        SudokuElement const& At(ssize_t low, ssize_t column) const;

        [[nodiscard]]
        constexpr SudokuElement& AtUnsafe(ssize_t low, ssize_t column) noexcept { return _elements[low][column]; }

        [[nodiscard]]
        constexpr SudokuElement const& AtUnsafe(ssize_t low, ssize_t column) const noexcept { return _elements[low][column]; }

        void Clear();

        [[nodiscard]] constexpr SudokuElement* Data() noexcept { return &_elements[0][0]; }
        [[nodiscard]] constexpr const SudokuElement* Data() const noexcept { return &_elements[0][0]; }

        [[nodiscard]]
        bool HasValidFormat() const noexcept;

        [[nodiscard]]
        bool IsFull() const noexcept;

        [[nodiscard]]
        constexpr unsigned PrimoLevel() const noexcept { return _primoLevel; }

        String ToDetailString() const;
        String ToString() const;

        bool Run();

        private:
        static void _checkIndex(ssize_t index);

        static constexpr size_t _fieldLength = 9;

        SudokuElement _elements[_fieldLength][_fieldLength];

        unsigned _primoLevel;

        //SudokuElementに同じ機能を実装済み
        //void _narrow0() noexcept;

        /// @brief 
        void _narrow1() noexcept;

        /// @brief 
        void _narrow2() noexcept;

        /// @brief 
        void _narrow3() noexcept;
    };
    
}

#endif //!KONGKONG_ALGORITHMS_SUDOKU_SUDOKUFIELD_H
