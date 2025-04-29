#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_BLOCKENUMERATORWRAPPER_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_BLOCKENUMERATORWRAPPER_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Collections.EnumeratorWrapperBase.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    template <class T>
    struct BlockEnumeratorWrapper final : public EnumeratorWrapperBase {
        BlockEnumeratorWrapper(NSEnumerator const& enumerator) noexcept : EnumeratorWrapperBase(enumerator) {}
        BlockEnumeratorWrapper(NSEnumerator&& enumerator) noexcept : EnumeratorWrapperBase(std::move(enumerator)) {}

        /// @brief nullptrとして作成
        constexpr BlockEnumeratorWrapper(std::nullptr_t) noexcept : EnumeratorWrapperBase(nullptr) {}

        /// @brief 次のオブジェクトを取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]] 
        T NextObject() const { return _enumerator.NextObject().template ToBlock<T>(); }
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_BLOCKENUMERATORWRAPPER_H
