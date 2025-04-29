#ifndef KONGKONG_APPLEDEVICE_METAL_METALCOMMANDBUFFERERROR_H
#define KONGKONG_APPLEDEVICE_METAL_METALCOMMANDBUFFERERROR_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    enum struct MetalCommandBufferError {
        None,
        Timeout,
        PageFault,
        Permitted,
        OutOfMemory,
        InvalidResource,
        Memoryless,
        DeviceRemoved,
        StackOverflow,
        Internal,
    };
}

#endif //!KONGKONG_APPLEDEVICE_METAL_METALCOMMANDBUFFERERROR_H
