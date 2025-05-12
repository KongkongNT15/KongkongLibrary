//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Memory::IMPLEMENTATION
{
    MemoryBlock::MemoryBlock(ssize_t size) :
        _p(),
        _size(size)
    {
        _checkSize(size);

        _p = MemoryAllocator::AllocMemoryUnsafe<uint8_t>(size);
    }

    MemoryBlock::MemoryBlock(MemoryBlock const& right) : MemoryBlock()
    {
        if (!right.HasMemoryBlock()) [[unlikely]] return;

        _p = MemoryAllocator::AllocMemoryUnsafe<uint8_t>(right._size);
        _size = right._size;

        ::memcpy(_p, right._p, (size_t)_size);
    }

    MemoryBlock::~MemoryBlock()
    {
        Free();
    }

    MemoryBlock& MemoryBlock::operator=(MemoryBlock const& right)
    {
        Free();

        if (!right.HasMemoryBlock()) [[unlikely]] return *this;

        _p = MemoryAllocator::AllocMemoryUnsafe<uint8_t>(right._size);
        _size = right._size;

        ::memcpy(_p, right._p, (size_t)_size);

        return *this;
    }

    MemoryBlock& MemoryBlock::operator=(MemoryBlock&& right)
    {
        Free();

        _p = right._p;
        _size = right._size;

        right._p = nullptr;
        right._size = 0;

        return *this;
    }

    void MemoryBlock::Alloc(ssize_t size)
    {
        _checkSize(size);
        AllocUnsafe(size);
    }

    void MemoryBlock::AllocUnsafe(ssize_t size)
    {
        _p = MemoryAllocator::AllocMemoryUnsafe<uint8_t>((size_t)size);
        _size = size;
    }

    void MemoryBlock::Fill(uint8_t value) noexcept
    {
        if (!HasMemoryBlock()) return;

        uint8_t* p = _p;
        uint8_t* end = p + _size;

        while (p != end) {
            *p = value;
            ++p;
        }
    }

    void MemoryBlock::Free() noexcept
    {
        if (HasMemoryBlock()) [[likely]]  {
            ::free(_p);

            _p = nullptr;
            _size = 0;
        }
        
    }

    void MemoryBlock::Realloc(ssize_t size)
    {
        _checkPointer();
        _checkSize(size);

        ReallocUnsafe(size);
    }

    void MemoryBlock::ReallocUnsafe(ssize_t size)
    {
        _p = MemoryAllocator::ReallocMemoryUnsafe<uint8_t>((size_t)size, _p);
        _size = size;
    }

    String MemoryBlock::ToString() const
    {
        return String::FromLiteral(u"KONGKONG_NAMESPACE::Memory::MemoryBlock");
    }

    void MemoryBlock::_checkIndex(ssize_t index) const
    {
        if (index < 0 || _size <= index) [[unlikely]] throw InvalidArgumentException(u"無効な要素番号です");
    }

    void MemoryBlock::_checkPointer() const
    {
        if (_p == nullptr) [[unlikely]] throw NullPointerException(u"MemoryBlockにメモリが割り当てられていません");
    }

    void MemoryBlock::_checkSize(ssize_t size) const
    {
        if (size <= 0) [[unlikely]] throw InvalidArgumentException(u"無効なブロックサイズです");
    }
}

namespace KONGKONG_NAMESPACE::Memory
{
    MemoryBlock::MemoryBlock() : Object(nullptr)
    {
        _setInstance(NEW ImplType());
    }

    MemoryBlock::MemoryBlock(ssize_t size) : Object(nullptr)
    {
        _setInstance(NEW ImplType(size));
    }
}
