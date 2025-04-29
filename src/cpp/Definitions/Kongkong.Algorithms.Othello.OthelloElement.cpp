//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Algorithms::Othello
{
    String OthelloElement::ToString() const
    {
        switch (_value) {
            case OthelloValue::None: return String::FromLiteral(u"None");
            case OthelloValue::White: return String::FromLiteral(u"White");
            case OthelloValue::Black: return String::FromLiteral(u"Black");

            default: [[unlikely]] return String::FromLiteral(u"Unknown Value");
        }
    }

    void OthelloElement::Value(OthelloValue value)
    {
        if (value > OthelloValue::Black) [[unlikely]] throw InvalidArgumentException(u"値が無効です");

        _value = value;
    }
}
