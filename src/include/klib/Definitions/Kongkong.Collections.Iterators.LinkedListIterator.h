#ifndef KONGKONG_COLLECTIONS_ITERATORS_LINKEDLISTITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_LINKEDLISTITERATOR_H

#include "Base.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Iterators.Iterator.h"
#include "Kongkong.Collections.Turbo.FastLinkedListIterator.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    template <class T>
    struct LinkedListIterator final : public Iterator<T> {

        constexpr LinkedListIterator(Turbo::FastLinkedListIterator<T> const& iter) noexcept : _iter(iter) {}

        T& Current() override
        {
            return _iter.Current();
        }

        void Increment() override
        {
            _iter.Increment();
        }

        Iterator<T>::ProjType Increment(int) override
        {
            LinkedListIterator<T>* p = NEW LinkedListIterator<T>(*this);

            MemoryAllocationException::CheckNull(p);

            Increment();

            return Object::template Make<Iterator<T>::ProjType, LinkedListIterator<T>>(p);
        }

        bool IsNotEqual(Iterator<T> const& right) const noexcept override
        {
            if (!right.template Is<LinkedListIterator<T>>()) [[unlikely]] return false;

            LinkedListIterator<T> const& value = dynamic_cast<LinkedListIterator<T> const&>(right);

            return this->_iter != value._iter;
        }
        
        String ToString() const override { return String(u"Kongkong::Collections::Iterators::LinkedListIterator<T>", true); }

        private:
        Turbo::FastLinkedListIterator<T> _iter;

        friend Collections::LinkedList<T>;

    };
}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    template <class T>
    class LinkedListIterator final : public Iterator<T> {
        public:
        using ImplType = IMPLEMENTATION::LinkedListIterator<T>;

        LinkedListIterator(Turbo::FastLinkedListIterator<T> const& iter) : Iterator<T>(nullptr) { Object::_setInstance(NEW ImplType(iter)); }

        /// @brief nullptrとして作成
        constexpr LinkedListIterator(std::nullptr_t) noexcept : Iterator<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_LINKEDLISTITERATOR_H
