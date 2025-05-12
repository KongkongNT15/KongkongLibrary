#ifndef KONGKONG_COLLECTIONS_TURBO_FASTARRAYLISTMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTARRAYLISTMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastArrayListMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _fastArrayListMethods() = default;

        template <class T>
        friend struct FastArrayList;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTARRAYLISTMETHODS_H
