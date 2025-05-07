#ifndef KONGKONG_APPLEDEVICE_METAL_METALLOGSTATE_H
#define KONGKONG_APPLEDEVICE_METAL_METALLOGSTATE_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

#include <functional>

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    KONGKONG_INTERFACE MetalLogState : public NSObject {

        /// @brief nullptrとして作成
        constexpr MetalLogState(::std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief ふぁ！？っく
        void AddLogHandler(::std::nullptr_t) const = delete;

        void AddLogHandler(void(*func)(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)) const;
        void AddLogHandler(void(^func)(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)) const;
        void AddLogHandler(::std::function<void(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)> const& func) const;

        /// @brief ふぁ！？っく
        void AddLogHandlerUnsafe(::std::nullptr_t) const = delete;

        void AddLogHandlerUnsafe(void(*func)(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)) const noexcept;
        void AddLogHandlerUnsafe(void(^func)(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)) const noexcept;
        void AddLogHandlerUnsafe(::std::function<void(Foundation::NSString const&, Foundation::NSString const&, MetalLogLevel, Foundation::NSString const&)> const& func) const noexcept;

        private:
    };
}

#endif //!KONGKONG_APPLEDEVICE_METAL_METALLOGSTATE_H
