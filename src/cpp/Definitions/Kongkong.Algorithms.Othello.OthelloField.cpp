//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Algorithms::Othello
{
    OthelloElement const& OthelloField::At(ssize_t row, ssize_t column) const
    {
        _checkRow(row);
        _checkColumn(column);

        return _values[row][column];
    }

    String OthelloField::ToString() const
    {

#ifdef KONGKONG_ENV_WINDOWS
        constexpr ssize_t length = 33 * 17 + 16 * 2;
#else
        constexpr ssize_t length = 33 * 17 + 16;
#endif

        constexpr ssize_t capacity = length + 1;

        constexpr char16_t line[] = u"+---+---+---+---+---+---+---+---+"

#ifdef KONGKONG_ENV_WINDOWS
            u"\r\n";
#else
            u"\n";
#endif

        String str = String::CreateWithCapacityUnsafe(capacity);
        
        str.AppendUnsafe(line);

        for (ssize_t row = 0; row < RowLength(); row++) {
            str.Append(u'|');
            
            for (ssize_t column = 0; column < ColumnLength(); column++) {
                str.Append(u' ');
                
                char16_t v;

                switch (_values[row][column]._value) {
                    case OthelloValue::None: v = u' '; break;
                    case OthelloValue::White: v = u'W'; break;
                    case OthelloValue::Black: v = u'B'; break;

                    default: [[unlikely]] v = u' '; break;
                }

                str.Append(v);

                str.AppendUnsafe(u" |");
            }

#ifdef KONGKONG_ENV_WINDOWS
            str.AppendUnsafe(u"\r\n");
#else
            str.Append(u'\n');
#endif
            if (row != RowLength() - 1) str.AppendUnsafe(line);
            else str.AppendUnsafe(u"+---+---+---+---+---+---+---+---+");
        }

        return str;
    }

    void OthelloField::_checkColumn(ssize_t column)
    {
        if (column < 0) [[unlikely]] throw InvalidArgumentException(u"横の座標にゼロ以下が指定されました");
        if (ColumnLength() <= column) [[unlikely]] throw ArgumentOutOfRangeException(u"横の座標が範囲外です");
    }

    void OthelloField::_checkRow(ssize_t row)
    {
        if (row < 0) [[unlikely]] throw InvalidArgumentException(u"縦の座標にゼロ以下が指定されました");
        if (RowLength() <= row) [[unlikely]] throw ArgumentOutOfRangeException(u"縦の座標が範囲外です");
    }
}
