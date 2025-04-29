#ifndef KONGKONG_COLLECTIONS_ITERATORS_CONSTARRAYITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_CONSTARRAYITERATOR_H

#include "Base.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Iterators.ConstIterator.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    template <class T>
    struct ConstArrayIterator final : public ConstIterator<T> {

        ConstArrayIterator(const T* ptr) noexcept : _ptr(ptr) {}

        bool IsNotEqual(ConstIterator<T> const& right) const override
        {
            if (!right.template Is<ConstArrayIterator<T>>()) [[unlikely]] return false;

            ConstArrayIterator<T> const& value = dynamic_cast<ConstArrayIterator<T> const&>(right);

            return this->_ptr != value._ptr;
        }
        T const& Current() const override { return *_ptr; }

        void Increment() noexcept override { ++_ptr; }

        ::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<T> Increment(int) override
        {
            ConstArrayIterator<T>* p = NEW ConstArrayIterator<T>(*this);

            MemoryAllocationException::CheckNull(p);

            Increment();

            return Object::Make<::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<T>, ConstArrayIterator<T>>(p);
        }

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::ConstArrayIterator<T>", true); }

        private:
        const T* _ptr;

    };

}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    template <class T>
    class ConstArrayIterator final : public ConstIterator<T> {
        public:
        using ImplType = IMPLEMENTATION::ConstArrayIterator<T>;

        ConstArrayIterator(const T* ptr) : ConstIterator<T>(nullptr) { Object::_setInstance(NEW ImplType(ptr)); }
        constexpr ConstArrayIterator(std::nullptr_t) noexcept : ConstIterator<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };

}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_CONSTARRAYITERATOR_H
