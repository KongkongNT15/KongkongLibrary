//このcppファイルをコンパイルに含めないでください

namespace std
{
    ostream& operator<<(ostream& out, KONGKONG_NAMESPACE::Algorithms::Sudoku::SudokuNumber number)
    {
        using KONGKONG_NAMESPACE::Algorithms::Sudoku::SudokuNumber;

        if (number == SudokuNumber::Empty) {
            out << ' ';
        }
        else if (SudokuNumber::One <= number && number <= SudokuNumber::Nine) {
            out << ((char)number + '0');
        }
        else {
            out << "Unknown Sudoku Number";
        }

        return out;
    }
}
