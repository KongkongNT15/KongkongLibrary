#ifndef KONGKONG_COLLECTIONS_ITERATORS_ARRAYLISTITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_ARRAYLISTITERATOR_H

#include "Base.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Iterators.Iterator.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    template <class T>
    struct ArrayListIterator final : public Iterator<T> {

        ArrayListIterator(T* p) noexcept : _p(p) {}

        bool IsNotEqual(Iterator<T> const& right) const override
        {
            if (!right.template Is<ArrayListIterator<T>>()) [[unlikely]] return false;

            ArrayListIterator<T> const& value = dynamic_cast<ArrayListIterator<T> const&>(right);

            return this->_p != value._p;
        }
        T& Current() override { return *_p; }

        void Increment() override { ++_p; }

        Iterator<T>::ProjType Increment(int) override
        {
            ArrayListIterator<T>* p = NEW ArrayListIterator<T>(*this);

            MemoryAllocationException::CheckNull(p);

            Increment();

            return Object::Make<::KONGKONG_NAMESPACE::Collections::Iterators::Iterator<T>, ArrayListIterator<T>>(p);
        }

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::ArrayListIterator<T>", true); }

        private:
        T* _p;
    };

}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    template <class T>
    class ArrayListIterator final : public Iterator<T> {
        public:
        using ImplType = IMPLEMENTATION::ArrayListIterator<T>;

        ArrayListIterator(T* p) : Iterator<T>(nullptr) { Object::_setInstance(NEW ImplType(p)); }
        constexpr ArrayListIterator(std::nullptr_t) noexcept : Iterator<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
    
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_ARRAYLISTITERATOR_H
