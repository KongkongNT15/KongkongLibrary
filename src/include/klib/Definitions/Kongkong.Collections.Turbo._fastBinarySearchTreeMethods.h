#ifndef KONGKONG_COLLECTIONS_TURBO_FASTBINARYTREEMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTBINARYTREEMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastBinarySearchTreeMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        _fastBinarySearchTreeMethods() = default;

        template <class T>
        friend struct FastBinarySearchTree;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTBINARYTREEMETHODS_H
