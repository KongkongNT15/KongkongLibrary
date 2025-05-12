#ifndef KONGKONG_COLLECTIONS_ITERATORS_ARRAYITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_ARRAYITERATOR_H

#include "Base.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Iterators.Iterator.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    template <class T>
    struct ArrayIterator final : public Iterator<T> {

        ArrayIterator(T* ptr) noexcept : _ptr(ptr) {}

        bool IsNotEqual(Iterator<T> const& right) const override
        {
            if (!right.template Is<ArrayIterator<T>>()) [[unlikely]] return false;

            ArrayIterator<T> const& value = dynamic_cast<ArrayIterator<T> const&>(right);

            return this->_ptr != value._ptr;
        }

        T& Current() override { return *_ptr; }

        void Increment() noexcept override { ++_ptr; }

        Iterator<T>::ProjType Increment(int) override
        {
            ArrayIterator<T>* p = NEW ArrayIterator<T>(*this);

            MemoryAllocationException::CheckNull(p);

            Increment();

            return Object::Make<::KONGKONG_NAMESPACE::Collections::Iterators::Iterator<T>, ArrayIterator<T>>(p);
        }

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::ArrayIterator<T>", true); }

        private:
        T* _ptr;

    };

}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    template <class T>
    class ArrayIterator final : public Iterator<T> {
        public:
        using ImplType = IMPLEMENTATION::ArrayIterator<T>;

        ArrayIterator(T* ptr) : Iterator<T>(nullptr) { Object::_setInstance(NEW ImplType(ptr)); }
        constexpr ArrayIterator(std::nullptr_t) noexcept : Iterator<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
    
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_ARRAYITERATOR_H
