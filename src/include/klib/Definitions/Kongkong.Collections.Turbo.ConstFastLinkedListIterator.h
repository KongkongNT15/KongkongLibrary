#ifndef KONGKONG_COLLECTIONS_TURBO_CONSTFASTLINKEDLISTITERATOR_H
#define KONGKONG_COLLECTIONS_TURBO_CONSTFASTLINKEDLISTITERATOR_H

#include "Base.h"
#include "Kongkong.Collections.LinkElement.h"
#include "Kongkong.Collections.Turbo._constFastLinkedListIteratorMethods.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct ConstFastLinkedListIterator final : public ValueType, public _constFastLinkedListIteratorMethods, public _fastLinkedListIteratorBase<T> {

        ConstFastLinkedListIterator& operator++() noexcept
        {
            this->IncrementUnsafe();
            return *this;
        }

        ConstFastLinkedListIterator operator++(int) noexcept
        {
            ConstFastLinkedListIterator itr(this->_element);

            this->IncrementUnsafe();

            return itr;
        }

        private:

        constexpr ConstFastLinkedListIterator(LinkElement<T>* element) noexcept : _fastLinkedListIteratorBase<T>(element) {}

        friend FastLinkedList<T>;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_CONSTFASTLINKEDLISTITERATOR_H
