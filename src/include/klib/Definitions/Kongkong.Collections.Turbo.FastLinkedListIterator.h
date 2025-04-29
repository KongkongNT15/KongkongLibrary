#ifndef KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATOR_H
#define KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATOR_H

#include "Base.h"
#include "Kongkong.Collections.LinkElement.h"
#include "Kongkong.Collections.Turbo._fastLinkedListIteratorMethods.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastLinkedListIterator final : public ValueType, public _fastLinkedListIteratorMethods, public _fastLinkedListIteratorBase<T> {

        [[nodiscard]] 
        T& operator*() noexcept
        {
            return this->_element->Value();
        }

        [[nodiscard]]
        T& Current()
        {
            this->_checkEnd();

            return this->_element->Value();
        }

        FastLinkedListIterator& operator++() noexcept
        {
            this->IncrementUnsafe();
            return *this;
        }

        FastLinkedListIterator operator++(int) noexcept
        {
            FastLinkedListIterator itr(this->_element);

            this->IncrementUnsafe();

            return itr;
        }

        private:

        constexpr FastLinkedListIterator(LinkElement<T>* element) noexcept : _fastLinkedListIteratorBase<T>(element) {}

        friend FastLinkedList<T>;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATOR_H
