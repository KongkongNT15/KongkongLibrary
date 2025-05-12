#ifndef KONGKONG_ARGUMENTOUTOFRANGEEXCEPTION_H
#define KONGKONG_ARGUMENTOUTOFRANGEEXCEPTION_H

#include "Base.h"
#include "Kongkong.ArgumentException.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 引数が範囲外
    struct ArgumentOutOfRangeException : public ArgumentException {
        using ArgumentException::ArgumentException;
    };

}

#endif //!KONGKONG_ARGUMENTOUTOFRANGEEXCEPTION_H
