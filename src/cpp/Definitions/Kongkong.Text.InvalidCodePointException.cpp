//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Text
{
    InvalidCodePointException::InvalidCodePointException() : Exception(String::FromLiteral(u"無効なコードポイントです"))
    {
    }
}