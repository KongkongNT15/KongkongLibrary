#ifndef KONGKONG_INITIALIZATIONEXCEPTION_H
#define KONGKONG_INITIALIZATIONEXCEPTION_H

#include "Base.h"
#include "Kongkong.Exception.h"

namespace KONGKONG_NAMESPACE
{
    struct InitializationException : public Exception {

        using Exception::Exception;

        /// @brief デフォルトのメッセージで作成
        InitializationException();

    };
}

#endif //!KONGKONG_INITIALIZATIONEXCEPTION_H
