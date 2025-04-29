#ifndef KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATORBASE_H
#define KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATORBASE_H

#include "Base.h"
#include "Kongkong.Collections.LinkElement.h"
#include "Kongkong.InvalidOperationException.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct _fastLinkedListIteratorBase {

        [[nodiscard]] friend constexpr bool operator==(_fastLinkedListIteratorBase const& left, _fastLinkedListIteratorBase const& right) noexcept { return left._element == right._element; }
        [[nodiscard]] friend constexpr bool operator!=(_fastLinkedListIteratorBase const& left, _fastLinkedListIteratorBase const& right) noexcept { return left._element != right._element; }

        [[nodiscard]] 
        T const& operator*() const noexcept
        {
            return _element->Value();
        }

        [[nodiscard]]
        T const& Current() const
        {
            _checkEnd();

            return _element->Value();
        }

        void Increment()
        {
            _checkEnd();
            _element = _element->Next();
        }

        void IncrementUnsafe() noexcept
        {
            _element = _element->Next();
        }

        private:

        constexpr _fastLinkedListIteratorBase(LinkElement<T>* element) noexcept : _element(element) {}

        LinkElement<T>* _element;

        void _checkEnd() const
        {
            if (_element == nullptr) [[unlikely]] throw InvalidOperationException(u"");
        }

        friend FastLinkedList<T>;
        friend FastLinkedListIterator<T>;
        friend ConstFastLinkedListIterator<T>;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATORBASE_H
