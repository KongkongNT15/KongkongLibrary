#ifndef KONGKONG_COLLECTIONS_TURBO_FASTPOINTERARRAYITERATORMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTPOINTERARRAYITERATORMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastPointerArrayIteratorMethods {
        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _fastPointerArrayIteratorMethods() = default;

        template <class T>
        friend struct FastPointerArrayIterator;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTPOINTERARRAYITERATORMETHODS_H
