//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Graphics
{
    String FontWeight::ToString() const
    {
        if (*this < ExtraLight()) return String::FromLiteral(u"Thin");
        if (*this < Light())      return String::FromLiteral(u"ExtraLight");
        if (*this < SemiLight())  return String::FromLiteral(u"Light");
        if (*this < Normal())     return String::FromLiteral(u"SemiLight");
        if (*this < Regular())    return String::FromLiteral(u"Normal");
        if (*this < Medium())     return String::FromLiteral(u"Regular");
        if (*this < SemiBold())   return String::FromLiteral(u"Medium");
        if (*this < Bold())       return String::FromLiteral(u"SemiBold");
        if (*this < ExtraBold())  return String::FromLiteral(u"Bold");
        if (*this < Black())      return String::FromLiteral(u"ExtraBold");
        if (*this < ExtraBlack()) return String::FromLiteral(u"Black");

        return String::FromLiteral(u"ExtraBlack");
    }
}