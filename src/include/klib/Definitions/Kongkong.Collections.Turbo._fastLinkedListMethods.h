#ifndef KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastLinkedListMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        _fastLinkedListMethods() = default;

        template <class T>
        friend struct FastLinkedList;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTLINKEDLISTMETHODS_H
