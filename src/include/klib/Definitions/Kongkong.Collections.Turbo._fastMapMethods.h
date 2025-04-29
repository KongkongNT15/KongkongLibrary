#ifndef KONGKONG_COLLECTIONS_TURBO_BASICFASTMAPMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_BASICFASTMAPMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _fastMapMethods {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _fastMapMethods() = default;

        template <class TKey, class TValue>
        friend struct FastMap;

    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_BASICFASTMAPMETHODS_H
