#ifndef KONGKONG_UNSAFELAZYOBJECTBASE_H
#define KONGKONG_UNSAFELAZYOBJECTBASE_H

#include "Base.h"

namespace KONGKONG_NAMESPACE
{
    struct _unsafeLazyObjectBase {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        _unsafeLazyObjectBase() = default;
        _unsafeLazyObjectBase(_unsafeLazyObjectBase const&) = default;
        _unsafeLazyObjectBase(_unsafeLazyObjectBase&&) = default;

        _unsafeLazyObjectBase& operator=(_unsafeLazyObjectBase const&) = default;
        _unsafeLazyObjectBase& operator=(_unsafeLazyObjectBase&&) = default;

        template <class T>
        friend struct UnsafeLazyObject;
    };
}

#endif //!KONGKONG_UNSAFELAZYOBJECTBASE_H
