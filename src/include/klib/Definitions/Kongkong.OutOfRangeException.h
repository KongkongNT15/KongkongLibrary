#ifndef KONGKONG_OUTOFRANGEEXCEPTION_H
#define KONGKONG_OUTOFRANGEEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 範囲外
    struct OutOfRangeException : public Exception {
        using Exception::Exception;
    };
    
}

#endif //!KONGKONG_OUTOFRANGEEXCEPTION_H
