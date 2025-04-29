//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Numeric
{
    std::ostream& operator<<(std::ostream& out, BigInteger const& value)
    {
        Collections::Turbo::FastArrayList<int> list;

        list.Append(0);

        bool isMinus = value.IsNegative();

        for (ssize_t i = value._list.Length() - 1; i >= 0; --i) {
            //全体に256をかける
            for (int& value : list) value *= 256;

            list[0] += isMinus ? (uint8_t)~value._list[i] : value._list[i];

            //2の補数表現
            if (isMinus && i == 0) ++list[0];

            //各要素が10を超えていたら調整
            BigInteger::_adjustPlus(list, true);

        }

        //最後に出力
        if (isMinus) out << '-';

        for (ssize_t i = list.Length() - 1; i >= 0; --i) {
            out << (char)(list[i] + '0');
        }

        return out;
    }

    std::istream& operator>>(std::istream& in, BigInteger& value)
    {
        bool isStart = false;
        bool isMinus = false;
        bool hasSymbol = false;
        BigInteger tmp;

        char c;

        while ((c = in.peek()) != std::char_traits<char>::eof()) {
            
            if (std::iswdigit(c)) {
                isStart = true;
                tmp._list.Insert(0, (uint8_t)(c - '0'));
            }
            else if (c == '-') {
                if (hasSymbol) {
                    if (!isStart) in.setstate(std::ios::failbit);
                    break;
                }
                hasSymbol = true;
                isMinus = true;
            }
            else if (c == '+') {
                if (hasSymbol) {
                    if (!isStart) in.setstate(std::ios::failbit);
                    break;
                }
                hasSymbol = true;
            }
            else {
                if (c != ' ' && c != '\n') {
                    if (!isStart) in.setstate(std::ios::failbit);
                    break;
                }
                else {
                    if (isStart) break;
                }
            }

            (void)in.get();
        }

        if (!in.fail()) {

            if (isMinus) {
                //マイナスと誤判定
                if (tmp.IsNegative()) {
                    tmp._list.Append(BigInteger::_symbol);
                }
                else {
                    uint8_t& back = tmp._list.Back();

                    back |= BigInteger::_symbol;
                }
            }
            else {
                //マイナスと誤判定
                if (tmp.IsNegative()) {
                    tmp._list.Append(0);
                }
            }

            value = std::move(tmp);
        }

        return in;
    }

    BigInteger operator+(BigInteger const& left, BigInteger const& right)
    {
        Collections::Turbo::FastArrayList<int> list;

        //サイズを取得
        ssize_t biggerSize, smallerSize;
        //小さいほうの値が負であるかどうか
        bool smallValueIsMinus;

        if (left.ByteSize() > right.ByteSize()) {
            biggerSize = left.ByteSize();
            smallerSize = right.ByteSize();

            smallValueIsMinus = right.IsNegative();
        }
        else {
            biggerSize = right.ByteSize();
            smallerSize = left.ByteSize();

            smallValueIsMinus = left.IsNegative();
        }

        for (ssize_t i = 0; i < biggerSize; ++i) {
            if (i >= smallerSize) {
                uint8_t v = smallValueIsMinus ? 255 : 0;
                list.Append(left._list[i] + v);
            }
            else {
                list.Append(left._list[i] + right._list[i]);
            }

        }

        //各要素が256を超えていたら調整
        BigInteger::_adjustPlus(list, false, 256);

        BigInteger value;

        for (int& v : list) value._list.Append((uint8_t)v);

        return value;

    }

    BigInteger operator-(BigInteger const& left, BigInteger const& right)
    {
        BigInteger tmp = ~right;

        ++tmp;

        return left + tmp;
    }

    BigInteger operator|(BigInteger const& left, BigInteger const& right)
    {
        BigInteger ret;

        //サイズを取得
        ssize_t biggerSize, smallerSize;
        const BigInteger* biggerValue;

        if (left.ByteSize() > right.ByteSize()) {
            biggerSize = left.ByteSize();
            smallerSize = right.ByteSize();

            biggerValue = &left;
        }
        else {
            biggerSize = right.ByteSize();
            smallerSize = left.ByteSize();

            biggerValue = &right;
        }

        for (ssize_t i = 0; i < biggerSize; ++i) {
            if (i >= smallerSize) {
                ret._list.Append(biggerValue->_list[i]);
            }
            else {
                ret._list.Append(left._list[i] | right._list[i]);
            }
        }

        return ret;
    }

    BigInteger operator&(BigInteger const& left, BigInteger const& right)
    {
        BigInteger ret;

        //サイズを取得
        ssize_t biggerSize, smallerSize;
        //小さいほうの値が負であるかどうか
        bool smallValueIsMinus;

        const BigInteger* biggerValue;

        if (left.ByteSize() > right.ByteSize()) {
            biggerSize = left.ByteSize();
            smallerSize = right.ByteSize();

            smallValueIsMinus = right.IsNegative();
            biggerValue = &left;
        }
        else {
            biggerSize = right.ByteSize();
            smallerSize = left.ByteSize();

            smallValueIsMinus = left.IsNegative();
            biggerValue = &right;
        }

        for (ssize_t i = 0; i < biggerSize; ++i) {
            if (i >= smallerSize) {
                uint8_t v = smallValueIsMinus ? 255 : 0;
                ret._list.Append(biggerValue->_list[i] & v);
            }
            else {
                ret._list.Append(left._list[i] & right._list[i]);
            }
        }

        return ret;
    }

    BigInteger operator~(BigInteger const& value)
    {
        BigInteger ret;

        for (ssize_t i = 0; i < value._list.Length(); ++i) {
            ret._list.Append((uint8_t)~value._list[i]);
        }

        return ret;
    }

    BigInteger BigInteger::operator++(int)
    {
        BigInteger ret = *this;
        ++(*this);

        return ret;
    }

    BigInteger BigInteger::operator--(int)
    {
        BigInteger ret = *this;
        --(*this);

        return ret;
    }

    void BigInteger::ShrinkToFit()
    {
        while (ByteSize() > 0) {
            if (_list.Back() == 0) _list.RemoveBack();
        }

        _list.ShrinkToFit();
    }

    String BigInteger::ToString() const
    {
        std::ostringstream wsout;
        wsout << *this;

        return wsout.str().c_str();
    }

    const uint8_t BigInteger::_symbol = 0b10000000;

    void BigInteger::_adjustMinus(Collections::Turbo::FastArrayList<int>& list, bool canAddValue, int sinsu)
    {
        //各要素が10を超えていたら調整
        for (ssize_t j = 0; j < list.Length(); ++j) {

            //最後のループ
            if (canAddValue && j == list.Length() - 1) {
                //問題なければそこで終了
                if (list[j] >= 0) break;

                //まだ処理しきれていない場合は続行
                list.Append(0);
            }

            while (list[j] < 0) {
                list[j] += sinsu;
                --list[j + 1];
            }
        }

    }

    void BigInteger::_adjustPlus(Collections::Turbo::FastArrayList<int>& list, bool canAddValue, int sinsu)
    {
        //各要素が10を超えていたら調整
        for (ssize_t j = 0; j < list.Length(); ++j) {

            //最後のループ
            if (canAddValue && j == list.Length() - 1) {
                //問題なければそこで終了
                if (list[j] < sinsu) break;

                //まだ処理しきれていない場合は続行
                list.Append(0);
            }

            while (list[j] >= sinsu) {
                list[j] -= sinsu;
                ++list[j + 1];
            }
        }

    }
}
