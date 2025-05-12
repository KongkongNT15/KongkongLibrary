//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::CStd
{
    void* CMemoryManager::AllocMemory(size_t length)
    {
        void* p = ::malloc(length);
        if (p == nullptr) [[unlikely]] throw CStdException();

        return p;
    }

    void CMemoryManager::FreeMemory(void* p) noexcept
    {
        ::free(p);
    }

    void* CMemoryManager::ReallocMemory(size_t newLength, void* p)
    {
        void* ret = ::realloc(p, newLength);
        if (ret == nullptr) [[unlikely]] throw CStdException();

        return ret;
    }
}
