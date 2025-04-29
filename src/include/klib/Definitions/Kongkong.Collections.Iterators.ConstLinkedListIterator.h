#ifndef KONGKONG_COLLECTIONS_ITERATORS_CONSTLINKEDLISTITERATOR_H
#define KONGKONG_COLLECTIONS_ITERATORS_CONSTLINKEDLISTITERATOR_H

#include "Base.h"
#include "Kongkong.MemoryAllocationException.h"
#include "Kongkong.Collections.Iterators.ConstIterator.h"
#include "Kongkong.Collections.Turbo.ConstFastLinkedListIterator.h"

namespace KONGKONG_NAMESPACE::Collections::Iterators::IMPLEMENTATION
{
    template <class T>
    struct ConstLinkedListIterator final : public ConstIterator<T> {

        constexpr ConstLinkedListIterator(Turbo::ConstFastLinkedListIterator<T> const& iter) noexcept : _iter(iter) {}

        T const& Current() const override
        {
            return _iter.Current();
        }

        void Increment() override
        {
            _iter.Increment();
        }

        ::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<T> Increment(int) override
        {
            ConstLinkedListIterator<T>* p = NEW ConstLinkedListIterator<T>(*this);

            MemoryAllocationException::CheckNull(p);

            Increment();

            return Object::template Make<::KONGKONG_NAMESPACE::Collections::Iterators::ConstIterator<T>, ConstLinkedListIterator<T>>(p);
        }

        bool IsNotEqual(ConstIterator<T> const& right) const override
        {
            if (!right.template Is<ConstLinkedListIterator<T>>()) [[unlikely]] return false;

            ConstLinkedListIterator<T> const& value = dynamic_cast<ConstLinkedListIterator<T> const&>(right);

            return this->_iter != value._iter;
        }

        String ToString() const override { return String(u"Kongkong::Collections::Iterators::ConstLinkedListIterator<T>", true); }

        private:
        Turbo::ConstFastLinkedListIterator<T> _iter;

        friend Collections::LinkedList<T>;
    };
}

namespace KONGKONG_NAMESPACE::Collections::Iterators
{
    template <class T>
    class ConstLinkedListIterator final : public ConstIterator<T> {
        public:
        using ImplType = IMPLEMENTATION::ConstLinkedListIterator<T>;

        ConstLinkedListIterator(Turbo::ConstFastLinkedListIterator<T> const& iter) : ConstIterator<T>(nullptr) { Object::_setInstance(NEW ImplType(iter)); }

        /// @brief nullptrとして作成
        constexpr ConstLinkedListIterator(std::nullptr_t) noexcept : ConstIterator<T>(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)
    };
}

#endif //!KONGKONG_COLLECTIONS_ITERATORS_CONSTLINKEDLISTITERATOR_H
