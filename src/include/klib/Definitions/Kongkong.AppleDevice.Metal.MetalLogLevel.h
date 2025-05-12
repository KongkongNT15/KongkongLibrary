#ifndef KONGKONG_APPLEDEVICE_METAL_METALLOGLEVEL_H
#define KONGKONG_APPLEDEVICE_METAL_METALLOGLEVEL_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Metal
{
    enum struct MetalLogLevel {
        Debug,
        Info,
        Notice,
        Error,
        Fault,
        Undefined,
    };
}

#endif //!KONGKONG_APPLEDEVICE_METAL_METALLOGLEVEL_H
