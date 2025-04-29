//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Algorithms
{
    bool Range::IsEqual(ssize_t length, const void* left, const void* right)
    {
        if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"長さにセロ以下が指定されました");

        ArgumentNullException::CheckNull(left, u"left");
        ArgumentNullException::CheckNull(right, u"right");

        return IsEqualUnsafe(length, left, right);
    }

    bool Range::IsEqualUnsafe(ssize_t length, const void* left, const void* right) noexcept
    {
        const uint8_t* lp = (const uint8_t*)left;
        const uint8_t* rp = (const uint8_t*)right;

        for (ssize_t i = 0; i < length; i++) {
            if (lp[i] != rp[i]) return false;
        }

        return true;
    }
}
