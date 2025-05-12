#ifndef KONGKONG_INVALIDARGUMENTEXCEPTION_H
#define KONGKONG_INVALIDARGUMENTEXCEPTION_H

#include "Base.h"
#include "Kongkong.ArgumentException.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 引数が不正
    struct InvalidArgumentException : public ArgumentException {
        using ArgumentException::ArgumentException;
    };
    
}

#endif //!KONGKONG_INVALIDARGUMENTEXCEPTION_H
