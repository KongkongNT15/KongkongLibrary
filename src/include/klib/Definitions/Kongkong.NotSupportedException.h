#ifndef KONGKONG_NOSUPPORTEDEXCEPTION_H
#define KONGKONG_NOSUPPORTEDEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    /// @brief 機能がサポートされていないときの例外
    struct NotSupportedException : public Exception {
        using Exception::Exception;
    };

}

#endif //!KONGKONG_NOSUPPORTEDEXCEPTION_H
