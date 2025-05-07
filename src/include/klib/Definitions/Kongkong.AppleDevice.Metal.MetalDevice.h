#ifndef KONGKONG_APPLEDEVICE_METAL_METALDEVICE_H
#define KONGKONG_APPLEDEVICE_METAL_METALDEVICE_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    KONGKONG_INTERFACE MetalDevice : public NSObject {

        [[nodiscard]]
        static MetalDevice DefaultDevice() noexcept;

        /// @brief nullptrとして作成
        constexpr MetalDevice(::std::nullptr_t) noexcept : NSObject(nullptr) {}
    };
}

#endif //!KONGKONG_APPLEDEVICE_METAL_METALDEVICE_H
