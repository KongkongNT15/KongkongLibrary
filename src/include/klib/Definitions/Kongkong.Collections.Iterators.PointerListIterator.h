#ifndef KONGKONG_COLLECTIONS_ITERATORS_POINTERLISTITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_POINTERLISTITERATOR_H

#include "Base.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Iterators.Iterator.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    template <class T>
    struct PointerListIterator final : public Iterator<T> {

        PointerListIterator(T** p) noexcept : _p(p) {}

        bool IsNotEqual(Iterator<T> const& right) const override
        {
            if (!right.template  Is<PointerListIterator<T>>()) [[unlikely]] return false;

            PointerListIterator<T> const& value = dynamic_cast<PointerListIterator<T> const&>(right);

            return this->_p != value._p;
        }

        T& Current() override { return *(*_p); }

        void Increment() override { ++_p; }

        Iterator<T>::ProjType Increment(int) override
        {
            PointerListIterator* p = NEW PointerListIterator(*this);

            MemoryAllocationException::CheckNull(p);

            Increment();

            return Object::Make<::KONGKONG_NAMESPACE::Collections::Iterators::Iterator<T>, PointerListIterator<T>>(p);
        }

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::PointerListIterator<T>", true); }

        private:
        T** _p; 
    };

}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    template <class T>
    class PointerListIterator final : public Iterator<T> {
        public:
        using ImplType = IMPLEMENTATION::PointerListIterator<T>;

        PointerListIterator(T** p) : Iterator<T>(nullptr) { Object::_setInstance(NEW ImplType(p)); }
        constexpr PointerListIterator(std::nullptr_t) noexcept : Iterator<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
    
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_POINTERLISTITERATOR_H
