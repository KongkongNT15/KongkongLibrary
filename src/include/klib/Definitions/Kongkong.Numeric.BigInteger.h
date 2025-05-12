#ifndef KONGKONG_NUMERIC_BIGINTEGER_H
#define KONGKONG_NUMERIC_BIGINTEGER_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.GenericString.h"
#include "Kongkong.Collections.Turbo.FastArrayList.h"

namespace KONGKONG_NAMESPACE::Numeric
{
    //任意の大きさの整数型
    //符号付き
    //2の補数表現(のつもり)
    //リトルエンディアン
    struct BigInteger : public ValueType {

        //整数値から値を作成
        BigInteger(int32_t value) : BigInteger(value, true) {};
        BigInteger(uint32_t value) : BigInteger(value, true) {};
        BigInteger(int64_t value) : BigInteger(value, true) {};
        BigInteger(uint64_t value) : BigInteger(value, true) {};
        
        //標準ストリームに入出力
        friend std::ostream& operator<<(std::ostream& out, BigInteger const& value);
        friend std::istream& operator>>(std::istream& in, BigInteger& value);

        //演算
        friend BigInteger operator+(BigInteger const& left, BigInteger const& right);
        friend BigInteger operator-(BigInteger const& left, BigInteger const& right);
        friend BigInteger operator*(BigInteger const& left, BigInteger const& right);
        friend BigInteger operator/(BigInteger const& left, BigInteger const& right);
        friend BigInteger operator|(BigInteger const& left, BigInteger const& right);
        friend BigInteger operator&(BigInteger const& left, BigInteger const& right);
        friend BigInteger operator~(BigInteger const& value);

        //値の変更
        BigInteger& operator+=(BigInteger const& right) { return *this = *this + right; }
        BigInteger& operator-=(BigInteger const& right) { return *this = *this - right; }

        BigInteger& operator++() { return *this += 1; }
        BigInteger operator++(int);

        BigInteger& operator--() { return *this += -1; }
        BigInteger operator--(int);

        //値が負であるかを確認
        bool IsNegative() const { return (_symbol & _list.Back()) == _symbol; }

        //値が正であるかを確認
        bool IsPositive() const { return !IsNegative(); }

        //ビット数を取得
        ssize_t BitSize() const { return _list.Length() * 8; }

        //バイト数を取得
        ssize_t ByteSize() const { return _list.Length(); }

        //値のサイズを最適化
        void ShrinkToFit();

        String ToString() const;


        private:
        //負の符号を指す値
        static const uint8_t _symbol;

        //listの各要素が負なら調整
        static void _adjustMinus(Collections::Turbo::FastArrayList<int>& list, bool canAddValue, int sinsu = 10);

        //listの各要素が10を超えていたら調整
        static void _adjustPlus(Collections::Turbo::FastArrayList<int>& list, bool canAddValue, int sinsu = 10);

        Collections::Turbo::FastArrayList<uint8_t> _list;

        BigInteger() = default;

        template <std::signed_integral Num>
        BigInteger(Num value, bool)
        {
            uint8_t* p = (uint8_t*)&value;
            uint8_t* end = (uint8_t*)(&value + 1);

            while (p != end) {
                _list.Append(*p);
                ++p;
            }
        }

        template <std::unsigned_integral Num>
        BigInteger(Num value, bool)
        {
            uint8_t* p = (uint8_t*)&value;
            uint8_t* end = (uint8_t*)(&value + 1);

            while (p != end) {
                _list.Append(*p);
                ++p;
            }

            _list.Append(0);
        }
    };
}

#endif //!KONGKONG_NUMERIC_BIGINTEGER_H
