//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Graphics::Imaging
{
    ImageRenderException::ImageRenderException() : Exception(String::FromLiteral(u"描画に失敗しました"))
    {
    }
}