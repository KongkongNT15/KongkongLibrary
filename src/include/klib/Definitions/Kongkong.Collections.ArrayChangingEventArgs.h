#ifndef KONGKONG_COLLECTIONS_ARRAYCHANGINGARGS_H
#define KONGKONG_COLLECTIONS_ARRAYCHANGINGARGS_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.Collections.CollectionChange.h"

namespace KONGKONG_NAMESPACE::Collections
{
    struct ArrayChangingEventArgs final : public ValueType {

        constexpr ArrayChangingEventArgs(::KONGKONG_NAMESPACE::Collections::CollectionChange collectionChange, ssize_t index) noexcept : _collectionChange(collectionChange), _index(index) {}
        constexpr ArrayChangingEventArgs(ssize_t index, ::KONGKONG_NAMESPACE::Collections::CollectionChange collectionChange) noexcept : _collectionChange(collectionChange), _index(index) {}

        /// @brief 変更の種類
        [[nodiscard]]
        constexpr ::KONGKONG_NAMESPACE::Collections::CollectionChange CollectionChange() const noexcept { return _collectionChange; }

        /// @brief 変更があった要素番号
        [[nodiscard]]
        constexpr ssize_t Index() const noexcept { return _index; }

        /// @brief 型名を取得
        [[nodiscard]]
        String ToString() const;

        private:
        ::KONGKONG_NAMESPACE::Collections::CollectionChange _collectionChange;
        ssize_t _index;
    };
}

#endif //!KONGKONG_COLLECTIONS_ARRAYCHANGINGARGS_H
