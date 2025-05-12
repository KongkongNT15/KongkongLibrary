#ifndef KONGKONG_COLLECTIONS_IITERABLE_H
#define KONGKONG_COLLECTIONS_IITERABLE_H

#include "Base.h"
#include "Kongkong.Collections.IReadOnlyIterable.h"
#include "Kongkong.Collections.Iterators.Iterator.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    KONGKONG_INTERFACE IIterable : virtual public IReadOnlyIterable<T> {
        [[nodiscard]] virtual Iterators::Iterator<T> begin() = 0;
        [[nodiscard]] virtual Iterators::Iterator<T> end() = 0;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    KONGKONG_INTERFACE IIterable final : public Interface {
        public:
        using ImplType = IMPLEMENTATION::IIterable<T>;

        [[nodiscard]]
        operator IReadOnlyIterable<T>() const { return Object::As<IReadOnlyIterable<T>>(); }

        /// @brief nullptrとして作成
        constexpr IIterable(std::nullptr_t) noexcept : Interface(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] Iterators::ConstIterator<T> begin() const { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] Iterators::ConstIterator<T> end() const { return _getPtr<ImplType>()->end(); }
    };
}

#endif //!KONGKONG_COLLECTIONS_IITERABLE_H
