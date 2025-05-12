#ifndef KONGKONG_COLLECTIONS_ITERATORS_CONSTARRAYLISTITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_CONSTARRAYLISTITERATOR_H

#include "Base.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Iterators.ConstIterator.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    //const版
    template <class T>
    struct ConstArrayListIterator final : public ConstIterator<T> {

        ConstArrayListIterator(const T* p) : _p(p) {}

        bool IsNotEqual(ConstIterator<T> const& right) const override
        {
            if (!right.template Is<ConstArrayListIterator<T>>()) [[unlikely]] return false;

            ConstArrayListIterator<T> const& value = dynamic_cast<ConstArrayListIterator<T> const&>(right);

            return this->_p != value._p;
        }
        T const& Current() const override { return *_p; }

        void Increment() override { ++_p; }

        ConstIterator<T>::ProjType Increment(int) override
        {
            ConstArrayListIterator<T>* p = NEW ConstArrayListIterator<T>(*this);

            MemoryAllocationException::CheckNull(p);

            Increment();

            return Object::Make<::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<T>, ConstArrayListIterator<T>>(p);
        }

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::ConstArrayListIterator<T>", true); }

        private:
        const T* _p;
    };
}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    //const版
    //ふぁ！？っく
    template <class T>
    class ConstArrayListIterator final : public ConstIterator<T> {
        public:
        using ImplType = IMPLEMENTATION::ConstArrayListIterator<T>;

        ConstArrayListIterator(const T* p) : ConstIterator<T>(nullptr) { Object::_setInstance(NEW ImplType(p)); }
        constexpr ConstArrayListIterator(std::nullptr_t) noexcept : ConstIterator<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
    
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_CONSTARRAYLISTITERATOR_H
