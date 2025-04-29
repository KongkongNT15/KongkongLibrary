#ifndef KONGKONG_COLLECTIONS_ITERATORS_CONSTPOINTERLISTITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_CONSTPOINTERLISTITERATOR_H

#include "Base.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Iterators.ConstIterator.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    template <class T>
    struct ConstPointerListIterator final : public ConstIterator<T> {

        ConstPointerListIterator(const T** p) noexcept : _p(p) {}

        bool IsNotEqual(ConstIterator<T> const& right) const override
        {
            if (!right.template  Is<ConstPointerListIterator<T>>()) [[unlikely]] return false;

            ConstPointerListIterator<T> const& value = dynamic_cast<ConstPointerListIterator<T> const&>(right);

            return this->_p != value._p;
        }
        
        T const& Current() const override { return *(*_p); }

        void Increment() override { ++_p; }

        ::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<T> Increment(int) override
        {
            ConstPointerListIterator* p = NEW ConstPointerListIterator(*this);

            MemoryAllocationException::CheckNull(p);

            Increment();

            return Object::template Make<::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<T>, ConstPointerListIterator<T>>(p);
        }

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::ConstPointerListIterator<T>", true); }

        private:
        const T** _p;  
    };

}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    template <class T>
    class ConstPointerListIterator final : public ConstIterator<T> {
        public:
        using ImplType = IMPLEMENTATION::ConstPointerListIterator<T>;

        ConstPointerListIterator(const T** p) : ConstIterator<T>(nullptr) { Object::_setInstance(NEW ImplType(p)); }
        constexpr ConstPointerListIterator(std::nullptr_t) noexcept : ConstIterator<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
    
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_CONSTPOINTERLISTITERATOR_H
