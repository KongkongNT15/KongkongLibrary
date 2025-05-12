#ifndef KONGKONG_ARGUMENTEXCEPTION_H
#define KONGKONG_ARGUMENTEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 引数が無効な値
    struct ArgumentException : public Exception {
        using Exception::Exception;
    };
    
}

#endif //!KONGKONG_ARGUMENTEXCEPTION_H
