#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSDECIMALNUMBER_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSDECIMALNUMBER_H

#include "Base.h"
#include "Kongkong.AppleDevice.Foundation.NSNumber.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    class NSDecimalNumber : public NSNumber {
        public:

        [[nodiscard]]
        static NSDecimalNumber NaN() noexcept;

        [[nodiscard]]
        static NSDecimalNumber One() noexcept;

        [[nodiscard]]
        static NSDecimalNumber Zero() noexcept;

        /// @brief nullptrとして作成
        constexpr NSDecimalNumber(std::nullptr_t) noexcept : NSNumber(nullptr) {}
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSDECIMALNUMBER_H
