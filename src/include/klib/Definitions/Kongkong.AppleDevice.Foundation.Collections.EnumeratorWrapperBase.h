#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ENUMERATORWRAPPERBASE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ENUMERATORWRAPPERBASE_H

#include "Base.h"
#include "Kongkong.ValueType.h"
#include "Kongkong.AppleDevice.Foundation.Collections.NSEnumerator.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    struct EnumeratorWrapperBase : public ValueType {

        [[nodiscard]]
        constexpr NSEnumerator const& Enumerator() const noexcept { return _enumerator; }

        /// @brief 型名を取得
        /// @throws MemoryAllocationException: インスタンスの作成に失敗したとき
        [[nodiscard]]
        String ToString() const;

        private:
        NSEnumerator _enumerator;

        EnumeratorWrapperBase(NSEnumerator const& enumerator) noexcept : _enumerator(enumerator) {}
        EnumeratorWrapperBase(NSEnumerator&& enumerator) noexcept : _enumerator(std::move(enumerator)) {}
        constexpr EnumeratorWrapperBase(std::nullptr_t) noexcept : _enumerator(nullptr) {}

        template <class T>
        friend struct BlockEnumeratorWrapper;

        template <class T> //requires std::derived_from<T, NSObject>
        friend struct EnumeratorWrapper;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ENUMERATORWRAPPERBASE_H
