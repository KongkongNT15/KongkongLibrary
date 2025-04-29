//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Algorithms::Sudoku
{
    SudokuElement::SudokuElement() noexcept :
        _value(SudokuNumber::Empty),
        _isPreFilled(false),
        _candidateNumbersHolder(_defaultHolderValue)
    {
    }

    SudokuElement::SudokuElement(SudokuNumber number) :
        _value(number),
        _isPreFilled(true),
        _candidateNumbersHolder(0)
    {
        _checkValue(number);

        if (number == SudokuNumber::Empty) [[unlikely]] {
            _isPreFilled = false;
            _candidateNumbersHolder = _defaultHolderValue;
        }
    }

    void SudokuElement::Clear()
    {
        _value = SudokuNumber::Empty;
        _isPreFilled = false;
        _candidateNumbersHolder = _defaultHolderValue;
    }

    bool SudokuElement::IsAcceptable(SudokuNumber number) const
    {
        _checkValue(number);

        return IsAcceptableUnsafe(number);
    }

    bool SudokuElement::IsAcceptableUnsafe(SudokuNumber number) const noexcept
    {
        short v = 1 << ((int)number - 1);
        return (bool)(v & _candidateNumbersHolder);
    }

    void SudokuElement::SetAcceptable(SudokuNumber number, bool isAcceptable)
    {
        _checkValue(number);

        if (IsFilled()) [[unlikely]] throw InvalidOperationException(u"すでに値が入っています");

        SetAcceptableUnsafe(number, isAcceptable);
    }

    void SudokuElement::SetAcceptableUnsafe(SudokuNumber number, bool isAcceptable) noexcept
    {
        short v;

        if (isAcceptable) {
            v = 1 << ((int)number - 1);
            _candidateNumbersHolder |= v;
        }
        else {
            v = (short)~(1 << ((int)7 - 1));
            _candidateNumbersHolder &= v;
        }
    }

    void SudokuElement::SetNumberUnsafe(SudokuNumber value) noexcept
    {
        if (value == SudokuNumber::Empty && _value != SudokuNumber::Empty) [[unlikely]] _candidateNumbersHolder = _defaultHolderValue;

        _value = value;
    }

    void SudokuElement::Number(SudokuNumber value)
    {
        _checkValue(value);

        SetNumberUnsafe(value);
    }

    String SudokuElement::ToString() const
    {
        return u"KONGKONG_NAMESPACE::Numeric::Sudoku::SudokuElement";
    }

    void SudokuElement::_checkValue(SudokuNumber value)
    {
        if (value > SudokuNumber::Nine) [[unlikely]] throw InvalidArgumentException(u"SudokuNumberの値が無効です");
    }
    
}
