#ifndef KONGKONG_COLLECTIONS_TURBO_FASTCOLLECTION_H
#define KONGKONG_COLLECTIONS_TURBO_FASTCOLLECTION_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastCollection {

        /// @brief コレクションが空かを判定
        [[nodiscard]]
        constexpr bool IsEmpty() const noexcept { return _length == 0; }

        /// @brief 要素数
        [[nodiscard]]
        constexpr ssize_t Length() const noexcept { return _length; }

        protected:
        ssize_t _length;

        private:
        _fastCollection() = default;
        constexpr _fastCollection(ssize_t length) noexcept : _length(length) {}

        template <class T>
        friend struct _fastArrayBase;

        template <class T>
        friend struct FastLinkedList;

        template <class T>
        friend struct FastPointerList;

        template <class T>
        friend struct FastLinkedQueue;

        template <class T>
        friend struct FastBinarySearchTree;

        template <class T, ssize_t N> requires (N >= 1 && sizeof(T) != 0)
        friend struct BuiltInArrayList;

        friend ArrayHelper;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTCOLLECTION_H
