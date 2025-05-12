//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    FormatException::FormatException(String const& errorMessage, bool useFormatErrorMessage) :
        Exception(useFormatErrorMessage ? u"入力された文字列'" + errorMessage + u"'の形式が正しくありません" : errorMessage)
    {
    }
    
}
