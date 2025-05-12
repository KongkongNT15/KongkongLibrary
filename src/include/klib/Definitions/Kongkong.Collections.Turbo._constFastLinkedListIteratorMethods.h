#ifndef KONGKONG_COLLECTIONS_TURBO_CONSTFASTLINKEDLISTITERATORMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_CONSTFASTLINKEDLISTITERATORMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _constFastLinkedListIteratorMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        _constFastLinkedListIteratorMethods() = default;

        template <class T>
        friend struct ConstFastLinkedListIterator;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_CONSTFASTLINKEDLISTITERATORMETHODS_H
