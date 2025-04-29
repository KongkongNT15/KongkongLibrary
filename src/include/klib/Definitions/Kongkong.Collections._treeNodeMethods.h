#ifndef KONGKONG_COLLECTIONS_TREENODEMETHODS_H
#define KONGKONG_COLLECTIONS_TREENODEMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections
{
    struct _treeNodeMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _treeNodeMethods() = default;

        template <class T>
        friend struct TreeNode;
    };
}

#endif //!KONGKONG_COLLECTIONS_TREENODEMETHODS_H
