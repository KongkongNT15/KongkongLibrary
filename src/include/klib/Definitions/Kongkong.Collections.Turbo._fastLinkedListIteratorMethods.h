#ifndef KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATORMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATORMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastLinkedListIteratorMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        _fastLinkedListIteratorMethods() = default;

        template <class T>
        friend struct FastLinkedListIterator;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTITERATORMETHODS_H
