//このcppファイルをコンパイルに含めないでください

#define CHECK_LENGTH_SIGNED(type) \
    void CollectionHelper::CheckLength(type length) \
    { \
        if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"要素数にゼロ以下が指定されました"); \
    }

#define CHECK_LENGTH_UNSIGNED(type) \
    void CollectionHelper::CheckLength(type length) \
    { \
        if (length == 0) [[unlikely]] throw InvalidArgumentException(u"要素数にゼロが指定されました"); \
    }

namespace KONGKONG_NAMESPACE::Collections
{
    void CollectionHelper::CheckBackFront(ssize_t length)
    {
        if (length == 0) [[unlikely]] throw InvalidOperationException(u"コンテナが空です");
    }

    void CollectionHelper::CheckCapacity(ssize_t capacity)
    {
        if (capacity < 1) [[unlikely]] throw InvalidArgumentException(u"格納可能な要素数にゼロ以下の値が指定されました");
    }

    void CollectionHelper::CheckCount(ssize_t length, ssize_t count)
    {
#if KONGKONG_HAS_CPP23
        [[assume(length >= 0)]];
#endif

        if (count <= 0) [[unlikely]] throw InvalidArgumentException(u"要素数にゼロ以下が指定されました");
        if (count > length) [[unlikely]] throw ArgumentOutOfRangeException(u"終了位置が範囲外です");
    }

    void CollectionHelper::CheckIndex(ssize_t index, ssize_t length)
    {
        if (index < 0) [[unlikely]] throw InvalidArgumentException(u"要素番号に負の値が指定されました");
        if (index >= length) [[unlikely]] throw ArgumentOutOfRangeException(u"範囲外の要素が指定されました");
    }

    CHECK_LENGTH_SIGNED(int8_t)
    CHECK_LENGTH_SIGNED(short)
    CHECK_LENGTH_SIGNED(int)
    CHECK_LENGTH_SIGNED(long)
    CHECK_LENGTH_SIGNED(long long)
    CHECK_LENGTH_UNSIGNED(uint8_t)
    CHECK_LENGTH_UNSIGNED(unsigned short)
    CHECK_LENGTH_UNSIGNED(unsigned int)
    CHECK_LENGTH_UNSIGNED(unsigned long)
    CHECK_LENGTH_UNSIGNED(unsigned long long)

    void CollectionHelper::CheckMinusLength(ssize_t length)
    {
        if (length < 0) [[unlikely]] throw InvalidArgumentException(u"要素数に負の値が指定されました");
    }

    void CollectionHelper::CheckOffset(ssize_t length, ssize_t offset)
    {
#if KONGKONG_HAS_CPP23
        [[assume(length >= 0)]];
#endif
        if (offset < 0) [[unlikely]] throw InvalidArgumentException(u"開始位置に負の値が指定されました");
        if (offset >= length) [[unlikely]] throw ArgumentOutOfRangeException(u"開始位置が範囲外です");
    }

    void CollectionHelper::CheckOffset(ssize_t length, ssize_t offset, ssize_t count)
    {
#if KONGKONG_HAS_CPP23
        [[assume(length >= 0)]];
#endif
        if (offset < 0) [[unlikely]] throw InvalidArgumentException(u"開始位置に負の値が指定されました");
        if (count < 0) [[unlikely]] throw InvalidArgumentException(u"要素数に負の値が指定されました");
        if (offset >= length) [[unlikely]] throw ArgumentOutOfRangeException(u"開始位置が範囲外です");
        if (offset + count > length) [[unlikely]] throw ArgumentOutOfRangeException(u"終端が範囲外です");
    }
}

#undef CHECK_LENGTH_SIGNED
#undef CHECK_LENGTH_UNSIGNED
