//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Memory
{
    String BufferBase::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Memory::Buffer<T>");
    }
}
