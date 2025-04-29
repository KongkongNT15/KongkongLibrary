#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ENUMERATORWRAPPER_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ENUMERATORWRAPPER_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.Collections.EnumeratorWrapperBase.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    template <class T> //requires std::derived_from<T, NSObject>
    struct EnumeratorWrapper final : public EnumeratorWrapperBase {

        EnumeratorWrapper(NSEnumerator const& enumerator) noexcept : EnumeratorWrapperBase(enumerator) {}
        EnumeratorWrapper(NSEnumerator&& enumerator) noexcept : EnumeratorWrapperBase(std::move(enumerator)) {}

        /// @brief nullptrとして作成
        constexpr EnumeratorWrapper(std::nullptr_t) noexcept : EnumeratorWrapperBase(nullptr) {}

        /// @brief 次のオブジェクトを取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]] 
        T NextObject() const { return _enumerator.NextObject().template As<T>(); }

    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_ENUMERATORWRAPPER_H
