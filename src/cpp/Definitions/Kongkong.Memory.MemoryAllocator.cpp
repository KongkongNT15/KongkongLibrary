//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Memory
{
    void MemoryAllocator::FreeMemory(void* p)
    {
        ArgumentNullException::CheckNull(p, u"p");

        FreeMemoryUnsafe(p);
    }

    void MemoryAllocator::FreeMemoryUnsafe(void* p) noexcept
    {
        ::free(p);
    }

    void* MemoryAllocator::_allocMemory(ssize_t length)
    {
        _checkLength(length);

        return _allocMemoryUnsafe(length);
    }

    void* MemoryAllocator::_allocMemoryUnsafe(ssize_t length)
    {
        void* p = ::malloc((size_t)length);

        MemoryAllocationException::CheckNull(p);

        return p;
    }

    void MemoryAllocator::_checkLength(ssize_t length)
    {
        if (length <= 0) [[unlikely]] throw InvalidArgumentException(u"メモリブロックの長さにゼロ以下が指定されました");
    }

    void* MemoryAllocator::_reallocMemory(ssize_t newLength, void* p)
    {
        ArgumentNullException::CheckNull(p, u"p");
        _checkLength(newLength);

        return _reallocMemoryUnsafe(newLength, p);
    }

    void* MemoryAllocator::_reallocMemoryUnsafe(ssize_t newLength, void* p)
    {
        void* tmp = ::realloc(p, (size_t)newLength);

        MemoryAllocationException::CheckNull(tmp);

        return tmp;
    }
}
