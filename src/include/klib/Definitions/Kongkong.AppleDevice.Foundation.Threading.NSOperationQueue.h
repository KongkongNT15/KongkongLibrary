#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSOPERATIONQUEUE_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSOPERATIONQUEUE_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    class NSOperationQueue : public NSObject {
        public:

        NSOperationQueue();

        /// @brief nullptrとして作成
        constexpr NSOperationQueue(::std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief ふぁ！？っく
        void AddOperationUnsafe(::std::nullptr_t) const = delete;

        bool AddOperationUnsafe(NSOperation const& op) const noexcept;

        void AddOperationWithBlockUnsafe(void(^block)(void)) const noexcept;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSOPERATIONQUEUE_H
