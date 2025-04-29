//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE
{
    char16_t MemoryAllocationException::_defaultMessage[14] = u"メモリの確保に失敗しました";
    
    void MemoryAllocationException::CheckNull(const void* p)
    {
        if (p == nullptr) [[unlikely]] throw MemoryAllocationException();
    }

    MemoryAllocationException::MemoryAllocationException() : 
        MemoryException(0)
    {
        //ふぁ！？っく
        _errorMessage._p = _defaultMessage;
        _errorMessage._length = 13;
        _errorMessage._capacity = 14;
    }

    MemoryAllocationException::~MemoryAllocationException()
    {
        //ふぁ！？っく
        _errorMessage._p = nullptr;
    }
    
}
