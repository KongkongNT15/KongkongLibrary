//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    void InvalidOperationException::CheckZeroLength(ssize_t length)
    {
        if (length == 0) [[unlikely]] throw InvalidOperationException(u"要素を参照できません、バッファーの長さがゼロです");
    }
}
