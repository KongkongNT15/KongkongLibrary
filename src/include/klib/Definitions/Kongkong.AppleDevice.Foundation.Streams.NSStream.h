#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_STREAMS_NSSTREAM_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_STREAMS_NSSTREAM_H

#include "Base.h"
#include "Kongkong.AppleDevice.NSObject.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation::Streams
{
    class NSStream : public NSObject {
        public:

        /// @brief nullptrとして作成
        constexpr NSStream(std::nullptr_t) noexcept : NSObject(nullptr) {}
    };
}


#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_STREAMS_NSSTREAM_H
