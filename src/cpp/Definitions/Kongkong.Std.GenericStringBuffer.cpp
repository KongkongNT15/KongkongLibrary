//このcppファイルをコンパイルに含めないでください

namespace KONGKONG_NAMESPACE::Standard::Cpp
{
    template <CharType TChar>
    GenericStringBuffer<TChar>::GenericStringBuffer() : _buffer((TChar*)::malloc(_defaultCapacity * sizeof(TChar))), _capacity(_defaultCapacity)
    {
        MemoryAllocationException::CheckNull(_buffer);
        _setgp(0, _capacity - 1);
    }

    template <CharType TChar>
    GenericStringBuffer<TChar>::GenericStringBuffer(GenericStringBuffer<TChar> const& right) : Base(right), _buffer((TChar*)::malloc(right._capacity * sizeof(TChar))), _capacity(right._capacity)
    {
        MemoryAllocationException::CheckNull(_buffer);
        _setgp(right.gptr() - right._buffer, right.epptr() - right.pptr());

        for (ssize_t i = 0; i < _capacity; i++) {
            _buffer[i] = right._buffer[i];
        }
    }

    template <CharType TChar>
    GenericStringBuffer<TChar>::GenericStringBuffer(GenericStringBuffer<TChar>&& right) noexcept : Base(right), _buffer(right._buffer), _capacity(right._capacity)
    {
        right._buffer = nullptr;
    }

    template <CharType TChar>
    GenericStringBuffer<TChar>::~GenericStringBuffer()
    {
        if (_buffer != nullptr) {
            ::free(_buffer);
        }
    }

    template <CharType TChar>
    GenericStringBuffer<TChar>& GenericStringBuffer<TChar>::operator=(GenericStringBuffer<TChar> const& right)
    {
        if (_capacity < right._capacity) {
            TChar* p = (TChar*)::malloc(right._capacity * (sizeof(TChar)));

            MemoryAllocationException::CheckNull(p);

            ::free(_buffer);

            _buffer = p;

            _capacity = right._capacity;
        }

        Base::operator=(right);

        for (ssize_t i = 0; i < right._capacity; i++) {
            _buffer[i] = right._buffer[i];
        }

        _setgp(right.gptr() - right._buffer, right.epptr() - right.pptr());

        return *this;
    }

    template <CharType TChar>
    GenericStringBuffer<TChar>& GenericStringBuffer<TChar>::operator=(GenericStringBuffer<TChar>&& right) noexcept
    {
        ::free(_buffer);

        Base::operator=(right);

        _buffer = right._buffer;
        _capacity = right._capacity;

        right._buffer = nullptr;

        return *this;
    }

    template <CharType TChar>
    GenericStringView<TChar> GenericStringBuffer<TChar>::GetStringView() const noexcept
    {
        TChar* p = _getEndPtr();
        *p = (TChar)0;

        return GenericStringView<TChar>::FromPointerUnsafe(p - _buffer, _buffer);
    }

    template <CharType TChar>
    GenericStringBuffer<TChar>::Base::int_type GenericStringBuffer<TChar>::overflow(Base::int_type c)
    {
        if (Base::traits_type::to_char_type(c) == Base::traits_type::eof()) return c;

        if (!_expandBuffer()) return Base::traits_type::eof();

        return Base::sputc(c);
    }

    template <CharType TChar>
    std::streamsize GenericStringBuffer<TChar>::xsputn(const TChar* s, std::streamsize n)
    {
        ssize_t space = Base::epptr() - Base::pptr();

        if (space < n) {
            if (!_expandBuffer(n + _defaultCapacity)) throw MemoryAllocationException();
        }

        ::memcpy(Base::pptr(), s, n * sizeof(TChar));

        Base::pbump((int)n);

        return n;
    }

    template <CharType TChar>
    void GenericStringBuffer<TChar>::_setgp(ssize_t defg, ssize_t defp) noexcept
    {
        this->setp(_buffer + _capacity - 1 - defp, _buffer + _capacity - 1);
        this->setg(_buffer, _buffer + defg, _buffer + _capacity - 1);
    }

    template <CharType TChar>
    TChar* GenericStringBuffer<TChar>::_getEndPtr() const noexcept
    {
        return this->gptr() > this->pptr() ? this->gptr() : this->pptr();
    }

    template <CharType TChar>
    bool GenericStringBuffer<TChar>::_expandBuffer(ssize_t append) noexcept
    {
        ssize_t def = this->pptr() - _buffer;

        _capacity += append;

        TChar* p = (TChar*)::realloc(_buffer, _capacity * sizeof(TChar));

        if (!p) return false;

        _buffer = p;

        _setgp(def, Base::epptr() - Base::pptr());

        return true;
    }

    template class GenericStringBuffer<char>;
    template class GenericStringBuffer<wchar_t>;
    template class GenericStringBuffer<char8_t>;
    template class GenericStringBuffer<char16_t>;
    template class GenericStringBuffer<char32_t>;
}
