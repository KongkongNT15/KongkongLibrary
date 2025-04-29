#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ARRAYWRAPPERBASE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ARRAYWRAPPERBASE_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Collections.NSArray.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    struct ArrayWrapperBase {

        friend bool operator==(ArrayWrapperBase const& left, ArrayWrapperBase const& right) noexcept;
        friend bool operator!=(ArrayWrapperBase const& left, ArrayWrapperBase const& right) noexcept;

        [[nodiscard]]
        constexpr NSArray const& Array() const noexcept { return _nsArray; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]] 
        String ToString() const;

        private:

        NSArray _nsArray;

        ArrayWrapperBase(NSArray const& nsArray) noexcept;
        ArrayWrapperBase(NSArray&& nsArray) noexcept;

        /// @brief nullptrとして作成
        constexpr ArrayWrapperBase(std::nullptr_t) noexcept : _nsArray(nullptr) {}

        template <class T> //requires std::derived_from<T, NSObject>
        friend struct ArrayWrapper;
    
        template <class T>
        friend struct BlockArrayWrapper;
    };

    [[nodiscard]] bool operator==(ArrayWrapperBase const& left, ArrayWrapperBase const& right) noexcept;
    [[nodiscard]] bool operator!=(ArrayWrapperBase const& left, ArrayWrapperBase const& right) noexcept;
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ARRAYWRAPPERBASE_H
