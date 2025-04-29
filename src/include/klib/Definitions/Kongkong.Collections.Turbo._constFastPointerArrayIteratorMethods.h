#ifndef KONGKONG_COLLECTIONS_TURBO_CONSTFASTPOINTERARRAYITERATORMETHODS_H
#define KONGKONG_COLLECTIONS_TURBO_CONSTFASTPOINTERARRAYITERATORMETHODS_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::Collections::Turbo
{
    struct _constFastPointerArrayIteratorMethods {
        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:

        _constFastPointerArrayIteratorMethods() = default;

        template <class T>
        friend struct ConstFastPointerArrayIterator;
    };
}

#endif //!KONGKONG_COLLECTIONS_TURBO_CONSTFASTPOINTERARRAYITERATORMETHODS_H
