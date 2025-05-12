#ifndef KONGKONG_ALGORITHMS_SUDOKU_SUDOKUNUMBER_H
#define KONGKONG_ALGORITHMS_SUDOKU_SUDOKUNUMBER_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Algorithms::Sudoku
{
    enum struct SudokuNumber : uint8_t {
        Empty = 0,
        One   = 1,
        Two   = 2,
        Three = 3,
        Four  = 4,
        Five  = 5,
        Six   = 6,
        Seven = 7,
        Eight = 8,
        Nine  = 9,

        Min   = One,
        Max   = Nine,

        Begin = One,
        End = Nine + 1,
    };

}

#endif //!KONGKONG_ALGORITHMS_SUDOKU_SUDOKUNUMBER_H
