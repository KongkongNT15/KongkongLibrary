﻿#ifndef KONGKONG_COLLECTIONS_TURBO_FASTLINKEDQUEUEMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_FASTLINKEDQUEUEMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastLinkedQueueMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _fastLinkedQueueMethods() = default;
        _fastLinkedQueueMethods(_fastLinkedQueueMethods const&) = default;
        _fastLinkedQueueMethods(_fastLinkedQueueMethods&&) = default;

        _fastLinkedQueueMethods& operator=(_fastLinkedQueueMethods const&) = default;
        _fastLinkedQueueMethods& operator=(_fastLinkedQueueMethods&&) = default;

        template <class T>
        friend struct FastLinkedQueue;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_FASTLINKEDQUEUEMETHODS_H
