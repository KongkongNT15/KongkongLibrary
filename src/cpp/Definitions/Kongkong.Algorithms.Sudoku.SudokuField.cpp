//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Algorithms::Sudoku
{

    SudokuElement& SudokuField::At(ssize_t low, ssize_t column)
    {
        _checkIndex(low);
        _checkIndex(column);

        return _elements[low][column];
    }

    SudokuElement const& SudokuField::At(ssize_t low, ssize_t column) const
    {
        _checkIndex(low);
        _checkIndex(column);

        return _elements[low][column];
    }

    SudokuField::SudokuField() noexcept :
        _elements{},
        _primoLevel(0)
    {
    }

    void SudokuField::Clear()
    {
        for (SudokuElement& element : *this) {
            element.Clear();
        }
    }

    bool SudokuField::IsFull() const noexcept
    {
        for (SudokuElement const& element : *this) {
            if (!element.IsFilled()) return false;
        }

        return true;
    }

    bool SudokuField::HasValidFormat() const noexcept
    {
        for (SudokuElement const& element : *this) {
            if (!element.HasValidNumber()) return false;
        }

        std::array<bool, 9> arr;
        ssize_t low, column, low3, column3;

        //横方向に同じ数字がないかを確認
        for (low = 0; low < LowLength(); low++) {
            arr.fill(false);

            for (column = 0; column < ColumnLength(); column++) {
                ssize_t index = (ssize_t)_elements[low][column].Number() - 1;

                if (index == -1) continue;

                if (arr[index] == true) return false;
                arr[index] = true;
            }
        }

        //縦方向に同じ数字がないかを確認
        for (column = 0; column < ColumnLength(); column++) {
            arr.fill(false);

            for (low = 0; low < ColumnLength(); low++) {
                ssize_t index = (ssize_t)_elements[low][column].Number() - 1;

                if (index == -1) continue;

                if (arr[index] == true) return false;
                arr[index] = true;
            }
        }

        //3 * 3のブロックに同じ数字がないかを確認
        for (low3 = 0; low3 < 3; low3++) {
            for (column3 = 0; column3 < 3; column3++) {
                arr.fill(false);

                for (low = 0; low < 3; low++) {
                    for (column = 0; column < 3; column++) {
                        ssize_t index = (ssize_t)_elements[3 * low3 + low][3 * column3 + column].Number() - 1;
                    
                        if (index == -1) continue;

                        if (arr[index] == true) return false;
                        arr[index] = true;
                    }
                }

            }
        }

        return true;
    }

    String SudokuField::ToString() const
    {
        constexpr char16_t yokobou1[] = 
#ifdef KONGKONG_ENV_WINDOWS
            u"+++---+---+---+++---+---+---+++---+---+---+++\r\n";
#else
            u"+++---+---+---+++---+---+---+++---+---+---+++\n";
#endif

        constexpr char16_t yokobou2[] = 
#ifdef KONGKONG_ENV_WINDOWS
            u"+++ - + - + - +++ - + - + - +++ - + - + - +++\r\n";
#else
            u"+++ - + - + - +++ - + - + - +++ - + - + - +++\n";
#endif
        std::u16string result;

        for (ssize_t low = 0; low < LowLength(); low++) {

            if (low % 3 == 0) {
                result.append(yokobou1);
                result.append(yokobou1);
            }
            else {
                result.append(yokobou2);
            }

            for (ssize_t column = 0; column < ColumnLength(); column++) {

                if (column % 3 == 0) result.append(u"||| ");
                else result.append(u"| ");

                SudokuNumber number = _elements[low][column].Number();

                if (number == SudokuNumber::Empty) result.append(u"  ");
                else {
                    result.push_back((char16_t)number + u'0');
                    result.push_back(u' ');
                }
            }
#ifdef KONGKONG_ENV_WINDOWS
            result.append(u"|||\r\n");
#else
            result.append(u"|||\n");
#endif
        }

        result.append(yokobou1);
        result.append(yokobou1);

        //末尾の\nを削除
        result.pop_back();

        return result;
    }

    void SudokuField::_checkIndex(ssize_t index)
    {
        if (index < 0 || 9 <= index) [[unlikely]] throw InvalidArgumentException(u"フィールドの範囲外の要素を指定しました");
    }

    void SudokuField::_narrow1() noexcept
    {
        ssize_t i, j;
        
        for (ssize_t low = 0; low < LowLength(); low++) {
            for (ssize_t column = 0; column < ColumnLength(); column++) {

                SudokuElement& e = _elements[low][column];

                if (e.IsFilled()) {
                    for (i = 0; i < SudokuElement::HolderLength(); i++) {

                        _elements[low][i].SetAcceptableUnsafe(e.Number(), false);
                        _elements[i][column].SetAcceptableUnsafe(e.Number(), false);
                    }
                    for (i = (low / BlockLowLength()) * BlockLowLength(); i < (low / BlockLowLength() + 1) * BlockLowLength(); i++) {
                        for (j = (column / BlockColumnLength()) * BlockColumnLength(); j < (column / BlockColumnLength() + 1) * BlockColumnLength(); j++) {
                            _elements[i][j].SetAcceptableUnsafe(e.Number(), false);
                        }
                    }
                }
            }
        }

    }

    void SudokuField::_narrow2() noexcept
    {
        ssize_t y3, x3, y1, x1, Y;
        bool error;
        bool ari;
        for (SudokuNumber num = SudokuNumber::One; num < SudokuNumber::End; num = (SudokuNumber)((int)num + 1)) {
            for (y3 = 0; y3 < LowLength(); y3 += BlockLowLength()) {
                for (x3 = 0; x3 < ColumnLength(); x3 += BlockColumnLength()) {
                    error = false;
                    Y = 0;
                    int z[3]{ -1, -1, -1 };
                    ari = false;
                    for (y1 = y3; y1 < y3 + BlockLowLength(); y1++) {
                        for (x1 = x3; x1 < x3 + BlockColumnLength(); x1++) {
                            if (_elements[y1][x1].IsAcceptableUnsafe(num)) {
                                if (ari) {
                                    if (y1 != Y) {
                                        error = true;
                                        break;
                                    }
                                    else {
                                        if (z[1] == -1) {
                                            z[1] = (int)x1;
                                        }
                                        else {
                                            z[2] = (int)x1;
                                        }
                                    }
                                }
                                else {
                                    ari = true;
                                    Y = y1;
                                    z[0] = (int)x1;
                                }
                            }
                        }
                        if (error) {
                            break;
                        }
                    }
                    if ((error == false && ari) && z[1] != -1) {
                        for (x1 = 0; x1 < ColumnLength(); x1++) {
                            if ((x1 != z[0] && x1 != z[1]) && x1 != z[2]) {
                                _elements[Y][x1].SetAcceptableUnsafe(num, false);
                            }
                        }
                    }
                }
            }
        }

    }

    void SudokuField::_narrow3() noexcept
    {
        ssize_t x3, y3, x1, y1, X;
        bool error;
        bool ari;
        for (SudokuNumber num = SudokuNumber::One; num < SudokuNumber::End; num = (SudokuNumber)((int)num + 1)) {
            for (x3 = 0; x3 < ColumnLength(); x3 += BlockColumnLength()) {
                for (y3 = 0; y3 < LowLength(); y3 += BlockLowLength()) {
                    error = false;
                    X = 0;
                    int z[3]{ -1, -1, -1 };
                    ari = false;
                    for (x1 = x3; x1 < x3 + BlockColumnLength(); x1++) {
                        for (y1 = y3; y1 < y3 + BlockLowLength(); y1++) {
                            if (_elements[y1][x1].IsAcceptableUnsafe(num)) {
                                if (ari) {
                                    if (x1 != X) {
                                        error = true;
                                        break;
                                    }
                                    else {
                                        if (z[1] == -1) {
                                            z[1] = (int)y1;
                                        }
                                        else {
                                            z[2] = (int)y1;
                                        }
                                    }
                                }
                                else {
                                    ari = true;
                                    X = x1;
                                    z[0] = (int)y1;
                                }
                            }
                        }
                        if (error) {
                            break;
                        }
                    }
                    if ((error == false && ari) && z[1] != -1) {
                        for (y1 = 0; y1 < LowLength(); y1++) {
                            if ((y1 != z[0] && y1 != z[1]) && y1 != z[2]) {
                                _elements[y1][X].SetAcceptableUnsafe(num, false);
                            }
                        }
                    }
                }
            }
        }

    }

}
