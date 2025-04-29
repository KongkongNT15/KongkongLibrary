#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSENUMRATOR_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSENUMRATOR_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    class NSEnumerator : public NSObject {
        public:

        /// @brief nullptrとして作成
        constexpr NSEnumerator(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief 次のオブジェクトを取得
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        [[nodiscard]] 
        NSObject NextObject() const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSENUMRATOR_H
