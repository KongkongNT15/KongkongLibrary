#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSNULL_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSNULL_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Collections
{
    class NSNull : public NSObject {
        public:

        /// @brief nullオブジェクトを取得
        [[nodiscard]]
        static NSNull Null() noexcept;

        /// @brief nullptrとして作成
        constexpr NSNull(std::nullptr_t) noexcept : NSObject(nullptr) {}
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_COLLECTIONS_NSNULL_H
