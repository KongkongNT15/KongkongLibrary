//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Bits
{
    BitSetElement& BitSetElement::operator=(bool value) noexcept
    {
        uint8_t n = 1 << _index;
        bool currentValue = (bool)(n & _value);

        if (currentValue) {
            if (!value) _value -= n;
        }
        else {
            if (value) _value += n;
        }

        return *this;
    }

    BitSetElement& BitSetElement::operator~() noexcept
    {
        uint8_t n = 1 << _index;
        bool currentValue = (bool)(n & _value);

        if (currentValue) _value -= n;
        else _value += n;
        
        return *this;
    }

    String BitSetElement::ToString() const
    {
        return String::ValueOf((bool)*this);
    }
}
