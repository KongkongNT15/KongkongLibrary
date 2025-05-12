//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Algorithms
{
    String RadixConverter::Convert(String const& numStr, uint8_t inputRadix, uint8_t outputRadix)
    {
        RadixConverter converter(inputRadix, outputRadix);

        return converter.Convert(numStr);
    }

    String RadixConverter::Convert(const char16_t* numStr, uint8_t inputRadix, uint8_t outputRadix)
    {
        RadixConverter converter(inputRadix, outputRadix);

        return converter.Convert(numStr);
    }

    String RadixConverter::Convert(ssize_t length, const char16_t* numStr, uint8_t inputRadix, uint8_t outputRadix)
    {
        RadixConverter converter(inputRadix, outputRadix);

        return converter.Convert(length, numStr);
    }

    String RadixConverter::Convert(String const& numStr, uint8_t inputRadix, uint8_t outputRadix, ssize_t decimalPrecision)
    {
        RadixConverter converter(inputRadix, outputRadix, decimalPrecision);

        return converter.Convert(numStr);
    }

    String RadixConverter::Convert(const char16_t* numStr, uint8_t inputRadix, uint8_t outputRadix, ssize_t decimalPrecision)
    {
        RadixConverter converter(inputRadix, outputRadix, decimalPrecision);

        return converter.Convert(numStr);
    }

    String RadixConverter::Convert(ssize_t length, const char16_t* numStr, uint8_t inputRadix, uint8_t outputRadix, ssize_t decimalPrecision)
    {
        RadixConverter converter(inputRadix, outputRadix, decimalPrecision);

        return converter.Convert(length, numStr);
    }

    RadixConverter::RadixConverter() noexcept :
        _decimalPrecision(_defaultDecimalPrecision),
        _inputRadix(_defaultInputRadix),
        _outputRadix(_defaultOutputRadix)
    {
    }

    RadixConverter::RadixConverter(uint8_t inputRadix, uint8_t outputRadix) :
        _decimalPrecision(_defaultDecimalPrecision),
        _inputRadix(inputRadix),
        _outputRadix(outputRadix)
    {
        _checkRadix(inputRadix);
        _checkRadix(outputRadix);
    }

    RadixConverter::RadixConverter(uint8_t inputRadix, uint8_t outputRadix, ssize_t decimalPrecision) :
        _decimalPrecision(decimalPrecision),
        _inputRadix(inputRadix),
        _outputRadix(outputRadix)
    {
        _checkRadix(inputRadix);
        _checkRadix(outputRadix);
        _checkDecimalPrecision(decimalPrecision);
    }

    String RadixConverter::Convert(String const& numStr) const
    {
        return _convertUnsafeNoLengthCheck(numStr.Length(), numStr.c_str());
    }

    String RadixConverter::Convert(const char16_t* numStr) const
    {
        ArgumentNullException::CheckNull(numStr, u"numStr");
        return _convertUnsafeNoLengthCheck(Text::StringHelper::GetLengthUnsafe(numStr), numStr);
    }

    String RadixConverter::Convert(ssize_t length, const char16_t* numStr) const
    {
        ArgumentNullException::CheckNull(numStr, u"numStr");
        if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"lengthの値がゼロ以下でした");
    
        return _convertUnsafeNoLengthCheck(length, numStr);
    }

    void RadixConverter::DecimalPrecision(ssize_t value)
    {
        _checkDecimalPrecision(value);
        _decimalPrecision = value;
    }

    void RadixConverter::InputRadix(uint8_t value)
    {
        _checkRadix(value);
        _inputRadix = value;
    }

    void RadixConverter::OutputRadix(uint8_t value)
    {
        _checkRadix(value);
        _outputRadix = value;
    }

    String RadixConverter::ToString() const
    {
        String str;

        str.AppendUnsafe(u"[ InputRadix:");

        _toString(str, _inputRadix);

        str.AppendUnsafe(u", OutputRadix:");

        _toString(str, _outputRadix);

        str.AppendUnsafe(u", DecimalPrecision:");

        _toString(str, _decimalPrecision);

        str.AppendUnsafe(u" ]");

        return str;
    }

    void RadixConverter::_checkDecimalPrecision(ssize_t value)
    {
        if (value < 0)[[unlikely]] throw InvalidArgumentException(u"表示する少数の桁数にゼロ未満が指定されました");
        if (value > MaxDecimalPrecision()) [[unlikely]] throw InvalidArgumentException(u"表示する少数の桁数が大きすぎます");
    }

    void RadixConverter::_checkRadix(uint8_t radix)
    {
        if (radix < MinRadix() || MaxRadix() < radix) [[unlikely]] throw InvalidArgumentException(u"範囲外の基数が指定されました\n基数は2~36の間の値にしてください");
    }

    Collections::Turbo::FastArrayList<uint8_t> RadixConverter::_createNumVec(ssize_t length, const char16_t* numStr, uint8_t inputRadix, bool& hasDecimal)
    {
        auto f = [&] () {
            throw FormatException(String(length, numStr, true));
        };

        const char16_t* p = numStr;
        const char16_t* end = numStr + length;

        bool isMinus = false;
        bool startsWithZero = false;
        bool hasZero = false;
        uint8_t realRadix = MinRadix();

        char16_t c;

        Collections::Turbo::FastArrayList<uint8_t> vec;

        while (p != end) {
            c = *p;
            if (c == u'0') {
                //0000567 => 567
                //-000004556 => -4556
                if (!vec.IsEmpty()) {
                    if (isMinus == false || vec.Length() >= 2) [[likely]] vec.Append(0);
                }
                else {
                    startsWithZero = true;
                }
                hasZero = true;
            }
            else if (u'1' <= c && c <= u'9') {
                vec.Append(_toNumberFromNumChar(c));

                if (realRadix < (uint8_t)(c - '0' + 1)) {
                    realRadix = (uint8_t)(c - '0' + 1);
                }
            }
            else if (u'A' <= c && c <= u'Z') {
                vec.Append(_toNumberFromUpperChar(c));

                if (realRadix < (uint8_t)(c - 'A' + 11)) {
                    realRadix = (uint8_t)(c - 'A' + 11);
                }
            }
            else if (u'a' <= c && c <= u'z') {
                vec.Append(_toNumberFromLowerChar(c));

                if (realRadix < (uint8_t)(c - 'a' + 11)) {
                    realRadix = (uint8_t)(c - 'a' + 11);
                }
            }
            else if (c == u'.') {
                if (hasDecimal) [[unlikely]] f();

                if (vec.IsEmpty()) {
                    //0.で始まらなければおかしい
                    if (startsWithZero == false) [[unlikely]] f();
                
                }

                //-. は不正
                if (isMinus && !hasZero && vec.Length() == 1) [[unlikely]] f();
                
                vec.Append('.');
                hasDecimal = true;
            }
            else if (c == u'-') {
                if (isMinus) [[unlikely]] f();
            
                //000-は不正
                if (startsWithZero) f();

                isMinus = true;
                vec.Append('-');
            }
            else [[unlikely]] {
                f();
            }

            ++p;
        }

        //numStr == u"-"のとき
        if (length == 1 && *numStr == u'-') [[unlikely]] f();
        
        //numStr == u"5375347."のとき
        if (vec.GetBackUnsafe() == '.') [[unlikely]] f();

        if (realRadix > inputRadix) [[unlikely]] {
            String message;

            message.AppendUnsafe(u"入力された値は");
            message.Append(u'0' + (char16_t)(realRadix));
            message.AppendUnsafe(u"です\n");
            message.Append(u'0' + (char16_t)(inputRadix));
            message.AppendUnsafe(u"進数では表現できません");

            throw InvalidArgumentException(std::move(message));
        }

        //zero_delete()
        if (hasDecimal) {
            while (vec.GetBackUnsafe() == 0) vec.RemoveBackUnsafe();

            //ここではvec.size() > 0
            if (vec.GetBackUnsafe() == '.') [[unlikely]] {
                vec.RemoveBackUnsafe();
                hasDecimal = false;
            }
            
        }

        if (isMinus) {
            //vec = { '-' }のとき
            if (vec.Length() == 1) [[unlikely]] vec.RemoveBackUnsafe();
        }

        return vec;
    }

    void RadixConverter::_irekae3(short* vec, unsigned ketasu, int sinsu)
    {
        for (unsigned i = 0; i < ketasu; i++) {
            while (vec[i] >= sinsu) {
                vec[i] -= sinsu;
                vec[i + 1]++;
            }
        }
    }

    void RadixConverter::_irekae4(short* vec, unsigned ketasu, int sinsu)
    {
        for (unsigned i = 0; i < ketasu; i++) {
            while (vec[i] < 0) {
                vec[i] += sinsu;
                vec[i + 1]--;
            }
        }
    }

    void RadixConverter::_printValue(String& str, const short* p, unsigned ketasu, unsigned power, int sinsu) noexcept
    {
        short bunkatsu[6]{};
        ssize_t i, j, k;

        k = 0;

        for (i = ketasu; i >= 0; i--) {
            bunkatsu[0] = p[i];

            for (j = 0; j < power; j++) {
                while (bunkatsu[j] >= sinsu) {
                    bunkatsu[j] -= sinsu;
                    bunkatsu[j + 1]++;
                    k = j + 1;
                }
            }

            j = i == ketasu ? k : power;

            for (; j >= 0; j--) {
                str.Append(_toChar(bunkatsu[j]));
            }

            for (j = 1; j <= power; j++) {
                bunkatsu[j] = 0;
            }
        }
    }

    char16_t RadixConverter::_toChar(short num) noexcept
    {
        if (num <= 9) return u'0' + (char16_t)num;
        
        return (char16_t)(u'A' + num - 10);
    }

    uint8_t RadixConverter::_toNumberFromLowerChar(char16_t c) noexcept
    {
        return (uint8_t)(c - u'a' + 10);
    }

    uint8_t RadixConverter::_toNumberFromNumChar(char16_t c) noexcept
    {
        return (uint8_t)(c - u'0');
    }

    uint8_t RadixConverter::_toNumberFromUpperChar(char16_t c) noexcept
    {
        return (uint8_t)(c - u'A' + 10);
    }

    String RadixConverter::_convertUnsafeNoLengthCheck(ssize_t length, const char16_t* numStr) const
    {
        bool hasDecimal = false;
        bool isMinus;
        Collections::Turbo::FastArrayList<uint8_t> vec = _createNumVec(length, numStr, _inputRadix, hasDecimal);
        short* integerPart = nullptr;
        ssize_t i;
        short* end;
        short* p;
        ssize_t decimalFront = 0;
        unsigned ketasuI;

        if (vec.IsEmpty()) return String::FromLiteral(u"0");

        String str;

        //マイナス記号を削除
        if (vec.GetFrontUnsafe() == '-') {
            isMinus = true;
            vec.RemoveAtUnsafe(0);
            str.Append(u'-');
        }

        if (hasDecimal) {
            for (i = 0; i < vec.Length(); i++) {
                if (vec[i] == '.') {
                    ketasuI = (unsigned)i;
                    decimalFront = i + 1;
                    break;
                }
            }

            if (_decimalPrecision == 0) hasDecimal = false;
        }
        else {
            ketasuI = (unsigned)vec.Length();
        }

        if (ketasuI != 0) {
            int sinsu3;
            unsigned power = 0;

            for (sinsu3 = _outputRadix; sinsu3 < _inputRadix; sinsu3 *= _outputRadix) {
                power++;
            }
            //integerPart = new short[ketasuI + 1];
            integerPart = (short*)::calloc(ketasuI + 1, sizeof(short));
            MemoryAllocationException::CheckNull(integerPart);

            end = integerPart + ketasuI;

            for (i = 0; i < ketasuI; i++) {
                for (p = integerPart; p != end; p++) {
                    *p *= _inputRadix;
                }

                *integerPart += vec[i];
                _irekae3(integerPart, ketasuI, sinsu3);
            }

            int ketasu1 = ketasuI;

            while (true) {
                if (integerPart[ketasu1] != 0) break;
                ketasu1--;
            }

            if (power == 0) {
                while (ketasu1 >= 0) {
                    str.Append(_toChar(integerPart[ketasu1]));
                    ketasu1--;
                }
            }
            else {
                _printValue(str, integerPart, ketasu1, power, _outputRadix);
            }
        }

        if (hasDecimal) {
            if (integerPart == nullptr) str.AppendUnsafe(u"0.");
            else str.Append(u'.');

            ssize_t k;
            ssize_t ketasho = vec.Length() - decimalFront;

            //short* bunshi = new short[ketasho + 12];
            //short* tmp = new short[ketasho + 12];
            short* bunshi = (short*)::calloc(ketasho + 12, sizeof(short));
            short* tmp = (short*)::calloc(ketasho + 12, sizeof(short));

            if (bunshi == nullptr || tmp == nullptr) [[unlikely]] {
                if (integerPart != nullptr) ::free(integerPart);
                if (bunshi != nullptr) ::free(bunshi);
                if (tmp != nullptr) ::free(tmp);

                throw MemoryAllocationException();
            }
            
            for (k = vec.Length() - 1, i = 0; k >= decimalFront; k--, i++) {
                bunshi[i] = vec[k];
            }

            for (ssize_t ii = -1; ii < _decimalPrecision; ii++) {
                short value = 0;

                while (true) {
                    //bunshiをtmpにコピー
                    for (k = 0; k < ketasho + 12; k++) {
                        tmp[k] = bunshi[k];
                    }
                    tmp[ketasho]--;
                    _irekae4(tmp, (unsigned)ketasho, _inputRadix);

                    if (tmp[ketasho] >= 0) {
                        //tmpをbunshiにコピー
                        for (k = 0; k < ketasho + 12; k++) {
                            bunshi[k] = tmp[k];
                        }

                        value++;
                    }

                    if (tmp[ketasho] < 0) break;
                }

                if (ii != -1) str.Append(_toChar(value));

                for (k = 0; k < ketasho + 12; k++) {
                    bunshi[k] *= _outputRadix;
                }

                _irekae3(bunshi, (unsigned)ketasho, _inputRadix);

                k = 0;

                while (k < ketasho + 12) {
                    if (bunshi[k] == 0) break;
                    k++;
                }

                //割り切れたことを示す(ハズ)
                if (k == ketasho + 12) break;
            }


            ::free(bunshi);
            ::free(tmp);
        }

        if (integerPart != nullptr) ::free(integerPart);
        else if (!hasDecimal) return String::FromLiteral(u"0");

        //str = u"0.00000000"のとき
        //str = u"9.00000000"のとき
        if (hasDecimal) {
            bool isNotZero = false;

            while (str.BackUnsafe() == u'0') {
                str.RemoveBackUnsafe();
            }

            if (str.BackUnsafe() == u'.') {
                str.RemoveBackUnsafe();

                //str = u"0.00000000"のとき
                //str = u"-0.00000000"のとき
                if (str.BackUnsafe() == u'0') return String::FromLiteral(u"0");
            }
        }

        return str;
    }

    void RadixConverter::_toString(String& str, ssize_t value) noexcept
    {
        if (value >= 10) _toString(str, value / 10);
        str.Append((char16_t)(value % 10) + u'0');
    }
    
}
