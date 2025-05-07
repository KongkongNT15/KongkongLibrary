//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    InitializationException::InitializationException() : Exception(String::FromLiteral(u"オブジェクトの初期化に失敗しました"))
    {
    }
}
