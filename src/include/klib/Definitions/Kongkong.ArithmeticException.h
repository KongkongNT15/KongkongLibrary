#ifndef KONGKONG_ARITHMETICEXCEPTION_H
#define KONGKONG_ARITHMETICEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 算術演算
    struct ArithmeticException : public Exception {
        using Exception::Exception;
    };
    
}

#endif //!KONGKONG_ARITHMETICEXCEPTION_H
