#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSLOCKING_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSLOCKING_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Threading
{
    INTERFACE NSLocking : public NSObject {

        /// @brief nullptrとして作成
        constexpr NSLocking(std::nullptr_t) noexcept : NSObject(nullptr) {}

        /// @brief 
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Lock() const;
        
        /// @throws NullPointerException: このインスタンスがnullptrのとき
        void Unlock() const;
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_THREADING_NSLOCKING_H
