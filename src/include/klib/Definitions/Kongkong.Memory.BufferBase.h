#ifndef KONGKONG_MEMORY_BUFFERBASE_H
#define KONGKONG_MEMORY_BUFFERBASE_H

#include "Base.h"
#include "Kongkong.ValueType.h"

namespace KONGKONG_NAMESPACE::Memory
{
    struct BufferBase : public ValueType {

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        BufferBase() = default;

        static constexpr char16_t _name[] = u"Buffer<T>";

        template <class T>
        friend struct Buffer;
    };
}

#endif //!KONGKONG_MEMORY_BUFFERBASE_H
