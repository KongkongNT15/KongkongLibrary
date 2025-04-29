//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    void ArgumentNullException::CheckNull(const void* p, const char16_t* pName)
    {
        if (p == nullptr) [[unlikely]] {
            ThrowWithName(pName);
        }
    }

    void ArgumentNullException::CheckNull(Object const& object, const char16_t* pName)
    {
        if (object == nullptr) [[unlikely]] {
            ThrowWithName(pName);
        }
    }


#ifdef KONGKONG_OBJECTIVE_C_ENABLED
    void ArgumentNullException::CheckNull(AppleDevice::NSObject const& object, const char16_t* pName)
    {
        if (object == nullptr) [[unlikely]] {
            ThrowWithName(pName);
        }
    }
#endif //KONGKONG_OBJECTIVE_C_ENABLED

    void ArgumentNullException::ThrowWithName(const char16_t* name)
    {
        String message;
        constexpr char16_t nulldesita[] = u"'がNullでした";

        message.Append(u'\'');
        message.AppendUnsafe(name);
        message.AppendUnsafe(sizeof(nulldesita) / sizeof(char16_t) - 1, nulldesita);

        throw ArgumentNullException(std::move(message));
    }
    
}
