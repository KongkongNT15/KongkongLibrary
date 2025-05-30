﻿#ifndef KONGKONG_COLLECTIONS_TURBO_FASTPOINTERLISTMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTPOINTERLISTMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastPointerListMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _fastPointerListMethods() = default;

        template <class T>
        friend struct FastPointerList;
    };
}


#endif //!KONGKONG_COLLECTIONS_TURBO_FASTPOINTERLISTMETHODS_H
