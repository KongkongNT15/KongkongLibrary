#ifndef KONGKONG_COLLECTIONS_IREADONLYITERABLE_H
#define KONGKONG_COLLECTIONS_IREADONLYITERABLE_H

#include "Base.h"

#include "Kongkong.NullPointerException.h"
#include "Kongkong.InterfaceType.h"
#include "Kongkong.Interface.h"
#include "Kongkong.Object.h"

#include "Kongkong.Collections.Iterators.ConstIterator.h"

namespace KONGKONG_NAMESPACE::Collections::IMPLEMENTATION
{
    template <class T>
    INTERFACE IReadOnlyIterable : public InterfaceType {
        [[nodiscard]] virtual Iterators::ConstIterator<T> begin() const = 0;
        [[nodiscard]] virtual Iterators::ConstIterator<T> end() const = 0;
    };
}

namespace KONGKONG_NAMESPACE::Collections
{
    template <class T>
    INTERFACE IReadOnlyIterable final : public Interface {
        public:
        using ImplType = IMPLEMENTATION::IReadOnlyIterable<T>;

        /// @brief nullptrとして作成
        constexpr IReadOnlyIterable(std::nullptr_t) noexcept : Interface(nullptr) {}

        OBJECT_GET_INSTANCE(ImplType)

        [[nodiscard]] Iterators::ConstIterator<T> begin() const { return _getPtr<ImplType>()->begin(); }
        [[nodiscard]] Iterators::ConstIterator<T> end() const { return _getPtr<ImplType>()->end(); }
    };
}

#endif //!KONGKONG_COLLECTIONS_IREADONLYITERABLE_H
