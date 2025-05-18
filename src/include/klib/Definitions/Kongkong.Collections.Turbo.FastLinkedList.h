#ifndef KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLIST_H
#define KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLIST_H

#include "Base.h"
#include "Kongkong.Collections.LinkElement.h"
#include "Kongkong.Collections.Turbo._fastLinkedListMethods.h"
#include "Kongkong.Collections.Turbo._fastCollection.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.Turbo.ConstFastLinkedListIterator.h"
#include "Kongkong.Collections.Turbo.FastLinkedListIterator.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    template <class T>
    struct FastLinkedList final : public ValueType, public _fastLinkedListMethods, public _fastCollection {

        constexpr FastLinkedList() noexcept : _fastCollection(0), _firstElement(nullptr), _lastElement(nullptr) {}

        FastLinkedList(std::initializer_list<T> const& inil) : FastLinkedList()
        {
            for (T const& v : inil) {
                Append(v);
            }
        }

        FastLinkedList(FastLinkedList const& right) : FastLinkedList()
        {
            for (T const& v : right) {
                Append(v);
            }
        }

        constexpr FastLinkedList(FastLinkedList&& right) noexcept : _fastCollection(right._length), _firstElement(right._firstElement), _lastElement(right._lastElement)
        {
            right._firstElement = nullptr;
        }

        ~FastLinkedList()
        {
            _finalize();
        }

        FastLinkedList& operator=(FastLinkedList const& right)
        {
            _finalize();
            this->_length = 0;
            _lastElement = nullptr;

            for (T const& v : right) {
                Append(v);
            }

            return *this;
        }

        FastLinkedList& operator=(FastLinkedList&& right) noexcept
        {
            _finalize();

            this->_length = right._length;
            _firstElement = right._firstElement;
            _lastElement = right._lastElement;

            right._firstElement = nullptr;
        }

        FastLinkedList& operator+=(T const& value)
        {
            Append(value);
            return *this;
        }

        FastLinkedList& operator+=(T&& value)
        {
            Append(std::move(value));
            return *this;
        }

        FastLinkedList& operator-=(T const& value) noexcept
        {
            Remove(value);
            return *this;
        }

        [[nodiscard]] constexpr FastLinkedListIterator<T> begin() noexcept { return FastLinkedListIterator<T>(_firstElement); }
        [[nodiscard]] constexpr ConstFastLinkedListIterator<T> begin() const noexcept { return ConstFastLinkedListIterator<T>(_firstElement); }
        [[nodiscard]] constexpr FastLinkedListIterator<T> end() noexcept { return FastLinkedListIterator<T>(nullptr); }
        [[nodiscard]] constexpr ConstFastLinkedListIterator<T> end() const noexcept { return ConstFastLinkedListIterator<T>(nullptr); }

        void Append(T const& value)
        {
            if (this->_length == 0) {
                //直接代入して問題ない
                _firstElement = NEW LinkElement<T>(nullptr, nullptr, value);

                MemoryAllocationException::CheckNull(_firstElement);

                _lastElement = _firstElement;
            }
            else {
                LinkElement<T>* p = NEW LinkElement<T>(_lastElement, nullptr, value);

                MemoryAllocationException::CheckNull(p);

                _lastElement->Next(p);
                _lastElement = p;
            }
            ++this->_length;
        }

        void Append(T&& value)
        {
            if (this->_length == 0) {
                //直接代入して問題ない
                _firstElement = NEW LinkElement<T>(nullptr, nullptr, std::move(value));

                MemoryAllocationException::CheckNull(_firstElement);

                _lastElement = _firstElement;
            }
            else {
                LinkElement<T>* p = NEW LinkElement<T>(_lastElement, nullptr, std::move(value));

                MemoryAllocationException::CheckNull(p);

                _lastElement->Next(p);
                _lastElement = p;
            }
            ++this->_length;
        }

        void AppendFront(T const& value)
        {
            if (this->_length == 0) {
                _firstElement = NEW LinkElement<T>(nullptr, nullptr, value);

                MemoryAllocationException::CheckNull(_firstElement);

                _lastElement = _firstElement;
            }
            else {
                LinkElement<T>* element = NEW LinkElement<T>(nullptr, _firstElement, value);

                MemoryAllocationException::CheckNull(element);

                _firstElement->Before(element);
                _firstElement = element;
            }
            this->_length++;
        }

        void AppendFront(T&& value)
        {
            if (this->_length == 0) {
                _firstElement = NEW LinkElement<T>(nullptr, nullptr, std::move(value));

                MemoryAllocationException::CheckNull(_firstElement);

                _lastElement = _firstElement;
            }
            else {
                LinkElement<T>* element = NEW LinkElement<T>(nullptr, _firstElement, std::move(value));

                MemoryAllocationException::CheckNull(element);

                _firstElement->Before(element);
                _firstElement = element;
            }
            this->_length++;
        }

        [[nodiscard]]
        T& Back()
        {
            CollectionHelper::CheckBackFront(this->_length);
            return BackUnsafe();
        }

        [[nodiscard]]
        T const& Back() const
        {
            CollectionHelper::CheckBackFront(this->_length);
            return BackUnsafe();
        }

        [[nodiscard]]
        T& BackUnsafe() noexcept
        {
            if(this->_length == 1) return _firstElement->Value();

            return _lastElement->Value();
        }

        [[nodiscard]]
        T const& BackUnsafe() const noexcept
        {
            if(this->_length == 1) return _firstElement->Value();

            return _lastElement->Value();
        }

        void Clear() noexcept
        {
            LinkElement<T>* p = _firstElement;
            LinkElement<T>* tmp;

            while (p != nullptr) {
                tmp = p->Next();

                delete p;
                p = tmp;
            }

            _firstElement = nullptr;
            _lastElement = nullptr;
            this->_length = 0;
        }

        [[nodiscard]]
        bool Contains(T const& value) const noexcept
        {
            if (this->_length == 0) [[unlikely]] return false;

            LinkElement<T>* element = _firstElement;

            while (element != nullptr)
            {
                if (element->Value() == value) return true;

                element = element->Next();
            }

            return false;
        }

        [[nodiscard]]
        T& Front()
        {
            CollectionHelper::CheckBackFront(this->_length);
            return FrontUnsafe();
        }

        [[nodiscard]]
        T const& Front() const
        {
            CollectionHelper::CheckBackFront(this->_length);
            return FrontUnsafe();
        }

        [[nodiscard]]
        T& FrontUnsafe() noexcept
        {
            return _firstElement->Value();
        }

        [[nodiscard]]
        T const& FrontUnsafe() const noexcept
        {
            return _firstElement->Value();
        }

        void Insert(ConstFastLinkedListIterator<T> const& iterator, T const& value)
        {
            _insert(iterator._element, value);
        }

        void Insert(FastLinkedListIterator<T> const& iterator, T const& value)
        {
            _insert(iterator._element, value);
        }

        void Insert(ConstFastLinkedListIterator<T> const& iterator, T&& value)
        {
            _insert(iterator._element, std::move(value));
        }

        void Insert(FastLinkedListIterator<T> const& iterator, T&& value)
        {
            _insert(iterator._element, std::move(value));
        }

        bool Remove(T const& value) noexcept
        {
            LinkElement<T>* element = _firstElement;

            while (element != nullptr) {
                if (element->Value() == value) {
                    LinkElement<T>* before = element->Before();
                    LinkElement<T>* next = element->Next();

                    if (before != nullptr) [[likely]] {
                        before->Next(next);
                    }
                    if (next != nullptr) [[likely]] {
                        next->Before(before);
                    }

                    if (element == _firstElement) _firstElement = next;
                    else if (element == _lastElement) _lastElement = before;

                    delete element;

                    --this->_length;

                    return true;
                }
                element = element->Next();
            }

            return false;
        }

        void RemoveBack()
        {
            CollectionHelper::CheckBackFront(this->_length);
            RemoveBackUnsafe();
        }

        void RemoveBackUnsafe() noexcept
        {
            if (this->_length == 1) {
                delete _firstElement;
                _firstElement = nullptr;
            }
            else {
                LinkElement<T>* element = _lastElement->Before();
                element->Next(nullptr);
                delete _lastElement;
            }

            this->_length--;
        }

        void RemoveFront()
        {
            CollectionHelper::CheckBackFront(this->_length);
            RemoveFrontUnsafe();
        }

        void RemoveFrontUnsafe() noexcept
        {
            delete _firstElement;

            _firstElement = nullptr;
            this->_length--;
        }

        void Reverse() noexcept
        {
            _reverseFunc(_firstElement);

            LinkElement<T>* tmp = _firstElement;
            _firstElement = _lastElement;
            _lastElement = tmp;
        }

        private:

        void _finalize() noexcept
        {
            LinkElement<T>* p = _firstElement;

            LinkElement<T>* tmp;

            while (p != nullptr) {
                tmp = p->Next();

                delete p;

                p = tmp;
            }
        }

        void _insert(LinkElement<T>* element, T const& value)
        {
            //
            if (element == nullptr) {
                Append(value);
            }
            else {
                if (element == _firstElement) {
                    AppendFront(value);
                }
                else {
                    LinkElement<T> before = element->Before();
                    LinkElement<T>* p = NEW LinkElement<T>(before, element, value);

                    MemoryAllocationException::CheckNull(p);

                    before->Next(p);
                    element->Before(p);
                    this->_length++;
                }
            }
        }

        void _insert(LinkElement<T>* element, T&& value)
        {
            //
            if (element == nullptr) {
                Append(std::move(value));
            }
            else {
                if (element == _firstElement) {
                    AppendFront(std::move(value));
                }
                else {
                    LinkElement<T> before = element->Before();
                    LinkElement<T>* p = NEW LinkElement<T>(before, element, value);

                    MemoryAllocationException::CheckNull(p);

                    before->Next(p);
                    element->Before(p);
                    this->_length++;
                }
            }
        }

        void _reverseFunc(LinkElement<T> *element) noexcept
        {
            if (element == nullptr) return;
            _reverseFunc(element->Next());

            LinkElement<T>* before = element->Before();
            LinkElement<T>* next = element->Next();
            element->Before(next);
            element->Next(before);
        };

        LinkElement<T>* _firstElement;
        LinkElement<T>* _lastElement;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLIST_H
