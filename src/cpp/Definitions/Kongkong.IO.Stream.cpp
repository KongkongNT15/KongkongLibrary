//このcppファイルをコンパイルに含めないでください

#define READ_NOT_SUPPORTED String::FromLiteral(u"このストリームは読み込みをサポートしていません")
#define WRITE_NOT_SUPPORTED String::FromLiteral(u"このストリームは書き込みをサポートしていません")

namespace KONGKONG_NAMESPACE::IO::IMPLEMENTATION
{
    int Stream::ReadByte()
    {
        throw NotSupportedException(READ_NOT_SUPPORTED);
    }

    void Stream::WriteByte(uint8_t)
    {
        throw NotSupportedException(WRITE_NOT_SUPPORTED);
    }
}

#undef READ_NOT_SUPPORTED
#undef WRITE_NOT_SUPPORTED