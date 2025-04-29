//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    void NullPointerException::CheckNull(const void* p, const char16_t* pName)
    {
        if (p == nullptr) [[unlikely]] {
            String message;

            message.Append(u'\'');
            message.AppendUnsafe(pName);
            message.AppendUnsafe(u"'がNullでした");

            throw NullPointerException(std::move(message));
        }
        
    }

}
