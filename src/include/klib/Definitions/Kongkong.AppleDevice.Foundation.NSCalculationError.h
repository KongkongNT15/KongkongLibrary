#ifndef KONGKONG_APPLEDEVICE_FOUNDATION_NSCALUCULATIONERROR_H
#define KONGKONG_APPLEDEVICE_FOUNDATION_NSCALUCULATIONERROR_H

#include "Base.h"

namespace KONGKONG_NAMESPACE::AppleDevice::Foundation
{
    enum struct NSCalculationError : size_t {
        NoError,
        LossOfPrecision, // Result lost precision
        Underflow,       // Result became 0
        Overflow,        // Result exceeds possible representation
        DivideByZero
    };
}

#endif //!KONGKONG_APPLEDEVICE_FOUNDATION_NSCALUCULATIONERROR_H
