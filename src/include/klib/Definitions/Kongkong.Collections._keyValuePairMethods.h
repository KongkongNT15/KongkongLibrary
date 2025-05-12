#ifndef KONGKONG_COLLECTIONS_KEYVALUEPAIRMETHODS_H
#define KONGKONG_COLLECTIONS_KEYVALUEPAIRMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections
{
    struct _keyValuePairMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _keyValuePairMethods() = default;

        template <class TKey, class TValue>
        friend struct KeyValuePair;
    };
}

#endif //!KONGKONG_COLLECTIONS_KEYVALUEPAIRMETHODS_H
