#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSDATA_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSDATA_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    class NSData : public NSObject {
        public:

        /// @brief nullptrとして作成
        constexpr NSData(std::nullptr_t) noexcept : NSObject(nullptr) {}
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSDATA_H
